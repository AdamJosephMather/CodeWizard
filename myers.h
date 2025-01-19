#ifndef MYERS_H
#define MYERS_H

#include <qcontainerfwd.h>
#include <qfloat16.h>

class Myers
{
public:
	Myers();
	QList<QStringList> getDiff(const QString& string1, const QString& string2);

//private:
	//int recurse(int at, int x, int y, int lenL1, int lenL2, QVector<bool>* cacheReady, QVector<int>* bestGotos, QVector<int>* bestScores, QList<int>* runsStartX, QList<int>* runsStartY, QList<int>* runsEndX, QList<int>* runsEndY);
};

#endif // MYERS_H
