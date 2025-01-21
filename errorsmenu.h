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
	void UpdateErrors(QList<int> lineNumbers, QStringList messages);
	void reposition();

private slots:
	void clickedOverlay(QPoint pos); // Slot for handling the clicked event
	void onErrorItemClicked(QListWidgetItem* item);

private:
	MyTextEdit* textEdit; // Pointer to MyTextEdit
	QStringList messages; // List of messages
	QList<int> lineNumbers; // List of line numbers

	MyTextEdit* overlayTextEdit; // Pointer to the overlay text edit
	QListWidget* errorsList;
};

#endif // ERRORSMENU_H
