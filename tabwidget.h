#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QWidget>
#include <qpushbutton.h>

class TabWidget : public QWidget
{
	Q_OBJECT
public:
	explicit TabWidget(bool darkmode, int index, QWidget *parent = nullptr);
	
	int m_index;
	void setText(QString text);
	void updateStyles(bool darkmode);
	void stFnt(QFont font);
	QString extraText = "";
	bool isUntitled = false;

private:
	QString m_text;
	
	QPushButton *tabButton;
	QPushButton *closeButton;

signals:
	void tabClicked(int index);
	void tabClosed(int index);
};

#endif // TABWIDGET_H
