#include "groqai.h"
#include <qboxlayout.h>
#include <qdialog.h>
#include <qlabel.h>
#include "mytextedit.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QtNetwork>

GroqAI::GroqAI(QObject *parent)
	: QObject(parent),
	  m_networkManager(new QNetworkAccessManager(this))
{
	connect(m_networkManager, &QNetworkAccessManager::finished, this, &GroqAI::onNetworkReply);
}

GroqAI::~GroqAI()
{
}

void GroqAI::setApiKey(const QString &apiKey)
{
	m_apiKey = apiKey;
}

void GroqAI::setModel(const QString &model)
{
	m_model = model;
}

void GroqAI::setTextEdit(MyTextEdit* tE)
{
	textEdit = tE;
}

void GroqAI::openHelpMenu(QString text) {
	qDebug() << "openHelpMenu";

	// Create a simple help dialog
	QDialog *helpDialog = new QDialog();
	helpDialog->setWindowTitle("Help Menu");

	helpDialog->resize(700, 100); // seems to resize to the apropriate size given the text or something - it's the label that causes this I think

	QLabel *helpText = new QLabel(text, helpDialog);
	helpText->setWordWrap(true);
	helpText->setFont(textEdit->font());
	helpText->setTextInteractionFlags(Qt::TextSelectableByMouse);

	QVBoxLayout *layout = new QVBoxLayout(helpDialog);
	layout->addWidget(helpText);

	helpDialog->setLayout(layout);
	helpDialog->exec();
}

void GroqAI::generateResponse(const QList<QPair<QString, QString>> &conversation)
{
	if (m_apiKey.isEmpty() || m_model.isEmpty()) {
        openHelpMenu("API key or model is not set for Groq AI.");
		return;
	}

	QUrl apiUrl("https://api.groq.com/openai/v1/chat/completions");
	QNetworkRequest request(apiUrl);
	request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
	request.setRawHeader("Authorization", "Bearer " + m_apiKey.toUtf8());

	QJsonObject payload;
	payload["model"] = m_model;
	payload["messages"] = formatConversation(conversation);

	QJsonDocument doc(payload);
	QByteArray data = doc.toJson();

	m_networkManager->post(request, data);
}

void GroqAI::generateResponse(const QStringList &senders, const QStringList &messages)
{
	if (senders.size() != messages.size()) {
		qDebug() << "Senders != Messages length";
		return;
	}

	QList<QPair<QString, QString>> conversation;
	for (int i = 0; i < senders.size(); ++i) {
		conversation.append(qMakePair(senders[i], messages[i]));
	}

	generateResponse(conversation);
}

QJsonArray GroqAI::formatConversation(const QList<QPair<QString, QString>> &conversation)
{
	QJsonArray messages;
	for (const QPair<QString, QString> &entry : conversation) {
		QJsonObject messageObject;
		messageObject["role"] = entry.first;
		messageObject["content"] = entry.second;
		messages.append(messageObject);
	}
	return messages;
}

QJsonArray GroqAI::formatConversation(const QStringList &senders, const QStringList &messages)
{
	QJsonArray formatted;
	for (int i = 0; i < senders.size(); ++i) {
		QJsonObject messageObject;
		messageObject["sender"] = senders[i];
		messageObject["content"] = messages[i];
		formatted.append(messageObject);
	}
	return formatted;
}

void GroqAI::onNetworkReply(QNetworkReply *reply)
{
	if (reply->error() != QNetworkReply::NoError) {
        openHelpMenu(reply->errorString());
		qDebug() << reply->errorString();
		reply->deleteLater();
		return;
	}

	QByteArray responseData = reply->readAll();
	QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
	if (jsonResponse.isObject()) {
		QJsonObject responseObject = jsonResponse.object();
		if (responseObject.contains("choices")) {
			qDebug() << responseObject["choices"];
			qDebug() << responseObject["choices"].toArray()[0];
			qDebug() << responseObject["choices"].toArray()[0].toObject()["message"];
			qDebug() << responseObject["choices"].toArray()[0].toObject()["message"].toObject()["content"];
			
			emit responseReceived(responseObject["choices"].toArray()[0].toObject()["message"].toObject()["content"].toString());
		} else {
			qDebug() << "Invalid response format." << responseData << "\n\n" << jsonResponse;
		}
	} else {
		qDebug() << "Failed to parse JSON response.\n\n" << responseData;
	}

	reply->deleteLater();
}
