#include "speaker.h"
#include <QtMultimedia/QMediaPlayer>

QMediaPlayer *player;

Speaker::Speaker(QMediaPlayer* p) {
	player = p;
}

void Speaker::speak(QString toSay){
	qDebug() << "Saying: " << toSay;
	QUrl resourceUrl("qrc:/audio/audio/" + toSay); // https://www.naturalreaders.com/online/ steffan
	player->setSource(resourceUrl);
	player->play();
}