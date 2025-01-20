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
    "on_actionKeybindings_triggered",
    "",
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
     138,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  842,    2, 0x08,    1 /* Private */,
       3,    0,  843,    2, 0x08,    2 /* Private */,
       4,    1,  844,    2, 0x08,    3 /* Private */,
       6,    0,  847,    2, 0x08,    5 /* Private */,
       7,    0,  848,    2, 0x08,    6 /* Private */,
       8,    0,  849,    2, 0x08,    7 /* Private */,
       9,    0,  850,    2, 0x08,    8 /* Private */,
      10,    1,  851,    2, 0x08,    9 /* Private */,
      12,    1,  854,    2, 0x08,   11 /* Private */,
      14,    1,  857,    2, 0x08,   13 /* Private */,
      17,    0,  860,    2, 0x08,   15 /* Private */,
      18,    1,  861,    2, 0x08,   16 /* Private */,
      20,    0,  864,    2, 0x08,   18 /* Private */,
      21,    1,  865,    2, 0x08,   19 /* Private */,
      23,    3,  868,    2, 0x08,   21 /* Private */,
      27,    0,  875,    2, 0x08,   25 /* Private */,
      28,    1,  876,    2, 0x08,   26 /* Private */,
      29,    2,  879,    2, 0x08,   28 /* Private */,
      32,    0,  884,    2, 0x08,   31 /* Private */,
      33,    0,  885,    2, 0x08,   32 /* Private */,
      34,    0,  886,    2, 0x08,   33 /* Private */,
      35,    0,  887,    2, 0x08,   34 /* Private */,
      36,    2,  888,    2, 0x08,   35 /* Private */,
      36,    1,  893,    2, 0x28,   38 /* Private | MethodCloned */,
      40,    2,  896,    2, 0x08,   40 /* Private */,
      40,    1,  901,    2, 0x28,   43 /* Private | MethodCloned */,
      43,    3,  904,    2, 0x08,   45 /* Private */,
      47,    9,  911,    2, 0x08,   49 /* Private */,
      57,    0,  930,    2, 0x08,   59 /* Private */,
      58,    0,  931,    2, 0x08,   60 /* Private */,
      59,    0,  932,    2, 0x08,   61 /* Private */,
      60,    0,  933,    2, 0x08,   62 /* Private */,
      61,    1,  934,    2, 0x08,   63 /* Private */,
      63,    1,  937,    2, 0x08,   65 /* Private */,
      65,    1,  940,    2, 0x08,   67 /* Private */,
      67,    1,  943,    2, 0x08,   69 /* Private */,
      69,    0,  946,    2, 0x08,   71 /* Private */,
      70,    0,  947,    2, 0x08,   72 /* Private */,
      71,    0,  948,    2, 0x08,   73 /* Private */,
      72,    1,  949,    2, 0x08,   74 /* Private */,
      75,    1,  952,    2, 0x08,   76 /* Private */,
      77,    1,  955,    2, 0x08,   78 /* Private */,
      79,    0,  958,    2, 0x08,   80 /* Private */,
      80,    1,  959,    2, 0x08,   81 /* Private */,
      81,    0,  962,    2, 0x08,   83 /* Private */,
      82,    3,  963,    2, 0x08,   84 /* Private */,
      86,    1,  970,    2, 0x08,   88 /* Private */,
      87,    0,  973,    2, 0x08,   90 /* Private */,
      88,    0,  974,    2, 0x08,   91 /* Private */,
      89,    0,  975,    2, 0x08,   92 /* Private */,
      90,    0,  976,    2, 0x08,   93 /* Private */,
      91,    0,  977,    2, 0x08,   94 /* Private */,
      92,    0,  978,    2, 0x08,   95 /* Private */,
      93,    1,  979,    2, 0x08,   96 /* Private */,
      95,    1,  982,    2, 0x08,   98 /* Private */,
      96,    0,  985,    2, 0x08,  100 /* Private */,
      97,    0,  986,    2, 0x08,  101 /* Private */,
      98,    0,  987,    2, 0x08,  102 /* Private */,
      99,    0,  988,    2, 0x08,  103 /* Private */,
     100,    0,  989,    2, 0x08,  104 /* Private */,
     101,    1,  990,    2, 0x08,  105 /* Private */,
     101,    0,  993,    2, 0x28,  107 /* Private | MethodCloned */,
     103,    0,  994,    2, 0x08,  108 /* Private */,
     104,    0,  995,    2, 0x08,  109 /* Private */,
     105,    0,  996,    2, 0x08,  110 /* Private */,
     106,    0,  997,    2, 0x08,  111 /* Private */,
     107,    0,  998,    2, 0x08,  112 /* Private */,
     108,    0,  999,    2, 0x08,  113 /* Private */,
     109,    0, 1000,    2, 0x08,  114 /* Private */,
     110,    0, 1001,    2, 0x08,  115 /* Private */,
     111,    0, 1002,    2, 0x08,  116 /* Private */,
     112,    0, 1003,    2, 0x08,  117 /* Private */,
     113,    0, 1004,    2, 0x08,  118 /* Private */,
     114,    0, 1005,    2, 0x08,  119 /* Private */,
     115,    0, 1006,    2, 0x08,  120 /* Private */,
     116,    0, 1007,    2, 0x08,  121 /* Private */,
     117,    0, 1008,    2, 0x08,  122 /* Private */,
     118,    0, 1009,    2, 0x08,  123 /* Private */,
     119,    0, 1010,    2, 0x08,  124 /* Private */,
     120,    0, 1011,    2, 0x08,  125 /* Private */,
     121,    0, 1012,    2, 0x08,  126 /* Private */,
     122,    0, 1013,    2, 0x08,  127 /* Private */,
     123,    0, 1014,    2, 0x08,  128 /* Private */,
     124,    0, 1015,    2, 0x08,  129 /* Private */,
     125,    0, 1016,    2, 0x08,  130 /* Private */,
     126,    0, 1017,    2, 0x08,  131 /* Private */,
     127,    0, 1018,    2, 0x08,  132 /* Private */,
     128,    0, 1019,    2, 0x08,  133 /* Private */,
     129,    0, 1020,    2, 0x08,  134 /* Private */,
     130,    0, 1021,    2, 0x08,  135 /* Private */,
     131,    0, 1022,    2, 0x08,  136 /* Private */,
     132,    0, 1023,    2, 0x08,  137 /* Private */,
     133,    0, 1024,    2, 0x08,  138 /* Private */,
     134,    0, 1025,    2, 0x08,  139 /* Private */,
     135,    0, 1026,    2, 0x08,  140 /* Private */,
     136,    0, 1027,    2, 0x08,  141 /* Private */,
     137,    0, 1028,    2, 0x08,  142 /* Private */,
     138,    0, 1029,    2, 0x08,  143 /* Private */,
     139,    0, 1030,    2, 0x08,  144 /* Private */,
     140,    0, 1031,    2, 0x08,  145 /* Private */,
     141,    0, 1032,    2, 0x08,  146 /* Private */,
     142,    0, 1033,    2, 0x08,  147 /* Private */,
     143,    0, 1034,    2, 0x08,  148 /* Private */,
     144,    0, 1035,    2, 0x08,  149 /* Private */,
     145,    0, 1036,    2, 0x08,  150 /* Private */,
     146,    0, 1037,    2, 0x08,  151 /* Private */,
     147,    0, 1038,    2, 0x08,  152 /* Private */,
     148,    0, 1039,    2, 0x08,  153 /* Private */,
     149,    0, 1040,    2, 0x08,  154 /* Private */,
     150,    0, 1041,    2, 0x08,  155 /* Private */,
     151,    0, 1042,    2, 0x08,  156 /* Private */,
     152,    0, 1043,    2, 0x08,  157 /* Private */,
     153,    1, 1044,    2, 0x08,  158 /* Private */,
     154,    1, 1047,    2, 0x08,  160 /* Private */,
     155,    1, 1050,    2, 0x08,  162 /* Private */,
     156,    1, 1053,    2, 0x08,  164 /* Private */,
     157,    0, 1056,    2, 0x08,  166 /* Private */,
     158,    0, 1057,    2, 0x08,  167 /* Private */,
     159,    0, 1058,    2, 0x08,  168 /* Private */,
     160,    0, 1059,    2, 0x08,  169 /* Private */,
     161,    0, 1060,    2, 0x08,  170 /* Private */,
     162,    0, 1061,    2, 0x08,  171 /* Private */,
     163,    0, 1062,    2, 0x08,  172 /* Private */,
     164,    0, 1063,    2, 0x08,  173 /* Private */,
     165,    0, 1064,    2, 0x08,  174 /* Private */,
     166,    0, 1065,    2, 0x08,  175 /* Private */,
     167,    0, 1066,    2, 0x08,  176 /* Private */,
     168,    0, 1067,    2, 0x08,  177 /* Private */,
     169,    0, 1068,    2, 0x08,  178 /* Private */,
     170,    0, 1069,    2, 0x08,  179 /* Private */,
     171,    1, 1070,    2, 0x08,  180 /* Private */,
     172,    1, 1073,    2, 0x08,  182 /* Private */,
     173,    2, 1076,    2, 0x08,  184 /* Private */,
     174,    1, 1081,    2, 0x08,  187 /* Private */,
     175,    1, 1084,    2, 0x08,  189 /* Private */,
     176,    1, 1087,    2, 0x08,  191 /* Private */,
     177,    0, 1090,    2, 0x08,  193 /* Private */,
     178,    1, 1091,    2, 0x08,  194 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Bool, 0x80000000 | 15,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void,
    QMetaType::Int, QMetaType::QString,   22,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString,   24,   25,   26,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Int, QMetaType::QColor, QMetaType::QColor,   30,   31,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 37, QMetaType::Int,   38,   39,
    QMetaType::Void, 0x80000000 | 37,   38,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   41,   42,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   44,   45,   46,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   48,   49,   50,   51,   52,   53,   54,   55,   56,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   62,
    0x80000000 | 64, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,   66,
    QMetaType::QString, QMetaType::QString,   68,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 73,   74,
    QMetaType::QString, QMetaType::QString,   76,
    QMetaType::Void, QMetaType::QStringList,   78,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint, QMetaType::QString, QMetaType::QString,   83,   84,   85,
    QMetaType::Void, QMetaType::QPoint,   62,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 94,    2,
    QMetaType::Void, 0x80000000 | 94,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,  102,
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
        // method 'on_actionKeybindings_triggered'
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
        case 0: _t->on_actionKeybindings_triggered(); break;
        case 1: _t->highlightComparisons(); break;
        case 2: { QString _r = _t->changeToTabs((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->on_actionCompare_2_Files_triggered(); break;
        case 4: _t->on_actionSet_Groq_AI_API_Key_triggered(); break;
        case 5: _t->saveSyntaxColorsToFile(); break;
        case 6: _t->loadSyntaxColorsFromFile(); break;
        case 7: _t->setFormatsFromMyList((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->updateMargins((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 9: { bool _r = _t->checkForLargeFile((*reinterpret_cast< std::add_pointer_t<QFile*>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->clearTSSyntaxHighlighting(); break;
        case 11: _t->changeFindSectionVisibility((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 12: _t->checkForFixitDialogue(); break;
        case 13: { int _r = _t->convertTheVersionNumber((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 14: _t->gotoDefinitionReceived((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 15: _t->rehighlightFullDoc(); break;
        case 16: _t->changeOnlyEditsTheme((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 17: { int _r = _t->colorDifference((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 18: _t->syntaxColorsOffImage(); break;
        case 19: _t->resetSyntaxColors(); break;
        case 20: _t->validateAndConvert(); break;
        case 21: _t->on_actionSet_Syntax_Colors_triggered(); break;
        case 22: _t->printTree((*reinterpret_cast< std::add_pointer_t<TSNode>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 23: _t->printTree((*reinterpret_cast< std::add_pointer_t<TSNode>>(_a[1]))); break;
        case 24: _t->setupSyntaxTreeOnOpen((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 25: _t->setupSyntaxTreeOnOpen((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 26: _t->onContentsChange((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 27: _t->applyEditToTree((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[9]))); break;
        case 28: _t->onOpenInExplorer(); break;
        case 29: _t->onCopyPath(); break;
        case 30: _t->onOpenOutside(); break;
        case 31: _t->mouseClicked(); break;
        case 32: _t->openFileTreeContextMenu((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 33: { std::tuple<QString,QString,QString,QStringList> _r = _t->getTabDetails((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< std::tuple<QString,QString,QString,QStringList>*>(_a[0]) = std::move(_r); }  break;
        case 34: _t->setupLSP((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 35: { QString _r = _t->plaintextToHtml((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 36: _t->showWeDontFuckWithTheLSP(); break;
        case 37: _t->showHoldYourHorses(); break;
        case 38: _t->fileTreeToggled(); break;
        case 39: _t->fileTreeOpened((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 40: { QString _r = _t->convertLeadingSpacesToTabs((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 41: _t->ShowSuggestionsWithSuperSet((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 42: _t->gotoDefinitionActionTriggered(); break;
        case 43: _t->highlightDiagnostics((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 44: _t->autoSave(); break;
        case 45: _t->moveHoverBox((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 46: _t->handleMouseMoved((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 47: _t->on_actionLSP_triggered(); break;
        case 48: _t->on_actionLSP_2_triggered(); break;
        case 49: { bool _r = _t->insertCompletion();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 50: { bool _r = _t->activateCodeAction();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 51: _t->pullUpSaveDialogue(); break;
        case 52: _t->onWindowStateChanged(); break;
        case 53: _t->onSuggestionItemClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 54: _t->onActionsItemClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 55: _t->on_actionOpen_Folder_triggered(); break;
        case 56: _t->on_actionStart_Macro_Recording_triggered(); break;
        case 57: _t->on_actionEnd_Macro_Recording_triggered(); break;
        case 58: _t->on_actionReplay_Macro_triggered(); break;
        case 59: _t->on_actionExit_triggered(); break;
        case 60: _t->on_actionOpen_triggered((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 61: _t->on_actionOpen_triggered(); break;
        case 62: _t->on_actionSave_triggered(); break;
        case 63: _t->on_actionSave_As_triggered(); break;
        case 64: _t->on_actionNew_triggered(); break;
        case 65: _t->on_actionRun_Module_F5_triggered(); break;
        case 66: _t->on_actionIncrement_Ctrl_triggered(); break;
        case 67: _t->on_actionDe_Increment_Ctrl_triggered(); break;
        case 68: _t->on_actionFix_It_triggered(); break;
        case 69: _t->on_actionComment_Ctrl_Alt_triggered(); break;
        case 70: _t->on_actionUn_Comment_Alt_5_triggered(); break;
        case 71: _t->on_actionIncrease_Text_Size_triggered(); break;
        case 72: _t->on_actionDecrease_Text_Size_triggered(); break;
        case 73: _t->on_actionSet_Text_Size_triggered(); break;
        case 74: _t->on_actionReset_Text_Size_triggered(); break;
        case 75: _t->on_actionChange_to_IDLE_format_triggered(); break;
        case 76: _t->on_actionTab_Width_triggered(); break;
        case 77: _t->on_actionSettings_triggered(); break;
        case 78: _t->on_actionExtras_triggered(); break;
        case 79: _t->on_actionMacros_triggered(); break;
        case 80: _t->on_actionCourier_New_2_triggered(); break;
        case 81: _t->on_actionDroidSansMono_2_triggered(); break;
        case 82: _t->on_actionMonaco_2_triggered(); break;
        case 83: _t->on_actionMonospace_2_triggered(); break;
        case 84: _t->on_actionCourier_Prime_2_triggered(); break;
        case 85: _t->on_actionSourceCodePro_2_triggered(); break;
        case 86: _t->on_actionUbuntuMono_2_triggered(); break;
        case 87: _t->on_actionRunning_Files_triggered(); break;
        case 88: _t->on_actionThe_Fix_It_Button_triggered(); break;
        case 89: _t->on_actionCodeWizard_triggered(); break;
        case 90: _t->on_actionPython_2_triggered(); break;
        case 91: _t->on_actionJavaScript_triggered(); break;
        case 92: _t->on_actionTypeScript_triggered(); break;
        case 93: _t->on_actionHTML_triggered(); break;
        case 94: _t->on_actionGo_triggered(); break;
        case 95: _t->on_actionC_triggered(); break;
        case 96: _t->on_actionC_2_triggered(); break;
        case 97: _t->on_actionC_3_triggered(); break;
        case 98: _t->on_actionRust_triggered(); break;
        case 99: _t->on_actionWGSL_triggered(); break;
        case 100: _t->on_actionGLSL_triggered(); break;
        case 101: _t->on_actionPlaintext_triggered(); break;
        case 102: _t->on_actionLua_triggered(); break;
        case 103: _t->on_actionJava_triggered(); break;
        case 104: _t->updateTagLine(); break;
        case 105: _t->updateDefaultWordLists(); break;
        case 106: _t->updateSyntax(); break;
        case 107: _t->findTriggered(); break;
        case 108: _t->nextTriggered(); break;
        case 109: _t->previousTriggered(); break;
        case 110: _t->replaceTriggered(); break;
        case 111: _t->replaceAllTriggered(); break;
        case 112: _t->updateLineNumbers((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 113: _t->updateScrollBarValue((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 114: _t->updateScrollBarValue2((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 115: _t->changeTheme((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 116: _t->on_actionDark_Mode_triggered(); break;
        case 117: _t->on_actionLight_Mode_triggered(); break;
        case 118: { bool _r = _t->wantedTheme();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 119: _t->saveWantedTheme(); break;
        case 120: _t->openFind(); break;
        case 121: _t->findTextEditChanged(); break;
        case 122: _t->centerCursor(); break;
        case 123: _t->updateFonts(); break;
        case 124: _t->setupCompleter(); break;
        case 125: { QString _r = _t->getCurrentWord();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 126: _t->updateExtraWordsList(); break;
        case 127: _t->fillSuggestions(); break;
        case 128: _t->fillActionsBox(); break;
        case 129: _t->updateFontSelection(); break;
        case 130: _t->changeHighlightColors((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 131: _t->openHelpMenu((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 132: _t->setLangOffFilename((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 133: _t->addFileToRecentList((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 134: _t->updateRecentList((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 135: _t->openRecentFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 136: _t->handleTabs(); break;
        case 137: { QString _r = _t->markdownToHtml((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 9:
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
        if (_id < 138)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 138;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 138)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 138;
    }
    return _id;
}
QT_WARNING_POP
