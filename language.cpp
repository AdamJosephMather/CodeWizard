#include "language.h"
#include <QDebug>

// Constructor with member initializer list
Language::Language(const QString& name,
				   const QStringList& strings,
				   const QStringList& stringExtensions,
				   const QStringList& comments,
				   const QStringList& multiLineStringsStarts,
				   const QStringList& multiLineStringsEnds,
				   const QStringList& multiLineCommentsStarts,
				   const QStringList& multiLineCommentsEnds,
				   const QStringList& openIndents,
				   const QStringList& closeIndents,
				   const QStringList& closeIndentsWords,
				   const QStringList& defWordList,
				   const QStringList& fileExtensions,
				   const std::unordered_map<QString, int>& colorMapTS,
				   const int& index)
	: name(name),
	strings(strings),
	stringExtensions(stringExtensions),
	comments(comments),
	multiLineStringsStart(multiLineStringsStart),
	multiLineStringsEnd(multiLineStringsEnd),
	multiLineCommentsStart(multiLineCommentsStart),
	multiLineCommentsEnd(multiLineCommentsEnd),
	openIndents(openIndents),
	closeIndents(closeIndents),
	closeIndentsWords(closeIndentsWords),
	defWordList(defWordList),
	fileExtensions(fileExtensions),
	colorMapTS(colorMapTS),
	index(index) {}

// Default constructor
Language::Language()
	: name(""),
	strings(),
	stringExtensions(),
	comments(),
	multiLineStringsStart(),
	multiLineStringsEnd(),
	multiLineCommentsStart(),
	multiLineCommentsEnd(),
	openIndents(),
	closeIndents(),
	closeIndentsWords(),
	defWordList(),
	fileExtensions(),
	colorMapTS(),
	index() {}

// Copy constructor
Language::Language(const Language& other)
	: name(other.name),
	strings(other.strings),
	stringExtensions(other.stringExtensions),
	comments(other.comments),
	multiLineStringsStart(other.multiLineStringsStart),
	multiLineStringsEnd(other.multiLineStringsEnd),
	multiLineCommentsStart(other.multiLineCommentsStart),
	multiLineCommentsEnd(other.multiLineCommentsEnd),
	openIndents(other.openIndents),
	closeIndents(other.closeIndents),
	closeIndentsWords(other.closeIndentsWords),
	defWordList(other.defWordList),
	fileExtensions(other.fileExtensions),
	colorMapTS(other.colorMapTS),
	index(other.index) {}

// Copy assignment operator
Language& Language::operator=(const Language& other) {
	if (this != &other) {
		name = other.name;
		strings = other.strings;
		stringExtensions = other.stringExtensions;
		comments = other.comments;
		multiLineStringsStart = other.multiLineStringsStart;
		multiLineStringsEnd = other.multiLineStringsEnd;
		multiLineCommentsStart = other.multiLineCommentsStart;
		multiLineCommentsEnd = other.multiLineCommentsEnd;
		openIndents = other.openIndents;
		closeIndents = other.closeIndents;
		closeIndentsWords = other.closeIndentsWords;
		defWordList = other.defWordList;
		fileExtensions = other.fileExtensions;
		colorMapTS = other.colorMapTS;
		index = other.index;
	}
	return *this;
}

// Destructor
Language::~Language() = default;
