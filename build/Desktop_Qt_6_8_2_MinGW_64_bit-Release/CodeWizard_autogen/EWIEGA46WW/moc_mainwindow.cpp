/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
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
#error "This file was generated using the moc from 6.8.2. It"
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
struct qt_meta_tag_ZN10MainWindowE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN10MainWindowE = QtMocHelpers::stringData(
    "MainWindow",
    "renameReference",
    "",
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
    "file",
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

Q_CONSTINIT static const uint qt_meta_data_ZN10MainWindowE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
     163,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  992,    2, 0x08,    1 /* Private */,
       3,    1,  995,    2, 0x08,    3 /* Private */,
       5,    2,  998,    2, 0x08,    5 /* Private */,
       8,    0, 1003,    2, 0x08,    8 /* Private */,
       9,    2, 1004,    2, 0x08,    9 /* Private */,
      14,    0, 1009,    2, 0x08,   12 /* Private */,
      15,    0, 1010,    2, 0x08,   13 /* Private */,
      16,    0, 1011,    2, 0x08,   14 /* Private */,
      17,    1, 1012,    2, 0x08,   15 /* Private */,
      19,    0, 1015,    2, 0x08,   17 /* Private */,
      20,    1, 1016,    2, 0x08,   18 /* Private */,
      22,    0, 1019,    2, 0x08,   20 /* Private */,
      23,    0, 1020,    2, 0x08,   21 /* Private */,
      24,    0, 1021,    2, 0x08,   22 /* Private */,
      25,    0, 1022,    2, 0x08,   23 /* Private */,
      26,    2, 1023,    2, 0x08,   24 /* Private */,
      31,    0, 1028,    2, 0x08,   27 /* Private */,
      32,    0, 1029,    2, 0x08,   28 /* Private */,
      33,    0, 1030,    2, 0x08,   29 /* Private */,
      34,    0, 1031,    2, 0x08,   30 /* Private */,
      35,    0, 1032,    2, 0x08,   31 /* Private */,
      36,    0, 1033,    2, 0x08,   32 /* Private */,
      37,    0, 1034,    2, 0x08,   33 /* Private */,
      38,    0, 1035,    2, 0x08,   34 /* Private */,
      39,    0, 1036,    2, 0x08,   35 /* Private */,
      40,    1, 1037,    2, 0x08,   36 /* Private */,
      42,    0, 1040,    2, 0x08,   38 /* Private */,
      43,    0, 1041,    2, 0x08,   39 /* Private */,
      44,    0, 1042,    2, 0x08,   40 /* Private */,
      45,    0, 1043,    2, 0x08,   41 /* Private */,
      46,    1, 1044,    2, 0x08,   42 /* Private */,
      48,    1, 1047,    2, 0x08,   44 /* Private */,
      50,    1, 1050,    2, 0x08,   46 /* Private */,
      53,    0, 1053,    2, 0x08,   48 /* Private */,
      54,    1, 1054,    2, 0x08,   49 /* Private */,
      56,    0, 1057,    2, 0x08,   51 /* Private */,
      57,    2, 1058,    2, 0x08,   52 /* Private */,
      60,    5, 1063,    2, 0x08,   55 /* Private */,
      66,    0, 1074,    2, 0x08,   61 /* Private */,
      67,    1, 1075,    2, 0x08,   62 /* Private */,
      68,    2, 1078,    2, 0x08,   64 /* Private */,
      71,    0, 1083,    2, 0x08,   67 /* Private */,
      72,    0, 1084,    2, 0x08,   68 /* Private */,
      73,    0, 1085,    2, 0x08,   69 /* Private */,
      74,    0, 1086,    2, 0x08,   70 /* Private */,
      75,    2, 1087,    2, 0x08,   71 /* Private */,
      75,    1, 1092,    2, 0x28,   74 /* Private | MethodCloned */,
      79,    2, 1095,    2, 0x08,   76 /* Private */,
      79,    1, 1100,    2, 0x28,   79 /* Private | MethodCloned */,
      82,    3, 1103,    2, 0x08,   81 /* Private */,
      86,    9, 1110,    2, 0x08,   85 /* Private */,
      96,    0, 1129,    2, 0x08,   95 /* Private */,
      97,    0, 1130,    2, 0x08,   96 /* Private */,
      98,    0, 1131,    2, 0x08,   97 /* Private */,
      99,    0, 1132,    2, 0x08,   98 /* Private */,
     100,    0, 1133,    2, 0x08,   99 /* Private */,
     101,    1, 1134,    2, 0x08,  100 /* Private */,
     103,    1, 1137,    2, 0x08,  102 /* Private */,
     105,    1, 1140,    2, 0x08,  104 /* Private */,
     107,    1, 1143,    2, 0x08,  106 /* Private */,
     109,    0, 1146,    2, 0x08,  108 /* Private */,
     110,    0, 1147,    2, 0x08,  109 /* Private */,
     111,    0, 1148,    2, 0x08,  110 /* Private */,
     112,    1, 1149,    2, 0x08,  111 /* Private */,
     115,    1, 1152,    2, 0x08,  113 /* Private */,
     117,    1, 1155,    2, 0x08,  115 /* Private */,
     119,    0, 1158,    2, 0x08,  117 /* Private */,
     120,    0, 1159,    2, 0x08,  118 /* Private */,
     121,    1, 1160,    2, 0x08,  119 /* Private */,
     122,    0, 1163,    2, 0x08,  121 /* Private */,
     123,    3, 1164,    2, 0x08,  122 /* Private */,
     127,    1, 1171,    2, 0x08,  126 /* Private */,
     128,    0, 1174,    2, 0x08,  128 /* Private */,
     129,    0, 1175,    2, 0x08,  129 /* Private */,
     130,    0, 1176,    2, 0x08,  130 /* Private */,
     131,    0, 1177,    2, 0x08,  131 /* Private */,
     132,    0, 1178,    2, 0x08,  132 /* Private */,
     133,    0, 1179,    2, 0x08,  133 /* Private */,
     134,    1, 1180,    2, 0x08,  134 /* Private */,
     136,    1, 1183,    2, 0x08,  136 /* Private */,
     137,    0, 1186,    2, 0x08,  138 /* Private */,
     138,    0, 1187,    2, 0x08,  139 /* Private */,
     139,    0, 1188,    2, 0x08,  140 /* Private */,
     140,    0, 1189,    2, 0x08,  141 /* Private */,
     141,    0, 1190,    2, 0x08,  142 /* Private */,
     142,    1, 1191,    2, 0x08,  143 /* Private */,
     142,    0, 1194,    2, 0x28,  145 /* Private | MethodCloned */,
     144,    0, 1195,    2, 0x08,  146 /* Private */,
     145,    0, 1196,    2, 0x08,  147 /* Private */,
     146,    0, 1197,    2, 0x08,  148 /* Private */,
     147,    0, 1198,    2, 0x08,  149 /* Private */,
     148,    0, 1199,    2, 0x08,  150 /* Private */,
     149,    0, 1200,    2, 0x08,  151 /* Private */,
     150,    0, 1201,    2, 0x08,  152 /* Private */,
     151,    0, 1202,    2, 0x08,  153 /* Private */,
     152,    0, 1203,    2, 0x08,  154 /* Private */,
     153,    0, 1204,    2, 0x08,  155 /* Private */,
     154,    0, 1205,    2, 0x08,  156 /* Private */,
     155,    0, 1206,    2, 0x08,  157 /* Private */,
     156,    0, 1207,    2, 0x08,  158 /* Private */,
     157,    0, 1208,    2, 0x08,  159 /* Private */,
     158,    0, 1209,    2, 0x08,  160 /* Private */,
     159,    0, 1210,    2, 0x08,  161 /* Private */,
     160,    0, 1211,    2, 0x08,  162 /* Private */,
     161,    0, 1212,    2, 0x08,  163 /* Private */,
     162,    0, 1213,    2, 0x08,  164 /* Private */,
     163,    0, 1214,    2, 0x08,  165 /* Private */,
     164,    0, 1215,    2, 0x08,  166 /* Private */,
     165,    0, 1216,    2, 0x08,  167 /* Private */,
     166,    0, 1217,    2, 0x08,  168 /* Private */,
     167,    0, 1218,    2, 0x08,  169 /* Private */,
     168,    0, 1219,    2, 0x08,  170 /* Private */,
     169,    0, 1220,    2, 0x08,  171 /* Private */,
     170,    0, 1221,    2, 0x08,  172 /* Private */,
     171,    0, 1222,    2, 0x08,  173 /* Private */,
     172,    0, 1223,    2, 0x08,  174 /* Private */,
     173,    0, 1224,    2, 0x08,  175 /* Private */,
     174,    0, 1225,    2, 0x08,  176 /* Private */,
     175,    0, 1226,    2, 0x08,  177 /* Private */,
     176,    0, 1227,    2, 0x08,  178 /* Private */,
     177,    0, 1228,    2, 0x08,  179 /* Private */,
     178,    0, 1229,    2, 0x08,  180 /* Private */,
     179,    0, 1230,    2, 0x08,  181 /* Private */,
     180,    0, 1231,    2, 0x08,  182 /* Private */,
     181,    0, 1232,    2, 0x08,  183 /* Private */,
     182,    0, 1233,    2, 0x08,  184 /* Private */,
     183,    0, 1234,    2, 0x08,  185 /* Private */,
     184,    0, 1235,    2, 0x08,  186 /* Private */,
     185,    0, 1236,    2, 0x08,  187 /* Private */,
     186,    0, 1237,    2, 0x08,  188 /* Private */,
     187,    0, 1238,    2, 0x08,  189 /* Private */,
     188,    0, 1239,    2, 0x08,  190 /* Private */,
     189,    0, 1240,    2, 0x08,  191 /* Private */,
     190,    0, 1241,    2, 0x08,  192 /* Private */,
     191,    0, 1242,    2, 0x08,  193 /* Private */,
     192,    0, 1243,    2, 0x08,  194 /* Private */,
     193,    0, 1244,    2, 0x08,  195 /* Private */,
     194,    1, 1245,    2, 0x08,  196 /* Private */,
     195,    1, 1248,    2, 0x08,  198 /* Private */,
     196,    1, 1251,    2, 0x08,  200 /* Private */,
     197,    1, 1254,    2, 0x08,  202 /* Private */,
     198,    0, 1257,    2, 0x08,  204 /* Private */,
     199,    0, 1258,    2, 0x08,  205 /* Private */,
     200,    0, 1259,    2, 0x08,  206 /* Private */,
     201,    0, 1260,    2, 0x08,  207 /* Private */,
     202,    0, 1261,    2, 0x08,  208 /* Private */,
     203,    0, 1262,    2, 0x08,  209 /* Private */,
     204,    0, 1263,    2, 0x08,  210 /* Private */,
     205,    0, 1264,    2, 0x08,  211 /* Private */,
     206,    0, 1265,    2, 0x08,  212 /* Private */,
     207,    0, 1266,    2, 0x08,  213 /* Private */,
     208,    0, 1267,    2, 0x08,  214 /* Private */,
     209,    0, 1268,    2, 0x08,  215 /* Private */,
     210,    0, 1269,    2, 0x08,  216 /* Private */,
     211,    0, 1270,    2, 0x08,  217 /* Private */,
     212,    1, 1271,    2, 0x08,  218 /* Private */,
     213,    1, 1274,    2, 0x08,  220 /* Private */,
     214,    2, 1277,    2, 0x08,  222 /* Private */,
     215,    1, 1282,    2, 0x08,  225 /* Private */,
     216,    1, 1285,    2, 0x08,  227 /* Private */,
     217,    1, 1288,    2, 0x08,  229 /* Private */,
     218,    0, 1291,    2, 0x08,  231 /* Private */,
     219,    1, 1292,    2, 0x08,  232 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QJsonObject,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 4, QMetaType::QString,    6,    7,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 12,   11,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void,
    QMetaType::Int, QMetaType::Int,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 27, 0x80000000 | 29,   28,   30,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString, QMetaType::QString,   41,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   47,
    QMetaType::Void, QMetaType::Bool,   49,
    QMetaType::Bool, 0x80000000 | 51,   52,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   55,
    QMetaType::Void,
    QMetaType::Int, QMetaType::QString, QMetaType::QString,   58,   59,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString,   61,   62,   63,   64,   65,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Int, QMetaType::QColor, QMetaType::QColor,   69,   70,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 76, QMetaType::Int,   77,   78,
    QMetaType::Void, 0x80000000 | 76,   77,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   80,   81,
    QMetaType::Void, QMetaType::QString,   80,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   83,   84,   85,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   87,   88,   89,   90,   91,   92,   93,   94,   95,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,  102,
    0x80000000 | 104, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,  106,
    QMetaType::QString, QMetaType::QString,  108,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 113,  114,
    QMetaType::QString, QMetaType::QString,  116,
    QMetaType::Void, QMetaType::QStringList,  118,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint, QMetaType::QString, QMetaType::QString,  124,  125,  126,
    QMetaType::Void, QMetaType::QPoint,  102,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 135,    2,
    QMetaType::Void, 0x80000000 | 135,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,  143,
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
    qt_meta_stringdata_ZN10MainWindowE.offsetsAndSizes,
    qt_meta_data_ZN10MainWindowE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN10MainWindowE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
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
    auto *_t = static_cast<MainWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->renameReference((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 1: _t->execChanges((*reinterpret_cast< std::add_pointer_t<QList<std::pair<double,QJsonObject>>>>(_a[1]))); break;
        case 2: _t->execChangesInOtherFile((*reinterpret_cast< std::add_pointer_t<QList<std::pair<double,QJsonObject>>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 3: _t->updateSplitsWidths(); break;
        case 4: _t->moveWidgetsToSplitter((*reinterpret_cast< std::add_pointer_t<QLayout*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[2]))); break;
        case 5: _t->storeResizeOfSplitters(); break;
        case 6: _t->updateTermimalViews(); break;
        case 7: _t->on_actionToggleComments_triggered(); break;
        case 8: _t->pullUpReloadDialogue((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->switchTerminalType(); break;
        case 10: { int _r = _t->findMatchingBracket((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->handleBracketsOnEnter(); break;
        case 12: _t->handleTerminalStdout(); break;
        case 13: _t->useBuiltinTerminalTriggered(); break;
        case 14: _t->on_actionVim_Modes_triggered(); break;
        case 15: _t->executeNormalAct((*reinterpret_cast< std::add_pointer_t<QTextCursor::MoveOperation>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QKeyEvent*>>(_a[2]))); break;
        case 16: _t->useVimModesTriggered(); break;
        case 17: _t->on_actionSet_Font_By_Name_triggered(); break;
        case 18: _t->on_actionGit_Integration_triggered(); break;
        case 19: _t->on_actionDiscard_Local_Changes_triggered(); break;
        case 20: _t->on_actionRegular_triggered(); break;
        case 21: _t->on_actionPush_triggered(); break;
        case 22: _t->on_actionKeybindings_triggered(); break;
        case 23: _t->on_actionOpen_Find_Menu_triggered(); break;
        case 24: _t->highlightComparisons(); break;
        case 25: { QString _r = _t->changeToTabs((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 26: _t->on_actionCompare_2_Files_triggered(); break;
        case 27: _t->on_actionSet_Groq_AI_API_Key_triggered(); break;
        case 28: _t->saveSyntaxColorsToFile(); break;
        case 29: _t->loadSyntaxColorsFromFile(); break;
        case 30: _t->setFormatsFromMyList((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 31: _t->updateMargins((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 32: { bool _r = _t->checkForLargeFile((*reinterpret_cast< std::add_pointer_t<QFile*>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 33: _t->clearTSSyntaxHighlighting(); break;
        case 34: _t->changeFindSectionVisibility((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 35: _t->checkForFixitDialogue(); break;
        case 36: { int _r = _t->compareVersionNumbers((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 37: _t->gotoDefinitionReceived((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 38: _t->rehighlightFullDoc(); break;
        case 39: _t->changeOnlyEditsTheme((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 40: { int _r = _t->colorDifference((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 41: _t->syntaxColorsOffImage(); break;
        case 42: _t->resetSyntaxColors(); break;
        case 43: _t->validateAndConvert(); break;
        case 44: _t->on_actionSet_Syntax_Colors_triggered(); break;
        case 45: _t->printTree((*reinterpret_cast< std::add_pointer_t<TSNode>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 46: _t->printTree((*reinterpret_cast< std::add_pointer_t<TSNode>>(_a[1]))); break;
        case 47: _t->setupSyntaxTreeOnOpen((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 48: _t->setupSyntaxTreeOnOpen((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 49: _t->onContentsChange((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 50: _t->applyEditToTree((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[9]))); break;
        case 51: _t->onOpenInExplorer(); break;
        case 52: _t->onCopyPath(); break;
        case 53: _t->onOpenOutside(); break;
        case 54: _t->mouseClicked(); break;
        case 55: _t->mouseReleased(); break;
        case 56: _t->openFileTreeContextMenu((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 57: { std::tuple<QString,QString,QString,QStringList> _r = _t->getTabDetails((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< std::tuple<QString,QString,QString,QStringList>*>(_a[0]) = std::move(_r); }  break;
        case 58: _t->setupLSP((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 59: { QString _r = _t->plaintextToHtml((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 60: _t->showWeDontFuckWithTheLSP(); break;
        case 61: _t->showHoldYourHorses(); break;
        case 62: _t->fileTreeToggled(); break;
        case 63: _t->fileTreeOpened((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 64: { QString _r = _t->convertLeadingSpacesToTabs((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 65: _t->ShowSuggestionsWithSuperSet((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 66: _t->gotoDefinitionActionTriggered(); break;
        case 67: _t->renameActionTriggered(); break;
        case 68: _t->highlightDiagnostics((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 69: _t->autoSave(); break;
        case 70: _t->moveHoverBox((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 71: _t->handleMouseMoved((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 72: _t->on_actionLSP_triggered(); break;
        case 73: _t->on_actionLSP_2_triggered(); break;
        case 74: { bool _r = _t->insertCompletion();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 75: { bool _r = _t->activateCodeAction();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 76: _t->pullUpSaveDialogue(); break;
        case 77: _t->onWindowStateChanged(); break;
        case 78: _t->onSuggestionItemClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 79: _t->onActionsItemClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 80: _t->on_actionOpen_Folder_triggered(); break;
        case 81: _t->on_actionStart_Macro_Recording_triggered(); break;
        case 82: _t->on_actionEnd_Macro_Recording_triggered(); break;
        case 83: _t->on_actionReplay_Macro_triggered(); break;
        case 84: _t->on_actionExit_triggered(); break;
        case 85: _t->on_actionOpen_triggered((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 86: _t->on_actionOpen_triggered(); break;
        case 87: _t->on_actionSave_triggered(); break;
        case 88: _t->on_actionSave_As_triggered(); break;
        case 89: _t->on_actionNew_triggered(); break;
        case 90: _t->on_actionRun_Module_F5_triggered(); break;
        case 91: _t->on_actionIncrement_Ctrl_triggered(); break;
        case 92: _t->on_actionDe_Increment_Ctrl_triggered(); break;
        case 93: _t->on_actionFix_It_triggered(); break;
        case 94: _t->on_actionComment_Ctrl_Alt_triggered(); break;
        case 95: _t->on_actionUn_Comment_Alt_5_triggered(); break;
        case 96: _t->on_actionIncrease_Text_Size_triggered(); break;
        case 97: _t->on_actionDecrease_Text_Size_triggered(); break;
        case 98: _t->on_actionSet_Text_Size_triggered(); break;
        case 99: _t->on_actionReset_Text_Size_triggered(); break;
        case 100: _t->on_actionChange_to_IDLE_format_triggered(); break;
        case 101: _t->on_actionTab_Width_triggered(); break;
        case 102: _t->on_actionSettings_triggered(); break;
        case 103: _t->on_actionExtras_triggered(); break;
        case 104: _t->on_actionMacros_triggered(); break;
        case 105: _t->on_actionCourier_New_2_triggered(); break;
        case 106: _t->on_actionDroidSansMono_2_triggered(); break;
        case 107: _t->on_actionMonaco_2_triggered(); break;
        case 108: _t->on_actionMonospace_2_triggered(); break;
        case 109: _t->on_actionCourier_Prime_2_triggered(); break;
        case 110: _t->on_actionSourceCodePro_2_triggered(); break;
        case 111: _t->on_actionUbuntuMono_2_triggered(); break;
        case 112: _t->on_actionRunning_Files_triggered(); break;
        case 113: _t->on_actionThe_Fix_It_Button_triggered(); break;
        case 114: _t->on_actionCodeWizard_triggered(); break;
        case 115: _t->on_actionPython_2_triggered(); break;
        case 116: _t->on_actionJavaScript_triggered(); break;
        case 117: _t->on_actionTypeScript_triggered(); break;
        case 118: _t->on_actionHTML_triggered(); break;
        case 119: _t->on_actionGo_triggered(); break;
        case 120: _t->on_actionC_triggered(); break;
        case 121: _t->on_actionC_2_triggered(); break;
        case 122: _t->on_actionC_3_triggered(); break;
        case 123: _t->on_actionRust_triggered(); break;
        case 124: _t->on_actionWGSL_triggered(); break;
        case 125: _t->on_actionGLSL_triggered(); break;
        case 126: _t->on_actionPlaintext_triggered(); break;
        case 127: _t->on_actionLua_triggered(); break;
        case 128: _t->on_actionJava_triggered(); break;
        case 129: _t->updateTagLine(); break;
        case 130: _t->updateDefaultWordLists(); break;
        case 131: _t->updateSyntax(); break;
        case 132: _t->findTriggered(); break;
        case 133: _t->nextTriggered(); break;
        case 134: _t->previousTriggered(); break;
        case 135: _t->replaceTriggered(); break;
        case 136: _t->replaceAllTriggered(); break;
        case 137: _t->updateLineNumbers((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 138: _t->updateScrollBarValue((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 139: _t->updateScrollBarValue2((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 140: _t->changeTheme((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 141: _t->on_actionDark_Mode_triggered(); break;
        case 142: _t->on_actionLight_Mode_triggered(); break;
        case 143: { bool _r = _t->wantedTheme();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 144: _t->saveWantedTheme(); break;
        case 145: _t->openFind(); break;
        case 146: _t->findTextEditChanged(); break;
        case 147: _t->centerCursor(); break;
        case 148: _t->updateFonts(); break;
        case 149: _t->setupCompleter(); break;
        case 150: { QString _r = _t->getCurrentWord();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 151: _t->updateExtraWordsList(); break;
        case 152: _t->fillSuggestions(); break;
        case 153: _t->fillActionsBox(); break;
        case 154: _t->updateFontSelection(); break;
        case 155: _t->changeHighlightColors((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 156: _t->openHelpMenu((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 157: _t->setLangOffFilename((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 158: _t->addFileToRecentList((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 159: _t->updateRecentList((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 160: _t->openRecentFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 161: _t->handleTabs(); break;
        case 162: { QString _r = _t->markdownToHtml((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 32:
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
    if (!strcmp(_clname, qt_meta_stringdata_ZN10MainWindowE.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 163)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 163;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 163)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 163;
    }
    return _id;
}
QT_WARNING_POP
