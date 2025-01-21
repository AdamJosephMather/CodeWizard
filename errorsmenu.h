#ifndef ERRORSMENU_H
#define ERRORSMENU_H

#include "mytextedit.h"
#include <QWidget>
#include <QObject> // Include QObject header for inheritance
#include <qlistwidget.h>

class ErrorsMenu : public QObject
{
	Q_OBJECT // This macro enables the signal-slot mechanism

public:
	ErrorsMenu(); // Constructor

	void Setup(MyTextEdit *t);
	void UpdateErrors(QList<int> lN, QStringList m, QList<int> s);
	void reposition();

private slots:
	void clickedOverlayErrors(QPoint pos);
	void clickedOverlayWarnings(QPoint pos);
	void clickedOverlayOther(QPoint pos);
	
	void onErrorItemClicked(QListWidgetItem* item);

private:
	void fillErrorsListWith(int sev);
	QList<int> findSeverities(int s);
	MyTextEdit* createOverlay(QString color);
	MyTextEdit* textEdit; // Pointer to MyTextEdit
	QStringList messages; // List of messages
	QList<int> lineNumbers; // List of line numbers
	QList<int> severity; // List of severities
	int currentlyShowing;

	MyTextEdit* overlayTextEditErrors;
	MyTextEdit* overlayTextEditWarnings;
	MyTextEdit* overlayTextEditOther;
	
	QListWidget* errorsList;
};

#endif // ERRORSMENU_H
