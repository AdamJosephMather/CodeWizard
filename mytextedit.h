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

protected:
	QString changeToTabs(QString text);
	
	void insertFromMimeData(const QMimeData *source) override;
	
	void contextMenuEvent(QContextMenuEvent *event) override;
	
	void mouseMoveEvent(QMouseEvent *event) override {
		QTextEdit::mouseMoveEvent(event);
		QPoint pos = event->pos();
		emit mousePositionChanged(pos);
	}
	
	void mousePressEvent(QMouseEvent *event) override {
		QTextEdit::mousePressEvent(event);
		if (event->button() == Qt::LeftButton) {
			emit mouseClicked(event->pos());
			// If you want to also emit the text cursor position:
			QTextCursor cursor = cursorForPosition(event->pos());
			emit mouseClickedAtCursor(cursor);
		}
	}
	
	void mouseReleaseEvent(QMouseEvent *event) override {
		QTextEdit::mouseReleaseEvent(event);
	
		if (event->button() == Qt::LeftButton) {
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
	}
	
	void paintEvent(QPaintEvent *event) override;
	
	void keyPressEvent(QKeyEvent *event) override;
	
private:
	QTextCursor m_originalCursor;
	void drawCursor(QPainter &painter, const QTextCursor &cursor, const QColor &color);
	void applyToAllCursors(const std::function<void(QTextCursor&)>& operation);
	void insertTextAtAllCursors(const QString &text);
	void handleNavigationKey(QKeyEvent *event);
	void handleDeletionKey(QKeyEvent *event);
	void drawSelection(QPainter &painter, QTextCursor cursor);
	
	void toggleCursorVisibility();
	QTimer cursorBlinkTimer;
	void handleDuplicateCursors();

signals:
	void mousePositionChanged(QPoint pos);
	void gotoDefinitionActionTriggered();
	void renameActionTriggered();
	void mouseClicked(QPoint pos);                 // New signal for mouse clicks
	void mouseReleased(QPoint pos);
	void mouseClickedAtCursor(QTextCursor cursor); // New signal with cursor info
	void mouseReleasedAtCursor(QTextCursor cursor); // New signal with cursor info
	void handleSizeChange(bool force);
};

#endif // MYTEXTEDIT_H
