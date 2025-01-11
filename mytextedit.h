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

class MyTextEdit : public QTextEdit {
	Q_OBJECT
public:
	explicit MyTextEdit(QWidget *parent = nullptr);
	void setContextMenuStyle(const QString& stylesheet);

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
	void wheelEvent(QWheelEvent *event) override;

signals:
	void mousePositionChanged(QPoint pos);
	void gotoDefinitionActionTriggered();
	void mouseClicked(QPoint pos);                 // New signal for mouse clicks
	void mouseClickedAtCursor(QTextCursor cursor); // New signal with cursor info
};

#endif // MYTEXTEDIT_H
