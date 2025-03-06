#ifdef Q_OS_WIN
#include "customHorizontalScrollArea.h"
#else
#include "/home/adamj/QtProjects/CodeWizard/customhorizontalscrollarea.h"
#endif

#include <QScrollBar>

customHorizontalScrollArea::customHorizontalScrollArea(QWidget *parent)
	: QScrollArea(parent) {}

void customHorizontalScrollArea::wheelEvent(QWheelEvent *event)
{
	// Check if we are scrolling vertically
	if (event->angleDelta().y() != 0) {
		// Scroll horizontally instead of vertically
		horizontalScrollBar()->setValue(horizontalScrollBar()->value() - event->angleDelta().y() / 8);
		event->accept();
	} else {
		// Pass the event to the parent if it's not a vertical scroll
		QScrollArea::wheelEvent(event);
	}
}
