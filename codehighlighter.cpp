#include "codehighlighter.h"

#include "language.h"
#include <qtextedit.h>

Language languageCls;

CodeHighlighter::CodeHighlighter(Language langCls, QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    languageCls = langCls;
    setupRules();
}

void CodeHighlighter::highlightBlock(const QString &text) {
    // Apply all keyword rules from colormap
    for (const HighlightingRule &rule : qAsConst(highlightingRules)) {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }

    // QString makeGreyChars = ",./\[]`~!@#$%^&*(){}_+-=\"?'|\\;:<>";
    QString DONTMakeGreyChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

    int i = 0;
    //int start = 0;  // Track the start position for formatting
    int currentElement = -1;
    int currentElementType = 0; // <=0 = nothing, 1 = string, 2 = comment, 3 = multilinestring, 4 = multilinecomment
    int prevBlockState = previousBlockState(); // using 1 number we need to find the endtype

    if (prevBlockState > 0){
        prevBlockState -= 1;
        if (prevBlockState >= languageCls.strings.length()){
            prevBlockState -= languageCls.strings.length();
            if (prevBlockState < languageCls.multiLineStringsStart.length()){
                currentElementType = 3; // multilinestrings
                currentElement = prevBlockState;
            }else{
                prevBlockState -= languageCls.multiLineStringsStart.length();
                if (prevBlockState < languageCls.multiLineCommentsStart.length()){
                    currentElementType = 4; // multiCommentsstrings
                    currentElement = prevBlockState;
                }
            }
        }else{
            currentElement = prevBlockState;
            currentElementType = 1;
        }
    }

    int startOfElement = 0;

    bool isExpectedChar = true;

    QTextCursor cursor(document());  // Initialize cursor
    QTextCharFormat c3Format; // Define formats as needed
    QTextCharFormat c4Format; // Define formats as needed
    QTextCharFormat c5Format;
    QTextCharFormat codeWizForm;

    QColor c3 = QColor(38, 175, 199);
    QColor c4 = QColor(38, 143, 199);
    QColor c5 = QColor(160, 160, 160);
    QColor codeWizCol = QColor(136, 67, 240);

    c3Format.setForeground(c3);
    c4Format.setForeground(c4);
    c5Format.setForeground(c5);
    codeWizForm.setForeground(codeWizCol);

    int textLength = text.length();

    for (int i = 0; i < text.length(); i++) {
        if (currentElement != -1 && isExpectedChar){ // in a string/multiline/whatnot

            QStringList from;
            QStringList to;
            if (currentElementType == 1){ // looking for singleline string //// NOT LOOKING FOR COMMENTS END
                from = languageCls.strings;
                to = languageCls.strings;
            }else if (currentElementType == 3){ // looking for multiline string
                from = languageCls.multiLineStringsStart;
                to = languageCls.multiLineStringsEnd;
            }else if (currentElementType == 4){ // looking for multiline comment
                from = languageCls.multiLineCommentsStart;
                to = languageCls.multiLineCommentsEnd;
            }

            for (int j = 0; j < from.length(); j ++){
                if (from[j] != from[currentElement]){continue;}

                QString lookingFor = to[j];

                int lengthOfElement = lookingFor.length();
                if (textLength >= i+lengthOfElement){
                    QString haveCurrently = text.mid(i, lengthOfElement);
                    if (haveCurrently == lookingFor){
                        auto format = c4Format; // requires an initializer --__--
                        if (currentElementType == 1 || currentElementType == 3) { // 1 or 3 (string or multilinestring)
                            format = c3Format; // strings
                        }else{
                            format = c4Format; // comments
                        }

                        setFormat(startOfElement, i-startOfElement+lengthOfElement, format);
                        i += lengthOfElement-1; // skip the upcoming chars we've already handled
                        currentElement = -1;
                        currentElementType = 0;
                        break;
                    }
                }
            }

            if (currentElement == -1){continue;}

        }else if(isExpectedChar){
            for (int elementIndex = 0; elementIndex < languageCls.multiLineStringsStart.length(); elementIndex ++){ // multiline anything before strings because otherwise """ might be interpreted as "
                QString lookingFor = languageCls.multiLineStringsStart[elementIndex];
                int lengthOfElement = lookingFor.length();
                if (textLength >= i+lengthOfElement){
                    QString haveCurrently = text.mid(i, lengthOfElement);
                    if (haveCurrently == lookingFor){
                        currentElement = elementIndex;
                        currentElementType = 3;
                        startOfElement = i;
                        i += lengthOfElement-1;
                        break;
                    }
                }
            }
            if (currentElement != -1){continue;}
            for (int elementIndex = 0; elementIndex < languageCls.multiLineCommentsStart.length(); elementIndex ++){ // multiline anything before strings because otherwise """ might be interpreted as "
                QString lookingFor = languageCls.multiLineCommentsStart[elementIndex];
                int lengthOfElement = lookingFor.length();
                if (textLength >= i+lengthOfElement){
                    QString haveCurrently = text.mid(i, lengthOfElement);
                    if (haveCurrently == lookingFor){
                        currentElement = elementIndex;
                        currentElementType = 4;
                        startOfElement = i;
                        i += lengthOfElement-1;
                        break;
                    }
                }
            }
            if (currentElement != -1){continue;}
            for (int elementIndex = 0; elementIndex < languageCls.comments.length(); elementIndex ++){ // multiline anything before strings because otherwise """ might be interpreted as "
                QString lookingFor = languageCls.comments[elementIndex];
                int lengthOfElement = lookingFor.length();
                if (textLength >= i+lengthOfElement){
                    QString haveCurrently = text.mid(i, lengthOfElement);
                    if (haveCurrently == lookingFor){
                        currentElement = elementIndex;
                        currentElementType = 2;
                        startOfElement = i;
                        i += lengthOfElement-1;
                        break;
                    }
                }
            }
            if (currentElementType == 2){break;} // comments continue to end

            if (currentElement != -1){continue;}
            for (int elementIndex = 0; elementIndex < languageCls.strings.length(); elementIndex ++){ // multiline anything before strings because otherwise """ might be interpreted as "
                QString lookingFor = languageCls.strings[elementIndex];
                int lengthOfElement = lookingFor.length();
                if (textLength >= i+lengthOfElement){
                    QString haveCurrently = text.mid(i, lengthOfElement);
                    if (haveCurrently == lookingFor){
                        currentElement = elementIndex;
                        currentElementType = 1;
                        startOfElement = i;
                        i += lengthOfElement-1;
                        continue;
                    }
                }
            }
            if (currentElement != -1){continue;}
        }

        if (!DONTMakeGreyChars.contains(text[i])){
            setFormat(i, 1, c5Format);
        }

        if (text[i] == '\\') {
            if (isExpectedChar) {
                isExpectedChar = false;
            } else {
                isExpectedChar = true;
            }
        } else {
            isExpectedChar = true;
        }
    }

    // Final formatting based on the last state
    if (currentElementType == 4 || currentElementType == 2) {
        setFormat(startOfElement, text.length()-startOfElement, c4Format);
    }else if (currentElementType == 3 || currentElementType == 1) {
        setFormat(startOfElement, text.length()-startOfElement, c3Format);
    }

    if (currentElementType >= 3 || (currentElementType == 1 && text[text.length()-1] == languageCls.stringExtensions[currentElement])){
        int state = currentElement+1;
        if (currentElementType > 1){
            state += languageCls.strings.length();
        }
        if (currentElementType == 4){
            state += languageCls.multiLineStringsStart.length();
        }
        setCurrentBlockState(state);
    }else{
        setCurrentBlockState(0);
    }

    HighlightingRule rule;
    QString pattern = QString("\\b%1\\b").arg("CodeWizard");
    rule.pattern = QRegularExpression(pattern, QRegularExpression::CaseInsensitiveOption);
    QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
    while (matchIterator.hasNext()) {
        QRegularExpressionMatch match = matchIterator.next();
        setFormat(match.capturedStart(), match.capturedLength(), codeWizForm);
    }
}

void CodeHighlighter::setupRules() {
    auto colormap = languageCls.colorMap;

    HighlightingRule rule;

    // Create regex patterns for each keyword in the colormap
    for (const auto& [keyword, format] : colormap) {
        // Create a word boundary regex for the keyword
        QString pattern = QString("\\b%1\\b").arg(keyword);
        rule.pattern = QRegularExpression(pattern);
        rule.format = format;
        highlightingRules.append(rule);
    }
}

void CodeHighlighter::setLanguage(Language newLanguage, bool doReHigh) {
    languageCls = newLanguage; // Update the colormap
    highlightingRules.clear(); // Clear previous rules
    setupRules(); // Re-setup rules with new colormap
    if (doReHigh){
        rehighlight(); // Rehighlight the current document
    }
}
