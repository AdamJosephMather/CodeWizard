#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QListWidgetItem>
#include <QMainWindow>
#include <QTextCursor>

#include <qdir.h>
#include <qsplitter.h>
#include <tree_sitter/api.h>

QT_BEGIN_NAMESPACE
namespace Ui {
	class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(const QString &fileName, QWidget *parent = nullptr);
	~MainWindow();
	bool eventFilter(QObject *watched, QEvent *event) override;

private slots:
	void useRelativeLineNumbersTriggered();
	void lineDragEvent(QPoint start, QPoint end, bool endODrag);
	void on_actionMultiple_Cursors_triggered();
	void urlChanged(const QUrl &url);
	void nextWebView();
	void backWebView();
	void reloadWebView();
	void useWebViewToggled();
	void openMenuWithHTML(QString name, QString html);
	void on_actionRender_As_Markdown_triggered();
	void addTerminal();
	void nextTerminal();
	void prevTerminal();
	void useTabsToggled();
	void addTab(QString name, QString file);
	void closeTab(int id);
	void tabClicked(int id);
	void on_actionSave_All_Settings_triggered();
	void on_actionLoad_All_Settings_triggered();
	void renameReference(QJsonObject);
	void execChanges(QList<QPair<double, QJsonObject>>);
	void execChangesInOtherFile(QList<QPair<double, QJsonObject>> changesList, QString fileUri);
	void updateSplitsWidths();
	void moveWidgetsToSplitter(QLayout *layout, QWidget *splitter);
	void storeResizeOfSplitters();
	void updateTermimalViews();
	void on_actionToggleComments_triggered();
	void pullUpReloadDialogue(QString message);
	void switchTerminalType();
	int findMatchingBracket(int direction);
	void handleBracketsOnEnter();
	void handleTerminalStdout(int index);
	void useBuiltinTerminalTriggered();
	void on_actionVim_Modes_triggered();
	void executeNormalAct(QTextCursor::MoveOperation move, QKeyEvent *key_event);
	void useVimModesTriggered();
	void on_actionSet_Font_By_Name_triggered();
	void on_actionGit_Integration_triggered();
	void on_actionDiscard_Local_Changes_triggered();
	void on_actionRegular_triggered();
	void on_actionPush_triggered();
	void on_actionKeybindings_triggered();
	void on_actionOpen_Find_Menu_triggered();
	void highlightComparisons();
	QString changeToTabs(QString text);
	void on_actionCompare_2_Files_triggered();
	void on_actionSet_Groq_AI_API_Key_triggered();
	void saveSyntaxColorsToFile();
	void loadSyntaxColorsFromFile();
	void setFormatsFromMyList(QString str);
	void updateMargins(bool force);
	bool checkForLargeFile(QFile *file);
	void clearTSSyntaxHighlighting();
	void changeFindSectionVisibility(bool visible);
	void checkForFixitDialogue();
	int compareVersionNumbers(QString vnum1, QString vnum2);
	void gotoDefinitionReceived(int line1, int character1, int line, int character, QString uri);
	void rehighlightFullDoc();
	void changeOnlyEditsTheme(bool);
	int colorDifference(QColor c1, QColor c2);
	void syntaxColorsOffImage();
	void resetSyntaxColors();
	void validateAndConvert();
	void on_actionSet_Syntax_Colors_triggered();
	void printTree(TSNode node, int depth = 0);
	void setupSyntaxTreeOnOpen(QString code, bool doHighlight=false);
	void onContentsChange(int position, int charsRemoved, int charsAdded);
	void applyEditToTree(int startByte, int oldEndByte, int newEndByte, int startPointRow, int startPointColumn, int oldEndPointRow, int oldEndPointColumn, int newEndPointRow, int newEndPointColumn);
	void onOpenInExplorer();
	void onCopyPath();
	void onOpenOutside();
	void mouseClicked();
	void mouseReleased();
	void openFileTreeContextMenu(const QPoint &pos);
	std::tuple<QString, QString, QString, QStringList> getTabDetails(QString);
	void setupLSP(QString oldFile);
	QString plaintextToHtml(QString plaintext);
	void showWeDontFuckWithTheLSP();
	void showHoldYourHorses();
	void fileTreeToggled();
	void fileTreeOpened(const QModelIndex &index);
	QString convertLeadingSpacesToTabs(const QString& input);
	void ShowSuggestionsWithSuperSet(QStringList completions);
	void gotoDefinitionActionTriggered();
	void renameActionTriggered();
	static void highlightDiagnostics(bool);
	void autoSave();
	void moveHoverBox(QPoint givenPos, QString info, QString type);
	void handleMouseMoved(QPoint pos);
	void on_actionLSP_triggered();
	void on_actionLSP_2_triggered();
	bool insertCompletion();
	bool activateCodeAction();
	void pullUpSaveDialogue();
	void onWindowStateChanged();
	void onSuggestionItemClicked(QListWidgetItem*);
	void onActionsItemClicked(QListWidgetItem*);
	void on_actionOpen_Folder_triggered();
	void on_actionStart_Macro_Recording_triggered();
	void on_actionEnd_Macro_Recording_triggered();
	void on_actionReplay_Macro_triggered();
	void on_actionExit_triggered();
	void on_actionOpen_triggered(bool dontUpdateFileTree = false);
	void on_actionSave_triggered();
	void on_actionSave_As_triggered();
	void on_actionNew_triggered();
	void on_actionRun_Module_F5_triggered();
	void on_actionIncrement_Ctrl_triggered();
	void on_actionDe_Increment_Ctrl_triggered();
	void on_actionFix_It_triggered();
	void on_actionComment_Ctrl_Alt_triggered();
	void on_actionUn_Comment_Alt_5_triggered();
	void on_actionIncrease_Text_Size_triggered();
	void on_actionDecrease_Text_Size_triggered();
	void on_actionSet_Text_Size_triggered();
	void on_actionReset_Text_Size_triggered();
	void on_actionChange_to_IDLE_format_triggered();
	void on_actionTab_Width_triggered();
	void on_actionSettings_triggered();
	void on_actionExtras_triggered();
	void on_actionMacros_triggered();
	void on_actionCourier_New_2_triggered();
	void on_actionDroidSansMono_2_triggered();
	void on_actionMonaco_2_triggered();
	void on_actionMonospace_2_triggered();
	void on_actionCourier_Prime_2_triggered();
	void on_actionSourceCodePro_2_triggered();
	void on_actionUbuntuMono_2_triggered();
	void on_actionRunning_Files_triggered();
	void on_actionThe_Fix_It_Button_triggered();
	void on_actionCodeWizard_triggered();
	void on_actionPython_2_triggered();
	void on_actionJavaScript_triggered();
	void on_actionTypeScript_triggered();
	void on_actionHTML_triggered();
	void on_actionGo_triggered();
	void on_actionC_triggered();
	void on_actionCss_triggered();
	void on_actionCobol_triggered();
	void on_actionC_2_triggered();
	void on_actionC_3_triggered();
	void on_actionRust_triggered();
	void on_actionWGSL_triggered();
	void on_actionGLSL_triggered();
	void on_actionPlaintext_triggered();
	void on_actionLua_triggered();
	void on_actionJava_triggered();
	void updateTagLine();
	void updateDefaultWordLists();
	void updateSyntax();
	void findTriggered();
	void nextTriggered();
	void previousTriggered();
	void replaceTriggered();
	void replaceAllTriggered();
	void updateLineNumbers(int);
	void updateScrollBarValue(int);
	void updateScrollBarValue2(int);
	void changeTheme(bool);
	void on_actionDark_Mode_triggered();
	void on_actionLight_Mode_triggered();
	bool wantedTheme();
	void saveWantedTheme();
	void openFind();
	void findTextEditChanged();
	void centerCursor();
	void updateFonts();
	void setupCompleter();
	QString getCurrentWord();
	void updateExtraWordsList();
	void fillSuggestions();
	void fillActionsBox();
	void updateFontSelection();
	void changeHighlightColors(bool);
	void openHelpMenu(QString);
	void setLangOffFilename(QString, bool);
	void addFileToRecentList(QString);
	void updateRecentList(QStringList);
	void openRecentFile(QString);
	void handleTabs();
	QString markdownToHtml(QString);

protected:
	void keyPressEvent(QKeyEvent *) override;
	void changeEvent(QEvent *event) override;

private:
	Ui::MainWindow *ui;
	QString m_fileName;
};
#endif // MAINWINDOW_H
