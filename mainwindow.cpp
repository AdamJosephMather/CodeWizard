#pragma GCC diagnostic ignored "-Wtrigraphs"

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QProcess>
#include <QMessageBox>
#include <QTextEdit>
#include <QKeyEvent>
#include <algorithm>
#include <QRegularExpression>
#include <QScrollBar>
#include <QStyleFactory>
#include <QSettings>
#include <qcompleter.h>
#include <QAbstractItemView>
#include <QStringListModel>
#include <QListWidget>
#include <QOperatingSystemVersion>
#include "language.h"
#include "languageserverclient.h"
#include <QtWidgets>
#include <QTextCursor>
#include <QRegularExpression>
#include <tree_sitter/api.h>
#include "syntaxhighlighter.h"
#ifdef _WIN32
	#include <QTextToSpeech>
#endif
#include "recordinglight.h"
#include "groqai.h"
#include "myers.h"
#include "errorsmenu.h"

extern "C" {
	TSLanguage* tree_sitter_cpp(void);
	TSLanguage* tree_sitter_python(void);
	TSLanguage* tree_sitter_rust(void);
	TSLanguage* tree_sitter_javascript(void);
	TSLanguage* tree_sitter_typescript(void);
	TSLanguage* tree_sitter_html(void);
	TSLanguage* tree_sitter_wgsl(void);
	TSLanguage* tree_sitter_glsl(void);
	TSLanguage* tree_sitter_c(void);
	TSLanguage* tree_sitter_c_sharp(void);
	TSLanguage* tree_sitter_lua(void);
	TSLanguage* tree_sitter_java(void);
	TSLanguage* tree_sitter_go(void);
}

QList<QLineEdit*> hexColorsList;

bool isErrorHighlighted = false;
SyntaxHighlighter treeParserSyntaxHighlighter;
TSTree *tree = nullptr;
TSParser *parser = ts_parser_new();
QTextDocument *textDocument;

QString updateSyntaxAdd = "";
int updateSyntaxPosition = -1;

QString versionNumber = "8.9.4";

GroqAI *groq;
QString groqApiKey;

QPoint mousePos;

QVector<QKeyEvent*> recordedEvents;
QVector<QObject*> recordedWidgets;
bool recordingMacro = false;
bool playingMacro = false;
RecordingLight *recordingLight;

QString fileName = "";
QString defWindowTitle = "CodeWizard V"+versionNumber+" - New File";
QString windowName = defWindowTitle;
MyTextEdit *textEdit;
QTextEdit *lineEdit;
MyTextEdit *lineNumberTextEdit;
QTextEdit *findTextEdit;
QTextEdit *replaceTextEdit;
QTextEdit *builtinTerminalTextEdit;
QTextEdit *builtinTerminalTextEditHORZ;
MyTextEdit *terminalInputLine;
MyTextEdit *terminalInputLineHORZ;

QColor recColor = QColor(255, 70, 0);
QColor c1 = QColor(217, 159, 0);
QColor c2 = QColor(222, 123, 2);
QColor c3 = QColor(38, 175, 199);
QColor c4 = QColor(38, 143, 199);
QColor c5 = QColor(160, 160, 160);

QString defaultSyntaxNumbers = "186,143,63|122,122,122|212,72,81|204,125,55|124,147,153|136,64,237|115,115,115|69,143,222";

QList<QTextCharFormat> coloredFormats;

QColor normalColor = QColor(255, 255, 255);

int marginBottomSize = 0;

QTextCharFormat c1Format;
QTextCharFormat c2Format;
QTextCharFormat c3Format;
QTextCharFormat c4Format;
QTextCharFormat c5Format;
QTextCharFormat c6Format;
QList<QTextCharFormat> errorFormats;
QList<QTextCharFormat> compFormats;

Language pythonLang;
Language rustLang;
Language WGSLLang;
Language cppLang;
Language txtLang;
Language jsLang;
Language HTMLLang;
Language goLang;
Language luaLang;
Language csharpLang;
Language GLSLLang;
Language javaLang;
Language tsLang;
Language cLang;

QVector<Language> supportedLangs;

Language currentLang;

std::unordered_map<QString, int> colormapPythonTS;
std::unordered_map<QString, int> colormapRustTS;
std::unordered_map<QString, int> colormapWGSLTS;
std::unordered_map<QString, int> colormapCppTS;
std::unordered_map<QString, int> colormapTxtTS;
std::unordered_map<QString, int> colormapJsTS;
std::unordered_map<QString, int> colormapHTMLTS;
std::unordered_map<QString, int> colormapGoTS;
std::unordered_map<QString, int> colormapLuaTS;
std::unordered_map<QString, int> colormapCsharpTS;
std::unordered_map<QString, int> colormapGLSLTS;
std::unordered_map<QString, int> colormapJavaTS;
std::unordered_map<QString, int> colormapTsTS;
std::unordered_map<QString, int> colormapCTS;

std::unordered_map<QString, int> storedLineNumbers;

QString bfrChars = " \n(\t=!-+/%*[{&}])\"$^@|><,`~#:;'?\\";

int previousLineCount = 1;
bool darkmode = true;
int previousTextLen = 0;
int tabWidth = 4;

QString defPythonTag = "python -u \"[filename]\"";
QString defRustTag = "cargo run";
QString defWGSLTag = "cargo run";
QString defCppTag = "call \"C:\\Program Files\\Microsoft Visual Studio\\[VERSION_NUMBER]\\Community\\VC\\Auxiliary\\Build\\vcvarsall.bat\" x64\ncl /EHsc \"[filename]\" && \"[filenameWoutExt].exe\"";
QString defTxtTag = "\"[filename]\"";
QString defJsTag = "node \"[filename]\"";
QString defTsTag = "ts-node \"[filename]\"";
QString defHTMLTag = "\"[filename]\"";
QString defGoTag = "go run .";
QString defLuaTag = "lua \"[filename]\"";
QString defCsharpTag = "csc \"[filename]\"";
QString defGLSLTag = "";
QString defJavaTag = "javac \"[filename]\"\njava \"[filename]\"";
QString defCTag = "call \"C:\\Program Files\\Microsoft Visual Studio\\[VERSION_NUMBER]\\Community\\VC\\Auxiliary\\Build\\vcvarsall.bat\" x64\ncl \"[filename]\" && \"[filenameWoutExt].exe\"";

QString pythonTag = defPythonTag;
QString rustTag = defRustTag;
QString WGSLTag = defWGSLTag;
QString CppTag = defCppTag;
QString txtTag = defTxtTag;
QString jsTag = defJsTag;
QString tsTag = defJsTag;
QString HTMLTag = defHTMLTag;
QString goTag = defGoTag;
QString luaTag = defLuaTag;
QString csharpTag = defCsharpTag;
QString GLSLTag = defGLSLTag;
QString javaTag = defJavaTag;
QString cTag = defCTag;

QString pythonLSP = "";
QString rustLSP = "";
QString WGSLLSP = "";
QString CppLSP = "";
QString txtLSP = "";
QString jsLSP = "";
QString tsLSP = "";
QString HTMLLSP = "";
QString goLSP = "";
QString luaLSP = "";
QString csharpLSP = "";
QString GLSLLSP = "";
QString javaLSP = "";
QString cLSP = "";

float fontSize = 11.0;

QPushButton *findButton;
QPushButton *nextButton;
QPushButton *replaceButton;
QPushButton *replaceAllButton;

QMenuBar *menuBarItem;
QMenu *menuEdit;
QMenu *menuFixit;
QMenu *menuOp1;
QMenu *menuRun;
QMenu *menuView;
QMenu *menuFonts;
QMenu *menuHelp;
QMenu *menuLanguage;
QMenu *menuGit;
QMenu *menuOpen_Recent;
QMenu *menuLSP_Settings;
QMenu *menuWarnings;
QMenu *menuAutocomplete;
QMenu *menuSilly;
QMenu *menuSubFonts;
QTreeView *fileTree;

QHBoxLayout *horizontalLayout;

QAction *recordMacroButton;
QAction *endRecordMacroButton;
QAction *replayMacroButton;

QAction *useFileTree;
QAction *useFileTreeIfFullscreen;
QFileSystemModel *fileModel;

QTextEdit *findBar;
QTextEdit *replaceBar;

QHBoxLayout *findLayout;

int globalLineCount = 1;

QString globalArgFileName;

QString preFindText = "";
int preFindCursorLoc = 0;

QString currentCompletion = "";

QStringList defWordListPython;
QStringList defWordListRust;
QStringList defWordListWGSL;
QStringList defWordListCpp;
QStringList defWordListTxt;
QStringList defWordListJs;
QStringList defWordListTs;
QStringList defWordListHTML;
QStringList defWordListGo;
QStringList defWordListLua;
QStringList defWordListCsharp;
QStringList defWordListGLSL;
QStringList defWordListJava;
QStringList defWordListC;

QSet<QString> wrdLstDefQSetted;
QStringList wrdLstDefQStringy;

QStringList extraWordList;
QListWidget* suggestionBox;
QTextEdit* hoverBox;
QListWidget* actionBox;

QStringList suggestion = {};

int currentSelection = 1;
int currentSelectionAction = 1;

int windowsVersion = -1;

QString currentFont = "Source Code Pro";

QStringList recentFiles;

LanguageServerClient *client;
bool callCompleteOponUpdate = false;
QStringList errMessages;
QList<int> errStartC;
QList<int> errStartL;
QList<int> errEndC;
QList<int> errEndL;
QList<int> errSeverity;
QJsonArray codeActions;
ErrorsMenu errMenu;

int expectedCompletionId = 0;
int expectedHoverInfoId = 0;
QMutex lspMutex;

QAction* showWarnings;
QAction* showErrors;
QAction* showOther;
QAction* onlyCodeWizardBuiltIn;
QAction* noAutocomplete;
QAction* hoverAction;
QAction* useVimMode;
QAction* useBuiltinTerminal;
QAction* preferHorizontalTerminal;
QAction* autoAddBrackets;

QString inputLineToTerminal;

int vimRepeater = 0;

QAction* autoSaveAct;
QList<QTextBlock> errHighlightedBlocks;
QAction* randomSelectFileTypeAct;

bool unsaved = false;
QString savedText = "";
bool isSettingUpLSP = false;
bool isOpeningFile = false;

QPoint suggestedPosition;
QMenu* fileTreeContextMenu;

bool holdingAnEvent = false;

#ifdef _WIN32
	QTextToSpeech *speech;
#endif

QAction *useSpeakerAction;
Myers* diffAlgo;

QString currentVimMode = "i";
QProcess *activeTerminal;
QStringList sentCommands;
int indexInSentCommands = -1;

QStringList fontFamilies;
QListWidget *fontList;

bool handlingReopen = false;
QString toCompareTo = "NOCOMPARISONYET_CODEWIZARD_WARNING - <THEENDISNIGH>";

QSplitter *splitter;
QSplitter *splitter2;

double splitWidths[3];

MainWindow::MainWindow(const QString &argFileName, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
	qDebug() << "MainWindow";

	ui->setupUi(this);

	// Replace with new splitters

	QWidget *placeholderWidget = ui->horizontalLayout_4;  // Get the widget holding the layout
	QLayout *oldLayout = placeholderWidget->layout();
	splitter = new QSplitter(Qt::Horizontal, this);
	splitter->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
	splitter->setContentsMargins(0, 0, 0, 0);

	while (!oldLayout->isEmpty()){
		QLayoutItem *item = oldLayout->takeAt(0);

		if (!item) continue;

		if (QWidget *widget = item->widget()) {
			oldLayout->removeWidget(widget);
			splitter->addWidget(widget);
			if (widget->layout()){
				widget->layout()->setSpacing(0);
				widget->layout()->setContentsMargins(0, 0, 0, 0);
			}
		} else if (QLayout *nestedLayout = item->layout()) {
			QWidget *container = new QWidget(splitter);
			QLayout *containerLayout = nullptr;

			if (QVBoxLayout *vLayout = qobject_cast<QVBoxLayout *>(nestedLayout)) {
				containerLayout = new QVBoxLayout(container);
			} else if (QHBoxLayout *hLayout = qobject_cast<QHBoxLayout *>(nestedLayout)) {
				containerLayout = new QHBoxLayout(container);
			} else if (QFormLayout *fLayout = qobject_cast<QFormLayout *>(nestedLayout)) {
				containerLayout = new QFormLayout(container);
			} // Add more layout types as needed

			if (!containerLayout){
				continue;
			}

			containerLayout->setSpacing(0);
			containerLayout->setContentsMargins(0, 0, 0, 0);

			container->setLayout(containerLayout);
			moveWidgetsToSplitter(nestedLayout, container);  // Handle nested layout
			splitter->addWidget(container);
		}
		delete item;
	}

	splitter->setParent(placeholderWidget->parentWidget());

	QLayout *mainLayout = placeholderWidget->parentWidget()->layout();
	if (mainLayout) {
		mainLayout->setSpacing(0);
		mainLayout->setContentsMargins(0, 0, 0, 0);
		mainLayout->replaceWidget(placeholderWidget, splitter);
	}

	delete placeholderWidget;

	// SPLITTER FOR THE SECOND TERMINAL - MUST BE DONE AFTER FIRST SPLITTER - NO I'M NOT GOING TO TELL YOU WHY, GFL FIGURING OUT WHY

	placeholderWidget = ui->verticalLayout_7;  // Get the widget holding the layout
	oldLayout = placeholderWidget->layout();
	splitter2 = new QSplitter(Qt::Vertical, this);
	splitter2->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
	splitter2->setContentsMargins(0, 0, 0, 0);

	while (!oldLayout->isEmpty()){
		QLayoutItem *item = oldLayout->takeAt(0);

		if (!item) continue;

		if (QWidget *widget = item->widget()) {
			oldLayout->removeWidget(widget);
			splitter2->addWidget(widget);
			if (widget->layout()){
				widget->layout()->setSpacing(0);
				widget->layout()->setContentsMargins(0, 0, 0, 0);
			}
		} else if (QLayout *nestedLayout = item->layout()) {
			QWidget *container = new QWidget(splitter2);
			QLayout *containerLayout = nullptr;

			if (QVBoxLayout *vLayout = qobject_cast<QVBoxLayout *>(nestedLayout)) {
				containerLayout = new QVBoxLayout(container);
			} else if (QHBoxLayout *hLayout = qobject_cast<QHBoxLayout *>(nestedLayout)) {
				containerLayout = new QHBoxLayout(container);
			} else if (QFormLayout *fLayout = qobject_cast<QFormLayout *>(nestedLayout)) {
				containerLayout = new QFormLayout(container);
			} // Add more layout types as needed

			if (!containerLayout){
				continue;
			}

			containerLayout->setSpacing(0);
			containerLayout->setContentsMargins(0, 0, 0, 0);

			container->setLayout(containerLayout);
			moveWidgetsToSplitter(nestedLayout, container);  // Handle nested layout
			splitter2->addWidget(container);
		}
		delete item;
	}

	splitter2->setParent(placeholderWidget->parentWidget());

	mainLayout = placeholderWidget->parentWidget()->layout();
	if (mainLayout) {
		mainLayout->setSpacing(0);
		mainLayout->setContentsMargins(0, 0, 0, 0);
		mainLayout->replaceWidget(placeholderWidget, splitter2);
	}

	delete placeholderWidget;

	// Ensure all elements are non-collapsible

	for (int i = 0; i < splitter->count(); ++i) {
		splitter->setCollapsible(i, false);  // Set each widget to be non-collapsible
	}
	for (int i = 0; i < splitter2->count(); ++i) {
		splitter2->setCollapsible(i, false);  // Set each widget to be non-collapsible
	}

	// Rest

	diffAlgo = new Myers();

	setWindowTitle(windowName);
	statusBar()->hide();

	groq = new GroqAI(this);
	groq->setModel("llama-3.3-70b-versatile");

	findButton = ui->pushButton_4;
	nextButton = ui->pushButton_3;
	replaceButton = ui->pushButton_2;
	replaceAllButton = ui->pushButton;

	findTextEdit = ui->textEdit_2;
	replaceTextEdit = ui->textEdit_3;
	builtinTerminalTextEdit = ui->textEdit_6;
	builtinTerminalTextEditHORZ = ui->textEdit_8;
	terminalInputLine = ui->textEdit_7;
	terminalInputLineHORZ = ui->textEdit_9;
	findTextEdit->setAcceptRichText(false);
	replaceTextEdit->setAcceptRichText(false);
	terminalInputLine->setAcceptRichText(false);
	builtinTerminalTextEdit->setReadOnly(true);
	terminalInputLineHORZ->setAcceptRichText(false);
	builtinTerminalTextEditHORZ->setReadOnly(true);

	activeTerminal = new QProcess(this);
	activeTerminal->setProcessChannelMode(QProcess::MergedChannels);

	connect(activeTerminal, &QProcess::readyReadStandardOutput, this, &MainWindow::handleTerminalStdout);
	connect(activeTerminal, &QProcess::readyReadStandardError, this, &MainWindow::handleTerminalStdout);

	// Start cmd with a command that will keep the prompt open
	#ifdef _WIN32
		activeTerminal->start("cmd.exe", QStringList() << "/k" << "echo CodeWizard Builtin Terminal.");
	#else
		activeTerminal->setEnvironment(QStringList() << "TERM=dumb");
		activeTerminal->start("bash", QStringList() << "--login" << "-i"); //<< "echo CodeWizard Builtin Terminal.");
		activeTerminal->write("echo CodeWizard Builtin Terminal.\n");
	#endif

	findBar = ui->textEdit_2;
	replaceBar = ui->textEdit_3;
	findLayout = ui->findLayout;

	menuBarItem = ui->menuBar;

	menuEdit = ui->menuEdit;
	menuFixit = ui->menuFixit;
	menuOp1 = ui->menuOp1;
	menuRun = ui->menuRun;
	menuView = ui->menuView;
	menuFonts = ui->menuFonts;
	menuHelp = ui->menuHelp;
	menuLanguage = ui->menuLanguage;
	menuGit = ui->menuGit;
	menuOpen_Recent = ui->menuOpen_Recent;
	menuLSP_Settings = ui->menuLSP_Settings;
	menuWarnings = ui->menuWarnings;
	menuAutocomplete = ui->menuAutocomplete;
	menuSilly = ui->menuSilly;

	menuSubFonts = menuFonts->addMenu("Browse Installed Fonts");
	
	fontFamilies = QFontDatabase::families();;
	fontList = new QListWidget();

	fontList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	fontList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	fontList->setFixedSize(350, 500);

	for (const QString &font : fontFamilies) {
		fontList->addItem(font);
	}

	connect(fontList, &QListWidget::itemClicked, this, [this](QListWidgetItem *item) {
		qDebug() << "fontListItemClicked";
		currentFont = item->text();
		updateFontSelection();
	});

	QWidgetAction *fontAction = new QWidgetAction(this);
	fontAction->setDefaultWidget(fontList);
	menuSubFonts->addAction(fontAction);

	useFileTree = ui->actionUse_File_Tree;
	useFileTreeIfFullscreen = ui->actionUse_File_Tree_If_Fullscreen;
	fileTree = ui->treeView;

	showWarnings = ui->actionShow_Warnings;
	showErrors = ui->actionShow_Errors;
	showOther = ui->actionShow_Other;
	onlyCodeWizardBuiltIn = ui->actionOnly_Use_CodeWizard_Built_In;
	noAutocomplete = ui->actionNo_Autocomplete;
	hoverAction = ui->actionHover;
	useVimMode = ui->actionUse_Vim_Modes;
	useBuiltinTerminal = ui->actionUse_Builtin_Terminal;
	preferHorizontalTerminal = ui->actionPrefer_Horizontal_Terminal;
	autoAddBrackets = ui->actionAuto_Add_Brackets;

	autoSaveAct = ui->actionAuto_Save;
	randomSelectFileTypeAct = ui->actionRandomly_Choose_Program_Type_On_Save;
	useSpeakerAction = ui->actionUse_Speaker;

	recordMacroButton = ui->actionStart_Macro_Recording;
	endRecordMacroButton = ui->actionEnd_Macro_Recording;
	replayMacroButton = ui->actionReplay_Macro;

	endRecordMacroButton->setEnabled(false);

	fileTreeContextMenu = new QMenu(this);

	lineEdit = ui->textEdit_5;

	textEdit = ui->textEdit;
	groq->setTextEdit(textEdit);
	errMenu.Setup(textEdit);

	suggestionBox = new QListWidget(textEdit); //this goes here so that it is initialized by the time the applyonlyeditstheme is called (or whatever)
	actionBox = new QListWidget(textEdit);
	hoverBox = new QTextEdit(textEdit);

	lineNumberTextEdit = ui->textEdit_4;

	bool thm = wantedTheme(); // must happen before any posibility of setting the saveWantedTheme

	textEdit->setWordWrapMode(QTextOption::NoWrap);
	textDocument = textEdit->document();

	QFont monacoFont("Monaco");
	textEdit->setFont(monacoFont);

	QPalette palette = textEdit->palette();
	normalColor = palette.color(QPalette::WindowText);

	c1Format.setForeground(c1);
	c2Format.setForeground(c2);
	c3Format.setForeground(c3);
	c4Format.setForeground(c4);
	c5Format.setForeground(c5);

	QTextCharFormat nothingFormat;
	QTextCharFormat stringsFormat;
	QTextCharFormat commentsFormat;
	QTextCharFormat variablesFormat;
	QTextCharFormat typesFormat;
	QTextCharFormat functionsFormat;
	QTextCharFormat extraFormat;
	QTextCharFormat greyFormat;
	QTextCharFormat literalFormat;

	QTextCharFormat form = QTextCharFormat();
	form.setUnderlineStyle(QTextCharFormat::SingleUnderline);

	QTextCharFormat basic;
	basic.setUnderlineStyle(QTextCharFormat::NoUnderline);
	errorFormats.append(basic);

	form.setUnderlineColor(recColor);
	errorFormats.append(form);
	form.setUnderlineColor(c1);
	errorFormats.append(form);
	form.setUnderlineColor(c3);
	errorFormats.append(form);
	form.setUnderlineColor(c4);
	errorFormats.append(form);

	errorFormats.append(basic); // yeah I know

	form.setUnderlineColor(recColor);
	form.setForeground(recColor);
	errorFormats.append(form);
	form.setUnderlineColor(c1);
	form.setForeground(c1);
	errorFormats.append(form);
	form.setUnderlineColor(c3);
	form.setForeground(c3);
	errorFormats.append(form);
	form.setUnderlineColor(c4);
	form.setForeground(c4);
	errorFormats.append(form);

	QTextCharFormat gFormComp;
	gFormComp.setForeground(QColor(0, 255, 0));
	compFormats.append(gFormComp);
	QTextCharFormat rFormComp;
	rFormComp.setForeground(QColor(255, 0, 0));
	compFormats.append(rFormComp);
	QTextCharFormat bFormComp;
	bFormComp.setForeground(QColor(0, 0, 255));
	compFormats.append(bFormComp);

	colormapPythonTS = {{"identifier", 3}, {"decorator", 5}, {"decorator/.CodeWiz./identifier", 5}, {"call", 5}, {"call/.CodeWiz./identifier", 5}, {"abs", 5}, {"abs/.CodeWiz./all", 5}, {"all", 5}, {"all/.CodeWiz./any", 5}, {"any", 5}, {"any/.CodeWiz./ascii", 5}, {"ascii", 5}, {"ascii/.CodeWiz./bin", 5}, {"bin", 5}, {"bin/.CodeWiz./bool", 5}, {"bool", 5}, {"bool/.CodeWiz./breakpoint", 5}, {"breakpoint", 5}, {"breakpoint/.CodeWiz./bytearray", 5}, {"bytearray", 5}, {"bytearray/.CodeWiz./bytes", 5}, {"bytes", 5}, {"bytes/.CodeWiz./callable", 5}, {"callable", 5}, {"callable/.CodeWiz./chr", 5}, {"chr", 5}, {"chr/.CodeWiz./classmethod", 5}, {"classmethod", 5}, {"classmethod/.CodeWiz./compile", 5}, {"compile", 5}, {"compile/.CodeWiz./complex", 5}, {"complex", 5}, {"complex/.CodeWiz./delattr", 5}, {"delattr", 5}, {"delattr/.CodeWiz./dict", 5}, {"dict", 5}, {"dict/.CodeWiz./dir", 5}, {"dir", 5}, {"dir/.CodeWiz./divmod", 5}, {"divmod", 5}, {"divmod/.CodeWiz./enumerate", 5}, {"enumerate", 5}, {"enumerate/.CodeWiz./eval", 5}, {"eval", 5}, {"eval/.CodeWiz./exec", 5}, {"exec", 5}, {"exec/.CodeWiz./filter", 5}, {"filter", 5}, {"filter/.CodeWiz./float", 5}, {"float", 5}, {"float/.CodeWiz./format", 5}, {"format", 5}, {"format/.CodeWiz./frozenset", 5}, {"frozenset", 5}, {"frozenset/.CodeWiz./getattr", 5}, {"getattr", 5}, {"getattr/.CodeWiz./globals", 5}, {"globals", 5}, {"globals/.CodeWiz./hasattr", 5}, {"hasattr", 5}, {"hasattr/.CodeWiz./hash", 5}, {"hash", 5}, {"hash/.CodeWiz./help", 5}, {"help", 5}, {"help/.CodeWiz./hex", 5}, {"hex", 5}, {"hex/.CodeWiz./id", 5}, {"id", 5}, {"id/.CodeWiz./input", 5}, {"input", 5}, {"input/.CodeWiz./int", 5}, {"int", 5}, {"int/.CodeWiz./isinstance", 5}, {"isinstance", 5}, {"isinstance/.CodeWiz./issubclass", 5}, {"issubclass", 5}, {"issubclass/.CodeWiz./iter", 5}, {"iter", 5}, {"iter/.CodeWiz./len", 5}, {"len", 5}, {"len/.CodeWiz./list", 5}, {"list", 5}, {"list/.CodeWiz./locals", 5}, {"locals", 5}, {"locals/.CodeWiz./map", 5}, {"map", 5}, {"map/.CodeWiz./max", 5}, {"max", 5}, {"max/.CodeWiz./memoryview", 5}, {"memoryview", 5}, {"memoryview/.CodeWiz./min", 5}, {"min", 5}, {"min/.CodeWiz./next", 5}, {"next", 5}, {"next/.CodeWiz./object", 5}, {"object", 5}, {"object/.CodeWiz./oct", 5}, {"oct", 5}, {"oct/.CodeWiz./open", 5}, {"open", 5}, {"open/.CodeWiz./ord", 5}, {"ord", 5}, {"ord/.CodeWiz./pow", 5}, {"pow", 5}, {"pow/.CodeWiz./print", 5}, {"print", 5}, {"print/.CodeWiz./property", 5}, {"property", 5}, {"property/.CodeWiz./range", 5}, {"range", 5}, {"range/.CodeWiz./repr", 5}, {"repr", 5}, {"repr/.CodeWiz./reversed", 5}, {"reversed", 5}, {"reversed/.CodeWiz./round", 5}, {"round", 5}, {"round/.CodeWiz./set", 5}, {"set", 5}, {"set/.CodeWiz./setattr", 5}, {"setattr", 5}, {"setattr/.CodeWiz./slice", 5}, {"slice", 5}, {"slice/.CodeWiz./sorted", 5}, {"sorted", 5}, {"sorted/.CodeWiz./staticmethod", 5}, {"staticmethod", 5}, {"staticmethod/.CodeWiz./str", 5}, {"str", 5}, {"str/.CodeWiz./sum", 5}, {"sum", 5}, {"sum/.CodeWiz./super", 5}, {"super", 5}, {"super/.CodeWiz./tuple", 5}, {"tuple", 5}, {"tuple/.CodeWiz./type", 5}, {"type", 5}, {"type/.CodeWiz./vars", 5}, {"vars", 5}, {"vars/.CodeWiz./zip", 5}, {"zip", 5}, {"zip/.CodeWiz./__import__", 5}, {"__import__", 5}, {"__import__/.CodeWiz./function_definition", 5}, {"function_definition", 5}, {"function_definition/.CodeWiz./identifier", 5}, {"none/.CodeWiz./true", 3}, {"true/.CodeWiz./false", 3}, {"integer", 8}, {"integer/.CodeWiz./float", 8}, {"comment", 2}, {"string", 1}, {"escape_sequence", 1}, {"interpolation", 7}, {"interpolation/.CodeWiz./{", 7}, {"{", 7}, {"}", 7}, {"-", 7}, {"-/.CodeWiz./-=", 7}, {"-=", 7}, {"-=/.CodeWiz./!=", 7}, {"!=", 7}, {"!=/.CodeWiz./*", 7}, {"*", 7}, {"*/.CodeWiz./**", 7}, {"**", 7}, {"**/.CodeWiz./**=", 7}, {"**=", 7}, {"**=/.CodeWiz./*=", 7}, {"*=", 7}, {"*=/.CodeWiz.//", 7}, {"/", 7}, {"//.CodeWiz.///", 7}, {"//", 7}, {"///.CodeWiz.///=", 7}, {"//=", 7}, {"//=/.CodeWiz.//=", 7}, {"/=", 7}, {"/=/.CodeWiz./&", 7}, {"&", 7}, {"&/.CodeWiz./&=", 7}, {"&=", 7}, {"&=/.CodeWiz./%", 7}, {"%", 7}, {"%/.CodeWiz./%=", 7}, {"%=", 7}, {"%=/.CodeWiz./^", 7}, {"^", 7}, {"^/.CodeWiz./^=", 7}, {"^=", 7}, {"^=/.CodeWiz./+", 7}, {"+", 7}, {"+/.CodeWiz./->", 7}, {"->", 7}, {"->/.CodeWiz./+=", 7}, {"+=", 7}, {"+=/.CodeWiz./<", 7}, {"<", 7}, {"</.CodeWiz./<<", 7}, {"<<", 7}, {"<</.CodeWiz./<<=", 7}, {"<<=", 7}, {"<<=/.CodeWiz./<=", 7}, {"<=", 7}, {"<=/.CodeWiz./<>", 7}, {"<>", 7}, {"<>/.CodeWiz./=", 7}, {"=", 7}, {"=/.CodeWiz./:=", 7}, {":=", 7}, {":=/.CodeWiz./==", 7}, {"==", 7}, {"==/.CodeWiz./>", 7}, {">", 7}, {">/.CodeWiz./>=", 7}, {">=", 7}, {">=/.CodeWiz./>>", 7}, {">>", 7}, {">>/.CodeWiz./>>=", 7}, {">>=", 7}, {">>=/.CodeWiz./|", 7}, {"|", 7}, {"|/.CodeWiz./|=", 7}, {"|=", 7}, {"|=/.CodeWiz./~", 7}, {"~", 7}, {"~/.CodeWiz./@=", 7}, {"@=", 7}, {"@=/.CodeWiz./and", 7}, {"and", 7}, {"and/.CodeWiz./in", 7}, {"in", 7}, {"in/.CodeWiz./is", 7}, {"is", 7}, {"is/.CodeWiz./not", 7}, {"not", 7}, {"not/.CodeWiz./or", 7}, {"or", 7}, {"or/.CodeWiz./is not", 7}, {"is not", 7}, {"is not/.CodeWiz./not in", 7}, {"not in", 7}, {"as", 6}, {"as/.CodeWiz./assert", 6}, {"assert", 6}, {"assert/.CodeWiz./async", 6}, {"async", 6}, {"async/.CodeWiz./await", 6}, {"await", 6}, {"await/.CodeWiz./break", 6}, {"break", 6}, {"break/.CodeWiz./class", 6}, {"class", 6}, {"class/.CodeWiz./continue", 6}, {"continue", 6}, {"continue/.CodeWiz./def", 6}, {"def", 6}, {"def/.CodeWiz./del", 6}, {"del", 6}, {"del/.CodeWiz./elif", 6}, {"elif", 6}, {"elif/.CodeWiz./else", 6}, {"else", 6}, {"else/.CodeWiz./except", 6}, {"except", 6}, {"except/.CodeWiz./exec", 6}, {"exec/.CodeWiz./finally", 6}, {"finally", 6}, {"finally/.CodeWiz./for", 6}, {"for", 6}, {"for/.CodeWiz./from", 6}, {"from", 6}, {"from/.CodeWiz./global", 6}, {"global", 6}, {"global/.CodeWiz./if", 6}, {"if", 6}, {"if/.CodeWiz./import", 6}, {"import", 6}, {"import/.CodeWiz./lambda", 6}, {"lambda", 6}, {"lambda/.CodeWiz./nonlocal", 6}, {"nonlocal", 6}, {"nonlocal/.CodeWiz./pass", 6}, {"pass", 6}, {"pass/.CodeWiz./print", 6}, {"print/.CodeWiz./raise", 6}, {"raise", 6}, {"raise/.CodeWiz./return", 6}, {"return", 6}, {"return/.CodeWiz./try", 6}, {"try", 6}, {"try/.CodeWiz./while", 6}, {"while", 6}, {"while/.CodeWiz./with", 6}, {"with", 6}, {"with/.CodeWiz./yield", 6}, {"yield", 6}, {"yield/.CodeWiz./match", 6}, {"match", 6}, {"match/.CodeWiz./case", 6}, {"case", 6}};
	colormapRustTS = {{"type_identifier", 4}, {"primitive_type", 4}, {"field_identifier", 4}, {"identifier", 3}, {"scoped_identifier", 4}, {"scoped_identifier/.CodeWiz./identifier", 4}, {"scoped_type_identifier", 4}, {"scoped_type_identifier/.CodeWiz./identifier", 4}, {"scoped_type_identifier/.CodeWiz./scoped_identifier", 4}, {"struct_pattern/.CodeWiz./scoped_type_identifier", 3}, {"scoped_type_identifier/.CodeWiz./type_identifier", 3}, {"call_expression", 5}, {"call_expression/.CodeWiz./identifier", 5}, {"call_expression/.CodeWiz./field_expression", 5}, {"field_expression/.CodeWiz./field_identifier", 5}, {"call_expression/.CodeWiz./scoped_identifier", 5}, {"scoped_identifier/.CodeWiz./::", 5}, {"::", 5}, {"::/.CodeWiz./identifier", 5}, {"generic_function", 5}, {"generic_function/.CodeWiz./identifier", 5}, {"generic_function/.CodeWiz./scoped_identifier", 5}, {"generic_function/.CodeWiz./field_expression", 5}, {"macro_invocation", 5}, {"macro_invocation/.CodeWiz./identifier", 5}, {"!", 5}, {"line_comment", 2}, {"block_comment", 2}, {"doc_comment", 2}, {"(", 7}, {")", 7}, {"[", 7}, {"]", 7}, {"{", 7}, {"}", 7}, {"type_arguments", 7}, {"type_arguments/.CodeWiz./<", 7}, {"<", 7}, {">", 7}, {"type_parameters", 7}, {"type_parameters/.CodeWiz./<", 7}, {":", 7}, {".", 7}, {",", 7}, {";", 7}, {"as", 6}, {"async", 6}, {"await", 6}, {"break", 6}, {"const", 6}, {"continue", 6}, {"default", 6}, {"dyn", 6}, {"else", 6}, {"enum", 6}, {"extern", 6}, {"fn", 6}, {"for", 6}, {"gen", 6}, {"if", 6}, {"impl", 6}, {"in", 6}, {"let", 6}, {"loop", 6}, {"macro_rules!", 6}, {"match", 6}, {"mod", 6}, {"move", 6}, {"pub", 6}, {"raw", 6}, {"ref", 6}, {"return", 6}, {"static", 6}, {"struct", 6}, {"trait", 6}, {"type", 6}, {"union", 6}, {"unsafe", 6}, {"use", 6}, {"where", 6}, {"while", 6}, {"yield", 6}, {"crate", 6}, {"mutable_specifier", 6}, {"self", 6}, {"super", 6}, {"char_literal", 1}, {"string_literal", 1}, {"raw_string_literal", 1}, {"boolean_literal", 3}, {"integer_literal", 3}, {"float_literal", 3}, {"escape_sequence", 1}, {"attribute_item", 4}, {"inner_attribute_item", 4}, {"*", 7}, {"&", 7}, {"'", 7}};
	colormapWGSLTS = {{"int_literal", 8}, {"float_literal", 8}, {"bool_literal", 8}, {"bool/.CodeWiz./u32", 4}, {"u32/.CodeWiz./i32", 4}, {"i32/.CodeWiz./f16", 4}, {"f16/.CodeWiz./f32", 4}, {"type_declaration", 4}, {"function_declaration", 5}, {"function_declaration/.CodeWiz./identifier", 5}, {"identifier", 5}, {"parameter", 4}, {"parameter/.CodeWiz./identifier", 4}, {"struct_declaration", 3}, {"struct_declaration/.CodeWiz./identifier", 3}, {"attribute", 4}, {"attribute/.CodeWiz./identifier", 4}, {"type_constructor_or_function_call_expression", 5}, {"type_constructor_or_function_call_expression/.CodeWiz./type_declaration", 5}, {"struct", 6}, {"struct/.CodeWiz./bitcast", 6}, {"bitcast", 6}, {"bitcast/.CodeWiz./discard", 6}, {"discard", 6}, {"discard/.CodeWiz./enable", 6}, {"enable", 6}, {"enable/.CodeWiz./fallthrough", 6}, {"fallthrough", 6}, {"fallthrough/.CodeWiz./let", 6}, {"let", 6}, {"let/.CodeWiz./type", 6}, {"type", 6}, {"type/.CodeWiz./var", 6}, {"var", 6}, {"var/.CodeWiz./override", 6}, {"override", 6}, {"override/.CodeWiz./texel_format", 6}, {"texel_format", 6}, {"private", 4}, {"private/.CodeWiz./storage", 4}, {"storage", 4}, {"storage/.CodeWiz./uniform", 4}, {"uniform", 4}, {"uniform/.CodeWiz./workgroup", 4}, {"workgroup", 4}, {"read", 4}, {"read/.CodeWiz./read_write", 4}, {"read_write", 4}, {"read_write/.CodeWiz./write", 4}, {"write", 4}, {"fn", 6}, {"return", 6}, {",/.CodeWiz./.", 7}, {"./.CodeWiz./:", 7}, {":/.CodeWiz./;", 7}, {";/.CodeWiz./->", 7}, {"(/.CodeWiz./)", 7}, {")/.CodeWiz./[", 7}, {"[/.CodeWiz./]", 7}, {"]/.CodeWiz./{", 7}, {"{/.CodeWiz./}", 7}, {"loop", 5}, {"loop/.CodeWiz./for", 5}, {"for", 5}, {"for/.CodeWiz./while", 5}, {"while", 5}, {"while/.CodeWiz./break", 5}, {"break", 5}, {"break/.CodeWiz./continue", 5}, {"continue", 5}, {"continue/.CodeWiz./continuing", 5}, {"continuing", 5}, {"if", 6}, {"if/.CodeWiz./else", 6}, {"else", 6}, {"else/.CodeWiz./switch", 6}, {"switch", 6}, {"switch/.CodeWiz./case", 6}, {"case", 6}, {"case/.CodeWiz./default", 6}, {"default", 6}, {"&", 7}, {"&/.CodeWiz./&&", 7}, {"&&", 7}, {"&&/.CodeWiz.//", 7}, {"/", 7}, {"//.CodeWiz./!", 7}, {"!", 7}, {"!/.CodeWiz./=", 7}, {"=", 7}, {"=/.CodeWiz./==", 7}, {"==", 7}, {"==/.CodeWiz./!=", 7}, {"!=", 7}, {"!=/.CodeWiz./>", 7}, {">", 7}, {">/.CodeWiz./>=", 7}, {">=", 7}, {">=/.CodeWiz./>>", 7}, {">>", 7}, {">>/.CodeWiz./<", 7}, {"<", 7}, {"</.CodeWiz./<=", 7}, {"<=", 7}, {"<=/.CodeWiz./<<", 7}, {"<<", 7}, {"<</.CodeWiz./%", 7}, {"%", 7}, {"%/.CodeWiz./-", 7}, {"-", 7}, {"-/.CodeWiz./+", 7}, {"+", 7}, {"+/.CodeWiz./|", 7}, {"|", 7}, {"|/.CodeWiz./||", 7}, {"||", 7}, {"||/.CodeWiz./*", 7}, {"*", 7}, {"*/.CodeWiz./~", 7}, {"~", 7}, {"~/.CodeWiz./^", 7}, {"^", 7}, {"^/.CodeWiz./@", 7}, {"@", 7}, {"@/.CodeWiz./++", 7}, {"++", 7}, {"++/.CodeWiz./--", 7}, {"--", 7}, {"line_comment", 2}, {"line_comment/.CodeWiz./block_comment", 2}, {"block_comment", 2}, {"ERROR", 6}};
	colormapCppTS = {{"call_expression/.CodeWiz./qualified_identifier", 5}, {"qualified_identifier/.CodeWiz./identifier", 5}, {"template_function/.CodeWiz./identifier", 5}, {"template_method/.CodeWiz./field_identifier", 5}, {"function_declarator/.CodeWiz./qualified_identifier", 5}, {"function_declarator", 5}, {"function_declarator/.CodeWiz./field_identifier", 5}, {"field_identifier", 5}, {"namespace_identifier", 4}, {"auto", 4}, {"this", 3}, {"nullptr", 3}, {"catch", 6}, {"catch/.CodeWiz./class", 6}, {"class", 6}, {"class/.CodeWiz./co_await", 6}, {"co_await", 6}, {"co_await/.CodeWiz./co_return", 6}, {"co_return", 6}, {"co_return/.CodeWiz./co_yield", 6}, {"co_yield", 6}, {"co_yield/.CodeWiz./constexpr", 6}, {"constexpr", 6}, {"constexpr/.CodeWiz./constinit", 6}, {"constinit", 6}, {"constinit/.CodeWiz./consteval", 6}, {"consteval", 6}, {"consteval/.CodeWiz./delete", 6}, {"delete", 6}, {"delete/.CodeWiz./explicit", 6}, {"explicit", 6}, {"explicit/.CodeWiz./final", 6}, {"final", 6}, {"final/.CodeWiz./friend", 6}, {"friend", 6}, {"friend/.CodeWiz./mutable", 6}, {"mutable", 6}, {"mutable/.CodeWiz./namespace", 6}, {"namespace", 6}, {"namespace/.CodeWiz./noexcept", 6}, {"noexcept", 6}, {"noexcept/.CodeWiz./new", 6}, {"new", 6}, {"new/.CodeWiz./override", 6}, {"override", 6}, {"override/.CodeWiz./private", 6}, {"private", 6}, {"private/.CodeWiz./protected", 6}, {"protected", 6}, {"protected/.CodeWiz./public", 6}, {"public", 6}, {"public/.CodeWiz./template", 6}, {"template", 6}, {"template/.CodeWiz./throw", 6}, {"throw", 6}, {"throw/.CodeWiz./try", 6}, {"try", 6}, {"try/.CodeWiz./typename", 6}, {"typename", 6}, {"typename/.CodeWiz./using", 6}, {"using", 6}, {"using/.CodeWiz./concept", 6}, {"concept", 6}, {"concept/.CodeWiz./requires", 6}, {"requires", 6}, {"requires/.CodeWiz./virtual", 6}, {"virtual", 6}, {"raw_string_literal", 1}, {"identifier", 3}, {"break", 6}, {"case", 6}, {"const", 6}, {"continue", 6}, {"default", 6}, {"do", 6}, {"else", 6}, {"enum", 6}, {"extern", 6}, {"for", 6}, {"if", 6}, {"inline", 6}, {"return", 6}, {"sizeof", 6}, {"static", 6}, {"struct", 6}, {"switch", 6}, {"typedef", 6}, {"union", 6}, {"volatile", 6}, {"while", 6}, {"#define", 6}, {"#elif", 6}, {"#else", 6}, {"#endif", 6}, {"#if", 6}, {"#ifdef", 6}, {"#ifndef", 6}, {"#include", 6}, {"preproc_directive", 6}, {"--", 7}, {"-", 7}, {"-=", 7}, {"->", 7}, {"=", 7}, {"!=", 7}, {"*", 7}, {"&", 7}, {"&&", 7}, {"+", 7}, {"++", 7}, {"+=", 7}, {"<", 7}, {"==", 7}, {">", 7}, {"||", 7}, {".", 7}, {";", 7}, {"string_literal", 1}, {"system_lib_string", 1}, {"null", 3}, {"number_literal", 8}, {"char_literal", 8}, {"statement_identifier", 4}, {"type_identifier", 4}, {"primitive_type", 4}, {"sized_type_specifier", 4}, {"call_expression", 5}, {"call_expression/.CodeWiz./identifier", 5}, {"call_expression/.CodeWiz./field_expression", 5}, {"field_expression/.CodeWiz./field_identifier", 5}, {"function_declarator/.CodeWiz./identifier", 5}, {"preproc_function_def/.CodeWiz./identifier", 5}, {"comment", 2}};
	colormapTxtTS = {};
	colormapJsTS = {{"identifier", 3}, {"property_identifier", 4}, {"function_expression/.CodeWiz./identifier", 5}, {"function_declaration/.CodeWiz./identifier", 5}, {"method_definition/.CodeWiz./property_identifier", 5}, {"pair", 5}, {"pair/.CodeWiz./property_identifier", 5}, {"function_expression/.CodeWiz./arrow_function", 5}, {"arrow_function/.CodeWiz./assignment_expression", 5}, {"assignment_expression/.CodeWiz./member_expression", 5}, {"member_expression/.CodeWiz./property_identifier", 5}, {"arrow_function/.CodeWiz./variable_declarator", 5}, {"variable_declarator/.CodeWiz./identifier", 5}, {"assignment_expression/.CodeWiz./identifier", 5}, {"arrow_function/.CodeWiz./call_expression", 5}, {"call_expression/.CodeWiz./identifier", 5}, {"call_expression/.CodeWiz./member_expression", 5}, {"identifier/.CodeWiz./shorthand_property_identifier", 3}, {"shorthand_property_identifier/.CodeWiz./shorthand_property_identifier_pattern", 3}, {"arguments", 3}, {"arguments/.CodeWiz./module", 3}, {"module", 3}, {"module/.CodeWiz./console", 3}, {"console", 3}, {"console/.CodeWiz./window", 3}, {"window", 3}, {"window/.CodeWiz./document", 3}, {"document", 3}, {"require", 5}, {"this", 3}, {"super", 3}, {"true/.CodeWiz./false", 3}, {"false/.CodeWiz./null", 3}, {"null/.CodeWiz./undefined", 3}, {"comment", 2}, {"string", 1}, {"string/.CodeWiz./template_string", 1}, {"template_string", 1}, {"regex", 1}, {"number", 8}, {";", 7}, {";/.CodeWiz./optional_chain", 7}, {"optional_chain", 7}, {"optional_chain/.CodeWiz./.", 7}, {".", 7}, {"./.CodeWiz./,", 7}, {",", 7}, {"-", 7}, {"-/.CodeWiz./--", 7}, {"--", 7}, {"--/.CodeWiz./-=", 7}, {"-=", 7}, {"-=/.CodeWiz./+", 7}, {"+", 7}, {"+/.CodeWiz./++", 7}, {"++", 7}, {"++/.CodeWiz./+=", 7}, {"+=", 7}, {"+=/.CodeWiz./*", 7}, {"*", 7}, {"*/.CodeWiz./*=", 7}, {"*=", 7}, {"*=/.CodeWiz./**", 7}, {"**", 7}, {"**/.CodeWiz./**=", 7}, {"**=", 7}, {"**=/.CodeWiz.//", 7}, {"/", 7}, {"//.CodeWiz.//=", 7}, {"/=", 7}, {"/=/.CodeWiz./%", 7}, {"%", 7}, {"%/.CodeWiz./%=", 7}, {"%=", 7}, {"%=/.CodeWiz./<", 7}, {"<", 7}, {"</.CodeWiz./<=", 7}, {"<=", 7}, {"<=/.CodeWiz./<<", 7}, {"<<", 7}, {"<</.CodeWiz./<<=", 7}, {"<<=", 7}, {"<<=/.CodeWiz./=", 7}, {"=", 7}, {"=/.CodeWiz./==", 7}, {"==", 7}, {"==/.CodeWiz./===", 7}, {"===", 7}, {"===/.CodeWiz./!", 7}, {"!", 7}, {"!/.CodeWiz./!=", 7}, {"!=", 7}, {"!=/.CodeWiz./!==", 7}, {"!==", 7}, {"!==/.CodeWiz./=>", 7}, {"=>", 7}, {"=>/.CodeWiz./>", 7}, {">", 7}, {">/.CodeWiz./>=", 7}, {">=", 7}, {">=/.CodeWiz./>>", 7}, {">>", 7}, {">>/.CodeWiz./>>=", 7}, {">>=", 7}, {">>=/.CodeWiz./>>>", 7}, {">>>", 7}, {">>>/.CodeWiz./>>>=", 7}, {">>>=", 7}, {">>>=/.CodeWiz./~", 7}, {"~", 7}, {"~/.CodeWiz./^", 7}, {"^", 7}, {"^/.CodeWiz./&", 7}, {"&", 7}, {"&/.CodeWiz./|", 7}, {"|", 7}, {"|/.CodeWiz./^=", 7}, {"^=", 7}, {"^=/.CodeWiz./&=", 7}, {"&=", 7}, {"&=/.CodeWiz./|=", 7}, {"|=", 7}, {"|=/.CodeWiz./&&", 7}, {"&&", 7}, {"&&/.CodeWiz./||", 7}, {"||", 7}, {"||/.CodeWiz./??", 7}, {"??", 7}, {"??/.CodeWiz./&&=", 7}, {"&&=", 7}, {"&&=/.CodeWiz./||=", 7}, {"||=", 7}, {"||=/.CodeWiz./??=", 7}, {"??=", 7}, {"(", 7}, {"(/.CodeWiz./)", 7}, {")", 7}, {")/.CodeWiz./[", 7}, {"[", 7}, {"[/.CodeWiz./]", 7}, {"]", 7}, {"]/.CodeWiz./{", 7}, {"{", 7}, {"{/.CodeWiz./}", 7}, {"}", 7}, {"template_substitution", 7}, {"template_substitution/.CodeWiz./${", 7}, {"${", 7}, {"as", 6}, {"as/.CodeWiz./async", 6}, {"async", 6}, {"async/.CodeWiz./await", 6}, {"await", 6}, {"await/.CodeWiz./break", 6}, {"break", 6}, {"break/.CodeWiz./case", 6}, {"case", 6}, {"case/.CodeWiz./catch", 6}, {"catch", 6}, {"catch/.CodeWiz./class", 6}, {"class", 6}, {"class/.CodeWiz./const", 6}, {"const", 6}, {"const/.CodeWiz./continue", 6}, {"continue", 6}, {"continue/.CodeWiz./debugger", 6}, {"debugger", 6}, {"debugger/.CodeWiz./default", 6}, {"default", 6}, {"default/.CodeWiz./delete", 6}, {"delete", 6}, {"delete/.CodeWiz./do", 6}, {"do", 6}, {"do/.CodeWiz./else", 6}, {"else", 6}, {"else/.CodeWiz./export", 6}, {"export", 6}, {"export/.CodeWiz./extends", 6}, {"extends", 6}, {"extends/.CodeWiz./finally", 6}, {"finally", 6}, {"finally/.CodeWiz./for", 6}, {"for", 6}, {"for/.CodeWiz./from", 6}, {"from", 6}, {"from/.CodeWiz./function", 6}, {"function", 6}, {"function/.CodeWiz./get", 6}, {"get", 6}, {"get/.CodeWiz./if", 6}, {"if", 6}, {"if/.CodeWiz./import", 6}, {"import", 6}, {"import/.CodeWiz./in", 6}, {"in", 6}, {"in/.CodeWiz./instanceof", 6}, {"instanceof", 6}, {"instanceof/.CodeWiz./let", 6}, {"let", 6}, {"let/.CodeWiz./new", 6}, {"new", 6}, {"new/.CodeWiz./of", 6}, {"of", 6}, {"of/.CodeWiz./return", 6}, {"return", 6}, {"return/.CodeWiz./set", 6}, {"set", 6}, {"set/.CodeWiz./static", 6}, {"static", 6}, {"static/.CodeWiz./switch", 6}, {"switch", 6}, {"switch/.CodeWiz./target", 6}, {"target", 6}, {"target/.CodeWiz./throw", 6}, {"throw", 6}, {"throw/.CodeWiz./try", 6}, {"try", 6}, {"try/.CodeWiz./typeof", 6}, {"typeof", 6}, {"typeof/.CodeWiz./var", 6}, {"var", 6}, {"var/.CodeWiz./void", 6}, {"void", 6}, {"void/.CodeWiz./while", 6}, {"while", 6}, {"while/.CodeWiz./with", 6}, {"with", 6}, {"with/.CodeWiz./yield", 6}, {"yield", 6}, {"expression_statement/.CodeWiz./undefined", 6}};
	colormapHTMLTS = {{"tag_name", 6}, {"erroneous_end_tag_name", 6}, {"doctype", 3}, {"attribute_name", 4}, {"attribute_value", 1}, {"comment", 2}, {"<", 7}, {"</.CodeWiz./>", 7}, {">", 7}, {">/.CodeWiz./</", 7}, {"</", 7}, {"<//.CodeWiz.//>", 7}, {"/>", 7}};
	colormapGoTS = {{"call_expression", 5}, {"call_expression/.CodeWiz./identifier", 5}, {"identifier", 5}, {"append", 5}, {"append/.CodeWiz./cap", 5}, {"cap", 5}, {"cap/.CodeWiz./close", 5}, {"close", 5}, {"close/.CodeWiz./complex", 5}, {"complex", 5}, {"complex/.CodeWiz./copy", 5}, {"copy", 5}, {"copy/.CodeWiz./delete", 5}, {"delete", 5}, {"delete/.CodeWiz./imag", 5}, {"imag", 5}, {"imag/.CodeWiz./len", 5}, {"len", 5}, {"len/.CodeWiz./make", 5}, {"make", 5}, {"make/.CodeWiz./new", 5}, {"new", 5}, {"new/.CodeWiz./panic", 5}, {"panic", 5}, {"panic/.CodeWiz./print", 5}, {"print", 5}, {"print/.CodeWiz./println", 5}, {"println", 5}, {"println/.CodeWiz./real", 5}, {"real", 5}, {"real/.CodeWiz./recover", 5}, {"recover", 5}, {"call_expression/.CodeWiz./selector_expression", 5}, {"selector_expression/.CodeWiz./field_identifier", 5}, {"function_declaration/.CodeWiz./identifier", 5}, {"method_declaration/.CodeWiz./field_identifier", 5}, {"type_identifier", 4}, {"field_identifier", 4}, {"--", 7}, {"--/.CodeWiz./-", 7}, {"-", 7}, {"-/.CodeWiz./-=", 7}, {"-=", 7}, {"-=/.CodeWiz./:=", 7}, {":=", 7}, {":=/.CodeWiz./!", 7}, {"!", 7}, {"!/.CodeWiz./!=", 7}, {"!=", 7}, {"!=/.CodeWiz./...", 7}, {"...", 7}, {".../.CodeWiz./*", 7}, {"*", 7}, {"*/.CodeWiz./*=", 7}, {"*=", 7}, {"*=/.CodeWiz.//", 7}, {"/", 7}, {"//.CodeWiz.//=", 7}, {"/=", 7}, {"/=/.CodeWiz./&", 7}, {"&", 7}, {"&/.CodeWiz./&&", 7}, {"&&", 7}, {"&&/.CodeWiz./&=", 7}, {"&=", 7}, {"&=/.CodeWiz./%", 7}, {"%", 7}, {"%/.CodeWiz./%=", 7}, {"%=", 7}, {"%=/.CodeWiz./^", 7}, {"^", 7}, {"^/.CodeWiz./^=", 7}, {"^=", 7}, {"^=/.CodeWiz./+", 7}, {"+", 7}, {"+/.CodeWiz./++", 7}, {"++", 7}, {"++/.CodeWiz./+=", 7}, {"+=", 7}, {"+=/.CodeWiz./<-", 7}, {"<-", 7}, {"<-/.CodeWiz./<", 7}, {"<", 7}, {"</.CodeWiz./<<", 7}, {"<<", 7}, {"<</.CodeWiz./<<=", 7}, {"<<=", 7}, {"<<=/.CodeWiz./<=", 7}, {"<=", 7}, {"<=/.CodeWiz./=", 7}, {"=", 7}, {"=/.CodeWiz./==", 7}, {"==", 7}, {"==/.CodeWiz./>", 7}, {">", 7}, {">/.CodeWiz./>=", 7}, {">=", 7}, {">=/.CodeWiz./>>", 7}, {">>", 7}, {">>/.CodeWiz./>>=", 7}, {">>=", 7}, {">>=/.CodeWiz./|", 7}, {"|", 7}, {"|/.CodeWiz./|=", 7}, {"|=", 7}, {"|=/.CodeWiz./||", 7}, {"||", 7}, {"||/.CodeWiz./~", 7}, {"~", 7}, {"break", 6}, {"break/.CodeWiz./case", 6}, {"case", 6}, {"case/.CodeWiz./chan", 6}, {"chan", 6}, {"chan/.CodeWiz./const", 6}, {"const", 6}, {"const/.CodeWiz./continue", 6}, {"continue", 6}, {"continue/.CodeWiz./default", 6}, {"default", 6}, {"default/.CodeWiz./defer", 6}, {"defer", 6}, {"defer/.CodeWiz./else", 6}, {"else", 6}, {"else/.CodeWiz./fallthrough", 6}, {"fallthrough", 6}, {"fallthrough/.CodeWiz./for", 6}, {"for", 6}, {"for/.CodeWiz./func", 6}, {"func", 6}, {"func/.CodeWiz./go", 6}, {"go", 6}, {"go/.CodeWiz./goto", 6}, {"goto", 6}, {"goto/.CodeWiz./if", 6}, {"if", 6}, {"if/.CodeWiz./import", 6}, {"import", 6}, {"import/.CodeWiz./interface", 6}, {"interface", 6}, {"interface/.CodeWiz./map", 6}, {"map", 6}, {"map/.CodeWiz./package", 6}, {"package", 6}, {"package/.CodeWiz./range", 6}, {"range", 6}, {"range/.CodeWiz./return", 6}, {"return", 6}, {"return/.CodeWiz./select", 6}, {"select", 6}, {"select/.CodeWiz./struct", 6}, {"struct", 6}, {"struct/.CodeWiz./switch", 6}, {"switch", 6}, {"switch/.CodeWiz./type", 6}, {"type", 6}, {"type/.CodeWiz./var", 6}, {"var", 6}, {"interpreted_string_literal/.CodeWiz./raw_string_literal", 1}, {"raw_string_literal/.CodeWiz./rune_literal", 1}, {"escape_sequence", 1}, {"int_literal/.CodeWiz./float_literal", 8}, {"float_literal/.CodeWiz./imaginary_literal", 8}, {"true/.CodeWiz./false", 3}, {"false/.CodeWiz./nil", 3}, {"nil/.CodeWiz./iota", 3}, {"comment", 2}};
	colormapLuaTS = {{"if_start/.CodeWiz./if_then", 6}, {"if_then/.CodeWiz./if_elseif", 6}, {"if_elseif/.CodeWiz./if_else", 6}, {"if_else/.CodeWiz./if_end", 6}, {"for_start/.CodeWiz./for_in", 6}, {"for_in/.CodeWiz./for_do", 6}, {"for_do/.CodeWiz./for_end", 6}, {"while_start/.CodeWiz./while_do", 6}, {"while_do/.CodeWiz./while_end", 6}, {"repeat_start", 6}, {"repeat_start/.CodeWiz./repeat_until", 6}, {"repeat_until", 6}, {"break_statement", 6}, {"return_statement", 6}, {"return_statement/.CodeWiz./module_return_statement", 6}, {"module_return_statement", 6}, {"do_start", 6}, {"do_start/.CodeWiz./do_end", 6}, {"do_end", 6}, {"not", 6}, {"not/.CodeWiz./and", 6}, {"and", 6}, {"and/.CodeWiz./or", 6}, {"or", 6}, {"=", 7}, {"=/.CodeWiz./~=", 7}, {"~=", 7}, {"~=/.CodeWiz./==", 7}, {"==", 7}, {"==/.CodeWiz./<=", 7}, {"<=", 7}, {"<=/.CodeWiz./>=", 7}, {">=", 7}, {">=/.CodeWiz./<", 7}, {"<", 7}, {"</.CodeWiz./>", 7}, {">", 7}, {">/.CodeWiz./+", 7}, {"+", 7}, {"+/.CodeWiz./-", 7}, {"-", 7}, {"-/.CodeWiz./%", 7}, {"%", 7}, {"%/.CodeWiz.//", 7}, {"/", 7}, {"//.CodeWiz.///", 7}, {"//", 7}, {"///.CodeWiz./*", 7}, {"*", 7}, {"*/.CodeWiz./^", 7}, {"^", 7}, {"^/.CodeWiz./&", 7}, {"&", 7}, {"&/.CodeWiz./~", 7}, {"~", 7}, {"~/.CodeWiz./|", 7}, {"|", 7}, {"|/.CodeWiz./>>", 7}, {">>", 7}, {">>/.CodeWiz./<<", 7}, {"<<", 7}, {"<</.CodeWiz./..", 7}, {"..", 7}, {"../.CodeWiz./#", 7}, {"#", 7}, {",", 7}, {",/.CodeWiz./.", 7}, {".", 7}, {"left_paren", 7}, {"left_paren/.CodeWiz./right_paren", 7}, {"right_paren", 7}, {"right_paren/.CodeWiz./[", 7}, {"[", 7}, {"[/.CodeWiz./]", 7}, {"]", 7}, {"]/.CodeWiz./{", 7}, {"{", 7}, {"{/.CodeWiz./}", 7}, {"}", 7}, {"identifier", 3}, {"self", 3}, {"boolean", 8}, {"nil", 3}, {"ellipsis", 3}, {"local", 6}, {"function_call_paren", 7}, {"function_start", 6}, {"function_start/.CodeWiz./function_end", 6}, {"function_end", 6}, {"emmy_type", 4}, {"emmy_literal", 1}, {"emmy_parameter", 4}, {"emmy_parameter/.CodeWiz./identifier", 4}, {"_", 2}, {"emmy_class", 2}, {"emmy_function_parameter/.CodeWiz./_", 4}, {"emmy_note", 2}, {"emmy_see", 2}, {"emmy_return", 2}, {"emmy_header", 2}, {"emmy_ignore", 2}, {"documentation_brief", 2}, {"documentation_command", 2}, {"function_call/.CodeWiz./identifier", 3}, {"identifier/.CodeWiz./function_call_paren", 3}, {"function_call", 5}, {"string_argument", 1}, {"table_argument", 2}, {"table_argument/.CodeWiz./comment", 2}, {"comment", 2}, {"string", 1}, {"number", 8}, {"ERROR", 6}};
	colormapCsharpTS = {{"identifier", 3}, {"predefined_type", 4}, {"real_literal", 8}, {"real_literal/.CodeWiz./integer_literal", 8}, {"integer_literal", 8}, {"character_literal/.CodeWiz./string_literal", 1}, {"string_literal/.CodeWiz./raw_string_literal", 1}, {"raw_string_literal/.CodeWiz./verbatim_string_literal", 1}, {"verbatim_string_literal/.CodeWiz./interpolated_string_expression", 1}, {"interpolated_string_expression/.CodeWiz./interpolation_start", 1}, {"interpolation_start/.CodeWiz./interpolation_quote", 1}, {"escape_sequence", 1}, {"boolean_literal", 3}, {"boolean_literal/.CodeWiz./null_literal", 3}, {"null_literal", 3}, {"comment", 2}, {";", 7}, {";/.CodeWiz./.", 7}, {".", 7}, {"./.CodeWiz./,", 7}, {",", 7}, {"--", 7}, {"--/.CodeWiz./-", 7}, {"-", 7}, {"-/.CodeWiz./-=", 7}, {"-=", 7}, {"-=/.CodeWiz./&", 7}, {"&", 7}, {"&/.CodeWiz./&=", 7}, {"&=", 7}, {"&=/.CodeWiz./&&", 7}, {"&&", 7}, {"&&/.CodeWiz./+", 7}, {"+", 7}, {"+/.CodeWiz./++", 7}, {"++", 7}, {"++/.CodeWiz./+=", 7}, {"+=", 7}, {"+=/.CodeWiz./<", 7}, {"<", 7}, {"</.CodeWiz./<=", 7}, {"<=", 7}, {"<=/.CodeWiz./<<", 7}, {"<<", 7}, {"<</.CodeWiz./<<=", 7}, {"<<=", 7}, {"<<=/.CodeWiz./=", 7}, {"=", 7}, {"=/.CodeWiz./==", 7}, {"==", 7}, {"==/.CodeWiz./!", 7}, {"!", 7}, {"!/.CodeWiz./!=", 7}, {"!=", 7}, {"!=/.CodeWiz./=>", 7}, {"=>", 7}, {"=>/.CodeWiz./>", 7}, {">", 7}, {">/.CodeWiz./>=", 7}, {">=", 7}, {">=/.CodeWiz./>>", 7}, {">>", 7}, {">>/.CodeWiz./>>=", 7}, {">>=", 7}, {">>=/.CodeWiz./>>>", 7}, {">>>", 7}, {">>>/.CodeWiz./>>>=", 7}, {">>>=", 7}, {">>>=/.CodeWiz./|", 7}, {"|", 7}, {"|/.CodeWiz./|=", 7}, {"|=", 7}, {"|=/.CodeWiz./||", 7}, {"||", 7}, {"||/.CodeWiz./?", 7}, {"?", 7}, {"?/.CodeWiz./??", 7}, {"??", 7}, {"??/.CodeWiz./??=", 7}, {"??=", 7}, {"??=/.CodeWiz./^", 7}, {"^", 7}, {"^/.CodeWiz./^=", 7}, {"^=", 7}, {"^=/.CodeWiz./~", 7}, {"~", 7}, {"~/.CodeWiz./*", 7}, {"*", 7}, {"*/.CodeWiz./*=", 7}, {"*=", 7}, {"*=/.CodeWiz.//", 7}, {"/", 7}, {"//.CodeWiz.//=", 7}, {"/=", 7}, {"/=/.CodeWiz./%", 7}, {"%", 7}, {"%/.CodeWiz./%=", 7}, {"%=", 7}, {"%=/.CodeWiz./:", 7}, {":", 7}, {"(", 7}, {"(/.CodeWiz./)", 7}, {")", 7}, {")/.CodeWiz./[", 7}, {"[", 7}, {"[/.CodeWiz./]", 7}, {"]", 7}, {"]/.CodeWiz./{", 7}, {"{", 7}, {"{/.CodeWiz./}", 7}, {"}", 7}, {"}/.CodeWiz./interpolation_brace", 7}, {"interpolation_brace", 7}, {"modifier", 6}, {"modifier/.CodeWiz./this", 6}, {"this", 6}, {"this/.CodeWiz./implicit_type", 6}, {"implicit_type", 6}, {"add", 6}, {"add/.CodeWiz./alias", 6}, {"alias", 6}, {"alias/.CodeWiz./as", 6}, {"as", 6}, {"as/.CodeWiz./base", 6}, {"base", 6}, {"base/.CodeWiz./break", 6}, {"break", 6}, {"break/.CodeWiz./case", 6}, {"case", 6}, {"case/.CodeWiz./catch", 6}, {"catch", 6}, {"catch/.CodeWiz./checked", 6}, {"checked", 6}, {"checked/.CodeWiz./class", 6}, {"class", 6}, {"class/.CodeWiz./continue", 6}, {"continue", 6}, {"continue/.CodeWiz./default", 6}, {"default", 6}, {"default/.CodeWiz./delegate", 6}, {"delegate", 6}, {"delegate/.CodeWiz./do", 6}, {"do", 6}, {"do/.CodeWiz./else", 6}, {"else", 6}, {"else/.CodeWiz./enum", 6}, {"enum", 6}, {"enum/.CodeWiz./event", 6}, {"event", 6}, {"event/.CodeWiz./explicit", 6}, {"explicit", 6}, {"explicit/.CodeWiz./extern", 6}, {"extern", 6}, {"extern/.CodeWiz./finally", 6}, {"finally", 6}, {"finally/.CodeWiz./for", 6}, {"for", 6}, {"for/.CodeWiz./foreach", 6}, {"foreach", 6}, {"foreach/.CodeWiz./global", 6}, {"global", 6}, {"global/.CodeWiz./goto", 6}, {"goto", 6}, {"goto/.CodeWiz./if", 6}, {"if", 6}, {"if/.CodeWiz./implicit", 6}, {"implicit", 6}, {"implicit/.CodeWiz./interface", 6}, {"interface", 6}, {"interface/.CodeWiz./is", 6}, {"is", 6}, {"is/.CodeWiz./lock", 6}, {"lock", 6}, {"lock/.CodeWiz./namespace", 6}, {"namespace", 6}, {"namespace/.CodeWiz./notnull", 6}, {"notnull", 6}, {"notnull/.CodeWiz./operator", 6}, {"operator", 6}, {"operator/.CodeWiz./params", 6}, {"params", 6}, {"params/.CodeWiz./return", 6}, {"return", 6}, {"return/.CodeWiz./remove", 6}, {"remove", 6}, {"remove/.CodeWiz./sizeof", 6}, {"sizeof", 6}, {"sizeof/.CodeWiz./stackalloc", 6}, {"stackalloc", 6}, {"stackalloc/.CodeWiz./static", 6}, {"static", 6}, {"static/.CodeWiz./struct", 6}, {"struct", 6}, {"struct/.CodeWiz./switch", 6}, {"switch", 6}, {"switch/.CodeWiz./throw", 6}, {"throw", 6}, {"throw/.CodeWiz./try", 6}, {"try", 6}, {"try/.CodeWiz./typeof", 6}, {"typeof", 6}, {"typeof/.CodeWiz./unchecked", 6}, {"unchecked", 6}, {"unchecked/.CodeWiz./using", 6}, {"using", 6}, {"using/.CodeWiz./while", 6}, {"while", 6}, {"while/.CodeWiz./new", 6}, {"new", 6}, {"new/.CodeWiz./await", 6}, {"await", 6}, {"await/.CodeWiz./in", 6}, {"in", 6}, {"in/.CodeWiz./yield", 6}, {"yield", 6}, {"yield/.CodeWiz./get", 6}, {"get", 6}, {"get/.CodeWiz./set", 6}, {"set", 6}, {"set/.CodeWiz./when", 6}, {"when", 6}, {"when/.CodeWiz./out", 6}, {"out", 6}, {"out/.CodeWiz./ref", 6}, {"ref", 6}, {"ref/.CodeWiz./from", 6}, {"from", 6}, {"from/.CodeWiz./where", 6}, {"where", 6}, {"where/.CodeWiz./select", 6}, {"select", 6}, {"select/.CodeWiz./record", 6}, {"record", 6}, {"record/.CodeWiz./init", 6}, {"init", 6}, {"init/.CodeWiz./with", 6}, {"with", 6}, {"with/.CodeWiz./let", 6}, {"let", 6}, {"parameter/.CodeWiz./identifier", 3}};
	colormapGLSLTS = {{"break", 6}, {"case", 6}, {"const", 6}, {"continue", 6}, {"default", 6}, {"do", 6}, {"else", 6}, {"enum", 6}, {"extern", 6}, {"for", 6}, {"if", 6}, {"inline", 6}, {"return", 6}, {"sizeof", 6}, {"static", 6}, {"struct", 6}, {"switch", 6}, {"typedef", 6}, {"union", 6}, {"volatile", 6}, {"while", 6}, {"#define", 6}, {"#elif", 6}, {"#else", 6}, {"#endif", 6}, {"#if", 6}, {"#ifdef", 6}, {"#ifndef", 6}, {"#include", 6}, {"preproc_directive", 6}, {"--", 7}, {"-", 7}, {"-=", 7}, {"->", 7}, {"=", 7}, {"!=", 7}, {"*", 7}, {"&", 7}, {"&&", 7}, {"+", 7}, {"++", 7}, {"+=", 7}, {"<", 7}, {"==", 7}, {">", 7}, {"||", 7}, {".", 7}, {";", 7}, {"string_literal", 1}, {"system_lib_string", 1}, {"null", 3}, {"number_literal", 8}, {"char_literal", 8}, {"call_expression", 5}, {"call_expression/.CodeWiz./identifier", 5}, {"identifier", 5}, {"call_expression/.CodeWiz./field_expression", 5}, {"field_expression/.CodeWiz./field_identifier", 5}, {"function_declarator", 5}, {"function_declarator/.CodeWiz./identifier", 5}, {"preproc_function_def/.CodeWiz./identifier", 5}, {"field_identifier", 4}, {"statement_identifier", 4}, {"type_identifier", 4}, {"primitive_type", 4}, {"sized_type_specifier", 4}, {"comment", 2}, {"in", 4}, {"in/.CodeWiz./out", 4}, {"out", 4}, {"out/.CodeWiz./inout", 4}, {"inout", 4}, {"inout/.CodeWiz./uniform", 4}, {"uniform", 4}, {"uniform/.CodeWiz./shared", 4}, {"shared", 4}, {"shared/.CodeWiz./layout", 4}, {"layout", 4}, {"layout/.CodeWiz./attribute", 4}, {"attribute", 4}, {"attribute/.CodeWiz./varying", 4}, {"varying", 4}, {"varying/.CodeWiz./buffer", 4}, {"buffer", 4}, {"buffer/.CodeWiz./coherent", 4}, {"coherent", 4}, {"coherent/.CodeWiz./readonly", 4}, {"readonly", 4}, {"readonly/.CodeWiz./writeonly", 4}, {"writeonly", 4}, {"writeonly/.CodeWiz./precision", 4}, {"precision", 4}, {"precision/.CodeWiz./highp", 4}, {"highp", 4}, {"highp/.CodeWiz./mediump", 4}, {"mediump", 4}, {"mediump/.CodeWiz./lowp", 4}, {"lowp", 4}, {"lowp/.CodeWiz./centroid", 4}, {"centroid", 4}, {"centroid/.CodeWiz./sample", 4}, {"sample", 4}, {"sample/.CodeWiz./patch", 4}, {"patch", 4}, {"patch/.CodeWiz./smooth", 4}, {"smooth", 4}, {"smooth/.CodeWiz./flat", 4}, {"flat", 4}, {"flat/.CodeWiz./noperspective", 4}, {"noperspective", 4}, {"noperspective/.CodeWiz./invariant", 4}, {"invariant", 4}, {"invariant/.CodeWiz./precise", 4}, {"precise", 4}, {"subroutine", 6}, {"extension_storage_class", 6}, {"^gl_", 3}};
	colormapJavaTS = {{"identifier", 3}, {"method_declaration/.CodeWiz./identifier", 5}, {"method_invocation/.CodeWiz./identifier", 5}, {"super", 5}, {"annotation/.CodeWiz./identifier", 4}, {"marker_annotation/.CodeWiz./identifier", 4}, {"@", 7}, {"type_identifier", 4}, {"interface_declaration/.CodeWiz./identifier", 4}, {"class_declaration/.CodeWiz./identifier", 4}, {"enum_declaration/.CodeWiz./identifier", 4}, {"field_access", 4}, {"field_access/.CodeWiz./identifier", 4}, {"scoped_identifier", 4}, {"scoped_identifier/.CodeWiz./identifier", 4}, {"method_invocation", 4}, {"method_reference", 4}, {"method_reference/.CodeWiz./identifier", 4}, {"constructor_declaration/.CodeWiz./identifier", 4}, {"boolean_type/.CodeWiz./integral_type", 4}, {"integral_type/.CodeWiz./floating_point_type", 4}, {"floating_point_type/.CodeWiz./void_type", 4}, {"this", 3}, {"hex_integer_literal/.CodeWiz./decimal_integer_literal", 8}, {"decimal_integer_literal/.CodeWiz./octal_integer_literal", 8}, {"octal_integer_literal/.CodeWiz./decimal_floating_point_literal", 8}, {"decimal_floating_point_literal/.CodeWiz./hex_floating_point_literal", 8}, {"character_literal", 1}, {"character_literal/.CodeWiz./string_literal", 1}, {"string_literal", 1}, {"escape_sequence", 1}, {"true/.CodeWiz./false", 3}, {"false/.CodeWiz./null_literal", 3}, {"line_comment", 2}, {"line_comment/.CodeWiz./block_comment", 2}, {"block_comment", 2}, {"abstract", 6}, {"abstract/.CodeWiz./assert", 6}, {"assert", 6}, {"assert/.CodeWiz./break", 6}, {"break", 6}, {"break/.CodeWiz./case", 6}, {"case", 6}, {"case/.CodeWiz./catch", 6}, {"catch", 6}, {"catch/.CodeWiz./class", 6}, {"class", 6}, {"class/.CodeWiz./continue", 6}, {"continue", 6}, {"continue/.CodeWiz./default", 6}, {"default", 6}, {"default/.CodeWiz./do", 6}, {"do", 6}, {"do/.CodeWiz./else", 6}, {"else", 6}, {"else/.CodeWiz./enum", 6}, {"enum", 6}, {"enum/.CodeWiz./exports", 6}, {"exports", 6}, {"exports/.CodeWiz./extends", 6}, {"extends", 6}, {"extends/.CodeWiz./final", 6}, {"final", 6}, {"final/.CodeWiz./finally", 6}, {"finally", 6}, {"finally/.CodeWiz./for", 6}, {"for", 6}, {"for/.CodeWiz./if", 6}, {"if", 6}, {"if/.CodeWiz./implements", 6}, {"implements", 6}, {"implements/.CodeWiz./import", 6}, {"import", 6}, {"import/.CodeWiz./instanceof", 6}, {"instanceof", 6}, {"instanceof/.CodeWiz./interface", 6}, {"interface", 6}, {"interface/.CodeWiz./module", 6}, {"module", 6}, {"module/.CodeWiz./native", 6}, {"native", 6}, {"native/.CodeWiz./new", 6}, {"new", 6}, {"new/.CodeWiz./non-sealed", 6}, {"non-sealed", 6}, {"non-sealed/.CodeWiz./open", 6}, {"open", 6}, {"open/.CodeWiz./opens", 6}, {"opens", 6}, {"opens/.CodeWiz./package", 6}, {"package", 6}, {"package/.CodeWiz./permits", 6}, {"permits", 6}, {"permits/.CodeWiz./private", 6}, {"private", 6}, {"private/.CodeWiz./protected", 6}, {"protected", 6}, {"protected/.CodeWiz./provides", 6}, {"provides", 6}, {"provides/.CodeWiz./public", 6}, {"public", 6}, {"public/.CodeWiz./requires", 6}, {"requires", 6}, {"requires/.CodeWiz./record", 6}, {"record", 6}, {"record/.CodeWiz./return", 6}, {"return", 6}, {"return/.CodeWiz./sealed", 6}, {"sealed", 6}, {"sealed/.CodeWiz./static", 6}, {"static", 6}, {"static/.CodeWiz./strictfp", 6}, {"strictfp", 6}, {"strictfp/.CodeWiz./switch", 6}, {"switch", 6}, {"switch/.CodeWiz./synchronized", 6}, {"synchronized", 6}, {"synchronized/.CodeWiz./throw", 6}, {"throw", 6}, {"throw/.CodeWiz./throws", 6}, {"throws", 6}, {"throws/.CodeWiz./to", 6}, {"to", 6}, {"to/.CodeWiz./transient", 6}, {"transient", 6}, {"transient/.CodeWiz./transitive", 6}, {"transitive", 6}, {"transitive/.CodeWiz./try", 6}, {"try", 6}, {"try/.CodeWiz./uses", 6}, {"uses", 6}, {"uses/.CodeWiz./volatile", 6}, {"volatile", 6}, {"volatile/.CodeWiz./when", 6}, {"when", 6}, {"when/.CodeWiz./while", 6}, {"while", 6}, {"while/.CodeWiz./with", 6}, {"with", 6}, {"with/.CodeWiz./yield", 6}, {"yield", 6}};
	colormapTsTS = {{"type_identifier", 4}, {"predefined_type", 4}, {"identifier", 4}, {"type_arguments", 7}, {"type_arguments/.CodeWiz./<", 7}, {"<", 7}, {">", 7}, {"abstract", 6}, {"abstract/.CodeWiz./declare", 6}, {"declare", 6}, {"declare/.CodeWiz./enum", 6}, {"enum", 6}, {"enum/.CodeWiz./export", 6}, {"export", 6}, {"export/.CodeWiz./implements", 6}, {"implements", 6}, {"implements/.CodeWiz./interface", 6}, {"interface", 6}, {"interface/.CodeWiz./keyof", 6}, {"keyof", 6}, {"keyof/.CodeWiz./namespace", 6}, {"namespace", 6}, {"namespace/.CodeWiz./private", 6}, {"private", 6}, {"private/.CodeWiz./protected", 6}, {"protected", 6}, {"protected/.CodeWiz./public", 6}, {"public", 6}, {"public/.CodeWiz./type", 6}, {"type", 6}, {"type/.CodeWiz./readonly", 6}, {"readonly", 6}, {"readonly/.CodeWiz./override", 6}, {"override", 6}, {"override/.CodeWiz./satisfies", 6}, {"satisfies", 6}, {"property_identifier", 4}, {"function_expression/.CodeWiz./identifier", 5}, {"function_declaration/.CodeWiz./identifier", 5}, {"method_definition/.CodeWiz./property_identifier", 5}, {"pair", 5}, {"pair/.CodeWiz./property_identifier", 5}, {"function_expression/.CodeWiz./arrow_function", 5}, {"arrow_function/.CodeWiz./assignment_expression", 5}, {"assignment_expression/.CodeWiz./member_expression", 5}, {"member_expression/.CodeWiz./property_identifier", 5}, {"arrow_function/.CodeWiz./variable_declarator", 5}, {"variable_declarator/.CodeWiz./identifier", 5}, {"assignment_expression/.CodeWiz./identifier", 5}, {"arrow_function/.CodeWiz./call_expression", 5}, {"call_expression/.CodeWiz./identifier", 5}, {"call_expression/.CodeWiz./member_expression", 5}, {"identifier/.CodeWiz./shorthand_property_identifier", 3}, {"shorthand_property_identifier/.CodeWiz./shorthand_property_identifier_pattern", 3}, {"arguments", 3}, {"arguments/.CodeWiz./module", 3}, {"module", 3}, {"module/.CodeWiz./console", 3}, {"console", 3}, {"console/.CodeWiz./window", 3}, {"window", 3}, {"window/.CodeWiz./document", 3}, {"document", 3}, {"require", 5}, {"this", 3}, {"super", 3}, {"true/.CodeWiz./false", 3}, {"false/.CodeWiz./null", 3}, {"null/.CodeWiz./undefined", 3}, {"comment", 2}, {"string", 1}, {"string/.CodeWiz./template_string", 1}, {"template_string", 1}, {"regex", 1}, {"number", 8}, {";", 7}, {";/.CodeWiz./optional_chain", 7}, {"optional_chain", 7}, {"optional_chain/.CodeWiz./.", 7}, {".", 7}, {"./.CodeWiz./,", 7}, {",", 7}, {"-", 7}, {"-/.CodeWiz./--", 7}, {"--", 7}, {"--/.CodeWiz./-=", 7}, {"-=", 7}, {"-=/.CodeWiz./+", 7}, {"+", 7}, {"+/.CodeWiz./++", 7}, {"++", 7}, {"++/.CodeWiz./+=", 7}, {"+=", 7}, {"+=/.CodeWiz./*", 7}, {"*", 7}, {"*/.CodeWiz./*=", 7}, {"*=", 7}, {"*=/.CodeWiz./**", 7}, {"**", 7}, {"**/.CodeWiz./**=", 7}, {"**=", 7}, {"**=/.CodeWiz.//", 7}, {"/", 7}, {"//.CodeWiz.//=", 7}, {"/=", 7}, {"/=/.CodeWiz./%", 7}, {"%", 7}, {"%/.CodeWiz./%=", 7}, {"%=", 7}, {"%=/.CodeWiz./<", 7}, {"</.CodeWiz./<=", 7}, {"<=", 7}, {"<=/.CodeWiz./<<", 7}, {"<<", 7}, {"<</.CodeWiz./<<=", 7}, {"<<=", 7}, {"<<=/.CodeWiz./=", 7}, {"=", 7}, {"=/.CodeWiz./==", 7}, {"==", 7}, {"==/.CodeWiz./===", 7}, {"===", 7}, {"===/.CodeWiz./!", 7}, {"!", 7}, {"!/.CodeWiz./!=", 7}, {"!=", 7}, {"!=/.CodeWiz./!==", 7}, {"!==", 7}, {"!==/.CodeWiz./=>", 7}, {"=>", 7}, {"=>/.CodeWiz./>", 7}, {">/.CodeWiz./>=", 7}, {">=", 7}, {">=/.CodeWiz./>>", 7}, {">>", 7}, {">>/.CodeWiz./>>=", 7}, {">>=", 7}, {">>=/.CodeWiz./>>>", 7}, {">>>", 7}, {">>>/.CodeWiz./>>>=", 7}, {">>>=", 7}, {">>>=/.CodeWiz./~", 7}, {"~", 7}, {"~/.CodeWiz./^", 7}, {"^", 7}, {"^/.CodeWiz./&", 7}, {"&", 7}, {"&/.CodeWiz./|", 7}, {"|", 7}, {"|/.CodeWiz./^=", 7}, {"^=", 7}, {"^=/.CodeWiz./&=", 7}, {"&=", 7}, {"&=/.CodeWiz./|=", 7}, {"|=", 7}, {"|=/.CodeWiz./&&", 7}, {"&&", 7}, {"&&/.CodeWiz./||", 7}, {"||", 7}, {"||/.CodeWiz./??", 7}, {"??", 7}, {"??/.CodeWiz./&&=", 7}, {"&&=", 7}, {"&&=/.CodeWiz./||=", 7}, {"||=", 7}, {"||=/.CodeWiz./??=", 7}, {"??=", 7}, {"(", 7}, {"(/.CodeWiz./)", 7}, {")", 7}, {")/.CodeWiz./[", 7}, {"[", 7}, {"[/.CodeWiz./]", 7}, {"]", 7}, {"]/.CodeWiz./{", 7}, {"{", 7}, {"{/.CodeWiz./}", 7}, {"}", 7}, {"template_substitution", 7}, {"template_substitution/.CodeWiz./${", 7}, {"${", 7}, {"as", 6}, {"as/.CodeWiz./async", 6}, {"async", 6}, {"async/.CodeWiz./await", 6}, {"await", 6}, {"await/.CodeWiz./break", 6}, {"break", 6}, {"break/.CodeWiz./case", 6}, {"case", 6}, {"case/.CodeWiz./catch", 6}, {"catch", 6}, {"catch/.CodeWiz./class", 6}, {"class", 6}, {"class/.CodeWiz./const", 6}, {"const", 6}, {"const/.CodeWiz./continue", 6}, {"continue", 6}, {"continue/.CodeWiz./debugger", 6}, {"debugger", 6}, {"debugger/.CodeWiz./default", 6}, {"default", 6}, {"default/.CodeWiz./delete", 6}, {"delete", 6}, {"delete/.CodeWiz./do", 6}, {"do", 6}, {"do/.CodeWiz./else", 6}, {"else", 6}, {"else/.CodeWiz./export", 6}, {"export/.CodeWiz./extends", 6}, {"extends", 6}, {"extends/.CodeWiz./finally", 6}, {"finally", 6}, {"finally/.CodeWiz./for", 6}, {"for", 6}, {"for/.CodeWiz./from", 6}, {"from", 6}, {"from/.CodeWiz./function", 6}, {"function", 6}, {"function/.CodeWiz./get", 6}, {"get", 6}, {"get/.CodeWiz./if", 6}, {"if", 6}, {"if/.CodeWiz./import", 6}, {"import", 6}, {"import/.CodeWiz./in", 6}, {"in", 6}, {"in/.CodeWiz./instanceof", 6}, {"instanceof", 6}, {"instanceof/.CodeWiz./let", 6}, {"let", 6}, {"let/.CodeWiz./new", 6}, {"new", 6}, {"new/.CodeWiz./of", 6}, {"of", 6}, {"of/.CodeWiz./return", 6}, {"return", 6}, {"return/.CodeWiz./set", 6}, {"set", 6}, {"set/.CodeWiz./static", 6}, {"static", 6}, {"static/.CodeWiz./switch", 6}, {"switch", 6}, {"switch/.CodeWiz./target", 6}, {"target", 6}, {"target/.CodeWiz./throw", 6}, {"throw", 6}, {"throw/.CodeWiz./try", 6}, {"try", 6}, {"try/.CodeWiz./typeof", 6}, {"typeof", 6}, {"typeof/.CodeWiz./var", 6}, {"var", 6}, {"var/.CodeWiz./void", 6}, {"void", 6}, {"void/.CodeWiz./while", 6}, {"while", 6}, {"while/.CodeWiz./with", 6}, {"with", 6}, {"with/.CodeWiz./yield", 6}, {"yield", 6}};
	colormapCTS = {{"identifier", 3}, {"break", 6}, {"case", 6}, {"const", 6}, {"continue", 6}, {"default", 6}, {"do", 6}, {"else", 6}, {"enum", 6}, {"extern", 6}, {"for", 6}, {"if", 6}, {"inline", 6}, {"return", 6}, {"sizeof", 6}, {"static", 6}, {"struct", 6}, {"switch", 6}, {"typedef", 6}, {"union", 6}, {"volatile", 6}, {"while", 6}, {"#define", 6}, {"#elif", 6}, {"#else", 6}, {"#endif", 6}, {"#if", 6}, {"#ifdef", 6}, {"#ifndef", 6}, {"#include", 6}, {"preproc_directive", 6}, {"--", 7}, {"-", 7}, {"-=", 7}, {"->", 7}, {"=", 7}, {"!=", 7}, {"*", 7}, {"&", 7}, {"&&", 7}, {"+", 7}, {"++", 7}, {"+=", 7}, {"<", 7}, {"==", 7}, {">", 7}, {"||", 7}, {".", 7}, {";", 7}, {"string_literal", 1}, {"system_lib_string", 1}, {"null", 3}, {"number_literal", 8}, {"char_literal", 8}, {"field_identifier", 4}, {"statement_identifier", 4}, {"type_identifier", 4}, {"primitive_type", 4}, {"sized_type_specifier", 4}, {"call_expression", 5}, {"call_expression/.CodeWiz./identifier", 5}, {"call_expression/.CodeWiz./field_expression", 5}, {"field_expression/.CodeWiz./field_identifier", 5}, {"function_declarator", 5}, {"function_declarator/.CodeWiz./identifier", 5}, {"preproc_function_def/.CodeWiz./identifier", 5}, {"comment", 2}};

	extraWordList = {};

	pythonLang.name = "Python";
	pythonLang.strings = QStringList() << "\"" << "\'";
	pythonLang.stringExtensions = QStringList() << "\\" << "\\";
	pythonLang.comments = QStringList() << "#";
	pythonLang.multiLineStringsStart = QStringList() << "\"\"\"" << "\'\'\'";
	pythonLang.multiLineStringsEnd = QStringList() << "\"\"\"" << "\'\'\'";
	pythonLang.multiLineCommentsStart = QStringList();
	pythonLang.multiLineCommentsEnd = QStringList();
	pythonLang.openIndents = QStringList() << ":";
	pythonLang.closeIndentsWords = QStringList() << "break" << "return" << "continue";
	pythonLang.defWordList = defWordListPython;
	pythonLang.fileExtensions = QStringList() << ".py" << ".pyw";

	pythonLang.colorMapTS = colormapPythonTS;

	rustLang.name = "Rust";
	rustLang.strings = QStringList() << "'";
	rustLang.stringExtensions = QStringList() << ""; // Backslash is used for escaping in strings
	rustLang.comments = QStringList() << "//"; // Single-line comments
	rustLang.multiLineStringsStart = QStringList() << "r#\"" << "r##\"" << "r###\"" << "\""; // Raw string literals start
	rustLang.multiLineStringsEnd = QStringList() << "\"#" << "\"##" << "\"###" << "\""; // Raw string literals end
	rustLang.multiLineCommentsStart = QStringList() << "/*"; // Start of block comment
	rustLang.multiLineCommentsEnd = QStringList() << "*/";   // End of block comment
	rustLang.openIndents = QStringList() << "{";
	rustLang.closeIndents = QStringList() << "}";
	rustLang.closeIndentsWords = QStringList();
	rustLang.defWordList = defWordListRust;
	rustLang.fileExtensions = QStringList() << ".rs" << ".toml";

	rustLang.colorMapTS = colormapRustTS;

	WGSLLang.name = "WGSL";
	WGSLLang.strings = QStringList() << "\"";
	WGSLLang.stringExtensions = QStringList() << "\\"; // Backslash for escaping
	WGSLLang.comments = QStringList() << "//"; // Single-line comments
	WGSLLang.multiLineStringsStart = QStringList();
	WGSLLang.multiLineStringsEnd = QStringList();
	WGSLLang.multiLineCommentsStart = QStringList() << "/*"; // Start of block comment
	WGSLLang.multiLineCommentsEnd = QStringList() << "*/";   // End of block comment
	WGSLLang.openIndents = QStringList() << "{";
	WGSLLang.closeIndents = QStringList() << "}";
	WGSLLang.closeIndentsWords = QStringList();
	WGSLLang.defWordList = defWordListWGSL;
	WGSLLang.fileExtensions = QStringList() << ".wgsl";

	WGSLLang.colorMapTS = colormapWGSLTS;

	cppLang.name = "C++";
	cppLang.strings = QStringList() << "\'" << "\"";
	cppLang.stringExtensions = QStringList() << "" << ""; // Backslash for escaping
	cppLang.comments = QStringList() << "//"; // Single-line comments
	cppLang.multiLineStringsStart = QStringList() << "R\"";
	cppLang.multiLineStringsEnd = QStringList() << "\"";
	cppLang.multiLineCommentsStart = QStringList() << "/*"; // Start of block comment
	cppLang.multiLineCommentsEnd = QStringList() << "*/";   // End of block comment
	cppLang.openIndents = QStringList() << "{";
	cppLang.closeIndents = QStringList() << "}";
	cppLang.closeIndentsWords = QStringList();
	cppLang.defWordList = defWordListCpp;
	cppLang.fileExtensions = QStringList() << ".cpp" << ".h";

	cppLang.colorMapTS = colormapCppTS;

	txtLang.name = "Txt";
	txtLang.fileExtensions = QStringList() << ".txt";
	txtLang.defWordList = defWordListTxt;

	jsLang.name = "JS";
	jsLang.strings = QStringList() << "\"" << "\'";
	jsLang.stringExtensions = QStringList() << "\\" << "\\";
	jsLang.comments = QStringList() << "//";
	jsLang.multiLineStringsStart = QStringList() << "`";
	jsLang.multiLineStringsEnd = QStringList() << "`";
	jsLang.multiLineCommentsStart = QStringList() << "/*" << "/**";
	jsLang.multiLineCommentsEnd = QStringList() << "*/" << "*/";
	jsLang.openIndents = QStringList() << "{";
	jsLang.closeIndents = QStringList() << "}";
	jsLang.closeIndentsWords = QStringList();
	jsLang.defWordList = defWordListJs;
	jsLang.fileExtensions = QStringList() << ".js";

	jsLang.colorMapTS = colormapJsTS;

	HTMLLang.name = "HTML";
	HTMLLang.strings = QStringList() << "\"" << "\'"; // Attribute values use double quotes
	HTMLLang.stringExtensions = QStringList() << "" << ""; // Entities start with an ampersand
	HTMLLang.comments = QStringList() << "//"; // HTML comment start
	HTMLLang.multiLineStringsStart = QStringList(); // HTML does not support multiline strings
	HTMLLang.multiLineStringsEnd = QStringList();   // No multiline strings in HTML
	HTMLLang.multiLineCommentsStart = QStringList() << "<!--" << "/*"; // Start of HTML comment
	HTMLLang.multiLineCommentsEnd = QStringList() << "-->" << "*/";   // End of HTML comment
	HTMLLang.openIndents = QStringList() << "{";
	HTMLLang.closeIndents = QStringList() << "}";
	HTMLLang.closeIndentsWords = QStringList();
	HTMLLang.defWordList = defWordListHTML;
	HTMLLang.fileExtensions = QStringList() << ".html";

	HTMLLang.colorMapTS = colormapHTMLTS;

	goLang.name = "Go";
	goLang.strings = QStringList() << "\"" << "'";
	goLang.stringExtensions =  QStringList() << "" << "";
	goLang.comments = QStringList() << "//";
	goLang.multiLineStringsStart = QStringList() << "`";
	goLang.multiLineStringsEnd = QStringList() << "`";
	goLang.multiLineCommentsStart = QStringList() << "/*";
	goLang.multiLineCommentsEnd = QStringList() << "*/";
	goLang.openIndents = QStringList() << "{";
	goLang.closeIndents = QStringList() << "}";
	goLang.closeIndentsWords = QStringList();
	goLang.defWordList = defWordListGo;
	goLang.fileExtensions = QStringList() << ".go" << ".mod";

	goLang.colorMapTS = colormapGoTS;

	luaLang.name = "Lua";
	luaLang.strings = QStringList() << "\"" << "'";
	luaLang.stringExtensions =  QStringList() << "" << "";
	luaLang.comments = QStringList() << "--";
	luaLang.multiLineStringsStart = QStringList() << "[[";
	luaLang.multiLineStringsEnd = QStringList() << "]]";
	luaLang.multiLineCommentsStart = QStringList() << "--[[" << "--[[";
	luaLang.multiLineCommentsEnd = QStringList() << "--]]" << "]]--";
	luaLang.openIndents = QStringList() << "{";
	luaLang.closeIndents = QStringList() << "}";
	luaLang.closeIndentsWords = QStringList();
	luaLang.defWordList = defWordListLua;
	luaLang.fileExtensions = QStringList() << ".lua" << ".rockspec";

	luaLang.colorMapTS = colormapLuaTS;

	csharpLang.name = "C#";
	csharpLang.strings = QStringList() << "\'" << "\"";
	csharpLang.stringExtensions = QStringList() << "" << ""; // Backslash for escaping
	csharpLang.comments = QStringList() << "//"; // Single-line comments
	csharpLang.multiLineStringsStart = QStringList() << "@\"";
	csharpLang.multiLineStringsEnd = QStringList() << "\"";
	csharpLang.multiLineCommentsStart = QStringList() << "/*"; // Start of block comment
	csharpLang.multiLineCommentsEnd = QStringList() << "*/";   // End of block comment
	csharpLang.openIndents = QStringList() << "{";
	csharpLang.closeIndents = QStringList() << "}";
	csharpLang.closeIndentsWords = QStringList();
	csharpLang.defWordList = defWordListCsharp;
	csharpLang.fileExtensions = QStringList() << ".cs" << ".csproj";

	csharpLang.colorMapTS = colormapCsharpTS;

	GLSLLang.name = "GLSL";
	GLSLLang.strings = QStringList() << "\"";
	GLSLLang.stringExtensions = QStringList() << "\\"; // Backslash for escaping
	GLSLLang.comments = QStringList() << "//"; // Single-line comments
	GLSLLang.multiLineStringsStart = QStringList();
	GLSLLang.multiLineStringsEnd = QStringList();
	GLSLLang.multiLineCommentsStart = QStringList() << "/*"; // Start of block comment
	GLSLLang.multiLineCommentsEnd = QStringList() << "*/";   // End of block comment
	GLSLLang.openIndents = QStringList() << "{";
	GLSLLang.closeIndents = QStringList() << "}";
	GLSLLang.closeIndentsWords = QStringList();
	GLSLLang.defWordList = defWordListGLSL;
	GLSLLang.fileExtensions = QStringList() << ".glsl";

	GLSLLang.colorMapTS = colormapGLSLTS;

	javaLang.name = "Java";
	javaLang.strings = QStringList() << "\"" << "\'";
	javaLang.stringExtensions = QStringList() << "" << ""; // Backslash for escaping
	javaLang.comments = QStringList() << "//"; // Single-line comments
	javaLang.multiLineStringsStart = QStringList() << "\"\"\"";
	javaLang.multiLineStringsEnd = QStringList() << "\"\"\"";
	javaLang.multiLineCommentsStart = QStringList() << "/*"; // Start of block comment
	javaLang.multiLineCommentsEnd = QStringList() << "*/";   // End of block comment
	javaLang.openIndents = QStringList() << "{";
	javaLang.closeIndents = QStringList() << "}";
	javaLang.closeIndentsWords = QStringList();
	javaLang.defWordList = defWordListJava;
	javaLang.fileExtensions = QStringList() << ".java" << ".xml";
	javaLang.colorMapTS = colormapJavaTS;

	tsLang.name = "TS";
	tsLang.strings = QStringList() << "\"" << "\'";
	tsLang.stringExtensions = QStringList() << "\\" << "\\";
	tsLang.comments = QStringList() << "//";
	tsLang.multiLineStringsStart = QStringList() << "`";
	tsLang.multiLineStringsEnd = QStringList() << "`";
	tsLang.multiLineCommentsStart = QStringList() << "/*" << "/**";
	tsLang.multiLineCommentsEnd = QStringList() << "*/" << "*/";
	tsLang.openIndents = QStringList() << "{";
	tsLang.closeIndents = QStringList() << "}";
	tsLang.closeIndentsWords = QStringList();
	tsLang.defWordList = defWordListTs;
	tsLang.fileExtensions = QStringList() << ".ts" << ".json";
	tsLang.colorMapTS = colormapTsTS;

	cLang.name = "C";
	cLang.strings = QStringList() << "\'" << "\"";
	cLang.stringExtensions = QStringList() << "" << ""; // Backslash for escaping
	cLang.comments = QStringList() << "//"; // Single-line comments
	cLang.multiLineStringsStart = QStringList(); // C does not have raw strings like C++
	cLang.multiLineStringsEnd = QStringList();
	cLang.multiLineCommentsStart = QStringList() << "/*"; // Start of block comment
	cLang.multiLineCommentsEnd = QStringList() << "*/";   // End of block comment
	cLang.openIndents = QStringList() << "{";
	cLang.closeIndents = QStringList() << "}";
	cLang.closeIndentsWords = QStringList();
	cLang.defWordList = defWordListC; // Replace with C-specific keywords
	cLang.fileExtensions = QStringList() << ".c";
	cLang.colorMapTS = colormapCTS;

	supportedLangs = {pythonLang, rustLang, WGSLLang, cppLang, txtLang, jsLang, HTMLLang, goLang, luaLang, csharpLang, GLSLLang, javaLang, tsLang, cLang};

	for (int i = 0; i < supportedLangs.count(); i ++){
		supportedLangs[i].index = i;
	}

	currentLang = pythonLang;

	updateDefaultWordLists();

	QTextCharFormat codeWizForm;
	QColor codeWizCol = QColor(136, 67, 240);
	codeWizForm.setForeground(codeWizCol);

	setupSyntaxTreeOnOpen("");

	lineNumberTextEdit->setReadOnly(true);
	lineNumberTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	lineNumberTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn); // So that it can't get out of sync w/ main textedit
	lineNumberTextEdit->setAlignment(Qt::AlignRight);

	textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

	findTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	replaceTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	lineEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	terminalInputLine->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	terminalInputLineHORZ->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	connect(textEdit->verticalScrollBar(), &QScrollBar::valueChanged,
			this, &MainWindow::updateScrollBarValue);

	connect(lineNumberTextEdit->verticalScrollBar(), &QScrollBar::valueChanged,
			this, &MainWindow::updateScrollBarValue2);

	textEdit->installEventFilter(this);
	findTextEdit->installEventFilter(this);
	replaceTextEdit->installEventFilter(this);
	builtinTerminalTextEdit->installEventFilter(this);
	builtinTerminalTextEditHORZ->installEventFilter(this);
	terminalInputLine->installEventFilter(this);
	terminalInputLineHORZ->installEventFilter(this);
	this->installEventFilter(this); // for the fullscreen

	darkmode = thm;
	changeOnlyEditsTheme(thm);

	lineEdit->setPlainText(pythonTag);

	QSettings settings("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize", QSettings::NativeFormat);
	bool settingsThm = settings.value("AppsUseLightTheme").toInt() == 0;

	connect(ui->actionExit, &QAction::triggered, this, &MainWindow::on_actionExit_triggered);

	connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::findTriggered);
	connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::nextTriggered);
	connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::replaceTriggered);
	connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::replaceAllTriggered);

	connect(textEdit, &QTextEdit::textChanged, this, &MainWindow::updateSyntax);
	connect(findTextEdit, &QTextEdit::textChanged, this, &MainWindow::findTextEditChanged);

	connect(lineEdit, &QTextEdit::textChanged, this, &MainWindow::saveWantedTheme);

	if (QOperatingSystemVersion::currentType() == QOperatingSystemVersion::Windows) {
		#ifdef _WIN32
			if (QOperatingSystemVersion::current() >= QOperatingSystemVersion::Windows11) {
				windowsVersion = 11;
			}else{
				windowsVersion = 10;
			}
		#endif
	}

	qDebug() << "Windows version: " << windowsVersion;

	hoverBox->setFont(textEdit->font());
	hoverBox->setFocusPolicy(Qt::NoFocus);
	hoverBox->setWordWrapMode(QTextOption::NoWrap);
	hoverBox->hide();
	actionBox->setFocusPolicy(Qt::NoFocus);
	actionBox->hide();
	suggestionBox->setFocusPolicy(Qt::NoFocus);
	suggestionBox->hide();

	changeTheme(thm);
	changeHighlightColors(thm);

	MainWindow::setupCompleter();

	updateFonts();
	updateFontSelection();

	lineNumberTextEdit->setUndoRedoEnabled(false);
	treeParserSyntaxHighlighter.setFormats(coloredFormats);
	treeParserSyntaxHighlighter.setLanguage(currentLang.name);

	connect(suggestionBox, &QListWidget::itemClicked, this, &MainWindow::onSuggestionItemClicked);
	connect(actionBox, &QListWidget::itemClicked, this, &MainWindow::onActionsItemClicked);

	connect(textEdit, &MyTextEdit::mousePositionChanged, this, &MainWindow::handleMouseMoved);
	connect(textEdit, &MyTextEdit::gotoDefinitionActionTriggered, this, &MainWindow::gotoDefinitionActionTriggered);
	connect(textEdit, &MyTextEdit::mouseClicked, this, &MainWindow::mouseClicked);
	connect(textEdit, &MyTextEdit::mouseReleased, this, &MainWindow::mouseReleased);
	connect(textEdit, &MyTextEdit::handleSizeChange, this, &MainWindow::updateMargins);
	connect(textDocument, &QTextDocument::contentsChange, this, &MainWindow::onContentsChange);

	connect(showWarnings, &QAction::toggled, this, &MainWindow::saveWantedTheme); // down here because they will call saveWantedTheme when being set otherwise
	connect(showErrors, &QAction::toggled, this, &MainWindow::saveWantedTheme);
	connect(showOther, &QAction::toggled, this, &MainWindow::saveWantedTheme);
	connect(onlyCodeWizardBuiltIn, &QAction::toggled, this, &MainWindow::saveWantedTheme);
	connect(noAutocomplete, &QAction::toggled, this, &MainWindow::saveWantedTheme);
	connect(hoverAction, &QAction::toggled, this, &MainWindow::saveWantedTheme);
	connect(useVimMode, &QAction::toggled, this, &MainWindow::useVimModesTriggered);
	connect(useBuiltinTerminal, &QAction::toggled, this, &MainWindow::useBuiltinTerminalTriggered);
	connect(preferHorizontalTerminal, &QAction::toggled, this, &MainWindow::switchTerminalType);
	connect(autoAddBrackets, &QAction::toggled, this, &MainWindow::saveWantedTheme);
	connect(autoSaveAct, &QAction::toggled, this, &MainWindow::saveWantedTheme);
	connect(randomSelectFileTypeAct, &QAction::toggled, this, &MainWindow::saveWantedTheme);
	connect(useSpeakerAction, &QAction::toggled, this, &MainWindow::saveWantedTheme);
	connect(useFileTree, &QAction::toggled, this, &MainWindow::fileTreeToggled);
	connect(useFileTreeIfFullscreen, &QAction::toggled, this, &MainWindow::fileTreeToggled);
	connect(splitter, &QSplitter::splitterMoved, this, &MainWindow::storeResizeOfSplitters);
	connect(splitter2, &QSplitter::splitterMoved, this, &MainWindow::storeResizeOfSplitters);

	connect(fileTree, &QTreeView::doubleClicked, this, &MainWindow::fileTreeOpened);

	connect(groq, &GroqAI::responseReceived, this, [this](const QString &response) {
		QTextCursor c = textEdit->textCursor();
		c.insertText(changeToTabs(response));
		textEdit->setTextCursor(c);
	});

	updateLineNumbers(1);

	//autosave

	QTimer* autoSaveTimer = new QTimer(this);
	connect(autoSaveTimer, &QTimer::timeout, this, &MainWindow::autoSave);
	autoSaveTimer->start(10000);

	// filetree

	fileTree->setContextMenuPolicy(Qt::CustomContextMenu);

	// Connect the custom context menu signal
	connect(fileTree, &QTreeView::customContextMenuRequested, this, &MainWindow::openFileTreeContextMenu);

	QAction* openInExplorerAction = new QAction("Open in Explorer", this);
	QAction* copyPathAction = new QAction("Copy Path", this);
	QAction* openOutsideAction = new QAction("Open Outside of CodeWizard", this);

	fileTreeContextMenu->addAction(openInExplorerAction);
	fileTreeContextMenu->addAction(copyPathAction);
	fileTreeContextMenu->addAction(openOutsideAction);

	connect(openInExplorerAction, &QAction::triggered, this, &MainWindow::onOpenInExplorer);
	connect(copyPathAction, &QAction::triggered, this, &MainWindow::onCopyPath);
	connect(openOutsideAction, &QAction::triggered, this, &MainWindow::onOpenOutside);

	fileModel = new QFileSystemModel;

	QSettings foundationSettings("FoundationTechnologies", "CodeWizard");
	QString mostRecentPath = foundationSettings.value("mostRecentFolder", "").toString();

	fileModel->setRootPath(mostRecentPath);
	fileTree->setModel(fileModel);
	fileTree->setRootIndex(fileModel->index(fileModel->rootPath()));
	fileTree->hideColumn(1);    // Hide column at index 1 (Size)
	fileTree->hideColumn(2);    // Hide column at index 2 (Type)
	fileTree->hideColumn(3);    // Hide column at index 3 (I don't remember)

	fileTree->header()->hide(); // Remove the 'Name' bar at top

	if (useFileTree->isChecked() && mostRecentPath != ""){
		fileTree->show();
	}else{
		fileTree->hide();
	}

	if (foundationSettings.value("wasFullScreened", false).toBool()){
		setWindowState(Qt::WindowMaximized);
	}

	#ifdef _WIN32
		speech = new QTextToSpeech(this);
		QList<QVoice> voices = speech->availableVoices();

		for (const QVoice &voice : voices) {
			if (voice.gender() == QVoice::Male) {
				speech->setVoice(voice);
				break;
			}
		}
	#endif

	recordingLight = new RecordingLight(textEdit);
	recordingLight->hide();

	updateMargins(false);

	//MUST BE ON END - why?

	textEdit->setFocus();

	if (!argFileName.isEmpty()){
		globalArgFileName = argFileName;
		on_actionOpen_triggered();
	}

	QTimer::singleShot(50, this, &MainWindow::updateSplitsWidths);
}

void MainWindow::updateSplitsWidths(){
	qDebug() << "updateSplitsWidths";

	int totalWidth = splitter->width();
	int totalHeight = splitter2->height();

	if (totalWidth == 0 || totalHeight == 0){
		QTimer::singleShot(50, this, &MainWindow::updateSplitsWidths); //reschedule it just in case
		return;
	}

	int ftW = totalWidth*splitWidths[0];
	int btW = totalWidth*splitWidths[1];
	int btH = totalHeight*splitWidths[2];
	int teW = totalWidth-ftW-btW;
	int teH = totalHeight-btH;

	QList<int> sizes;

	sizes.push_back(ftW);
	sizes.push_back(teW);

	if (!(useFileTree->isChecked() || useFileTreeIfFullscreen->isChecked() && (isFullScreen() || isMaximized()))){
		teW += ftW;
		sizes[1] += ftW;
	}

	if (useBuiltinTerminal->isChecked() && !preferHorizontalTerminal->isChecked()){
		sizes.push_back(btW);
	}else{
		teW += btW;
		sizes[1] += btW;
	}

	splitter->setSizes(sizes);
	sizes.clear();
	sizes.push_back(teH);

	if (useBuiltinTerminal->isChecked() && preferHorizontalTerminal->isChecked()){
		sizes.push_back(btH);
		splitter2->setSizes(sizes);
	}
}

void MainWindow::storeResizeOfSplitters(){
	qDebug() << "storeResizeOfSplitters";

	auto s1 = splitter->sizes();
	auto s2 = splitter2->sizes();

	int totalWidth = 0;
	for (int i = 0; i < s1.length(); i++){
		totalWidth += s1[i];
	}

	int totalHeight = 0;
	for (int i = 0; i < s2.length(); i++){
		totalHeight += s2[i];
	}

	if (totalWidth == 0 || totalHeight == 0){return;}

	splitWidths[0] = (float)fileTree->width()/(float)totalWidth;
	splitWidths[1] = (float)builtinTerminalTextEdit->width()/(float)totalWidth;
	splitWidths[2] = (float)builtinTerminalTextEditHORZ->height()/(float)totalHeight;

	saveWantedTheme();
}

void MainWindow::moveWidgetsToSplitter(QLayout *layout, QWidget *toWidget) {
	if (!layout) return;

	// Iterate over all layout items
	while (!layout->isEmpty()) {
		QLayoutItem *item = layout->takeAt(0);

		if (!item) continue;

		if (QWidget *widget = item->widget()) {
			layout->removeWidget(widget);
			toWidget->layout()->addWidget(widget);

			if (widget->layout()){
				widget->layout()->setSpacing(0);
				widget->layout()->setContentsMargins(0, 0, 0, 0);
			}
		}
		else if (QLayout *nestedLayout = item->layout()) {
			// If it's a nested layout, create a new container widget for the layout
			QWidget *container = new QWidget(toWidget);
			QLayout *containerLayout = nullptr;

			if (QVBoxLayout *vLayout = qobject_cast<QVBoxLayout *>(nestedLayout)) {
				containerLayout = new QVBoxLayout(container);
			} else if (QHBoxLayout *hLayout = qobject_cast<QHBoxLayout *>(nestedLayout)) {
				containerLayout = new QHBoxLayout(container);
			} else if (QFormLayout *fLayout = qobject_cast<QFormLayout *>(nestedLayout)) {
				containerLayout = new QFormLayout(container);
			} // Add more layout types as needed

			if (!containerLayout){
				continue;
			}

			containerLayout->setSpacing(0);
			containerLayout->setContentsMargins(0, 0, 0, 0);

			container->setLayout(containerLayout);
			moveWidgetsToSplitter(nestedLayout, container);  // Handle nested layout
			toWidget->layout()->addWidget(container);
		}

		// Cleanup memory for the layout item (but not the widget since it's moved)
		delete item;
	}
}

void MainWindow::changeEvent(QEvent *event) {
	if (event->type() == QEvent::ActivationChange) {
		if (this->isActiveWindow()) {
			qDebug() << "returnedToCodeWizard";

			if (handlingReopen){
				return;
			}

			handlingReopen = true;

			if (fileName.isEmpty()){
				handlingReopen = false;
				return;
			}

			QFileInfo fileInfo(fileName);
			QFile file(fileName);
			if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
				handlingReopen = false;
				return;
			}

			QTextStream in(&file);
			QString fileContent = in.readAll();

			if (fileContent != toCompareTo && toCompareTo != "NOCOMPARISONYET_CODEWIZARD_WARNING - <THEENDISNIGH>"){
				if (useSpeakerAction->isChecked()){
					#ifdef _WIN32
						speech->say("Detected change in file, reload?");
					#endif
				}
				pullUpReloadDialogue("Detected change in file, reload?");
			}

			handlingReopen = false;
		}else{
			qDebug() << "leftCodeWizard";
			if (fileName.isEmpty()){
				handlingReopen = false;
				return;
			}

			QFileInfo fileInfo(fileName);
			QFile file(fileName);
			if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
				handlingReopen = false;
				return;
			}

			QTextStream in(&file);
			toCompareTo = in.readAll();
		}
	}
	QMainWindow::changeEvent(event);
}

void MainWindow::pullUpReloadDialogue(QString message){
	QMessageBox dialog;
	dialog.setWindowTitle("Reload");
	dialog.setText(message);
	dialog.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	dialog.setDefaultButton(QMessageBox::Yes);
	dialog.setFont(textEdit->font());

	int response = dialog.exec();
	if (response == QMessageBox::Yes) {
		globalArgFileName = fileName;
		on_actionOpen_triggered();
	}
}

void MainWindow::handleTerminalStdout(){
	QByteArray output = activeTerminal->readAll();

	QString text = QString::fromLocal8Bit(output);

	builtinTerminalTextEdit->moveCursor(QTextCursor::End);
	builtinTerminalTextEdit->insertPlainText(text);
	builtinTerminalTextEdit->verticalScrollBar()->setValue(builtinTerminalTextEdit->verticalScrollBar()->maximum());

	builtinTerminalTextEditHORZ->moveCursor(QTextCursor::End);
	builtinTerminalTextEditHORZ->insertPlainText(text);
	builtinTerminalTextEditHORZ->verticalScrollBar()->setValue(builtinTerminalTextEditHORZ->verticalScrollBar()->maximum());
}

void MainWindow::useVimModesTriggered(){
	qDebug() << "useVimModesTriggered";

	if (!useVimMode->isChecked()){
		currentVimMode = "i";
		textEdit->setCursorWidth(1);
	}else{
		currentVimMode = "n";
		QFontMetrics metrics(textEdit->font());
		int charWidth = metrics.horizontalAdvance("M");
		textEdit->setCursorWidth(charWidth);
	}

	vimRepeater = 0;
	saveWantedTheme();
}

void MainWindow::switchTerminalType(){
	qDebug() << "switchTerminalType";
	useBuiltinTerminalTriggered(); // does the same thing.
}

void MainWindow::updateTermimalViews(){
	qDebug() << "updateTermimalViews";
	if (useBuiltinTerminal->isChecked()){
		if (preferHorizontalTerminal->isChecked()){
			builtinTerminalTextEditHORZ->show();
			terminalInputLineHORZ->show();
			builtinTerminalTextEdit->hide();
			terminalInputLine->hide();

			builtinTerminalTextEdit->parentWidget()->setParent(nullptr);
			builtinTerminalTextEditHORZ->parentWidget()->setParent(nullptr);

			splitter2->addWidget(builtinTerminalTextEditHORZ->parentWidget());
		}else{
			builtinTerminalTextEditHORZ->hide();
			terminalInputLineHORZ->hide();
			builtinTerminalTextEdit->show();
			terminalInputLine->show();

			builtinTerminalTextEdit->parentWidget()->setParent(nullptr);
			builtinTerminalTextEditHORZ->parentWidget()->setParent(nullptr);

			splitter->addWidget(builtinTerminalTextEdit->parentWidget());
		}
	}else{
		builtinTerminalTextEdit->hide();
		builtinTerminalTextEditHORZ->hide();
		terminalInputLine->hide();
		terminalInputLineHORZ->hide();

		builtinTerminalTextEdit->parentWidget()->setParent(nullptr);
		builtinTerminalTextEditHORZ->parentWidget()->setParent(nullptr);
	}

	updateSplitsWidths();

	//ensure all are non-collapsible

	for (int i = 0; i < splitter->count(); ++i) {
		splitter->setCollapsible(i, false);
	}
	for (int i = 0; i < splitter2->count(); ++i) {
		splitter2->setCollapsible(i, false);
	}
}

void MainWindow::useBuiltinTerminalTriggered(){
	qDebug() << "useBuiltinTerminalTriggered";

	updateTermimalViews();
	saveWantedTheme();
}

void MainWindow::on_actionDiscard_Local_Changes_triggered(){
	qDebug() << "on_actionDiscard_Local_Changes_triggered";

	QModelIndex index = fileTree->rootIndex();
	if (!index.isValid()){
		openHelpMenu("Base folder not set.");
		return;
	}

	QString filePath = fileModel->filePath(index);
	QString tmpDirPath = QStandardPaths::writableLocation(QStandardPaths::TempLocation) + "/CodeWizard";

	QDir tmpDir(tmpDirPath);
	if (!tmpDir.exists()) {
		tmpDir.mkpath(tmpDirPath);
	}

	#ifdef _WIN32
		QString scriptFilePath = tmpDirPath + "/run_script.bat";
		QFile scriptFile(scriptFilePath);
		if (scriptFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
			QTextStream out(&scriptFile);
			out << "cd /d \"" + filePath + "\" && git reset --hard && git pull";
		}
		scriptFile.close();

		QStringList arguments;
		arguments << "/c" << "start" << "cmd" << "/k" << scriptFilePath;

		QProcess *process = new QProcess(this);
		process->startDetached("cmd.exe", arguments);
	#else
		QString scriptFilePath = tmpDirPath + "/run_script.sh";
		QFile scriptFile(scriptFilePath);
		if (scriptFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
			QTextStream out(&scriptFile);
			out << "#!bash\n";
			out << "cd \"" + filePath + "\" && git reset --hard && git pull";
		}
		scriptFile.close();

		QFile::setPermissions(scriptFilePath, QFile::Permissions(QFile::ExeUser | QFile::ReadUser | QFile::WriteUser));
		QProcess *process = new QProcess(this);
		process->startDetached("bash", QStringList() << "-c" << scriptFilePath);
	#endif
}

void MainWindow::on_actionRegular_triggered(){
	qDebug() << "on_actionRegular_triggered";

	QModelIndex index = fileTree->rootIndex();
	if (!index.isValid()){
		openHelpMenu("Base folder not set.");
		return;
	}

	QString filePath = fileModel->filePath(index);
	QString tmpDirPath = QStandardPaths::writableLocation(QStandardPaths::TempLocation) + "/CodeWizard";

	QDir tmpDir(tmpDirPath);
	if (!tmpDir.exists()) {
		tmpDir.mkpath(tmpDirPath);
	}

	#ifdef _WIN32
		QString scriptFilePath = tmpDirPath + "/run_script.bat";
		QFile scriptFile(scriptFilePath);
		if (scriptFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
			QTextStream out(&scriptFile);
			out << "cd /d \"" + filePath + "\" && git pull";
		}
		scriptFile.close();

		QStringList arguments;
		arguments << "/c" << "start" << "cmd" << "/k" << scriptFilePath;

		QProcess *process = new QProcess(this);
		process->startDetached("cmd.exe", arguments);
	#else
		QString scriptFilePath = tmpDirPath + "/run_script.sh";
		QFile scriptFile(scriptFilePath);
		if (scriptFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
			QTextStream out(&scriptFile);
			out << "#!bash\n";
			out << "cd \"" + filePath + "\" && git pull";
		}
		scriptFile.close();

		QFile::setPermissions(scriptFilePath, QFile::Permissions(QFile::ExeUser | QFile::ReadUser | QFile::WriteUser));
		QProcess *process = new QProcess(this);
		process->startDetached("bash", QStringList() << "-c" << scriptFilePath);
	#endif
}

void MainWindow::on_actionPush_triggered(){
	qDebug() << "on_actionPush_triggered";

	QModelIndex index = fileTree->rootIndex();
	if (!index.isValid()){
		openHelpMenu("Base folder not set.");
		return;
	}

	QString filePath = fileModel->filePath(index);

	QInputDialog dialog;
	dialog.setFont(textEdit->font());
	dialog.setWindowTitle("Git");
	dialog.setLabelText("Commit message?");

	dialog.exec();

	QString commitmessage = "";

	if (dialog.result() == QDialog::Accepted) {
		commitmessage = dialog.textValue();
	} else {
		return;
	}

	QString tmpDirPath = QStandardPaths::writableLocation(QStandardPaths::TempLocation) + "/CodeWizard";

	QDir tmpDir(tmpDirPath);
	if (!tmpDir.exists()) {
		tmpDir.mkpath(tmpDirPath);
	}

	#ifdef _WIN32
		QString scriptFilePath = tmpDirPath + "/run_script.bat";
		QFile scriptFile(scriptFilePath);
		if (scriptFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
			QTextStream out(&scriptFile);
			out << "cd /d \"" + filePath + "\" && git add --all && git commit -m \"" + commitmessage + "\" && git push";
		}
		scriptFile.close();

		QStringList arguments;
		arguments << "/c" << "start" << "cmd" << "/k" << scriptFilePath;

		QProcess *process = new QProcess(this);
		process->startDetached("cmd.exe", arguments);
	#else
		QString scriptFilePath = tmpDirPath + "/run_script.sh";
		QFile scriptFile(scriptFilePath);
		if (scriptFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
			QTextStream out(&scriptFile);
			out << "#!bash\n";
			out << "cd \"" + filePath + "\" && git add --all && git commit -m \"" + commitmessage + "\" && git push";
		}
		scriptFile.close();

		QFile::setPermissions(scriptFilePath, QFile::Permissions(QFile::ExeUser | QFile::ReadUser | QFile::WriteUser));
		QProcess *process = new QProcess(this);
		process->startDetached("bash", QStringList() << "-c" << scriptFilePath);
	#endif
}

void MainWindow::on_actionCompare_2_Files_triggered(){
	qDebug() << "on_actionCompare_2_Files_triggered";
	if (isSettingUpLSP){
		showWeDontFuckWithTheLSP();
		return;
	}

	if (isOpeningFile){
		showHoldYourHorses();
		return;
	}

	if (unsaved && fileName != ""){
		pullUpSaveDialogue();
	}

	QString newFile = QFileDialog::getOpenFileName(this, tr("Open File"), fileName, tr("All Files (*);"));

	QFileInfo fileInfo(newFile);
	QFile file(newFile);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		QMessageBox newWarningBox;
		newWarningBox.setIcon(QMessageBox::Warning);
		newWarningBox.setText(tr("Cannot open file: %1").arg(file.errorString()));
		newWarningBox.setWindowTitle(tr("Error"));
		newWarningBox.setFont(textEdit->font());
		newWarningBox.exec();
		isOpeningFile = false;
		return;
	}

	fileName = "";

	isOpeningFile = true;

	QTextStream in(&file);
	QString fileContent = in.readAll();

	QString newFile2 = QFileDialog::getOpenFileName(this, tr("Open File"), fileName, tr("All Files (*);"));

	QFileInfo fileInfo2(newFile2);
	QFile file2(newFile2);
	if (!file2.open(QIODevice::ReadOnly | QIODevice::Text)) {
		QMessageBox newWarningBox;
		newWarningBox.setIcon(QMessageBox::Warning);
		newWarningBox.setText(tr("Cannot open file: %1").arg(file2.errorString()));
		newWarningBox.setWindowTitle(tr("Error"));
		newWarningBox.setFont(textEdit->font());
		newWarningBox.exec();
		isOpeningFile = false;
		return;
	}

	setLangOffFilename(newFile, false);

	QTextStream in2(&file2);
	QString fileContent2 = in2.readAll();

	auto differences = diffAlgo->getDiff(fileContent, fileContent2);

	QStringList fileContentLst;

	for (int i = 0; i < differences.length(); i++){
		fileContentLst << differences[i][1];
	}

	fileContent = fileContentLst.join("\n");
	windowName = "CodeWizard V"+versionNumber+" - Comparison";

	previousLineCount = 1;
	savedText = fileContent;

	setupSyntaxTreeOnOpen(fileContent); // must be before setPlainText - don't ask why - I could tell you though...

	highlightDiagnostics(true);

	textEdit->setPlainText(fileContent);
	toCompareTo = fileContent;
	previousLineCount = fileContent.count('\xa')+1;
	file.close();

	int cnt = fileContent.count('\n') + 1;
	updateLineNumbers(cnt);
	QString linesText = lineNumberTextEdit->toPlainText();
	QStringList linesList = linesText.split("\n");

	for (int i = 0; i < differences.length(); i++){
		linesList[i] += " " + differences[i][0];
	}

	lineNumberTextEdit->setPlainText(linesList.join("\n"));

	QFontMetrics metrics(textEdit->font());

	int charCount = QString::number(globalLineCount).length()+2;
	int width = metrics.horizontalAdvance('M') * charCount+15;

	lineNumberTextEdit->setMinimumWidth(width);
	lineNumberTextEdit->setMaximumWidth(width);
	lineNumberTextEdit->setFixedWidth(width);

	updateExtraWordsList();

	setWindowTitle(windowName);

	rehighlightFullDoc();
	highlightComparisons();
	updateMargins(true);

	isOpeningFile = false;
}

QString MainWindow::changeToTabs(QString text){
	QStringList lines = text.split("\n");
	QStringList newLines;

	for (QString line : lines){
		int seen = 0;
		QString rest = "";
		bool doneSeen = false;

		for (QChar c : line){
			if (c == ' ' && !doneSeen){
				seen ++;
			}else{
				doneSeen = true;
				rest += c;
			}
		}

		int tabs = seen/4;
		int spaces = seen%4;

		QString outLine = "";

		for (int i = 0; i < tabs; i++){
			outLine += "	";
		}

		for (int i = 0; i < spaces; i++){
			outLine += " ";
		}

		outLine += rest;

		newLines.push_back(outLine);
	}

	return newLines.join("\n");
}

void MainWindow::updateMargins(bool force) {
	qDebug() << "updateMargins - " << force;

	errMenu.reposition();

	QFontMetrics metrics(textEdit->font());

	marginBottomSize = textEdit->height()-metrics.height()*2;
	if (marginBottomSize < 0){
		marginBottomSize = 0;
	}

	if (textDocument->blockCount() < 200 || force){ // I do this for performance issues with opening and closing the find menu/resizing menu. It resets the ENTIRE html
		auto format = textDocument->rootFrame()->frameFormat();
		format.setBottomMargin(marginBottomSize);
		textDocument->rootFrame()->setFrameFormat(format);
	}
}

void MainWindow::on_actionSet_Syntax_Colors_triggered() {
	qDebug() << "on_actionSet_Syntax_Colors_triggered";

	QDialog diag = QDialog(this);
	QVBoxLayout *layout = new QVBoxLayout(this);
	hexColorsList = QList<QLineEdit*>();

	// Create 8 QLineEdit widgets for hex strings

	QList<QString> labelText = {"String Hex:", "Comment Hex:", "Variable Hex:", "Types Hex:", "Function Hex:", "Keywords Hex:", "Character Hex:", "Literal Hex:"};

	for (int i = 0; i < 8; ++i) {
		QLabel *label = new QLabel(this);
		label->setText(labelText[i]);
		layout->addWidget(label);
		label->setFont(textEdit->font());

		QLineEdit *lineEdit = new QLineEdit(this);
		lineEdit->setPlaceholderText("Enter hex code (e.g., #RRGGBB)");
		lineEdit->setFont(textEdit->font());

		if (coloredFormats.length() > i+1){
			lineEdit->setText(coloredFormats[i+1].foreground().color().name());
		}

		hexColorsList.push_back(lineEdit);

		layout->addWidget(lineEdit);
	}

	// Create a QPushButton
	QPushButton *validateButton = new QPushButton("Validate and Convert", this);
	validateButton->setFont(textEdit->font());

	QPushButton *imageButton = new QPushButton("Color off image (;", this);
	imageButton->setFont(textEdit->font());

	QPushButton *resetButton = new QPushButton("Reset to default", this);
	resetButton->setFont(textEdit->font());

	QPushButton *saveToFileButton = new QPushButton("Save To File", this);
	saveToFileButton->setFont(textEdit->font());

	QPushButton *loadFromFileButton = new QPushButton("Load From File", this);
	loadFromFileButton->setFont(textEdit->font());

	connect(validateButton, &QPushButton::clicked, this, &MainWindow::validateAndConvert);
	connect(resetButton, &QPushButton::clicked, this, &MainWindow::resetSyntaxColors);
	connect(imageButton, &QPushButton::clicked, this, &MainWindow::syntaxColorsOffImage);
	connect(saveToFileButton, &QPushButton::clicked, this, &MainWindow::saveSyntaxColorsToFile);
	connect(loadFromFileButton, &QPushButton::clicked, this, &MainWindow::loadSyntaxColorsFromFile);

	layout->addWidget(validateButton);
	layout->addWidget(imageButton);
	layout->addWidget(resetButton);
	layout->addWidget(saveToFileButton);
	layout->addWidget(loadFromFileButton);

	diag.setLayout(layout);
	diag.exec();
}

void MainWindow::saveSyntaxColorsToFile(){
	QString saveFile = QFileDialog::getSaveFileName(this, tr("Save File"), "syntaxColors.cdwzrd", tr("All Files (*);"));

	if (saveFile.isEmpty()){
		return;
	}

	if (!saveFile.endsWith(".cdwzrd")){
		saveFile += ".cdwzrd";
	}

	QFile file(saveFile);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
		openHelpMenu("Failed to open file to save syntax colors.");
		if (useSpeakerAction->isChecked()){
			#ifdef _WIN32
				speech->say("Failed to open file to save syntax colors.");
			#endif
		}
		return;
	}

	QStringList listOData;

	for (int i = 0; i < hexColorsList.length(); i++){
		listOData.push_back(hexColorsList[i]->text());
	}

	QString data = "CodeWizard - SyntaxColors\n\n"+listOData.join(",");

	QTextStream out(&file);
	out << data;
	file.close();

	openHelpMenu("Completed.");
}

void MainWindow::loadSyntaxColorsFromFile(){
	QString filePath = QFileDialog::getOpenFileName(this, "Open CodeWizard File", "", "CodeWizard Files (*.cdwzrd);");

	if (filePath.isEmpty()) {
		return; // Return an empty string if no file is selected
	}

	QFile file(filePath);

	// Attempt to open the file in read-only mode
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		openHelpMenu("Failed to open file.");
		if (useSpeakerAction->isChecked()){
			#ifdef _WIN32
				speech->say("Failed to open file.");
			#endif
		}
		return;
	}

	// Read the contents of the file
	QTextStream in(&file);
	QString fileContents = in.readAll();
	file.close();

	QString expectedHeader = "CodeWizard - SyntaxColors\n\n";

	if (!fileContents.startsWith(expectedHeader)){
		openHelpMenu("File does not match specification.");
		if (useSpeakerAction->isChecked()){
			#ifdef _WIN32
				speech->say("File does not match specification.");
			#endif
		}
		return;
	}

	QString content = fileContents.mid(expectedHeader.length(), fileContents.length()-expectedHeader.length());

	QStringList hex = content.split(",");

	if (hex.length() != 8){
		openHelpMenu("File does not match specification.");
		if (useSpeakerAction->isChecked()){
			#ifdef _WIN32
				speech->say("File does not match specification.");
			#endif
		}
		return;
	}

	for (int i = 0; i < hex.length(); i++){
		hexColorsList[i]->setText(hex[i]);
	}

	validateAndConvert();
}

int MainWindow::colorDifference(QColor c1, QColor c2){
	qDebug() << "colorDifference";

	return qSqrt(qPow(c1.red()-c2.red(), 2) + qPow(c1.green()-c2.green(), 2) + qPow(c1.blue()-c2.blue(), 2));
}

void MainWindow::syntaxColorsOffImage(){
	qDebug() << "syntaxColorsOffImage";

	QString filePath = QFileDialog::getOpenFileName(nullptr, "Open Image File", "", "Images (*.png *.jpg *.bmp *.jpeg);;All Files (*)");
	if (filePath.isEmpty()) {
		return;
	}
	QPixmap pixmap(filePath);
	if (pixmap.isNull()) {
		return;
	}

	QImage image = pixmap.toImage();

	int width = image.width();
	int height = image.height();

	std::srand(static_cast<unsigned>(std::time(nullptr)));
	QList<QColor> chosen;

	int leiniency = 11;

	for (int z = 0; z < 8; z++){
		chosen = {};
		bool worked = true;

		for (int i = 0; i < 8; i++){
			bool first = true;
			QColor workingon;

			for (int j = 0; j < 200; j++){
				int x = std::rand() % width;
				int y = std::rand() % height;

				QRgb rgb = image.pixel(x,y);
				QColor color(rgb);

				int brightness = .212*(float)color.red()+.7152*(float)color.green()+.0722*(float)color.blue();

				if (darkmode && brightness < 163-z*leiniency){
					continue;
				}else if(!darkmode && brightness > 133+z*leiniency){
					continue;
				}

				if (first){
					bool keep = true;

					for (int k = 0; k < chosen.length(); k++){
						if (colorDifference(chosen[k], color) < 50){
							keep = false;
							break;
						}
					}

					if (keep){
						workingon = color;
						first = false;
					}
				}else{
					if (colorDifference(workingon, color) < 30){
						workingon = QColor((workingon.red()+color.red())/2, (workingon.green()+color.green())/2, (workingon.blue()+color.blue())/2);
					}
				}
			}

			if (first && z == 7){ // max number of retries
				if (useSpeakerAction->isChecked()){
					#ifdef _WIN32
						speech->say("This image did not play nicely with this feature.");
					#endif
				}

				openHelpMenu("This image did not play nicely with this feature. Try again (unlikely to work - we tried 8 times for you) or pick another image.");
				return;
			}else if (first){
				worked = false;
				break;
			}

			chosen.push_back(workingon);
		}

		if (worked){
			break;
		}
	}

	coloredFormats = {};
	coloredFormats.append(QTextCharFormat());
	for (const QColor color : chosen){
		QTextCharFormat form = QTextCharFormat();
		form.setForeground(color);
		coloredFormats.append(form);
	}

	for (int i = 1; i < 9; ++i) {
		hexColorsList[i-1]->setText(coloredFormats[i].foreground().color().name());
	}

	validateAndConvert();
}

void MainWindow::setFormatsFromMyList(QString str){
	qDebug() << "setFormatsFromMyList";

	coloredFormats = {};
	coloredFormats.append(QTextCharFormat());
	QStringList defaultNums = defaultSyntaxNumbers.split("|");

	int i = 0;
	for(const QString color : str.split("|")){
		QStringList nums = color.split(",");
		QTextCharFormat form = QTextCharFormat();
		QColor col(nums[0].toInt(), nums[1].toInt(), nums[2].toInt());

		form.setForeground(col);
		coloredFormats.append(form);
	}
}

void MainWindow::resetSyntaxColors(){
	qDebug() << "resetSyntaxColors";

	setFormatsFromMyList(defaultSyntaxNumbers);

	for (int i = 1; i < 9; ++i) {
		hexColorsList[i-1]->setText(coloredFormats[i].foreground().color().name());
	}

	validateAndConvert();
}

void MainWindow::validateAndConvert(){
	qDebug() << "validateAndConvert";

	QDialog diag = QDialog(this);
	QVBoxLayout *layout = new QVBoxLayout(this);
	QLabel *label = new QLabel(this);
	label->setFont(textEdit->font());

	QList<QString> hexEdits;

	for (const QLineEdit* LE : hexColorsList){
		QRegularExpression regex("^#[0-9A-Fa-f]{6}([0-9A-Fa-f]{2})?$");
		QRegularExpressionMatch match = regex.match(LE->text());

		if (match.hasMatch()) {
			hexEdits.append(LE->text());
		} else {
			if (useSpeakerAction->isChecked()){
				#ifdef _WIN32
					speech->say("Hex code invalid.");
				#endif
			}
			label->setText("ERROR: Hex code invalid: \""+LE->text()+"\"");
			layout->addWidget(label);
			diag.setLayout(layout);
			diag.exec();
			return;
		}
	}

	coloredFormats = {};
	coloredFormats.append(QTextCharFormat());

	for (const QString hex : hexEdits){
		QTextCharFormat form;
		form.setForeground(QColor(hex));
		coloredFormats.append(form);
		treeParserSyntaxHighlighter.setFormats(coloredFormats);
		saveWantedTheme();
	}

	rehighlightFullDoc();

	if (useSpeakerAction->isChecked()){
		#ifdef _WIN32
			speech->say("Succeeded!");
		#endif
	}

	label->setText("Succeeded!");
	layout->addWidget(label);
	diag.setLayout(layout);
	diag.exec();
}

void MainWindow::applyEditToTree(int startByte, int oldEndByte, int newEndByte, int startPointRow, int startPointColumn, int oldEndPointRow, int oldEndPointColumn, int newEndPointRow, int newEndPointColumn) {
	qDebug() << "applyEditToTree";

	TSInputEdit edit;
	edit.start_byte = startByte;
	edit.old_end_byte = oldEndByte;
	edit.new_end_byte = newEndByte;

	edit.start_point = {static_cast<uint32_t>(startPointRow), static_cast<uint32_t>(startPointColumn)};
	edit.old_end_point = {static_cast<uint32_t>(oldEndPointRow), static_cast<uint32_t>(oldEndPointColumn)};
	edit.new_end_point = {static_cast<uint32_t>(newEndPointRow), static_cast<uint32_t>(newEndPointColumn)};

	ts_tree_edit(tree, &edit);
}

void MainWindow::rehighlightFullDoc(){
	qDebug() << "rehighlightFullDoc";

	treeParserSyntaxHighlighter.setLanguage(currentLang.name);

	if (!tree){
		return;
	}

	treeParserSyntaxHighlighter.fullDocRehighlight(textDocument, tree);
}

void MainWindow::onContentsChange(int position, int charsRemoved, int charsAdded) {
	qDebug() << "onContentsChange";

	if (!tree){
		return;
	}
	// Get the block containing the change
	QTextBlock block = textDocument->findBlock(position);
	if (!block.isValid()) return;

	// Determine the range of affected text
	int startByte = position;
	int oldEndByte = position + charsRemoved;
	int newEndByte = position + charsAdded;

	int startRow = block.firstLineNumber();
	int startCol = position - block.position();

	int oldEndRow = startRow; // Assuming single block edit; adjust for multi-block edits
	int oldEndCol = startCol + charsRemoved;

	int newEndRow = startRow;
	int newEndCol = startCol + charsAdded;

	// Apply edit to the Tree-sitter tree
	applyEditToTree(startByte, oldEndByte, newEndByte, startRow, startCol, oldEndRow, oldEndCol, newEndRow, newEndCol);

	// Parse incrementally
	QByteArray documentText = textDocument->toPlainText().toLatin1().constData();
	TSTree* newTree = ts_parser_parse_string(parser, tree, documentText, documentText.size());

	treeParserSyntaxHighlighter.setLanguage(currentLang.name); // we do this because I'm too lazy to do it any other way
	treeParserSyntaxHighlighter.updateHighlighting(textDocument, position, charsAdded+charsRemoved, tree, newTree, charsAdded == textDocument->characterCount());

	tree = newTree;
}

void MainWindow::printTree(TSNode node, int depth) {
	// Indent based on depth
	QString indent = QString(depth * 2, ' ');
	qDebug() << indent << ts_node_type(node); // DON'T REMOVE THIS ADAM (from your friendly neighborhood adam)

	// Get the node type and text range
	const char* nodeType = ts_node_type(node);
	uint32_t startByte = ts_node_start_byte(node);
	uint32_t endByte = ts_node_end_byte(node);
	bool isNamed = ts_node_is_named(node);

	// Recursively log all child nodes
	uint32_t childCount = ts_node_child_count(node);
	for (uint32_t i = 0; i < childCount; i++) {
		printTree(ts_node_child(node, i), depth + 1);
	}
}

void MainWindow::mouseClicked(){
	qDebug() << "mouseClicked";
}

void MainWindow::mouseReleased(){
	qDebug() << "mouseClicked";

	if (QGuiApplication::queryKeyboardModifiers() & Qt::ControlModifier) {
		gotoDefinitionActionTriggered();
	}
}

void MainWindow::onOpenOutside()
{
	qDebug() << "onOpenOutside";

	QModelIndex index = fileTree->currentIndex();
	if (!index.isValid())
		return;

	QString filePath = fileModel->filePath(index);
	QFileInfo fileInfo(filePath);

	// Use QProcess to open the file with the system's default application
	QProcess process;
	#ifdef _WIN32
		process.startDetached("cmd", QStringList() << "/c" << "start" << "" << QDir::toNativeSeparators(filePath));
	#elif defined(Q_OS_MAC)
		process.startDetached("open", QStringList() << filePath);
	#else
		process.startDetached("xdg-open", QStringList() << filePath);
	#endif
}

void MainWindow::onOpenInExplorer()
{
	qDebug() << "onOpenInExplorer";

	QModelIndex index = fileTree->currentIndex();
	if (!index.isValid())
		return;

	QString filePath = fileModel->filePath(index);
	QFileInfo fileInfo(filePath);
	QDesktopServices::openUrl(QUrl::fromLocalFile(fileInfo.dir().absolutePath()));
}

void MainWindow::onCopyPath()
{
	qDebug() << "onCopyPath";

	QModelIndex index = fileTree->currentIndex();
	if (!index.isValid())
		return;

	QString filePath = fileModel->filePath(index);
	QClipboard *clipboard = QApplication::clipboard();
	clipboard->setText(filePath);
}

void MainWindow::openFileTreeContextMenu(const QPoint &pos)
{
	qDebug() << "openFileTreeContextMenu";

	// Get the index at the cursor position
	QModelIndex index = fileTree->indexAt(pos);
	if (!index.isValid())
		return;

	// Get the file info for the clicked item
	QString filePath = fileModel->filePath(index);
	QFileInfo fileInfo(filePath);

	// Show context menu at cursor position
	fileTreeContextMenu->popup(fileTree->viewport()->mapToGlobal(pos));
}

void MainWindow::onWindowStateChanged(){
	qDebug() << "onWindowStateChanged";

	if (useFileTree->isChecked() || useFileTreeIfFullscreen->isChecked() && (isFullScreen() || isMaximized())){
		fileTree->show();
	}else{
		fileTree->hide();
	}
}

void MainWindow::on_actionOpen_Folder_triggered(){
	qDebug() << "on_actionOpen_Folder_triggered";

	QString folderPath = QFileDialog::getExistingDirectory(this,
		"Select Folder",  // Dialog title
		QString(),        // Initial directory (can leave empty for default)
		QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks); // Show only directories

	// Check if a folder was selected
	if (!folderPath.isEmpty()) {
		fileModel->setRootPath(folderPath);
		QSettings settings("FoundationTechnologies", "CodeWizard");
		settings.setValue("mostRecentFolder", folderPath);

		fileTree->setRootIndex(fileModel->index(fileModel->rootPath()));

		if (useFileTree->isChecked() || useFileTreeIfFullscreen->isChecked() && (isFullScreen() || isMaximized())){ // BACK TO HERE YO
			fileTree->show();
		}else{
			fileTree->hide();
		}
	}
}

void MainWindow::showWeDontFuckWithTheLSP(){
	qDebug() << "showWeDontFuckWithTheLSP";

	if (useSpeakerAction->isChecked()){
		#ifdef _WIN32
			speech->say("Action not supported while LSP is initializing.");
		#endif
	}
	QMessageBox messageBox;
	messageBox.setWindowTitle("CodeWizard");
	messageBox.setText("Please retry in a moment, this action is not supported while the LSP is initializing.");
	messageBox.setIcon(QMessageBox::Information);
	messageBox.setStandardButtons(QMessageBox::Ok);
	messageBox.setFont(textEdit->font());
	messageBox.exec();
}

void MainWindow::showHoldYourHorses(){
	qDebug() << "showHoldYourHorses";

	if (useSpeakerAction->isChecked()){
		#ifdef _WIN32
			speech->say("Action not supported while opening file.");
		#endif
	}
	QMessageBox messageBox;
	messageBox.setWindowTitle("CodeWizard");
	messageBox.setText("Please retry in a moment, still opening another file.");
	messageBox.setIcon(QMessageBox::Information);
	messageBox.setStandardButtons(QMessageBox::Ok);
	messageBox.setFont(textEdit->font());
	messageBox.exec();
}

void MainWindow::checkForFixitDialogue(){
	qDebug() << "checkForFixitDialogue";

	if (!textEdit->toPlainText().contains("\n    ")){
		return;
	}

	if (useSpeakerAction->isChecked()){
		#ifdef _WIN32
			speech->say("Detected space based indenting in file. Fix-it recommended.");
		#endif
	}

	QMessageBox messageBox;
	messageBox.setWindowTitle("CodeWizard");
	messageBox.setText("Detected space-based indenting in file. Run Fix-It?");
	messageBox.setIcon(QMessageBox::Information);
	messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);

	messageBox.setFont(textEdit->font());

	// Execute and check the user's choice
	if (messageBox.exec() == QMessageBox::Yes) {
		on_actionFix_It_triggered();
	}
}

void MainWindow::fileTreeOpened(const QModelIndex &index){
	qDebug() << "fileTreeOpened";

	if (isSettingUpLSP){
		showWeDontFuckWithTheLSP();
		return;
	}

	if (isOpeningFile){
		showHoldYourHorses();
		return;
	}

	QString oldFile = fileName;

	isOpeningFile = true;

	storedLineNumbers[fileName] = textEdit->verticalScrollBar()->value();

	if (!index.model()->hasChildren(index)) {
		QString newFile = index.data(QFileSystemModel::FilePathRole).toString();

		if (newFile.isEmpty()){
			isOpeningFile = false;
			return;
		}

		if (useSpeakerAction->isChecked()){
			#ifdef _WIN32
				speech->say("Opening File");
			#endif
		}

		if (unsaved && fileName != ""){
			pullUpSaveDialogue();
		}

		QFileInfo fileInfo(newFile);
		QFile file(newFile);
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
			QMessageBox newWarningBox;
			newWarningBox.setIcon(QMessageBox::Warning);
			newWarningBox.setText(tr("Cannot open file: %1").arg(file.errorString()));
			newWarningBox.setWindowTitle(tr("Error"));
			newWarningBox.setFont(textEdit->font());
			newWarningBox.exec();
			isOpeningFile = false;
			return;
		}

		if (!checkForLargeFile(&file)){
			isOpeningFile = false;
			return;
		}

		fileName = newFile;

		setLangOffFilename(fileName, false);

		unsaved = false;

		QString fileNameName = fileInfo.fileName();

		windowName = "CodeWizard V"+versionNumber+" - "+fileNameName+" - "+fileName;

		QTextStream in(&file);
		QString fileContent = in.readAll();

		previousLineCount = 1;
		savedText = fileContent;

		setupSyntaxTreeOnOpen(fileContent);

		highlightDiagnostics(true);

		textEdit->setPlainText(fileContent);
		toCompareTo = fileContent;

		previousLineCount = fileContent.count('\xa')+1;
		file.close();

		int cnt = fileContent.count('\n') + 1;

		updateLineNumbers(cnt);
		updateExtraWordsList();

		setWindowTitle(windowName);
		addFileToRecentList(fileName);

		auto it = storedLineNumbers.find(fileName);
		if (it != storedLineNumbers.end()) {
			textEdit->verticalScrollBar()->setValue(it->second);
		}

		lspMutex.lock();
		setupLSP(oldFile);
		lspMutex.unlock();

		updateMargins(true); // called on open - every time

		if (useSpeakerAction->isChecked()){
			#ifdef _WIN32
				speech->say("File Opened");
			#endif
		}
	}
	isOpeningFile = false;

	checkForFixitDialogue();
}

bool MainWindow::checkForLargeFile(QFile *file){
	qint64 fileSize = file->size(); // bytes
	qint64 kb = fileSize/1024; // 1000 of these per mb

	if (kb > 1000){ // 1mb I think
		if (useSpeakerAction->isChecked()){
			#ifdef _WIN32
				speech->say("That's a large file ("+QString::number(kb/1000)+" mb). Open anyways?");
			#endif
		}

		QMessageBox dialog;
		dialog.setWindowTitle("CodeWizard");
		dialog.setText("Opening large file ("+QString::number(kb/1000)+" mb) - continue?");
		dialog.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
		dialog.setDefaultButton(QMessageBox::Yes);
		dialog.setFont(textEdit->font());

		int response = dialog.exec();
		if (response == QMessageBox::No) {
			return false;
		}
	}

	return true;
}

void MainWindow::fileTreeToggled(){
	qDebug() << "fileTreeToggled";

	saveWantedTheme();
	if (useFileTree->isChecked() || useFileTreeIfFullscreen->isChecked() && (isFullScreen() || isMaximized())){
		fileTree->show();
	}else{
		fileTree->hide();
	}
}

void MainWindow::autoSave(){
//	qDebug() << "autoSave";

	if (isSettingUpLSP){ // we don't show message here because it's automated
		return;
	}

	if (unsaved && fileName != "" && autoSaveAct->isChecked()){
		on_actionSave_triggered();
		setWindowTitle(windowName);
		unsaved = false;
	}
}

void MainWindow::gotoDefinitionActionTriggered(){
	qDebug() << "gotoDefinitionActionTriggered";

	if (isSettingUpLSP || isOpeningFile){
		return;
	}

	lspMutex.lock();
	if (client){
		QTextCursor cursor = textEdit->textCursor();
		int line = cursor.blockNumber();
		int column = cursor.columnNumber();
		client->requestGotoDefinition(line, column);
	}
	lspMutex.unlock();
}

void MainWindow::handleMouseMoved(QPoint pos)
{
//	qDebug() << "handleMouseMoved"; - we don't do it for certain functions

	QPoint difference = pos - mousePos;

	QTextCursor cursor = textEdit->cursorForPosition(pos); // Get cursor at mouse position
	QRect cursorRect = textEdit->cursorRect(cursor);
	QPoint cursorPos = cursorRect.topLeft();
	suggestedPosition = cursorRect.bottomLeft();

	if (qAbs(difference.x()) < 30 && qAbs(difference.y()) < 30){
		return;
	}

	expectedHoverInfoId = -1;

	mousePos = pos;
	hoverBox->hide();

	if (isSettingUpLSP || isOpeningFile){
		return;
	}

	if (!client){
		return;
	}

	if (qAbs(cursorPos.x() - pos.x()) > 15 || qAbs(cursorPos.y() - pos.y()) > 15){
		return;
	}

	// here we determine if it's over a diagnostic to check out - otherwise we request the help of the LSP for info

	int line = cursor.blockNumber(); // 0 based
	int column = cursor.columnNumber();
	int bestIndx = -1;

	QList<int> allowedSeverities;
	if (showErrors->isChecked()){
		allowedSeverities.append(1);
	}
	if (showWarnings->isChecked()){
		allowedSeverities.append(2);
	}
	if (showOther->isChecked()){
		allowedSeverities.append(3);
		allowedSeverities.append(4);
	}

	if (!allowedSeverities.empty()){
		for (int i = 0; i < errMessages.length(); i++){ // sorted least to most important by severity
			int sL = errStartL[i];
			int eL = errEndL[i];
			int sC = errStartC[i];
			int eC = errEndC[i];
			int eS = errSeverity[i];

			if (line >= sL && line <= eL && column >= sC-1 && column <= eC+1){
				if (allowedSeverities.contains(eS)){
					bestIndx = i;
				}
			}
		}
	}

	if (bestIndx != -1){
		moveHoverBox(suggestedPosition, errMessages[bestIndx], "plaintext");
		return;
	}

	if (hoverAction->isChecked()){
		cursor.select(QTextCursor::WordUnderCursor); // Select the word under the cursor
		QString word = cursor.selectedText();

		if (!word.isEmpty()){
			int line = cursor.blockNumber(); // 0 based
			int column = cursor.columnNumber();
			QTimer::singleShot(600, [=]() { // call after x milliseconds
				QPoint difference = pos - mousePos;

				if (qAbs(difference.x()) > 30 || qAbs(difference.y()) > 30){
					return;
				}

				lspMutex.lock();
				expectedHoverInfoId = client->requestHover(line, column);
				lspMutex.unlock();
			});
		}
	}
}

void MainWindow::onSuggestionItemClicked(QListWidgetItem* item){
	qDebug() << "onSuggestionItemClicked";

	currentSelection = suggestionBox->row(item);
	fillSuggestions();
	insertCompletion();
}

void MainWindow::onActionsItemClicked(QListWidgetItem* item){
	qDebug() << "onActionsItemClicked";

	currentSelectionAction = actionBox->row(item);
	fillActionsBox();
	activateCodeAction();
}

void MainWindow::on_actionLSP_triggered()
{
	qDebug() << "on_actionLSP_triggered";

	QString lspPath = "";
	QString languageId = currentLang.name.toLower(); // need to reasign for langs where my chosen name is not the language id

	if (currentLang.name == "Python"){
		lspPath = pythonLSP;
	}else if (currentLang.name == "Rust"){
		lspPath = rustLSP;
	}else if (currentLang.name == "WGSL"){
		lspPath = WGSLLSP;
	}else if (currentLang.name == "GLSL"){
		lspPath = WGSLLSP;
	}else if (currentLang.name == "C++"){
		lspPath = CppLSP;
		languageId = "cpp";
	}else if (currentLang.name == "Txt"){
		lspPath = txtLSP;
		languageId = "plaintext";
	}else if (currentLang.name == "JS"){
		lspPath = jsLSP;
		languageId = "javascript";
	}else if (currentLang.name == "TS"){
		lspPath = tsLSP;
		languageId = "typescript";
	}else if (currentLang.name == "HTML"){
		lspPath = HTMLLSP;
	}else if (currentLang.name == "Go"){
		lspPath = goLSP;
	}else if (currentLang.name == "Lua"){
		lspPath = luaLSP;
	}else if (currentLang.name == "C#"){
		lspPath = csharpLSP;
		languageId = "csharp";
	}else if (currentLang.name == "Java"){
		lspPath = javaLSP;
	}else if (currentLang.name == "C"){
		lspPath = cLSP;
	}

	QInputDialog dialog;
	dialog.setFont(textEdit->font());  // Set the font to match textEdit's font
	dialog.setWindowTitle("LSP SETUP");
	dialog.setLabelText("Cmd to start Language Server");
	dialog.setTextValue(lspPath);  // Default text value can be an empty string
	dialog.setTextEchoMode(QLineEdit::Normal);  // You can change this to Password if needed
	dialog.exec();

	if (dialog.result() != QDialog::Accepted) {
		return;
	}

	lspPath = dialog.textValue();

	//QString lspPath = QFileDialog::getOpenFileName(this, tr("Open File"), fileName, tr("All Files (*);"));

	if (currentLang.name == "Python"){
		pythonLSP = lspPath;
	}else if (currentLang.name == "Rust"){
		rustLSP = lspPath;
	}else if (currentLang.name == "WGSL"){
		WGSLLSP = lspPath;
	}else if (currentLang.name == "GLSL"){
		WGSLLSP = lspPath;
	}else if (currentLang.name == "C++"){
		CppLSP = lspPath;
	}else if (currentLang.name == "Txt"){
		txtLSP = lspPath;
	}else if (currentLang.name == "JS"){
		jsLSP = lspPath;
	}else if (currentLang.name == "TS"){
		tsLSP = lspPath;
	}else if (currentLang.name == "HTML"){
		HTMLLSP = lspPath;
	}else if (currentLang.name == "Go"){
		goLSP = lspPath;
	}else if (currentLang.name == "Lua"){
		luaLSP = lspPath;
	}else if (currentLang.name == "C#"){
		csharpLSP = lspPath;
	}else if (currentLang.name == "Java"){
		javaLSP = lspPath;
	}else if (currentLang.name == "C"){
		cLSP = lspPath;
	}

	saveWantedTheme();
}

void MainWindow::gotoDefinitionReceived(int line1, int character1, int line, int character, QString uri) {
	qDebug() << "gotoDefinitionReceived";

	if (uri != QUrl::fromLocalFile(fileName).toString()){
		globalArgFileName = QUrl(uri).toLocalFile();
		QMetaObject::invokeMethod(this, [this, line, character, uri]() {
			on_actionOpen_triggered(true);
		}, Qt::QueuedConnection);
		QMetaObject::invokeMethod(this, [this, line1, character1, line, character, uri]() {
			if (uri == QUrl::fromLocalFile(fileName).toString()){
				gotoDefinitionReceived(line1, character1, line, character, uri);
			}
		}, Qt::QueuedConnection);

		return;
	}

	QTextCursor cursor = textEdit->textCursor();
	cursor.setPosition(textDocument->findBlockByNumber(line1).position() + character1);
	cursor.setPosition(textDocument->findBlockByNumber(line).position() + character, QTextCursor::KeepAnchor);
	textEdit->setTextCursor(cursor);
	textEdit->ensureCursorVisible();
}

void MainWindow::setupLSP(QString oldFile)
{
	qDebug() << "setupLSP";

	isSettingUpLSP = true;

	QString lspPath = "";
	QString languageId = currentLang.name.toLower(); // need to reasign for langs where my chosen name is not the language id

	if (currentLang.name == "Python"){
		lspPath = pythonLSP;
	}else if (currentLang.name == "Rust"){
		lspPath = rustLSP;
	}else if (currentLang.name == "WGSL"){
		lspPath = WGSLLSP;
	}else if (currentLang.name == "GLSL"){
		lspPath = WGSLLSP;
	}else if (currentLang.name == "C++"){
		lspPath = CppLSP;
		languageId = "cpp";
	}else if (currentLang.name == "Txt"){
		lspPath = txtLSP;
		languageId = "plaintext";
	}else if (currentLang.name == "JS"){
		lspPath = jsLSP;
		languageId = "javascript";
	}else if (currentLang.name == "TS"){
		lspPath = tsLSP;
		languageId = "typescript";
	}else if (currentLang.name == "HTML"){
		lspPath = HTMLLSP;
	}else if (currentLang.name == "Go"){
		lspPath = goLSP;
	}else if (currentLang.name == "Lua"){
		lspPath = luaLSP;
	}else if (currentLang.name == "C#"){
		lspPath = csharpLSP;
		languageId = "csharp";
	}else if (currentLang.name == "Java"){
		lspPath = javaLSP;
	}else if (currentLang.name == "C"){
		lspPath = cLSP;
	}

	if (client && client->lspPath == lspPath){
		client->closeDocument(oldFile);
		client->openDocument(fileName, languageId, textEdit->toPlainText());
		isSettingUpLSP = false;
		return;
	}

	//The client is not setup with the correct LSP

	if (client){
		client->shutdown();
		delete client;
		client = nullptr;
	}

	if (lspPath.isEmpty() || fileName.isEmpty()){
		isSettingUpLSP = false;
		return;
	}

	if (useSpeakerAction->isChecked()){
		#ifdef _WIN32
			speech->say("Initializing LSP");
		#endif
	}

	client = new LanguageServerClient(lspPath, textEdit);

	// Connect to receive completions
	connect(client, &LanguageServerClient::completionReceived, [this](const QStringList &completions, int id) {
		if (id != expectedCompletionId){
			return;
		}

		ShowSuggestionsWithSuperSet(completions);
	});

	connect(client, &LanguageServerClient::receivedDiagnostics, [this](const QStringList &messages, const QList<int> &startC, const QList<int> &startL, const QList<int> &endC, const QList<int> &endL, const QList<int> &severity){
		if (isErrorHighlighted){
			highlightDiagnostics(true);
		}
		errMessages = messages;
		errStartC = startC;
		errStartL = startL;
		errEndC = endC;
		errEndL = endL;
		errSeverity = severity;

		errMenu.UpdateErrors(startL, messages, severity);

		highlightDiagnostics(false);
		isErrorHighlighted = true;
	});

	connect(client, &LanguageServerClient::hoverInformationReceived, [this](QString info, QString type, int id) {
		if (id == expectedHoverInfoId){
			moveHoverBox(suggestedPosition, info, type);
		}
	});

	connect(client, &LanguageServerClient::gotoDefinitionsReceived, this, &MainWindow::gotoDefinitionReceived, Qt::AutoConnection);

	connect(client, &LanguageServerClient::codeActionsReceived, [this](const QJsonArray& suggestedActions) {
		codeActions = suggestedActions;

		if (suggestedActions.count() == 0){
			return;
		}

		currentSelectionAction = 0;

		QStringList actions = {};
		for (int i = 0; i < suggestedActions.count(); i++){
			actions.append(suggestedActions[i].toObject()["title"].toString());
		}

		QFontMetrics metrics(textEdit->font());
		int height;

		if (7 < actions.length()){
			height = metrics.height() * 7;
		}else{
			height = metrics.height() * (actions.length()+1);
		}

		QRect cursorRect = textEdit->cursorRect();
		QPoint suggestedPosition = cursorRect.bottomLeft();

		// Get the geometry of the parent window
		QWidget* parentWindow = textEdit->window(); // Ensure the parent is the main window
		QRect parentGeometry = parentWindow->rect(); // Geometry relative to the parent

		// Adjust the suggestion box position to prevent overflow
		int boxWidth = 400; // Width of the suggestion box
		if (suggestedPosition.x() + boxWidth > parentGeometry.width()) {
			suggestedPosition.setX(parentGeometry.width() - boxWidth);
		}

		if (suggestedPosition.y() + height > parentGeometry.height()) {
			suggestedPosition.setY(parentGeometry.height() - height);
		}

		fillActionsBox();

		// Apply the adjusted position and dimensions
		actionBox->move(suggestedPosition);
		actionBox->resize(boxWidth, height);
		actionBox->show();
	});

	QFileInfo fileInfo(fileName);

	client->initialize(fileInfo.absolutePath());

	client->openDocument(fileName, languageId, textEdit->toPlainText());

	if (useSpeakerAction->isChecked()){
		#ifdef _WIN32
			speech->say("Initialized LSP");
		#endif
	}

	isSettingUpLSP = false;
}

void MainWindow::ShowSuggestionsWithSuperSet(QStringList completions){
	qDebug() << "ShowSuggestionsWithSuperSet";

	QString word = MainWindow::getCurrentWord();

	suggestion = {};

	for (int i = 0; i < completions.length(); i++) {
		if (completions[i].startsWith(word) && word != completions[i]) {
			suggestion.push_back(completions[i]);
		}
	}

	fillSuggestions();

	if (suggestion.length() > 0){
		QFontMetrics metrics(textEdit->font());
		int height;

		if (7 < suggestion.length()){
			height = metrics.height() * 7;
		}else{
			height = metrics.height() * (suggestion.length()+1);
		}

		QRect cursorRect = textEdit->cursorRect();
		QPoint suggestedPosition = cursorRect.bottomLeft();

		// Get the geometry of the parent window
		QWidget* parentWindow = textEdit->window(); // Ensure the parent is the main window
		QRect parentGeometry = parentWindow->rect(); // Geometry relative to the parent

		// Adjust the suggestion box position to prevent overflow
		int boxWidth = 300; // Width of the suggestion box
		if (suggestedPosition.x() + boxWidth > parentGeometry.width()) {
			suggestedPosition.setX(parentGeometry.width() - boxWidth);
		}

		if (suggestedPosition.y() + height > parentGeometry.height()) {
			suggestedPosition.setY(parentGeometry.height() - height);
		}

		// Apply the adjusted position and dimensions
		suggestionBox->move(suggestedPosition);
		suggestionBox->resize(boxWidth, height);
		suggestionBox->show();
		currentCompletion = suggestion[0];
	}else{
		suggestionBox->hide();
		currentCompletion = "";
	}
}

void MainWindow::fillActionsBox(){
	qDebug() << "fillActionsBox";

	actionBox->clear();
	for (int i = 0; i < codeActions.count(); i++){
		QString copiedString = codeActions[i].toObject()["title"].toString();
		if (i == currentSelectionAction){
			actionBox->addItem(" > "+copiedString);
		}else{
			actionBox->addItem(copiedString);
		}
	}

	if (currentSelectionAction < codeActions.count()){
		QListWidgetItem* item = actionBox->item(currentSelectionAction);
		if (item) {
			actionBox->scrollToItem(item, QAbstractItemView::PositionAtCenter);
		}
	}
	actionBox->update();
}

void MainWindow::moveHoverBox(QPoint givenPos, QString info, QString type){
	qDebug() << "moveHoverBox - type " << type;

	QString finalString = info.trimmed();

	QStringList lines;
	int lineCount = 0;

	if (type == "markdown"){
		finalString = markdownToHtml(info);
	}else{
		finalString = plaintextToHtml(info);
	}

	hoverBox->setHtml(finalString);

	lineCount = finalString.count("<br>")+finalString.count("<hr>")*4 + 2;
	lines = hoverBox->toPlainText().split("\n"); // this way we don't get the sh*t from the html

	int maxLength = 0;

	for (const QString& line : lines) {
		maxLength = qMax(maxLength, line.length());
	}

	QFontMetrics metrics(textEdit->font());
	int textHeight = metrics.height() * (lineCount);
	int textWidth = metrics.horizontalAdvance('M') * (maxLength + 4);

	int maxWidth = qMin(textEdit->width()/2, textWidth);
	int maxHeight = qMin(textEdit->height()/3, textHeight);

	hoverBox->resize(maxWidth, maxHeight);

	QPoint newPos = givenPos;
	if (givenPos.x() + maxWidth > textEdit->width()) { // If it goes beyond the right edge
		newPos.setX(givenPos.x() - maxWidth); // Move it to the left side
	}

	if (givenPos.y() + maxHeight > textEdit->height()) {
		newPos.setY(givenPos.y() - maxHeight - metrics.height());
	}

	hoverBox->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);
	hoverBox->setFocusPolicy(Qt::StrongFocus); // Allow the hoverBox to receive keyboard focus

	hoverBox->move(newPos);
	hoverBox->show();
}

QString MainWindow::plaintextToHtml(QString plaintext) {
	qDebug() << "plaintextToHtml";

	QString html = plaintext;

	html.replace("&", "&amp;");
	html.replace(">", "&gt;");
	html.replace("<", "&lt;");
	html.replace("\"", "&quot;");
	html.replace("'", "&apos;");

	html.replace("\n---\n", "</p><hr><p>");
	html.replace("\n<hr>", "</p><hr><p>");
	html.replace("<hr>\n", "</p><hr><p>");

	while (html.contains("\n\n")){
		html.replace("\n\n", "\n");
	}

	html.replace("\n", "<br>");

	html = "<p>"+html+"</p>";

	return "<div style=\"white-space: pre;\">"+html+"</div>";
}

QString MainWindow::markdownToHtml(QString markdown) {
	qDebug() << "markdownToHtml";

	QString html = markdown;

	while (html.contains("\n\n\n")){
		html.replace("\n\n\n", "\n\n");
	}

	html.replace("&", "&amp;");
	html.replace(">", "&gt;");
	html.replace("<", "&lt;");
	html.replace("\"", "&quot;");
	html.replace("'", "&apos;");

	html.replace("\n---\n", "<hr>");
	html.replace("\n<hr>", "<hr>");
	html.replace("<hr>\n", "<hr>");

	while (html.contains("```")){
		html.replace("```", "`");
	}

	QSet<QChar> alphanumerical = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '_'};

	int lastIndx = 0;
	for (int i = 0; i < html.length(); i++){
		if (alphanumerical.contains(html[i])){
			lastIndx = i;
		}
	}

	QString before = html.left(lastIndx);
	QString after = html.mid(lastIndx);
	after.replace("\n", "");
	html = before + after;

	// Convert headers
	html.replace(QRegularExpression(R"(^###### (.+)$)", QRegularExpression::MultilineOption), "<h6>\\1</h6>");
	html.replace(QRegularExpression(R"(^##### (.+)$)", QRegularExpression::MultilineOption), "<h5>\\1</h5>");
	html.replace(QRegularExpression(R"(^#### (.+)$)", QRegularExpression::MultilineOption), "<h4>\\1</h4>");
	html.replace(QRegularExpression(R"(^### (.+)$)", QRegularExpression::MultilineOption), "<h3>\\1</h3>");
	html.replace(QRegularExpression(R"(^## (.+)$)", QRegularExpression::MultilineOption), "<h2>\\1</h2>");
	html.replace(QRegularExpression(R"(^# (.+)$)", QRegularExpression::MultilineOption), "<h1>\\1</h1>");

	// Convert bold
	html.replace(QRegularExpression(R"(\*\*(.+?)\*\*)"), "<b>\\1</b>");
	html.replace(QRegularExpression(R"(__(.+?)__)"), "<b>\\1</b>");

	// Convert italic
	html.replace(QRegularExpression(R"(\*(.+?)\*)"), "<i>\\1</i>");
	html.replace(QRegularExpression(R"(_(.+?)_)"), "<i>\\1</i>");

	// Convert inline code
	html.replace(QRegularExpression(R"(`([\s\S]+?)`)"), "<code>\\1</code>");

	// Convert links
	html.replace(QRegularExpression(R"(\[(.+?)\]\((.+?)\))"), R"(<a href="\\2">\\1</a>)");

	// Replace line breaks
	html = html.trimmed();
	html.replace("\n", "<br>");
	html.replace("`", "");

	return "<div style=\"white-space: pre;\">"+html+"</div>";
}

void MainWindow::on_actionIncrease_Text_Size_triggered()
{
	qDebug() << "on_actionIncrease_Text_Size_triggered";

	fontSize += 1.0;
	updateFonts();
	saveWantedTheme();
}

void MainWindow::on_actionReset_Text_Size_triggered()
{
	qDebug() << "on_actionReset_Text_Size_triggered";

	fontSize = 11.0;
	updateFonts();
	saveWantedTheme();
}

void MainWindow::on_actionDecrease_Text_Size_triggered()
{
	qDebug() << "on_actionDecrease_Text_Size_triggered";

	if (fontSize > 1.0){
		fontSize -= 1.0;
	}
	updateFonts();
	saveWantedTheme();
}

void MainWindow::on_actionSet_Text_Size_triggered()
{
	qDebug() << "on_actionSet_Text_Size_triggered";

	bool ok;
	double newFontSize = QInputDialog::getDouble(
		this,
		"Font Size",
		"Text Size:",
		fontSize,   // Current font size
		1.0,        // Minimum font size
		50.0,       // Maximum font size
		1,          // Step size
		&ok         // Whether the user pressed OK or Cancel
	);

	if (ok) {
		fontSize = newFontSize;  // Update with the new floating-point font size
		saveWantedTheme();
		updateFonts();
	}
}

void MainWindow::updateFonts()
{
	qDebug() << "updateFonts";

	QFont font = textEdit->font();
	font.setPointSizeF(fontSize);
	font.setItalic(false);
	font.setBold(false);
	font.setStyleHint(QFont::Monospace);

	textEdit->setFont(font);

	QApplication::setFont(font);

	QFontMetrics metrics(textEdit->font());

	int fontHeight = metrics.height();
	int adjustedHeight = fontHeight + 10;

	textEdit->setTabStopDistance(tabWidth * metrics.horizontalAdvance(' '));
	textEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

	findTextEdit->setFont(font);
	findTextEdit->setTabStopDistance(tabWidth * metrics.horizontalAdvance(' '));
	findTextEdit->setMinimumHeight(adjustedHeight);
	findTextEdit->setMaximumHeight(adjustedHeight);

	replaceTextEdit->setFont(font);
	replaceTextEdit->setTabStopDistance(tabWidth * metrics.horizontalAdvance(' '));
	replaceTextEdit->setMinimumHeight(adjustedHeight);
	replaceTextEdit->setMaximumHeight(adjustedHeight);

	terminalInputLine->setFont(font);
	terminalInputLine->setTabStopDistance(tabWidth * metrics.horizontalAdvance(' '));
	terminalInputLine->setMinimumHeight(adjustedHeight);
	terminalInputLine->setMaximumHeight(adjustedHeight);

	terminalInputLineHORZ->setFont(font);
	terminalInputLineHORZ->setTabStopDistance(tabWidth * metrics.horizontalAdvance(' '));
	terminalInputLineHORZ->setMinimumHeight(adjustedHeight);
	terminalInputLineHORZ->setMaximumHeight(adjustedHeight);

	builtinTerminalTextEdit->setFont(font);
	builtinTerminalTextEdit->setTabStopDistance(tabWidth * metrics.horizontalAdvance(' '));

	builtinTerminalTextEditHORZ->setFont(font);
	builtinTerminalTextEditHORZ->setTabStopDistance(tabWidth * metrics.horizontalAdvance(' '));

	fileTreeContextMenu->setFont(font);

	lineNumberTextEdit->setFont(font);

	lineEdit->setFont(font);

	int charCount = QString::number(globalLineCount).length();
	int width = metrics.horizontalAdvance('M') * charCount+15;

	lineNumberTextEdit->setMinimumWidth(width);
	lineNumberTextEdit->setMaximumWidth(width);
	lineNumberTextEdit->setFixedWidth(width);

	lineEdit->setMaximumHeight(adjustedHeight*2);

	findButton->setFont(font);
	nextButton->setFont(font);
	replaceButton->setFont(font);
	replaceAllButton->setFont(font);

	findBar->setFont(font);
	replaceBar->setFont(font);

	menuEdit->setFont(font);
	menuFixit->setFont(font);
	menuOp1->setFont(font);
	menuRun->setFont(font);
	menuView->setFont(font);
	menuFonts->setFont(font);
	menuSubFonts->setFont(font);
	menuHelp->setFont(font);
	menuLanguage->setFont(font);
	menuGit->setFont(font);
	menuBarItem->setFont(font);
	menuOpen_Recent->setFont(font);
	menuLSP_Settings->setFont(font);
	menuWarnings->setFont(font);
	menuAutocomplete->setFont(font);
	menuSilly->setFont(font);

	suggestionBox->setFont(font);
	actionBox->setFont(font);
	hoverBox->setFont(font);

	fileTree->setFont(font);

	fontList->setFont(font);

	//I hate this

	//I shouldn't have to do this. BUT when selecting with selectAll() or whatever it changes the font, but you can't see it in findTextEdit->font()... Whatever.
	QTextCursor cursor = findTextEdit->textCursor(); // Get the current cursor
	cursor.select(QTextCursor::Document); // Select all text in the document
	// Create a QTextCharFormat to set the new font
	QTextCharFormat format;
	format.setFont(font); // Set the current font
	// Apply the new format to the selected text
	cursor.mergeCharFormat(format); // Merge the current font into the selection
	findTextEdit->setTextCursor(cursor); // Optional: Reset the cursor to the QTextEdit

	updateLineNumbers(globalLineCount);

	errMenu.reposition();
}

void MainWindow::setupCompleter() {
	qDebug() << "setupCompleter";

	QObject::connect(textEdit, &QTextEdit::cursorPositionChanged, [=]() {
		qDebug() << "lamda textEdit cursorPositionChanged";
		suggestionBox->hide();
		actionBox->hide();
		hoverBox->hide();
	});

	QObject::connect(textEdit, &QTextEdit::textChanged, [=]() { // i'm going to make this 'multi-purpose' good luck to any poor soul who comes along and reads this - Kai - this program is a mess. But I love it.
		qDebug() << "lamda textEdit textChanged";
		//This is the only unpoluted textchanged event - lol
		QString plaintext = textEdit->toPlainText();

		if (!unsaved){
			if (plaintext != savedText){ // this function also get's called for non text changed events (think highlighting or IDK)
				setWindowTitle("*"+windowName);
				unsaved = true;
			}
		}
		//Here we are going to handle the completer (what this function was supposed to be)

		if (isSettingUpLSP || isOpeningFile){
			return;
		}

		if (isErrorHighlighted){
			highlightDiagnostics(true);
		}

		//Here be dragons

		//updateSyntaxTree(plaintext);

		QString word = MainWindow::getCurrentWord();

		// If the word length is sufficient, complete
		if (!word.isEmpty()) {
			currentSelection = 0;
			QTextCursor cursor = textEdit->textCursor();

			if ((!client || onlyCodeWizardBuiltIn->isChecked()) && !noAutocomplete->isChecked()){ // ala CodeWizard
				suggestion = {};

				for (int i = 0; i < extraWordList.length(); i++) {
					if (extraWordList[i].startsWith(word) && word != extraWordList[i]) {
						suggestion.push_back(extraWordList[i]);
					}
				}

				for (int i = 0; i < wrdLstDefQStringy.length(); i++) {
					if (wrdLstDefQStringy[i].startsWith(word) && word != wrdLstDefQStringy[i]) {
						suggestion.push_back(wrdLstDefQStringy[i]);
					}
				}

				ShowSuggestionsWithSuperSet(suggestion);
			}
		} else {
			currentCompletion = "";
			suggestionBox->hide();
		}
	});
}

void MainWindow::updateDefaultWordLists(){
	qDebug() << "updateDefaultWordLists";

	wrdLstDefQStringy = currentLang.defWordList;

	wrdLstDefQSetted.clear();
	for (const QString &word : currentLang.defWordList) {
		wrdLstDefQSetted.insert(word);
	}
}

void MainWindow::fillSuggestions(){
	qDebug() << "fillSuggestions";

	suggestionBox->clear();
	for (int i = 0; i < suggestion.length(); i++){
		QString copiedString = suggestion[i];
		copiedString.replace("\n", " ");
		if (i == currentSelection){
			suggestionBox->addItem(" > "+copiedString);
		}else{
			suggestionBox->addItem(copiedString);
		}
	}

	if (currentSelection < suggestion.length()){
		QListWidgetItem* item = suggestionBox->item(currentSelection);
		if (item) {
			suggestionBox->scrollToItem(item, QAbstractItemView::PositionAtCenter);
		}
	}
	suggestionBox->update();
}

QString MainWindow::getCurrentWord() {
	qDebug() << "getCurrentWord";

	QTextCursor cursor = textEdit->textCursor();
	QTextBlock block = cursor.block();
	QString blockText = block.text();    // Use block.text() instead of cursor.selectedText()

	int blockPos = cursor.position() - block.position(); // Position within the block
	QString word;

	// Find the word before the current position in the block text
	int start = blockPos - 1;
	while (start >= 0 && (blockText[start].isLetterOrNumber() || blockText[start] == '_')) --start;
	word = blockText.mid(start + 1, blockPos - start - 1);
	return word;
}

void MainWindow::saveWantedTheme()
{
	qDebug() << "saveWantedTheme";

	if (currentLang.name == "Python"){
		pythonTag = lineEdit->toPlainText();
	}else if (currentLang.name == "Rust"){
		rustTag = lineEdit->toPlainText();
	}else if (currentLang.name == "WGSL"){
		WGSLTag = lineEdit->toPlainText();
	}else if (currentLang.name == "GLSL"){
		WGSLTag = lineEdit->toPlainText();
	}else if (currentLang.name == "C++"){
		CppTag = lineEdit->toPlainText();
	}else if (currentLang.name == "Txt"){
		txtTag = lineEdit->toPlainText();
	}else if (currentLang.name == "JS"){
		jsTag = lineEdit->toPlainText();
	}else if (currentLang.name == "TS"){
		tsTag = lineEdit->toPlainText();
	}else if (currentLang.name == "HTML"){
		HTMLTag = lineEdit->toPlainText();
	}else if (currentLang.name == "Go"){
		goTag = lineEdit->toPlainText();
	}else if (currentLang.name == "Lua"){
		luaTag = lineEdit->toPlainText();
	}else if (currentLang.name == "C#"){
		csharpTag = lineEdit->toPlainText();
	}else if (currentLang.name == "Java"){
		javaTag = lineEdit->toPlainText();
	}else if (currentLang.name == "C"){
		cTag = lineEdit->toPlainText();
	}

	QSettings settings("FoundationTechnologies", "CodeWizard");
	settings.setValue("variablesSet", true);
	settings.setValue("pythonTag", pythonTag);
	settings.setValue("rustTag", rustTag);
	settings.setValue("WGSLTag", WGSLTag);
	settings.setValue("GLSLTag", GLSLTag);
	settings.setValue("CppTag", CppTag);
	settings.setValue("txtTag", txtTag);
	settings.setValue("jsTag", jsTag);
	settings.setValue("tsTag", tsTag);
	settings.setValue("HTMLTag", HTMLTag);
	settings.setValue("goTag", goTag);
	settings.setValue("luaTag", luaTag);
	settings.setValue("csharpTag", csharpTag);
	settings.setValue("javaTag", javaTag);
	settings.setValue("cTag", cTag);

	settings.setValue("pythonLSP", pythonLSP);
	settings.setValue("rustLSP", rustLSP);
	settings.setValue("WGSLLSP", WGSLLSP);
	settings.setValue("CppLSP", CppLSP);
	settings.setValue("txtLSP", txtLSP);
	settings.setValue("jsLSP", jsLSP);
	settings.setValue("tsLSP", tsLSP);
	settings.setValue("HTMLLSP", HTMLLSP);
	settings.setValue("goLSP", goLSP);
	settings.setValue("luaLSP", luaLSP);
	settings.setValue("csharpLSP", csharpLSP);
	settings.setValue("GLSLLSP", GLSLLSP);
	settings.setValue("javaLSP", javaLSP);
	settings.setValue("cLSP", cLSP);

	settings.setValue("showWarnings", showWarnings->isChecked());
	settings.setValue("showErrors", showErrors->isChecked());
	settings.setValue("showOther", showOther->isChecked());
	settings.setValue("onlyCodeWizardBuiltIn", onlyCodeWizardBuiltIn->isChecked());
	settings.setValue("noAutocomplete", noAutocomplete->isChecked());
	settings.setValue("hoverAction", hoverAction->isChecked());
	settings.setValue("vimMode", useVimMode->isChecked());
	settings.setValue("builtinTerminal", useBuiltinTerminal->isChecked());
	settings.setValue("preferHorizontalTerminal", preferHorizontalTerminal->isChecked());
	settings.setValue("autoAddBrackets", autoAddBrackets->isChecked());
	settings.setValue("useFileTree", useFileTree->isChecked());
	settings.setValue("useFiletreeIfFullscreen",  useFileTreeIfFullscreen->isChecked());

	settings.setValue("autoSaveAct", autoSaveAct->isChecked());
	settings.setValue("randomSelectFileTypeAct",randomSelectFileTypeAct->isChecked());
	settings.setValue("useSpeakerAction", useSpeakerAction->isChecked());

	settings.setValue("splitWidths0", splitWidths[0]);
	settings.setValue("splitWidths1", splitWidths[1]);
	settings.setValue("splitWidths2", splitWidths[2]);

	QStringList strLst = QStringList();

	bool firstLine = true;
	for (const QTextCharFormat form : coloredFormats){
		if (firstLine){
			firstLine = false;
			continue;
		}

		QString str = QString::number(form.foreground().color().red())+","+QString::number(form.foreground().color().green())+","+QString::number(form.foreground().color().blue());
		strLst.append(str);
	}

	QString str = strLst.join("|");

	if (coloredFormats.length() == 9){
		settings.setValue("syntaxColors", str);
	}

	settings.setValue("groqApiKey", groqApiKey);
	settings.setValue("fontSize", fontSize);
	settings.setValue("darkModeEnabled", darkmode);
	settings.setValue("currentFont", currentFont);
	settings.setValue("tabWidth", tabWidth);
	settings.setValue("codewizard_version", versionNumber);
}

int MainWindow::compareVersionNumbers(QString vnum1, QString vnum2){
	if (vnum1 == ""){vnum1 = versionNumber;}
	if (vnum2 == ""){vnum2 = versionNumber;}

	if (vnum1 == "prior 6.0.0"){vnum1 = "5.9.9";}
	if (vnum2 == "prior 6.0.0"){vnum1 = "5.9.9";}

	QStringList nums1 = vnum1.split(".");
	QStringList nums2 = vnum2.split(".");

	if (nums1.length() != nums2.length()){
		if (nums1.length() > nums2.length()){ // we assume that if one version number has more identifiers, that it is greater than the other.
			return 1;
		}
		return -1; // otherwise the other must be longer - therfore the equality is less than
	}

	for (int i = 0; i < nums1.length(); i++){
		int n1 = nums1[i].toInt();
		int n2 = nums2[i].toInt();

		if (n1 > n2){
			return 1;
		}else if (n1 < n2){
			return -1;
		}
	}

	return 0;
}

bool MainWindow::wantedTheme()
{
	qDebug() << "wantedTheme";

	QSettings settings("FoundationTechnologies", "CodeWizard");
	bool exists = settings.value("variablesSet", false).toBool();

	if (exists){
		QString existingVersion = settings.value("codewizard_version", "prior 6.0.0").toString();

		if (compareVersionNumbers(existingVersion, "5.9.9") > 0){ // more than v599
			pythonTag = settings.value("pythonTag", defPythonTag).toString();
			rustTag = settings.value("rustTag", defRustTag).toString();
			WGSLTag = settings.value("WGSLTag", defWGSLTag).toString();
			GLSLTag = settings.value("GLSLTag", defGLSLTag).toString();
			CppTag = settings.value("CppTag", defCppTag).toString();
			txtTag = settings.value("txtTag", defTxtTag).toString();
			jsTag = settings.value("jsTag", defJsTag).toString();
			tsTag = settings.value("tsTag", defTsTag).toString();
			HTMLTag = settings.value("HTMTag", defHTMLTag).toString();
			goTag = settings.value("goTag", defGoTag).toString();
			luaTag = settings.value("luaTag", defLuaTag).toString();
			csharpTag = settings.value("csharpTag", defCsharpTag).toString();
			javaTag = settings.value("javaTag", defJavaTag).toString();
			cTag = settings.value("cTag", defCTag).toString();
		}
		if (compareVersionNumbers(existingVersion, "8.6.3") < 0){ // less than v863
			CppTag = defCppTag;
			cTag = defCTag;
		}

		pythonLSP = settings.value("pythonLSP", "").toString();
		rustLSP = settings.value("rustLSP", "").toString();
		WGSLLSP = settings.value("WGSLLSP", "").toString();
		GLSLLSP = settings.value("GLSLLSP", "").toString();
		CppLSP = settings.value("CppLSP", "").toString();
		txtLSP = settings.value("txtLSP", "").toString();
		jsLSP = settings.value("jsLSP", "").toString();
		tsLSP = settings.value("tsLSP", "").toString();
		HTMLLSP = settings.value("HTMLLSP", "").toString();
		goLSP = settings.value("goLSP", "").toString();
		luaLSP = settings.value("luaLSP", "").toString();
		csharpLSP = settings.value("csharpLSP", "").toString();
		javaLSP = settings.value("javaLSP", "").toString();
		cLSP = settings.value("cLSP", "").toString();

		groqApiKey = settings.value("groqApiKey", "").toString();
		groq->setApiKey(groqApiKey);

		QString numbers = settings.value("syntaxColors", defaultSyntaxNumbers).toString();

		if (numbers == "38,175,199|38,143,199|50,168,160|222,123,2|41,171,47|217,159,0|160,160,160|245,120,66"){
			numbers = defaultSyntaxNumbers;
		}else if (numbers.count("|") != 7){
			numbers = defaultSyntaxNumbers;
		}

		setFormatsFromMyList(numbers);

		showWarnings->setChecked(settings.value("showWarnings", true).toBool());
		showErrors->setChecked(settings.value("showErrors", true).toBool());
		showOther->setChecked(settings.value("showOther", true).toBool());
		onlyCodeWizardBuiltIn->setChecked(settings.value("onlyCodeWizardBuiltIn", false).toBool());
		noAutocomplete->setChecked(settings.value("noAutocomplete", false).toBool());
		hoverAction->setChecked(settings.value("hoverAction", true).toBool());
		useVimMode->setChecked(settings.value("vimMode", false).toBool());
		useBuiltinTerminal->setChecked(settings.value("builtinTerminal", false).toBool());
		preferHorizontalTerminal->setChecked(settings.value("preferHorizontalTerminal", false).toBool());
		autoAddBrackets->setChecked(settings.value("autoAddBrackets", false).toBool());
		autoSaveAct->setChecked(settings.value("autoSaveAct", true).toBool());
		useFileTree->setChecked(settings.value("useFileTree", false).toBool());
		useFileTreeIfFullscreen->setChecked(settings.value("useFileTreeIfFullscreen", true).toBool());

		bool defaultRandomSelect = false;
		QString name = qgetenv("USER"); // this env is LINUX - might as well right?
		if (name.isEmpty()){
			name = qgetenv("USERNAME"); // this env is WINDOWS
		}

		if (name.toLower() == "kaihe"){ // just for you kai
			defaultRandomSelect = true;
		}

		splitWidths[0] = settings.value("splitWidths0", 0.25f).toDouble();
		splitWidths[1] = settings.value("splitWidths1", 0.25f).toDouble();
		splitWidths[2] = settings.value("splitWidths2", 0.25f).toDouble();
		updateTermimalViews(); // also calls the update for the splitWidths.

		randomSelectFileTypeAct->setChecked(settings.value("randomSelectFileTypeAct", defaultRandomSelect).toBool());
		useSpeakerAction->setChecked(settings.value("useSpeakerAction", false).toBool());

		recentFiles = settings.value("recentFiles", {}).toStringList();
		updateRecentList(recentFiles);

		fontSize = settings.value("fontSize", 11.0).toFloat();
		if (fontSize <= 0){
			fontSize = 11.0;
		}
		currentFont = settings.value("currentFont", "Source Code Pro").toString();
		tabWidth = settings.value("tabWidth", 4).toInt();
		return settings.value("darkModeEnabled", false).toBool(); // Default to false if not found
	}else{
		#ifdef _WIN32
			QSettings settings("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize", QSettings::NativeFormat);
			return settings.value("AppsUseLightTheme").toInt() == 0;
		#else
			QProcess process;
			process.start("gsettings get org.gnome.desktop.interface gtk-theme");
			process.waitForFinished();
			QString output = process.readAllStandardOutput().trimmed();
			return output.contains("dark", Qt::CaseInsensitive);
		#endif
	}
}

void MainWindow::on_actionSet_Font_By_Name_triggered(){
	// Cascadia Code

	QInputDialog dialog;
	dialog.setFont(textEdit->font());  // Set the font to match textEdit's font
	dialog.setWindowTitle("CodeWizard - Font Selection");
	dialog.setLabelText("Font to use?");
	dialog.setTextValue(currentFont);  // Default text value can be an empty string
	dialog.setTextEchoMode(QLineEdit::Normal);  // You can change this to Password if needed
	dialog.exec();

	if (dialog.result() != QDialog::Accepted) {
		return;
	}

	currentFont = dialog.textValue();
	updateFontSelection();
}

void MainWindow::on_actionSet_Groq_AI_API_Key_triggered(){
	QInputDialog dialog;
	dialog.setFont(textEdit->font());  // Set the font to match textEdit's font
	dialog.setWindowTitle("CodeWizard - AI");
	dialog.setLabelText("Groq API Key?");
	dialog.setTextValue(groqApiKey);  // Default text value can be an empty string
	dialog.setTextEchoMode(QLineEdit::Normal);  // You can change this to Password if needed
	dialog.exec();

	if (dialog.result() != QDialog::Accepted) {
		return;
	}

	groqApiKey = dialog.textValue();
	groq->setApiKey(groqApiKey);
	saveWantedTheme();
}

MainWindow::~MainWindow()
{
	qDebug() << "~MainWindow";

	QSettings settings("FoundationTechnologies", "CodeWizard");
	settings.setValue("wasFullScreened", (isFullScreen() || isMaximized()));

	lspMutex.lock();
	if (client){
		client->shutdown();
		delete client;
		client = nullptr;
	}
	lspMutex.unlock();

	if (unsaved && fileName != ""){
		pullUpSaveDialogue();
	}

	delete ui;
}

void MainWindow::updateScrollBarValue(int value)
{
//	qDebug() << "updateScrollBarValue";
	lineNumberTextEdit->verticalScrollBar()->setValue(value);
}

void MainWindow::updateScrollBarValue2(int value)
{
//	qDebug() << "updateScrollBarValue2";
	if (value <= textEdit->verticalScrollBar()->maximum()){
		textEdit->verticalScrollBar()->setValue(value);
	}else{
		lineNumberTextEdit->verticalScrollBar()->setValue(textEdit->verticalScrollBar()->maximum());
	}
}

void MainWindow::findTriggered()
{
	qDebug() << "findTriggered";

	QString text = textEdit->toPlainText();
	QTextCursor cursor = textEdit->textCursor();
	QString find = findTextEdit->toPlainText();

	if (find == ""){
		return;
	}

	int position = text.indexOf(find, 0, Qt::CaseInsensitive);
	if (position != -1)
	{
		cursor.setPosition(position);
		cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, find.length());
		textEdit->setTextCursor(cursor);
	}
}

void MainWindow::findTextEditChanged()
{
	qDebug() << "findTextEditChanged";

	disconnect(findTextEdit, &QTextEdit::textChanged, this, &MainWindow::findTextEditChanged);
	QTextCursor cursor = findTextEdit->textCursor();
	int cursorPosition = cursor.position();
	int currentAnchor = cursor.anchor();

	cursor.select(QTextCursor::Document); // i hate this bit
	QFont currentFont = findTextEdit->font();
	QTextCharFormat format;
	format.setFont(currentFont);
	cursor.mergeCharFormat(format);
	cursor.setPosition(cursorPosition);
	cursor.setPosition(currentAnchor, QTextCursor::KeepAnchor); // that's it you can look back now

	connect(findTextEdit, &QTextEdit::textChanged, this, &MainWindow::findTextEditChanged);
}

void MainWindow::previousTriggered()
{
	qDebug() << "previousTriggered";

	QString text = textEdit->toPlainText();
	QTextCursor cursor = textEdit->textCursor();
	QString find = findTextEdit->toPlainText();

	if (find.isEmpty()) {
		return;
	}

	int startPosition = cursor.position();
	int position = text.lastIndexOf(find, startPosition - find.length() - 1, Qt::CaseInsensitive);

	if (position == -1) {
		position = text.lastIndexOf(find, text.length() - 1, Qt::CaseInsensitive);
	}

	if (position != -1)
	{
		cursor.setPosition(position);
		cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, find.length());
		textEdit->setTextCursor(cursor);
	}
}

void MainWindow::nextTriggered()
{
	qDebug() << "nextTriggered";

	QString text = textEdit->toPlainText();
	QTextCursor cursor = textEdit->textCursor();
	QString find = findTextEdit->toPlainText();

	if (find == ""){
		return;
	}

	int startPosition = cursor.position();
	int position = text.indexOf(find, startPosition, Qt::CaseInsensitive);

	if (position == -1) {
		position = text.indexOf(find, 0, Qt::CaseInsensitive);
	}

	if (position != -1)
	{
		textEdit->horizontalScrollBar()->setValue(0);
		cursor.setPosition(position);
		cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, find.length());
		textEdit->setTextCursor(cursor);
	}
}

void MainWindow::replaceTriggered(){
	qDebug() << "replaceTriggered";

	QTextCursor cursor = textEdit->textCursor();
	QString selectedText = cursor.selectedText();
	QString find = findTextEdit->toPlainText();
	QString replace = replaceTextEdit->toPlainText();

	if (find == "" || selectedText == ""){
		return;
	}

	if (selectedText.compare(find, Qt::CaseInsensitive) == 0)
	{
		cursor.insertText(replace);
		textEdit->setTextCursor(cursor);
		nextTriggered();
	}
}

void MainWindow::replaceAllTriggered(){
	qDebug() << "replaceAllTriggered";

	QString find = findTextEdit->toPlainText();
	QString replace = replaceTextEdit->toPlainText();

	if (find.isEmpty()) {
		return;
	}

	QRegularExpression re(QRegularExpression::escape(find), QRegularExpression::CaseInsensitiveOption);
	QTextCursor docCursor(textDocument);

	docCursor = textDocument->find(re, docCursor);
	if (docCursor.isNull()) {
		return;
	}
	docCursor.beginEditBlock();
	docCursor.insertText(replace);

	while (!docCursor.isNull() && !docCursor.atEnd()) {
		auto c = textDocument->find(re, docCursor);

		if (c.isNull()){
			break;
		}

		docCursor.setPosition(c.position(), QTextCursor::MoveAnchor);
		docCursor.setPosition(c.anchor(), QTextCursor::KeepAnchor);

		docCursor.insertText(replace);
	}

	docCursor.endEditBlock();
}

void MainWindow::on_actionExit_triggered(){
	qDebug() << "on_actionExit_triggered";
	QApplication::quit();
}

void MainWindow::clearTSSyntaxHighlighting(){
	qDebug() << "clearTSSyntaxHighlighting";

	QTextBlock block = textEdit->document()->firstBlock();
	QTextCharFormat form = QTextCharFormat();
	form.setForeground(normalColor);

	while (block.isValid()){
		QTextLayout* layout = block.layout();

		if (!layout) {
			block = block.next();
			continue;
		}

		QTextLayout::FormatRange range;
		range.format = form;
		range.start = 0;
		range.length = block.length();

		QVector<QTextLayout::FormatRange> formats = layout->formats();
		formats.append(range);
		layout->setFormats(formats);

		block = block.next();
	}

	textDocument->markContentsDirty(0, textDocument->characterCount());
}

void MainWindow::setupSyntaxTreeOnOpen(QString code, bool doHighlight)
{
	qDebug() << "setupSyntaxTreeOnOpen";

	treeParserSyntaxHighlighter.colormap = currentLang.colorMapTS;

	if (currentLang.name == "Python"){
		ts_parser_set_language(parser, tree_sitter_python());
	}else if (currentLang.name == "Rust"){
		ts_parser_set_language(parser, tree_sitter_rust());
	}else if (currentLang.name == "WGSL"){
		ts_parser_set_language(parser, tree_sitter_wgsl());
	}else if (currentLang.name == "GLSL"){
		ts_parser_set_language(parser, tree_sitter_glsl());
	}else if (currentLang.name == "C++"){
		ts_parser_set_language(parser, tree_sitter_cpp());
	}else if (currentLang.name == "Txt"){
		tree = nullptr;
		clearTSSyntaxHighlighting();
		return;
	}else if (currentLang.name == "JS"){
		ts_parser_set_language(parser, tree_sitter_javascript());
	}else if (currentLang.name == "TS"){
		ts_parser_set_language(parser, tree_sitter_typescript());
	}else if (currentLang.name == "HTML"){
		ts_parser_set_language(parser, tree_sitter_html());
	}else if (currentLang.name == "Go"){
		ts_parser_set_language(parser, tree_sitter_go());
	}else if (currentLang.name == "Lua"){
		ts_parser_set_language(parser, tree_sitter_lua());
	}else if (currentLang.name == "C#"){
		ts_parser_set_language(parser, tree_sitter_c_sharp());
	}else if (currentLang.name == "Java"){
		ts_parser_set_language(parser, tree_sitter_java());
	}else if (currentLang.name == "C"){
		ts_parser_set_language(parser, tree_sitter_c());
	}

	QElapsedTimer timer;
	timer.start();
	QByteArray byteArray = code.toLatin1();
	const char* source_code = byteArray.constData();

	tree = ts_parser_parse_string(
		parser,
		nullptr,  // Optional: previous tree to update
		source_code,
		strlen(source_code)
	);

//	printTree(ts_tree_root_node(tree), 0);

	if (doHighlight){
		rehighlightFullDoc();
	}

	errMessages.clear();
	errStartC.clear();
	errStartL.clear();
	errEndC.clear();
	errEndL.clear();
	errSeverity.clear();
	errMenu.UpdateErrors(errStartL, errMessages, errSeverity);

	isErrorHighlighted = false;
}

void MainWindow::on_actionOpen_triggered(bool dontUpdateFileTree)
{
	qDebug() << "on_actionOpen_triggered";

	if (isSettingUpLSP){
		showWeDontFuckWithTheLSP();
		return;
	}

	if (isOpeningFile){
		showHoldYourHorses();
		return;
	}

	isOpeningFile = true;
	QString oldFile = fileName;

	if (unsaved && fileName != ""){
		pullUpSaveDialogue();
	}

	QString newFile = "";
	if (!globalArgFileName.isEmpty()){
		newFile = globalArgFileName;
		globalArgFileName = "";
	}else{
		newFile = QFileDialog::getOpenFileName(this, tr("Open File"), fileName, tr("All Files (*);"));
	}

	if (newFile.isEmpty()){
		isOpeningFile = false;
		return;
	}

	storedLineNumbers[newFile] = textEdit->verticalScrollBar()->value();

	if (useSpeakerAction->isChecked()){
		#ifdef _WIN32
			speech->say("Opening File");
		#endif
	}

	QFileInfo fileInfo(newFile);
	QFile file(newFile);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		QMessageBox newWarningBox;
		newWarningBox.setIcon(QMessageBox::Warning);
		newWarningBox.setText(tr("Cannot open file: %1").arg(file.errorString()));
		newWarningBox.setWindowTitle(tr("Error"));
		newWarningBox.setFont(textEdit->font());
		newWarningBox.exec();
		isOpeningFile = false;
		return;
	}

	bool ret = checkForLargeFile(&file);

	if (!ret){
		isOpeningFile = false;
		return;
	}

	fileName = newFile;

	setLangOffFilename(fileName, false);
	unsaved = false;
	QString fileNameName = fileInfo.fileName();

	windowName = "CodeWizard V"+versionNumber+" - "+fileNameName+" - "+fileName;

	QTextStream in(&file);
	QString fileContent = in.readAll();
	previousLineCount = 1;
	savedText = fileContent;

	setupSyntaxTreeOnOpen(fileContent); // must be before setPlainText - don't ask why - I could tell you though...

	highlightDiagnostics(true);

	textEdit->setPlainText(fileContent);
	toCompareTo = fileContent;
	previousLineCount = fileContent.count('\xa')+1;
	file.close();

	int cnt = fileContent.count('\n') + 1;
	updateLineNumbers(cnt);

	updateExtraWordsList();

	setWindowTitle(windowName);

	addFileToRecentList(fileName);

	if (!dontUpdateFileTree){
		fileModel->setRootPath(fileInfo.absolutePath());
		QSettings settings("FoundationTechnologies", "CodeWizard");
		settings.setValue("mostRecentFolder", fileInfo.absolutePath());

		fileTree->setRootIndex(fileModel->index(fileModel->rootPath()));
	}

	if (useFileTree->isChecked() || useFileTreeIfFullscreen->isChecked() && (isFullScreen() || isMaximized())){
		fileTree->show();
	}else{
		fileTree->hide();
	}

	auto it = storedLineNumbers.find(fileName);
	if (it != storedLineNumbers.end()) {
		textEdit->verticalScrollBar()->setValue(it->second);
	}

	lspMutex.lock();
	setupLSP(oldFile);
	lspMutex.unlock();

	updateMargins(true); // called on open - every time

	if (useSpeakerAction->isChecked()){
		#ifdef _WIN32
			speech->say("File Opened");
		#endif
	}

	isOpeningFile = false;

	checkForFixitDialogue();
}

void MainWindow::setLangOffFilename(QString fileName, bool rehigh){
	qDebug() << "setLangOffFilename";

	for (int i = 0; i < supportedLangs.size(); i++){
		for (int j = 0; j < supportedLangs[i].fileExtensions.size(); j++){
			if (fileName.endsWith(supportedLangs[i].fileExtensions[j], Qt::CaseInsensitive)){
				currentLang = supportedLangs[i];
				updateTagLine();
				updateDefaultWordLists();
				return;
			}
		}
	}

	if (isOpeningFile){
		currentLang = txtLang;
		lineEdit->setPlainText(txtTag);
	}else{
		currentLang = pythonLang;
		lineEdit->setPlainText(pythonTag);
	}
	updateDefaultWordLists();
}

void MainWindow::updateTagLine(){
	qDebug() << "updateTagLine";

	if (currentLang.name == "Python"){
		lineEdit->setPlainText(pythonTag);
	}else if (currentLang.name == "Rust"){
		lineEdit->setPlainText(rustTag);
	}else if (currentLang.name == "WGSL"){
		lineEdit->setPlainText(WGSLTag);
	}else if (currentLang.name == "GLSL"){
		lineEdit->setPlainText(GLSLTag);
	}else if (currentLang.name == "C++"){
		lineEdit->setPlainText(CppTag);
	}else if (currentLang.name == "Txt"){
		lineEdit->setPlainText(txtTag);
	}else if (currentLang.name == "JS"){
		lineEdit->setPlainText(jsTag);
	}else if (currentLang.name == "TS"){
		lineEdit->setPlainText(tsTag);
	}else if (currentLang.name == "HTML"){
		lineEdit->setPlainText(HTMLTag);
	}else if (currentLang.name == "Go"){
		lineEdit->setPlainText(goTag);
	}else if (currentLang.name == "Lua"){
		lineEdit->setPlainText(luaTag);
	}else if (currentLang.name == "C#"){
		lineEdit->setPlainText(csharpTag);
	}else if (currentLang.name == "Java"){
		lineEdit->setPlainText(javaTag);
	}else if (currentLang.name == "C"){
		lineEdit->setPlainText(cTag);
	}
}

void MainWindow::updateExtraWordsList(){
	qDebug() << "updateExtraWordsList";

	extraWordList.clear();

	QString text = textEdit->toPlainText();
	QSet<QChar> alphanumerical = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '_'};

	QSet<QString> uniqueExtraWords;
	QString word;

	for (int i = 0; i < text.length(); ++i) {
		QChar c = text.at(i);
		if (alphanumerical.contains(c.toLower())) {
			word += c;
		} else if (!word.isEmpty()) {
			if (word.length() > 2 && !wrdLstDefQSetted.contains(word)) {
				uniqueExtraWords.insert(word);
			}
			word.clear();
		}
	}

	if (!word.isEmpty() && word.length() > 2 && !wrdLstDefQSetted.contains(word)) {
		uniqueExtraWords.insert(word);
	}

	extraWordList = QStringList(uniqueExtraWords.begin(), uniqueExtraWords.end()); // Convert set to list
}

void MainWindow::pullUpSaveDialogue()
{
	qDebug() << "pullUpSaveDialogue";

	if (handlingReopen){return;}

	if (autoSaveAct->isChecked()){
		on_actionSave_triggered();
		return;
	}

	if (useSpeakerAction->isChecked()){
		#ifdef _WIN32
			speech->say("Save File?");
		#endif
	}

	QMessageBox dialog;
	dialog.setWindowTitle("Save");
	dialog.setText("Save file?");
	dialog.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	dialog.setDefaultButton(QMessageBox::Yes);
	dialog.setFont(textEdit->font());

	int response = dialog.exec();
	if (response == QMessageBox::Yes) {
		on_actionSave_triggered();
	}
}

void MainWindow::on_actionNew_triggered()
{
	qDebug() << "on_actionNew_triggered";

	if (unsaved && fileName != ""){
		pullUpSaveDialogue();
	}

	if (isSettingUpLSP || isOpeningFile){
		return;
	}

	lspMutex.lock();
	if (client){
		client->shutdown();
		delete client;
		client = nullptr;
	}
	lspMutex.unlock();

	savedText = "";
	highlightDiagnostics(true);
	textEdit->setPlainText("");
	windowName = defWindowTitle;
	setWindowTitle(windowName);
	fileName = "";
	previousLineCount = 1;

	int cnt = 1;
	updateLineNumbers(cnt);
}

void saveToFile(QString text)
{
	qDebug() << "saveToFile";

	if (fileName.isEmpty()) {
		qWarning() << "Error: File name is empty.";
		return;
	}

	QFile file(fileName);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
		qWarning() << "Error: Unable to open file" << fileName << "for writing."
				   << file.errorString();
		return;
	}

	QTextStream out(&file);
	out << text;

	file.close();

	unsaved = false;
}

void MainWindow::on_actionRun_Module_F5_triggered()
{
	qDebug() << "on_actionRun_Module_F5_triggered";
	
	if (unsaved){
		on_actionSave_triggered();
	}
	
	builtinTerminalTextEdit->insertPlainText("\nRequesting process gracefully stop.");
	builtinTerminalTextEditHORZ->insertPlainText("\nRequesting process gracefully stop.");

	activeTerminal->terminate();
	if (!activeTerminal->waitForFinished(100)) {
		builtinTerminalTextEdit->insertPlainText("\nForcing process to terminate.");
		builtinTerminalTextEditHORZ->insertPlainText("\nForcing process to terminate.");
		activeTerminal->kill();
		activeTerminal->waitForFinished();
	}

	delete activeTerminal;

	builtinTerminalTextEdit->insertPlainText("\n\nHard Reset CodeWizard Builtin Terminal\n\n");
	builtinTerminalTextEditHORZ->insertPlainText("\n\nHard Reset CodeWizard Builtin Terminal\n\n");

	activeTerminal = new QProcess(this);
	activeTerminal->setProcessChannelMode(QProcess::MergedChannels);

	connect(activeTerminal, &QProcess::readyReadStandardOutput, this, &MainWindow::handleTerminalStdout);
	connect(activeTerminal, &QProcess::readyReadStandardError, this, &MainWindow::handleTerminalStdout);

	QProcess *process;

	if (!useBuiltinTerminal->isChecked()){
		process = new QProcess(this);

		QObject::connect(process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
						 [process](int exitCode, QProcess::ExitStatus exitStatus) {
							 process->deleteLater(); // Clean up the process object
						 });
	} else {
		if (preferHorizontalTerminal->isChecked()){
			terminalInputLineHORZ->setFocus();
		} else {
			terminalInputLine->setFocus();
		}
	}

	// Get the file information and path
	QFileInfo fileInfo(fileName);
	QString fileDir = fileInfo.absolutePath();
	QString fileNameName = fileInfo.fileName();

	// Create a temporary directory if not already present
	QString tmpDirPath = QStandardPaths::writableLocation(QStandardPaths::TempLocation) + "/CodeWizard";
	QDir tmpDir(tmpDirPath);
	if (!tmpDir.exists()) {
		tmpDir.mkpath(tmpDirPath);
	}

	#ifdef _WIN32
		// Define the batch file path for Windows
		QString batFilePath = tmpDirPath + "/run_script.bat";
	#else
		// Define the shell script path for Linux
		QString batFilePath = tmpDirPath + "/run_script.sh";
	#endif

	qDebug() << batFilePath;

	QString finalRun;
	QString intermediateTag;

	// Write the command to the batch or shell file
	QFile batFile(batFilePath);
	if (batFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
		QTextStream out(&batFile);

		// Write the necessary command based on the selected language
		if (currentLang.name == "Python") {
			intermediateTag = pythonTag;
		} else if (currentLang.name == "Rust") {
			intermediateTag = rustTag;
		} else if (currentLang.name == "WGSL") {
			intermediateTag = WGSLTag;
		} else if (currentLang.name == "GLSL") {
			intermediateTag = GLSLTag;
		} else if (currentLang.name == "C++") {
			intermediateTag = CppTag;
		} else if (currentLang.name == "JS") {
			intermediateTag = jsTag;
		} else if (currentLang.name == "TS") {
			intermediateTag = tsTag;
		} else if (currentLang.name == "HTML") {
			intermediateTag = HTMLTag;
		} else if (currentLang.name == "Go") {
			intermediateTag = goTag;
		} else if (currentLang.name == "Txt") {
			intermediateTag = txtTag;
		} else if (currentLang.name == "Lua") {
			intermediateTag = luaTag;
		} else if (currentLang.name == "C#") {
			intermediateTag = csharpTag;
		} else if (currentLang.name == "Java") {
			intermediateTag = javaTag;
		} else if (currentLang.name == "C") {
			intermediateTag = cTag;
		}

		intermediateTag.replace("[filename]", fileNameName).replace("[filenameWoutExt]", fileNameName.split('.')[0]);

		#ifdef _WIN32
			out << "cd /d " << fileDir << "\n";
			out << intermediateTag;
		#else
			// For Linux, we use a shell script style command
			out << "#!bash\n";
			out << "cd " << fileDir << "\n";
			out << intermediateTag;
		#endif

		finalRun = intermediateTag;

		batFile.close();

		#ifndef _WIN32
			// Set execution permissions on Linux
			QFile::setPermissions(batFilePath, QFileDevice::ReadOwner | QFileDevice::WriteOwner | QFileDevice::ExeOwner);
		#endif
	}

	if (!useBuiltinTerminal->isChecked()){
		#ifdef _WIN32
			QStringList arguments;
			arguments << "/c" << "start" << "cmd" << "/k" << batFilePath;
			process->startDetached("cmd.exe", arguments);
		#else
			QStringList arguments;
			arguments << "-e" << "bash -c '" + batFilePath + "; exec bash'";
			process->startDetached("gnome-terminal -- bash -c 'bash "+batFilePath+"; exec bash'");
		#endif
	} else {
		#ifdef _WIN32
			activeTerminal->start("cmd.exe");
		#else
			activeTerminal->setEnvironment(QStringList() << "TERM=dumb");
			activeTerminal->start("bash", QStringList() << "--login" << "-i"); //<< "echo CodeWizard Builtin Terminal.");
		#endif

		QString moveD = "cd " + fileDir + "\n" + finalRun + "\n";
		activeTerminal->write(moveD.toUtf8());
	}
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
	qDebug() << "keyPressEvent";

	if(event->key() == Qt::Key_F5)
	{
		on_actionRun_Module_F5_triggered();
	}

	if(event->modifiers() & Qt::ControlModifier)
	{
		if (event->key() == Qt::Key_S){
			if (event->modifiers() & Qt::ShiftModifier) {
				on_actionSave_As_triggered();
			} else {
				on_actionSave_triggered();
			}
		}else if (event->key() == Qt::Key_O){
			on_actionOpen_triggered();
		}else if (event->key() == Qt::Key_B){
			if (isFullScreen() || isMaximized()){
				if (useFileTree->isChecked()){
					useFileTree->setChecked(false);
					useFileTreeIfFullscreen->setChecked(false);
				}else if (useFileTreeIfFullscreen->isChecked()){
					useFileTreeIfFullscreen->setChecked(false);
					return;
				}else{
					useFileTreeIfFullscreen->setChecked(true);
				}
			}else{
				useFileTree->toggle();
			}
		}else if(event->key() == Qt::Key_T){
			useBuiltinTerminal->toggle();
		}else if (event->key() == Qt::Key_N){
			on_actionNew_triggered();
		}else if (event->key() == Qt::Key_BracketLeft){
			on_actionDe_Increment_Ctrl_triggered();
		}else if (event->key() == Qt::Key_BracketRight){
			on_actionIncrement_Ctrl_triggered();
		}else if (event->key() == Qt::Key_Slash){
			on_actionToggleComments_triggered();
		}else if (event->key() == Qt::Key_F || event->key() == Qt::Key_H){
			changeFindSectionVisibility(true);
			openFind();
		}else if (event->key() == Qt::Key_P){
			on_actionReplay_Macro_triggered();
		}else if (event->key() == Qt::Key_Plus || event->key() == Qt::Key_Equal){
			on_actionIncrease_Text_Size_triggered();
		}else if (event->key() == Qt::Key_Minus || event->key() == Qt::Key_Underscore){
			on_actionDecrease_Text_Size_triggered();
		}
	}
}

void MainWindow::openFind()
{
	qDebug() << "openFind";

	disconnect(findTextEdit, &QTextEdit::textChanged, this, &MainWindow::findTextEditChanged);

	QString selectedText = textEdit->textCursor().selectedText();

	if (!selectedText.isEmpty()) {
		findTextEdit->setPlainText(selectedText);
	}

	//QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_A, Qt::ControlModifier);
	//QApplication::postEvent(findTextEdit, event);

	findTextEdit->setFocus();

	QFont currentFont = findTextEdit->font(); // Get the current font from the QTextEdit
	//I shouldn't have to do this. BUT when selecting with selectAll() or whatever it changes the font, but you can't see it in findTextEdit->font()... Whatever.
	QTextCursor cursor = findTextEdit->textCursor(); // Get the current cursor
	cursor.select(QTextCursor::Document); // Select all text in the document
	// Create a QTextCharFormat to set the new font
	QTextCharFormat format;
	format.setFont(currentFont); // Set the current font
	// Apply the new format to the selected text
	cursor.mergeCharFormat(format); // Merge the current font into the selection
	findTextEdit->setTextCursor(cursor); // Optional: Reset the cursor to the QTextEdit

	connect(findTextEdit, &QTextEdit::textChanged, this, &MainWindow::findTextEditChanged);
}

void removeOneTabAndAddChar(QString characterToAdd)
{
	qDebug() << "removeOneTabAndAddChar";

	QTextCursor cursor = textEdit->textCursor();

	cursor.movePosition(QTextCursor::Left, QTextCursor::KeepAnchor);

	if (cursor.selectedText() == "\t") {
		cursor.removeSelectedText();
	} else {
		cursor.movePosition(QTextCursor::Right);
	}

	cursor.insertText(characterToAdd);
	textEdit->setTextCursor(cursor);
}

void MainWindow::on_actionStart_Macro_Recording_triggered() {
	qDebug() << "on_actionStart_Macro_Recording_triggered";

	// Clear previous recordings and reset state
	recordedEvents.clear();
	recordedWidgets.clear();
	recordingMacro = true;
	recordMacroButton->setEnabled(false);
	endRecordMacroButton->setEnabled(true);
	replayMacroButton->setEnabled(false);
	if (useSpeakerAction->isChecked()){
		#ifdef _WIN32
			speech->say("Started Macro Recording");
		#endif
	}
	int margin = 15; // Margin from the top-right edge
	recordingLight->move(textEdit->width() - recordingLight->width() - margin, margin);
	recordingLight->raise();
	recordingLight->show();
	qDebug() << "Moved to: " << textEdit->width() - recordingLight->width() - margin;
}

void MainWindow::on_actionEnd_Macro_Recording_triggered() {
	qDebug() << "on_actionEnd_Macro_Recording_triggered";

	recordingMacro = false;
	recordMacroButton->setEnabled(true);
	endRecordMacroButton->setEnabled(false);
	replayMacroButton->setEnabled(true);
	if (useSpeakerAction->isChecked()){
		#ifdef _WIN32
			speech->say("Ended Macro Recording");
		#endif
	}

	recordingLight->hide();
}

void MainWindow::on_actionReplay_Macro_triggered() {
	qDebug() << "on_actionReplay_Macro_triggered";

	if (recordingMacro){
		return;
	}

	if (playingMacro){
		playingMacro = false;
		return;
	}

	recordMacroButton->setEnabled(false);
	endRecordMacroButton->setEnabled(false);
	replayMacroButton->setEnabled(true);

	playingMacro = true;

	QInputDialog dialog;
	dialog.setFont(textEdit->font());
	dialog.setWindowTitle("Macro");
	dialog.setLabelText("Repeat number (0 is end of file):");
	dialog.setIntValue(1);
	dialog.setIntMinimum(0);
	dialog.setIntMaximum(276447231);
	dialog.setIntStep(1);
	dialog.exec();

	int repeatTimes = 1;
	bool runUntilEOF = false;

	if (dialog.result() == QDialog::Accepted) {
		repeatTimes = dialog.intValue();
	}

	if (repeatTimes == 0){
		runUntilEOF = true;
	}

	textEdit->setFocus();

	int i = 0;
	while (true){
		if (!runUntilEOF && i >= repeatTimes || !playingMacro){
			break;
		}

		for (int j = 0; j < recordedEvents.size(); j++) {
			const QKeyEvent* keyEvent = std::as_const(recordedEvents)[j];
			QObject* object = recordedWidgets[j];

			QKeyEvent* replayedEvent = new QKeyEvent(
				keyEvent->type(),
				keyEvent->key(),
				keyEvent->modifiers(),
				keyEvent->text()
				);

			QCoreApplication::postEvent(object, replayedEvent);
			QCoreApplication::processEvents(QEventLoop::AllEvents, 1000);
		}
		i++;

		if(runUntilEOF){
			QCoreApplication::processEvents(QEventLoop::AllEvents, 1000);
			QTextCursor cursor = textEdit->textCursor(); // Get the current cursor
			int currentLine = cursor.blockNumber();      // Get the current block number (0-based)
			int totalLines = textDocument->blockCount(); // Get total number of blocks
			if (currentLine == totalLines - 1){
				break;
			}
		}
	}

	playingMacro = false;

	recordMacroButton->setEnabled(true);
	endRecordMacroButton->setEnabled(false);
	replayMacroButton->setEnabled(true);
}

void MainWindow::executeNormalAct(QTextCursor::MoveOperation move, QKeyEvent *key_event){
	if (vimRepeater == 0){
		vimRepeater = 1;
	}

	QTextCursor cursor = textEdit->textCursor();
	if (key_event->modifiers() && Qt::ShiftModifier){
		cursor.movePosition(move, QTextCursor::KeepAnchor, vimRepeater);
	}else{
		cursor.movePosition(move, QTextCursor::MoveAnchor, vimRepeater);
	}
	textEdit->setTextCursor(cursor);
	vimRepeater = 0;
}

int MainWindow::findMatchingBracket(int direction){
	qDebug() << "findMatchingBracket";

	int seen = 0;
	QTextCursor cursor = textEdit->textCursor();
	int initPos = cursor.position();
	int copyInitPos = cursor.position();

	QString opening = "{[(<";
	QString closing = "}])>";

	if (direction < 0){
		opening = "}])>";
		closing = "{[(<";
	}

	QString text = textEdit->toPlainText();

	int textLen = text.length();

	if (opening.contains(text.at(initPos-1))){
		initPos = initPos-1;
	}else{
		if (!opening.contains(text.at(initPos))){
			return initPos;
		}
	}

	QChar lookingFor = closing.at(opening.indexOf(text.at(initPos)));
	QChar had = text.at(initPos);

	int curPos = initPos + direction;

	while (true) {
		if (curPos < 0 || curPos >= textLen){
			break;
		}

		if (had == text.at(curPos)){
			seen += 1;
		}else if (lookingFor == text.at(curPos)){
			if (seen == 0){
				return curPos;
			}else{
				seen -= 1;
			}
		}

		curPos += direction;
	}

	return copyInitPos;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
//	qDebug() << "eventFilter"; - we don't do it for certain functions

	if (event->type()==QEvent::WindowStateChange){
		onWindowStateChanged();
	}

	if (watched == terminalInputLine || watched == terminalInputLineHORZ) {
		if (event->type() == QEvent::KeyPress){
			QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
			QKeySequence key_sequence{static_cast<int>(keyEvent->modifiers()) + keyEvent->key()};

			QTextCursor cursor;

			if (watched == terminalInputLine){
				cursor = terminalInputLine->textCursor();
			}else{
				cursor = terminalInputLineHORZ->textCursor();
			}

			QString selectedText = cursor.selectedText();

			if (key_sequence == QKeySequence("Ctrl+C") && selectedText.isEmpty()){
				activeTerminal->kill();
				activeTerminal->waitForFinished();

				activeTerminal = new QProcess(this);
				activeTerminal->setProcessChannelMode(QProcess::MergedChannels);

				connect(activeTerminal, &QProcess::readyReadStandardOutput, this, &MainWindow::handleTerminalStdout);
				connect(activeTerminal, &QProcess::readyReadStandardError, this, &MainWindow::handleTerminalStdout);

				QFileInfo fileInfo(fileName);
				QString fileDir = fileInfo.absolutePath();
				activeTerminal->setWorkingDirectory(fileDir);

				builtinTerminalTextEdit->insertPlainText("\n\n");
				builtinTerminalTextEditHORZ->insertPlainText("\n\n");
				#ifdef _WIN32
					activeTerminal->start("cmd.exe", QStringList() << "/k" << "echo CodeWizard Builtin Terminal.");
				#else
					activeTerminal->setEnvironment(QStringList() << "TERM=dumb");
					activeTerminal->start("bash", QStringList() << "--login" << "-i"); //<< "echo CodeWizard Builtin Terminal.");
					activeTerminal->write("echo CodeWizard Builtin Terminal.\n");
				#endif
			}

			if (keyEvent->key() == Qt::Key_Escape){
				textEdit->setFocus();
			}if (keyEvent->key() == Qt::Key_Up){
				indexInSentCommands += 1;
				QString toset;

				if (indexInSentCommands >= sentCommands.length()){
					indexInSentCommands = -1;
					toset = "";
				}else{
					toset = sentCommands[indexInSentCommands];
				}

				terminalInputLine->setText(toset);
				terminalInputLineHORZ->setText(toset);

				QTextCursor cursor = terminalInputLine->textCursor();
				QTextCursor cursor2 = terminalInputLineHORZ->textCursor();

				cursor.movePosition(QTextCursor::EndOfLine);
				cursor2.movePosition(QTextCursor::EndOfLine);

				terminalInputLine->setTextCursor(cursor);
				terminalInputLineHORZ->setTextCursor(cursor2);
			}if (keyEvent->key() == Qt::Key_Down){
				indexInSentCommands -= 1;
				QString toset;

				if (indexInSentCommands < -1){
					indexInSentCommands = sentCommands.length()-1;
				}

				if (indexInSentCommands == -1){
					toset = "";
				}else{
					toset = sentCommands[indexInSentCommands];
				}

				terminalInputLine->setText(toset);
				terminalInputLineHORZ->setText(toset);

				QTextCursor cursor = terminalInputLine->textCursor();
				QTextCursor cursor2 = terminalInputLineHORZ->textCursor();

				cursor.movePosition(QTextCursor::EndOfLine);
				cursor2.movePosition(QTextCursor::EndOfLine);

				terminalInputLine->setTextCursor(cursor);
				terminalInputLineHORZ->setTextCursor(cursor2);
			}

			if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter){
				QString lineToSend;

				if (watched == terminalInputLine){
					lineToSend = terminalInputLine->toPlainText() + "\n";
					if (sentCommands.length() == 0 || sentCommands.at(0) != terminalInputLine->toPlainText()){
						sentCommands.push_front(terminalInputLine->toPlainText());
					}
				}else{
					lineToSend = terminalInputLineHORZ->toPlainText() + "\n";
					if (sentCommands.length() == 0 || sentCommands.at(0) != terminalInputLineHORZ->toPlainText()){
						sentCommands.push_front(terminalInputLineHORZ->toPlainText());
					}
				}

				indexInSentCommands = -1;
				activeTerminal->write(lineToSend.toUtf8());
				builtinTerminalTextEdit->insertPlainText(lineToSend);
				builtinTerminalTextEditHORZ->insertPlainText(lineToSend);
				terminalInputLine->setPlainText("");
				terminalInputLineHORZ->setPlainText("");
				return true;
			}
		}
		return false;
	}

	if (recordingMacro && (event->type() == QEvent::KeyPress || event->type() == QEvent::KeyRelease)) {
		QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
		QKeySequence key_sequence{static_cast<int>(keyEvent->modifiers()) + keyEvent->key()};

		auto newEvent = new QKeyEvent(
			keyEvent->type(),      // Type of event (KeyPress/KeyRelease)
			keyEvent->key(),       // The key that was pressed
			keyEvent->modifiers(), // Any modifier keys (Shift, Ctrl, etc.)
			keyEvent->text()       // Text representation of the key
			);

		bool saved = false;

		if ((key_sequence == QKeySequence("Alt+Alt") || key_sequence == QKeySequence("Alt")) && event->type() == QEvent::KeyRelease && holdingAnEvent){
			recordedEvents.removeLast();
			recordedWidgets.removeLast();
			on_actionEnd_Macro_Recording_triggered();
			textEdit->setFocus();
			holdingAnEvent = false;
			return true;
		}else if ((key_sequence == QKeySequence("Alt+Alt") || key_sequence == QKeySequence("Alt")) && event->type() == QEvent::KeyPress){
			holdingAnEvent = true;
		}

		if ((key_sequence != QKeySequence("Alt") && key_sequence != QKeySequence("Alt+Alt"))){
			holdingAnEvent = false;
		}

		recordedEvents.append(newEvent);
		recordedWidgets.append(watched);
	}

	if (event->type() == QEvent::KeyPress || event->type() == QEvent::KeyRelease && !recordingMacro){
		QKeyEvent *key_event = dynamic_cast<QKeyEvent*>(event);
		QKeySequence key_sequence{static_cast<int>(key_event->modifiers()) + key_event->key()};

		if (event->type() == QEvent::KeyRelease && holdingAnEvent && (key_sequence == QKeySequence("Alt+Alt") || key_sequence == QKeySequence("Alt"))){
			on_actionStart_Macro_Recording_triggered();
			textEdit->setFocus();
			holdingAnEvent = false;
		}else if (event->type() == QEvent::KeyPress && !holdingAnEvent && (key_sequence == QKeySequence("Alt+Alt") || key_sequence == QKeySequence("Alt"))){
			holdingAnEvent = true;
		}

		if (key_sequence != QKeySequence("Alt+Alt") && key_sequence != QKeySequence("Alt")){
			holdingAnEvent = false;
		}
	}

	if( event->type() != QEvent::KeyPress){
		return false;
	}

	QKeyEvent *key_event = dynamic_cast<QKeyEvent*>(event);
	QKeySequence key_sequence{static_cast<int>(key_event->modifiers()) + key_event->key()};

	if (watched == textEdit){
		if (isSettingUpLSP || isOpeningFile){
			return false;
		}

		bool isACtrl = key_event->modifiers() & Qt::ControlModifier || key_event->modifiers() & Qt::AltModifier;

		if (!isACtrl && currentVimMode == "n"){
			QString keyText = key_event->text();

			if (keyText.length() == 1 && keyText[0].isDigit()){
				vimRepeater = vimRepeater*10 + keyText[0].digitValue();
			}

			if (key_event->key() == Qt::Key_I){
				currentVimMode = "i";
				textEdit->setCursorWidth(1);
				vimRepeater = 0;
			}else if (key_event->key() == Qt::Key_J || key_event->key() == Qt::Key_Down){
				executeNormalAct(QTextCursor::Down, key_event);
			}else if (key_event->key() == Qt::Key_K || key_event->key() == Qt::Key_Up){
				executeNormalAct(QTextCursor::Up, key_event);
			}else if (key_event->key() == Qt::Key_H || key_event->key() == Qt::Key_Left){
				executeNormalAct(QTextCursor::Left, key_event);
			}else if (key_event->key() == Qt::Key_L || key_event->key() == Qt::Key_Right){
				executeNormalAct(QTextCursor::Right, key_event);
			}else if (key_event->key() == Qt::Key_E){
				executeNormalAct(QTextCursor::WordRight, key_event);
			}else if (key_event->key() == Qt::Key_W){
				executeNormalAct(QTextCursor::WordLeft, key_event);
			}else if (key_event->key() == Qt::Key_Return){
				handleTabs();
				handleBracketsOnEnter();
				return false;
			}else if (key_event->key() == Qt::Key_Backspace || key_event->key() == Qt::Key_Home || key_event->key() == Qt::Key_End || key_event->key() == Qt::Key_PageUp || key_event->key() == Qt::Key_PageDown || key_event->key() == Qt::Key_F5){
				return false; // I am electing not to handle these in any special way - also CodeWizard for the win
			}else if (key_event->key() == Qt::Key_O){
				currentVimMode = "i";
				textEdit->setCursorWidth(1);
				vimRepeater = 0;
				executeNormalAct(QTextCursor::EndOfLine, key_event);
				QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Return, Qt::NoModifier, "");
				QCoreApplication::postEvent(textEdit, event);
			}else if (key_event->key() == Qt::Key_A){
				currentVimMode = "i";
				textEdit->setCursorWidth(1);
				vimRepeater = 0;
				executeNormalAct(QTextCursor::EndOfLine, key_event);
			}else if (key_event->key() == Qt::Key_Dollar || key_event->key() == Qt::Key_4 && key_event->modifiers() & Qt::ShiftModifier){
				vimRepeater = 0;
				executeNormalAct(QTextCursor::EndOfLine, new QKeyEvent(QEvent::KeyPress, Qt::Key_unknown, Qt::NoModifier));
			}else if (key_event->key() == Qt::Key_Less || key_event->key() == Qt::Key_Comma){
				QTextCursor cursor = textEdit->textCursor();
				int initLoc = cursor.position();
				int loc = findMatchingBracket(-1);
				if (initLoc != loc){
					cursor.setPosition(loc+1);
					textEdit->setTextCursor(cursor);
				}
			}else if (key_event->key() == Qt::Key_Greater || key_event->key() == Qt::Key_Period){
				int loc = findMatchingBracket(1);
				QTextCursor cursor = textEdit->textCursor();
				cursor.setPosition(loc);
				textEdit->setTextCursor(cursor);
			}

			return true; // always handle inputs in normal mode - normal is a strange term for this but whatever - it'll work.
		}

		if (isACtrl) {
			if (key_event->key() == Qt::Key_Less || key_event->key() == Qt::Key_Comma){
				QTextCursor cursor = textEdit->textCursor();
				int initLoc = cursor.position();
				int loc = findMatchingBracket(-1);
				if (initLoc != loc){
					cursor.setPosition(loc+1);
					textEdit->setTextCursor(cursor);
				}
			}else if (key_event->key() == Qt::Key_Greater || key_event->key() == Qt::Key_Period){
				int loc = findMatchingBracket(1);
				QTextCursor cursor = textEdit->textCursor();
				cursor.setPosition(loc);
				textEdit->setTextCursor(cursor);
			}
		}

		if (key_sequence == QKeySequence(".")){
			updateExtraWordsList();
		}else if (key_sequence == QKeySequence("(")){
			updateExtraWordsList();
		}else if (key_sequence == QKeySequence(";")){
			updateExtraWordsList();
		}else if (key_sequence == QKeySequence(" ")){
			updateExtraWordsList();
		}else if (key_sequence == QKeySequence("\t")){
			updateExtraWordsList();
		}

		if (client && !noAutocomplete->isChecked() && !onlyCodeWizardBuiltIn->isChecked()) {
			QString keyStr = key_sequence.toString(QKeySequence::NativeText);

			QString keyText = key_event->text();

			if (keyText.length() == 1) {
				QChar ch = keyText.at(0);
				if (ch.isLetterOrNumber() || client->triggerChars.contains(ch)) {
					expectedCompletionId = -1;
					callCompleteOponUpdate = true;
				}
			}
		}

		if (key_sequence == QKeySequence("Shift+Return")) {
			QKeyEvent *enterEvent = new QKeyEvent(QEvent::KeyPress, Qt::Key_Return, Qt::NoModifier);
			QApplication::postEvent(textEdit, enterEvent);
			return true; // Mark as handled
		}else if (key_sequence == QKeySequence("Alt+3")) {
			on_actionComment_Ctrl_Alt_triggered();
			return true; // Mark as handled
		}else if (key_sequence == QKeySequence("Alt+4")) {
			on_actionUn_Comment_Alt_5_triggered();
			return true; // Mark as handled
		}else if (QString("{[(<").contains(key_event->text()) && !isACtrl && (key_event->key() == Qt::Key_ParenLeft || key_event->key() == Qt::Key_BracketLeft || key_event->key() == Qt::Key_Less || key_event->key() == Qt::Key_BraceLeft)) {
			if (autoAddBrackets->isChecked()){
				updateSyntaxAdd = QString("}])>").at(QString("{[(<").indexOf(key_event->text()));
				updateSyntaxPosition = textEdit->textCursor().position()+1;
			}
		}else if (key_event->key() == Qt::Key_BraceRight && currentLang.closeIndents.contains("}")){
			removeOneTabAndAddChar("}");
			return true; // Mark as handled
		}else if (key_sequence == QKeySequence("Alt+Return")) {
			if (client){
				QTextCursor cursor = textEdit->textCursor();
				int line = cursor.blockNumber();
				int column = cursor.columnNumber();
				QTextCursor anchorCursor = cursor;
				anchorCursor.setPosition(cursor.anchor());
				int anchorLine = anchorCursor.blockNumber();
				int anchorColumn = anchorCursor.columnNumber();

				// Determine start and end positions
				int startLine, startColumn, endLine, endColumn;
				if (line < anchorLine || (line == anchorLine && column < anchorColumn)) {
					startLine = line;
					startColumn = column;
					endLine = anchorLine;
					endColumn = anchorColumn;
				} else {
					startLine = anchorLine;
					startColumn = anchorColumn;
					endLine = line;
					endColumn = column;
				}

				lspMutex.lock();
				client->requestActions(startLine, startColumn, endLine, endColumn);
				lspMutex.unlock();
				return true;
			}
		}else if (key_sequence == QKeySequence("Alt+A")) {
			QString textCopied = textEdit->toPlainText();
			QTextCursor c = textEdit->textCursor();
			int pos = c.position();
			textCopied.insert(pos, "[INSERT_CODE_HERE]");

			QList<QPair<QString, QString>> conversation = {
				{"user", "Please create just the code which should be inserted at the specified point (the specified point is '[INSERT_CODE_HERE]'). Do not include any other text with you response. Just pick up exactly where was left off. If there is no code which makes sense to insert at that point, just do your best to create code which could fit there, never include text other than the code in your response. Also your response should be plaintext, not markdown. Do not include the name of the language you are writing. ONLY the text to insert at that position. Here's the current code:\n\n"+textCopied}
			};
			groq->generateResponse(conversation);
			return true;
		}

		if (suggestionBox->isVisible() && !suggestion.isEmpty()) {
			if (key_event->key() == Qt::Key_Down) {
				currentSelection = (currentSelection + 1) % suggestion.length();
				fillSuggestions();
				return true; // Mark as handled
			} else if (key_event->key() == Qt::Key_Up) {
				currentSelection = (currentSelection - 1 + suggestion.length()) % suggestion.length();
				fillSuggestions();
				return true; // Mark as handled
			} else if (key_event->key() == Qt::Key_Escape) {
				suggestionBox->setVisible(false);
				return true; // Mark as handled
			}else if (key_event->key() == Qt::Key_Tab) {
				return insertCompletion();
			}
		}if (actionBox->isVisible() && !codeActions.isEmpty()) {
			if (key_event->key() == Qt::Key_Down) {
				currentSelectionAction = (currentSelectionAction + 1) % codeActions.count();
				fillActionsBox();
				return true; // Mark as handled
			} else if (key_event->key() == Qt::Key_Up) {
				currentSelectionAction = (currentSelectionAction - 1 + codeActions.count()) % codeActions.count();
				fillActionsBox();
				return true; // Mark as handled
			} else if (key_event->key() == Qt::Key_Escape) {
				actionBox->setVisible(false);
				return true; // Mark as handled
			}else if (key_event->key() == Qt::Key_Tab || key_event->key() == Qt::Key_Return) {
				return activateCodeAction();
			}
		}else{
			if (key_event->key() == Qt::Key_Down) {
				QTextCursor cursor = textEdit->textCursor();
				int initialPosition = cursor.position();
				if (key_event->modifiers() & Qt::ShiftModifier) {
					cursor.movePosition(QTextCursor::Down, QTextCursor::KeepAnchor);
				} else {
					cursor.movePosition(QTextCursor::Down);
				}
				if (cursor.position() == initialPosition) {
					if (key_event->modifiers() & Qt::ShiftModifier) {
						cursor.movePosition(QTextCursor::EndOfLine, QTextCursor::KeepAnchor);
					}else{
						cursor.movePosition(QTextCursor::EndOfLine);
					}
				}
				textEdit->setTextCursor(cursor);
				return true;
			} else if (key_event->key() == Qt::Key_Up) {
				QTextCursor cursor = textEdit->textCursor();
				int initialPosition = cursor.position();
				if (key_event->modifiers() & Qt::ShiftModifier) {
					cursor.movePosition(QTextCursor::Up, QTextCursor::KeepAnchor);
				} else {
					cursor.movePosition(QTextCursor::Up);
				}
				if (cursor.position() == initialPosition) {
					if (key_event->modifiers() & Qt::ShiftModifier) {
						cursor.movePosition(QTextCursor::StartOfLine, QTextCursor::KeepAnchor);
					}else{
						cursor.movePosition(QTextCursor::StartOfLine);
					}
				}
				textEdit->setTextCursor(cursor);
				return true;
			}
		}

		if(!suggestionBox->isVisible() && !actionBox->isVisible() && key_event->key() == Qt::Key_Escape){
			changeFindSectionVisibility(false);
			if (useVimMode->isChecked()){
				QFontMetrics metrics(textEdit->font());
				int charWidth = metrics.horizontalAdvance("M");
				textEdit->setCursorWidth(charWidth);
				currentVimMode = "n";
				vimRepeater = 0;
			}
		}

		if (key_sequence == QKeySequence("Return")) {
			handleTabs();
			handleBracketsOnEnter();
		}
	}else if (watched == findTextEdit || watched == replaceTextEdit) {
		if (key_event->key() == Qt::Key_Escape) {
			textEdit->setFocus();
			changeFindSectionVisibility(false);
			return true;
		}else if (key_sequence == QKeySequence("Shift+Return")){
			previousTriggered();
			return true;
		}else if (key_event->key() == Qt::Key_Return) {
			nextTriggered();
			return true;
		}
	}else if (watched == replaceTextEdit) {
		if (key_event->key() == Qt::Key_Escape) {
			textEdit->setFocus();
			return true;
		}
	}

	return false;
}

void MainWindow::on_actionOpen_Find_Menu_triggered(){
	changeFindSectionVisibility(true);
	openFind();
}

void MainWindow::changeFindSectionVisibility(bool visible){
	for (int i = 0; i < findLayout->count(); ++i) {
		QWidget* widget = findLayout->itemAt(i)->widget();
		auto* layoutItm = findLayout->itemAt(i)->layout();

		if (widget) {
			if (visible){
				widget->show();
			}else{
				widget->hide();
			}
		}

		if (layoutItm) {
			for (int j = 0; j < layoutItm->count(); ++j) {
				QWidget* widget2 = layoutItm->itemAt(j)->widget();

				if (widget2) {
					if (visible){
						widget2->show();
					}else{
						widget2->hide();
					}
				}
			}
		}
	}
}

QString MainWindow::convertLeadingSpacesToTabs(const QString& input) {
	qDebug() << "convertLeadingSpacesToTabs";

	// Split into lines
	QStringList lines = input.split('\n');

	// Process each line
	for (int i = 0; i < lines.size(); ++i) {
		QString& line = lines[i];
		int spaceCount = 0;

		// Count leading spaces
		for (QChar c : line) {
			if (c == ' ')
				spaceCount++;
			else
				break;
		}

		// Replace sets of 4 spaces with tabs
		if (spaceCount > 0) {
			int tabCount = spaceCount / 4;
			int remainingSpaces = spaceCount % 4;

			// Build the new line with tabs and remaining spaces
			QString newLine = QString(tabCount, '\t') +
							  QString(remainingSpaces, ' ') +
							  line.mid(spaceCount);

			lines[i] = newLine;
		}
	}

	// Join lines back together
	return lines.join('\n');
}

bool MainWindow::activateCodeAction()
{
	qDebug() << "activateCodeAction";

	QJsonArray arguments = codeActions[currentSelectionAction].toObject()["arguments"].toArray();

	if (!arguments.isEmpty()) {
		QJsonObject changes = arguments[0].toObject()["changes"].toObject();

		// A list to hold changes in a sortable way
		QList<QPair<double, QJsonObject>> changesList;

		// Iterate over the keys in the changes object (which are file paths, in this case)
		for (auto it = changes.begin(); it != changes.end(); ++it) {
			// Extract the changes for each file
			QJsonArray fileChanges = it.value().toArray();

			// Iterate over the changes for each file
			for (const QJsonValue& fileChange : fileChanges) {
				QJsonObject change = fileChange.toObject();
				QJsonObject range = change["range"].toObject();
				QJsonObject end = range["end"].toObject();

				// Extract line number from the start position
				double pos = (double)end["line"].toInt()+1.0 - 1.0/(double)end["character"].toInt();

				// Store each change with its corresponding line number
				changesList.append(qMakePair(pos, change));
			}
		}

		//Sort changes in descending order by line number
		std::sort(changesList.begin(), changesList.end(), [](const QPair<double, QJsonObject>& a, const QPair<double, QJsonObject>& b) {
			return a.first > b.first; // Sort by line number, descending
		});

		QTextCursor cursor = textEdit->textCursor();
		cursor.beginEditBlock();
		textEdit->blockSignals(true);

		// Apply the changes in sorted order
		for (const QPair<double, QJsonObject>& changePair : changesList) {
			QJsonObject change = changePair.second;
			QString newText = convertLeadingSpacesToTabs(change["newText"].toString());
			QJsonObject range = change["range"].toObject();
			QJsonObject start = range["start"].toObject();
			QJsonObject end = range["end"].toObject();

			// Extract line and character positions from the range
			int startLine = start["line"].toInt();
			int startCharacter = start["character"].toInt();
			int endLine = end["line"].toInt();
			int endCharacter = end["character"].toInt();

			cursor.setPosition(textDocument->findBlockByLineNumber(startLine).position() + startCharacter);
			cursor.setPosition(textDocument->findBlockByLineNumber(endLine).position() + endCharacter, QTextCursor::KeepAnchor);
			cursor.insertText(newText);
		}
		textEdit->blockSignals(false);
		cursor.endEditBlock(); // this goes after to ensure that the thing registers the change with the lsp

		return true;
	}

	QJsonArray changes = codeActions[currentSelectionAction].toObject()["edit"].toObject()["documentChanges"].toArray()[0].toObject()["edits"].toArray();

	if (!changes.empty()){
		QList<QPair<double, QJsonObject>> changesList;

		for (auto it = 0; it < changes.count(); ++it) {
			// Extract the changes for each file
			QJsonObject change = changes[it].toObject();
			QJsonObject range = change["range"].toObject();
			QJsonObject end = range["end"].toObject();

			// Extract line number from the start position
			double pos = (double)end["line"].toInt()+1.0 - 1.0/(double)end["character"].toInt();
			// Store each change with its corresponding line number
			changesList.append(qMakePair(pos, change));
		}

		//Sort changes in descending order by line number
		std::sort(changesList.begin(), changesList.end(), [](const QPair<double, QJsonObject>& a, const QPair<double, QJsonObject>& b) {
			return a.first > b.first; // Sort by line number, descending
		});

		QTextCursor cursor = textEdit->textCursor();
		cursor.beginEditBlock();
		textEdit->blockSignals(true);

		// Apply the changes in sorted order
		for (const QPair<double, QJsonObject>& changePair : changesList) {
			QJsonObject change = changePair.second;
			QString newText = convertLeadingSpacesToTabs(change["newText"].toString());
			QJsonObject range = change["range"].toObject();
			QJsonObject start = range["start"].toObject();
			QJsonObject end = range["end"].toObject();

			// Extract line and character positions from the range
			int startLine = start["line"].toInt();
			int startCharacter = start["character"].toInt();
			int endLine = end["line"].toInt();
			int endCharacter = end["character"].toInt();

			// Move the cursor to the start position
			cursor.setPosition(textDocument->findBlockByLineNumber(startLine).position() + startCharacter);

			// Select the range in the QTextEdit
			cursor.setPosition(textDocument->findBlockByLineNumber(endLine).position() + endCharacter, QTextCursor::KeepAnchor);

			// Replace the selected text with the new text
			cursor.insertText(newText);
		}

		cursor.endEditBlock();
		textEdit->blockSignals(false);

		return true;
	}

	return false;
}

bool MainWindow::insertCompletion()
{
	qDebug() << "insertCompletion";

	if (isSettingUpLSP || isOpeningFile){
		return false;
	}

	if (currentSelection < suggestion.length() && currentSelection != -1) {
		QString completion = suggestion[currentSelection];

		if (client) {
			QRegularExpression placeholderPattern(R"(\$\{\d+:[^\}]*\})");

			// Find all occurrences of the placeholder pattern
			QRegularExpressionMatchIterator matchIterator = placeholderPattern.globalMatch(completion);

			// Replace all occurrences with "$0"
			QString replacedCompletion = completion;
			while (matchIterator.hasNext()) {
				QRegularExpressionMatch match = matchIterator.next();
				replacedCompletion.replace(match.captured(0), "$0");
			}

			// Replace all but the first occurrence of "$0" with an empty string
			int firstIndex = replacedCompletion.indexOf("$0");
			if (firstIndex != -1) {
				int secondIndex = replacedCompletion.indexOf("$0", firstIndex + 1);
				while (secondIndex != -1) {
					replacedCompletion.replace(secondIndex, 2, ""); // Remove "$0"
					secondIndex = replacedCompletion.indexOf("$0", secondIndex + 1);
				}
			}

			if (replacedCompletion.contains("$1") && !replacedCompletion.contains("$0")){
				replacedCompletion.replace("$1", "$0");
			}

			completion = replacedCompletion; // Update the completion string
		}

		QString curWord = MainWindow::getCurrentWord();

		completion = completion.remove(0, curWord.length());

		if (completion.contains("\n")){
			QTextCursor cursor = textEdit->textCursor(); // Get the current cursor position
			cursor.movePosition(QTextCursor::EndOfLine);
			cursor.movePosition(QTextCursor::StartOfLine, QTextCursor::KeepAnchor);
			QString lineText = cursor.selectedText();

			QString tabs;
			QString lastRealChar;
			QString lastRealWord;
			QStringList lastPosWords;
			QStringList lines = completion.split("\n");
			std::tie(tabs, lastRealWord, lastRealChar, lastPosWords) = getTabDetails(lineText+lines[0]);

			if (currentLang.openIndents.contains(lastRealChar)){
				tabs += "\t";
			}else if (currentLang.closeIndents.contains(lastRealChar)){
				tabs.remove(0, 1);
			}

			lines[1] = tabs+lines[1];

			for (int i = 2; i < lines.length(); i++){
				std::tie(tabs, lastRealWord, lastRealChar, lastPosWords) = getTabDetails(lines[i-1]);
				if (currentLang.openIndents.contains(lastRealChar)){
					tabs += "\t";
				}else if (currentLang.closeIndents.contains(lastRealChar)){
					tabs.remove(0, 1);
				}

				lines[i] = tabs+lines[i];
			}

			std::tie(tabs, lastRealWord, lastRealChar, lastPosWords) = getTabDetails(lines[lines.length()-1]);
			if (currentLang.closeIndents.contains(lastRealChar)){
				lines[lines.length()-1].remove(0, 1);
			}

			completion = lines.join("\n");
		}

		QTextCursor cursor = textEdit->textCursor();

		int cursorPos = completion.indexOf("$0");

		int initPos = cursor.position();

		if (cursorPos != -1) {
			completion.remove(cursorPos, 2);  // Remove $0
		}

		callCompleteOponUpdate = true;

		cursor.insertText(completion);

		if (cursorPos != -1) {
			cursor.setPosition(initPos + cursorPos);  // Move cursor to the position where $0 was
		}

		textEdit->setTextCursor(cursor);

		// suggestion = {};
		return true;
	}
	return false;
}

void MainWindow::on_actionSave_triggered()
{
	qDebug() << "on_actionSave_triggered";

	if (isSettingUpLSP){
		showWeDontFuckWithTheLSP();
		return;
	}

	lspMutex.lock();
	if (!client){
		setupLSP("");
	}
	lspMutex.unlock();

	if (fileName.isEmpty()){
		fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("All Files (*);"));

		if (fileName.isEmpty()){
			return;
		}

		QFileInfo fileInfo(fileName);
		QString fileNameName = fileInfo.fileName();

		if (!fileNameName.contains('.')){
			if (randomSelectFileTypeAct->isChecked()){ // This is the silly thing which randomly selects c++ - nobody will ever use it but it's relatively easy to implement
				double value = QRandomGenerator::global()->generateDouble();
				if (value > 0.5){
					fileName += ".py";
				}else{
					fileName += ".cpp";
				}
			}else{
				fileName += ".py";
			}
		}

		setLangOffFilename(fileName, true);
		setupSyntaxTreeOnOpen(textEdit->toPlainText());
		onContentsChange(0, 0, 0);

		fileModel->setRootPath(fileInfo.absolutePath());
		QSettings settings("FoundationTechnologies", "CodeWizard");
		settings.setValue("mostRecentFolder", fileInfo.absolutePath());
		fileTree->setRootIndex(fileModel->index(fileModel->rootPath()));

		windowName = "CodeWizard V"+versionNumber+" - "+fileNameName+" - "+fileName;

		addFileToRecentList(fileName);

		updateMargins(true); // called on open - every time
	}
	saveToFile(textEdit->toPlainText());
	savedText = textEdit->toPlainText();
	setWindowTitle(windowName);

	lspMutex.lock();
	if (client){
		client->documentSaved(textEdit->toPlainText());
	}
	lspMutex.unlock();

	toCompareTo = textEdit->toPlainText();
}

void MainWindow::centerCursor() {
	qDebug() << "centerCursor";

	QTextCursor cursor = textEdit->textCursor();
	QRect cursorRect = textEdit->cursorRect(cursor);

	// Get the viewport dimensions
	QSize viewportSize = textEdit->viewport()->size();

	// Calculate the horizontal and vertical offsets
	int xOffset = cursorRect.center().x() - viewportSize.width() / 2;
	int yOffset = cursorRect.center().y() - viewportSize.height() / 2;

	// Scroll the QTextEdit to center the cursor
	QScrollBar* horizontalScrollBar = textEdit->horizontalScrollBar();
	QScrollBar* verticalScrollBar = textEdit->verticalScrollBar();

	horizontalScrollBar->setValue(horizontalScrollBar->value() + xOffset);
	verticalScrollBar->setValue(verticalScrollBar->value() + yOffset);
}

void MainWindow::on_actionIncrement_Ctrl_triggered()
{
	qDebug() << "on_actionIncrement_Ctrl_triggered";

	textEdit->blockSignals(true);
	QTextCursor cursor = textEdit->textCursor();
	int start;
	int end;
	int rawstart;
	int rawend;
	if (cursor.hasSelection()) {
		rawstart = cursor.selectionStart();
		rawend = cursor.selectionEnd();

		start = qMin(rawstart, rawend);
		end = qMax(rawstart, rawend);
	}else{
		rawstart = cursor.position();
		rawend = cursor.position();

		start = qMin(rawstart, rawend);
		end = qMax(rawstart, rawend);
	}

	cursor.setPosition(end);
	cursor.movePosition(QTextCursor::StartOfLine);
	int endLineLoc = cursor.position();

	cursor.setPosition(start);
	cursor.movePosition(QTextCursor::StartOfLine);
	int startLineLoc = cursor.position();

	cursor.setPosition(startLineLoc);

	int numOfLines = 1;

	if (startLineLoc == endLineLoc){
		numOfLines = 1;
	}else{
		while (true) {
			cursor.movePosition(QTextCursor::Down);
			numOfLines += 1;
			if (cursor.position() == endLineLoc){
				break;
			}
		}
	}

	cursor.beginEditBlock();
	cursor.setPosition(startLineLoc);
	for (int line = 0; line < numOfLines; line ++) {
		cursor.insertText("\t");
		cursor.movePosition(QTextCursor::PreviousCharacter);
		cursor.movePosition(QTextCursor::Down);
	}
	cursor.endEditBlock();

	updateSyntax();
	textEdit->blockSignals(false);
}

void MainWindow::on_actionDe_Increment_Ctrl_triggered()
{
	qDebug() << "on_actionDe_Increment_Ctrl_triggered";

	textEdit->blockSignals(true);
	QTextCursor cursor = textEdit->textCursor();
	int start;
	int end;
	int rawstart;
	int rawend;
	if (cursor.hasSelection()) {
		rawstart = cursor.selectionStart();
		rawend = cursor.selectionEnd();

		start = qMin(rawstart, rawend);
		end = qMax(rawstart, rawend);
	}else{
		rawstart = cursor.position();
		rawend = cursor.position();

		start = qMin(rawstart, rawend);
		end = qMax(rawstart, rawend);
	}

	cursor.setPosition(end);
	cursor.movePosition(QTextCursor::StartOfLine);
	int endLineLoc = cursor.position();

	cursor.setPosition(start);
	cursor.movePosition(QTextCursor::StartOfLine);
	int startLineLoc = cursor.position();

	cursor.setPosition(startLineLoc);

	int numOfLines = 1;

	if (startLineLoc == endLineLoc){
		numOfLines = 1;
	}else{
		while (true) {
			cursor.movePosition(QTextCursor::Down);
			numOfLines += 1;
			if (cursor.position() == endLineLoc){
				break;
			}
		}
	}

	cursor.beginEditBlock();
	cursor.setPosition(startLineLoc);
	for (int line = 0; line < numOfLines; line ++) {
		cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);
		if (cursor.selectedText() == "\t") {
			cursor.removeSelectedText();
		}else{
			cursor.movePosition(QTextCursor::PreviousCharacter);
		}

		cursor.movePosition(QTextCursor::Down);
	}
	cursor.endEditBlock();

	updateSyntax();
	textEdit->blockSignals(false);
}

void MainWindow::on_actionComment_Ctrl_Alt_triggered()
{
	qDebug() << "on_actionComment_Ctrl_Alt_triggered";

	if (currentLang.comments.length() == 0){
		return;
	}

	disconnect(textEdit, &QTextEdit::textChanged, this, &MainWindow::updateSyntax);
	QTextCursor cursor = textEdit->textCursor();
	cursor.beginEditBlock();

	int start;
	int end;
	int rawstart;
	int rawend;
	if (cursor.hasSelection()) {
		rawstart = cursor.selectionStart();
		rawend = cursor.selectionEnd();

		start = qMin(rawstart, rawend);
		end = qMax(rawstart, rawend);
	}else{
		rawstart = cursor.position();
		rawend = cursor.position();

		start = qMin(rawstart, rawend);
		end = qMax(rawstart, rawend);
	}

	cursor.setPosition(start);
	cursor.movePosition(QTextCursor::StartOfLine);
	int startlineloc = cursor.position();

	cursor.setPosition(end);

	cursor.movePosition(QTextCursor::StartOfLine);

	while (true) {
		if (cursor.position() == startlineloc){
			cursor.insertText(currentLang.comments[0]);
			break;
		}

		cursor.insertText(currentLang.comments[0]);

		cursor.movePosition(QTextCursor::Up);
		cursor.movePosition(QTextCursor::StartOfLine);
	}

	updateSyntax();
	cursor.endEditBlock();
	connect(textEdit, &QTextEdit::textChanged, this, &MainWindow::updateSyntax);
}

void MainWindow::on_actionToggleComments_triggered(){
	qDebug() << "on_actionToggleComments_triggered";

	if (currentLang.comments.length() == 0){
		return;
	}

	QTextCursor cursor = textEdit->textCursor();
	int start;
	int end;
	int rawstart;
	int rawend;
	if (cursor.hasSelection()) {
		rawstart = cursor.selectionStart();
		rawend = cursor.selectionEnd();

		start = qMin(rawstart, rawend);
		end = qMax(rawstart, rawend);
	}else{
		rawstart = cursor.position();
		rawend = cursor.position();

		start = qMin(rawstart, rawend);
		end = qMax(rawstart, rawend);
	}

	cursor.setPosition(start);
	cursor.movePosition(QTextCursor::StartOfLine);

	while (true){
		cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);
		if (cursor.selectedText() != " " && cursor.selectedText() != "\t"){
			cursor.movePosition(QTextCursor::PreviousCharacter);
			break;
		}
		cursor.clearSelection();
	}

	for (int i = 0; i < currentLang.comments[0].length(); i++){
		cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);
	}

	if (cursor.selectedText() == currentLang.comments[0]) {
		on_actionUn_Comment_Alt_5_triggered();
	}else{
		on_actionComment_Ctrl_Alt_triggered();
	}

}

void MainWindow::on_actionUn_Comment_Alt_5_triggered()
{
	qDebug() << "on_actionUn_Comment_Alt_5_triggered";

	if (currentLang.comments.length() == 0){
		return;
	}

	disconnect(textEdit, &QTextEdit::textChanged, this, &MainWindow::updateSyntax);
	QTextCursor cursor = textEdit->textCursor();
	cursor.beginEditBlock();

	int start;
	int end;
	int rawstart;
	int rawend;
	if (cursor.hasSelection()) {
		rawstart = cursor.selectionStart();
		rawend = cursor.selectionEnd();

		start = qMin(rawstart, rawend);
		end = qMax(rawstart, rawend);
	}else{
		rawstart = cursor.position();
		rawend = cursor.position();

		start = qMin(rawstart, rawend);
		end = qMax(rawstart, rawend);
	}

	cursor.setPosition(start);
	cursor.movePosition(QTextCursor::StartOfLine);
	int startlineloc = cursor.position();

	cursor.setPosition(end);

	cursor.movePosition(QTextCursor::StartOfLine);

	while (true) {
		if (cursor.position() == startlineloc){

			while (true){
				cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);
				if (cursor.selectedText() != " " && cursor.selectedText() != "\t"){
					cursor.movePosition(QTextCursor::PreviousCharacter);
					break;
				}
				cursor.clearSelection();
			}

			for (int i = 0; i < currentLang.comments[0].length(); i++){
				cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);
			}

			if (cursor.selectedText() == currentLang.comments[0]) {
				cursor.removeSelectedText();
				cursor.clearSelection();
				cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);
				if (cursor.selectedText() == " "){
					cursor.removeSelectedText();
				}
			}
			break;
		}

		while (true){
			cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);
			if (cursor.selectedText() != " " && cursor.selectedText() != "\t"){
				cursor.movePosition(QTextCursor::PreviousCharacter);
				break;
			}
			cursor.clearSelection();
		}

		for (int i = 0; i < currentLang.comments[0].length(); i++){
			cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);
		}

		if (cursor.selectedText() == currentLang.comments[0]) {
			cursor.removeSelectedText();
			cursor.clearSelection();
			cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);
			if (cursor.selectedText() == " "){
				cursor.removeSelectedText();
			}
		}else{
			for (int i = 0; i < currentLang.comments[0].length(); i++){
				cursor.movePosition(QTextCursor::PreviousCharacter, QTextCursor::KeepAnchor);
			}
		}
		cursor.movePosition(QTextCursor::Up);
		cursor.movePosition(QTextCursor::StartOfLine);
	}

	updateSyntax();
	cursor.endEditBlock();
	connect(textEdit, &QTextEdit::textChanged, this, &MainWindow::updateSyntax);
}

void MainWindow::on_actionDark_Mode_triggered()
{
	qDebug() << "on_actionDark_Mode_triggered";

	darkmode = true;
	changeTheme(darkmode);
	saveWantedTheme();
}

void MainWindow::on_actionLight_Mode_triggered()
{
	qDebug() << "on_actionLight_Mode_triggered";

	darkmode = false;
	changeTheme(darkmode);
	saveWantedTheme();
}

void MainWindow::on_actionTab_Width_triggered()
{
	qDebug() << "on_actionTab_Width_triggered";

	QInputDialog dialog;
	dialog.setFont(textEdit->font());
	dialog.setWindowTitle("Preferences");
	dialog.setLabelText("Width of tabs in spaces:");
	dialog.setIntValue(4);
	dialog.setIntMinimum(2);
	dialog.setIntMaximum(15);
	dialog.setIntStep(1);
	dialog.exec();

	if (dialog.result() == QDialog::Accepted) {
		tabWidth = dialog.intValue();
		saveWantedTheme();
		updateFonts();
	}
}

void MainWindow::on_actionSave_As_triggered()
{
	qDebug() << "on_actionSave_As_triggered";

	if (isSettingUpLSP){
		showWeDontFuckWithTheLSP();
		return;
	}

	QString oldFile = fileName;

	QString newFile = QFileDialog::getSaveFileName(this, tr("Save File"), fileName, tr("All Files (*);"));
	if (newFile != ""){
		fileName = newFile;
	}else{
		return;
	}

	QFileInfo fileInfo(fileName);
	QString fileNameName = fileInfo.fileName();

	if (!fileNameName.contains('.')){
		if (randomSelectFileTypeAct->isChecked()){ // This is the silly thing which randomly selects c++ - nobody will ever use it but it's relatively easy to implement
			double value = QRandomGenerator::global()->generateDouble();
			if (value > 0.5){
				fileName += ".py";
			}else{
				fileName += ".cpp";
			}
		}else{
			fileName += ".py";
		}
	}

	setLangOffFilename(fileName, true);
	setupSyntaxTreeOnOpen(textEdit->toPlainText());
	onContentsChange(0, 0, 0);
	addFileToRecentList(fileName);

	fileModel->setRootPath(fileInfo.absolutePath());
	QSettings settings("FoundationTechnologies", "CodeWizard");
	settings.setValue("mostRecentFolder", fileInfo.absolutePath());
	fileTree->setRootIndex(fileModel->index(fileModel->rootPath()));

	windowName = "CodeWizard V"+versionNumber+" - " + fileNameName + " - " + fileName;
	setWindowTitle(windowName);
	saveToFile(textEdit->toPlainText());
	savedText = textEdit->toPlainText();

	lspMutex.lock();
	setupLSP(oldFile);
	lspMutex.unlock();

	updateMargins(true); // called on open - every time
}

void MainWindow::on_actionFix_It_triggered(){ // THE FIX IT BUTTON
	qDebug() << "on_actionFix_It_triggered";

	disconnect(textEdit, &QTextEdit::textChanged, this, &MainWindow::updateSyntax);

	QString text = textEdit->toPlainText();

	QStringList parts = text.split('\xa');

	QInputDialog dialog;
	dialog.setFont(textEdit->font());  // Set the font to Arial, size 12
	dialog.setWindowTitle("FixIt");
	dialog.setLabelText("Number of spaces per indent level:");
	dialog.setIntValue(4);
	dialog.setIntMinimum(2);
	dialog.setIntMaximum(15);
	dialog.setIntStep(1);

	dialog.exec();

	int numOfIdentifiedSpaces = 4;

	if (dialog.result() == QDialog::Accepted) {
		numOfIdentifiedSpaces = dialog.intValue();
	} else {
		connect(textEdit, &QTextEdit::textChanged, this, &MainWindow::updateSyntax);
		return;
	}

	bool justSpaceDone = false;

	QStringList *newParts = new QStringList();

	for (int i = 0; i < parts.length(); i ++)
	{
		QString strChanged = parts[i];
		strChanged = strChanged.replace(" ", "").replace("\t", "");

		if (strChanged == ""){
			if (justSpaceDone){
				continue;
			}
			justSpaceDone = true;
		}else{
			justSpaceDone = false;
		}

		QString inPrt = parts[i];
		QString fixedPrt = "";
		bool doneExtra = false;

		for (int cIndex = 0; cIndex < inPrt.length(); cIndex++){
			if (doneExtra || inPrt[inPrt.length()-cIndex-1] != ' ' && inPrt[inPrt.length()-cIndex-1] != '\t'){
				fixedPrt = inPrt[inPrt.length()-cIndex-1] + fixedPrt;
				doneExtra = true;
			}
		}

		QString fixedPrt2 = "";
		bool doneIndentation = false;
		int numOfSpaces = 0;

		for (int cIndex = 0; cIndex < fixedPrt.length(); cIndex++){
			if (doneIndentation)
			{
				fixedPrt2 += fixedPrt[cIndex];
			}else{
				if (fixedPrt[cIndex] == ' '){
					numOfSpaces += 1;
				}else if(fixedPrt[cIndex] == '\t'){
					numOfSpaces = 0;
					fixedPrt2 += '\t';
				}else{
					doneIndentation = true;
					for (int spcIndx = 0; spcIndx < numOfSpaces; spcIndx ++){
						fixedPrt2 += ' ';
					}
					fixedPrt2 += fixedPrt[cIndex];
				}
				if (numOfSpaces == numOfIdentifiedSpaces){
					numOfSpaces = 0;
					fixedPrt2 += '\t';
				}
			}

		}

		newParts->append(fixedPrt2);
	}

	text = newParts->join('\xa');

	QTextCursor cursor = textEdit->textCursor();
	cursor.beginEditBlock();
	cursor.select(QTextCursor::Document); // Select the entire document
	cursor.removeSelectedText();         // Clear the selection
	cursor.insertText(text);          // Insert new text
	cursor.endEditBlock();

	//textEdit->setPlainText(text);

	updateSyntax();

	connect(textEdit, &QTextEdit::textChanged, this, &MainWindow::updateSyntax);
}

void MainWindow::on_actionChange_to_IDLE_format_triggered(){
	qDebug() << "on_actionChange_to_IDLE_format_triggered";

	disconnect(textEdit, &QTextEdit::textChanged, this, &MainWindow::updateSyntax);

	QString text = textEdit->toPlainText();

	QStringList parts = text.split('\xa');

	QInputDialog dialog;
	dialog.setFont(textEdit->font());  // Set the font to Arial, size 12
	dialog.setWindowTitle("FixIt");
	dialog.setLabelText("Number of spaces per indent level:");
	dialog.setIntValue(4);
	dialog.setIntMinimum(2);
	dialog.setIntMaximum(15);
	dialog.setIntStep(1);

	dialog.exec();

	int numOfIdentifiedSpaces = 4;

	if (dialog.result() == QDialog::Accepted) {
		numOfIdentifiedSpaces = dialog.intValue();
	} else {
		connect(textEdit, &QTextEdit::textChanged, this, &MainWindow::updateSyntax);
		return;
	}

	QString spaceIndnt = "";

	for (int i = 0; i < numOfIdentifiedSpaces; i++){
		spaceIndnt += " ";
	}

	QStringList *newParts = new QStringList();

	for (int i = 0; i < parts.length(); i ++)
	{
		QString strChanged = parts[i];
		strChanged = strChanged.replace(" ", "").replace("\t", "");

		QString inPrt = parts[i];
		QString fixedPrt = "";
		bool doneTabs = false;

		for (int cIndex = 0; cIndex < inPrt.length(); cIndex++){
			if (inPrt[cIndex] == '\t' && !doneTabs){

				fixedPrt += spaceIndnt;
			}else{
				doneTabs = true;
				fixedPrt += inPrt[cIndex];
			}
		}

		newParts->append(fixedPrt);
	}

	text = newParts->join('\xa');

	QTextCursor cursor = textEdit->textCursor();
	cursor.beginEditBlock();
	cursor.select(QTextCursor::Document); // Select the entire document
	cursor.removeSelectedText();         // Clear the selection
	cursor.insertText(text);          // Insert new text
	cursor.endEditBlock();

	connect(textEdit, &QTextEdit::textChanged, this, &MainWindow::updateSyntax);

	updateSyntax();
}

void MainWindow::highlightComparisons()
{
	qDebug() << "highlightComparisons";

	QTextBlock block = lineNumberTextEdit->document()->firstBlock();

	int ln = QString::number(globalLineCount).length()+2;

	while (block.isValid()) {
		QTextLayout* layout = block.layout();
		if (!layout) {
			continue;
		}

		QString blockText = block.text();

		QTextLayout::FormatRange range;

		if (blockText.endsWith("+")){
			range.format = compFormats[0];
		}else if (blockText.endsWith("-")){
			range.format = compFormats[1];
		}else if (blockText.endsWith("=")){
			range.format = compFormats[2];
		}

		range.start = 0;
		range.length = ln;

		QVector<QTextLayout::FormatRange> formats = layout->formats();
		formats.append(range);
		layout->setFormats(formats);

		block = block.next();
	}

	lineNumberTextEdit->document()->markContentsDirty(0, textDocument->characterCount());
}

void MainWindow::highlightDiagnostics(bool reverseTheProcess) // this hurt to get right - don't touch a single line of this shit
{
	qDebug() << "highlightDiagnostics - reverse: " << reverseTheProcess;

	textEdit->blockSignals(true);

	QTextCursor blckcursor = textEdit->textCursor();

	int pos = blckcursor.position();

	if (reverseTheProcess){
		isErrorHighlighted = false;

		// Only clear blocks that were highlighted
		QTextBlock block = textDocument->begin();

		for (QTextBlock block : errHighlightedBlocks) {
			if (!block.isValid()){
				continue;
			}

			QTextLayout* layout = block.layout();

			if (!layout) {
				continue;
			}

			QTextLayout::FormatRange range;
			range.format = errorFormats[0];
			range.start = 0;
			range.length = block.length();

			QVector<QTextLayout::FormatRange> formats = layout->formats();

			formats.append(range);
			layout->setFormats(formats);
			textDocument->markContentsDirty(block.position() + range.start, range.length);
		}

		errHighlightedBlocks.clear();
	}else{
		QList<int> allowedSeverities;
		if (showErrors->isChecked()){
			allowedSeverities.append(1);
		}
		if (showWarnings->isChecked()){
			allowedSeverities.append(2);
		}
		if (showOther->isChecked()){
			allowedSeverities.append(3);
			allowedSeverities.append(4);
		}

		if (allowedSeverities.isEmpty()){
			textEdit->blockSignals(false);
			return;
		}

		int maxErrors = 40;

		for (int i = 0; i < errStartL.size(); ++i) {
			if (i >= maxErrors){
				break;
			}

			int startLine = errStartL[i];
			int endLine = errEndL[i];
			int startC = errStartC[i];
			int endC = errEndC[i];
			int severity = errSeverity[i];

			if (!allowedSeverities.contains(severity)){
				continue;
			}

			if (startLine == endLine && startC == endC){
				startC -= 1;
				if (startC < 0){
					startC = 0;
					endC += 1;
				}
			}

			QTextBlock block = textDocument->findBlockByNumber(startLine);

			// Process each block in the range
			for (int currentLine = startLine; currentLine <= endLine; ++currentLine) {
				if (!block.isValid()) {
					break;
				}

				QTextLayout* layout = block.layout();
				if (!layout) {
					continue;
				}

				errHighlightedBlocks.push_back(block);

				int blockLen = block.length();
				int blockPos = block.position();

				QTextLayout::FormatRange range;
				range.format = errorFormats[severity];

				if (currentLine == startLine) {
					range.start = startC;
					if (currentLine == endLine) {
						range.length = endC-startC;
					}else{
						range.length = blockLen-startC;
					}
				}else{
					range.start = 0;
					if (currentLine == endLine) {
						range.length = endC;
					}else{
						range.length = blockLen;
					}
				}

				QVector<QTextLayout::FormatRange> formats = layout->formats();
				formats.append(range);
				layout->setFormats(formats);
				textDocument->markContentsDirty(blockPos, blockLen);

				if (currentLine != endLine){
					block = block.next();
				}
			}
		}
	}

	blckcursor.setPosition(pos);

	textEdit->blockSignals(false);
}

void MainWindow::updateLineNumbers(int count) // good enough
{
	qDebug() << "updateLineNumbers";

	lineNumberTextEdit->blockSignals(true);

	int globalDigits = QString::number(globalLineCount).length();
	int countDigits = std::to_string(count).length();

	count += 1;

	globalLineCount = count - 1;

	if (globalDigits != countDigits) {
		updateFonts();
	}

	QStringList lineNumbers;

	for (int i = 1; i < count; ++i) {
		QString nm = QString::number(i);
		int spaces = countDigits-nm.length();

		lineNumbers << QString(spaces, ' ')+nm;
	}

	QString text = lineNumbers.join("\n") + QString(1000, '\n');

	lineNumberTextEdit->setPlainText(text);
	lineNumberTextEdit->blockSignals(false);
}

std::tuple<QString, QString, QString, QStringList> MainWindow::getTabDetails(QString lineText)
{
	qDebug() << "getTabDetails";

	bool doneIndentSection = false;
	QString tabs = "";
	QString lastRealChar = "";
	QString lastRealWord = "";
	QStringList lastPosWords = {};
	bool inComment = false;
	bool clearNext = false;
	int skip = 0;

	for (int cIndx = 0; cIndx < lineText.length(); cIndx++) {
		if (skip != 0){
			skip -= 1;
			continue;
		}

		QString nextChar = lineText[cIndx];

		for (QString commentStart : currentLang.comments){
			QString substring = lineText.mid(cIndx, commentStart.length());

			if (substring == commentStart){
				inComment = true;
				skip = commentStart.length();
				break;
			}
		}
		if (skip != 0){
			skip -= 1;
			continue;
		}

		if (!doneIndentSection && nextChar == "\t"){
			tabs += "\t";
		}else{
			doneIndentSection = true;
			if (inComment){
				break;
			}
		}

		if (nextChar != "\t" && nextChar != " ")
		{
			lastRealChar = nextChar;
			if (clearNext){
				clearNext = false;
				lastRealWord = "";
			}
			lastRealWord += nextChar;
		}else{
			lastPosWords << lastRealWord;
			clearNext = true;
		}
	}

	if (!lastRealWord.isEmpty()){
		lastPosWords << lastRealWord;
	}

	return std::make_tuple(tabs, lastRealWord, lastRealChar, lastPosWords);
}

void MainWindow::handleTabs()
{
	qDebug() << "handleTabs";

	QString text = textEdit->toPlainText();
	QTextCursor cursor = textEdit->textCursor();

	int cPos = cursor.position();
	cursor.clearSelection();
	cursor.movePosition(QTextCursor::StartOfLine, QTextCursor::KeepAnchor);
	QString lineText = cursor.selectedText();
	cursor.clearSelection();
	cursor.setPosition(cPos, QTextCursor::MoveAnchor);

	QString tabs;
	QString lastRealChar;
	QString lastRealWord;
	QStringList lastPosWords;
	std::tie(tabs, lastRealWord, lastRealChar, lastPosWords) = getTabDetails(lineText);

	if (currentLang.openIndents.contains(lastRealChar)){
		tabs += "\t";
	}else if (currentLang.name == "HTML"){
		bool htmlIndent = false;
		if (lastRealWord.length() >= 2){
			QString endBit = lastRealWord.mid(lastRealWord.length() - 2, 2);
			if (endBit == "->" or endBit == "/>"){
				htmlIndent = false;
			}else if (lastRealChar == ">" && !lastRealWord.contains("</")){
				htmlIndent = true;
			}
		}else if (lastRealChar == ">"){
			htmlIndent = true;
		}

		if (lastRealChar == "{" || htmlIndent){
			tabs += "\t";
		}
	}

	QString alphanumericals = "abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ;";

	QString realRealLastWord = "";

	for (QString word : lastPosWords){
		realRealLastWord = "";

		std::reverse(word.begin(), word.end());

		for (QChar i : word){
			if (!alphanumericals.contains(i)){
				break;
			}
			realRealLastWord += i;
		}

		std::reverse(realRealLastWord.begin(), realRealLastWord.end());

		if (currentLang.closeIndentsWords.contains(realRealLastWord)){
			if (tabs.length() > 0){
				tabs.chop(1);
				break;
			}
		}
	}

	if (tabs != ""){
		updateSyntaxAdd = tabs;
	}
}

void MainWindow::handleBracketsOnEnter(){
	QTextCursor cursor = textEdit->textCursor();
	cursor.movePosition(QTextCursor::Left, QTextCursor::MoveAnchor);
	cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, 2);
	QString selectedText = cursor.selectedText();
	if (selectedText == "{}" || selectedText == "()" || selectedText == "[]" || selectedText == "<>"){
		QString nextLine = updateSyntaxAdd;
		if (!nextLine.isEmpty() && currentLang.openIndents.contains(selectedText.at(0))){
			nextLine.remove(0, 1);
		}else{
			updateSyntaxAdd += "\t";
		}
		updateSyntaxPosition = cursor.position()+updateSyntaxAdd.length();
		updateSyntaxAdd += "\n"+nextLine;
	}
}

void MainWindow::updateSyntax()
{
	qDebug() << "updateSyntax";

	if (isSettingUpLSP || isOpeningFile){
		return;
	}

	disconnect(textEdit, &QTextEdit::textChanged, this, &MainWindow::updateSyntax);

	int vScrollVal = textEdit->verticalScrollBar()->value();
	int hScrollVal = textEdit->horizontalScrollBar()->value();

	QTextCursor cursor = textEdit->textCursor();

	lspMutex.lock();
	if (client){
		QString text = textEdit->toPlainText();
		client->updateDocument(text);
		if (callCompleteOponUpdate){
			callCompleteOponUpdate = false;
			int line = cursor.blockNumber();
			int column = cursor.columnNumber();
			expectedCompletionId = client->requestCompletion(line, column);
			ShowSuggestionsWithSuperSet(suggestion);
		}
	}
	lspMutex.unlock();

	if (updateSyntaxAdd != "") {
		cursor.beginEditBlock();
		cursor.insertText(updateSyntaxAdd);
		cursor.endEditBlock();
		updateSyntaxAdd = "";
	}

	if (updateSyntaxPosition != -1){
		cursor.setPosition(updateSyntaxPosition);
		updateSyntaxPosition = -1;
		textEdit->setTextCursor(cursor);
	}

	int lineCount = textDocument->blockCount();

	if (lineCount != previousLineCount){
		updateLineNumbers(lineCount);
		updateExtraWordsList();
	}

	textEdit->verticalScrollBar()->setValue(vScrollVal);
	textEdit->horizontalScrollBar()->setValue(hScrollVal);

	previousLineCount = lineCount;

	connect(textEdit, &QTextEdit::textChanged, this, &MainWindow::updateSyntax);
}

void MainWindow::changeHighlightColors(bool darkmode){
	qDebug() << "changeHighlightColors";

	QPalette lightPalette = qApp->palette();

	if (darkmode){
		lightPalette.setColor(QPalette::Inactive, QPalette::Highlight, QColor("#FFFFFF"));
		lightPalette.setColor(QPalette::Inactive, QPalette::HighlightedText, QColor("#000000"));
		lightPalette.setColor(QPalette::Active, QPalette::Highlight, QColor("#FFFFFF"));
		lightPalette.setColor(QPalette::Active, QPalette::HighlightedText, QColor("#000000"));
	}else{
		lightPalette.setColor(QPalette::Inactive, QPalette::Highlight, QColor("#000000"));
		lightPalette.setColor(QPalette::Inactive, QPalette::HighlightedText, QColor("#FFFFFF"));
		lightPalette.setColor(QPalette::Active, QPalette::Highlight, QColor("#000000"));
		lightPalette.setColor(QPalette::Active, QPalette::HighlightedText, QColor("#FFFFFF"));
	}

	qApp->setPalette(lightPalette);
}

void MainWindow::changeOnlyEditsTheme(bool darkmode){
	qDebug() << "changeOnlyEditsTheme";

	QColor color1;
	QColor color2;

	if (darkmode){
		color1 = QColor(23, 23, 23);
		color2 = QColor(32, 32, 32);
	} else {
		color1 = QColor(230, 230, 230);
		color2 = QColor(245, 245, 245);
	}
	
	errMenu.recolor(color2);

	QPalette palette = textEdit->palette();
	palette.setColor(QPalette::Base, color1);
	textEdit->setPalette(palette);

	palette = lineNumberTextEdit->palette();
	palette.setColor(QPalette::Base, color2);
	lineNumberTextEdit->setPalette(palette);

	palette = hoverBox->palette();
	palette.setColor(QPalette::Base, color2);
	hoverBox->setPalette(palette);

	palette = actionBox->palette();
	palette.setColor(QPalette::Base, color2);
	actionBox->setPalette(palette);

	palette = suggestionBox->palette();
	palette.setColor(QPalette::Base, color2);
	suggestionBox->setPalette(palette);

	palette = fileTree->palette();
	palette.setColor(QPalette::Base, color2);
	fileTree->setPalette(palette);

	palette = replaceTextEdit->palette();
	palette.setColor(QPalette::Base, color2);
	replaceTextEdit->setPalette(palette);

	palette = builtinTerminalTextEdit->palette();
	palette.setColor(QPalette::Base, color2);
	builtinTerminalTextEdit->setPalette(palette);

	palette = terminalInputLine->palette();
	palette.setColor(QPalette::Base, color1);
	terminalInputLine->setPalette(palette);

	palette = builtinTerminalTextEditHORZ->palette();
	palette.setColor(QPalette::Base, color2);
	builtinTerminalTextEditHORZ->setPalette(palette);

	palette = terminalInputLineHORZ->palette();
	palette.setColor(QPalette::Base, color1);
	terminalInputLineHORZ->setPalette(palette);

	palette = findTextEdit->palette();
	palette.setColor(QPalette::Base, color2);
	findTextEdit->setPalette(palette);

	palette = lineEdit->palette();
	palette.setColor(QPalette::Base, color2);
	lineEdit->setPalette(palette);

	palette = findButton->palette();
	palette.setColor(QPalette::Button, color2);
	findButton->setPalette(palette);

	palette = replaceButton->palette();
	palette.setColor(QPalette::Button, color2);
	replaceButton->setPalette(palette);

	palette = replaceAllButton->palette();
	palette.setColor(QPalette::Button, color2);
	replaceAllButton->setPalette(palette);

	palette = nextButton->palette();
	palette.setColor(QPalette::Button, color2);
	nextButton->setPalette(palette);
}

void MainWindow::changeTheme(bool darkMode)
{
	qDebug() << "changeTheme";

	// Dark theme style
	QString contextMenuSheet = R"(
		QMenu {
			background-color: rgb(25, 25, 25);
			color: white;
			border: 1px solid rgb(45, 45, 45);
			border-radius: 8px;
			padding: 2px;
		}

		QMenu::item {
			background-color: transparent;
			color: white;
			padding: 3px 12px;
			margin: 1px 2px;
			border-radius: 4px;
		}

		QMenu::item:selected {
			background-color: rgb(45, 45, 45);
			color: white;
		}

		QMenu::separator {
			height: 1px;
			background-color: rgb(255, 255, 255);
			margin: 2px 4px;
		}
	)";

	// Light theme style
	QString contextMenuLightSheet = R"(
		QMenu {
			background-color: rgb(245, 245, 245);
			color: rgb(40, 40, 40);
			border: 1px solid rgb(220, 220, 220);
			border-radius: 8px;
			padding: 2px;
		}

		QMenu::item {
			background-color: transparent;
			color: rgb(40, 40, 40);
			padding: 3px 12px;
			margin: 1px 2px;
			border-radius: 4px;
		}

		QMenu::item:selected {
			background-color: rgb(230, 230, 230);
			color: rgb(0, 0, 0);
		}

		QMenu::separator {
			height: 1px;
			background-color: rgb(0, 0, 0);
			margin: 2px 4px;
		}
	)";

	if (windowsVersion == 11) {
		qApp->setStyle(QStyleFactory::create("Macintosh"));
	} else {
		// Use Fusion style on Windows 10
		qApp->setStyle(QStyleFactory::create("Fusion"));
	}

	if (darkMode) {
		// Optionally modify the palette for light mode
		QPalette lightPalette = qApp->palette();

		lightPalette.setColor(QPalette::Inactive, QPalette::Highlight, QColor("#FFFFFF"));
		lightPalette.setColor(QPalette::Inactive, QPalette::HighlightedText, QColor("#000000"));
		lightPalette.setColor(QPalette::Active, QPalette::Highlight, QColor("#FFFFFF"));
		lightPalette.setColor(QPalette::Active, QPalette::HighlightedText, QColor("#000000"));

		// Customize the palette as needed

		lightPalette.setColor(QPalette::Window, QColor(25, 25, 25));
		lightPalette.setColor(QPalette::WindowText, Qt::white);
		lightPalette.setColor(QPalette::Base, QColor(45, 45, 45));
		lightPalette.setColor(QPalette::ButtonText, Qt::white);
		lightPalette.setColor(QPalette::Text, Qt::white);
		lightPalette.setColor(QPalette::AlternateBase, QColor(30, 30, 30));
		lightPalette.setColor(QPalette::Button, QColor(45, 45, 45));
		lightPalette.setColor(QPalette::ToolTipBase, QColor(201, 201, 201));
		lightPalette.setColor(QPalette::Light, QColor(255, 255, 255));
		lightPalette.setColor(QPalette::Dark, QColor(100, 100, 100));

		QString menubarSheet = "QMenuBar {background-color: rgb(30, 30, 30); color: white; }"
							   "QMenu { background-color: rgb(20, 20, 20); color: white; }"
							   "QMenu::item:selected { background-color: rgb(45, 45, 45); color: white; }"
							   "QMenu::separator {height: 1px;background-color: rgb(255, 255, 255); margin: 2px 4px;}"
							   "QMenuBar::item { background-color: rgb(30, 30, 30); padding: 2px 4px; border-radius: 4px; margin: 3px 3px 2px 3px; }"
							   "QMenuBar::item:hover { background-color: rgb(70, 70, 70); }"
							   "QMenuBar::item:selected { background-color: rgb(70, 70, 70); }";

		ui->menuBar->setStyleSheet(menubarSheet);

		QString listWidgetSheet =
		   "QListWidget{ background-color: rgb(20, 20, 20); color: white; }"
		   "QListWidget::item:selected { background-color: rgb(45, 45, 45); color: white; }"
		   "QListWidget::separator {height: 1px;background-color: rgb(255, 255, 255); margin: 2px 4px;}"
		   "QListWidget::item { background-color: rgb(30, 30, 30); padding: 2px 2px; border-radius: 4px; margin: 3px 3px 2px 3px; }"
		   "QListWidget::item:hover { background-color: rgb(70, 70, 70); }";

		fontList->setStyleSheet(listWidgetSheet);

		QList<QMenu*> menus = ui->menuBar->findChildren<QMenu*>();

		// Apply the stylesheet to each QMenu
		for (QMenu* menu : menus) {
			if (menu) {
				menu->setStyleSheet(contextMenuSheet);
			}
		}

		// Apply the context menu stylesheet for each QTextEdit
		textEdit->setContextMenuStyle(contextMenuSheet);
		fileTreeContextMenu->setStyleSheet(contextMenuSheet);

		qApp->setPalette(lightPalette);
		normalColor = QColor(255, 255, 255);
	}else{
		// Optionally modify the palette for light mode
		QPalette lightPalette = qApp->palette();

		lightPalette.setColor(QPalette::Inactive, QPalette::Highlight, QColor("#000000"));
		lightPalette.setColor(QPalette::Inactive, QPalette::HighlightedText, QColor("#FFFFFF"));
		lightPalette.setColor(QPalette::Active, QPalette::Highlight, QColor("#000000"));
		lightPalette.setColor(QPalette::Active, QPalette::HighlightedText, QColor("#FFFFFF"));

		lightPalette.setColor(QPalette::Window, QColor(220, 220, 220));
		lightPalette.setColor(QPalette::WindowText, Qt::black);
		lightPalette.setColor(QPalette::Base, QColor(251, 251, 251));
		lightPalette.setColor(QPalette::ButtonText, Qt::black);
		lightPalette.setColor(QPalette::Text, Qt::black);
		lightPalette.setColor(QPalette::AlternateBase, QColor(201, 201, 201));
		lightPalette.setColor(QPalette::Button, QColor(251, 251, 251));
		lightPalette.setColor(QPalette::ToolTipBase, QColor(201, 201, 201));
		lightPalette.setColor(QPalette::Light, QColor(255, 255, 255));
		lightPalette.setColor(QPalette::Dark, QColor(100, 100, 100));

		QString menubarSheet = "QMenuBar {background-color: rgb(251, 251, 251); color: black; }"
								"QMenu { background-color: rgb(251, 251, 251); color: black; }"
								"QMenu::item:selected { background-color: rgb(150, 150, 150); color: black; }"
								"QMenu::separator {height: 1px; background-color: rgb(0, 0, 0); margin: 2px 4px;}"
								"QMenuBar::item { background-color: rgb(251, 251, 251); padding: 2px 4px; border-radius: 4px; margin: 3px 3px 2px 3px; }"
								"QMenuBar::item:hover { background-color: rgb(200, 200, 200); }"
								"QMenuBar::item:selected { background-color: rgb(200, 200, 200); }";

		ui->menuBar->setStyleSheet(menubarSheet);

		QString listWidgetSheet =
								"QListWidget{ background-color: rgb(251, 251, 251); color: black; }"
								"QListWidget::item:selected { background-color: rgb(150, 150, 150); color: black; }"
								"QListWidget::separator {height: 1px; background-color: rgb(0, 0, 0); margin: 2px 4px;}"
								"QListWidget::item { background-color: rgb(251, 251, 251); padding: 2px 2px; border-radius: 4px; margin: 3px 3px 2px 3px; }"
								"QListWidget::item:hover { background-color: rgb(200, 200, 200); }";

		fontList->setStyleSheet(listWidgetSheet);

		QList<QMenu*> menus = ui->menuBar->findChildren<QMenu*>();
		for (QMenu* menu : menus) {
			if (menu) {
				menu->setStyleSheet(contextMenuLightSheet);
			}
		}

		textEdit->setContextMenuStyle(contextMenuLightSheet);
		fileTreeContextMenu->setStyleSheet(contextMenuLightSheet);

		qApp->setPalette(lightPalette);
		normalColor = QColor(0, 0, 0);
	}

	changeOnlyEditsTheme(darkmode);
	changeHighlightColors(darkmode);

	updateSyntax();
	centerCursor();
}

void MainWindow::on_actionCourier_New_2_triggered()
{
	qDebug() << "on_actionCourier_New_2_triggered";

	currentFont = "Courier New";
	updateFontSelection();
}

void MainWindow::on_actionCourier_Prime_2_triggered()
{
	qDebug() << "on_actionCourier_Prime_2_triggered";

	currentFont = "Courier Prime";
	updateFontSelection();
}

void MainWindow::on_actionSourceCodePro_2_triggered()
{
	qDebug() << "on_actionSourceCodePro_2_triggered";

	currentFont = "Source Code Pro";
	updateFontSelection();
}

void MainWindow::on_actionUbuntuMono_2_triggered()
{
	qDebug() << "on_actionUbuntuMono_2_triggered";

	currentFont = "Ubuntu Mono";
	updateFontSelection();
}

void MainWindow::on_actionDroidSansMono_2_triggered()
{
	qDebug() << "on_actionDroidSansMono_2_triggered";

	currentFont = "Droid Sans Mono";
	updateFontSelection();
}

void MainWindow::on_actionMonaco_2_triggered()
{
	qDebug() << "on_actionMonaco_2_triggered";

	currentFont = "Monaco";
	updateFontSelection();
}

void MainWindow::on_actionMonospace_2_triggered()
{
	qDebug() << "on_actionMonospace_2_triggered";

	currentFont = "Monospace";
	updateFontSelection();
}

void MainWindow::updateFontSelection()
{
	qDebug() << "updateFontSelection";

	QFont font = textEdit->font();

	font.setItalic(false); // these 2 are probably not neccecarry but they sure do look pretty
	font.setBold(false);
	font.setFamily(currentFont);

	textEdit->setFont(font);
	updateFonts();
	saveWantedTheme();
}

void MainWindow::on_actionRunning_Files_triggered(){
	qDebug() << "on_actionRunning_Files_triggered";

	openHelpMenu("Running Files:\n"
				 "\n"
				 "1. The 'tag line':\n"
				 "	a. The tag line is the line at the bottom right of the CodeWizard window.\n"
				 "	b. The tag line is the command that CodeWizard will execute when attempting to run your code.\n"
				 "	c. Specifics:\n"
				 "		The CodeWizard will first change directory to the location of the file you are editing. Then run the tagline replacing all instances of [filename] with the filename. And all instances of [filenameWoutExt] with the filename without the extension (think test.py vs test)\n"
				 "\n"
				 "2. Running file:\n"
				 "	a. The key binding for running the active file is F5.\n"
				 "	b. You can also run files in the 'Run' menu.\n"
				 "\n"
				 "3. Errors:\n"
				 "	a. If CodeWizard fails to run your program it is likely due to it being blocked by an antivirus or windows defender. The solution is to run it as administrator.");
}

void MainWindow::on_actionVim_Modes_triggered(){
	qDebug() << "on_actionVim_Modes_triggered";

	openHelpMenu("Vim Modes\n\nAs of CodeWizard V8.8.9 we now support a modified set of the vim actions. Namely, when enabled, CodeWizard has a 'Normal' mode and an 'Insert' mode.\nIn normal mode there are a set of commands which work - which will be listed below. In insert mode, all keys are the same as regular (unless you press escape under the right circumstances to enter normal mode.)\n\nHere is the list of shortcuts which work in normal mode:\n    1. H - Moves left\n    2. J - Moves Down\n    3. K - Moves Up\n    4. L - Moves Right\n    5. W - Equivalent to Ctrl+Left\n    6. E - Equivalent to Ctrl+Right\n    7. All commands containing 'Ctrl' - Normal\n    8. All commands containing 'Alt' - Normal\n    9. Return/Enter/Backspace - Normal\n    10. PageDown, PageUp, Home, End - Normal\n    11. Comma/Less Than (<) - Jumps to corresponding previous bracket to the left\n    12. Period/Greater Than (>) - Jumps to corresponding previous bracket to the right\n    13. $ - Jumps to end of line\n    14. A - Jumps to end of line and enters insert mode\n    15. O - Inserts line below current line and enters insert mode");
}

void MainWindow::on_actionThe_Fix_It_Button_triggered(){
	qDebug() << "on_actionThe_Fix_It_Button_triggered";

	openHelpMenu("The Fix It Button\n\n"
				 "The Fix It button was named with grand plans for it, and they still exist. Kinda.\n\n"
				 "Currently the Fix It button serves mainly to change all four space increments (the indenting) to tabs. It is also designed to remove excess whitespace on lines and remove multiple blank lines.\n\n"
				 "The back to IDLE button changes the formating such that the tabs are replaced with four space increments again.");
}

void MainWindow::on_actionCodeWizard_triggered(){
	qDebug() << "on_actionCodeWizard_triggered";

	openHelpMenu("Designed by Adam Mather.\n\nVersion "+versionNumber);
}

void MainWindow::on_actionSettings_triggered(){
	qDebug() << "on_actionSettings_triggered";

	openHelpMenu("The settings for CodeWizard are mostly under the edit tab. Notable settings include:\n\nEdit->Fonts\nEdit->Tab Width\nEdit->Dark Mode\nEdit->Light Mode\nEdit->Auto Save\nView->Use File Tree\nView->Use File Tree If Fullscreen\nLanguage->LSP Settings\n\nNotable Shortcuts:\n\nAlt+Enter - Code Actions (LSP helpers)\nRight Click->Goto Definition (Requires LSP)");
}

void MainWindow::on_actionExtras_triggered(){
	qDebug() << "on_actionExtras_triggered";

	openHelpMenu("Notable Extras:\n\nAuto Save - Runs every 10 seconds, can be disabled with Edit->Auto Save\nBuiltin Terminal - CodeWizard has a limited builtin terminal. I would not advise you use it. View->Use Builtin Terminal");
}

void MainWindow::on_actionMacros_triggered(){
	qDebug() << "on_actionMacros_triggered";

	openHelpMenu("Macros:\nIn CodeWizard, a macro is a recorded set of keyboard actions. Once a macro is recorded with 'Edit->Start Macro Recording' and 'Edit->End Macro Recording' said macro can then be played back with Ctrl+P or 'Edit->Replay Macro'. If you run a macro '0' times it will run until the end of the file. No, it will not fix your dumb mistakes. Yes, it is a great way to waste time. (I promise) It is worthwhile to note that to stop a macro run amuck you can use Ctrl+P again to stop the macro execution.");
}

void MainWindow::on_actionLSP_2_triggered(){
	qDebug() << "on_actionLSP_2_triggered";

	openHelpMenu("Language Server Protocol:\n\nFrom CodeWizard V8.0.0 onwards we now support users setting their own Language Server. First set the language you want to set the LSP for, then press Language->Set LSP for language. To specify the LSP to use, type the command needed to run said language server. For example:\n\n   Python - \"jedi-language-server.exe\"\n      Install with \"pip install jedi-language-server\" and ensure \"C:\\Users\\USERNAME\\AppData\\Roaming\\Python\\PythonXX\\Scripts\" is in your path\n\n   C/C++ - \"clangd.exe\"\n      Download from official site\n\n   Rust - \"rust-analyzer.exe\"\n      Download from official site\n\n   TypeScript/JavaScript - \"typescript-language-server --stdio\"\n      Installed with \"npm install -g typescript-language-server typescript\"\n\n   Go - \"gopls\"\n      Installed with \"go install golang.org/x/tools/gopls@latest\"\n\n   HTML - \"vscode-html-language-server --stdio\"\n      Installed with \"npm i -g vscode-langservers-extracted\" (also provides vscode-css-language-server, vscode-json-language-server, vscode-eslint-language-server)\n\n\nLanguage Servers Provide the following features to CodeWizard:\n\n   1. Autocompletion\n   2. Hover for info\n   3. Goto definition\n   4. Errors/Warnings\n   5. Code Actions (error correction, formatting, etc)\n\nAll of these can be enabled/disabled under Languages->LSP Settings. There is also the option to disable LSP autocomplete but keep CodeWizard autocomplete, should you prefer it.\n\nExtra Notes:\n   1. When first setting the LSP for a language it may crash, just try again. It usually works the second time.");
}

void MainWindow::on_actionGit_Integration_triggered(){
	qDebug() << "on_actionGit_Integration_triggered";

	openHelpMenu("CodeWizard has builtin git support. When you press Git->Push, it will request a commit message, and then trigger the commands 'git add --all', 'git commit -m \"message\"' and 'git push'. Similarly for Git->Pull->Regular it runs 'git pull' and for Git->Pull->Discard Local Changes it runs 'git reset --hard'");
}

void MainWindow::on_actionKeybindings_triggered(){
	qDebug() << "on_actionKeybindings_triggered";

	openHelpMenu("Keybindings:\n\
  \n\
  Ctrl+B ------- Toggle filetree\n\
  Ctrl+T ------- Toggle builtin terminal\n\
  Ctrl+S ------- Save file\n\
  Ctrl+O ------- Open file\n\
  Ctrl+N ------- New file\n\
  Ctrl+'+' ----- Increase text size\n\
  Ctrl+'-' ----- Decrease text size\n\
  Alt ---------- Start/End macro recording\n\
  Ctrl+P ------- Replay Macro\n\
  Ctrl+F/H ----- Find\n\
  Ctrl+[ ------- De-indent\n\
  Ctrl+] ------- Indent\n\
  Alt+Enter ---- Code actions (LSP)\n\
  Alt+3 -------- Comment out section\n\
  Alt+4 -------- De-comment out section\n\
  Alt+A -------- Activate AI suggestion\n\
  F5 ----------- Run code\n\
  Ctrl+, ------- Jumps to left corresponding bracket\n\
  Ctrl+. ------- Jumps to right corresponding bracket\n\
  Crtl+/ ------- Toggle Comment");
}

void MainWindow::openHelpMenu(QString text) {
	qDebug() << "openHelpMenu";

	// Create a simple help dialog
	QDialog *helpDialog = new QDialog(this);
	helpDialog->setWindowTitle("Help Menu");

	helpDialog->resize(700, 100); // seems to resize to the apropriate size given the text or something - it's the label that causes this I think

	QLabel *helpText = new QLabel(text, helpDialog);
	helpText->setWordWrap(true);
	helpText->setFont(textEdit->font());
	helpText->setTextInteractionFlags(Qt::TextSelectableByMouse);

	QVBoxLayout *layout = new QVBoxLayout(helpDialog);
	layout->addWidget(helpText);

	helpDialog->setLayout(layout);
	helpDialog->exec();
}

void MainWindow::on_actionPython_2_triggered(){
	qDebug() << "on_actionPython_2_triggered";

	currentLang = pythonLang;
	lineEdit->setPlainText(pythonTag);
	updateDefaultWordLists();
	setupSyntaxTreeOnOpen(textEdit->toPlainText(), true);
}

void MainWindow::on_actionC_triggered(){
	qDebug() << "on_actionC_triggered";

	currentLang = cppLang;
	lineEdit->setPlainText(CppTag);
	updateDefaultWordLists();
	setupSyntaxTreeOnOpen(textEdit->toPlainText(), true);
}

void MainWindow::on_actionWGSL_triggered(){
	qDebug() << "on_actionWGSL_triggered";

	currentLang = WGSLLang;
	lineEdit->setPlainText(WGSLTag);
	updateDefaultWordLists();
	setupSyntaxTreeOnOpen(textEdit->toPlainText(), true);
}

void MainWindow::on_actionRust_triggered(){
	qDebug() << "on_actionRust_triggered";

	currentLang = rustLang;
	lineEdit->setPlainText(rustTag);
	updateDefaultWordLists();
	setupSyntaxTreeOnOpen(textEdit->toPlainText(), true);
}

void MainWindow::on_actionHTML_triggered(){
	qDebug() << "on_actionHTML_triggered";

	currentLang = HTMLLang;
	lineEdit->setPlainText(HTMLTag);
	updateDefaultWordLists();
	setupSyntaxTreeOnOpen(textEdit->toPlainText(), true);
}

void MainWindow::on_actionGo_triggered(){
	qDebug() << "on_actionGo_triggered";

	currentLang = goLang;
	lineEdit->setPlainText(goTag);
	updateDefaultWordLists();
	setupSyntaxTreeOnOpen(textEdit->toPlainText(), true);
}

void MainWindow::on_actionLua_triggered(){
	qDebug() << "on_actionLua_triggered";

	currentLang = luaLang;
	lineEdit->setPlainText(luaTag);
	updateDefaultWordLists();
	setupSyntaxTreeOnOpen(textEdit->toPlainText(), true);
}

void MainWindow::on_actionPlaintext_triggered(){
	qDebug() << "on_actionPlaintext_triggered";

	currentLang = txtLang;
	lineEdit->setPlainText("");
	updateDefaultWordLists();
	setupSyntaxTreeOnOpen(textEdit->toPlainText(), true);
}

void MainWindow::on_actionJavaScript_triggered(){
	qDebug() << "on_actionJavaScript_triggered";

	currentLang = jsLang;
	lineEdit->setPlainText(jsTag);
	updateDefaultWordLists();
	setupSyntaxTreeOnOpen(textEdit->toPlainText(), true);
}

void MainWindow::on_actionTypeScript_triggered(){
	qDebug() << "on_actionTypeScript_triggered";

	currentLang = tsLang;
	lineEdit->setPlainText(tsTag);
	updateDefaultWordLists();
	setupSyntaxTreeOnOpen(textEdit->toPlainText(), true);
}

void MainWindow::on_actionC_2_triggered(){
	qDebug() << "on_actionC_2_triggered";

	currentLang = csharpLang;
	lineEdit->setPlainText(csharpTag);
	updateDefaultWordLists();
	setupSyntaxTreeOnOpen(textEdit->toPlainText(), true);
}

void MainWindow::on_actionC_3_triggered(){
	qDebug() << "on_actionC_3_triggered";

	currentLang = cLang;
	lineEdit->setPlainText(cTag);
	updateDefaultWordLists();
	setupSyntaxTreeOnOpen(textEdit->toPlainText(), true);
}

void MainWindow::on_actionGLSL_triggered(){
	qDebug() << "on_actionGLSL_triggered";

	currentLang = GLSLLang;
	lineEdit->setPlainText(GLSLTag);
	updateDefaultWordLists();
	setupSyntaxTreeOnOpen(textEdit->toPlainText(), true);
}

void MainWindow::on_actionJava_triggered(){
	qDebug() << "on_actionJava_triggered";

	currentLang = javaLang;
	lineEdit->setPlainText(javaTag);
	updateDefaultWordLists();
	setupSyntaxTreeOnOpen(textEdit->toPlainText(), true);
}

void MainWindow::addFileToRecentList(QString file){
	qDebug() << "addFileToRecentList";

	if (recentFiles.contains(file)){
		recentFiles.removeAll(file);
	}

	recentFiles.push_front(file);

	if (recentFiles.length() > 20){ // too long
		recentFiles = recentFiles.mid(0, 20);
	}

	updateRecentList(recentFiles);
}

void MainWindow::updateRecentList(QStringList files){
	qDebug() << "updateRecentList";

	menuOpen_Recent->clear();

	for (QString file : files){
		QAction* action = menuOpen_Recent->addAction(file);
		action->setData(file);
		connect(action, &QAction::triggered, this, [this, action]() {
			openRecentFile(action->data().toString());
		});
	}

	QSettings settings("FoundationTechnologies", "CodeWizard");
	settings.setValue("recentFiles", recentFiles);
}

void MainWindow::openRecentFile(QString newFile){
	qDebug() << "openRecentFile";

	if (isSettingUpLSP){
		showWeDontFuckWithTheLSP();
		return;
	}

	if (isOpeningFile){
		showHoldYourHorses();
		return;
	}

	QString oldFile = fileName;

	isOpeningFile = true;

	if (useSpeakerAction->isChecked()){
		#ifdef _WIN32
			speech->say("Opening File");
		#endif
	}

	if (unsaved && fileName != ""){
		pullUpSaveDialogue();
	}

	if (newFile.isEmpty()){
		isOpeningFile = false;
		return;
	}

	storedLineNumbers[newFile] = textEdit->verticalScrollBar()->value();

	QFileInfo fileInfo(newFile);
	QFile file(newFile);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		QMessageBox newWarningBox;
		newWarningBox.setIcon(QMessageBox::Warning);
		newWarningBox.setText(tr("Cannot open file: %1").arg(file.errorString()));
		newWarningBox.setWindowTitle(tr("Error"));
		newWarningBox.setFont(textEdit->font());
		newWarningBox.exec();
		isOpeningFile = false;
		return;
	}

	bool ret = checkForLargeFile(&file);

	if (!ret){
		isOpeningFile = false;
		return;
	}

	fileName = newFile;

	setLangOffFilename(fileName, false);
	unsaved = false;

	QString fileDir = fileInfo.absolutePath();
	QString fileNameName = fileInfo.fileName();

	windowName = "CodeWizard V"+versionNumber+" - "+fileNameName+" - "+fileName;

	QTextStream in(&file);
	QString fileContent = in.readAll();
	previousLineCount = 1;
	savedText = fileContent;

	setupSyntaxTreeOnOpen(fileContent);

	highlightDiagnostics(true);

	textEdit->setPlainText(fileContent);
	toCompareTo = fileContent;

	previousLineCount = fileContent.count('\xa')+1;
	file.close();

	addFileToRecentList(fileName);

	int cnt = fileContent.count('\n') + 1;
	updateLineNumbers(cnt);

	updateExtraWordsList();

	setWindowTitle(windowName);

	fileModel->setRootPath(fileInfo.absolutePath());
	QSettings settings("FoundationTechnologies", "CodeWizard");
	settings.setValue("mostRecentFolder", fileInfo.absolutePath());

	fileTree->setRootIndex(fileModel->index(fileModel->rootPath()));

	if (useFileTree->isChecked() || useFileTreeIfFullscreen->isChecked() && (isFullScreen() || isMaximized())){ // BACK TO HERE YO
		fileTree->show();
	}else{
		fileTree->hide();
	}

	auto it = storedLineNumbers.find(fileName);
	if (it != storedLineNumbers.end()) {
		textEdit->verticalScrollBar()->setValue(it->second);
	}

	lspMutex.lock();
	setupLSP(oldFile);
	lspMutex.unlock();

	updateMargins(true); // called on open - every time

	if (useSpeakerAction->isChecked()){
		#ifdef _WIN32
			speech->say("File Opened");
		#endif
	}

	isOpeningFile = false;

	checkForFixitDialogue();
}
