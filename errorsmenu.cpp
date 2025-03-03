#include "errorsmenu.h"
#include "mytextedit.h"
#include <qwidget.h>

//need to call reposition from updateMargins

ErrorsMenu::ErrorsMenu() {}

void ErrorsMenu::Setup(MyTextEdit *t) {
	qDebug() << "Setup - ErrMenu";
	textEdit = t;

	overlayTextEditErrors = createOverlay("red");
	overlayTextEditWarnings = createOverlay("orange");
	overlayTextEditOther = createOverlay("blue");

	MyTextEdit::connect(overlayTextEditErrors, &MyTextEdit::mouseClicked, this, &ErrorsMenu::clickedOverlayErrors);
	MyTextEdit::connect(overlayTextEditWarnings, &MyTextEdit::mouseClicked, this, &ErrorsMenu::clickedOverlayWarnings);
	MyTextEdit::connect(overlayTextEditOther, &MyTextEdit::mouseClicked, this, &ErrorsMenu::clickedOverlayOther);

	overlayTextEditErrors->setText("0");
	overlayTextEditWarnings->setText("0");
	overlayTextEditOther->setText("0");

	errorsList = new QListWidget(textEdit);
	errorsList->setFocusPolicy(Qt::NoFocus);

	reposition();
	overlayTextEditErrors->hide();
	overlayTextEditWarnings->hide();
	overlayTextEditOther->hide();
	errorsList->hide();
	currentlyShowing = -1;

    connect(errorsList, &QListWidget::itemClicked, this, &ErrorsMenu::onErrorItemClicked);
}

void ErrorsMenu::recolor(QColor backColor){
	QPalette palette = errorsList->palette();
	palette.setColor(QPalette::Base, backColor);
	errorsList->setPalette(palette);
}

MyTextEdit* ErrorsMenu::createOverlay(QString color){
	qDebug() << "createOverlay - errMenu";
	MyTextEdit* overlayTextEdit = new MyTextEdit(textEdit);
	overlayTextEdit->setStyleSheet(
		"QTextEdit {"
		"   border: 2px solid "+color+";"
		"   border-radius: 10px;"
		"   color: "+color+";"
		"   background: transparent;"
		"   text-align: center;"
		"   vertical-align: middle;"
		"}"
	);
	overlayTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	overlayTextEdit->setTextInteractionFlags(Qt::TextBrowserInteraction);
	overlayTextEdit->setCursor(Qt::PointingHandCursor);
	return overlayTextEdit;
}

void ErrorsMenu::onErrorItemClicked(QListWidgetItem* item){
	qDebug() << "onErrorItemClicked - errMenu";
	int selected = errorsList->row(item);
	QList<int> itms = findSeverities(currentlyShowing);
	int lineNumber = lineNumbers[itms[selected]]+1;

	QTextCursor cursor = textEdit->textCursor();
	cursor.movePosition(QTextCursor::Start);
	for (int i = 1; i < lineNumber; ++i) {
		cursor.movePosition(QTextCursor::Down);
	}
	textEdit->setTextCursor(cursor);
}

void ErrorsMenu::clickedOverlayOther(QPoint pos){
	qDebug() << "clickedOverlayOther - errMenu";
	reposition();

	if (currentlyShowing != 2 || !errorsList->isVisible()){
		currentlyShowing = 2;
		fillErrorsListWith(2);
		reposition();
		errorsList->show();
	}else{
		currentlyShowing = -1;
		errorsList->hide();
	}
}

void ErrorsMenu::clickedOverlayWarnings(QPoint pos){
	qDebug() << "clickedOverlayOther - errMenu";
	reposition();

	if (currentlyShowing != 1 || !errorsList->isVisible()){
		currentlyShowing = 1;
		fillErrorsListWith(1);
		reposition();
		errorsList->show();
	}else{
		currentlyShowing = -1;
		errorsList->hide();
	}
}

void ErrorsMenu::clickedOverlayErrors(QPoint pos){
	qDebug() << "clickedOverlayOther - errMenu";
	reposition();

	if (currentlyShowing != 0 || !errorsList->isVisible()){
		currentlyShowing = 0;
		fillErrorsListWith(0);
		reposition();
		errorsList->show();
	}else{
		currentlyShowing = -1;
		errorsList->hide();
	}
}

void ErrorsMenu::fillErrorsListWith(int sev){
	errorsList->clear();
	QList<int> itms = findSeverities(sev);
	for (int i = 0; i < itms.length(); i++){
		errorsList->addItem(QString::number(lineNumbers[itms[i]]+1)+" - "+messages[itms[i]].split("\n")[0]);
	}
	if (itms.length() == 0){
		errorsList->hide();
	}
}

void ErrorsMenu::UpdateErrors(QList<int> ln, QStringList m, QList<int> s){
	qDebug() << "UpdateErrors - ErrMenu" << lineNumbers;

	lineNumbers = ln;
	messages = m;
	severity = s;

	reposition();

	if (currentlyShowing != -1){
		fillErrorsListWith(currentlyShowing);
	}else{
		errorsList->hide();
	}
}

QList<int> ErrorsMenu::findSeverities(int s){
	QList<int> errIndexes;

	for (int i = 0; i < severity.length(); i++){
		if (severity[i] == s+1){ // 1, 2, 3, 4 (3&4 are other)
			errIndexes.push_back(i);
		}else if (s+1 == 3 && severity[i] == s+2){
			errIndexes.push_back(i);
		}
	}

	return errIndexes;
}

void ErrorsMenu::reposition(){
	qDebug() << "reposition - ErrMenu";

	overlayTextEditErrors->setFont(textEdit->font());
	overlayTextEditWarnings->setFont(textEdit->font());
	overlayTextEditOther->setFont(textEdit->font());
	errorsList->setFont(textEdit->font());

	QFontMetrics metrics(textEdit->font());

	int curLocX = textEdit->geometry().width() - 20;
	int oh = metrics.height() + 11;
	int y = textEdit->geometry().height() - oh - 20;

	QList<int> errIndexes = findSeverities(0);
	if (errIndexes.length() != 0){
		overlayTextEditErrors->setText(QString::number(errIndexes.length()));
		int ow = QString::number(errIndexes.length()).length()*metrics.horizontalAdvance("M") + 15;
		curLocX = curLocX-ow;
		overlayTextEditErrors->setGeometry(curLocX, y, ow, oh);
		overlayTextEditErrors->show();
		curLocX = curLocX-10;
	}else{
		overlayTextEditErrors->hide();
	}

	QList<int> warnIndexes = findSeverities(1);
	if (warnIndexes.length() != 0){
		overlayTextEditWarnings->setText(QString::number(warnIndexes.length()));
		int ow = QString::number(warnIndexes.length()).length()*metrics.horizontalAdvance("M") + 15;
		curLocX = curLocX-ow;
		overlayTextEditWarnings->setGeometry(curLocX, y, ow, oh);
		overlayTextEditWarnings->show();
		curLocX = curLocX-10;
	}else{
		overlayTextEditWarnings->hide();
	}

	QList<int> othIndexes = findSeverities(2);
	if (othIndexes.length() != 0){
		overlayTextEditOther->setText(QString::number(othIndexes.length()));
		int ow = QString::number(othIndexes.length()).length()*metrics.horizontalAdvance("M") + 14;
		curLocX = curLocX-ow;
		overlayTextEditOther->setGeometry(curLocX, y, ow, oh);
		overlayTextEditOther->show();
		curLocX = curLocX-10;
	}else{
		overlayTextEditOther->hide();
	}

	int eW = 500;
	int eH = metrics.height()*(2+findSeverities(currentlyShowing).length());
	if (eH > 350){
		eH = 350;
	}
	int x = textEdit->geometry().width() - eW - 20;
	y = y - eH - 20;

	errorsList->setGeometry(x, y, eW, eH);
	errorsList->setFont(textEdit->font());
}
