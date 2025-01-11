#ifndef LANGUAGESERVERCLIENT_H
#define LANGUAGESERVERCLIENT_H

#include <QObject>
#include <QProcess>
#include <QJsonObject>
#include <QJsonDocument>
#include <QTextEdit>
#include <QEventLoop>

class LanguageServerClient : public QObject
{
	Q_OBJECT

public:
	explicit LanguageServerClient(const QString &serverPath, QTextEdit* providedTextEdit, QObject *parent = nullptr);
	~LanguageServerClient();

	void initialize(const QString &rootUri);
	void openDocument(const QString &uri, const QString &languageId, const QString &content);
	void closeDocument(const QString &uri);
	void updateDocument(const QString &content);
	int requestCompletion(int line, int character);
	int requestHover(int line, int character);
	void requestGotoDefinition(int line, int character);
	void requestActions(int line, int character, int line2, int character2);
	void documentSaved(QString text);
	void shutdown();

	bool isInitialized = false;
	QString lspPath;
	QStringList triggerChars;

signals:
	void completionReceived(const QStringList &completions, int id);
	void gotoDefinitionsReceived(int, int, QString uri);
	void receivedDiagnostics(const QStringList &messages, const QList<int> &startC, const QList<int> &startL, const QList<int> &endC, const QList<int> &endL, const QList<int> &severity);
	void serverErrorOccurred(const QString &error);  // Signal for server error
	void serverFinished(int exitCode, QProcess::ExitStatus exitStatus);  // Signal for process finish
	void initializeResponseReceived();
	void hoverInformationReceived(QString, QString, int id);
	void codeActionsReceived(const QJsonArray& codeActions);

private slots:
	void onServerReadyRead();
	void onServerErrorOccurred(QProcess::ProcessError error);  // Slot for process error
	void onServerFinished(int exitCode, QProcess::ExitStatus exitStatus);  // Slot for process finished

private:
	QJsonArray filterDiagnostics(const QJsonArray &diagnostics, int lineStart, int columnStart, int lineEnd, int columnEnd);
	void sendMessage(const QJsonObject &message);
	QJsonObject readMessage();

	QProcess serverProcess;
	int requestId;
	int documentVersion;
	QEventLoop initializeLoop;
};

#endif // LANGUAGESERVERCLIENT_H
