#ifndef GROQAI_H
#define GROQAI_H

#include "mytextedit.h"
#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QList>
#include <QPair>

class GroqAI : public QObject
{
	Q_OBJECT

public:
	explicit GroqAI(QObject *parent = nullptr);
	~GroqAI();

	void setApiKey(const QString &apiKey);
	void setModel(const QString &model);
	void setTextEdit(MyTextEdit* tE);

	// Overloaded methods to handle different conversation formats
	void generateResponse(const QList<QPair<QString, QString>> &conversation);
	void generateResponse(const QStringList &senders, const QStringList &messages);

signals:
	void responseReceived(const QString &response);
	void errorOccurred(const QString &errorString);

private slots:
	void onNetworkReply(QNetworkReply *reply);

private:
	MyTextEdit* textEdit;
	void openHelpMenu(QString text);
	QString m_apiKey;
	QString m_model;
	QNetworkAccessManager *m_networkManager;

	QJsonArray formatConversation(const QList<QPair<QString, QString>> &conversation);
	QJsonArray formatConversation(const QStringList &senders, const QStringList &messages);
};

#endif // GROQAI_H
