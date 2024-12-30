#ifndef LANGUAGE_H
#define LANGUAGE_H
#include <QString>
#include <QStringList>
#include <QTextCharFormat>
#include <map>

class Language {
public:
    // Constructors
    Language(const QString& name,
             const QStringList& stringExtensions,
             const QStringList& extensions,
             const QStringList& comments,
             const QStringList& multiLineStringsStart,
             const QStringList& multiLineStringsEnd,
             const QStringList& multiLineCommentsStart,
             const QStringList& multiLineCommentsEnd,
             const QStringList& openIndents,
             const QStringList& closeIndents,
             const QStringList& closeIndentsWords,
             const QStringList& defWordList,
             const QStringList& fileExtensions,
             const std::map<QString, QTextCharFormat>& colorMap,
             const std::unordered_map<QString, int>& colorMapTS,
             const int& index);
    Language();

    // Copy constructor
    Language(const Language& other);

    // Copy assignment operator
    Language& operator=(const Language& other);

    // Destructor
    ~Language();

public:
    QString name;
    QStringList strings;
    QStringList stringExtensions;
    QStringList comments;
    QStringList multiLineStringsStart;
    QStringList multiLineStringsEnd;
    QStringList multiLineCommentsStart;
    QStringList multiLineCommentsEnd;
    QStringList openIndents;
    QStringList closeIndents;
    QStringList closeIndentsWords;
    QStringList defWordList;
    QStringList fileExtensions;
    std::map<QString, QTextCharFormat> colorMap; // Changed from reference to value
    std::unordered_map<QString, int> colorMapTS;
    int index;
};
#endif // LANGUAGE_H
