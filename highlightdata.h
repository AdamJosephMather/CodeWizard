#ifndef HIGHLIGHTDATA_H
#define HIGHLIGHTDATA_H

#include <QTextBlockUserData>

class HighlightData : public QTextBlockUserData
{
public:
	HighlightData(); // Constructor declaration

	bool hasHighlight; // Member variable
};

#endif // HIGHLIGHTDATA_H
