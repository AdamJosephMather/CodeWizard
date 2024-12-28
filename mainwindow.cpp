#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QProcess>
#include <QMessageBox>
#include <QTextEdit>
#include <QKeyEvent>
#include <map>
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
#include "codehighlighter.h"
#include "language.h"
#include "languageserverclient.h"
#include <QtWidgets>
#include <QTextCursor>
#include <QRegularExpression>
#include <QtConcurrent/QtConcurrent>

QString updateSyntaxAdd = "";

QString versionNumber = "8.0.0";

QPoint mousePos;

QVector<QKeyEvent*> recordedEvents;
QVector<QObject*> recordedWidgets;
bool recordingMacro = false;
bool playingMacro = false;

QString fileName = "";
QString defWindowTitle = "CodeWizard V"+versionNumber+" - New File";
QString windowName = defWindowTitle;
MyTextEdit *textEdit;
QTextEdit *lineEdit;
MyTextEdit *lineNumberTextEdit;
QTextEdit *findTextEdit;
QTextEdit *replaceTextEdit;

QColor recColor = QColor(255, 70, 0);
QColor c1 = QColor(217, 159, 0);
QColor c2 = QColor(222, 123, 2);
QColor c3 = QColor(38, 175, 199);
QColor c4 = QColor(38, 143, 199);

QColor normalColor = QColor(255, 255, 255);

QTextCharFormat c1Format;
QTextCharFormat c2Format;
QTextCharFormat c3Format;
QTextCharFormat c4Format;
QTextCharFormat normalColorFormat;
QList<QTextCharFormat> errorFormats;

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

std::map<QString, QTextCharFormat> colormapPython;
std::map<QString, QTextCharFormat> colormapRust;
std::map<QString, QTextCharFormat> colormapWGSL;
std::map<QString, QTextCharFormat> colormapCpp;
std::map<QString, QTextCharFormat> colormapTxt;
std::map<QString, QTextCharFormat> colormapJs;
std::map<QString, QTextCharFormat> colormapHTML;
std::map<QString, QTextCharFormat> colormapGo;
std::map<QString, QTextCharFormat> colormapLua;
std::map<QString, QTextCharFormat> colormapCsharp;
std::map<QString, QTextCharFormat> colormapGLSL;
std::map<QString, QTextCharFormat> colormapJava;
std::map<QString, QTextCharFormat> colormapTs;
std::map<QString, QTextCharFormat> colormapC;

QString bfrChars = " \n(\t=!-+/%*[{&}])\"$^@|><,`~#:;'?\\";

int previousLineCount = 1;
bool darkmode = true;
int previousTextLen = 0;
int tabWidth = 4;

QString defPythonTag = "python \"[filename]\"";
QString defRustTag = "cargo run";
QString defWGSLTag = "cargo run";
QString defCppTag = "call \"C:\\Program Files\\Microsoft Visual Studio\\[VERSION_NUMBER]\\Community\\VC\\Auxiliary\\Build\\vcvarsall.bat\" x64\ncl /EHsc \"[filename]\"\n\"[filenameWoutExt].exe\"";
QString defTxtTag = "\"[filename]\"";
QString defJsTag = "node \"[filename]\"";
QString defTsTag = "ts-node \"[filename]\"";
QString defHTMLTag = "\"[filename]\"";
QString defGoTag = "go run .";
QString defLuaTag = "lua \"[filename]\"";
QString defCsharpTag = "csc \"[filename]\"";
QString defGLSLTag = "";
QString defJavaTag = "javac \"[filename]\"\njava \"[filename]\"";
QString defCTag = "call \"C:\\Program Files\\Microsoft Visual Studio\\[VERSION_NUMBER]\\Community\\VC\\Auxiliary\\Build\\vcvarsall.bat\" x64\ncl \"[filename]\"\n\"[filenameWoutExt].exe\"";

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

int fontSize = 11;

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
QMenu *menuOpen_Recent;
QMenu *menuLSP_Settings;
QMenu *menuWarnings;
QMenu *menuAutocomplete;
QMenu *menuSilly;
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

QString currentFont = "Monaco";

QStringList recentFiles;

CodeHighlighter *highlighter;

LanguageServerClient *client;
bool callCompleteOponUpdate = false;
QStringList errMessages;
QList<int> errStartC;
QList<int> errStartL;
QList<int> errEndC;
QList<int> errEndL;
QList<int> errSeverity;
QJsonArray codeActions;
int expectedCompletionId = 0;
int expectedHoverInfoId = 0;
QMutex lspMutex;

QAction* showWarnings;
QAction* showErrors;
QAction* showOther;
QAction* onlyCodeWizardBuiltIn;
QAction* noAutocomplete;
QAction* hoverAction;

QAction* autoSaveAct;

QAction* randomSelectFileTypeAct;

bool unsaved = false;
QString savedText = "";
bool isSettingUpLSP = false;
bool isOpeningFile = false;

QPoint suggestedPosition;
QMenu* fileTreeContextMenu;

bool ctrlDown = false;

MainWindow::MainWindow(const QString &argFileName, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(windowName);

    statusBar()->hide();

    findButton = ui->pushButton_4;
    nextButton = ui->pushButton_3;
    replaceButton = ui->pushButton_2;
    replaceAllButton = ui->pushButton;

    findTextEdit = ui->textEdit_2;
    replaceTextEdit = ui->textEdit_3;
    findTextEdit->setAcceptRichText(false);
    replaceTextEdit->setAcceptRichText(false);

    findBar = ui->textEdit_2;
    replaceBar = ui->textEdit_3;

    menuBarItem = ui->menuBar;

    menuEdit = ui->menuEdit;
    menuFixit = ui->menuFixit;
    menuOp1 = ui->menuOp1;
    menuRun = ui->menuRun;
    menuView = ui->menuView;
    menuFonts = ui->menuFonts;
    menuHelp = ui->menuHelp;
    menuLanguage = ui->menuLanguage;
    menuOpen_Recent = ui->menuOpen_Recent;
    menuLSP_Settings = ui->menuLSP_Settings;
    menuWarnings = ui->menuWarnings;
    menuAutocomplete = ui->menuAutocomplete;
    menuSilly = ui->menuSilly;

    useFileTree = ui->actionUse_File_Tree;
    useFileTreeIfFullscreen = ui->actionUse_File_Tree_If_Fullscreen;
    fileTree = ui->treeView;

    showWarnings = ui->actionShow_Warnings;
    showErrors = ui->actionShow_Errors;
    showOther = ui->actionShow_Other;
    onlyCodeWizardBuiltIn = ui->actionOnly_Use_CodeWizard_Built_In;
    noAutocomplete = ui->actionNo_Autocomplete;
    hoverAction = ui->actionHover;

    autoSaveAct = ui->actionAuto_Save;
    randomSelectFileTypeAct = ui->actionRandomly_Choose_Program_Type_On_Save;

    recordMacroButton = ui->actionStart_Macro_Recording;
    endRecordMacroButton = ui->actionEnd_Macro_Recording;
    replayMacroButton = ui->actionReplay_Macro;

    endRecordMacroButton->setEnabled(false);

    fileTreeContextMenu = new QMenu(this);

    lineEdit = ui->textEdit_5;

    textEdit = ui->textEdit;
    textEdit->setWordWrapMode(QTextOption::NoWrap);
    textEdit->setFocus();
    QFont monacoFont("Monaco");
    textEdit->setFont(monacoFont);

    QPalette palette = textEdit->palette();
    normalColor = palette.color(QPalette::WindowText);

    c1Format.setForeground(c1);
    c2Format.setForeground(c2);
    c3Format.setForeground(c3);
    c4Format.setForeground(c4);
    normalColorFormat.setForeground(normalColor);

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

    defWordListPython = {"global", "for", "print", "input", "open", "class", "import", "from", "while", "True", "break", "return", "continue", "del", "False", "not", "try", "except", "all", "ascii", "bin", "bool", "bytearray", "bytes", "chr", "classmethod", "compile", "complex", "and", "finally", "Exception", "ModuleNotFoundError", "IndexError", "KeyboardInterrupt", "MemoryError", "NameError", "NotImplementedError", "OSError", "OverflowError", "RecursionError", "ReferenceError", "RuntimeError", "StopIteration", "StopAsyncIteration", "SyntaxError", "IndentationError", "TabError", "SystemError", "SystemExit", "TypeError", "UnboundLocalError", "UnicodeError", "UnicodeEncodeError", "UnicodeDecodeError", "UnicodeTranslateError", "ValueError", "ZeroDivisionError", "EnvironmentError", "IOError", "WindowsError", "BlockingIOError", "ChildProcessError", "ConnectionError", "BrokenPipeError", "ConnectionAbortedError", "ConnectionRefusedError", "ConnectionResetError", "FileExistsError", "FileNotFoundError", "InterruptedError", "IsADirectoryError", "NotADirectoryError", "PermissionError", "ProcessLookupError", "TimeoutError", "Warning", "UserWarning", "DeprecationWarning", "PendingDeprecationWarning", "SyntaxWarning", "RuntimeWarning", "FutureWarning", "ImportWarning", "UnicodeWarning", "EncodingWarning", "BytesWarning", "ResourceWarning", "ExceptionGroup", "BaseExceptionGroup", "pass", "abs", "min", "max", "len", "range", "enumerate", "int", "float", "str", "assert", "with", "None", "delattr", "dict", "dir", "divmod", "eval", "exec", "filter", "format", "frozenset", "getattr", "globals", "hasattr", "hash", "help", "hex", "isinstance", "issubclass", "iter", "list", "locals", "map", "memoryview", "next", "object", "oct", "ord", "pow", "property", "repr", "reversed", "round", "set", "setattr", "slice", "sorted", "staticmethod", "sum", "super", "tuple", "type", "vars", "zip", "labmda", "self", "split", "append", "remove" };
    defWordListRust = {"Vec", "bool", "char", "f32", "f64", "i128", "i16", "i32", "i64", "i8", "isize", "str", "u128", "u16", "u32", "u64", "u8", "usize", "println", "print", "as", "break", "const", "continue", "crate", "else", "enum", "extern", "false", "fn", "for", "if", "impl", "in", "let", "loop", "match", "mod", "move", "mut", "pub", "ref", "return", "self", "Self", "static", "struct", "super", "trait", "true", "type", "unsafe", "use", "where", "while", "async", "await", "dyn", "abstract", "become", "box", "final", "macro", "override", "priv", "typeof", "unsized", "virtual", "yield", "try", "macro_rules", "union", "safe"};
    defWordListWGSL = {"i32", "u32", "f32", "f16", "enable", "bool", "vec2", "vec3", "vec4", "vec2", "vec3", "vec4", "mat2x2", "mat2x3", "mat2x4", "mat3x2", "mat3x3", "mat3x4", "mat4x2", "mat4x3", "mat4x4", "texture_1d", "texture_2d", "texture_2d_array", "texture_3d", "texture_depth_2d", "texture_depth_2d_array", "texture_depth_cube", "texture_depth_cube_array", "texture_multisampled_2d", "texture_storage_1d", "out", "uniform", "storage", "workgroup", "private", "function", "else", "for", "while", "loop", "break", "continue", "switch", "case", "default", "return", "acos", "asin", "atan", "cos", "sin", "tan", "exp", "exp2", "log", "log2", "pow", "sqrt", "rsqrt", "abs", "ceil", "floor", "round", "trunc", "sign", "min", "max", "clamp", "mix", "step", "smoothstep", "dot", "cross", "normalize", "distance", "length", "countOneBits", "reverseBits", "extractBits", "insertBits", "shiftLeft", "shiftRight", "all", "any", "select", "textureSample", "textureSampleBias", "textureSampleCompare", "textureSampleGrad", "textureSampleLevel", "textureDimensions", "textureNumLevels", "textureNumLayers", "textureNumSamples", "textureLoad", "textureStore", "atomicAdd", "atomicSub", "atomicMin", "atomicMax", "atomicAnd", "atomicOr", "atomicXor", "atomicExchange", "atomicCompareExchangeWeak", "workgroupBarrier", "storageBarrier", "vertex", "fragment", "compute", "location", "builtin", "group", "binding", "size", "align", "interpolate", "const", "true", "false", "#define", "#include", "let", "var", "workgroup_size"};
    defWordListCpp = {"std", "else", "switch", "case", "default", "break", "continue", "goto", "return", "for", "while", "int", "float", "double", "char", "void", "bool", "wchar_t", "short", "long", "signed", "unsigned", "auto", "bitset", "const", "static", "mutable", "volatile", "extern", "thread_local", "constexpr", "inline", "register", "class", "struct", "union", "this", "public", "private", "protected", "friend", "virtual", "explicit", "operator", "template", "typename", "decltype", "noexcept", "new", "delete", "dynamic_cast", "static_cast", "reinterpret_cast", "const_cast", "try", "catch", "throw", "namespace", "using", "sizeof", "alignof", "typeid", "static_assert", "export", "concept", "co_await", "co_return", "co_yield", "import", "module", "#include", "#define", "#undef", "#ifdef", "#ifndef", "#if", "#else", "#elif", "#endif", "#pragma", "nullptr", "cin", "cout", "cerr", "clog", "endl", "wcin", "wcout", "abs", "sin", "cos", "tan", "asin", "acos", "atan", "atan2", "pow", "sqrt", "ceil", "floor", "round", "string", "wstring", "to_string", "stoi", "stol", "stod", "stoul", "sort", "reverse", "accumulate", "find", "binary_search", "lower_bound", "upper_bound", "vector", "array", "deque", "list", "map", "unordered_map", "set", "unordered_set", "pair", "tuple", "begin", "end", "cbegin", "cend", "rbegin", "rend", "thread", "mutex", "lock", "unique_lock", "condition_variable", "async", "future", "true", "false", "alignas", "final", "override", "__FILE__", "__LINE__", "__DATE__", "__TIME__", "__func__", "__cplusplus"};
    defWordListTxt = {"CodeWizard"};
    defWordListTs = {"if", "else", "switch", "case", "default", "for", "while", "do", "break", "continue", "function", "return", "class", "extends", "constructor", "super", "var", "let", "const", "try", "catch", "finally", "throw", "import", "export", "from", "as", "new", "delete", "typeof", "instanceof", "void", "yield", "await", "async", "with", "this", "debugger", "true", "false", "null", "undefined", "NaN", "Infinity", "Array", "Object", "String", "Number", "Boolean", "Symbol", "BigInt", "array", "object", "string", "number", "boolean", "symbol", "bigint", "Date", "Math", "JSON", "RegExp", "Map", "Set", "WeakMap", "WeakSet", "Promise", "Proxy", "Reflect", "Function", "Error", "EvalError", "RangeError", "ReferenceError", "SyntaxError", "TypeError", "URIError", "window", "document", "console", "alert", "confirm", "prompt", "setTimeout", "setInterval", "clearTimeout", "clearInterval", "requestAnimationFrame", "cancelAnimationFrame", "use", "strict", "type", "interface", "implements", "enum", "readonly", "keyof", "typeof", "infer", "as", "unknown", "never", "void", "any", "abstract", "public", "private", "protected", "declare", "module", "namespace", "export", "import", "is", "satisfies", "extends"};
    defWordListHTML = {"if", "else", "switch", "case", "default", "for", "while", "do", "break", "continue", "function", "return", "class", "extends", "constructor", "super", "var", "let", "const", "try", "catch", "finally", "throw", "import", "export", "from", "as", "new", "delete", "typeof", "instanceof", "void", "yield", "await", "async", "with", "this", "debugger", "true", "false", "null", "undefined", "NaN", "Infinity","Array", "Object", "String", "Number", "Boolean", "Symbol", "BigInt", "Date", "Math", "JSON", "RegExp", "Map", "Set", "WeakMap", "WeakSet", "Promise", "Proxy", "Reflect", "Function", "Error", "EvalError", "RangeError", "ReferenceError", "SyntaxError", "TypeError", "URIError", "window", "document", "console", "alert", "confirm", "prompt", "setTimeout", "setInterval", "clearTimeout", "clearInterval", "requestAnimationFrame", "cancelAnimationFrame", "use", "strict", "html", "head", "body", "title", "meta", "link", "style", "script", "div", "span", "a", "p", "ul", "ol", "li", "h1", "h2", "h3", "h4", "h5", "h6", "table", "tr", "th", "td", "form", "input", "button", "select", "option", "textarea", "img", "audio", "video", "iframe", "canvas", "svg", "footer", "header", "main", "section", "article", "aside", "nav", "blockquote", "code", "pre", "b", "i", "u", "strong", "em", "br", "hr", "del", "ins", "mark", "q", "cite", "id", "class", "style", "src", "href", "alt", "title", "type", "value", "name", "placeholder", "action", "method", "target", "rel", "for", "disabled", "readonly", "checked", "required", "maxlength", "pattern", "download", "autocomplete", "accept", "accept-charset", "enctype", "formaction", "formenctype", "formmethod", "formtarget", "DOCTYPE"};
    defWordListJs = {"if", "else", "switch", "case", "default", "for", "while", "do", "break", "continue", "function", "return", "class", "extends", "constructor", "super", "var", "let", "const", "try", "catch", "finally", "throw", "import", "export", "from", "as", "new", "delete", "typeof", "instanceof", "void", "yield", "await", "async", "with", "this", "debugger", "true", "false", "null", "undefined", "NaN", "Infinity", "Array", "Object", "String", "Number", "Boolean", "Symbol", "BigInt", "array", "object", "string", "number", "boolean", "symbol", "bigint", "Date", "Math", "JSON", "RegExp", "Map", "Set", "WeakMap", "WeakSet", "Promise", "Proxy", "Reflect", "Function", "Error", "EvalError", "RangeError", "ReferenceError", "SyntaxError", "TypeError", "URIError", "window", "document", "console", "alert", "confirm", "prompt", "setTimeout", "setInterval", "clearTimeout", "clearInterval", "requestAnimationFrame", "cancelAnimationFrame", "use", "strict"};
    defWordListGo = {"break", "case", "chan", "const", "continue", "default", "defer", "else", "fallthrough", "for", "func", "go", "goto", "if", "import", "interface", "map", "package", "range", "return", "select", "struct", "switch", "type", "var", "append", "cap", "close", "complex", "copy", "delete", "imag", "len", "make", "new", "panic", "print", "println", "Print", "Println", "real", "recover", "bool", "byte", "complex64", "complex128", "error", "float32", "float64", "int", "int8", "int16", "int32", "int64", "rune", "string", "uint", "uint8", "uint16", "uint32", "uint64", "uintptr", "true", "false", "nil"};
    defWordListLua = {"if", "else", "elseif", "for", "while", "repeat", "until", "break", "return", "local", "function", "end", "do", "not", "and", "or", "in", "then", "nil", "boolean", "number", "string", "table", "function", "userdata", "thread", "print", "tonumber", "tostring", "type", "pairs", "ipairs", "next", "assert", "error", "pcall", "xpcall", "require", "load", "loadfile", "dofile", "gcinfo"};
    defWordListCsharp = {"abstract", "as", "base", "bool", "break", "byte", "case", "catch", "char", "checked", "class", "const", "continue", "decimal", "default", "delegate", "do", "double", "else", "enum", "event", "explicit", "extern", "false", "finally", "fixed", "float", "for", "foreach", "goto", "if", "implicit", "in", "int", "interface", "internal", "is", "lock", "long", "namespace", "new", "null", "object", "operator", "out", "override", "params", "private", "protected", "public", "readonly", "ref", "return", "sbyte", "sealed", "short", "sizeof", "stackalloc", "static", "string", "struct", "switch", "this", "throw", "true", "try", "typeof", "uint", "ulong", "unchecked", "unsafe", "ushort", "using", "virtual", "void", "volatile", "while", "var", "dynamic", "await", "async", "add", "alias", "ascending", "descending", "from", "get", "global", "group", "into", "join", "let", "nameof", "on", "orderby", "partial", "remove", "select", "set", "value", "where", "yield"};
    defWordListGLSL = {"if", "else", "for", "while", "do", "break", "continue", "return", "discard", "struct", "in", "out", "inout", "uniform", "layout", "const", "attribute", "varying", "buffer", "shared", "coherent", "volatile", "restrict", "readonly", "writeonly", "atomic_uint", "true", "false", "highp", "mediump", "lowp", "string", "float", "uint", "double", "int", "bool", "precision", "sampler2D", "sampler3D", "samplerCube", "sampler2DShadow", "samplerCubeShadow", "sampler1D", "sampler1DShadow", "sampler2DArray", "sampler2DArrayShadow", "samplerBuffer", "sampler2DMS", "sampler2DMSArray", "samplerCubeArray", "samplerCubeArrayShadow", "sampler1DArray", "sampler1DArrayShadow", "sampler3DArray", "sampler3DArrayShadow", "subroutine", "mat2", "mat3", "mat4", "mat2x2", "mat2x3", "mat2x4", "mat3x2", "mat3x3", "mat3x4", "mat4x2", "mat4x3", "mat4x4", "vec2", "vec3", "vec4", "ivec2", "ivec3", "ivec4", "uvec2", "uvec3", "uvec4", "bvec2", "bvec3", "bvec4", "dvec2", "dvec3", "dvec4", "dmat2", "dmat3", "dmat4", "dmat2x2", "dmat2x3", "dmat2x4", "dmat3x2", "dmat3x3", "dmat3x4", "dmat4x2", "dmat4x3", "dmat4x4", "void", "abs", "acos", "acosh", "all", "any", "asin", "asinh", "atan", "atan2", "atanh", "ceil", "clamp", "cos", "cosh", "cross", "degrees", "dFdx", "dFdy", "distance", "dot", "exp", "exp2", "faceforward", "floor", "fma", "fract", "frexp", "fwidth", "inversesqrt", "interpolateAtCentroid", "interpolateAtSample", "interpolateAtOffset", "isinf", "isnan", "ldexp", "length", "log", "log2", "max", "min", "mix", "mod", "modf", "normalize", "pow", "radians", "reflect", "refract", "round", "roundEven", "sign", "sin", "sinh", "smoothstep", "sqrt", "step", "tan", "tanh", "trunc", "texelFetch", "texture", "textureGrad", "textureLod", "textureProj", "transpose", "unpackUnorm", "unpackSnorm", "packUnorm", "packSnorm", "bitfieldExtract", "bitfieldInsert", "bitfieldReverse", "findLSB", "findMSB", "uaddCarry", "usubBorrow", "umulExtended", "imulExtended", "bitCount", "not", "version"};
    defWordListJava = {"Set", "List", "ArrayList", "String", "Override", "abstract", "assert", "boolean", "break", "byte", "case", "catch", "char", "class", "const", "continue", "default", "do", "double", "else", "enum", "extends", "final", "finally", "float", "for", "goto", "if", "implements", "import", "instanceof", "int", "interface", "long", "native", "new", "null", "package", "private", "protected", "public", "return", "short", "static", "strictfp", "super", "switch", "synchronized", "this", "throw", "throws", "transient", "try", "void", "volatile", "while", "true", "false", "null", "var", "yield"};
    defWordListC = {"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","inline","int","long","register","restrict","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while","_Alignas","_Alignof","_Atomic","_Bool","_Complex","_Generic","_Imaginary","_Noreturn","_Static_assert","_Thread_local","asm","typeof","attribute","malloc","calloc","realloc","free","printf","fprintf","sprintf","snprintf","scanf","sscanf","fscanf","perror","stdin","stdout","stderr","fopen","fclose","fread","fwrite","fseek","ftell","rewind","feof","ferror","fgets","fputs","getc","putc","getchar","putchar","strcmp","strncmp","strcat","strncat","strcpy","strncpy","strlen","strchr","strrchr","strstr","strtok","memcmp","memcpy","memmove","memset","abs","fabs","pow","sqrt","ceil","floor","round","sin","cos","tan","asin","acos","atan","atan2","exp","log","log10","rand","srand","time","clock","exit","atexit","qsort","bsearch","assert","raise","signal","setjmp","longjmp","va_start","va_arg","va_end","isalnum","isalpha","isdigit","islower","isupper","isspace","isxdigit","tolower","toupper","errno","offsetof","NULL","true","false","FILE","LINE","DATE","TIME","STDC","STDC_VERSION","STDC_HOSTED","func"};

    extraWordList = {};

    colormapC = {
        {"auto", c2Format},
        {"break", c2Format},
        {"case", c2Format},
        {"char", c2Format},
        {"const", c2Format},
        {"continue", c2Format},
        {"default", c2Format},
        {"do", c1Format},
        {"double", c2Format},
        {"else", c2Format},
        {"enum", c1Format},
        {"extern", c1Format},
        {"float", c2Format},
        {"for", c1Format},
        {"goto", c1Format},
        {"if", c1Format},
        {"inline", c1Format},
        {"int", c2Format},
        {"long", c2Format},
        {"register", c1Format},
        {"restrict", c1Format},
        {"return", c2Format},
        {"short", c2Format},
        {"signed", c2Format},
        {"sizeof", c1Format},
        {"static", c2Format},
        {"struct", c2Format},
        {"switch", c2Format},
        {"typedef", c1Format},
        {"union", c1Format},
        {"unsigned", c2Format},
        {"void", c2Format},
        {"volatile", c2Format},
        {"while", c1Format},
        {"Alignas", c2Format},
        {"Alignof", c2Format},
        {"Atomic", c2Format},
        {"Bool", c2Format},
        {"Complex", c2Format},
        {"Generic", c2Format},
        {"Imaginary", c2Format},
        {"Noreturn", c2Format},
        {"asm", c1Format},
        {"attribute", c2Format},
        {"typeof", c1Format},
        {"malloc", c1Format},
        {"calloc", c1Format},
        {"realloc", c1Format},
        {"free", c1Format},
        {"printf", c2Format},
        {"fprintf", c2Format},
        {"sprintf", c2Format},
        {"snprintf", c2Format},
        {"scanf", c1Format},
        {"sscanf", c1Format},
        {"fscanf", c1Format},
        {"perror", c1Format},
        {"stdin", c1Format},
        {"stdout", c1Format},
        {"stderr", c1Format},
        {"fopen", c1Format},
        {"fclose", c1Format},
        {"fread", c1Format},
        {"fwrite", c1Format},
        {"fseek", c1Format},
        {"ftell", c1Format},
        {"rewind", c1Format},
        {"feof", c1Format},
        {"ferror", c1Format},
        {"fgets", c1Format},
        {"fputs", c1Format},
        {"getc", c1Format},
        {"putc", c1Format},
        {"getchar", c1Format},
        {"putchar", c1Format},
        {"strcmp", c1Format},
        {"strncmp", c1Format},
        {"strcat", c1Format},
        {"strncat", c1Format},
        {"strcpy", c1Format},
        {"strncpy", c1Format},
        {"strlen", c1Format},
        {"strchr", c1Format},
        {"strrchr", c1Format},
        {"strstr", c1Format},
        {"strtok", c1Format},
        {"memcmp", c1Format},
        {"memcpy", c1Format},
        {"memmove", c1Format},
        {"memset", c1Format},
        {"abs", c1Format},
        {"fabs", c1Format},
        {"pow", c1Format},
        {"sqrt", c1Format},
        {"ceil", c1Format},
        {"floor", c1Format},
        {"round", c1Format},
        {"sin", c1Format},
        {"cos", c1Format},
        {"tan", c1Format},
        {"asin", c1Format},
        {"acos", c1Format},
        {"atan", c1Format},
        {"atan2", c1Format},
        {"exp", c1Format},
        {"log", c1Format},
        {"log10", c1Format},
        {"rand", c1Format},
        {"srand", c1Format},
        {"time", c1Format},
        {"clock", c1Format},
        {"exit", c1Format},
        {"atexit", c1Format},
        {"qsort", c1Format},
        {"bsearch", c1Format},
        {"assert", c1Format},
        {"raise", c2Format},
        {"signal", c1Format},
        {"setjmp", c1Format},
        {"longjmp", c1Format},
        {"isalnum", c1Format},
        {"isalpha", c1Format},
        {"isdigit", c1Format},
        {"islower", c1Format},
        {"isupper", c1Format},
        {"isspace", c1Format},
        {"isxdigit", c1Format},
        {"tolower", c1Format},
        {"toupper", c1Format},
        {"errno", c1Format},
        {"offsetof", c1Format},
        {"NULL", c2Format},
        {"true", c2Format},
        {"false", c2Format},
        {"FILE", c1Format},
        {"LINE", c2Format},
        {"DATE", c2Format},
        {"TIME", c2Format},
        {"STDC", c2Format},
        {"func", c1Format}
    };

    colormapTs = {
        {"if", c1Format},
        {"else", c1Format},
        {"switch", c1Format},
        {"case", c1Format},
        {"default", c1Format},
        {"for", c1Format},
        {"while", c1Format},
        {"do", c1Format},
        {"break", c2Format},
        {"continue", c2Format},
        {"function", c1Format},
        {"return", c2Format},
        {"class", c1Format},
        {"extends", c1Format},
        {"constructor", c1Format},
        {"super", c1Format},
        {"var", c2Format},
        {"let", c2Format},
        {"const", c2Format},
        {"try", c1Format},
        {"catch", c1Format},
        {"finally", c1Format},
        {"throw", c1Format},
        {"import", c2Format},
        {"export", c2Format},
        {"from", c1Format},
        {"as", c1Format},
        {"new", c2Format},
        {"delete", c1Format},
        {"typeof", c1Format},
        {"instanceof", c1Format},
        {"void", c2Format},
        {"yield", c2Format},
        {"await", c2Format},
        {"async", c2Format},
        {"with", c1Format},
        {"this", c1Format},
        {"debugger", c1Format},
        {"true", c2Format},
        {"false", c2Format},
        {"null", c2Format},
        {"undefined", c2Format},
        {"NaN", c2Format},
        {"Infinity", c2Format},
        {"Array", c2Format},
        {"Object", c2Format},
        {"String", c2Format},
        {"Number", c2Format},
        {"Boolean", c2Format},
        {"Symbol", c2Format},
        {"BigInt", c2Format},
        {"array", c2Format},
        {"object", c2Format},
        {"string", c2Format},
        {"number", c2Format},
        {"boolean", c2Format},
        {"symbol", c2Format},
        {"bigint", c2Format},
        {"Date", c2Format},
        {"Math", c2Format},
        {"JSON", c2Format},
        {"RegExp", c2Format},
        {"Map", c2Format},
        {"Set", c2Format},
        {"WeakMap", c2Format},
        {"WeakSet", c2Format},
        {"Promise", c2Format},
        {"Proxy", c2Format},
        {"Reflect", c2Format},
        {"Function", c2Format},
        {"Error", c2Format},
        {"EvalError", c2Format},
        {"RangeError", c2Format},
        {"ReferenceError", c2Format},
        {"SyntaxError", c2Format},
        {"TypeError", c2Format},
        {"URIError", c2Format},
        {"window", c2Format},
        {"document", c2Format},
        {"console", c2Format},
        {"alert", c2Format},
        {"confirm", c2Format},
        {"prompt", c2Format},
        {"setTimeout", c1Format},
        {"setInterval", c1Format},
        {"clearTimeout", c1Format},
        {"clearInterval", c1Format},
        {"requestAnimationFrame", c1Format},
        {"cancelAnimationFrame", c1Format},
        {"use", c2Format},
        {"strict", c2Format},
        {"type", c2Format},
        {"interface", c2Format},
        {"implements", c2Format},
        {"enum", c2Format},
        {"readonly", c2Format},
        {"keyof", c2Format},
        {"typeof", c2Format},
        {"infer", c2Format},
        {"as", c2Format},
        {"unknown", c2Format},
        {"never", c2Format},
        {"void", c2Format},
        {"any", c2Format},
        {"abstract", c2Format},
        {"public", c2Format},
        {"private", c2Format},
        {"protected", c2Format},
        {"declare", c2Format},
        {"module", c2Format},
        {"namespace", c2Format},
        {"export", c2Format},
        {"import", c2Format},
        {"is", c2Format},
        {"satisfies", c2Format},
        {"extends", c2Format}
    };

    colormapJava = {
        {"Set", c2Format},
        {"abstract", c2Format},
        {"assert", c2Format},
        {"boolean", c2Format},
        {"break", c2Format},
        {"byte", c2Format},
        {"case", c1Format},
        {"catch", c1Format},
        {"char", c2Format},
        {"class", c2Format},
        {"const", c2Format},
        {"continue", c2Format},
        {"default", c2Format},
        {"do", c1Format},
        {"double", c2Format},
        {"else", c1Format},
        {"enum", c1Format},
        {"extends", c2Format},
        {"final", c2Format},
        {"finally", c1Format},
        {"float", c2Format},
        {"for", c1Format},
        {"goto", c1Format},
        {"if", c1Format},
        {"implements", c2Format},
        {"import", c2Format},
        {"instanceof", c1Format},
        {"int", c2Format},
        {"interface", c2Format},
        {"long", c2Format},
        {"native", c2Format},
        {"new", c2Format},
        {"null", c2Format},
        {"package", c2Format},
        {"private", c2Format},
        {"protected", c2Format},
        {"public", c2Format},
        {"return", c2Format},
        {"short", c2Format},
        {"static", c2Format},
        {"strictfp", c2Format},
        {"super", c2Format},
        {"switch", c2Format},
        {"synchronized", c2Format},
        {"this", c2Format},
        {"throw", c2Format},
        {"throws", c2Format},
        {"transient", c2Format},
        {"try", c1Format},
        {"void", c2Format},
        {"volatile", c1Format},
        {"while", c1Format},
        {"true", c2Format},
        {"false", c2Format},
        {"null", c2Format},
        {"var", c2Format},
        {"yield", c2Format},
        {"Override", c2Format},
        {"String", c2Format},
        {"List", c2Format},
        {"ArrayList", c2Format}
    };

    colormapGLSL = {
        {"if", c1Format},
        {"else", c1Format},
        {"for", c1Format},
        {"while", c1Format},
        {"do", c1Format},
        {"break", c2Format},
        {"continue", c2Format},
        {"return", c2Format},
        {"discard", c2Format},
        {"struct", c2Format},
        {"in", c2Format},
        {"out", c2Format},
        {"inout", c2Format},
        {"uniform", c2Format},
        {"layout", c2Format},
        {"const", c2Format},
        {"attribute", c1Format},
        {"varying", c1Format},
        {"buffer", c1Format},
        {"shared", c1Format},
        {"coherent", c1Format},
        {"volatile", c2Format},
        {"restrict", c2Format},
        {"readonly", c2Format},
        {"writeonly", c2Format},
        {"atomic_uint", c2Format},
        {"true", c2Format},
        {"false", c2Format},
        {"highp", c2Format},
        {"mediump", c2Format},
        {"lowp", c2Format},
        {"string", c2Format},
        {"float", c2Format},
        {"uint", c2Format},
        {"double", c2Format},
        {"int", c2Format},
        {"bool", c2Format},
        {"precision", c2Format},
        {"sampler2D", c2Format},
        {"sampler3D", c2Format},
        {"samplerCube", c2Format},
        {"sampler2DShadow", c2Format},
        {"samplerCubeShadow", c2Format},
        {"sampler1D", c2Format},
        {"sampler1DShadow", c2Format},
        {"sampler2DArray", c2Format},
        {"sampler2DArrayShadow", c2Format},
        {"samplerBuffer", c2Format},
        {"sampler2DMS", c2Format},
        {"sampler2DMSArray", c2Format},
        {"samplerCubeArray", c2Format},
        {"samplerCubeArrayShadow", c2Format},
        {"sampler1DArray", c2Format},
        {"sampler1DArrayShadow", c2Format},
        {"sampler3DArray", c2Format},
        {"sampler3DArrayShadow", c2Format},
        {"subroutine", c2Format},
        {"mat2", c2Format},
        {"mat3", c2Format},
        {"mat4", c2Format},
        {"mat2x2", c2Format},
        {"mat2x3", c2Format},
        {"mat2x4", c2Format},
        {"mat3x2", c2Format},
        {"mat3x3", c2Format},
        {"mat3x4", c2Format},
        {"mat4x2", c2Format},
        {"mat4x3", c2Format},
        {"mat4x4", c2Format},
        {"vec2", c2Format},
        {"vec3", c2Format},
        {"vec4", c2Format},
        {"ivec2", c2Format},
        {"ivec3", c2Format},
        {"ivec4", c2Format},
        {"uvec2", c2Format},
        {"uvec3", c2Format},
        {"uvec4", c2Format},
        {"bvec2", c2Format},
        {"bvec3", c2Format},
        {"bvec4", c2Format},
        {"dvec2", c2Format},
        {"dvec3", c2Format},
        {"dvec4", c2Format},
        {"dmat2", c2Format},
        {"dmat3", c2Format},
        {"dmat4", c2Format},
        {"dmat2x2", c2Format},
        {"dmat2x3", c2Format},
        {"dmat2x4", c2Format},
        {"dmat3x2", c2Format},
        {"dmat3x3", c2Format},
        {"dmat3x4", c2Format},
        {"dmat4x2", c2Format},
        {"dmat4x3", c2Format},
        {"dmat4x4", c2Format},
        {"void", c2Format},
        {"abs", c1Format},
        {"acos", c1Format},
        {"acosh", c1Format},
        {"all", c1Format},
        {"any", c1Format},
        {"asin", c1Format},
        {"asinh", c1Format},
        {"atan", c1Format},
        {"atan2", c1Format},
        {"atanh", c1Format},
        {"ceil", c1Format},
        {"clamp", c1Format},
        {"cos", c1Format},
        {"cosh", c1Format},
        {"cross", c1Format},
        {"degrees", c1Format},
        {"dFdx", c1Format},
        {"dFdy", c1Format},
        {"distance", c1Format},
        {"dot", c1Format},
        {"exp", c1Format},
        {"exp2", c1Format},
        {"faceforward", c1Format},
        {"floor", c1Format},
        {"fma", c1Format},
        {"fract", c1Format},
        {"frexp", c1Format},
        {"fwidth", c1Format},
        {"inversesqrt", c1Format},
        {"interpolateAtCentroid", c1Format},
        {"interpolateAtSample", c1Format},
        {"interpolateAtOffset", c1Format},
        {"isinf", c1Format},
        {"isnan", c1Format},
        {"ldexp", c1Format},
        {"length", c1Format},
        {"log", c1Format},
        {"log2", c1Format},
        {"max", c1Format},
        {"min", c1Format},
        {"mix", c1Format},
        {"mod", c1Format},
        {"modf", c1Format},
        {"normalize", c1Format},
        {"pow", c1Format},
        {"radians", c1Format},
        {"reflect", c1Format},
        {"refract", c1Format},
        {"round", c1Format},
        {"roundEven", c1Format},
        {"sign", c1Format},
        {"sin", c1Format},
        {"sinh", c1Format},
        {"smoothstep", c1Format},
        {"sqrt", c1Format},
        {"step", c1Format},
        {"tan", c1Format},
        {"tanh", c1Format},
        {"trunc", c1Format},
        {"texelFetch", c1Format},
        {"texture", c1Format},
        {"textureGrad", c1Format},
        {"textureLod", c1Format},
        {"textureProj", c1Format},
        {"transpose", c1Format},
        {"unpackUnorm", c1Format},
        {"unpackSnorm", c1Format},
        {"packUnorm", c1Format},
        {"packSnorm", c1Format},
        {"bitfieldExtract", c1Format},
        {"bitfieldInsert", c1Format},
        {"bitfieldReverse", c1Format},
        {"findLSB", c1Format},
        {"findMSB", c1Format},
        {"uaddCarry", c1Format},
        {"usubBorrow", c1Format},
        {"umulExtended", c1Format},
        {"imulExtended", c1Format},
        {"bitCount", c1Format},
        {"not", c1Format},
        {"version", c2Format}
    };

    colormapJs = {
        {"if", c1Format},
        {"else", c1Format},
        {"switch", c1Format},
        {"case", c1Format},
        {"default", c1Format},
        {"for", c1Format},
        {"while", c1Format},
        {"do", c1Format},
        {"break", c2Format},
        {"continue", c2Format},
        {"function", c1Format},
        {"return", c2Format},
        {"class", c1Format},
        {"extends", c1Format},
        {"constructor", c1Format},
        {"super", c1Format},
        {"var", c2Format},
        {"let", c2Format},
        {"const", c2Format},
        {"try", c1Format},
        {"catch", c1Format},
        {"finally", c1Format},
        {"throw", c1Format},
        {"import", c2Format},
        {"export", c2Format},
        {"from", c1Format},
        {"as", c1Format},
        {"new", c2Format},
        {"delete", c1Format},
        {"typeof", c1Format},
        {"instanceof", c1Format},
        {"void", c2Format},
        {"yield", c2Format},
        {"await", c2Format},
        {"async", c2Format},
        {"with", c1Format},
        {"this", c1Format},
        {"debugger", c1Format},
        {"true", c2Format},
        {"false", c2Format},
        {"null", c2Format},
        {"undefined", c2Format},
        {"NaN", c2Format},
        {"Infinity", c2Format},
        {"Array", c2Format},
        {"Object", c2Format},
        {"String", c2Format},
        {"Number", c2Format},
        {"Boolean", c2Format},
        {"Symbol", c2Format},
        {"BigInt", c2Format},
        {"array", c2Format},
        {"object", c2Format},
        {"string", c2Format},
        {"number", c2Format},
        {"boolean", c2Format},
        {"symbol", c2Format},
        {"bigint", c2Format},
        {"Date", c2Format},
        {"Math", c2Format},
        {"JSON", c2Format},
        {"RegExp", c2Format},
        {"Map", c2Format},
        {"Set", c2Format},
        {"WeakMap", c2Format},
        {"WeakSet", c2Format},
        {"Promise", c2Format},
        {"Proxy", c2Format},
        {"Reflect", c2Format},
        {"Function", c2Format},
        {"Error", c2Format},
        {"EvalError", c2Format},
        {"RangeError", c2Format},
        {"ReferenceError", c2Format},
        {"SyntaxError", c2Format},
        {"TypeError", c2Format},
        {"URIError", c2Format},
        {"window", c2Format},
        {"document", c2Format},
        {"console", c2Format},
        {"alert", c2Format},
        {"confirm", c2Format},
        {"prompt", c2Format},
        {"setTimeout", c1Format},
        {"setInterval", c1Format},
        {"clearTimeout", c1Format},
        {"clearInterval", c1Format},
        {"requestAnimationFrame", c1Format},
        {"cancelAnimationFrame", c1Format},
        {"use", c2Format},
        {"strict", c2Format}
    };

    colormapTxt = {};

    colormapCpp = {
        {"std", c1Format},
        {"if", c1Format},
        {"else", c1Format},
        {"switch", c1Format},
        {"case", c1Format},
        {"default", c1Format},
        {"break", c2Format},
        {"continue", c2Format},
        {"goto", c2Format},
        {"return", c2Format},
        {"for", c1Format},
        {"while", c1Format},
        {"do", c1Format},
        {"int", c2Format},
        {"float", c2Format},
        {"double", c2Format},
        {"char", c2Format},
        {"void", c2Format},
        {"bool", c2Format},
        {"wchar_t", c2Format},
        {"short", c2Format},
        {"long", c2Format},
        {"signed", c2Format},
        {"unsigned", c2Format},
        {"auto", c2Format},
        {"const", c2Format},
        {"static", c2Format},
        {"mutable", c2Format},
        {"volatile", c2Format},
        {"bitset", c2Format},
        {"extern", c1Format},
        {"thread_local", c1Format},
        {"constexpr", c1Format},
        {"inline", c1Format},
        {"register", c1Format},
        {"class", c2Format},
        {"struct", c1Format},
        {"union", c1Format},
        {"this", c1Format},
        {"public", c2Format},
        {"private", c2Format},
        {"protected", c2Format},
        {"friend", c2Format},
        {"virtual", c2Format},
        {"explicit", c2Format},
        {"operator", c2Format},
        {"template", c2Format},
        {"typename", c2Format},
        {"decltype", c2Format},
        {"noexcept", c2Format},
        {"new", c2Format},
        {"delete", c2Format},
        {"dynamic_cast", c1Format},
        {"static_cast", c1Format},
        {"reinterpret_cast", c1Format},
        {"const_cast", c1Format},
        {"try", c2Format},
        {"catch", c2Format},
        {"throw", c2Format},
        {"namespace", c1Format},
        {"using", c2Format},
        {"sizeof", c2Format},
        {"alignof", c2Format},
        {"typeid", c1Format},
        {"static_assert", c1Format},
        {"export", c1Format},
        {"concept", c1Format},
        {"co_await", c1Format},
        {"co_return", c1Format},
        {"co_yield", c1Format},
        {"import", c1Format},
        {"module", c1Format},
        {"include", c1Format},
        {"define", c1Format},
        {"undef", c1Format},
        {"ifdef", c1Format},
        {"ifndef", c1Format},
        {"endif", c1Format},
        {"pragma", c1Format},
        {"nullptr", c1Format},
        {"cin", c1Format},
        {"cout", c1Format},
        {"cerr", c1Format},
        {"clog", c1Format},
        {"endl", c1Format},
        {"wcin", c1Format},
        {"wcout", c1Format},
        {"abs", c1Format},
        {"sin", c1Format},
        {"cos", c1Format},
        {"tan", c1Format},
        {"asin", c1Format},
        {"acos", c1Format},
        {"atan", c1Format},
        {"atan2", c1Format},
        {"pow", c1Format},
        {"sqrt", c1Format},
        {"ceil", c1Format},
        {"floor", c1Format},
        {"round", c1Format},
        {"string", c2Format},
        {"wstring", c1Format},
        {"to_string", c1Format},
        {"stoi", c1Format},
        {"stol", c1Format},
        {"stod", c1Format},
        {"stoul", c1Format},
        {"sort", c1Format},
        {"reverse", c1Format},
        {"accumulate", c1Format},
        {"find", c1Format},
        {"binary_search", c1Format},
        {"lower_bound", c1Format},
        {"upper_bound", c1Format},
        {"vector", c2Format},
        {"array", c2Format},
        {"deque", c2Format},
        {"list", c2Format},
        {"map", c2Format},
        {"unordered_map", c2Format},
        {"set", c2Format},
        {"unordered_set", c2Format},
        {"pair", c2Format},
        {"tuple", c2Format},
        {"begin", c2Format},
        {"end", c2Format},
        {"cbegin", c1Format},
        {"cend", c1Format},
        {"rbegin", c1Format},
        {"rend", c1Format},
        {"thread", c1Format},
        {"mutex", c1Format},
        {"lock", c1Format},
        {"unique_lock", c1Format},
        {"condition_variable", c1Format},
        {"async", c1Format},
        {"future", c1Format},
        {"true", c2Format},
        {"false", c2Format},
        {"alignas", c2Format},
        {"final", c2Format},
        {"override", c2Format},
        {"__FILE__", c2Format},
        {"__LINE__", c2Format},
        {"__DATE__", c2Format},
        {"__TIME__", c2Format},
        {"__func__", c2Format},
        {"__cplusplus", c2Format}
    };

    colormapWGSL = {
                    {"i32", c2Format},
                    {"u32", c2Format},
                    {"f32", c2Format},
                    {"f16", c2Format},
                    {"enable", c1Format},
                    {"bool", c2Format},
                    {"vec2", c2Format},
                    {"vec3", c2Format},
                    {"vec4", c2Format},
                    {"vec2", c2Format},
                    {"vec3", c2Format},
                    {"vec4", c2Format},
                    {"mat2x2", c2Format},
                    {"mat2x3", c2Format},
                    {"mat2x4", c2Format},
                    {"mat3x2", c2Format},
                    {"mat3x3", c2Format},
                    {"mat3x4", c2Format},
                    {"mat4x2", c2Format},
                    {"mat4x3", c2Format},
                    {"mat4x4", c2Format},
                    {"texture_1d", c2Format},
                    {"texture_2d", c2Format},
                    {"texture_2d_array", c2Format},
                    {"texture_3d", c2Format},
                    {"texture_depth_2d", c2Format},
                    {"texture_depth_2d_array", c2Format},
                    {"texture_depth_cube", c2Format},
                    {"texture_depth_cube_array", c2Format},
                    {"texture_multisampled_2d", c2Format},
                    {"texture_storage_1d", c2Format},
                    {"in", c1Format},
                    {"out", c1Format},
                    {"uniform", c1Format},
                    {"storage", c1Format},
                    {"workgroup", c1Format},
                    {"private", c1Format},
                    {"function", c1Format},
                    {"fn", c1Format},
                    {"if", c1Format},
                    {"else", c1Format},
                    {"for", c1Format},
                    {"while", c1Format},
                    {"loop", c1Format},
                    {"break", c2Format},
                    {"continue", c2Format},
                    {"switch", c1Format},
                    {"case", c1Format},
                    {"default", c1Format},
                    {"return", c2Format},
                    {"acos", c1Format},
                    {"asin", c1Format},
                    {"atan", c1Format},
                    {"cos", c1Format},
                    {"sin", c1Format},
                    {"tan", c1Format},
                    {"exp", c1Format},
                    {"exp2", c1Format},
                    {"log", c1Format},
                    {"log2", c1Format},
                    {"pow", c1Format},
                    {"sqrt", c1Format},
                    {"rsqrt", c1Format},
                    {"abs", c1Format},
                    {"ceil", c1Format},
                    {"floor", c1Format},
                    {"round", c1Format},
                    {"trunc", c1Format},
                    {"sign", c1Format},
                    {"min", c1Format},
                    {"max", c1Format},
                    {"clamp", c1Format},
                    {"mix", c1Format},
                    {"step", c1Format},
                    {"smoothstep", c1Format},
                    {"dot", c1Format},
                    {"cross", c1Format},
                    {"normalize", c1Format},
                    {"distance", c1Format},
                    {"length", c1Format},
                    {"countOneBits", c1Format},
                    {"reverseBits", c1Format},
                    {"extractBits", c1Format},
                    {"insertBits", c1Format},
                    {"shiftLeft", c1Format},
                    {"shiftRight", c1Format},
                    {"all", c1Format},
                    {"any", c1Format},
                    {"select", c1Format},
                    {"textureSample", c2Format},
                    {"textureSampleBias", c2Format},
                    {"textureSampleCompare", c2Format},
                    {"textureSampleGrad", c2Format},
                    {"textureSampleLevel", c2Format},
                    {"textureDimensions", c2Format},
                    {"textureNumLevels", c2Format},
                    {"textureNumLayers", c2Format},
                    {"textureNumSamples", c2Format},
                    {"textureLoad", c2Format},
                    {"textureStore", c2Format},
                    {"atomicAdd", c1Format},
                    {"atomicSub", c1Format},
                    {"atomicMin", c1Format},
                    {"atomicMax", c1Format},
                    {"atomicAnd", c1Format},
                    {"atomicOr", c1Format},
                    {"atomicXor", c1Format},
                    {"atomicExchange", c1Format},
                    {"atomicCompareExchangeWeak", c1Format},
                    {"workgroupBarrier", c1Format},
                    {"storageBarrier", c1Format},
                    {"vertex", c1Format},
                    {"fragment", c1Format},
                    {"compute", c1Format},
                    {"location", c1Format},
                    {"builtin", c1Format},
                    {"group", c1Format},
                    {"binding", c1Format},
                    {"size", c1Format},
                    {"align", c1Format},
                    {"interpolate", c1Format},
                    {"workgroup_size", c1Format},
                    {"group", c1Format},
                    {"const", c1Format},
                    {"true", c2Format},
                    {"false", c2Format},
                    {"#define", c1Format},
                    {"#include", c1Format},
                    {"let", c1Format},
                    {"var", c1Format},
                    };

    colormapRust = {
                    {"println", c1Format},
                    {"print", c1Format},
                    {"as", c1Format},
                    {"break", c2Format},
                    {"const", c1Format},
                    {"continue", c2Format},
                    {"crate", c1Format},
                    {"else", c1Format},
                    {"enum", c2Format},
                    {"extern", c1Format},
                    {"false", c2Format},
                    {"fn", c1Format},
                    {"for", c1Format},
                    {"if", c1Format},
                    {"impl", c1Format},
                    {"in", c1Format},
                    {"let", c1Format},
                    {"loop", c1Format},
                    {"match", c1Format},
                    {"mod", c1Format},
                    {"move", c1Format},
                    {"mut", c1Format},
                    {"pub", c1Format},
                    {"ref", c1Format},
                    {"return", c2Format},
                    {"self", c1Format},
                    {"Self", c1Format},
                    {"struct", c1Format},
                    {"super", c1Format},
                    {"trait", c1Format},
                    {"true", c2Format},
                    {"type", c1Format},
                    {"unsafe", c1Format},
                    {"use", c1Format},
                    {"where", c1Format},
                    {"while", c1Format},
                    {"async", c1Format},
                    {"await", c1Format},
                    {"dyn", c1Format},
                    {"abstract", c1Format},
                    {"become", c1Format},
                    {"box", c1Format},
                    {"do", c1Format},
                    {"final", c1Format},
                    {"macro", c1Format},
                    {"override", c1Format},
                    {"priv", c1Format},
                    {"typeof", c1Format},
                    {"unsized", c1Format},
                    {"virtual", c1Format},
                    {"yield", c2Format},
                    {"try", c2Format},
                    {"macro_rules", c1Format},
                    {"union", c1Format},
                    {"static", c1Format},
                    {"safe", c1Format},
                    {"bool", c2Format},
                    {"char", c2Format},
                    {"f32", c2Format},
                    {"f64", c2Format},
                    {"i128", c2Format},
                    {"i16", c2Format},
                    {"i32", c2Format},
                    {"i64", c2Format},
                    {"i8", c2Format},
                    {"isize", c2Format},
                    {"str", c2Format},
                    {"u128", c2Format},
                    {"u16", c2Format},
                    {"u32", c2Format},
                    {"u64", c2Format},
                    {"u8", c2Format},
                    {"usize", c2Format},
                    {"Vec", c2Format},
                    };

    colormapPython = {
                      {"global", c1Format},
                      {"for", c1Format},
                      {"if", c1Format},
                      {"elif", c1Format},
                      {"else", c1Format},
                      {"input", c2Format},
                      {"def", c1Format},
                      {"class", c1Format},
                      {"import", c2Format},
                      {"from", c2Format},
                      {"while", c1Format},
                      {"True", c2Format},
                      {"break", c2Format},
                      {"return", c2Format},
                      {"continue", c2Format},
                      {"del", c1Format},
                      {"False", c2Format},
                      {"not", c1Format},
                      {"try", c2Format},
                      {"except", c2Format},
                      {"all", c1Format},
                      {"ascii", c2Format},
                      {"bin", c2Format},
                      {"bool", c2Format},
                      {"bytearray", c2Format},
                      {"bytes", c2Format},
                      {"chr", c2Format},
                      {"classmethod", c2Format},
                      {"compile", c1Format},
                      {"complex", c2Format},
                      {"as", c1Format},
                      {"and", c1Format},
                      {"or", c1Format},
                      {"finally", c1Format},
                      {"Exception", c2Format},
                      {"ModuleNotFoundError", c2Format},
                      {"IndexError", c2Format},
                      {"KeyboardInterrupt", c2Format},
                      {"MemoryError", c2Format},
                      {"NameError", c2Format},
                      {"NotImplementedError", c2Format},
                      {"OSError", c2Format},
                      {"OverflowError", c2Format},
                      {"RecursionError", c2Format},
                      {"ReferenceError", c2Format},
                      {"RuntimeError", c2Format},
                      {"StopIteration", c2Format},
                      {"StopAsyncIteration", c2Format},
                      {"SyntaxError", c2Format},
                      {"IndentationError", c2Format},
                      {"TabError", c2Format},
                      {"SystemError", c2Format},
                      {"SystemExit", c2Format},
                      {"TypeError", c2Format},
                      {"UnboundLocalError", c2Format},
                      {"UnicodeError", c2Format},
                      {"UnicodeEncodeError", c2Format},
                      {"UnicodeDecodeError", c2Format},
                      {"UnicodeTranslateError", c2Format},
                      {"ValueError", c2Format},
                      {"ZeroDivisionError", c2Format},
                      {"EnvironmentError", c2Format},
                      {"IOError", c2Format},
                      {"WindowsError", c2Format},
                      {"BlockingIOError", c2Format},
                      {"ChildProcessError", c2Format},
                      {"ConnectionError", c2Format},
                      {"BrokenPipeError", c2Format},
                      {"ConnectionAbortedError", c2Format},
                      {"ConnectionRefusedError", c2Format},
                      {"ConnectionResetError", c2Format},
                      {"FileExistsError", c2Format},
                      {"FileNotFoundError", c2Format},
                      {"InterruptedError", c2Format},
                      {"IsADirectoryError", c2Format},
                      {"NotADirectoryError", c2Format},
                      {"PermissionError", c2Format},
                      {"ProcessLookupError", c2Format},
                      {"TimeoutError", c2Format},
                      {"Warning", c2Format},
                      {"UserWarning", c2Format},
                      {"DeprecationWarning", c2Format},
                      {"PendingDeprecationWarning", c2Format},
                      {"SyntaxWarning", c2Format},
                      {"RuntimeWarning", c2Format},
                      {"FutureWarning", c2Format},
                      {"ImportWarning", c2Format},
                      {"UnicodeWarning", c2Format},
                      {"EncodingWarning", c2Format},
                      {"BytesWarning", c2Format},
                      {"ResourceWarning", c2Format},
                      {"ExceptionGroup", c2Format},
                      {"BaseExceptionGroup", c2Format},
                      {"pass", c1Format},
                      {"in", c1Format},
                      {"abs", c1Format},
                      {"min", c1Format},
                      {"len", c1Format},
                      {"range", c2Format},
                      {"enumerate", c2Format},
                      {"int", c2Format},
                      {"float", c2Format},
                      {"str", c2Format},
                      {"assert", c2Format},
                      {"with", c1Format},
                      {"None", c1Format},
                      {"delattr", c1Format},
                      {"dict", c2Format},
                      {"dir", c1Format},
                      {"divmod", c1Format},
                      {"eval", c1Format},
                      {"exec", c1Format},
                      {"filter", c1Format},
                      {"format", c1Format},
                      {"frozenset", c1Format},
                      {"getattr", c1Format},
                      {"globals", c1Format},
                      {"hasattr", c1Format},
                      {"hash", c1Format},
                      {"help", c1Format},
                      {"hex", c1Format},
                      {"id", c1Format},
                      {"isinstance", c1Format},
                      {"issubclass", c1Format},
                      {"iter", c1Format},
                      {"list", c2Format},
                      {"locals", c1Format},
                      {"map", c2Format},
                      {"max", c1Format},
                      {"memoryview", c1Format},
                      {"next", c1Format},
                      {"object", c1Format},
                      {"oct", c1Format},
                      {"open", c1Format},
                      {"ord", c1Format},
                      {"pow", c1Format},
                      {"print", c2Format},
                      {"property", c1Format},
                      {"repr", c1Format},
                      {"reversed", c1Format},
                      {"round", c2Format},
                      {"set", c2Format},
                      {"setattr", c1Format},
                      {"slice", c1Format},
                      {"sorted", c1Format},
                      {"staticmethod", c1Format},
                      {"sum", c1Format},
                      {"super", c1Format},
                      {"tuple", c1Format},
                      {"type", c1Format},
                      {"vars", c1Format},
                      {"zip", c1Format},
                      {"is", c1Format},
                      {"labmda", c1Format}};

    colormapHTML = {
        {"html", c1Format},
        {"head", c1Format},
        {"body", c1Format},
        {"title", c1Format},
        {"meta", c1Format},
        {"link", c1Format},
        {"style", c1Format},
        {"script", c1Format},
        {"div", c1Format},
        {"span", c1Format},
        {"a", c1Format},
        {"p", c1Format},
        {"ul", c1Format},
        {"ol", c1Format},
        {"li", c1Format},
        {"h1", c1Format},
        {"h2", c1Format},
        {"h3", c1Format},
        {"h4", c1Format},
        {"h5", c1Format},
        {"h6", c1Format},
        {"table", c1Format},
        {"tr", c1Format},
        {"th", c1Format},
        {"td", c1Format},
        {"form", c1Format},
        {"input", c1Format},
        {"button", c1Format},
        {"select", c1Format},
        {"option", c1Format},
        {"textarea", c1Format},
        {"img", c1Format},
        {"audio", c1Format},
        {"video", c1Format},
        {"iframe", c1Format},
        {"canvas", c1Format},
        {"svg", c1Format},
        {"footer", c1Format},
        {"header", c1Format},
        {"main", c1Format},
        {"section", c1Format},
        {"article", c1Format},
        {"aside", c1Format},
        {"nav", c1Format},
        {"blockquote", c1Format},
        {"code", c1Format},
        {"pre", c1Format},
        {"b", c1Format},
        {"i", c1Format},
        {"u", c1Format},
        {"strong", c1Format},
        {"em", c1Format},
        {"br", c1Format},
        {"hr", c1Format},
        {"del", c1Format},
        {"ins", c1Format},
        {"mark", c1Format},
        {"q", c1Format},
        {"cite", c1Format},
        {"id", c1Format},
        {"class", c1Format},
        {"style", c1Format},
        {"src", c1Format},
        {"href", c1Format},
        {"alt", c1Format},
        {"title", c1Format},
        {"type", c1Format},
        {"value", c1Format},
        {"name", c1Format},
        {"placeholder", c1Format},
        {"action", c1Format},
        {"method", c1Format},
        {"target", c1Format},
        {"rel", c1Format},
        {"for", c1Format},
        {"disabled", c1Format},
        {"readonly", c1Format},
        {"checked", c1Format},
        {"required", c1Format},
        {"maxlength", c1Format},
        {"pattern", c1Format},
        {"download", c1Format},
        {"autocomplete", c1Format},
        {"accept", c1Format},
        {"accept-charset", c1Format},
        {"enctype", c1Format},
        {"formaction", c1Format},
        {"formenctype", c1Format},
        {"formmethod", c1Format},
        {"formtarget", c1Format},
        {"DOCTYPE", c1Format},
        {"if", c1Format},
        {"else", c1Format},
        {"switch", c1Format},
        {"case", c1Format},
        {"default", c1Format},
        {"for", c1Format},
        {"while", c1Format},
        {"do", c1Format},
        {"break", c2Format},
        {"continue", c2Format},
        {"function", c1Format},
        {"return", c2Format},
        {"class", c1Format},
        {"extends", c1Format},
        {"constructor", c1Format},
        {"super", c1Format},
        {"var", c2Format},
        {"let", c2Format},
        {"const", c2Format},
        {"try", c1Format},
        {"catch", c1Format},
        {"finally", c1Format},
        {"throw", c1Format},
        {"import", c2Format},
        {"export", c2Format},
        {"from", c1Format},
        {"as", c1Format},
        {"new", c2Format},
        {"delete", c1Format},
        {"typeof", c1Format},
        {"instanceof", c1Format},
        {"void", c2Format},
        {"yield", c2Format},
        {"await", c2Format},
        {"async", c2Format},
        {"with", c1Format},
        {"this", c1Format},
        {"debugger", c1Format},
        {"true", c2Format},
        {"false", c2Format},
        {"null", c2Format},
        {"undefined", c2Format},
        {"NaN", c2Format},
        {"Infinity", c2Format},
        {"Array", c2Format},
        {"Object", c2Format},
        {"String", c2Format},
        {"Number", c2Format},
        {"Boolean", c2Format},
        {"Symbol", c2Format},
        {"BigInt", c2Format},
        {"Date", c2Format},
        {"Math", c2Format},
        {"JSON", c2Format},
        {"RegExp", c2Format},
        {"Map", c2Format},
        {"Set", c2Format},
        {"WeakMap", c2Format},
        {"WeakSet", c2Format},
        {"Promise", c2Format},
        {"Proxy", c2Format},
        {"Reflect", c2Format},
        {"Function", c2Format},
        {"Error", c2Format},
        {"EvalError", c2Format},
        {"RangeError", c2Format},
        {"ReferenceError", c2Format},
        {"SyntaxError", c2Format},
        {"TypeError", c2Format},
        {"URIError", c2Format},
        {"window", c2Format},
        {"document", c2Format},
        {"console", c2Format},
        {"alert", c2Format},
        {"confirm", c2Format},
        {"prompt", c2Format},
        {"setTimeout", c1Format},
        {"setInterval", c1Format},
        {"clearTimeout", c1Format},
        {"clearInterval", c1Format},
        {"requestAnimationFrame", c1Format},
        {"cancelAnimationFrame", c1Format},
        {"use", c2Format},
        {"strict", c2Format}
    };

    colormapGo = {
        {"break", c2Format},
        {"case", c2Format},
        {"chan", c2Format},
        {"const", c2Format},
        {"continue", c2Format},
        {"default", c2Format},
        {"defer", c2Format},
        {"else", c2Format},
        {"fallthrough", c1Format},
        {"for", c1Format},
        {"func", c2Format},
        {"go", c2Format},
        {"goto", c2Format},
        {"if", c2Format},
        {"import", c2Format},
        {"interface", c1Format},
        {"map", c1Format},
        {"package", c2Format},
        {"range", c2Format},
        {"return", c2Format},
        {"select", c1Format},
        {"struct", c2Format},
        {"switch", c2Format},
        {"type", c2Format},
        {"var", c2Format},
        {"append", c1Format},
        {"cap", c1Format},
        {"close", c1Format},
        {"complex", c1Format},
        {"copy", c1Format},
        {"delete", c2Format},
        {"imag", c1Format},
        {"len", c1Format},
        {"make", c1Format},
        {"new", c1Format},
        {"panic", c1Format},
        {"print", c1Format},
        {"println", c1Format},
        {"Print", c1Format},
        {"Println", c1Format},
        {"real", c1Format},
        {"recover", c1Format},
        {"bool", c2Format},
        {"byte", c2Format},
        {"complex64", c2Format},
        {"complex128", c2Format},
        {"error", c2Format},
        {"float32", c2Format},
        {"float64", c2Format},
        {"int", c2Format},
        {"int8", c2Format},
        {"int16", c2Format},
        {"int32", c2Format},
        {"int64", c2Format},
        {"rune", c2Format},
        {"string", c2Format},
        {"uint", c2Format},
        {"uint8", c2Format},
        {"uint16", c2Format},
        {"uint32", c2Format},
        {"uint64", c2Format},
        {"uintptr", c2Format},
        {"true", c2Format},
        {"false", c2Format},
        {"nil", c1Format}
    };

    colormapLua = {
        {"if", c1Format},
        {"else", c1Format},
        {"elseif", c1Format},
        {"for", c1Format},
        {"while", c1Format},
        {"repeat", c1Format},
        {"until", c1Format},
        {"break", c1Format},
        {"return", c1Format},
        {"local", c1Format},
        {"function", c1Format},
        {"end", c1Format},
        {"do", c1Format},
        {"not", c1Format},
        {"and", c1Format},
        {"or", c1Format},
        {"in", c1Format},
        {"then", c1Format},
        {"nil", c2Format},
        {"boolean", c2Format},
        {"number", c2Format},
        {"string", c2Format},
        {"table", c2Format},
        {"function", c2Format},
        {"userdata", c2Format},
        {"thread", c2Format},
        {"print", c1Format},
        {"tonumber", c1Format},
        {"tostring", c1Format},
        {"type", c1Format},
        {"pairs", c1Format},
        {"ipairs", c1Format},
        {"next", c1Format},
        {"assert", c1Format},
        {"error", c1Format},
        {"pcall", c1Format},
        {"xpcall", c1Format},
        {"require", c1Format},
        {"load", c1Format},
        {"loadfile", c1Format},
        {"dofile", c1Format},
        {"gcinfo", c1Format}
    };

    colormapCsharp = {
        {"as", c1Format},
        {"base", c1Format},
        {"bool", c1Format},
        {"break", c2Format},
        {"byte", c1Format},
        {"case", c2Format},
        {"catch", c2Format},
        {"char", c1Format},
        {"checked", c1Format},
        {"class", c2Format},
        {"const", c2Format},
        {"continue", c2Format},
        {"decimal", c2Format},
        {"default", c2Format},
        {"delegate", c2Format},
        {"do", c2Format},
        {"double", c2Format},
        {"else", c1Format},
        {"enum", c1Format},
        {"event", c1Format},
        {"explicit", c1Format},
        {"extern", c1Format},
        {"false", c2Format},
        {"finally", c1Format},
        {"fixed", c1Format},
        {"float", c2Format},
        {"for", c1Format},
        {"foreach", c1Format},
        {"goto", c1Format},
        {"if", c1Format},
        {"implicit", c1Format},
        {"in", c1Format},
        {"int", c2Format},
        {"interface", c1Format},
        {"internal", c1Format},
        {"is", c1Format},
        {"lock", c1Format},
        {"long", c2Format},
        {"namespace", c1Format},
        {"new", c2Format},
        {"null", c2Format},
        {"object", c2Format},
        {"operator", c1Format},
        {"out", c1Format},
        {"override", c1Format},
        {"params", c2Format},
        {"private", c2Format},
        {"protected", c2Format},
        {"public", c2Format},
        {"readonly", c1Format},
        {"ref", c2Format},
        {"return", c2Format},
        {"sbyte", c2Format},
        {"sealed", c2Format},
        {"short", c2Format},
        {"sizeof", c1Format},
        {"stackalloc", c2Format},
        {"static", c2Format},
        {"string", c2Format},
        {"struct", c2Format},
        {"switch", c2Format},
        {"this", c2Format},
        {"throw", c1Format},
        {"true", c1Format},
        {"try", c1Format},
        {"typeof", c1Format},
        {"uint", c2Format},
        {"ulong", c2Format},
        {"unchecked", c2Format},
        {"unsafe", c2Format},
        {"ushort", c2Format},
        {"using", c1Format},
        {"virtual", c2Format},
        {"void", c2Format},
        {"volatile", c1Format},
        {"while", c1Format},
        {"var", c2Format},
        {"dynamic", c2Format},
        {"await", c2Format},
        {"async", c2Format},
        {"add", c1Format},
        {"alias", c1Format},
        {"ascending", c1Format},
        {"descending", c1Format},
        {"from", c1Format},
        {"get", c1Format},
        {"global", c2Format},
        {"group", c1Format},
        {"into", c1Format},
        {"join", c1Format},
        {"let", c2Format},
        {"nameof", c1Format},
        {"on", c1Format},
        {"orderby", c1Format},
        {"partial", c1Format},
        {"remove", c1Format},
        {"select", c1Format},
        {"set", c1Format},
        {"value", c1Format},
        {"where", c1Format},
        {"yield", c2Format}
    };

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
    pythonLang.colorMap = colormapPython;

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
    rustLang.fileExtensions = QStringList() << ".rs";
    rustLang.colorMap = colormapRust;

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
    WGSLLang.colorMap = colormapWGSL;

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
    cppLang.fileExtensions = QStringList() << ".cpp";
    cppLang.colorMap = colormapCpp;

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
    jsLang.colorMap = colormapJs;

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
    HTMLLang.colorMap = colormapHTML;

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
    goLang.fileExtensions = QStringList() << ".go";
    goLang.colorMap = colormapGo;

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
    luaLang.fileExtensions = QStringList() << ".lua";
    luaLang.colorMap = colormapLua;

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
    csharpLang.fileExtensions = QStringList() << ".cs";
    csharpLang.colorMap = colormapCsharp;

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
    GLSLLang.colorMap = colormapGLSL;

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
    javaLang.fileExtensions = QStringList() << ".java";
    javaLang.colorMap = colormapJava;

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
    tsLang.fileExtensions = QStringList() << ".ts";
    tsLang.colorMap = colormapTs;

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
    cLang.colorMap = colormapC; // Replace with C-specific color map

    supportedLangs = {pythonLang, rustLang, WGSLLang, cppLang, txtLang, jsLang, HTMLLang, goLang, luaLang, csharpLang, GLSLLang, javaLang, tsLang, cLang};

    currentLang = pythonLang;

    updateDefaultWordLists();

    highlighter = new CodeHighlighter(currentLang, textEdit->document());

    lineNumberTextEdit = ui->textEdit_4;
    lineNumberTextEdit->setReadOnly(true);
    lineNumberTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    findTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    replaceTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    lineEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    connect(textEdit->verticalScrollBar(), &QScrollBar::valueChanged,
            this, &MainWindow::updateScrollBarValue);

    connect(lineNumberTextEdit->verticalScrollBar(), &QScrollBar::valueChanged,
            this, &MainWindow::updateScrollBarValue2);

    textEdit->installEventFilter(this);
    findTextEdit->installEventFilter(this);
    replaceTextEdit->installEventFilter(this);
    this->installEventFilter(this); // for the fullscreen

    bool thm = wantedTheme();
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
        if (QOperatingSystemVersion::current() >= QOperatingSystemVersion::Windows11) {
            windowsVersion = 11;
        }else{
            windowsVersion = 10;
        }
    }

    qDebug() << "Windows version: " << windowsVersion;

    if (thm != settingsThm || windowsVersion != 11)
    {
        changeTheme(thm);
    }
    changeHighlightColors(thm);

    if (!argFileName.isEmpty()){
        globalArgFileName = argFileName;
        on_actionOpen_triggered();
    }

    MainWindow::setupCompleter();

    suggestionBox = new QListWidget(this);
    suggestionBox->setFocusPolicy(Qt::NoFocus);
    suggestionBox->hide();

    actionBox = new QListWidget(this);
    actionBox->setFocusPolicy(Qt::NoFocus);
    actionBox->hide();

    hoverBox = new QTextEdit(this);
    hoverBox->setFont(textEdit->font());
    hoverBox->setFocusPolicy(Qt::NoFocus);
    hoverBox->setWordWrapMode(QTextOption::NoWrap);
    hoverBox->hide();

    updateFonts();

    updateFontSelection();

    lineNumberTextEdit->setUndoRedoEnabled(false);

    connect(suggestionBox, &QListWidget::itemClicked, this, &MainWindow::onSuggestionItemClicked);
    connect(actionBox, &QListWidget::itemClicked, this, &MainWindow::onActionsItemClicked);

    connect(textEdit, &MyTextEdit::mousePositionChanged, this, &MainWindow::handleMouseMoved);
    connect(textEdit, &MyTextEdit::gotoDefinitionActionTriggered, this, &MainWindow::gotoDefinitionActionTriggered);
    connect(textEdit, &MyTextEdit::mouseClicked, this, &MainWindow::mouseClicked);

    connect(showWarnings, &QAction::toggled, this, &MainWindow::saveWantedTheme); // down here because they will call saveWantedTheme when being set otherwise
    connect(showErrors, &QAction::toggled, this, &MainWindow::saveWantedTheme);
    connect(showOther, &QAction::toggled, this, &MainWindow::saveWantedTheme);
    connect(onlyCodeWizardBuiltIn, &QAction::toggled, this, &MainWindow::saveWantedTheme);
    connect(noAutocomplete, &QAction::toggled, this, &MainWindow::saveWantedTheme);
    connect(hoverAction, &QAction::toggled, this, &MainWindow::saveWantedTheme);

    connect(autoSaveAct, &QAction::toggled, this, &MainWindow::saveWantedTheme);
    connect(randomSelectFileTypeAct, &QAction::toggled, this, &MainWindow::saveWantedTheme);
    connect(useFileTree, &QAction::toggled, this, &MainWindow::fileTreeToggled);
    connect(useFileTreeIfFullscreen, &QAction::toggled, this, &MainWindow::fileTreeToggled);
    connect(fileTree, &QTreeView::doubleClicked, this, &MainWindow::fileTreeOpened);

    updateLineNumbers(1);

    //autosave

    QTimer* autoSaveTimer = new QTimer(this);
    connect(autoSaveTimer, &QTimer::timeout, this, &MainWindow::autoSave);
    autoSaveTimer->start(10000);

    // filetree 🤮


    fileTree->setContextMenuPolicy(Qt::CustomContextMenu);

    // Connect the custom context menu signal
    connect(fileTree, &QTreeView::customContextMenuRequested,
            this, &MainWindow::openFileTreeContextMenu);

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
    fileTree->hideColumn(1);  // Hide column at index 1 (Size)
    fileTree->hideColumn(2);  // Hide column at index 2 (Type)
    fileTree->hideColumn(3);  // Hide column at index 2 (Type)

    if (useFileTree->isChecked() && mostRecentPath != ""){
        fileTree->show();
    }else{
        fileTree->hide();
    }

    if (foundationSettings.value("wasFullScreened", false).toBool()){
        setWindowState(Qt::WindowMaximized);
    }
}

void MainWindow::mouseClicked(){
    if (ctrlDown) {
        gotoDefinitionActionTriggered();
    }
}

void MainWindow::onOpenOutside()
{
    QModelIndex index = fileTree->currentIndex();
    if (!index.isValid())
        return;

    QString filePath = fileModel->filePath(index);
    QFileInfo fileInfo(filePath);

    // Use QProcess to open the file with the system's default application
    QProcess process;
    #ifdef Q_OS_WIN
        process.startDetached("cmd", QStringList() << "/c" << "start" << "" << QDir::toNativeSeparators(filePath));
    #elif defined(Q_OS_MAC)
        process.startDetached("open", QStringList() << filePath);
    #else
        process.startDetached("xdg-open", QStringList() << filePath);
    #endif
}

void MainWindow::onOpenInExplorer()
{
    QModelIndex index = fileTree->currentIndex();
    if (!index.isValid())
        return;

    QString filePath = fileModel->filePath(index);
    QFileInfo fileInfo(filePath);
    QDesktopServices::openUrl(QUrl::fromLocalFile(fileInfo.dir().absolutePath()));
}

void MainWindow::onCopyPath()
{
    QModelIndex index = fileTree->currentIndex();
    if (!index.isValid())
        return;

    QString filePath = fileModel->filePath(index);
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(filePath);
}

void MainWindow::openFileTreeContextMenu(const QPoint &pos)
{
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
    if (useFileTree->isChecked() || useFileTreeIfFullscreen->isChecked() && (isFullScreen() || isMaximized())){ // BACK TO HERE YO
        fileTree->show();
    }else{
        fileTree->hide();
    }
}

void MainWindow::on_actionOpen_Folder_triggered(){
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
    QMessageBox messageBox;
    messageBox.setWindowTitle("CodeWizard");
    messageBox.setText("Please retry in a moment, this action is not supported while the LSP is initializing.");
    messageBox.setIcon(QMessageBox::Information);
    messageBox.setStandardButtons(QMessageBox::Ok);
    messageBox.setFont(textEdit->font());
    messageBox.exec();
}

void MainWindow::showHoldYourHorses(){
    QMessageBox messageBox;
    messageBox.setWindowTitle("CodeWizard");
    messageBox.setText("Please retry in a moment, still opening another file.");
    messageBox.setIcon(QMessageBox::Information);
    messageBox.setStandardButtons(QMessageBox::Ok);
    messageBox.setFont(textEdit->font());
    messageBox.exec();
}

void MainWindow::fileTreeOpened(const QModelIndex &index){
    if (isSettingUpLSP){
        showWeDontFuckWithTheLSP();
        return;
    }

    if (isOpeningFile){
        showHoldYourHorses();
        return;
    }

    isOpeningFile = true;

    if (!index.model()->hasChildren(index)) {
        QString newFile = index.data(QFileSystemModel::FilePathRole).toString();

        if (newFile.isEmpty()){
            isOpeningFile = false;
            return;
        }

        if (unsaved && fileName != ""){
            pullUpSaveDialogue();
        }

        fileName = newFile;

        setLangOffFilename(fileName, false);

        unsaved = false;

        QFileInfo fileInfo(fileName);
        QString fileNameName = fileInfo.fileName();

        windowName = "CodeWizard V"+versionNumber+" - "+fileNameName+" - "+fileName;

        QFile file(fileName);
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

        QTextStream in(&file);
        QString fileContent = in.readAll();

        previousLineCount = 1;
        savedText = fileContent;

        textEdit->blockSignals(true);
        textEdit->setPlainText(fileContent);
        textEdit->blockSignals(false);

        previousLineCount = fileContent.count('\xa')+1;
        file.close();

        int cnt = fileContent.count('\n') + 1;

        updateLineNumbers(cnt);
        updateExtraWordsList();

        setWindowTitle(windowName);
        addFileToRecentList(fileName);

        lspMutex.lock();
        setupLSP();
        lspMutex.unlock();
    }
    isOpeningFile = false;
}

void MainWindow::fileTreeToggled(){
    saveWantedTheme();
    if (useFileTree->isChecked() || useFileTreeIfFullscreen->isChecked() && (isFullScreen() || isMaximized())){
        fileTree->show();
    }else{
        fileTree->hide();
    }
}

void MainWindow::autoSave(){
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
    // if (!hoverBox->isHidden()){

    QPoint difference = pos - mousePos;

    if (qAbs(difference.x()) < 20 && qAbs(difference.y()) < 20){
        return;
    }

    expectedHoverInfoId = -1;
    // }

    mousePos = pos;
    hoverBox->hide();

    if (isSettingUpLSP || isOpeningFile){
        return;
    }

    if (!client){
        return;
    }

    QTextCursor cursor = textEdit->cursorForPosition(pos); // Get cursor at mouse position

    QPoint cursorPos = textEdit->cursorRect(cursor).topLeft();

    if (qAbs(cursorPos.x() - pos.x()) > 15 || qAbs(cursorPos.y() - pos.y()) > 15){
        return;
    }

    QRect cursorRect = textEdit->cursorRect(cursor);
    QFontMetrics metrics(textEdit->font());
    int offsetY = metrics.height() * -1;
    int offsetX = metrics.horizontalAdvance("M") * -4;
    suggestedPosition = textEdit->mapToParent(cursorRect.bottomLeft() + QPoint(offsetX, offsetY));

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

            if (line >= sL && line <= eL && column >= sC && column <= eC){
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

                if (qAbs(difference.x()) > 20 || qAbs(difference.y()) > 20){
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
    currentSelection = suggestionBox->row(item);
    fillSuggestions();
    insertCompletion();
}

void MainWindow::onActionsItemClicked(QListWidgetItem* item){
    currentSelectionAction = actionBox->row(item);
    fillActionsBox();
    activateCodeAction();
}

void MainWindow::on_actionLSP_triggered()
{
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

    if (lspPath.isEmpty()){
        return;
    }

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

void MainWindow::setupLSP()
{
    isSettingUpLSP = true;

    if (client){
        client->shutdown();
        delete client;
        client = nullptr;
    }

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

    if (lspPath.isEmpty() || fileName.isEmpty()){
        isSettingUpLSP = false;
        return;
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
        errMessages = messages;
        errStartC = startC;
        errStartL = startL;
        errEndC = endC;
        errEndL = endL;
        errSeverity = severity;
        highlightDiagnostics(false);
    });

    connect(client, &LanguageServerClient::hoverInformationReceived, [this](QString info, QString type, int id) {
        if (id == expectedHoverInfoId){
            moveHoverBox(suggestedPosition, info, type);
        }
    });

    connect(client, &LanguageServerClient::gotoDefinitionsReceived, [this](int line, int character, QString uri) {
        QTextCursor cursor = textEdit->textCursor();
        cursor.setPosition(textEdit->document()->findBlockByNumber(line).position() + character);
        textEdit->setTextCursor(cursor);
        textEdit->ensureCursorVisible();
    });

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

        int offset = metrics.height() * 2;
        QRect cursorRect = textEdit->cursorRect();
        QPoint suggestedPosition = textEdit->mapToParent(cursorRect.bottomLeft() + QPoint(0, offset));

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

    isSettingUpLSP = false;
}

void MainWindow::ShowSuggestionsWithSuperSet(QStringList completions){
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

        int offset = metrics.height() * 2;
        QRect cursorRect = textEdit->cursorRect();
        QPoint suggestedPosition = textEdit->mapToParent(cursorRect.bottomLeft() + QPoint(0, offset));

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
    QString finalString = info.trimmed();

    QStringList lines = finalString.split("\n");
    int lineCount = 0;
    if (type == "markdown"){
        finalString = markdownToHtml(info);
        lineCount = finalString.count("<br>");
        QStringList lines = finalString.split("<br>");
    }else{
        lineCount = finalString.count("\n");
        QStringList lines = finalString.split("\n");
    }

    int maxLength = 0;

    for (const QString& line : lines) {
        maxLength = qMax(maxLength, line.length());
    }

    QFontMetrics metrics(textEdit->font());
    int textHeight = metrics.height() * (lineCount+2); // 2 because it looks better
    int textWidth = metrics.horizontalAdvance('M') * (maxLength + 4); // 4 so that the scrollbar is not overlapping text

    int maxWidth = qMin(textEdit->width()/2, textWidth);
    int maxHeight = qMin(textEdit->height()/3, textHeight);

    hoverBox->resize(maxWidth, maxHeight);

    QPoint newPos = givenPos;
    if (givenPos.x() + maxWidth + 30 > textEdit->width()) { // If it goes beyond the right edge
        newPos.setX(givenPos.x() - maxWidth + 40); // Move it to the left side
    } else {
        newPos.setX(givenPos.x() + 30); // Otherwise, stay on the right
    }

    if (givenPos.y() + maxHeight + 50 > textEdit->height()) {
        newPos.setY(givenPos.y() - maxHeight + 30); // for some reason it starts above the cursor so we move it up less than we do down
    } else {
        newPos.setY(givenPos.y() + 50);
    }

    hoverBox->setTextInteractionFlags(Qt::TextBrowserInteraction); // Enable interaction

    if (type == "markdown"){
        hoverBox->setHtml(finalString);
    }else{
        hoverBox->setPlainText(finalString);
    }

    hoverBox->move(newPos);
    hoverBox->show();
}

QString MainWindow::markdownToHtml(QString markdown) {
    QString html = markdown;

    while (html.contains("\n\n\n")){
        html.replace("\n\n\n", "\n\n");
    }

    while (html.contains("``")){
        html.replace("``", "`");
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
    html.replace("\n", "<br>");
    html.replace("`", "");

    return html;
}

void MainWindow::on_actionIncrease_Text_Size_triggered()
{
    fontSize += 1;
    updateFonts();
    saveWantedTheme();
}

void MainWindow::on_actionReset_Text_Size_triggered()
{
    fontSize = 11;
    updateFonts();
    saveWantedTheme();
}

void MainWindow::on_actionDecrease_Text_Size_triggered()
{
    if (fontSize > 1){
        fontSize -= 1;
    }
    updateFonts();
    saveWantedTheme();
}

void MainWindow::on_actionSet_Text_Size_triggered()
{
    QInputDialog dialog;
    dialog.setFont(textEdit->font());  // Set the font to Arial, size 12
    dialog.setWindowTitle("Font Size");
    dialog.setLabelText("Text Size:");
    dialog.setIntValue(fontSize);
    dialog.setIntMinimum(1);
    dialog.setIntMaximum(50);
    dialog.setIntStep(1);
    dialog.exec();

    if (dialog.result() == QDialog::Accepted) {
        fontSize = dialog.intValue();
        saveWantedTheme();
        updateFonts();
    }
}

void MainWindow::updateFonts()
{
    QFont font = textEdit->font();
    font.setPointSize(fontSize);
    textEdit->setFont(font);

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

    fileTreeContextMenu->setFont(font);

    lineNumberTextEdit->setFont(font);

    lineEdit->setFont(font);
    setTagLineSize();

    int charCount = QString::number(globalLineCount).length();
    int width = metrics.horizontalAdvance('M') * charCount+15;

    lineNumberTextEdit->setMinimumWidth(width);
    lineNumberTextEdit->setMaximumWidth(width);
    lineNumberTextEdit->setFixedWidth(width);

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
    menuHelp->setFont(font);
    menuLanguage->setFont(font);
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
}

void MainWindow::setupCompleter() {
    QObject::connect(textEdit, &QTextEdit::cursorPositionChanged, [=]() {
        suggestionBox->hide();
        actionBox->hide();
        hoverBox->hide();
    });


    QObject::connect(textEdit, &QTextEdit::textChanged, [=]() { // i'm going to make this 'multi-purpose' good luck to any poor soul who comes along and reads this - Kai - this program is a mess. But I love it.
        //This is the only unpoluted textchanged event - lol

        if (!unsaved){
            if (textEdit->toPlainText() != savedText){ // this function also get's called for non text changed events (think highlighting or IDK)
                setWindowTitle("*"+windowName);
                unsaved = true;
            }
        }
        //Here we are going to handle the completer (what this function was supposed to be)

        if (isSettingUpLSP || isOpeningFile){
            return;
        }

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
    wrdLstDefQStringy = currentLang.defWordList;

    wrdLstDefQSetted.clear();
    for (const QString &word : currentLang.defWordList) {
        wrdLstDefQSetted.insert(word);
    }

    setTagLineSize();
}

void MainWindow::setTagLineSize(){
    QFontMetrics metrics(textEdit->font());

    int fontHeight = metrics.height();
    int adjustedHeight = fontHeight + 10;

    if (currentLang.name == "C++" || currentLang.name == "C"){
        lineEdit->setMinimumHeight(adjustedHeight*2);
        lineEdit->setMaximumHeight(adjustedHeight*2);
    }else{
        lineEdit->setMinimumHeight(adjustedHeight);
        lineEdit->setMaximumHeight(adjustedHeight);
    }
}

void MainWindow::fillSuggestions(){
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
    settings.setValue("useFileTree", useFileTree->isChecked());
    settings.setValue("useFiletreeIfFullscreen",  useFileTreeIfFullscreen->isChecked());

    settings.setValue("autoSaveAct", autoSaveAct->isChecked());
    settings.setValue("randomSelectFileTypeAct",randomSelectFileTypeAct->isChecked());

    settings.setValue("fontSize", fontSize);
    settings.setValue("darkModeEnabled", darkmode);
    settings.setValue("currentFont", currentFont);
    settings.setValue("tabWidth", tabWidth);
    settings.setValue("codewizard_version", versionNumber);

}

bool MainWindow::wantedTheme()
{
    QSettings settings("FoundationTechnologies", "CodeWizard");
    bool exists = settings.value("variablesSet", false).toBool();

    if (exists){
        if (settings.value("codewizard_version", "prior 6.0.0").toString() != "prior 6.0.0"){
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

        showWarnings->setChecked(settings.value("showWarnings", true).toBool());
        showErrors->setChecked(settings.value("showErrors", true).toBool());
        showOther->setChecked(settings.value("showOther", true).toBool());
        onlyCodeWizardBuiltIn->setChecked(settings.value("onlyCodeWizardBuiltIn", false).toBool());
        noAutocomplete->setChecked(settings.value("noAutocomplete", false).toBool());
        hoverAction->setChecked(settings.value("hoverAction", true).toBool());
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

        randomSelectFileTypeAct->setChecked(settings.value("randomSelectFileTypeAct", defaultRandomSelect).toBool());

        recentFiles = settings.value("recentFiles", {}).toStringList();
        updateRecentList(recentFiles);

        fontSize = settings.value("fontSize", 11).toInt();
        if (fontSize <= 0){
            fontSize = 11;
        }
        currentFont = settings.value("currentFont", "Monaco").toString();
        tabWidth = settings.value("tabWidth", 4).toInt();
        return settings.value("darkModeEnabled", false).toBool(); // Default to false if not found
    }else{
        QSettings settings("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize", QSettings::NativeFormat);
        return settings.value("AppsUseLightTheme").toInt() == 0;
    }
}

MainWindow::~MainWindow()
{
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
    lineNumberTextEdit->verticalScrollBar()->setValue(value);
}

void MainWindow::updateScrollBarValue2(int value)
{
    textEdit->verticalScrollBar()->setValue(value);
}

void MainWindow::findTriggered()
{
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

void MainWindow::nextTriggered()
{
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
        cursor.setPosition(position);
        cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, find.length());
        textEdit->setTextCursor(cursor);
    }
}


void MainWindow::replaceTriggered()
{
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

void MainWindow::replaceAllTriggered()
{
    QString find = findTextEdit->toPlainText();
    QString replace = replaceTextEdit->toPlainText();

    if (find.isEmpty()) {
        return;
    }

    textEdit->blockSignals(true);

    QTextCursor cursor = textEdit->textCursor(); // Get the current cursor
    cursor.beginEditBlock(); // Begin a single undo block

    QRegularExpression re(QRegularExpression::escape(find), QRegularExpression::CaseInsensitiveOption);
    QTextDocument *document = textEdit->document();
    QTextCursor docCursor(document);

    while (!docCursor.isNull() && !docCursor.atEnd()) {
        docCursor = document->find(re, docCursor);
        if (!docCursor.isNull()) {
            docCursor.insertText(replace);
        }
    }

    cursor.endEditBlock(); // End the undo block

    textEdit->blockSignals(false);
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionOpen_triggered()
{
    if (isSettingUpLSP){
        showWeDontFuckWithTheLSP();
        return;
    }

    if (isOpeningFile){
        showHoldYourHorses();
        return;
    }

    isOpeningFile = true;

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

    if (!newFile.isEmpty()){
        fileName = newFile;
    }else{
        isOpeningFile = false;
        return;
    }

    if (!fileName.isEmpty()) {
        setLangOffFilename(fileName, false);
        unsaved = false;

        QFileInfo fileInfo(fileName);
        QString fileNameName = fileInfo.fileName();

        windowName = "CodeWizard V"+versionNumber+" - "+fileNameName+" - "+fileName;

        QFile file(fileName);
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

        QTextStream in(&file);
        QString fileContent = in.readAll();
        previousLineCount = 1;
        savedText = fileContent;
        textEdit->setPlainText(fileContent);
        previousLineCount = fileContent.count('\xa')+1;
        file.close();

        int cnt = fileContent.count('\n') + 1;
        updateLineNumbers(cnt);

        updateExtraWordsList();

        setWindowTitle(windowName);

        addFileToRecentList(fileName);

        fileModel->setRootPath(fileInfo.absolutePath());
        QSettings settings("FoundationTechnologies", "CodeWizard");
        settings.setValue("mostRecentFolder", fileInfo.absolutePath());

        fileTree->setRootIndex(fileModel->index(fileModel->rootPath()));

        if (useFileTree->isChecked() || useFileTreeIfFullscreen->isChecked() && (isFullScreen() || isMaximized())){ // BACK TO HERE YO
            fileTree->show();
        }else{
            fileTree->hide();
        }

        lspMutex.lock();
        setupLSP();
        lspMutex.unlock();
    }

    isOpeningFile = false;
}

void MainWindow::setLangOffFilename(QString fileName, bool rehigh){
    for (int i = 0; i < supportedLangs.size(); i++){
        for (int j = 0; j < supportedLangs[i].fileExtensions.size(); j++){
            if (fileName.endsWith(supportedLangs[i].fileExtensions[j], Qt::CaseInsensitive)){
                currentLang = supportedLangs[i];
                updateTagLine();
                highlighter->setLanguage(currentLang, rehigh);
                updateDefaultWordLists();
                return;
            }
        }
    }

    highlighter->setLanguage(pythonLang, rehigh);
    currentLang = pythonLang;
    lineEdit->setPlainText(pythonTag);
    updateDefaultWordLists();
}

void MainWindow::updateTagLine(){
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
    if (autoSaveAct->isChecked()){
        on_actionSave_triggered();
        return;
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
    on_actionSave_triggered();
    QProcess *process = new QProcess(this);

    QObject::connect(process, &QProcess::readyReadStandardOutput, [process]() {
        QString output = process->readAllStandardOutput();
    });

    QObject::connect(process, &QProcess::readyReadStandardError, [process]() {
        QString error = process->readAllStandardError();
    });

    QObject::connect(process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
                     [process](int exitCode, QProcess::ExitStatus exitStatus) {
                         process->deleteLater(); // Clean up the process object
                     });

    // Get the file information and path
    QFileInfo fileInfo(fileName);
    QString fileDir = fileInfo.absolutePath();
    QString fileNameName = fileInfo.fileName();

    // Create a temporary directory if not already present
    QString tmpDirPath = "C:/.tmp";
    QDir tmpDir(tmpDirPath);
    if (!tmpDir.exists()) {
        tmpDir.mkpath(tmpDirPath);
    }

    // Define the batch file path
    QString batFilePath = tmpDirPath + "/run_script.bat";

    // Write the command to the .bat file
    QFile batFile(batFilePath);
    if (batFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&batFile);

        QString intermediateTag;

        // Write the necessary command based on the selected language
        if (currentLang.name == "Python") {
            intermediateTag = pythonTag;
        } else if (currentLang.name == "Rust") {
            intermediateTag = rustTag;
        } else if (currentLang.name == "WGSL"){
            intermediateTag = WGSLTag;
        } else if (currentLang.name == "GLSL"){
            intermediateTag = GLSLTag;
        } else if (currentLang.name == "C++"){
            intermediateTag = CppTag;
        } else if (currentLang.name == "JS"){
            intermediateTag = jsTag;
        } else if (currentLang.name == "TS"){
            intermediateTag = tsTag;
        } else if (currentLang.name == "HTML"){
            intermediateTag = HTMLTag;
        } else if (currentLang.name == "Go"){
            intermediateTag = goTag;
        } else if (currentLang.name == "Txt"){
            intermediateTag = txtTag;
        } else if (currentLang.name == "Lua"){
            intermediateTag = luaTag;
        } else if (currentLang.name == "C#"){
            intermediateTag = csharpTag;
        } else if (currentLang.name == "Java"){
            intermediateTag = javaTag;
        } else if (currentLang.name == "C"){
            intermediateTag = cTag;
        }

        intermediateTag.replace("[filename]", fileNameName).replace("[filenameWoutExt]", fileNameName.split('.')[0]);

        out << "cd /d " << fileDir << "\n";
        out << intermediateTag;

        batFile.close();
    }

    // Use 'start cmd /k' to open a new command prompt and run the batch file, keeping the window open after execution
    QStringList arguments;
    arguments << "/c" << "start" << "cmd" << "/k" << batFilePath;

    // Start the process
    process->startDetached("cmd.exe", arguments);
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    qDebug() << "Key release event" << event->modifiers();
    if(event->key() == Qt::Key_Control)
    {
        qDebug() << "Ctrl up now";
        ctrlDown = false;
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Control){
        ctrlDown = true;
    }

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
        }else if (event->key() == Qt::Key_N){
            on_actionNew_triggered();
        }else if (event->key() == Qt::Key_BracketLeft){
            on_actionDe_Increment_Ctrl_triggered();
        }else if (event->key() == Qt::Key_BracketRight){
            on_actionIncrement_Ctrl_triggered();
        }else if (event->key() == Qt::Key_F || event->key() == Qt::Key_H){
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

    if (!selectedText.isEmpty()){
        nextTriggered();
    }
}

void removeOneTabAndAddChar(QString characterToAdd)
{
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
    // Clear previous recordings and reset state
    recordedEvents.clear();
    recordedWidgets.clear();
    recordingMacro = true;
    recordMacroButton->setEnabled(false);
    endRecordMacroButton->setEnabled(true);
    replayMacroButton->setEnabled(false);
}

void MainWindow::on_actionEnd_Macro_Recording_triggered() {
    recordingMacro = false;
    recordMacroButton->setEnabled(true);
    endRecordMacroButton->setEnabled(false);
    replayMacroButton->setEnabled(true);
}

void MainWindow::on_actionReplay_Macro_triggered() {
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
    dialog.setIntValue(0);
    dialog.setIntMinimum(0);
    dialog.setIntMaximum(99999999999999);
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
            int totalLines = textEdit->document()->blockCount(); // Get total number of blocks
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

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type()==QEvent::WindowStateChange){
        onWindowStateChanged();
    }

    if (recordingMacro && (event->type() == QEvent::KeyPress || event->type() == QEvent::KeyRelease)) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);

        // Create a new QKeyEvent using the constructor parameters
        recordedEvents.append(new QKeyEvent(
            keyEvent->type(),      // Type of event (KeyPress/KeyRelease)
            keyEvent->key(),       // The key that was pressed
            keyEvent->modifiers(), // Any modifier keys (Shift, Ctrl, etc.)
            keyEvent->text()       // Text representation of the key
            ));

        recordedWidgets.append(watched);
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

        if (client && !noAutocomplete->isChecked() && !onlyCodeWizardBuiltIn->isChecked()) {
            QString keyStr = key_sequence.toString(QKeySequence::NativeText);

            if (keyStr.length() == 1) {
                QChar ch = keyStr.at(0);
                if (!ch.isSpace()){
                    expectedCompletionId = -1;
                    callCompleteOponUpdate = true;
                }
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

        if (key_sequence == QKeySequence("Shift+Return")) {
            QKeyEvent *enterEvent = new QKeyEvent(
                QEvent::KeyPress, Qt::Key_Return, Qt::NoModifier);
            QApplication::postEvent(textEdit, enterEvent);
            return true; // Mark as handled
        }else if (key_sequence == QKeySequence("Return")) {
            handleTabs();
            //return true;
        }else if (key_sequence == QKeySequence("Alt+3")) {
            on_actionComment_Ctrl_Alt_triggered();
            return true; // Mark as handled
        }else if (key_sequence == QKeySequence("Alt+4")) {
            on_actionUn_Comment_Alt_5_triggered();
            return true; // Mark as handled
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
    }else if (watched == findTextEdit) {
        if (key_event->key() == Qt::Key_Escape) {
            textEdit->setFocus();
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

QString MainWindow::convertLeadingSpacesToTabs(const QString& input) {
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

            // Move the cursor to the start position
            cursor.setPosition(textEdit->document()->findBlockByLineNumber(startLine).position() + startCharacter);

            // Select the range in the QTextEdit
            cursor.setPosition(textEdit->document()->findBlockByLineNumber(endLine).position() + endCharacter, QTextCursor::KeepAnchor);

            // Replace the selected text with the new text
            cursor.insertText(newText);
        }

        cursor.endEditBlock();
        textEdit->blockSignals(false);

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
            cursor.setPosition(textEdit->document()->findBlockByLineNumber(startLine).position() + startCharacter);

            // Select the range in the QTextEdit
            cursor.setPosition(textEdit->document()->findBlockByLineNumber(endLine).position() + endCharacter, QTextCursor::KeepAnchor);

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
    if (isSettingUpLSP){
        showWeDontFuckWithTheLSP();
        return;
    }

    lspMutex.lock();
    if (!client){
        setupLSP();
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

        windowName = "CodeWizard V"+versionNumber+" - "+fileNameName+" - "+fileName;

        addFileToRecentList(fileName);
    }
    saveToFile(textEdit->toPlainText());
    savedText = textEdit->toPlainText();
    setWindowTitle(windowName);

    lspMutex.lock();
    if (client){
        client->documentSaved(textEdit->toPlainText());
    }
    lspMutex.unlock();
}

void MainWindow::centerCursor() {
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
    textEdit->blockSignals(true);
    //disconnect(textEdit, &QTextEdit::textChanged, this, &MainWindow::updateSyntax);
    QTextCursor cursor = textEdit->textCursor();
    int start;
    int end;
    int rawstart;
    int rawend;
    if (cursor.hasSelection()) {
        rawstart = cursor.selectionStart();
        rawend = cursor.selectionEnd();

        start = std::min(rawstart, rawend);
        end = std::max(rawstart, rawend);
    }else{
        rawstart = cursor.position();
        rawend = cursor.position();

        start = std::min(rawstart, rawend);
        end = std::max(rawstart, rawend);
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
    //connect(textEdit, &QTextEdit::textChanged, this, &MainWindow::updateSyntax);
}

void MainWindow::on_actionDe_Increment_Ctrl_triggered()
{
    textEdit->blockSignals(true);
    //disconnect(textEdit, &QTextEdit::textChanged, this, &MainWindow::updateSyntax);
    QTextCursor cursor = textEdit->textCursor();
    int start;
    int end;
    int rawstart;
    int rawend;
    if (cursor.hasSelection()) {
        rawstart = cursor.selectionStart();
        rawend = cursor.selectionEnd();

        start = std::min(rawstart, rawend);
        end = std::max(rawstart, rawend);
    }else{
        rawstart = cursor.position();
        rawend = cursor.position();

        start = std::min(rawstart, rawend);
        end = std::max(rawstart, rawend);
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
    //connect(textEdit, &QTextEdit::textChanged, this, &MainWindow::updateSyntax);
}

void MainWindow::on_actionComment_Ctrl_Alt_triggered()
{
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

        start = std::min(rawstart, rawend);
        end = std::max(rawstart, rawend);
    }else{
        rawstart = cursor.position();
        rawend = cursor.position();

        start = std::min(rawstart, rawend);
        end = std::max(rawstart, rawend);
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

void MainWindow::on_actionUn_Comment_Alt_5_triggered()
{
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

        start = std::min(rawstart, rawend);
        end = std::max(rawstart, rawend);
    }else{
        rawstart = cursor.position();
        rawend = cursor.position();

        start = std::min(rawstart, rawend);
        end = std::max(rawstart, rawend);
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
    darkmode = true;
    changeTheme(darkmode);
    saveWantedTheme();
}

void MainWindow::on_actionLight_Mode_triggered()
{
    darkmode = false;
    changeTheme(darkmode);
    saveWantedTheme();
}

void MainWindow::on_actionTab_Width_triggered()
{
    QInputDialog dialog;
    dialog.setFont(textEdit->font());  // Set the font to Arial, size 12
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
    if (isSettingUpLSP){
        showWeDontFuckWithTheLSP();
        return;
    }

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
    addFileToRecentList(fileName);

    windowName = "CodeWizard V"+versionNumber+" - " + fileNameName + " - " + fileName;
    setWindowTitle(windowName);
    saveToFile(textEdit->toPlainText());
    savedText = textEdit->toPlainText();

    lspMutex.lock();
    setupLSP();
    lspMutex.unlock();
}

void MainWindow::on_actionFix_It_triggered(){ // THE FIX IT BUTTON
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

void MainWindow::on_actionChange_to_IDLE_format_triggered(){ // THE FIX IT BUTTON
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

void MainWindow::highlightDiagnostics(bool reverseTheProcess) // this hurt to get right - don't touch a single line of this shit
{
    textEdit->blockSignals(true);

    QTextCursor blckcursor = textEdit->textCursor();

    int pos = blckcursor.position();

    QTextDocument* doc = textEdit->document();

    if (reverseTheProcess){
        if(errMessages.empty()){
            return;
        }

        for (int i = 0; i < errStartL.size(); ++i) {
            int startLine = errStartL[i];
            int endLine = errEndL[i];
            int startC = errStartC[i];
            int endC = errEndC[i];
            int severity = errSeverity[i];

            // Process each block in the range
            for (int currentLine = startLine; currentLine <= endLine; ++currentLine) {
                QTextBlock block = doc->findBlockByNumber(currentLine);
                if (!block.isValid()) {
                    continue;
                }

                QTextLayout* layout = block.layout();
                if (!layout) {
                    continue;
                }

                QTextLayout::FormatRange range;
                range.format = errorFormats[0];

                // Set start position
                if (currentLine == startLine) {
                    range.start = startC;
                } else {
                    range.start = 0;
                }

                // Set length
                if (currentLine == endLine) {
                    range.length = endC - range.start;
                } else {
                    range.length = block.length() - range.start;
                }

                // Apply the format
                QVector<QTextLayout::FormatRange> formats = layout->formats();
                formats.append(range);
                layout->setFormats(formats);
            }
        }
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
            return;
        }

        for (int i = 0; i < errStartL.size(); ++i) {
            int startLine = errStartL[i];
            int endLine = errEndL[i];
            int startC = errStartC[i];
            int endC = errEndC[i];
            int severity = errSeverity[i];

            if (startLine == endLine && startC == endC){
                startC -= 1;
                if (startC < 0){
                    startC = 0;
                    endC += 1;
                }
            }

            if (!allowedSeverities.contains(severity)){
                continue;
            }

            // Process each block in the range
            for (int currentLine = startLine; currentLine <= endLine; ++currentLine) {
                QTextBlock block = doc->findBlockByNumber(currentLine);
                if (!block.isValid()) {
                    continue;
                }

                QTextLayout* layout = block.layout();
                if (!layout) {
                    continue;
                }

                QTextLayout::FormatRange range;
                range.format = errorFormats[severity];

                // Set start position
                if (currentLine == startLine) {
                    range.start = startC;
                } else {
                    range.start = 0;
                }

                // Set length
                if (currentLine == endLine) {
                    range.length = endC - range.start;
                } else {
                    range.length = block.length() - range.start;
                }

                // Apply the format
                QVector<QTextLayout::FormatRange> formats = layout->formats();
                formats.append(range);
                layout->setFormats(formats);
            }
        }
    }

    blckcursor.setPosition(pos);

    doc->markContentsDirty(0, doc->characterCount());

    textEdit->blockSignals(false);
}

void MainWindow::updateLineNumbers(int count) // good enough
{
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
        lineNumbers << QString::number(i); // Collect line numbers in a list
    }

    QString text = lineNumbers.join("\n");

    lineNumberTextEdit->setPlainText(text);
    lineNumberTextEdit->blockSignals(false);
}



std::tuple<QString, QString, QString, QStringList> MainWindow::getTabDetails(QString lineText)
{
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
                tabs = tabs.removeLast();
                break;
            }
        }
    }

    if (tabs != ""){
        updateSyntaxAdd = tabs;
    }
}

void MainWindow::updateSyntax()
{
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

    int lineCount = textEdit->document()->blockCount();
    // int textLen = text.length();

    if (lineCount != previousLineCount){
        updateLineNumbers(lineCount);
        updateExtraWordsList();
    }

    textEdit->verticalScrollBar()->setValue(vScrollVal);
    textEdit->horizontalScrollBar()->setValue(hScrollVal);

    previousLineCount = lineCount;
    // previousTextLen = textLen;

    connect(textEdit, &QTextEdit::textChanged, this, &MainWindow::updateSyntax);
}

void MainWindow::changeHighlightColors(bool darkmode){
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

void MainWindow::changeTheme(bool darkMode)
{
    // Dark theme style
    QString contextMenuSheet = R"(
        QMenu {
            background-color: rgb(30, 30, 30);
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

        lightPalette.setColor(QPalette::Window, QColor(30, 30, 30));
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
                               "QMenu::item:selected { background-color: rgb(45, 45, 45)); color: white; }"
                               "QMenu::separator {height: 1px;background-color: rgb(255, 255, 255);margin: 2px 4px;}"
                               "QMenuBar::item:hover { background-color: rgb(70, 70, 70); }";
        ui->menuBar->setStyleSheet(menubarSheet);

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
    } else {
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
                                "QMenu::separator {height: 1px;background-color: rgb(0, 0, 0);margin: 2px 4px;}"
                                "QMenuBar::item:hover { background-color: rgb(200, 200, 200); }";
        ui->menuBar->setStyleSheet(menubarSheet);

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

    changeHighlightColors(darkmode);

    normalColorFormat.setForeground(normalColor);

    disconnect(textEdit, &QTextEdit::textChanged, this, &MainWindow::updateSyntax);
    updateSyntax();
    centerCursor();
    connect(textEdit, &QTextEdit::textChanged, this, &MainWindow::updateSyntax);
}

void MainWindow::on_actionCourier_New_2_triggered()
{
    currentFont = "Courier New";
    updateFontSelection();
}

void MainWindow::on_actionCourier_Prime_2_triggered()
{
    currentFont = "Courier Prime";
    updateFontSelection();
}

void MainWindow::on_actionSourceCodePro_2_triggered()
{
    currentFont = "Source Code Pro";
    updateFontSelection();
}

void MainWindow::on_actionUbuntuMono_2_triggered()
{
    currentFont = "Ubuntu Mono";
    updateFontSelection();
}

void MainWindow::on_actionDroidSansMono_2_triggered()
{
    currentFont = "Droid Sans Mono";
    updateFontSelection();
}

void MainWindow::on_actionMonaco_2_triggered()
{
    currentFont = "Monaco";
    updateFontSelection();
}

void MainWindow::on_actionMonospace_2_triggered()
{
    currentFont = "Monospace";
    updateFontSelection();
}

void MainWindow::updateFontSelection()
{
    QFont font = textEdit->font();
    // Update just the font family to Monaco
    font.setFamily(currentFont); // Set to Monaco
    // Reapply the updated font to QTextEdit
    textEdit->setFont(font);
    updateFonts();
    saveWantedTheme();
}

void MainWindow::on_actionRunning_Files_triggered(){
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

void MainWindow::on_actionThe_Fix_It_Button_triggered(){
    openHelpMenu("The Fix It Button\n\n"
                 "The Fix It button was named with grand plans for it, and they still exist. Kinda.\n\n"
                 "Currently the Fix It button serves mainly to change all four space increments (the indenting) to tabs. It is also designed to remove excess whitespace on lines and remove multiple blank lines.\n\n"
                 "The back to IDLE button changes the formating such that the tabs are replaced with four space increments again.");
}

void MainWindow::on_actionCodeWizard_triggered(){
    openHelpMenu("Designed by Adam Mather.\n\nVersion "+versionNumber);
}

void MainWindow::on_actionSettings_triggered(){
    openHelpMenu("The settings for CodeWizard are mostly under the edit tab. Notable settings include:\n\nEdit->Fonts\nEdit->Tab Width\nEdit->Dark Mode\nEdit->Light Mode\nEdit->Auto Save\nView->Use File Tree\nView->Use File Tree If Fullscreen\nLanguage->LSP Settings\n\nNotable Shortcuts:\n\nAlt+Enter - Code Actions (LSP helpers)\nRight Click->Goto Definition (Requires LSP)");
}

void MainWindow::on_actionExtras_triggered(){
    openHelpMenu("Notable Extras:\n\nAuto Save - Runs every 10 seconds, can be disabled with Edit->Auto Save");
}

void MainWindow::on_actionMacros_triggered(){
    openHelpMenu("Macros:\nIn CodeWizard, a macro is a recorded set of keyboard actions. Once a macro is recorded with 'Edit->Start Macro Recording' and 'Edit->End Macro Recording' said macro can then be played back with Ctrl+P or 'Edit->Replay Macro'. If you run a macro '0' times it will run until the end of the file. No, it will not fix your dumb mistakes. Yes, it is a great way to waste time. (I promise) It is worthwhile to note that to stop a macro run amuck you can use Ctrl+P again to stop the macro execution.");
}

void MainWindow::on_actionLSP_2_triggered(){
    openHelpMenu("Language Server Protocol:\n\nFrom CodeWizard V8.0.0 onwards we now support users setting their own Language Server. First set the language you want to set the LSP for, then press Language->Set LSP for language. To specify the LSP to use, type the command needed to run said language server. For example:\n\n   Python - \"jedi-language-server.exe\"\n      Install with \"pip install jedi-language-server\" and ensure \"C:\\Users\\USERNAME\\AppData\\Roaming\\Python\\PythonXX\\Scripts\" is in your path\n\n   C/C++ - \"clangd.exe\"\n      Download from official site\n\n   Rust - \"rust-analyzer.exe\"\n      Download from official site\n\n   TypeScript/JavaScript - \"javascript-typescript-langserver --stdio\"\n      Installed with \"npm install -g javascript-typescript-langserver\"\n\n   Go - \"gopls\"\n      Installed with \"go install golang.org/x/tools/gopls@latest\"\n\n   HTML - \"vscode-html-language-server --stdio\"\n      Installed with \"npm i -g vscode-langservers-extracted\" (also provides vscode-css-language-server, vscode-json-language-server, vscode-eslint-language-server)\n\n\nLanguage Servers Provide the following features to CodeWizard:\n\n   1. Autocompletion\n   2. Hover for info\n   3. Goto definition\n   4. Errors/Warnings\n   5. Code Actions (error correction, formatting, etc)\n\nAll of these can be enabled/disabled under Languages->LSP Settings. There is also the option to disable LSP autocomplete but keep CodeWizard autocomplete, should you prefer it.\n\nExtra Notes:\n   1. When first setting the LSP for a language it may crash, just try again. It usually works the second time.");
}

void MainWindow::openHelpMenu(QString text) {
    // Create a simple help dialog
    QDialog *helpDialog = new QDialog(this);
    helpDialog->setWindowTitle("Help Menu");

    helpDialog->resize(700, 100); // seems to resize to the apropriate size given the text or something

    QLabel *helpText = new QLabel(text, helpDialog);
    helpText->setWordWrap(true); // Enable text wrapping if the text is long
    helpText->setFont(textEdit->font());
    helpText->setTextInteractionFlags(Qt::TextSelectableByMouse);

    // Create a layout for the dialog
    QVBoxLayout *layout = new QVBoxLayout(helpDialog);
    layout->addWidget(helpText);

    // Show the dialog
    helpDialog->setLayout(layout);
    helpDialog->exec(); // Use exec() to block interaction with the main window until closed
}

void MainWindow::on_actionPython_2_triggered(){
    highlighter->setLanguage(pythonLang, true);
    currentLang = pythonLang;
    lineEdit->setPlainText(pythonTag);
    updateDefaultWordLists();
}

void MainWindow::on_actionC_triggered(){
    currentLang = cppLang;
    lineEdit->setPlainText(CppTag);
    highlighter->setLanguage(cppLang, true);
    updateDefaultWordLists();
}

void MainWindow::on_actionWGSL_triggered(){
    currentLang = WGSLLang;
    lineEdit->setPlainText(WGSLTag);
    highlighter->setLanguage(WGSLLang, true);
    updateDefaultWordLists();
}

void MainWindow::on_actionRust_triggered(){
    currentLang = rustLang;
    lineEdit->setPlainText(rustTag);
    highlighter->setLanguage(rustLang, true);
    updateDefaultWordLists();
}

void MainWindow::on_actionHTML_triggered(){
    currentLang = HTMLLang;
    lineEdit->setPlainText(HTMLTag);
    highlighter->setLanguage(HTMLLang, true);
    updateDefaultWordLists();
}

void MainWindow::on_actionGo_triggered(){
    currentLang = goLang;
    lineEdit->setPlainText(goTag);
    highlighter->setLanguage(goLang, true);
    updateDefaultWordLists();
}

void MainWindow::on_actionLua_triggered(){
    currentLang = luaLang;
    lineEdit->setPlainText(luaTag);
    highlighter->setLanguage(luaLang, true);
    updateDefaultWordLists();
}

void MainWindow::on_actionPlaintext_triggered(){
    currentLang = txtLang;
    lineEdit->setPlainText("");
    highlighter->setLanguage(txtLang, true);
    updateDefaultWordLists();
}

void MainWindow::on_actionJavaScript_triggered(){
    currentLang = jsLang;
    lineEdit->setPlainText(jsTag);
    highlighter->setLanguage(jsLang, true);
    updateDefaultWordLists();
}

void MainWindow::on_actionTypeScript_triggered(){
    currentLang = tsLang;
    lineEdit->setPlainText(tsTag);
    highlighter->setLanguage(tsLang, true);
    updateDefaultWordLists();
}

void MainWindow::on_actionC_2_triggered(){
    currentLang = csharpLang;
    lineEdit->setPlainText(csharpTag);
    highlighter->setLanguage(csharpLang, true);
    updateDefaultWordLists();
}

void MainWindow::on_actionC_3_triggered(){
    currentLang = cLang;
    lineEdit->setPlainText(cTag);
    highlighter->setLanguage(cLang, true);
    updateDefaultWordLists();
}

void MainWindow::on_actionGLSL_triggered(){
    currentLang = GLSLLang;
    lineEdit->setPlainText(GLSLTag);
    highlighter->setLanguage(GLSLLang, true);
    updateDefaultWordLists();
}

void MainWindow::on_actionJava_triggered(){
    currentLang = javaLang;
    lineEdit->setPlainText(javaTag);
    highlighter->setLanguage(javaLang, true);
    updateDefaultWordLists();
}

void MainWindow::addFileToRecentList(QString file){
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
    if (isSettingUpLSP){
        showWeDontFuckWithTheLSP();
        return;
    }

    if (isOpeningFile){
        showHoldYourHorses();
        return;
    }

    isOpeningFile = true;

    if (unsaved && fileName != ""){
        pullUpSaveDialogue();
    }

    if (!newFile.isEmpty()){
        fileName = newFile;
    }else{
        isOpeningFile = false;
        return;
    }

    if (!fileName.isEmpty()) {
        setLangOffFilename(fileName, false);
        unsaved = false;

        QFileInfo fileInfo(fileName);
        QString fileDir = fileInfo.absolutePath();
        QString fileNameName = fileInfo.fileName();

        windowName = "CodeWizard V"+versionNumber+" - "+fileNameName+" - "+fileName;
        QFile file(fileName);
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

        QTextStream in(&file);
        QString fileContent = in.readAll();
        previousLineCount = 1;
        savedText = fileContent;
        textEdit->setPlainText(fileContent);
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

        lspMutex.lock();
        setupLSP();
        lspMutex.unlock();
    } 

    isOpeningFile = false;
}
