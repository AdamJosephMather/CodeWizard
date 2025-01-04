#ifndef RECORDINGLIGHT_H
#define RECORDINGLIGHT_H

#include <QWidget>
#include <QPainter>

class RecordingLight : public QWidget {
	Q_OBJECT

public:
	explicit RecordingLight(QWidget *parent = nullptr);

protected:
	void paintEvent(QPaintEvent *event) override;
	void updatePulse();

private:
	QTimer *pulseTimer;  // Timer for pulsing effect
	qreal currentScale;  // Current scale of the light
	bool growing;

};

#endif // RECORDINGLIGHT_H
