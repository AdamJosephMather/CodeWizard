#ifndef MYERS_H
#define MYERS_H

#include <qcontainerfwd.h>
#include <qfloat16.h>

class Myers
{
public:
	Myers();
	QList<QStringList> getDiff(QString string1, QString string2);

private:
	qfloat16 getScore(QList<QList<int>> path);

};

#endif // MYERS_H
