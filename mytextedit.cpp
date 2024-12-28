// MyTextEdit.cpp
#include "MyTextEdit.h"
#include <QMenu>
#include <QAction>
#include <QContextMenuEvent>

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

    if (menuStyle != ""){
        menu->setPalette(palette());
        menu->setStyleSheet(menuStyle);
    }

    menu->setFont(this->font());

    menu->addSeparator();
    menu->addAction(definitionAction);
    menu->exec(event->globalPos());
    delete menu;  // Clean up the menu
}
