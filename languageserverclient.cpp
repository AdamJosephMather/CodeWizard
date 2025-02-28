#ifdef _WIN32
#include "languageserverclient.h"
#else
#include "/home/adamj/QtProjects/CodeWizard/languageserverclient.h"
#endif

#include <QDebug>
#include <QJsonArray>
#include <QThread>
#include <QTimer>
#include <qmessagebox.h>

QString langID;
QString missingNext;
QString fileURI;
QByteArray currentExecution;
QString fileRootURI;
QMap<int, QString> requestsMap;
QJsonArray diagnostics;
bool quitting = false;
QEventLoop shutdownLoop;
int shutdownId = -999;
bool alreadyDoneShutdownLoop = false;
bool failedToStart = false;
int initializeRequestId = -999;
QTextEdit* copyOfTextEdit;

LanguageServerClient::LanguageServerClient(const QString &serverPath, QTextEdit *providedTextEdit, QObject *parent)
	: QObject(parent), requestId(0), documentVersion(1)
{
	lspPath = serverPath;

	copyOfTextEdit = providedTextEdit;
	langID = "";
	missingNext = "";
	fileURI = "";
	currentExecution = QByteArray();
	fileRootURI = "";
	requestsMap = QMap<int, QString>();
	diagnostics = QJsonArray();
	quitting = false;
	shutdownId = -999;
	alreadyDoneShutdownLoop = false;
	initializeRequestId = -999;
	failedToStart = false;

	connect(&serverProcess, &QProcess::readyReadStandardOutput, this, &LanguageServerClient::onServerReadyRead);
	connect(&serverProcess, &QProcess::errorOccurred, this, &LanguageServerClient::onServerErrorOccurred);
	connect(&serverProcess, &QProcess::finished, this, &LanguageServerClient::onServerFinished);

	#ifdef Q_OS_WIN
		serverProcess.start("cmd", QStringList() << "/c" << serverPath); // to send /k
	#else
		serverProcess.start("/bin/sh", QStringList() << "-c" << serverPath); // to send /k
	#endif

	if (!serverProcess.waitForStarted()) {
		failedToStart = true;
		qWarning() << "Failed to start language server at:" << serverPath;
		qWarning() << "Error:" << serverProcess.errorString();
	}
}

void LanguageServerClient::onServerErrorOccurred(QProcess::ProcessError error)
{
	qDebug() << "Server error occurred:" << error;
	qDebug() << "Error String:" << serverProcess.errorString();
	initializeLoop.quit();
	failedToStart = true;
}

void LanguageServerClient::onServerFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
	qDebug() << "Server process finished with exit code:" << exitCode << "and status:" << exitStatus;
	initializeLoop.quit();
	failedToStart = true;
}

LanguageServerClient::~LanguageServerClient()
{
}

void LanguageServerClient::initialize(const QString &rootUri)
{
	fileRootURI = QUrl::fromLocalFile(rootUri).toString();

	QJsonObject capabilities {
		{"textDocument", QJsonObject{
			{"completion", QJsonObject{
				{"completionItem", QJsonObject{
					{"snippetSupport", true},
					{"resolveSupport", QJsonObject{
						{"properties", QJsonArray{"documentation", "detail", "additionalTextEdits"}}
					}}
				}}
			}},
			{"synchronization", QJsonObject{
				{"dynamicRegistration", true},
				{"didSave", true},
				{"didChange", true},
				{"willSave", false}
			}},
			{"publishDiagnostics", QJsonObject{
				{"enabled", true}
			}}
		}},
		{"completionProvider", QJsonObject{
			{"resolveProvider", true},
			{"triggerCharacters", QJsonArray{".", ":", ">", "<", "/", "@", "*", "(", "[", "{", "'", "\"", "#"}}
		}},
		{"workspace", QJsonObject{
			{"workspaceFolders", true},
			{"configuration", true}
		}}
	};
	
	QJsonObject params {
		{"rootUri", fileRootURI},
		{"capabilities", capabilities},
		{"clientInfo", QJsonObject{
			   {"name", "CodeWizardLSP"},
			   {"version", "1.0.0"}
		   }},
		{"workspaceFolders", QJsonArray{
			 QJsonObject{
				 {"uri", fileRootURI},
				 {"name", "workspace"}
			 }
		 }},
	};

	initializeRequestId = requestId++;
	QJsonObject message {
		{"jsonrpc", "2.0"},
		{"id", initializeRequestId},
		{"method", "initialize"},
		{"params", params}
	};

	sendMessage(message);

	if (failedToStart){
		QMessageBox newWarningBox;
		newWarningBox.setIcon(QMessageBox::Warning);
		newWarningBox.setText("Failed to start LSP - Ensure it's accessible via the command given.");
		newWarningBox.setWindowTitle(tr("Error"));
		newWarningBox.setFont(copyOfTextEdit->font());
		newWarningBox.exec();
		return;
	}

	initializeLoop.exec();

	if (failedToStart){
		QMessageBox newWarningBox;
		newWarningBox.setIcon(QMessageBox::Warning);
		newWarningBox.setText("Failed to start LSP - Ensure it's accessible via the command given.");
		newWarningBox.setWindowTitle(tr("Error"));
		newWarningBox.setFont(copyOfTextEdit->font());
		newWarningBox.exec();
		return;
	}

	QJsonObject initializedMessage {
		{"jsonrpc", "2.0"},
		{"method", "initialized"},
		{"params", QJsonObject()}
	};

	sendMessage(initializedMessage);

	isInitialized = true;
}

void LanguageServerClient::shutdown()
{
	if (failedToStart){
		return;
	}

	serverProcess.close();

	serverProcess.terminate();

	if (!serverProcess.waitForFinished(500)) { // 500 milliseconds because I've given up on properly ending the connection and I'm expecting a failure - yeah
		serverProcess.kill();
		serverProcess.waitForFinished();
	}

	serverProcess.deleteLater();
}

void LanguageServerClient::openDocument(const QString &uri, const QString &languageId, const QString &content)
{
	langID = languageId;
	fileURI = QUrl::fromLocalFile(uri).toString();

	QJsonObject textDocument {
		{"uri", fileURI},
		{"languageId", languageId},
		{"version", documentVersion},
		{"text", content}
	};

	QJsonObject params {
		{"textDocument", textDocument}
	};

	QJsonObject message {
		{"jsonrpc", "2.0"},
		{"method", "textDocument/didOpen"},
		{"params", params}
	};

	sendMessage(message);
}

void LanguageServerClient::closeDocument(const QString &uri)
{
	fileURI = QUrl::fromLocalFile(uri).toString();

	QJsonObject textDocument {
		{"uri", fileURI}
	};

	QJsonObject params {
		{"textDocument", textDocument}
	};

	QJsonObject message {
		{"jsonrpc", "2.0"},
		{"method", "textDocument/didClose"},
		{"params", params}
	};

	sendMessage(message);
}

void LanguageServerClient::updateDocument(const QString &content)
{
	QJsonObject textDocument {
		{"uri", fileURI},
		{"version", ++documentVersion}
	};

	QJsonArray contentChanges {
		QJsonObject { {"text", content} }
	};

	QJsonObject params {
		{"textDocument", textDocument},
		{"contentChanges", contentChanges}
	};

	QJsonObject message {
		{"jsonrpc", "2.0"},
		{"method", "textDocument/didChange"},
		{"params", params}
	};

	sendMessage(message);
}

void LanguageServerClient::documentSaved(QString text){
	QJsonObject textDocument {
		{"uri", fileURI},
		{"languageId", langID},
		{"version", ++documentVersion}
	};

	QJsonObject params {
		{"textDocument", textDocument},
		{"text", text}
	};

	QJsonObject message {
		{"jsonrpc", "2.0"},
		{"method", "textDocument/didSave"},
		{"params", params}
	};

	sendMessage(message);

}

int LanguageServerClient::requestCompletion(int line, int character)
{
	QJsonObject textDocument {
		{"uri", fileURI}
	};

	QJsonObject position {
		{"line", line},
		{"character", character}
	};

	QJsonObject context{
		{"triggerKind", 1} // 1 - manual completion trigger 2 - typing
	};

	QJsonObject params {
		{"textDocument", textDocument},
		{"position", position},
		{"context", context}
	};

	QJsonObject message {
		{"jsonrpc", "2.0"},
		{"id", requestId++},
		{"method", "textDocument/completion"},
		{"params", params}
	};

	requestsMap.insert(requestId-1, "textDocument/completion");

	sendMessage(message);

	return requestId-1;
}

int LanguageServerClient::requestHover(int line, int character)
{
	QJsonObject textDocument {
		{"uri", fileURI}
	};

	QJsonObject position {
		{"line", line},
		{"character", character}
	};

	QJsonObject params {
		{"textDocument", textDocument},
		{"position", position}
	};

	QJsonObject message {
		{"jsonrpc", "2.0"},
		{"id", requestId++},
		{"method", "textDocument/hover"},
		{"params", params}
	};

	requestsMap.insert(requestId-1, "textDocument/hover");

	sendMessage(message);

	return requestId-1;
}

void LanguageServerClient::requestActions(int line, int character, int line2, int character2)
{
	// Create the textDocument object with the file URI
	QJsonObject textDocument {
		{"uri", fileURI}
	};

	// Create the range object with start and end positions
	QJsonObject range {
		{"start", QJsonObject{{"line", line}, {"character", character}}},
		{"end", QJsonObject{{"line", line2}, {"character", character2}}}
	};

	// Create the context object (can be empty if no diagnostics are provided)
	QJsonObject context {
		{"diagnostics", filterDiagnostics(diagnostics, line, character, line2, character2)} // Optionally, provide diagnostics here if available
	};

	// Create the params object to pass to the request
	QJsonObject params {
		{"textDocument", textDocument},
		{"range", range},
		{"context", context}  // Optional: Include diagnostics if needed
	};

	// Create the message object for the request
	QJsonObject message {
		{"jsonrpc", "2.0"},
		{"id", requestId++},
		{"method", "textDocument/codeAction"},
		{"params", params}
	};

	requestsMap.insert(requestId-1, "textDocument/codeAction");

	sendMessage(message);
}

QJsonArray LanguageServerClient::filterDiagnostics(const QJsonArray &diagnostics, int lineStart, int columnStart, int lineEnd, int columnEnd)
{
	QJsonArray filteredDiagnostics;

	for (const auto &diagnostic : diagnostics) {
		QJsonObject diagnosticObj = diagnostic.toObject();
		QJsonObject range = diagnosticObj["range"].toObject();
		QJsonObject start = range["start"].toObject();
		QJsonObject end = range["end"].toObject();

		int diagStartLine = start["line"].toInt();
		int diagStartColumn = start["character"].toInt();
		int diagEndLine = end["line"].toInt();
		int diagEndColumn = end["character"].toInt();

		// Check if the diagnostic range intersects with the requested range
		if ((diagEndLine >= lineStart && diagStartLine <= lineEnd) &&
			(diagEndColumn >= columnStart && diagStartColumn <= columnEnd)) {
			filteredDiagnostics.append(diagnostic);
		}
	}

	return filteredDiagnostics;
}

void LanguageServerClient::requestGotoDefinition(int line, int character)
{
	QJsonObject textDocument {
		{"uri", fileURI}
	};

	QJsonObject position {
		{"line", line},
		{"character", character}
	};

	QJsonObject params {
		{"textDocument", textDocument},
		{"position", position}
	};

	QJsonObject message {
		{"jsonrpc", "2.0"},
		{"id", requestId++},
		{"method", "textDocument/definition"},
		{"params", params}
	};

	requestsMap.insert(requestId-1, "textDocument/definition");

	sendMessage(message);
}

void LanguageServerClient::onServerReadyRead()
{
	while (serverProcess.bytesAvailable() > 0 || currentExecution.contains("\r\n") || currentExecution.contains("Content-Length")) {
		QJsonObject response = readMessage();
		if (response == QJsonObject()){
			continue;
		}

		if (response["method"] == "window/logMessage"){
			continue;
		}

		int id = response["id"].toInt();

		if (id == shutdownId && (response["method"].isNull() || !response.contains("method"))){
			alreadyDoneShutdownLoop = true;
			shutdownLoop.quit();
			continue;
		}

		// Handle initialize response
		if (!isInitialized && response["result"].toObject()["capabilities"].toObject() != QJsonObject()) {
			// Initialize response received
			QJsonObject serverCapabilities = response["result"].toObject()["capabilities"].toObject();

			QJsonArray triggerCharsArr = serverCapabilities["completionProvider"].toObject()["triggerCharacters"].toArray();

			triggerChars.clear();
			QStringList stringList;
			for (const QJsonValue &value : triggerCharsArr) {
				if (value.isString()) {
					triggerChars.push_back(value.toString());
				}
			}
			triggerChars.push_back("_");

			qDebug() << "TRIGGER CHARACTERS: " << triggerChars;

			// You can store server capabilities here if needed
			// Signal that we've received the initialize response
			initializeLoop.quit();
			emit initializeResponseReceived();
			continue;
		}

		if (!isInitialized && id == initializeRequestId && (response["method"].isNull() || !response.contains("method"))){ // backup
			initializeLoop.quit();
			emit initializeResponseReceived();
			continue;
		}

		if (response.contains("error")) {
			qWarning() << "Error in response:" << response;
			continue;
		}

		if (response["method"] == "workspace/configuration"){
			sendMessage(QJsonObject{
				{"jsonrpc", "2.0"},
				{"id", id},
				{"result", QJsonArray{QJsonObject{}}}
			});
			continue;
		}

		if (response["method"] == "textDocument/publishDiagnostics"){
			if (response["params"].toObject()["uri"].toString().toLower() == fileURI.toLower()) {
				QJsonArray items = response["params"].toObject()["diagnostics"].toArray();
				diagnostics = items;
				QStringList messages = {};
				QList<int> startC = {};
				QList<int> startL = {};
				QList<int> endC = {};
				QList<int> endL = {};
				QList<int> severity = {};

				for (const QJsonValue &item : items) {
					messages.push_back(item.toObject()["message"].toString());
					startC.push_back(item.toObject()["range"].toObject()["start"].toObject()["character"].toInt());
					startL.push_back(item.toObject()["range"].toObject()["start"].toObject()["line"].toInt());
					endC.push_back(item.toObject()["range"].toObject()["end"].toObject()["character"].toInt());
					endL.push_back(item.toObject()["range"].toObject()["end"].toObject()["line"].toInt());
					severity.push_back(item.toObject()["severity"].toInt());
				}

				// Create a list of indices to sort the severity list
				QList<int> indices(severity.size());
				std::iota(indices.begin(), indices.end(), 0);  // Fill indices with 0, 1, 2, ..., n

				// Sort indices based on severity values
				std::sort(indices.begin(), indices.end(), [&](int a, int b) {
					return severity[a] > severity[b];  // Compare severity values
				});

				// Create sorted versions of the other lists based on the sorted indices
				QStringList sortedMessages;
				QList<int> sortedStartC, sortedStartL, sortedEndC, sortedEndL, sortedSeverity;

				for (int index : indices) {
					sortedMessages.push_back(messages[index]);
					sortedStartC.push_back(startC[index]);
					sortedStartL.push_back(startL[index]);
					sortedEndC.push_back(endC[index]);
					sortedEndL.push_back(endL[index]);
					sortedSeverity.push_back(severity[index]);
				}

				emit receivedDiagnostics(sortedMessages, sortedStartC, sortedStartL, sortedEndC, sortedEndL, sortedSeverity);
			}
		}else if (response["method"] == "window/showMessage" || response["method"] == "client/registerCapability"){
			continue;
		}

		QString responseType = "";
		if (requestsMap.contains(id)){
			responseType = requestsMap[id];
		}

		QJsonObject result = response["result"].toObject();

		if (responseType == "textDocument/hover") { // responses to requests (autocomplete,hover,etc)
			QString contents = result["contents"].toObject()["value"].toString();
			QString type = result["contents"].toObject()["kind"].toString();

			if (contents != ""){
				emit hoverInformationReceived(contents.replace("\n\n\n", "\n\n"), type, id);
			}
			continue;
		}else if (responseType == "textDocument/codeAction"){
			QJsonArray codeActions = response["result"].toArray();
			emit codeActionsReceived(codeActions); // it's complicated enough that we just send the stuff.
			continue;
		}else if (responseType == "textDocument/definition"){
			QJsonArray array = response["result"].toArray();
			if (array.size() == 0){
				continue;
			}

			QJsonObject location = array[0].toObject()["range"].toObject()["end"].toObject();
			int line = location["line"].toInt();
			int character = location["character"].toInt();
			
			location = array[0].toObject()["range"].toObject()["start"].toObject();
			int line1 = location["line"].toInt();
			int character1 = location["character"].toInt();
			
			QString locFile = response["result"].toArray()[0].toObject()["uri"].toString();

			emit gotoDefinitionsReceived(line1, character1, line, character, locFile);
			continue;
		}else if (responseType == "textDocument/completion"){
			QJsonArray items = result["items"].toArray();

			QStringList completions;
			QStringList sortTexts;

			for (const QJsonValue &item : items) {
				QJsonObject itmObj = item.toObject();
				if (itmObj.contains("insertText")){
					QString newStr = itmObj["insertText"].toString();

					if (completions.contains(newStr)){
						continue;
					}

					completions.append(newStr);
					if (itmObj.contains("sortText")){
						sortTexts.append(itmObj["sortText"].toString());
					}
				} else if (itmObj.contains("textEdit")){
					QString newStr = itmObj["textEdit"].toObject()["newText"].toString();

					if (completions.contains(newStr)){
						continue;
					}

					completions.append(newStr);
					if (itmObj.contains("sortText")){
						sortTexts.append(itmObj["sortText"].toString());
					}
				} else if (itmObj.contains("label")){
					QString newStr = itmObj["label"].toString();

					if (completions.contains(newStr)){
						continue;
					}

					completions.append(newStr);
					if (itmObj.contains("sortText")){
						sortTexts.append(itmObj["sortText"].toString());
					}
				}
			}

			if (sortTexts.length() == completions.length()){
				QVector<QPair<QString, QString>> combined;
				for (int i = 0; i < completions.size(); ++i) {
					combined.append(qMakePair(sortTexts[i], completions[i]));
				}

				std::sort(combined.begin(), combined.end(), [](const QPair<QString, QString>& a, const QPair<QString, QString>& b) {
					return a.first < b.first;
				});

				QStringList outLst;
				for (const auto& pair : combined) {
					outLst.append(pair.second);
				}

				emit completionReceived(outLst, id);
			}else{
				emit completionReceived(completions, id);
			}
			continue;
		}
	}
}

void LanguageServerClient::sendMessage(const QJsonObject &message)
{
	QByteArray data = QJsonDocument(message).toJson(QJsonDocument::Compact);
	QString header = QString("Content-Length: %1\r\n\r\n").arg(data.size());
	serverProcess.write(header.toUtf8());
	serverProcess.write(data);
}

QJsonObject LanguageServerClient::readMessage() // How do I put this? I'm a god.
{
	int bytesAvail = serverProcess.bytesAvailable();
	if (bytesAvail != 0){
		QByteArray line = serverProcess.read(bytesAvail);
		currentExecution += line;
	}

	int index = currentExecution.indexOf("Content-Length");

	if (index != -1) {
		QByteArray part1 = currentExecution.left(index);
		currentExecution = currentExecution.mid(index + 14);

		QJsonDocument doc = QJsonDocument::fromJson(part1);
		if (doc.isObject()){
			return QJsonDocument::fromJson(part1).object();
		}
	}

	index = currentExecution.indexOf("\r\n");

	if (index != -1) {
		QByteArray part1 = currentExecution.left(index);         // Part before "\r\n"
		currentExecution = currentExecution.mid(index + 2);     // Part after "\r\n" (skipping over "\r\n")

		QJsonDocument doc = QJsonDocument::fromJson(part1);
		if (doc.isObject()){
			return QJsonDocument::fromJson(part1).object();
		}
	}

	QJsonDocument doc = QJsonDocument::fromJson(currentExecution);
	if (doc.isObject()){
		QJsonObject obj = QJsonDocument::fromJson(currentExecution).object();
		currentExecution = "";
		return obj;
	}

	return QJsonObject();
}
