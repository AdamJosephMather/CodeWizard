#ifndef MYTEXTEDIT_H
#define MYTEXTEDIT_H

#include <QTextEdit>
#include <QMouseEvent>
#include <QMimeData>
#include <QMenu>
#include <QAction>
#include <QContextMenuEvent>
#include <QDebug>
#include <qpainter.h>
#include <QTextCursor>
#include <QList>
#include <QPaintEvent>
#include <QApplication>
#include <QTimer>

class MyTextEdit : public QTextEdit {
	Q_OBJECT
public:
	explicit MyTextEdit(QWidget *parent = nullptr);
	void setContextMenuStyle(const QString& stylesheet);
	QList<QTextCursor> additionalCursors;
	void updateViewport();
	bool cursorBlinking;
	bool useMultiCursors = false;
	void handleDuplicateCursors();
	bool dontScroll = false;
	QStringList coppies;
	
	void setVIM(bool vim);
	void setCurrentVim(QString vmMd);
	bool useVIM = false;
	QString currentVimMode = "i";
	int vimRepeater = 0;

protected:
	QString changeToTabs(QString text);
	
	void insertFromMimeData(const QMimeData *source) override;
	
	void contextMenuEvent(QContextMenuEvent *event) override;
	
	bool eventFilter(QObject *obj, QEvent *event) override;
	
	void mouseMoveEvent(QMouseEvent *event) override {
		if (startedDrag && hasFocus()){
			emit dragEvent(startDrag, event->pos(), false, false);
		}else{
			startedDrag = false;
		}
		
		QTextEdit::mouseMoveEvent(event);
		QPoint pos = event->pos();
		emit mousePositionChanged(pos);
	}
	
	void mousePressEvent(QMouseEvent *event) override {
		if (event->button() == Qt::LeftButton) {
			auto *mouseEvent = static_cast<QMouseEvent *>(event);
			
			if (mouseEvent->buttons() & Qt::LeftButton){
				startDrag = event->pos();
				startedDrag = true;
				emit dragEvent(startDrag, event->pos(), true, false);
			}

			if (mouseEvent->buttons() & Qt::LeftButton && QGuiApplication::keyboardModifiers() & Qt::AltModifier) {
				QPoint relativePos = mapFromGlobal(QCursor::pos());
				QTextCursor cursor = cursorForPosition(relativePos);
				additionalCursors.push_back(cursor);
				cursorBlinking = true;
				updateViewport();
				event->accept();
				
				emit mouseClicked(event->pos());
				emit mouseClickedAtCursor(cursor);
				return;
			}
			emit mouseClicked(event->pos());
			QTextCursor cursor = cursorForPosition(event->pos());
			emit mouseClickedAtCursor(cursor);
		}
		QTextEdit::mousePressEvent(event);
	}
	
	void mouseReleaseEvent(QMouseEvent *event) override {
		QTextEdit::mouseReleaseEvent(event);
		
		if (event->button() == Qt::LeftButton) {
			if (startedDrag && hasFocus()){
				emit dragEvent(startDrag, event->pos(), false, true);
			}
			startedDrag = false;
			
			emit mouseReleased(event->pos());  // Emit position on mouse release
			// If you want to also emit the text cursor position on mouse release:
			QTextCursor cursor = cursorForPosition(event->pos());
			emit mouseReleasedAtCursor(cursor);  // Emit cursor position on mouse release
		}
	}
	
	void wheelEvent(QWheelEvent *event) override;
	
	void resizeEvent(QResizeEvent* event) override {
		QTextEdit::resizeEvent(event);
		// Call your function here
		emit handleSizeChange(false);
		emit anyGeometryChange();
	}
	
	void moveEvent(QMoveEvent* event) override {
		QTextEdit::moveEvent(event);
		emit anyGeometryChange();
	}
	
	void paintEvent(QPaintEvent *event) override;
	
	void keyPressEvent(QKeyEvent *event) override;
	
	void getCopyText();
	void pasteText();
	
	void focusInEvent(QFocusEvent *event) override;
	void focusOutEvent(QFocusEvent *event) override;
	
private:
	QTextCursor m_originalCursor;
	QPoint startDrag;
	bool startedDrag;
	void drawCursor(QPainter &painter, const QTextCursor &cursor, const QColor &color);
	void applyToAllCursors(const std::function<void(QTextCursor&)>& operation);
	void insertTextAtAllCursors(const QString &text);
	void handleNavigationKey(QKeyEvent *event);
	void handleDeletionKey(QKeyEvent *event);
	void drawSelection(QPainter &painter, QTextCursor cursor, bool onEnd);
	
	void toggleCursorVisibility();
	QTimer cursorBlinkTimer;
	
	void executeNormalAct(QTextCursor::MoveOperation move, QKeyEvent *key_event);

signals:
	void wheelSignal(QWheelEvent* event);
	void anyGeometryChange();
	void mousePositionChanged(QPoint pos);
	void gotoDefinitionActionTriggered();
	void renameActionTriggered();
	void mouseClicked(QPoint pos);                 // New signal for mouse clicks
	void mouseReleased(QPoint pos);
	void mouseClickedAtCursor(QTextCursor cursor); // New signal with cursor info
	void mouseReleasedAtCursor(QTextCursor cursor); // New signal with cursor info
	void handleSizeChange(bool force);
	void dragEvent(QPoint start, QPoint end, bool startODrag, bool endODrag);
	void focusChange(bool focused);
	
	void executedNormalAct(QTextCursor::MoveOperation move, QKeyEvent *key_event, int vimRepeater);
};

#endif // MYTEXTEDIT_H
