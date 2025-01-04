#include "recordinglight.h"
#include <QWidget>
#include <QTimer>

RecordingLight::RecordingLight(QWidget *parent)
	: QWidget(parent) {
	// Set the size of the recording light (small red dot)
	setFixedSize(10, 10);
	currentScale = 160;

	pulseTimer = new QTimer(this);
	connect(pulseTimer, &QTimer::timeout, this, &RecordingLight::updatePulse);
	pulseTimer->start(50);
}

void RecordingLight::updatePulse(){
	if (growing){
		currentScale += 5;
	}else{
		currentScale -= 5;
	}
	
	if (currentScale < 160){
		growing = true;
		currentScale = 160;
	}else if (currentScale > 255){
		growing = false;
		currentScale = 255;
	}
	
	update();
}

void RecordingLight::paintEvent(QPaintEvent *) {
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setBrush(QColor(currentScale, 0, 0));
	painter.setPen(Qt::NoPen);
	painter.drawEllipse(rect());
}
