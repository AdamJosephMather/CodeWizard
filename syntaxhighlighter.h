#ifndef SYNTAXHIGHLIGHTER_H
#define SYNTAXHIGHLIGHTER_H

#include <QTextDocument>
#include <QTextLayout>
#include <QTextCharFormat>
#include <QString>
#include <QList>
#include <QSet>
#include <tree_sitter/api.h>

// Structure for storing highlight block information
struct HighlightBlock {
    int startPosition;
    int length;
    QString type;  // The highlighting type/category

    bool operator==(const HighlightBlock& other) const {
        return startPosition == other.startPosition &&
               length == other.length &&
               type == other.type;
    }
};

class SyntaxHighlighter {
public:
    // Convert tree-sitter tree into list of highlight blocks
    QList<HighlightBlock> getHighlightBlocks(TSNode root);

    // Apply highlighting only where needed
    void updateHighlighting(QTextDocument* document, const QList<HighlightBlock>& newBlocks, int cursorPos, TSTree* oldTree, TSTree* newTree, bool forceFull);
    void setFormats(QList<QTextCharFormat> newFormats);

    std::unordered_map<QString, int> colormap;

private:
    void traverseNode(QStringList, QString, TSNode node, QList<HighlightBlock>& blocks);
    bool shouldHighlight(TSNode node);
    QTextCharFormat getFormatForType(const QString& parentAndType);
};

#endif // SYNTAXHIGHLIGHTER_H
