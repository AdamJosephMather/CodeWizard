#ifndef MYERS_H
#define MYERS_H

#include <qcontainerfwd.h>
#include <qfloat16.h>

class Myers
{
public:
	Myers();
	QList<QStringList> getDiff(const QString& string1, const QString& string2);

private:
	qfloat16 getScore(const QList<QList<int>>& path);
};

#endif // MYERS_H
