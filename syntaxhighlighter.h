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
    QList<HighlightBlock> getHighlightBlocks(TSNode root, uint32_t start, uint32_t end);

    // Apply highlighting only where needed
    void updateHighlighting(QTextDocument* document, int cursorPos, int addedLen, TSTree* oldTree, TSTree* newTree, bool forceFull);
    void setFormats(QList<QTextCharFormat> newFormats);

    std::unordered_map<QString, int> colormap;

private:
    void traverseNode(QStringList, QString, TSNode node, QList<HighlightBlock>& blocks, uint32_t start, uint32_t end);
    bool shouldHighlight(TSNode node);
    QTextCharFormat getFormatForType(const QString& parentAndType);
};

#endif // SYNTAXHIGHLIGHTER_H
