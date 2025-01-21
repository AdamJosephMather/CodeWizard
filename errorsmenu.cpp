#include "errorsmenu.h"
#include "mytextedit.h"
#include <qwidget.h>

//need to call reposition from updateMargins

ErrorsMenu::ErrorsMenu() {}

void ErrorsMenu::Setup(MyTextEdit *t) {
	qDebug() << "Setup - ErrMenu";
	textEdit = t;
	
	overlayTextEdit = new MyTextEdit(t);
	overlayTextEdit->setStyleSheet(
		"QTextEdit {"
		"   border: 2px solid red;"
		"   border-radius: 6px;"
		"   color: red;"
		"   background: transparent;"
		"   text-align: center;"
		"   vertical-align: middle;"
		"}"
	);
	overlayTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	overlayTextEdit->setTextInteractionFlags(Qt::TextBrowserInteraction);
	overlayTextEdit->setCursor(Qt::PointingHandCursor);
	
	MyTextEdit::connect(overlayTextEdit, &MyTextEdit::mouseClicked, this, &ErrorsMenu::clickedOverlay);
	
	overlayTextEdit->setText("0");
	
	errorsList = new QListWidget(textEdit);
	errorsList->setFocusPolicy(Qt::NoFocus);
	
	reposition();
	overlayTextEdit->hide();
	errorsList->hide();
	
	connect(errorsList, &QListWidget::itemClicked, this, &ErrorsMenu::onErrorItemClicked);
}

void ErrorsMenu::onErrorItemClicked(QListWidgetItem* item){
	qDebug() << "onErrorItemClicked - errMenu";

	int selected = errorsList->row(item);
	
	int lineNumber = lineNumbers[selected]+1;
	
	QTextCursor cursor = textEdit->textCursor();
	cursor.movePosition(QTextCursor::Start);
	for (int i = 1; i < lineNumber; ++i) {
		cursor.movePosition(QTextCursor::Down);
	}
	textEdit->setTextCursor(cursor);
}

void ErrorsMenu::clickedOverlay(QPoint pos){
	qDebug() << "clickedOverlay - errMenu";
	reposition();
	
	if (errorsList->isVisible()){
		errorsList->hide();
	}else{
		errorsList->show();
	}
}

void ErrorsMenu::UpdateErrors(QList<int> ln, QStringList m){
	qDebug() << "UpdateErrors - ErrMenu" << lineNumbers;
	
	lineNumbers = ln;
	messages = m;
	
	overlayTextEdit->setText(QString::number(lineNumbers.length()));
	reposition();
	
	if (lineNumbers.length() > 0){
		overlayTextEdit->show();
	}else{
		errorsList->hide();
		overlayTextEdit->hide();
	}
	
	errorsList->clear();
	for (int i = 0; i < lineNumbers.length(); i++){
		errorsList->addItem(QString::number(lineNumbers[i]+1)+" - "+messages[i].split("\n")[0]);		
	}
}

void ErrorsMenu::reposition(){
	qDebug() << "reposition - ErrMenu";
	
	overlayTextEdit->setFont(textEdit->font());
	errorsList->setFont(textEdit->font());
	QFontMetrics metrics(textEdit->font());
	
	int ow = overlayTextEdit->toPlainText().length()*metrics.horizontalAdvance("M") + 15;
	int oh = metrics.height() + 10;
	
	int x = textEdit->geometry().width() - ow - 20;
	int y = textEdit->geometry().height() - oh - 20;
	
	qDebug() << x << y << ow << oh;
	
	overlayTextEdit->setGeometry(x, y, ow, oh);
	
	int eW = 500;
	int eH = metrics.height()*(2+lineNumbers.length());
	if (eH > 350){
		eH = 350;
	}
	x = textEdit->geometry().width() - eW - 20;
	y = y - eH - 20;
	
	errorsList->setGeometry(x, y, eW, eH);
	errorsList->setFont(textEdit->font());
}