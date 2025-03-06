/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "useTabsToggled",
    "",
    "addTab",
    "name",
    "file",
    "closeTab",
    "id",
    "tabClicked",
    "on_actionSave_All_Settings_triggered",
    "on_actionLoad_All_Settings_triggered",
    "renameReference",
    "execChanges",
    "QList<std::pair<double,QJsonObject>>",
    "execChangesInOtherFile",
    "changesList",
    "fileUri",
    "updateSplitsWidths",
    "moveWidgetsToSplitter",
    "QLayout*",
    "layout",
    "QWidget*",
    "splitter",
    "storeResizeOfSplitters",
    "updateTermimalViews",
    "on_actionToggleComments_triggered",
    "pullUpReloadDialogue",
    "message",
    "switchTerminalType",
    "findMatchingBracket",
    "direction",
    "handleBracketsOnEnter",
    "handleTerminalStdout",
    "useBuiltinTerminalTriggered",
    "on_actionVim_Modes_triggered",
    "executeNormalAct",
    "QTextCursor::MoveOperation",
    "move",
    "QKeyEvent*",
    "key_event",
    "useVimModesTriggered",
    "on_actionSet_Font_By_Name_triggered",
    "on_actionGit_Integration_triggered",
    "on_actionDiscard_Local_Changes_triggered",
    "on_actionRegular_triggered",
    "on_actionPush_triggered",
    "on_actionKeybindings_triggered",
    "on_actionOpen_Find_Menu_triggered",
    "highlightComparisons",
    "changeToTabs",
    "text",
    "on_actionCompare_2_Files_triggered",
    "on_actionSet_Groq_AI_API_Key_triggered",
    "saveSyntaxColorsToFile",
    "loadSyntaxColorsFromFile",
    "setFormatsFromMyList",
    "str",
    "updateMargins",
    "force",
    "checkForLargeFile",
    "QFile*",
    "clearTSSyntaxHighlighting",
    "changeFindSectionVisibility",
    "visible",
    "checkForFixitDialogue",
    "compareVersionNumbers",
    "vnum1",
    "vnum2",
    "gotoDefinitionReceived",
    "line1",
    "character1",
    "line",
    "character",
    "uri",
    "rehighlightFullDoc",
    "changeOnlyEditsTheme",
    "colorDifference",
    "c1",
    "c2",
    "syntaxColorsOffImage",
    "resetSyntaxColors",
    "validateAndConvert",
    "on_actionSet_Syntax_Colors_triggered",
    "printTree",
    "TSNode",
    "node",
    "depth",
    "setupSyntaxTreeOnOpen",
    "code",
    "doHighlight",
    "onContentsChange",
    "position",
    "charsRemoved",
    "charsAdded",
    "applyEditToTree",
    "startByte",
    "oldEndByte",
    "newEndByte",
    "startPointRow",
    "startPointColumn",
    "oldEndPointRow",
    "oldEndPointColumn",
    "newEndPointRow",
    "newEndPointColumn",
    "onOpenInExplorer",
    "onCopyPath",
    "onOpenOutside",
    "mouseClicked",
    "mouseReleased",
    "openFileTreeContextMenu",
    "pos",
    "getTabDetails",
    "std::tuple<QString,QString,QString,QStringList>",
    "setupLSP",
    "oldFile",
    "plaintextToHtml",
    "plaintext",
    "showWeDontFuckWithTheLSP",
    "showHoldYourHorses",
    "fileTreeToggled",
    "fileTreeOpened",
    "QModelIndex",
    "index",
    "convertLeadingSpacesToTabs",
    "input",
    "ShowSuggestionsWithSuperSet",
    "completions",
    "gotoDefinitionActionTriggered",
    "renameActionTriggered",
    "highlightDiagnostics",
    "autoSave",
    "moveHoverBox",
    "givenPos",
    "info",
    "type",
    "handleMouseMoved",
    "on_actionLSP_triggered",
    "on_actionLSP_2_triggered",
    "insertCompletion",
    "activateCodeAction",
    "pullUpSaveDialogue",
    "onWindowStateChanged",
    "onSuggestionItemClicked",
    "QListWidgetItem*",
    "onActionsItemClicked",
    "on_actionOpen_Folder_triggered",
    "on_actionStart_Macro_Recording_triggered",
    "on_actionEnd_Macro_Recording_triggered",
    "on_actionReplay_Macro_triggered",
    "on_actionExit_triggered",
    "on_actionOpen_triggered",
    "dontUpdateFileTree",
    "on_actionSave_triggered",
    "on_actionSave_As_triggered",
    "on_actionNew_triggered",
    "on_actionRun_Module_F5_triggered",
    "on_actionIncrement_Ctrl_triggered",
    "on_actionDe_Increment_Ctrl_triggered",
    "on_actionFix_It_triggered",
    "on_actionComment_Ctrl_Alt_triggered",
    "on_actionUn_Comment_Alt_5_triggered",
    "on_actionIncrease_Text_Size_triggered",
    "on_actionDecrease_Text_Size_triggered",
    "on_actionSet_Text_Size_triggered",
    "on_actionReset_Text_Size_triggered",
    "on_actionChange_to_IDLE_format_triggered",
    "on_actionTab_Width_triggered",
    "on_actionSettings_triggered",
    "on_actionExtras_triggered",
    "on_actionMacros_triggered",
    "on_actionCourier_New_2_triggered",
    "on_actionDroidSansMono_2_triggered",
    "on_actionMonaco_2_triggered",
    "on_actionMonospace_2_triggered",
    "on_actionCourier_Prime_2_triggered",
    "on_actionSourceCodePro_2_triggered",
    "on_actionUbuntuMono_2_triggered",
    "on_actionRunning_Files_triggered",
    "on_actionThe_Fix_It_Button_triggered",
    "on_actionCodeWizard_triggered",
    "on_actionPython_2_triggered",
    "on_actionJavaScript_triggered",
    "on_actionTypeScript_triggered",
    "on_actionHTML_triggered",
    "on_actionGo_triggered",
    "on_actionC_triggered",
    "on_actionC_2_triggered",
    "on_actionC_3_triggered",
    "on_actionRust_triggered",
    "on_actionWGSL_triggered",
    "on_actionGLSL_triggered",
    "on_actionPlaintext_triggered",
    "on_actionLua_triggered",
    "on_actionJava_triggered",
    "updateTagLine",
    "updateDefaultWordLists",
    "updateSyntax",
    "findTriggered",
    "nextTriggered",
    "previousTriggered",
    "replaceTriggered",
    "replaceAllTriggered",
    "updateLineNumbers",
    "updateScrollBarValue",
    "updateScrollBarValue2",
    "changeTheme",
    "on_actionDark_Mode_triggered",
    "on_actionLight_Mode_triggered",
    "wantedTheme",
    "saveWantedTheme",
    "openFind",
    "findTextEditChanged",
    "centerCursor",
    "updateFonts",
    "setupCompleter",
    "getCurrentWord",
    "updateExtraWordsList",
    "fillSuggestions",
    "fillActionsBox",
    "updateFontSelection",
    "changeHighlightColors",
    "openHelpMenu",
    "setLangOffFilename",
    "addFileToRecentList",
    "updateRecentList",
    "openRecentFile",
    "handleTabs",
    "markdownToHtml"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
     169,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0, 1028,    2, 0x08,    1 /* Private */,
       3,    2, 1029,    2, 0x08,    2 /* Private */,
       6,    1, 1034,    2, 0x08,    5 /* Private */,
       8,    1, 1037,    2, 0x08,    7 /* Private */,
       9,    0, 1040,    2, 0x08,    9 /* Private */,
      10,    0, 1041,    2, 0x08,   10 /* Private */,
      11,    1, 1042,    2, 0x08,   11 /* Private */,
      12,    1, 1045,    2, 0x08,   13 /* Private */,
      14,    2, 1048,    2, 0x08,   15 /* Private */,
      17,    0, 1053,    2, 0x08,   18 /* Private */,
      18,    2, 1054,    2, 0x08,   19 /* Private */,
      23,    0, 1059,    2, 0x08,   22 /* Private */,
      24,    0, 1060,    2, 0x08,   23 /* Private */,
      25,    0, 1061,    2, 0x08,   24 /* Private */,
      26,    1, 1062,    2, 0x08,   25 /* Private */,
      28,    0, 1065,    2, 0x08,   27 /* Private */,
      29,    1, 1066,    2, 0x08,   28 /* Private */,
      31,    0, 1069,    2, 0x08,   30 /* Private */,
      32,    0, 1070,    2, 0x08,   31 /* Private */,
      33,    0, 1071,    2, 0x08,   32 /* Private */,
      34,    0, 1072,    2, 0x08,   33 /* Private */,
      35,    2, 1073,    2, 0x08,   34 /* Private */,
      40,    0, 1078,    2, 0x08,   37 /* Private */,
      41,    0, 1079,    2, 0x08,   38 /* Private */,
      42,    0, 1080,    2, 0x08,   39 /* Private */,
      43,    0, 1081,    2, 0x08,   40 /* Private */,
      44,    0, 1082,    2, 0x08,   41 /* Private */,
      45,    0, 1083,    2, 0x08,   42 /* Private */,
      46,    0, 1084,    2, 0x08,   43 /* Private */,
      47,    0, 1085,    2, 0x08,   44 /* Private */,
      48,    0, 1086,    2, 0x08,   45 /* Private */,
      49,    1, 1087,    2, 0x08,   46 /* Private */,
      51,    0, 1090,    2, 0x08,   48 /* Private */,
      52,    0, 1091,    2, 0x08,   49 /* Private */,
      53,    0, 1092,    2, 0x08,   50 /* Private */,
      54,    0, 1093,    2, 0x08,   51 /* Private */,
      55,    1, 1094,    2, 0x08,   52 /* Private */,
      57,    1, 1097,    2, 0x08,   54 /* Private */,
      59,    1, 1100,    2, 0x08,   56 /* Private */,
      61,    0, 1103,    2, 0x08,   58 /* Private */,
      62,    1, 1104,    2, 0x08,   59 /* Private */,
      64,    0, 1107,    2, 0x08,   61 /* Private */,
      65,    2, 1108,    2, 0x08,   62 /* Private */,
      68,    5, 1113,    2, 0x08,   65 /* Private */,
      74,    0, 1124,    2, 0x08,   71 /* Private */,
      75,    1, 1125,    2, 0x08,   72 /* Private */,
      76,    2, 1128,    2, 0x08,   74 /* Private */,
      79,    0, 1133,    2, 0x08,   77 /* Private */,
      80,    0, 1134,    2, 0x08,   78 /* Private */,
      81,    0, 1135,    2, 0x08,   79 /* Private */,
      82,    0, 1136,    2, 0x08,   80 /* Private */,
      83,    2, 1137,    2, 0x08,   81 /* Private */,
      83,    1, 1142,    2, 0x28,   84 /* Private | MethodCloned */,
      87,    2, 1145,    2, 0x08,   86 /* Private */,
      87,    1, 1150,    2, 0x28,   89 /* Private | MethodCloned */,
      90,    3, 1153,    2, 0x08,   91 /* Private */,
      94,    9, 1160,    2, 0x08,   95 /* Private */,
     104,    0, 1179,    2, 0x08,  105 /* Private */,
     105,    0, 1180,    2, 0x08,  106 /* Private */,
     106,    0, 1181,    2, 0x08,  107 /* Private */,
     107,    0, 1182,    2, 0x08,  108 /* Private */,
     108,    0, 1183,    2, 0x08,  109 /* Private */,
     109,    1, 1184,    2, 0x08,  110 /* Private */,
     111,    1, 1187,    2, 0x08,  112 /* Private */,
     113,    1, 1190,    2, 0x08,  114 /* Private */,
     115,    1, 1193,    2, 0x08,  116 /* Private */,
     117,    0, 1196,    2, 0x08,  118 /* Private */,
     118,    0, 1197,    2, 0x08,  119 /* Private */,
     119,    0, 1198,    2, 0x08,  120 /* Private */,
     120,    1, 1199,    2, 0x08,  121 /* Private */,
     123,    1, 1202,    2, 0x08,  123 /* Private */,
     125,    1, 1205,    2, 0x08,  125 /* Private */,
     127,    0, 1208,    2, 0x08,  127 /* Private */,
     128,    0, 1209,    2, 0x08,  128 /* Private */,
     129,    1, 1210,    2, 0x08,  129 /* Private */,
     130,    0, 1213,    2, 0x08,  131 /* Private */,
     131,    3, 1214,    2, 0x08,  132 /* Private */,
     135,    1, 1221,    2, 0x08,  136 /* Private */,
     136,    0, 1224,    2, 0x08,  138 /* Private */,
     137,    0, 1225,    2, 0x08,  139 /* Private */,
     138,    0, 1226,    2, 0x08,  140 /* Private */,
     139,    0, 1227,    2, 0x08,  141 /* Private */,
     140,    0, 1228,    2, 0x08,  142 /* Private */,
     141,    0, 1229,    2, 0x08,  143 /* Private */,
     142,    1, 1230,    2, 0x08,  144 /* Private */,
     144,    1, 1233,    2, 0x08,  146 /* Private */,
     145,    0, 1236,    2, 0x08,  148 /* Private */,
     146,    0, 1237,    2, 0x08,  149 /* Private */,
     147,    0, 1238,    2, 0x08,  150 /* Private */,
     148,    0, 1239,    2, 0x08,  151 /* Private */,
     149,    0, 1240,    2, 0x08,  152 /* Private */,
     150,    1, 1241,    2, 0x08,  153 /* Private */,
     150,    0, 1244,    2, 0x28,  155 /* Private | MethodCloned */,
     152,    0, 1245,    2, 0x08,  156 /* Private */,
     153,    0, 1246,    2, 0x08,  157 /* Private */,
     154,    0, 1247,    2, 0x08,  158 /* Private */,
     155,    0, 1248,    2, 0x08,  159 /* Private */,
     156,    0, 1249,    2, 0x08,  160 /* Private */,
     157,    0, 1250,    2, 0x08,  161 /* Private */,
     158,    0, 1251,    2, 0x08,  162 /* Private */,
     159,    0, 1252,    2, 0x08,  163 /* Private */,
     160,    0, 1253,    2, 0x08,  164 /* Private */,
     161,    0, 1254,    2, 0x08,  165 /* Private */,
     162,    0, 1255,    2, 0x08,  166 /* Private */,
     163,    0, 1256,    2, 0x08,  167 /* Private */,
     164,    0, 1257,    2, 0x08,  168 /* Private */,
     165,    0, 1258,    2, 0x08,  169 /* Private */,
     166,    0, 1259,    2, 0x08,  170 /* Private */,
     167,    0, 1260,    2, 0x08,  171 /* Private */,
     168,    0, 1261,    2, 0x08,  172 /* Private */,
     169,    0, 1262,    2, 0x08,  173 /* Private */,
     170,    0, 1263,    2, 0x08,  174 /* Private */,
     171,    0, 1264,    2, 0x08,  175 /* Private */,
     172,    0, 1265,    2, 0x08,  176 /* Private */,
     173,    0, 1266,    2, 0x08,  177 /* Private */,
     174,    0, 1267,    2, 0x08,  178 /* Private */,
     175,    0, 1268,    2, 0x08,  179 /* Private */,
     176,    0, 1269,    2, 0x08,  180 /* Private */,
     177,    0, 1270,    2, 0x08,  181 /* Private */,
     178,    0, 1271,    2, 0x08,  182 /* Private */,
     179,    0, 1272,    2, 0x08,  183 /* Private */,
     180,    0, 1273,    2, 0x08,  184 /* Private */,
     181,    0, 1274,    2, 0x08,  185 /* Private */,
     182,    0, 1275,    2, 0x08,  186 /* Private */,
     183,    0, 1276,    2, 0x08,  187 /* Private */,
     184,    0, 1277,    2, 0x08,  188 /* Private */,
     185,    0, 1278,    2, 0x08,  189 /* Private */,
     186,    0, 1279,    2, 0x08,  190 /* Private */,
     187,    0, 1280,    2, 0x08,  191 /* Private */,
     188,    0, 1281,    2, 0x08,  192 /* Private */,
     189,    0, 1282,    2, 0x08,  193 /* Private */,
     190,    0, 1283,    2, 0x08,  194 /* Private */,
     191,    0, 1284,    2, 0x08,  195 /* Private */,
     192,    0, 1285,    2, 0x08,  196 /* Private */,
     193,    0, 1286,    2, 0x08,  197 /* Private */,
     194,    0, 1287,    2, 0x08,  198 /* Private */,
     195,    0, 1288,    2, 0x08,  199 /* Private */,
     196,    0, 1289,    2, 0x08,  200 /* Private */,
     197,    0, 1290,    2, 0x08,  201 /* Private */,
     198,    0, 1291,    2, 0x08,  202 /* Private */,
     199,    0, 1292,    2, 0x08,  203 /* Private */,
     200,    0, 1293,    2, 0x08,  204 /* Private */,
     201,    0, 1294,    2, 0x08,  205 /* Private */,
     202,    1, 1295,    2, 0x08,  206 /* Private */,
     203,    1, 1298,    2, 0x08,  208 /* Private */,
     204,    1, 1301,    2, 0x08,  210 /* Private */,
     205,    1, 1304,    2, 0x08,  212 /* Private */,
     206,    0, 1307,    2, 0x08,  214 /* Private */,
     207,    0, 1308,    2, 0x08,  215 /* Private */,
     208,    0, 1309,    2, 0x08,  216 /* Private */,
     209,    0, 1310,    2, 0x08,  217 /* Private */,
     210,    0, 1311,    2, 0x08,  218 /* Private */,
     211,    0, 1312,    2, 0x08,  219 /* Private */,
     212,    0, 1313,    2, 0x08,  220 /* Private */,
     213,    0, 1314,    2, 0x08,  221 /* Private */,
     214,    0, 1315,    2, 0x08,  222 /* Private */,
     215,    0, 1316,    2, 0x08,  223 /* Private */,
     216,    0, 1317,    2, 0x08,  224 /* Private */,
     217,    0, 1318,    2, 0x08,  225 /* Private */,
     218,    0, 1319,    2, 0x08,  226 /* Private */,
     219,    0, 1320,    2, 0x08,  227 /* Private */,
     220,    1, 1321,    2, 0x08,  228 /* Private */,
     221,    1, 1324,    2, 0x08,  230 /* Private */,
     222,    2, 1327,    2, 0x08,  232 /* Private */,
     223,    1, 1332,    2, 0x08,  235 /* Private */,
     224,    1, 1335,    2, 0x08,  237 /* Private */,
     225,    1, 1338,    2, 0x08,  239 /* Private */,
     226,    0, 1341,    2, 0x08,  241 /* Private */,
     227,    1, 1342,    2, 0x08,  242 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    4,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonObject,    2,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void, 0x80000000 | 13, QMetaType::QString,   15,   16,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19, 0x80000000 | 21,   20,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   27,
    QMetaType::Void,
    QMetaType::Int, QMetaType::Int,   30,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 36, 0x80000000 | 38,   37,   39,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString, QMetaType::QString,   50,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   56,
    QMetaType::Void, QMetaType::Bool,   58,
    QMetaType::Bool, 0x80000000 | 60,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   63,
    QMetaType::Void,
    QMetaType::Int, QMetaType::QString, QMetaType::QString,   66,   67,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString,   69,   70,   71,   72,   73,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Int, QMetaType::QColor, QMetaType::QColor,   77,   78,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 84, QMetaType::Int,   85,   86,
    QMetaType::Void, 0x80000000 | 84,   85,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   88,   89,
    QMetaType::Void, QMetaType::QString,   88,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   91,   92,   93,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   95,   96,   97,   98,   99,  100,  101,  102,  103,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,  110,
    0x80000000 | 112, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,  114,
    QMetaType::QString, QMetaType::QString,  116,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 121,  122,
    QMetaType::QString, QMetaType::QString,  124,
    QMetaType::Void, QMetaType::QStringList,  126,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint, QMetaType::QString, QMetaType::QString,  132,  133,  134,
    QMetaType::Void, QMetaType::QPoint,  110,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 143,    2,
    QMetaType::Void, 0x80000000 | 143,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,  151,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::QString, QMetaType::QString,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'useTabsToggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addTab'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'closeTab'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'tabClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_actionSave_All_Settings_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionLoad_All_Settings_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'renameReference'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>,
        // method 'execChanges'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<QPair<double,QJsonObject>>, std::false_type>,
        // method 'execChangesInOtherFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<QPair<double,QJsonObject>>, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'updateSplitsWidths'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'moveWidgetsToSplitter'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QLayout *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QWidget *, std::false_type>,
        // method 'storeResizeOfSplitters'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateTermimalViews'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionToggleComments_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pullUpReloadDialogue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'switchTerminalType'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'findMatchingBracket'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'handleBracketsOnEnter'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleTerminalStdout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'useBuiltinTerminalTriggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionVim_Modes_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'executeNormalAct'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTextCursor::MoveOperation, std::false_type>,
        QtPrivate::TypeAndForceComplete<QKeyEvent *, std::false_type>,
        // method 'useVimModesTriggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionSet_Font_By_Name_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionGit_Integration_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionDiscard_Local_Changes_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionRegular_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionPush_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionKeybindings_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionOpen_Find_Menu_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'highlightComparisons'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'changeToTabs'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'on_actionCompare_2_Files_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionSet_Groq_AI_API_Key_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'saveSyntaxColorsToFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loadSyntaxColorsFromFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setFormatsFromMyList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'updateMargins'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'checkForLargeFile'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<QFile *, std::false_type>,
        // method 'clearTSSyntaxHighlighting'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'changeFindSectionVisibility'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'checkForFixitDialogue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'compareVersionNumbers'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'gotoDefinitionReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'rehighlightFullDoc'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'changeOnlyEditsTheme'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'colorDifference'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QColor, std::false_type>,
        QtPrivate::TypeAndForceComplete<QColor, std::false_type>,
        // method 'syntaxColorsOffImage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'resetSyntaxColors'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'validateAndConvert'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionSet_Syntax_Colors_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'printTree'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<TSNode, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'printTree'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<TSNode, std::false_type>,
        // method 'setupSyntaxTreeOnOpen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setupSyntaxTreeOnOpen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'onContentsChange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'applyEditToTree'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onOpenInExplorer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onCopyPath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onOpenOutside'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'mouseClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'mouseReleased'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openFileTreeContextMenu'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>,
        // method 'getTabDetails'
        QtPrivate::TypeAndForceComplete<std::tuple<QString,QString,QString,QStringList>, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'setupLSP'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'plaintextToHtml'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'showWeDontFuckWithTheLSP'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showHoldYourHorses'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'fileTreeToggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'fileTreeOpened'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'convertLeadingSpacesToTabs'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'ShowSuggestionsWithSuperSet'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'gotoDefinitionActionTriggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'renameActionTriggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'highlightDiagnostics'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'autoSave'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'moveHoverBox'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPoint, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'handleMouseMoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPoint, std::false_type>,
        // method 'on_actionLSP_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionLSP_2_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'insertCompletion'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'activateCodeAction'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'pullUpSaveDialogue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onWindowStateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSuggestionItemClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'onActionsItemClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'on_actionOpen_Folder_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionStart_Macro_Recording_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionEnd_Macro_Recording_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionReplay_Macro_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionExit_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionOpen_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_actionOpen_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionSave_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionSave_As_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionNew_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionRun_Module_F5_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionIncrement_Ctrl_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionDe_Increment_Ctrl_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionFix_It_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionComment_Ctrl_Alt_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionUn_Comment_Alt_5_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionIncrease_Text_Size_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionDecrease_Text_Size_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionSet_Text_Size_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionReset_Text_Size_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionChange_to_IDLE_format_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionTab_Width_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionSettings_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionExtras_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionMacros_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionCourier_New_2_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionDroidSansMono_2_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionMonaco_2_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionMonospace_2_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionCourier_Prime_2_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionSourceCodePro_2_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionUbuntuMono_2_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionRunning_Files_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionThe_Fix_It_Button_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionCodeWizard_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionPython_2_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionJavaScript_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionTypeScript_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionHTML_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionGo_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionC_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionC_2_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionC_3_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionRust_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionWGSL_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionGLSL_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionPlaintext_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionLua_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionJava_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateTagLine'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateDefaultWordLists'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateSyntax'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'findTriggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'nextTriggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'previousTriggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'replaceTriggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'replaceAllTriggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateLineNumbers'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'updateScrollBarValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'updateScrollBarValue2'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'changeTheme'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_actionDark_Mode_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionLight_Mode_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'wantedTheme'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveWantedTheme'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openFind'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'findTextEditChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'centerCursor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateFonts'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setupCompleter'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getCurrentWord'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'updateExtraWordsList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'fillSuggestions'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'fillActionsBox'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateFontSelection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'changeHighlightColors'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'openHelpMenu'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'setLangOffFilename'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'addFileToRecentList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'updateRecentList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'openRecentFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'handleTabs'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'markdownToHtml'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->useTabsToggled(); break;
        case 1: _t->addTab((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 2: _t->closeTab((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->tabClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->on_actionSave_All_Settings_triggered(); break;
        case 5: _t->on_actionLoad_All_Settings_triggered(); break;
        case 6: _t->renameReference((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 7: _t->execChanges((*reinterpret_cast< std::add_pointer_t<QList<std::pair<double,QJsonObject>>>>(_a[1]))); break;
        case 8: _t->execChangesInOtherFile((*reinterpret_cast< std::add_pointer_t<QList<std::pair<double,QJsonObject>>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 9: _t->updateSplitsWidths(); break;
        case 10: _t->moveWidgetsToSplitter((*reinterpret_cast< std::add_pointer_t<QLayout*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[2]))); break;
        case 11: _t->storeResizeOfSplitters(); break;
        case 12: _t->updateTermimalViews(); break;
        case 13: _t->on_actionToggleComments_triggered(); break;
        case 14: _t->pullUpReloadDialogue((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 15: _t->switchTerminalType(); break;
        case 16: { int _r = _t->findMatchingBracket((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 17: _t->handleBracketsOnEnter(); break;
        case 18: _t->handleTerminalStdout(); break;
        case 19: _t->useBuiltinTerminalTriggered(); break;
        case 20: _t->on_actionVim_Modes_triggered(); break;
        case 21: _t->executeNormalAct((*reinterpret_cast< std::add_pointer_t<QTextCursor::MoveOperation>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QKeyEvent*>>(_a[2]))); break;
        case 22: _t->useVimModesTriggered(); break;
        case 23: _t->on_actionSet_Font_By_Name_triggered(); break;
        case 24: _t->on_actionGit_Integration_triggered(); break;
        case 25: _t->on_actionDiscard_Local_Changes_triggered(); break;
        case 26: _t->on_actionRegular_triggered(); break;
        case 27: _t->on_actionPush_triggered(); break;
        case 28: _t->on_actionKeybindings_triggered(); break;
        case 29: _t->on_actionOpen_Find_Menu_triggered(); break;
        case 30: _t->highlightComparisons(); break;
        case 31: { QString _r = _t->changeToTabs((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 32: _t->on_actionCompare_2_Files_triggered(); break;
        case 33: _t->on_actionSet_Groq_AI_API_Key_triggered(); break;
        case 34: _t->saveSyntaxColorsToFile(); break;
        case 35: _t->loadSyntaxColorsFromFile(); break;
        case 36: _t->setFormatsFromMyList((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 37: _t->updateMargins((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 38: { bool _r = _t->checkForLargeFile((*reinterpret_cast< std::add_pointer_t<QFile*>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 39: _t->clearTSSyntaxHighlighting(); break;
        case 40: _t->changeFindSectionVisibility((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 41: _t->checkForFixitDialogue(); break;
        case 42: { int _r = _t->compareVersionNumbers((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 43: _t->gotoDefinitionReceived((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 44: _t->rehighlightFullDoc(); break;
        case 45: _t->changeOnlyEditsTheme((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 46: { int _r = _t->colorDifference((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 47: _t->syntaxColorsOffImage(); break;
        case 48: _t->resetSyntaxColors(); break;
        case 49: _t->validateAndConvert(); break;
        case 50: _t->on_actionSet_Syntax_Colors_triggered(); break;
        case 51: _t->printTree((*reinterpret_cast< std::add_pointer_t<TSNode>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 52: _t->printTree((*reinterpret_cast< std::add_pointer_t<TSNode>>(_a[1]))); break;
        case 53: _t->setupSyntaxTreeOnOpen((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 54: _t->setupSyntaxTreeOnOpen((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 55: _t->onContentsChange((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 56: _t->applyEditToTree((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[9]))); break;
        case 57: _t->onOpenInExplorer(); break;
        case 58: _t->onCopyPath(); break;
        case 59: _t->onOpenOutside(); break;
        case 60: _t->mouseClicked(); break;
        case 61: _t->mouseReleased(); break;
        case 62: _t->openFileTreeContextMenu((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 63: { std::tuple<QString,QString,QString,QStringList> _r = _t->getTabDetails((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< std::tuple<QString,QString,QString,QStringList>*>(_a[0]) = std::move(_r); }  break;
        case 64: _t->setupLSP((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 65: { QString _r = _t->plaintextToHtml((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 66: _t->showWeDontFuckWithTheLSP(); break;
        case 67: _t->showHoldYourHorses(); break;
        case 68: _t->fileTreeToggled(); break;
        case 69: _t->fileTreeOpened((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 70: { QString _r = _t->convertLeadingSpacesToTabs((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 71: _t->ShowSuggestionsWithSuperSet((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 72: _t->gotoDefinitionActionTriggered(); break;
        case 73: _t->renameActionTriggered(); break;
        case 74: _t->highlightDiagnostics((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 75: _t->autoSave(); break;
        case 76: _t->moveHoverBox((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 77: _t->handleMouseMoved((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 78: _t->on_actionLSP_triggered(); break;
        case 79: _t->on_actionLSP_2_triggered(); break;
        case 80: { bool _r = _t->insertCompletion();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 81: { bool _r = _t->activateCodeAction();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 82: _t->pullUpSaveDialogue(); break;
        case 83: _t->onWindowStateChanged(); break;
        case 84: _t->onSuggestionItemClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 85: _t->onActionsItemClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 86: _t->on_actionOpen_Folder_triggered(); break;
        case 87: _t->on_actionStart_Macro_Recording_triggered(); break;
        case 88: _t->on_actionEnd_Macro_Recording_triggered(); break;
        case 89: _t->on_actionReplay_Macro_triggered(); break;
        case 90: _t->on_actionExit_triggered(); break;
        case 91: _t->on_actionOpen_triggered((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 92: _t->on_actionOpen_triggered(); break;
        case 93: _t->on_actionSave_triggered(); break;
        case 94: _t->on_actionSave_As_triggered(); break;
        case 95: _t->on_actionNew_triggered(); break;
        case 96: _t->on_actionRun_Module_F5_triggered(); break;
        case 97: _t->on_actionIncrement_Ctrl_triggered(); break;
        case 98: _t->on_actionDe_Increment_Ctrl_triggered(); break;
        case 99: _t->on_actionFix_It_triggered(); break;
        case 100: _t->on_actionComment_Ctrl_Alt_triggered(); break;
        case 101: _t->on_actionUn_Comment_Alt_5_triggered(); break;
        case 102: _t->on_actionIncrease_Text_Size_triggered(); break;
        case 103: _t->on_actionDecrease_Text_Size_triggered(); break;
        case 104: _t->on_actionSet_Text_Size_triggered(); break;
        case 105: _t->on_actionReset_Text_Size_triggered(); break;
        case 106: _t->on_actionChange_to_IDLE_format_triggered(); break;
        case 107: _t->on_actionTab_Width_triggered(); break;
        case 108: _t->on_actionSettings_triggered(); break;
        case 109: _t->on_actionExtras_triggered(); break;
        case 110: _t->on_actionMacros_triggered(); break;
        case 111: _t->on_actionCourier_New_2_triggered(); break;
        case 112: _t->on_actionDroidSansMono_2_triggered(); break;
        case 113: _t->on_actionMonaco_2_triggered(); break;
        case 114: _t->on_actionMonospace_2_triggered(); break;
        case 115: _t->on_actionCourier_Prime_2_triggered(); break;
        case 116: _t->on_actionSourceCodePro_2_triggered(); break;
        case 117: _t->on_actionUbuntuMono_2_triggered(); break;
        case 118: _t->on_actionRunning_Files_triggered(); break;
        case 119: _t->on_actionThe_Fix_It_Button_triggered(); break;
        case 120: _t->on_actionCodeWizard_triggered(); break;
        case 121: _t->on_actionPython_2_triggered(); break;
        case 122: _t->on_actionJavaScript_triggered(); break;
        case 123: _t->on_actionTypeScript_triggered(); break;
        case 124: _t->on_actionHTML_triggered(); break;
        case 125: _t->on_actionGo_triggered(); break;
        case 126: _t->on_actionC_triggered(); break;
        case 127: _t->on_actionC_2_triggered(); break;
        case 128: _t->on_actionC_3_triggered(); break;
        case 129: _t->on_actionRust_triggered(); break;
        case 130: _t->on_actionWGSL_triggered(); break;
        case 131: _t->on_actionGLSL_triggered(); break;
        case 132: _t->on_actionPlaintext_triggered(); break;
        case 133: _t->on_actionLua_triggered(); break;
        case 134: _t->on_actionJava_triggered(); break;
        case 135: _t->updateTagLine(); break;
        case 136: _t->updateDefaultWordLists(); break;
        case 137: _t->updateSyntax(); break;
        case 138: _t->findTriggered(); break;
        case 139: _t->nextTriggered(); break;
        case 140: _t->previousTriggered(); break;
        case 141: _t->replaceTriggered(); break;
        case 142: _t->replaceAllTriggered(); break;
        case 143: _t->updateLineNumbers((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 144: _t->updateScrollBarValue((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 145: _t->updateScrollBarValue2((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 146: _t->changeTheme((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 147: _t->on_actionDark_Mode_triggered(); break;
        case 148: _t->on_actionLight_Mode_triggered(); break;
        case 149: { bool _r = _t->wantedTheme();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 150: _t->saveWantedTheme(); break;
        case 151: _t->openFind(); break;
        case 152: _t->findTextEditChanged(); break;
        case 153: _t->centerCursor(); break;
        case 154: _t->updateFonts(); break;
        case 155: _t->setupCompleter(); break;
        case 156: { QString _r = _t->getCurrentWord();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 157: _t->updateExtraWordsList(); break;
        case 158: _t->fillSuggestions(); break;
        case 159: _t->fillActionsBox(); break;
        case 160: _t->updateFontSelection(); break;
        case 161: _t->changeHighlightColors((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 162: _t->openHelpMenu((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 163: _t->setLangOffFilename((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 164: _t->addFileToRecentList((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 165: _t->updateRecentList((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 166: _t->openRecentFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 167: _t->handleTabs(); break;
        case 168: { QString _r = _t->markdownToHtml((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 38:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QFile* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 169)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 169;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 169)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 169;
    }
    return _id;
}
QT_WARNING_POP
