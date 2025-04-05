#ifdef _WIN32
#include "mytextedit.h"
#else
#include "/home/adamj/QtProjects/CodeWizard/mytextedit.h"
#endif

#include <QMenu>
#include <QAction>
#include <QContextMenuEvent>
#include <qregularexpression.h>
#include <qscrollbar.h>
#include <QTextCursor>
#include <QList>
#include <QAbstractTextDocumentLayout>
#include <QTextBlock>
#include <QClipboard>

QString menuStyle = "";

MyTextEdit::MyTextEdit(QWidget *parent) : QTextEdit(parent) {
	setMouseTracking(true);
	
	int blinkRate = QApplication::cursorFlashTime(); 
	
	// Set up a timer to toggle the cursor visibility
	cursorBlinkTimer.setInterval(blinkRate / 2);
	connect(&cursorBlinkTimer, &QTimer::timeout, this, &MyTextEdit::toggleCursorVisibility);
	cursorBlinkTimer.start();
}

void MyTextEdit::focusInEvent(QFocusEvent *event){
	QTextEdit::focusInEvent(event);
	emit focusChange(true);
	updateViewport(); // focus bar
}

void MyTextEdit::focusOutEvent(QFocusEvent *event) {
	QTextEdit::focusOutEvent(event);
	emit focusChange(false);
	updateViewport(); // focus bar
}

void MyTextEdit::toggleCursorVisibility() {
	cursorBlinking = !cursorBlinking;
	updateViewport();  // Trigger a repaint if needed
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
	
	QAction* renameAction = new QAction("Rename Property", this);
	connect(renameAction, &QAction::triggered, this, [this]() {
		emit MyTextEdit::renameActionTriggered();
	});

	if (menuStyle != "") {
		menu->setPalette(palette());
		menu->setStyleSheet(menuStyle);
	}

	menu->setFont(this->font());

	menu->addSeparator();
	menu->addAction(definitionAction);
	menu->addAction(renameAction);
	
	menu->exec(event->globalPos());
	
	delete menu;
}

void MyTextEdit::wheelEvent(QWheelEvent *event) {
	emit wheelSignal(event);
	
	if (dontScroll){
		event->ignore();
		return;
	}
	
	if (event->modifiers() & Qt::ShiftModifier) {
		horizontalScrollBar()->setValue(horizontalScrollBar()->value() - event->angleDelta().y());
		event->accept();
	} if (event->modifiers() & Qt::ControlModifier) { // override the default behavior
		verticalScrollBar()->setValue(verticalScrollBar()->value() - event->angleDelta().y()*2);
		event->accept();
	} else {
		QTextEdit::wheelEvent(event);
	}
}

void MyTextEdit::drawSelection(QPainter &painter, QTextCursor cursor, bool onEnd)
{
	if (!cursor.hasSelection())
		return;
	
	qreal extra;
	if (onEnd){
		extra = fontMetrics().horizontalAdvance("M")/2;
	}
	
	// Get the rectangle for the selection
	QTextDocument *doc = cursor.document();
	QTextLayout *layout = cursor.block().layout();
	
	int selectionStart = cursor.selectionStart() - cursor.block().position();
	int selectionEnd = cursor.selectionEnd() - cursor.block().position();
	
	QTextLine line = layout->lineForTextPosition(selectionStart);
	
	// Calculate the selection rectangle
	qreal x1 = line.cursorToX(selectionStart);
	qreal x2 = line.cursorToX(selectionEnd);
	qreal y = line.y() + layout->position().y() - 4;
	qreal height = line.height();
	qreal width = x2 - x1 + extra;
	
	QRectF selectionRect(x1, y, width, height);
	
	// Apply document margins
	selectionRect.translate(doc->documentMargin()-horizontalScrollBar()->value(), doc->documentMargin()-verticalScrollBar()->value());
	
	// Set semi-transparent grey color
	painter.setPen(Qt::NoPen);
	painter.setBrush(QColor(128, 128, 128, 128)); // Semi-transparent grey
	
	// Draw the selection rectangle
	painter.drawRect(selectionRect);
}

void MyTextEdit::drawCursor(QPainter &painter, const QTextCursor &cursor, const QColor &color)
{
	QTextBlock block = cursor.block();
	if (!block.isValid()) {
		return;
	}
	
	QAbstractTextDocumentLayout *layout = document()->documentLayout();
	
	if (cursor.hasSelection()){
		QTextCursor c = textCursor();
		c.setPosition(cursor.selectionStart());
		while (true){
			c.movePosition(QTextCursor::EndOfLine, QTextCursor::KeepAnchor);
			if (c.position() >= cursor.selectionEnd()){
				c.setPosition(cursor.selectionEnd(), QTextCursor::KeepAnchor);
				drawSelection(painter, c, false);
				break;
			}
			drawSelection(painter, c, true);
			c.movePosition(QTextCursor::Down);
			c.movePosition(QTextCursor::StartOfLine);
		}
		
	}
	
	if (cursorBlinking){
		return;
	}
	
	int cursorPosition = cursor.position() - block.position();
	QTextLine line = block.layout()->lineForTextPosition(cursorPosition);
	if (!line.isValid()) {
		return;
	}
	
	qreal x = line.cursorToX(cursorPosition);
	QPointF blockPos = layout->blockBoundingRect(block).topLeft();
	int width = cursorWidth();
	qreal height = line.height();
	qreal top = blockPos.y() + line.y();
	QPoint offset = -QPoint(horizontalScrollBar()->value(), verticalScrollBar()->value());
	
	painter.setPen(Qt::NoPen);
	painter.setBrush(color);
	painter.drawRect(QRectF(blockPos.x() + x + offset.x(),
						   top + offset.y(),
						   width,
						   height));
}

void MyTextEdit::paintEvent(QPaintEvent *event)
{
	// First let the standard paint event handle the default drawing
	QTextEdit::paintEvent(event);
	
	if (useMultiCursors){
		// Then draw our additional cursors on top
		QPainter painter(viewport());
		
		// Draw all additional cursors
		for (const QTextCursor &cursor : additionalCursors) {
			// Use a different color for additional cursors to distinguish them
			drawCursor(painter, cursor, QColor(255, 165, 0)); // Orange color
		}
	}
	
	QAbstractTextDocumentLayout *layout = document()->documentLayout();
	QPoint offset = -QPoint(horizontalScrollBar()->value(), verticalScrollBar()->value());
	
	QPainter painter(viewport());
	painter.setPen(Qt::red);
	
	QColor warnings = QColor(217, 159, 0);
	QColor other = QColor(38, 175, 199);
	QColor errors = QColor(255, 70, 0);
	
	QFontMetrics fm = painter.fontMetrics();
	
	for (int i = 0; i < errLineNums.length(); i++){
		int lnNum = errLineNums[i];
		QString errMessage = " ■ "+errMessages[i];
		int sev = errTypes[i];
		
		if (sev == 1) { // Errors
			painter.setPen(errors);
		} else if (sev == 2) { // Warnings
			painter.setPen(warnings);
		} else { // Other
			painter.setPen(other);
		}
		
		QTextBlock block = document()->findBlockByLineNumber(lnNum);
		if (!block.isValid()) continue;
		QTextCursor cursor(block);
		cursor.movePosition(QTextCursor::EndOfLine);
		
		int cursorPosition = cursor.position() - block.position();
		QTextLine line = block.layout()->lineForTextPosition(cursorPosition);
		if (!line.isValid()) {
			return;
		}
		
		qreal x = line.cursorToX(cursorPosition);
		QPointF blockPos = layout->blockBoundingRect(block).topLeft();
		qreal top = blockPos.y() + line.y();
		
		QPointF pos(blockPos.x() + x + offset.x() + 35, top + offset.y() + line.height() - fm.descent());
		painter.drawText(pos, errMessage);
	}
}

void MyTextEdit::setCurrentVim(QString vmMd){
	currentVimMode = vmMd;
	additionalCursors.clear();
	vimRepeater = 0;
	
	if (vmMd == "i"){
		setCursorWidth(1);
	}else{
		QFontMetrics metrics(font());
		int charWidth = metrics.horizontalAdvance("M");
		setCursorWidth(charWidth);
	}
	
	updateViewport();
}

void MyTextEdit::setVIM(bool uV){
	useVIM = uV;
	additionalCursors.clear();
	currentVimMode = "i";
	setCursorWidth(1);
	vimRepeater = 0;
	updateViewport();
}

void MyTextEdit::executeNormalAct(QTextCursor::MoveOperation move, QKeyEvent *key_event){
	if (vimRepeater == 0){
		vimRepeater = 1;
	}

	QTextCursor cursor = textCursor();
	if (key_event->modifiers() && Qt::ShiftModifier){
		cursor.movePosition(move, QTextCursor::KeepAnchor, vimRepeater);
	}else{
		cursor.movePosition(move, QTextCursor::MoveAnchor, vimRepeater);
	}
	setTextCursor(cursor);
	vimRepeater = 0;
	
	emit executedNormalAct(move, key_event, vimRepeater);
}

bool MyTextEdit::eventFilter(QObject *watched, QEvent *event){
	return false;
}

void MyTextEdit::keyPressEvent(QKeyEvent *event)
{
	if (useVIM) {
		bool isACtrl = event->modifiers() & Qt::ControlModifier || event->modifiers() & Qt::AltModifier;
		
		if (!isACtrl && currentVimMode == "n"){
			QString keyText = event->text();

			if (keyText.length() == 1 && keyText[0].isDigit()){
				vimRepeater = vimRepeater*10 + keyText[0].digitValue();
			}
			
			if (event->key() == Qt::Key_I){
				currentVimMode = "i";
				setCursorWidth(1);
				additionalCursors.clear();
				updateViewport();
				vimRepeater = 0;
			}else if (event->key() == Qt::Key_J || event->key() == Qt::Key_Down){
				executeNormalAct(QTextCursor::Down, event);
			}else if (event->key() == Qt::Key_K || event->key() == Qt::Key_Up){
				executeNormalAct(QTextCursor::Up, event);
			}else if (event->key() == Qt::Key_H || event->key() == Qt::Key_Left){
				executeNormalAct(QTextCursor::Left, event);
			}else if (event->key() == Qt::Key_L || event->key() == Qt::Key_Right){
				executeNormalAct(QTextCursor::Right, event);
			}else if (event->key() == Qt::Key_E){
				executeNormalAct(QTextCursor::WordRight, event);
			}else if (event->key() == Qt::Key_W){
				executeNormalAct(QTextCursor::WordLeft, event);
			}else if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return || event->key() == Qt::Key_Backspace || event->key() == Qt::Key_Home || event->key() == Qt::Key_End || event->key() == Qt::Key_PageUp || event->key() == Qt::Key_PageDown || event->key() == Qt::Key_F5){
				return QTextEdit::keyPressEvent(event); // I am electing not to handle these in any special way - also CodeWizard for the win
			}else if (event->key() == Qt::Key_C){
				QKeyEvent *copyEvent = new QKeyEvent(QEvent::KeyPress, Qt::Key_C, Qt::ControlModifier);
				QCoreApplication::postEvent(this, copyEvent);
			}else if (event->key() == Qt::Key_X){
				QKeyEvent *copyEvent = new QKeyEvent(QEvent::KeyPress, Qt::Key_X, Qt::ControlModifier);
				QCoreApplication::postEvent(this, copyEvent);
			}else if (event->key() == Qt::Key_V){
				QKeyEvent *copyEvent = new QKeyEvent(QEvent::KeyPress, Qt::Key_V, Qt::ControlModifier);
				QCoreApplication::postEvent(this, copyEvent);
			}else if (event->key() == Qt::Key_G){ // gotoline
				QTextCursor cursor = textCursor();
				int curLine = cursor.blockNumber()+1; // 0 based
				int diff = vimRepeater-curLine;
				
				auto keepers = QTextCursor::MoveAnchor;
				if (event->modifiers() & Qt::ShiftModifier){
					keepers = QTextCursor::KeepAnchor;
				}
				
				if (diff > 0){
					cursor.movePosition(QTextCursor::Down, keepers, diff);
				}if (diff < 0){
					cursor.movePosition(QTextCursor::Up, keepers, abs(diff));
				}
				
				setTextCursor(cursor);
				vimRepeater = 0;
			}else if (event->key() == Qt::Key_O){
				currentVimMode = "i";
				setCursorWidth(1);
				additionalCursors.clear();
				updateViewport();
				vimRepeater = 0;
				executeNormalAct(QTextCursor::EndOfLine, event);
				QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Return, Qt::NoModifier, "");
				QCoreApplication::postEvent(this, event);
			}else if (event->key() == Qt::Key_A){
				currentVimMode = "i";
				setCursorWidth(1);
				additionalCursors.clear();
				updateViewport();
				vimRepeater = 0;
				executeNormalAct(QTextCursor::EndOfLine, event);
			}else if (event->key() == Qt::Key_Dollar || event->key() == Qt::Key_4 && event->modifiers() & Qt::ShiftModifier){
				vimRepeater = 0;
				executeNormalAct(QTextCursor::EndOfLine, new QKeyEvent(QEvent::KeyPress, Qt::Key_unknown, Qt::NoModifier));
			}else if (event->key() == Qt::Key_AsciiCircum || event->key() == Qt::Key_6 && event->modifiers() & Qt::ShiftModifier){
				vimRepeater = 0;
				executeNormalAct(QTextCursor::StartOfLine, new QKeyEvent(QEvent::KeyPress, Qt::Key_unknown, Qt::NoModifier));
			}

			return; // always handle inputs in normal mode - normal is a strange term for this but whatever - it'll work.
		}else if (currentVimMode == "i"){
			if (event->key() == Qt::Key_Escape){
				currentVimMode = "n";
				additionalCursors.clear();
				QFontMetrics metrics(font());
				int charWidth = metrics.horizontalAdvance("M");
				setCursorWidth(charWidth);
				vimRepeater = 0;
				updateViewport();
				return;
			}
		}
	}
	
	if (additionalCursors.isEmpty() || !useMultiCursors) {
		if (event->modifiers() & Qt::ControlModifier && (event->key() == Qt::Key_C || event->key() == Qt::Key_X)){
			coppies.clear();
		}
		
		QTextEdit::keyPressEvent(event);
		return;
	}
	
	// Store the original cursor before we start manipulating
	m_originalCursor = textCursor();
	
	// Handle different key types
	switch (event->key()) {
		// Navigation keys
		case Qt::Key_Left:
		case Qt::Key_Right:
		case Qt::Key_Up:
		case Qt::Key_Down:
		case Qt::Key_Home:
		case Qt::Key_End:
			handleNavigationKey(event);
			break;
			
		// Deletion keys
		case Qt::Key_Backspace:
		case Qt::Key_Delete:
			handleDeletionKey(event);
			break;
		
		case Qt::Key_Tab:
			insertTextAtAllCursors("\t");
			break;
	
		case Qt::Key_Return:
		case Qt::Key_Enter:
			insertTextAtAllCursors("\n");
			break;
			
		default:
			if (event->modifiers() & Qt::ControlModifier && event->key() == Qt::Key_V){
				pasteText();
			} else if (event->modifiers() & Qt::ControlModifier && event->key() == Qt::Key_C){
				getCopyText();
			} else if (event->modifiers() & Qt::ControlModifier && event->key() == Qt::Key_X){
				getCopyText();
				insertTextAtAllCursors("");
			} else if (!event->text().isEmpty() && event->text()[0].isPrint() && !(event->modifiers() & Qt::ControlModifier)) {
				insertTextAtAllCursors(event->text());
			} else {
				// For special keys we haven't specifically handled, use default behavior
				QTextEdit::keyPressEvent(event);
			}
			break;
	}
	
	// Ensure viewport is updated to reflect cursor changes
	cursorBlinking = false;
	viewport()->update();
}

void MyTextEdit::pasteText(){
	if (coppies.length() != additionalCursors.length()+1){
		QClipboard *clipboard = QGuiApplication::clipboard();
		QString textToPaste = changeToTabs(clipboard->text());
		insertTextAtAllCursors(textToPaste);
	}else{
		QTextCursor mainCursor = textCursor();
		mainCursor.beginEditBlock();
		
		mainCursor.insertText(coppies[0]);
		
		for (int i = 0; i < additionalCursors.length(); i++){
			QTextCursor cursor = additionalCursors[i];
			cursor.insertText(coppies[i+1]);
		}
		
		mainCursor.endEditBlock();
	}
}

void MyTextEdit::getCopyText(){
	coppies.clear();
	coppies.push_back(textCursor().selectedText());
	
	for (QTextCursor cursor : additionalCursors){
		coppies.push_back(cursor.selectedText());
	}
}

void MyTextEdit::applyToAllCursors(const std::function<void(QTextCursor&)>& operation)
{
	// Create a document modification group to make this a single undo operation
	QTextCursor mainCursor = textCursor();
	mainCursor.beginEditBlock();
	
	// Apply to all additional cursors first
	for (int i = 0; i < additionalCursors.size(); ++i) {
		QTextCursor cursor = additionalCursors[i];
		operation(cursor);
		additionalCursors[i] = cursor;
	}
	
	// Apply to the main cursor last (so it's where the user sees the action)
	operation(mainCursor);
	setTextCursor(mainCursor);
	
	mainCursor.endEditBlock();
}

void MyTextEdit::insertTextAtAllCursors(const QString &text)
{
	applyToAllCursors([&](QTextCursor &cursor) {
		cursor.insertText(text);
	});
	handleDuplicateCursors();
}

void MyTextEdit::handleNavigationKey(QKeyEvent *event)
{
	// Define the cursor move operation based on the key and modifiers
	QTextCursor::MoveOperation moveOp;
	QTextCursor::MoveMode moveMode = event->modifiers() & Qt::ShiftModifier ? 
									QTextCursor::KeepAnchor : QTextCursor::MoveAnchor;
	
	bool control = event->modifiers() & Qt::ControlModifier;
	
	switch (event->key()) {
		case Qt::Key_Left:
			if (control){
				moveOp = QTextCursor::WordLeft;
			}else{
				moveOp = QTextCursor::Left;
			}
			break;
		case Qt::Key_Right:
			if (control){
				moveOp = QTextCursor::WordRight;
			}else{
				moveOp = QTextCursor::Right;
			}
			break;
		case Qt::Key_Up:
			moveOp = QTextCursor::Up;
			break;
		case Qt::Key_Down:
			moveOp = QTextCursor::Down;
			break;
		case Qt::Key_Home:
			if (control)
				moveOp = QTextCursor::Start;
			else
				moveOp = QTextCursor::StartOfLine;
			break;
		case Qt::Key_End:
			if (control)
				moveOp = QTextCursor::End;
			else
				moveOp = QTextCursor::EndOfLine;
			break;
		default:
			return;
	}
	
	// Apply the move operation to all cursors
	applyToAllCursors([&](QTextCursor &cursor) {
		cursor.movePosition(moveOp, moveMode);
	});
	
	handleDuplicateCursors();
}

void MyTextEdit::handleDeletionKey(QKeyEvent *event)
{
	if (event->key() == Qt::Key_Backspace) {
		applyToAllCursors([&](QTextCursor &cursor) {
			cursor.deletePreviousChar();
		});
	} else if (event->key() == Qt::Key_Delete) {
		applyToAllCursors([&](QTextCursor &cursor) {
			cursor.deleteChar();
		});
	}
	
	handleDuplicateCursors();
}

void MyTextEdit::updateViewport(){
	viewport()->update();
}

void MyTextEdit::handleDuplicateCursors(){
	m_originalCursor = textCursor();
	
	for (int i = additionalCursors.length()-1; i >= 0; i--){
		QTextCursor c1;
		c1 = additionalCursors[i];
		
		bool deleted = false;
		
		for (int j = i-1; j >= 0; j--){
			QTextCursor c2 = additionalCursors[j];
			if (c1.position() == c2.position() && c1.anchor() == c2.anchor()){
				additionalCursors.remove(i);
				deleted = true;
				break;
			}
		}
		
		if (deleted){
			continue;
		}
		if (m_originalCursor.position() == c1.position() && m_originalCursor.anchor() == c1.anchor()){
			additionalCursors.remove(i);
		}
	}
}