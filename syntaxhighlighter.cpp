#include "SyntaxHighlighter.h"
#include <QTextBlock>
#include <QTextLayout>
#include <QFont>
#include <qregularexpression.h>

QList<QTextCharFormat> formats;
std::unordered_map<QString, int> knownTypes = {{"true",8}, {"false", 8}};
QRegularExpression *regex = new QRegularExpression("[a-zA-Z0-9]");

void SyntaxHighlighter::setFormats(QList<QTextCharFormat> newFormats){
    formats = newFormats;
}

// Convert tree-sitter tree into list of highlight blocks
QList<HighlightBlock> SyntaxHighlighter::getHighlightBlocks(TSNode root) {
    QList<HighlightBlock> blocks;
    traverseNode(QStringList(), "", root, blocks);
    return blocks;
}

// Apply highlighting only where needed
void SyntaxHighlighter::updateHighlighting(QTextDocument* document, const QList<HighlightBlock>& newBlocks, int cursorPos, TSTree* oldTree, TSTree* newTree, bool forceFull) {
    // Get existing format ranges for each block

    uint32_t rangeCount;
    TSRange* ranges = ts_tree_get_changed_ranges(oldTree, newTree, &rangeCount);

    qDebug() << "ranges received " << ranges;

    // Traverse each changed range
    for (uint32_t z = 0; z < rangeCount; ++z) {
        qDebug() << ranges[z].start_byte << ranges[z].end_byte;

        QTextBlock B1 = document->findBlock(ranges[z].start_byte);
        QTextBlock B2 = document->findBlock(ranges[z].end_byte);

        int blockNumber1 = B1.blockNumber();
        int blockNumber2 = B2.blockNumber();

        if (forceFull){
            B1 = document->begin();
        }

        // QTextBlock currentBlock = document->findBlock(cursorPos);
        // qDebug() << currentBlock.position() << currentBlock.blockNumber() << cursorPos;

        for (QTextBlock block = B1; block.isValid() && (block.blockNumber() < blockNumber2+1 || forceFull); block = block.next()) {
            QTextLayout* layout = block.layout();
            QList<QTextLayout::FormatRange> currentFormats = layout->formats();

            // Find highlights that intersect with this block
            QList<HighlightBlock> relevantBlocks;
            int blockStart = block.position();
            int blockEnd = blockStart + block.length();

            for (const auto& highlight : newBlocks) {
                if (highlight.startPosition + highlight.length >= blockStart &&
                    highlight.startPosition < blockEnd) {
                    relevantBlocks.append(highlight);
                }
            }

            // Check if current formatting matches what we want
            bool needsUpdate = false;
            if (currentFormats.size() != relevantBlocks.size()) {
                needsUpdate = true;
            } else {
                for (int i = 0; i < currentFormats.size(); ++i) {
                    // Compare format properties with highlight block
                    if (currentFormats[i].start != relevantBlocks[i].startPosition - blockStart ||
                        currentFormats[i].length != relevantBlocks[i].length) {
                        needsUpdate = true;
                        break;
                    }
                }
            }

            if (needsUpdate) {
                QList<QTextLayout::FormatRange> newFormats;
                for (const auto& highlight : relevantBlocks) {
                    QTextLayout::FormatRange range;
                    range.start = highlight.startPosition - blockStart;
                    range.length = highlight.length;
                    range.format = getFormatForType(highlight.type);
                    newFormats.append(range);
                }

                layout->setFormats(newFormats);
                document->markContentsDirty(blockStart, block.length());
            }
        }
    }


    QTextBlock block = document->findBlock(cursorPos);

    for (int z = 0; z < 2; z ++) {
        QTextLayout* layout = block.layout();
        if (!block.isValid()){
            continue;
        }
        QList<QTextLayout::FormatRange> currentFormats = layout->formats();

        // Find highlights that intersect with this block
        QList<HighlightBlock> relevantBlocks;
        int blockStart = block.position();
        int blockEnd = blockStart + block.length();

        for (const auto& highlight : newBlocks) {
            if (highlight.startPosition + highlight.length >= blockStart &&
                highlight.startPosition < blockEnd) {
                relevantBlocks.append(highlight);
            }
        }

        // Check if current formatting matches what we want
        bool needsUpdate = false;
        if (currentFormats.size() != relevantBlocks.size()) {
            needsUpdate = true;
        } else {
            for (int i = 0; i < currentFormats.size(); ++i) {
                // Compare format properties with highlight block
                if (currentFormats[i].start != relevantBlocks[i].startPosition - blockStart ||
                    currentFormats[i].length != relevantBlocks[i].length) {
                    needsUpdate = true;
                    break;
                }
            }
        }

        if (needsUpdate) {
            QList<QTextLayout::FormatRange> newFormats;
            for (const auto& highlight : relevantBlocks) {
                QTextLayout::FormatRange range;
                range.start = highlight.startPosition - blockStart;
                range.length = highlight.length;
                range.format = getFormatForType(highlight.type);
                newFormats.append(range);
            }

            layout->setFormats(newFormats);
            document->markContentsDirty(blockStart, block.length());
        }

        block = block.next();
    }
}

void SyntaxHighlighter::traverseNode(QStringList parents, QString p, TSNode node, QList<HighlightBlock>& blocks) {
    if (!p.isEmpty()){
        parents.append(p);
    }

    QString nodeType = QString::fromUtf8(ts_node_type(node));

    if (shouldHighlight(node)) {
        uint32_t startByte = ts_node_start_byte(node);
        uint32_t endByte = ts_node_end_byte(node);

        QString parentType = "";
        for (int i = 0; i < parents.count(); i++){
            if (parents[i] != nodeType){
                parentType = parents[i];
            }
        }

        blocks.append(HighlightBlock{
            static_cast<int>(startByte),
            static_cast<int>(endByte - startByte),
            parentType+"/.CodeWiz./"+nodeType
        });
    }

    // Recurse through children
    uint32_t childCount = ts_node_child_count(node);
    for (uint32_t i = 0; i < childCount; ++i) {
        TSNode child = ts_node_child(node, i);
        traverseNode(parents, nodeType, child, blocks);
    }
}

bool SyntaxHighlighter::shouldHighlight(TSNode nodeType) {
    if (ts_node_child_count(nodeType) == 0){
        return true;
    }

    uint32_t childCount = ts_node_child_count(nodeType);
    for (uint32_t i = 0; i < childCount; ++i) {
        TSNode child = ts_node_child(nodeType, i);
        if (regex->match(ts_node_type(child)).hasMatch()){
            return false;
        }
    }
    return true;
}

QTextCharFormat SyntaxHighlighter::getFormatForType(const QString& parentAndType) {
    auto it = colormap.find(parentAndType);  // Find the iterator for the type
    if (it != colormap.end()) {
        return formats[it->second];  // Access the value of the iterator (which is the key for formats)
    }

    QStringList PAT = parentAndType.split("/.CodeWiz./");
    QString type = PAT[1];

    auto it2 = colormap.find(type);  // Find the iterator for the type
    if (it2 != colormap.end()) {
        return formats[it2->second];  // Access the value of the iterator (which is the key for formats)
    }

    if (parentAndType.contains("string") || parentAndType.contains("char")) {
        return formats[1];
    }

    if (parentAndType.contains("comment")) {
        return formats[2];
    }

    if (parentAndType.contains("type") || parentAndType.contains("public") || parentAndType.contains("private") || parentAndType.contains("static")) {
        return formats[4];
    }

    if (parentAndType.contains("arguments")) {
        return formats[3];
    }

    if (parentAndType.contains("\"") || parentAndType.contains("\'")) {
        return formats[1];
    }

    if (!regex->match(type).hasMatch()){
        return formats[7];
    }

    if (type.contains("if") || type.contains("else") || type.contains("then") || type.contains("end") || type.contains("return") || type.contains("continue") || type.contains("break") || type.contains("yeild")){
        return formats[6];
    }

    if (type.contains("function")){
        return formats[5];
    }

    auto it3 = knownTypes.find(type);  // Find the iterator for the type
    if (it3 != knownTypes.end()) {
        return formats[it3->second];  // Access the value of the iterator (which is the key for formats)
    }

    qDebug() << "#######" << parentAndType;
    return QTextCharFormat();  // Return a default QTextCharFormat if not found
}
