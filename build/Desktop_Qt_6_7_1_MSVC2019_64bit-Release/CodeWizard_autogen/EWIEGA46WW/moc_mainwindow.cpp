/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../mainwindow.h"
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
    "on_actionGit_Integration_triggered",
    "",
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
     143,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  872,    2, 0x08,    1 /* Private */,
       3,    0,  873,    2, 0x08,    2 /* Private */,
       4,    0,  874,    2, 0x08,    3 /* Private */,
       5,    0,  875,    2, 0x08,    4 /* Private */,
       6,    0,  876,    2, 0x08,    5 /* Private */,
       7,    0,  877,    2, 0x08,    6 /* Private */,
       8,    0,  878,    2, 0x08,    7 /* Private */,
       9,    1,  879,    2, 0x08,    8 /* Private */,
      11,    0,  882,    2, 0x08,   10 /* Private */,
      12,    0,  883,    2, 0x08,   11 /* Private */,
      13,    0,  884,    2, 0x08,   12 /* Private */,
      14,    0,  885,    2, 0x08,   13 /* Private */,
      15,    1,  886,    2, 0x08,   14 /* Private */,
      17,    1,  889,    2, 0x08,   16 /* Private */,
      19,    1,  892,    2, 0x08,   18 /* Private */,
      22,    0,  895,    2, 0x08,   20 /* Private */,
      23,    1,  896,    2, 0x08,   21 /* Private */,
      25,    0,  899,    2, 0x08,   23 /* Private */,
      26,    1,  900,    2, 0x08,   24 /* Private */,
      28,    3,  903,    2, 0x08,   26 /* Private */,
      32,    0,  910,    2, 0x08,   30 /* Private */,
      33,    1,  911,    2, 0x08,   31 /* Private */,
      34,    2,  914,    2, 0x08,   33 /* Private */,
      37,    0,  919,    2, 0x08,   36 /* Private */,
      38,    0,  920,    2, 0x08,   37 /* Private */,
      39,    0,  921,    2, 0x08,   38 /* Private */,
      40,    0,  922,    2, 0x08,   39 /* Private */,
      41,    2,  923,    2, 0x08,   40 /* Private */,
      41,    1,  928,    2, 0x28,   43 /* Private | MethodCloned */,
      45,    2,  931,    2, 0x08,   45 /* Private */,
      45,    1,  936,    2, 0x28,   48 /* Private | MethodCloned */,
      48,    3,  939,    2, 0x08,   50 /* Private */,
      52,    9,  946,    2, 0x08,   54 /* Private */,
      62,    0,  965,    2, 0x08,   64 /* Private */,
      63,    0,  966,    2, 0x08,   65 /* Private */,
      64,    0,  967,    2, 0x08,   66 /* Private */,
      65,    0,  968,    2, 0x08,   67 /* Private */,
      66,    1,  969,    2, 0x08,   68 /* Private */,
      68,    1,  972,    2, 0x08,   70 /* Private */,
      70,    1,  975,    2, 0x08,   72 /* Private */,
      72,    1,  978,    2, 0x08,   74 /* Private */,
      74,    0,  981,    2, 0x08,   76 /* Private */,
      75,    0,  982,    2, 0x08,   77 /* Private */,
      76,    0,  983,    2, 0x08,   78 /* Private */,
      77,    1,  984,    2, 0x08,   79 /* Private */,
      80,    1,  987,    2, 0x08,   81 /* Private */,
      82,    1,  990,    2, 0x08,   83 /* Private */,
      84,    0,  993,    2, 0x08,   85 /* Private */,
      85,    1,  994,    2, 0x08,   86 /* Private */,
      86,    0,  997,    2, 0x08,   88 /* Private */,
      87,    3,  998,    2, 0x08,   89 /* Private */,
      91,    1, 1005,    2, 0x08,   93 /* Private */,
      92,    0, 1008,    2, 0x08,   95 /* Private */,
      93,    0, 1009,    2, 0x08,   96 /* Private */,
      94,    0, 1010,    2, 0x08,   97 /* Private */,
      95,    0, 1011,    2, 0x08,   98 /* Private */,
      96,    0, 1012,    2, 0x08,   99 /* Private */,
      97,    0, 1013,    2, 0x08,  100 /* Private */,
      98,    1, 1014,    2, 0x08,  101 /* Private */,
     100,    1, 1017,    2, 0x08,  103 /* Private */,
     101,    0, 1020,    2, 0x08,  105 /* Private */,
     102,    0, 1021,    2, 0x08,  106 /* Private */,
     103,    0, 1022,    2, 0x08,  107 /* Private */,
     104,    0, 1023,    2, 0x08,  108 /* Private */,
     105,    0, 1024,    2, 0x08,  109 /* Private */,
     106,    1, 1025,    2, 0x08,  110 /* Private */,
     106,    0, 1028,    2, 0x28,  112 /* Private | MethodCloned */,
     108,    0, 1029,    2, 0x08,  113 /* Private */,
     109,    0, 1030,    2, 0x08,  114 /* Private */,
     110,    0, 1031,    2, 0x08,  115 /* Private */,
     111,    0, 1032,    2, 0x08,  116 /* Private */,
     112,    0, 1033,    2, 0x08,  117 /* Private */,
     113,    0, 1034,    2, 0x08,  118 /* Private */,
     114,    0, 1035,    2, 0x08,  119 /* Private */,
     115,    0, 1036,    2, 0x08,  120 /* Private */,
     116,    0, 1037,    2, 0x08,  121 /* Private */,
     117,    0, 1038,    2, 0x08,  122 /* Private */,
     118,    0, 1039,    2, 0x08,  123 /* Private */,
     119,    0, 1040,    2, 0x08,  124 /* Private */,
     120,    0, 1041,    2, 0x08,  125 /* Private */,
     121,    0, 1042,    2, 0x08,  126 /* Private */,
     122,    0, 1043,    2, 0x08,  127 /* Private */,
     123,    0, 1044,    2, 0x08,  128 /* Private */,
     124,    0, 1045,    2, 0x08,  129 /* Private */,
     125,    0, 1046,    2, 0x08,  130 /* Private */,
     126,    0, 1047,    2, 0x08,  131 /* Private */,
     127,    0, 1048,    2, 0x08,  132 /* Private */,
     128,    0, 1049,    2, 0x08,  133 /* Private */,
     129,    0, 1050,    2, 0x08,  134 /* Private */,
     130,    0, 1051,    2, 0x08,  135 /* Private */,
     131,    0, 1052,    2, 0x08,  136 /* Private */,
     132,    0, 1053,    2, 0x08,  137 /* Private */,
     133,    0, 1054,    2, 0x08,  138 /* Private */,
     134,    0, 1055,    2, 0x08,  139 /* Private */,
     135,    0, 1056,    2, 0x08,  140 /* Private */,
     136,    0, 1057,    2, 0x08,  141 /* Private */,
     137,    0, 1058,    2, 0x08,  142 /* Private */,
     138,    0, 1059,    2, 0x08,  143 /* Private */,
     139,    0, 1060,    2, 0x08,  144 /* Private */,
     140,    0, 1061,    2, 0x08,  145 /* Private */,
     141,    0, 1062,    2, 0x08,  146 /* Private */,
     142,    0, 1063,    2, 0x08,  147 /* Private */,
     143,    0, 1064,    2, 0x08,  148 /* Private */,
     144,    0, 1065,    2, 0x08,  149 /* Private */,
     145,    0, 1066,    2, 0x08,  150 /* Private */,
     146,    0, 1067,    2, 0x08,  151 /* Private */,
     147,    0, 1068,    2, 0x08,  152 /* Private */,
     148,    0, 1069,    2, 0x08,  153 /* Private */,
     149,    0, 1070,    2, 0x08,  154 /* Private */,
     150,    0, 1071,    2, 0x08,  155 /* Private */,
     151,    0, 1072,    2, 0x08,  156 /* Private */,
     152,    0, 1073,    2, 0x08,  157 /* Private */,
     153,    0, 1074,    2, 0x08,  158 /* Private */,
     154,    0, 1075,    2, 0x08,  159 /* Private */,
     155,    0, 1076,    2, 0x08,  160 /* Private */,
     156,    0, 1077,    2, 0x08,  161 /* Private */,
     157,    0, 1078,    2, 0x08,  162 /* Private */,
     158,    1, 1079,    2, 0x08,  163 /* Private */,
     159,    1, 1082,    2, 0x08,  165 /* Private */,
     160,    1, 1085,    2, 0x08,  167 /* Private */,
     161,    1, 1088,    2, 0x08,  169 /* Private */,
     162,    0, 1091,    2, 0x08,  171 /* Private */,
     163,    0, 1092,    2, 0x08,  172 /* Private */,
     164,    0, 1093,    2, 0x08,  173 /* Private */,
     165,    0, 1094,    2, 0x08,  174 /* Private */,
     166,    0, 1095,    2, 0x08,  175 /* Private */,
     167,    0, 1096,    2, 0x08,  176 /* Private */,
     168,    0, 1097,    2, 0x08,  177 /* Private */,
     169,    0, 1098,    2, 0x08,  178 /* Private */,
     170,    0, 1099,    2, 0x08,  179 /* Private */,
     171,    0, 1100,    2, 0x08,  180 /* Private */,
     172,    0, 1101,    2, 0x08,  181 /* Private */,
     173,    0, 1102,    2, 0x08,  182 /* Private */,
     174,    0, 1103,    2, 0x08,  183 /* Private */,
     175,    0, 1104,    2, 0x08,  184 /* Private */,
     176,    1, 1105,    2, 0x08,  185 /* Private */,
     177,    1, 1108,    2, 0x08,  187 /* Private */,
     178,    2, 1111,    2, 0x08,  189 /* Private */,
     179,    1, 1116,    2, 0x08,  192 /* Private */,
     180,    1, 1119,    2, 0x08,  194 /* Private */,
     181,    1, 1122,    2, 0x08,  196 /* Private */,
     182,    0, 1125,    2, 0x08,  198 /* Private */,
     183,    1, 1126,    2, 0x08,  199 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Bool, 0x80000000 | 20,   21,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void,
    QMetaType::Int, QMetaType::QString,   27,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString,   29,   30,   31,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Int, QMetaType::QColor, QMetaType::QColor,   35,   36,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 42, QMetaType::Int,   43,   44,
    QMetaType::Void, 0x80000000 | 42,   43,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   46,   47,
    QMetaType::Void, QMetaType::QString,   46,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   49,   50,   51,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   53,   54,   55,   56,   57,   58,   59,   60,   61,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   67,
    0x80000000 | 69, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,   71,
    QMetaType::QString, QMetaType::QString,   73,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 78,   79,
    QMetaType::QString, QMetaType::QString,   81,
    QMetaType::Void, QMetaType::QStringList,   83,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint, QMetaType::QString, QMetaType::QString,   88,   89,   90,
    QMetaType::Void, QMetaType::QPoint,   67,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 99,    2,
    QMetaType::Void, 0x80000000 | 99,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,  107,
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
        case 0: _t->on_actionGit_Integration_triggered(); break;
        case 1: _t->on_actionDiscard_Local_Changes_triggered(); break;
        case 2: _t->on_actionRegular_triggered(); break;
        case 3: _t->on_actionPush_triggered(); break;
        case 4: _t->on_actionKeybindings_triggered(); break;
        case 5: _t->on_actionOpen_Find_Menu_triggered(); break;
        case 6: _t->highlightComparisons(); break;
        case 7: { QString _r = _t->changeToTabs((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->on_actionCompare_2_Files_triggered(); break;
        case 9: _t->on_actionSet_Groq_AI_API_Key_triggered(); break;
        case 10: _t->saveSyntaxColorsToFile(); break;
        case 11: _t->loadSyntaxColorsFromFile(); break;
        case 12: _t->setFormatsFromMyList((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 13: _t->updateMargins((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 14: { bool _r = _t->checkForLargeFile((*reinterpret_cast< std::add_pointer_t<QFile*>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 15: _t->clearTSSyntaxHighlighting(); break;
        case 16: _t->changeFindSectionVisibility((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 17: _t->checkForFixitDialogue(); break;
        case 18: { int _r = _t->convertTheVersionNumber((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 19: _t->gotoDefinitionReceived((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 20: _t->rehighlightFullDoc(); break;
        case 21: _t->changeOnlyEditsTheme((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 22: { int _r = _t->colorDifference((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 23: _t->syntaxColorsOffImage(); break;
        case 24: _t->resetSyntaxColors(); break;
        case 25: _t->validateAndConvert(); break;
        case 26: _t->on_actionSet_Syntax_Colors_triggered(); break;
        case 27: _t->printTree((*reinterpret_cast< std::add_pointer_t<TSNode>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 28: _t->printTree((*reinterpret_cast< std::add_pointer_t<TSNode>>(_a[1]))); break;
        case 29: _t->setupSyntaxTreeOnOpen((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 30: _t->setupSyntaxTreeOnOpen((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 31: _t->onContentsChange((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 32: _t->applyEditToTree((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[9]))); break;
        case 33: _t->onOpenInExplorer(); break;
        case 34: _t->onCopyPath(); break;
        case 35: _t->onOpenOutside(); break;
        case 36: _t->mouseClicked(); break;
        case 37: _t->openFileTreeContextMenu((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 38: { std::tuple<QString,QString,QString,QStringList> _r = _t->getTabDetails((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< std::tuple<QString,QString,QString,QStringList>*>(_a[0]) = std::move(_r); }  break;
        case 39: _t->setupLSP((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 40: { QString _r = _t->plaintextToHtml((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 41: _t->showWeDontFuckWithTheLSP(); break;
        case 42: _t->showHoldYourHorses(); break;
        case 43: _t->fileTreeToggled(); break;
        case 44: _t->fileTreeOpened((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 45: { QString _r = _t->convertLeadingSpacesToTabs((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 46: _t->ShowSuggestionsWithSuperSet((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 47: _t->gotoDefinitionActionTriggered(); break;
        case 48: _t->highlightDiagnostics((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 49: _t->autoSave(); break;
        case 50: _t->moveHoverBox((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 51: _t->handleMouseMoved((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 52: _t->on_actionLSP_triggered(); break;
        case 53: _t->on_actionLSP_2_triggered(); break;
        case 54: { bool _r = _t->insertCompletion();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 55: { bool _r = _t->activateCodeAction();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 56: _t->pullUpSaveDialogue(); break;
        case 57: _t->onWindowStateChanged(); break;
        case 58: _t->onSuggestionItemClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 59: _t->onActionsItemClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 60: _t->on_actionOpen_Folder_triggered(); break;
        case 61: _t->on_actionStart_Macro_Recording_triggered(); break;
        case 62: _t->on_actionEnd_Macro_Recording_triggered(); break;
        case 63: _t->on_actionReplay_Macro_triggered(); break;
        case 64: _t->on_actionExit_triggered(); break;
        case 65: _t->on_actionOpen_triggered((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 66: _t->on_actionOpen_triggered(); break;
        case 67: _t->on_actionSave_triggered(); break;
        case 68: _t->on_actionSave_As_triggered(); break;
        case 69: _t->on_actionNew_triggered(); break;
        case 70: _t->on_actionRun_Module_F5_triggered(); break;
        case 71: _t->on_actionIncrement_Ctrl_triggered(); break;
        case 72: _t->on_actionDe_Increment_Ctrl_triggered(); break;
        case 73: _t->on_actionFix_It_triggered(); break;
        case 74: _t->on_actionComment_Ctrl_Alt_triggered(); break;
        case 75: _t->on_actionUn_Comment_Alt_5_triggered(); break;
        case 76: _t->on_actionIncrease_Text_Size_triggered(); break;
        case 77: _t->on_actionDecrease_Text_Size_triggered(); break;
        case 78: _t->on_actionSet_Text_Size_triggered(); break;
        case 79: _t->on_actionReset_Text_Size_triggered(); break;
        case 80: _t->on_actionChange_to_IDLE_format_triggered(); break;
        case 81: _t->on_actionTab_Width_triggered(); break;
        case 82: _t->on_actionSettings_triggered(); break;
        case 83: _t->on_actionExtras_triggered(); break;
        case 84: _t->on_actionMacros_triggered(); break;
        case 85: _t->on_actionCourier_New_2_triggered(); break;
        case 86: _t->on_actionDroidSansMono_2_triggered(); break;
        case 87: _t->on_actionMonaco_2_triggered(); break;
        case 88: _t->on_actionMonospace_2_triggered(); break;
        case 89: _t->on_actionCourier_Prime_2_triggered(); break;
        case 90: _t->on_actionSourceCodePro_2_triggered(); break;
        case 91: _t->on_actionUbuntuMono_2_triggered(); break;
        case 92: _t->on_actionRunning_Files_triggered(); break;
        case 93: _t->on_actionThe_Fix_It_Button_triggered(); break;
        case 94: _t->on_actionCodeWizard_triggered(); break;
        case 95: _t->on_actionPython_2_triggered(); break;
        case 96: _t->on_actionJavaScript_triggered(); break;
        case 97: _t->on_actionTypeScript_triggered(); break;
        case 98: _t->on_actionHTML_triggered(); break;
        case 99: _t->on_actionGo_triggered(); break;
        case 100: _t->on_actionC_triggered(); break;
        case 101: _t->on_actionC_2_triggered(); break;
        case 102: _t->on_actionC_3_triggered(); break;
        case 103: _t->on_actionRust_triggered(); break;
        case 104: _t->on_actionWGSL_triggered(); break;
        case 105: _t->on_actionGLSL_triggered(); break;
        case 106: _t->on_actionPlaintext_triggered(); break;
        case 107: _t->on_actionLua_triggered(); break;
        case 108: _t->on_actionJava_triggered(); break;
        case 109: _t->updateTagLine(); break;
        case 110: _t->updateDefaultWordLists(); break;
        case 111: _t->updateSyntax(); break;
        case 112: _t->findTriggered(); break;
        case 113: _t->nextTriggered(); break;
        case 114: _t->previousTriggered(); break;
        case 115: _t->replaceTriggered(); break;
        case 116: _t->replaceAllTriggered(); break;
        case 117: _t->updateLineNumbers((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 118: _t->updateScrollBarValue((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 119: _t->updateScrollBarValue2((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 120: _t->changeTheme((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 121: _t->on_actionDark_Mode_triggered(); break;
        case 122: _t->on_actionLight_Mode_triggered(); break;
        case 123: { bool _r = _t->wantedTheme();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 124: _t->saveWantedTheme(); break;
        case 125: _t->openFind(); break;
        case 126: _t->findTextEditChanged(); break;
        case 127: _t->centerCursor(); break;
        case 128: _t->updateFonts(); break;
        case 129: _t->setupCompleter(); break;
        case 130: { QString _r = _t->getCurrentWord();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 131: _t->updateExtraWordsList(); break;
        case 132: _t->fillSuggestions(); break;
        case 133: _t->fillActionsBox(); break;
        case 134: _t->updateFontSelection(); break;
        case 135: _t->changeHighlightColors((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 136: _t->openHelpMenu((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 137: _t->setLangOffFilename((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 138: _t->addFileToRecentList((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 139: _t->updateRecentList((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 140: _t->openRecentFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 141: _t->handleTabs(); break;
        case 142: { QString _r = _t->markdownToHtml((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 14:
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
        if (_id < 143)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 143;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 143)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 143;
    }
    return _id;
}
QT_WARNING_POP
