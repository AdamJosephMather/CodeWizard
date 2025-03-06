#ifndef CUSTOMHORIZONTALSCROLLAREA_H
#define CUSTOMHORIZONTALSCROLLAREA_H

#include <QScrollArea>
#include <QWheelEvent>

class customHorizontalScrollArea : public QScrollArea
{
	Q_OBJECT

public:
	explicit customHorizontalScrollArea(QWidget *parent = nullptr);

protected:
	void wheelEvent(QWheelEvent *event) override;
};

#endif // CUSTOMHORIZONTALSCROLLAREA_H
