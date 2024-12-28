#ifndef CODEHIGHLIGHTER_H
#define CODEHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <QRegularExpression>
#include <map>
#include <QVector>
#include <QString>
#include "language.h"
#include <qtextedit.h>

class CodeHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    explicit CodeHighlighter(Language language, QTextDocument *parent = nullptr);
    void setLanguage(Language newLang, bool doReHigh);

protected:
    void highlightBlock(const QString &text) override;

private:
    struct HighlightingRule {
        QRegularExpression pattern;
        QTextCharFormat format;
    };

    QVector<HighlightingRule> highlightingRules;
    std::map<QString, QTextCharFormat> colormap;

    void setupRules();
};

#endif // CODEHIGHLIGHTER_H
