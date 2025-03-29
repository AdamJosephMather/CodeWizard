#include "tabwidget.h"
#include <qboxlayout.h>

TabWidget::TabWidget(bool darkmode, int index, QWidget *parent) : QWidget{parent} {
	tabButton = new QPushButton("TExT");
	closeButton = new QPushButton("X");
	
	m_index = index;
	
	tabButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
	closeButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
	
	connect(tabButton, &QPushButton::clicked, this, [this]{
		emit tabClicked(m_index);
	});
	
	connect(closeButton, &QPushButton::clicked, this, [this]{
		emit tabClosed(m_index);
	});
	
	updateStyles(darkmode);

	// Layout
	QHBoxLayout *layout = new QHBoxLayout(this);
	layout->setSpacing(0);
	layout->setContentsMargins(0, 0, 0, 0);
	layout->addWidget(tabButton);
	layout->addWidget(closeButton);
	setLayout(layout);
}

void TabWidget::setText(QString text){
	m_text = text;
	tabButton->setText(m_text);
}

void TabWidget::updateStyles(bool darkmode){
	QString regular = "rgb(251, 251, 251)";
	QString hover = "rgb(241, 241, 241)";
	QString click = "rgb(231, 231, 231)";
	QString oneStepFurther = "rgb(221, 221, 221)";
	QString text = "rgb(0, 0, 0)";
	
	if (darkmode){
		regular = "rgb(40, 40, 40)";
		hover = "rgb(50, 50, 50)";
		click = "rgb(60, 60, 60)";
		oneStepFurther = "rgb(70, 70, 70)";
		text = "rgb(255, 255, 255)";
	}
	
	tabButton->setStyleSheet(
		"QPushButton {"
		"   border-top-left-radius: 3px;"
		"   border-bottom-left-radius: 3px;"
		"   border-right: none;"
		"	margin-top: 1px;"
		"	margin-left: 2px;"
		"   padding: 1px;"
		"   padding-top: 0px;"
		"   padding-bottom: 0px;"
		"   background-color: "+regular+";"
		"	color: "+text+";"
		"}"
		"QPushButton:hover { background-color: "+hover+"; }"
		"QPushButton:pressed { background-color: "+click+"; }"
	);

	closeButton->setStyleSheet(
		"QPushButton {"
		"   border-top-right-radius: 3px;"
		"   border-bottom-right-radius: 3px;"
		"   border-left: none;"
		"	margin-top: 1px;"
		"   padding: 3px;"
		"   padding-top: 0px;"
		"   padding-bottom: 0px;"
		"   background-color: "+hover+";"
		"	color: "+text+";"
		"}"
		"QPushButton:hover { background-color: "+click+"; }"
		"QPushButton:pressed { background-color: "+oneStepFurther+"; }"
	);
}

void TabWidget::stFnt(QFont font){
	tabButton->setFont(font);
	closeButton->setFont(font);
}