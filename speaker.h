#ifndef SPEAKER_H
#define SPEAKER_H

#include <QString>
#include <QtMultimedia/QMediaPlayer>

class Speaker
{
public:
	Speaker(QMediaPlayer* p);
	void speak(QString toSay);
};

#endif // SPEAKER_H
