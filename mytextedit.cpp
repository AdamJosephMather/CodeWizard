#include "MyTextEdit.h"
#include <QMenu>
#include <QAction>
#include <QContextMenuEvent>
#include <qregularexpression.h>
#include <qscrollbar.h>

QString menuStyle = "";

MyTextEdit::MyTextEdit(QWidget *parent) : QTextEdit(parent) {
	setMouseTracking(true);
}

void MyTextEdit::setContextMenuStyle(const QString& stylesheet) {
	menuStyle = stylesheet;
}

QString MyTextEdit::changeToTabs(QString text){
	QStringList lines = text.split("\n");
	QStringList newLines;
	
	for (QString line : lines){
		int seen = 0;
		QString rest = "";
		bool doneSeen = false;
		
		for (QChar c : line){
			if (c == ' ' && !doneSeen){
				seen ++;
			}else{
				doneSeen = true;
				rest += c;
			}
		}
		
		int tabs = seen/4;
		int spaces = seen%4;
		
		QString outLine = "";
		
		for (int i = 0; i < tabs; i++){
			outLine += "	";
		}
		
		for (int i = 0; i < spaces; i++){
			outLine += " ";
		}
		
		outLine += rest;
		
		newLines.push_back(outLine);
	}
	
	return newLines.join("\n");
}

void MyTextEdit::insertFromMimeData(const QMimeData *source) {
	if (source->hasText()) {
		this->insertPlainText(changeToTabs(source->text()));
	}
}

void MyTextEdit::contextMenuEvent(QContextMenuEvent *event) {
	QMenu* menu = createStandardContextMenu();  // Create the default context menu
	QAction* definitionAction = new QAction("Goto Definition", this);
	connect(definitionAction, &QAction::triggered, this, [this]() {
		emit MyTextEdit::gotoDefinitionActionTriggered();
	});

	if (menuStyle != "") {
		menu->setPalette(palette());
		menu->setStyleSheet(menuStyle);
	}

	menu->setFont(this->font());

	menu->addSeparator();
	menu->addAction(definitionAction);
	menu->exec(event->globalPos());
	delete menu;  // Clean up the menu
}

void MyTextEdit::wheelEvent(QWheelEvent *event) {
	// Check if Shift key is pressed
	if (event->modifiers() & Qt::ShiftModifier) {
		// Scroll horizontally
		horizontalScrollBar()->setValue(horizontalScrollBar()->value() - event->angleDelta().y());
	} else {
		// Default vertical scrolling behavior
		QTextEdit::wheelEvent(event);
	}
}
