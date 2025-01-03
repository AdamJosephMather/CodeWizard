#include "MyTextEdit.h"
#include <QMenu>
#include <QAction>
#include <QContextMenuEvent>
#include <qscrollbar.h>

QString menuStyle = "";

MyTextEdit::MyTextEdit(QWidget *parent) : QTextEdit(parent) {
	setMouseTracking(true);
}

void MyTextEdit::setContextMenuStyle(const QString& stylesheet) {
	menuStyle = stylesheet;
}

void MyTextEdit::insertFromMimeData(const QMimeData *source) {
	if (source->hasText()) {
		this->insertPlainText(source->text());
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
