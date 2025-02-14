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
    "findMatchingBracket",
    "",
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
    "convertTheVersionNumber",
    "vnum",
    "gotoDefinitionReceived",
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
     151,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  920,    2, 0x08,    1 /* Private */,
       4,    0,  923,    2, 0x08,    3 /* Private */,
       5,    0,  924,    2, 0x08,    4 /* Private */,
       6,    0,  925,    2, 0x08,    5 /* Private */,
       7,    0,  926,    2, 0x08,    6 /* Private */,
       8,    2,  927,    2, 0x08,    7 /* Private */,
      13,    0,  932,    2, 0x08,   10 /* Private */,
      14,    0,  933,    2, 0x08,   11 /* Private */,
      15,    0,  934,    2, 0x08,   12 /* Private */,
      16,    0,  935,    2, 0x08,   13 /* Private */,
      17,    0,  936,    2, 0x08,   14 /* Private */,
      18,    0,  937,    2, 0x08,   15 /* Private */,
      19,    0,  938,    2, 0x08,   16 /* Private */,
      20,    0,  939,    2, 0x08,   17 /* Private */,
      21,    0,  940,    2, 0x08,   18 /* Private */,
      22,    1,  941,    2, 0x08,   19 /* Private */,
      24,    0,  944,    2, 0x08,   21 /* Private */,
      25,    0,  945,    2, 0x08,   22 /* Private */,
      26,    0,  946,    2, 0x08,   23 /* Private */,
      27,    0,  947,    2, 0x08,   24 /* Private */,
      28,    1,  948,    2, 0x08,   25 /* Private */,
      30,    1,  951,    2, 0x08,   27 /* Private */,
      32,    1,  954,    2, 0x08,   29 /* Private */,
      35,    0,  957,    2, 0x08,   31 /* Private */,
      36,    1,  958,    2, 0x08,   32 /* Private */,
      38,    0,  961,    2, 0x08,   34 /* Private */,
      39,    1,  962,    2, 0x08,   35 /* Private */,
      41,    3,  965,    2, 0x08,   37 /* Private */,
      45,    0,  972,    2, 0x08,   41 /* Private */,
      46,    1,  973,    2, 0x08,   42 /* Private */,
      47,    2,  976,    2, 0x08,   44 /* Private */,
      50,    0,  981,    2, 0x08,   47 /* Private */,
      51,    0,  982,    2, 0x08,   48 /* Private */,
      52,    0,  983,    2, 0x08,   49 /* Private */,
      53,    0,  984,    2, 0x08,   50 /* Private */,
      54,    2,  985,    2, 0x08,   51 /* Private */,
      54,    1,  990,    2, 0x28,   54 /* Private | MethodCloned */,
      58,    2,  993,    2, 0x08,   56 /* Private */,
      58,    1,  998,    2, 0x28,   59 /* Private | MethodCloned */,
      61,    3, 1001,    2, 0x08,   61 /* Private */,
      65,    9, 1008,    2, 0x08,   65 /* Private */,
      75,    0, 1027,    2, 0x08,   75 /* Private */,
      76,    0, 1028,    2, 0x08,   76 /* Private */,
      77,    0, 1029,    2, 0x08,   77 /* Private */,
      78,    0, 1030,    2, 0x08,   78 /* Private */,
      79,    1, 1031,    2, 0x08,   79 /* Private */,
      81,    1, 1034,    2, 0x08,   81 /* Private */,
      83,    1, 1037,    2, 0x08,   83 /* Private */,
      85,    1, 1040,    2, 0x08,   85 /* Private */,
      87,    0, 1043,    2, 0x08,   87 /* Private */,
      88,    0, 1044,    2, 0x08,   88 /* Private */,
      89,    0, 1045,    2, 0x08,   89 /* Private */,
      90,    1, 1046,    2, 0x08,   90 /* Private */,
      93,    1, 1049,    2, 0x08,   92 /* Private */,
      95,    1, 1052,    2, 0x08,   94 /* Private */,
      97,    0, 1055,    2, 0x08,   96 /* Private */,
      98,    1, 1056,    2, 0x08,   97 /* Private */,
      99,    0, 1059,    2, 0x08,   99 /* Private */,
     100,    3, 1060,    2, 0x08,  100 /* Private */,
     104,    1, 1067,    2, 0x08,  104 /* Private */,
     105,    0, 1070,    2, 0x08,  106 /* Private */,
     106,    0, 1071,    2, 0x08,  107 /* Private */,
     107,    0, 1072,    2, 0x08,  108 /* Private */,
     108,    0, 1073,    2, 0x08,  109 /* Private */,
     109,    0, 1074,    2, 0x08,  110 /* Private */,
     110,    0, 1075,    2, 0x08,  111 /* Private */,
     111,    1, 1076,    2, 0x08,  112 /* Private */,
     113,    1, 1079,    2, 0x08,  114 /* Private */,
     114,    0, 1082,    2, 0x08,  116 /* Private */,
     115,    0, 1083,    2, 0x08,  117 /* Private */,
     116,    0, 1084,    2, 0x08,  118 /* Private */,
     117,    0, 1085,    2, 0x08,  119 /* Private */,
     118,    0, 1086,    2, 0x08,  120 /* Private */,
     119,    1, 1087,    2, 0x08,  121 /* Private */,
     119,    0, 1090,    2, 0x28,  123 /* Private | MethodCloned */,
     121,    0, 1091,    2, 0x08,  124 /* Private */,
     122,    0, 1092,    2, 0x08,  125 /* Private */,
     123,    0, 1093,    2, 0x08,  126 /* Private */,
     124,    0, 1094,    2, 0x08,  127 /* Private */,
     125,    0, 1095,    2, 0x08,  128 /* Private */,
     126,    0, 1096,    2, 0x08,  129 /* Private */,
     127,    0, 1097,    2, 0x08,  130 /* Private */,
     128,    0, 1098,    2, 0x08,  131 /* Private */,
     129,    0, 1099,    2, 0x08,  132 /* Private */,
     130,    0, 1100,    2, 0x08,  133 /* Private */,
     131,    0, 1101,    2, 0x08,  134 /* Private */,
     132,    0, 1102,    2, 0x08,  135 /* Private */,
     133,    0, 1103,    2, 0x08,  136 /* Private */,
     134,    0, 1104,    2, 0x08,  137 /* Private */,
     135,    0, 1105,    2, 0x08,  138 /* Private */,
     136,    0, 1106,    2, 0x08,  139 /* Private */,
     137,    0, 1107,    2, 0x08,  140 /* Private */,
     138,    0, 1108,    2, 0x08,  141 /* Private */,
     139,    0, 1109,    2, 0x08,  142 /* Private */,
     140,    0, 1110,    2, 0x08,  143 /* Private */,
     141,    0, 1111,    2, 0x08,  144 /* Private */,
     142,    0, 1112,    2, 0x08,  145 /* Private */,
     143,    0, 1113,    2, 0x08,  146 /* Private */,
     144,    0, 1114,    2, 0x08,  147 /* Private */,
     145,    0, 1115,    2, 0x08,  148 /* Private */,
     146,    0, 1116,    2, 0x08,  149 /* Private */,
     147,    0, 1117,    2, 0x08,  150 /* Private */,
     148,    0, 1118,    2, 0x08,  151 /* Private */,
     149,    0, 1119,    2, 0x08,  152 /* Private */,
     150,    0, 1120,    2, 0x08,  153 /* Private */,
     151,    0, 1121,    2, 0x08,  154 /* Private */,
     152,    0, 1122,    2, 0x08,  155 /* Private */,
     153,    0, 1123,    2, 0x08,  156 /* Private */,
     154,    0, 1124,    2, 0x08,  157 /* Private */,
     155,    0, 1125,    2, 0x08,  158 /* Private */,
     156,    0, 1126,    2, 0x08,  159 /* Private */,
     157,    0, 1127,    2, 0x08,  160 /* Private */,
     158,    0, 1128,    2, 0x08,  161 /* Private */,
     159,    0, 1129,    2, 0x08,  162 /* Private */,
     160,    0, 1130,    2, 0x08,  163 /* Private */,
     161,    0, 1131,    2, 0x08,  164 /* Private */,
     162,    0, 1132,    2, 0x08,  165 /* Private */,
     163,    0, 1133,    2, 0x08,  166 /* Private */,
     164,    0, 1134,    2, 0x08,  167 /* Private */,
     165,    0, 1135,    2, 0x08,  168 /* Private */,
     166,    0, 1136,    2, 0x08,  169 /* Private */,
     167,    0, 1137,    2, 0x08,  170 /* Private */,
     168,    0, 1138,    2, 0x08,  171 /* Private */,
     169,    0, 1139,    2, 0x08,  172 /* Private */,
     170,    0, 1140,    2, 0x08,  173 /* Private */,
     171,    1, 1141,    2, 0x08,  174 /* Private */,
     172,    1, 1144,    2, 0x08,  176 /* Private */,
     173,    1, 1147,    2, 0x08,  178 /* Private */,
     174,    1, 1150,    2, 0x08,  180 /* Private */,
     175,    0, 1153,    2, 0x08,  182 /* Private */,
     176,    0, 1154,    2, 0x08,  183 /* Private */,
     177,    0, 1155,    2, 0x08,  184 /* Private */,
     178,    0, 1156,    2, 0x08,  185 /* Private */,
     179,    0, 1157,    2, 0x08,  186 /* Private */,
     180,    0, 1158,    2, 0x08,  187 /* Private */,
     181,    0, 1159,    2, 0x08,  188 /* Private */,
     182,    0, 1160,    2, 0x08,  189 /* Private */,
     183,    0, 1161,    2, 0x08,  190 /* Private */,
     184,    0, 1162,    2, 0x08,  191 /* Private */,
     185,    0, 1163,    2, 0x08,  192 /* Private */,
     186,    0, 1164,    2, 0x08,  193 /* Private */,
     187,    0, 1165,    2, 0x08,  194 /* Private */,
     188,    0, 1166,    2, 0x08,  195 /* Private */,
     189,    1, 1167,    2, 0x08,  196 /* Private */,
     190,    1, 1170,    2, 0x08,  198 /* Private */,
     191,    2, 1173,    2, 0x08,  200 /* Private */,
     192,    1, 1178,    2, 0x08,  203 /* Private */,
     193,    1, 1181,    2, 0x08,  205 /* Private */,
     194,    1, 1184,    2, 0x08,  207 /* Private */,
     195,    0, 1187,    2, 0x08,  209 /* Private */,
     196,    1, 1188,    2, 0x08,  210 /* Private */,

 // slots: parameters
    QMetaType::Int, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 11,   10,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString, QMetaType::QString,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   29,
    QMetaType::Void, QMetaType::Bool,   31,
    QMetaType::Bool, 0x80000000 | 33,   34,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   37,
    QMetaType::Void,
    QMetaType::Int, QMetaType::QString,   40,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString,   42,   43,   44,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Int, QMetaType::QColor, QMetaType::QColor,   48,   49,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 55, QMetaType::Int,   56,   57,
    QMetaType::Void, 0x80000000 | 55,   56,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   59,   60,
    QMetaType::Void, QMetaType::QString,   59,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   62,   63,   64,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   66,   67,   68,   69,   70,   71,   72,   73,   74,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   80,
    0x80000000 | 82, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,   84,
    QMetaType::QString, QMetaType::QString,   86,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 91,   92,
    QMetaType::QString, QMetaType::QString,   94,
    QMetaType::Void, QMetaType::QStringList,   96,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint, QMetaType::QString, QMetaType::QString,  101,  102,  103,
    QMetaType::Void, QMetaType::QPoint,   80,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 112,    2,
    QMetaType::Void, 0x80000000 | 112,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,  120,
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
        // method 'convertTheVersionNumber'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'gotoDefinitionReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
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
        case 0: { int _r = _t->findMatchingBracket((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->handleBracketsOnEnter(); break;
        case 2: _t->handleTerminalStdout(); break;
        case 3: _t->useBuiltinTerminalTriggered(); break;
        case 4: _t->on_actionVim_Modes_triggered(); break;
        case 5: _t->executeNormalAct((*reinterpret_cast< std::add_pointer_t<QTextCursor::MoveOperation>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QKeyEvent*>>(_a[2]))); break;
        case 6: _t->useVimModesTriggered(); break;
        case 7: _t->on_actionSet_Font_By_Name_triggered(); break;
        case 8: _t->on_actionGit_Integration_triggered(); break;
        case 9: _t->on_actionDiscard_Local_Changes_triggered(); break;
        case 10: _t->on_actionRegular_triggered(); break;
        case 11: _t->on_actionPush_triggered(); break;
        case 12: _t->on_actionKeybindings_triggered(); break;
        case 13: _t->on_actionOpen_Find_Menu_triggered(); break;
        case 14: _t->highlightComparisons(); break;
        case 15: { QString _r = _t->changeToTabs((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 16: _t->on_actionCompare_2_Files_triggered(); break;
        case 17: _t->on_actionSet_Groq_AI_API_Key_triggered(); break;
        case 18: _t->saveSyntaxColorsToFile(); break;
        case 19: _t->loadSyntaxColorsFromFile(); break;
        case 20: _t->setFormatsFromMyList((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 21: _t->updateMargins((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 22: { bool _r = _t->checkForLargeFile((*reinterpret_cast< std::add_pointer_t<QFile*>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 23: _t->clearTSSyntaxHighlighting(); break;
        case 24: _t->changeFindSectionVisibility((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 25: _t->checkForFixitDialogue(); break;
        case 26: { int _r = _t->convertTheVersionNumber((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 27: _t->gotoDefinitionReceived((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 28: _t->rehighlightFullDoc(); break;
        case 29: _t->changeOnlyEditsTheme((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 30: { int _r = _t->colorDifference((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 31: _t->syntaxColorsOffImage(); break;
        case 32: _t->resetSyntaxColors(); break;
        case 33: _t->validateAndConvert(); break;
        case 34: _t->on_actionSet_Syntax_Colors_triggered(); break;
        case 35: _t->printTree((*reinterpret_cast< std::add_pointer_t<TSNode>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 36: _t->printTree((*reinterpret_cast< std::add_pointer_t<TSNode>>(_a[1]))); break;
        case 37: _t->setupSyntaxTreeOnOpen((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 38: _t->setupSyntaxTreeOnOpen((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 39: _t->onContentsChange((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 40: _t->applyEditToTree((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[9]))); break;
        case 41: _t->onOpenInExplorer(); break;
        case 42: _t->onCopyPath(); break;
        case 43: _t->onOpenOutside(); break;
        case 44: _t->mouseClicked(); break;
        case 45: _t->openFileTreeContextMenu((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 46: { std::tuple<QString,QString,QString,QStringList> _r = _t->getTabDetails((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< std::tuple<QString,QString,QString,QStringList>*>(_a[0]) = std::move(_r); }  break;
        case 47: _t->setupLSP((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 48: { QString _r = _t->plaintextToHtml((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 49: _t->showWeDontFuckWithTheLSP(); break;
        case 50: _t->showHoldYourHorses(); break;
        case 51: _t->fileTreeToggled(); break;
        case 52: _t->fileTreeOpened((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 53: { QString _r = _t->convertLeadingSpacesToTabs((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 54: _t->ShowSuggestionsWithSuperSet((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 55: _t->gotoDefinitionActionTriggered(); break;
        case 56: _t->highlightDiagnostics((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 57: _t->autoSave(); break;
        case 58: _t->moveHoverBox((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 59: _t->handleMouseMoved((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 60: _t->on_actionLSP_triggered(); break;
        case 61: _t->on_actionLSP_2_triggered(); break;
        case 62: { bool _r = _t->insertCompletion();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 63: { bool _r = _t->activateCodeAction();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 64: _t->pullUpSaveDialogue(); break;
        case 65: _t->onWindowStateChanged(); break;
        case 66: _t->onSuggestionItemClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 67: _t->onActionsItemClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 68: _t->on_actionOpen_Folder_triggered(); break;
        case 69: _t->on_actionStart_Macro_Recording_triggered(); break;
        case 70: _t->on_actionEnd_Macro_Recording_triggered(); break;
        case 71: _t->on_actionReplay_Macro_triggered(); break;
        case 72: _t->on_actionExit_triggered(); break;
        case 73: _t->on_actionOpen_triggered((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 74: _t->on_actionOpen_triggered(); break;
        case 75: _t->on_actionSave_triggered(); break;
        case 76: _t->on_actionSave_As_triggered(); break;
        case 77: _t->on_actionNew_triggered(); break;
        case 78: _t->on_actionRun_Module_F5_triggered(); break;
        case 79: _t->on_actionIncrement_Ctrl_triggered(); break;
        case 80: _t->on_actionDe_Increment_Ctrl_triggered(); break;
        case 81: _t->on_actionFix_It_triggered(); break;
        case 82: _t->on_actionComment_Ctrl_Alt_triggered(); break;
        case 83: _t->on_actionUn_Comment_Alt_5_triggered(); break;
        case 84: _t->on_actionIncrease_Text_Size_triggered(); break;
        case 85: _t->on_actionDecrease_Text_Size_triggered(); break;
        case 86: _t->on_actionSet_Text_Size_triggered(); break;
        case 87: _t->on_actionReset_Text_Size_triggered(); break;
        case 88: _t->on_actionChange_to_IDLE_format_triggered(); break;
        case 89: _t->on_actionTab_Width_triggered(); break;
        case 90: _t->on_actionSettings_triggered(); break;
        case 91: _t->on_actionExtras_triggered(); break;
        case 92: _t->on_actionMacros_triggered(); break;
        case 93: _t->on_actionCourier_New_2_triggered(); break;
        case 94: _t->on_actionDroidSansMono_2_triggered(); break;
        case 95: _t->on_actionMonaco_2_triggered(); break;
        case 96: _t->on_actionMonospace_2_triggered(); break;
        case 97: _t->on_actionCourier_Prime_2_triggered(); break;
        case 98: _t->on_actionSourceCodePro_2_triggered(); break;
        case 99: _t->on_actionUbuntuMono_2_triggered(); break;
        case 100: _t->on_actionRunning_Files_triggered(); break;
        case 101: _t->on_actionThe_Fix_It_Button_triggered(); break;
        case 102: _t->on_actionCodeWizard_triggered(); break;
        case 103: _t->on_actionPython_2_triggered(); break;
        case 104: _t->on_actionJavaScript_triggered(); break;
        case 105: _t->on_actionTypeScript_triggered(); break;
        case 106: _t->on_actionHTML_triggered(); break;
        case 107: _t->on_actionGo_triggered(); break;
        case 108: _t->on_actionC_triggered(); break;
        case 109: _t->on_actionC_2_triggered(); break;
        case 110: _t->on_actionC_3_triggered(); break;
        case 111: _t->on_actionRust_triggered(); break;
        case 112: _t->on_actionWGSL_triggered(); break;
        case 113: _t->on_actionGLSL_triggered(); break;
        case 114: _t->on_actionPlaintext_triggered(); break;
        case 115: _t->on_actionLua_triggered(); break;
        case 116: _t->on_actionJava_triggered(); break;
        case 117: _t->updateTagLine(); break;
        case 118: _t->updateDefaultWordLists(); break;
        case 119: _t->updateSyntax(); break;
        case 120: _t->findTriggered(); break;
        case 121: _t->nextTriggered(); break;
        case 122: _t->previousTriggered(); break;
        case 123: _t->replaceTriggered(); break;
        case 124: _t->replaceAllTriggered(); break;
        case 125: _t->updateLineNumbers((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 126: _t->updateScrollBarValue((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 127: _t->updateScrollBarValue2((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 128: _t->changeTheme((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 129: _t->on_actionDark_Mode_triggered(); break;
        case 130: _t->on_actionLight_Mode_triggered(); break;
        case 131: { bool _r = _t->wantedTheme();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 132: _t->saveWantedTheme(); break;
        case 133: _t->openFind(); break;
        case 134: _t->findTextEditChanged(); break;
        case 135: _t->centerCursor(); break;
        case 136: _t->updateFonts(); break;
        case 137: _t->setupCompleter(); break;
        case 138: { QString _r = _t->getCurrentWord();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 139: _t->updateExtraWordsList(); break;
        case 140: _t->fillSuggestions(); break;
        case 141: _t->fillActionsBox(); break;
        case 142: _t->updateFontSelection(); break;
        case 143: _t->changeHighlightColors((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 144: _t->openHelpMenu((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 145: _t->setLangOffFilename((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 146: _t->addFileToRecentList((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 147: _t->updateRecentList((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 148: _t->openRecentFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 149: _t->handleTabs(); break;
        case 150: { QString _r = _t->markdownToHtml((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 22:
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
        if (_id < 151)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 151;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 151)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 151;
    }
    return _id;
}
QT_WARNING_POP
