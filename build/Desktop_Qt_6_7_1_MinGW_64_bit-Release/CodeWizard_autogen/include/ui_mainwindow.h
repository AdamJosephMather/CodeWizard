/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "C:/Users/adamj/Documents/QtProjects/CodeWizard/mytextedit.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionNew;
    QAction *actionSave_As;
    QAction *actionRun_Module_F5;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionIncrement_Ctrl;
    QAction *actionDe_Increment_Ctrl;
    QAction *actionFix_It;
    QAction *actionComment_Alt_3;
    QAction *actionUn_Comment_Alt_4;
    QAction *actionComment_Ctrl_Alt;
    QAction *actionComment_Ctrl_Shift_Alt;
    QAction *actionSwitch_Theme;
    QAction *actionUn_Comment_Alt_5;
    QAction *actionDark_Mode;
    QAction *actionLight_Mode;
    QAction *actionIncrease_Text_Size;
    QAction *actionDecrease_Text_Size;
    QAction *actionReset_Text_Size;
    QAction *actionChange_to_IDLE_format;
    QAction *actionChoose_Font;
    QAction *actionAnonymousPro_ttf;
    QAction *actionCourier_New_ttf;
    QAction *actionDroidSansMono;
    QAction *actionErika_Type;
    QAction *actionMonaco;
    QAction *actionMonospace;
    QAction *actionAnonymousPro;
    QAction *actionCourier_New;
    QAction *actionCourier_Prime;
    QAction *actionSourceCodePro;
    QAction *actionUbuntoMono;
    QAction *actionUbuntuMono;
    QAction *actionPython;
    QAction *actionRunning_Files;
    QAction *actionFix_It_2;
    QAction *actionThe_Fix_It_Button;
    QAction *actionCodeWizard;
    QAction *actionPython_2;
    QAction *actionC;
    QAction *actionRust;
    QAction *actionJavaScript;
    QAction *actionHTML;
    QAction *actionPlaintext;
    QAction *actionWGSL;
    QAction *actionCourier_New_2;
    QAction *actionCourier_Prime_2;
    QAction *actionDroidSansMono_2;
    QAction *actionMonaco_2;
    QAction *actionMonospace_2;
    QAction *actionSourceCodePro_2;
    QAction *actionUbuntuMono_2;
    QAction *actionGo;
    QAction *actionLua;
    QAction *actionC_2;
    QAction *actionGLSL;
    QAction *actionJava;
    QAction *actionOp1;
    QAction *actionTypeScript;
    QAction *actionTab_Width;
    QAction *actionSettings;
    QAction *actionStart_Macro_Recording;
    QAction *actionEnd_Macro_Recording;
    QAction *actionReplay_Macro;
    QAction *actionSet_Text_Size;
    QAction *actionMacros;
    QAction *actionC_3;
    QAction *actionLSP;
    QAction *actionLSP_2;
    QAction *actionHover;
    QAction *actionShow_Warnings;
    QAction *actionShow_Errors;
    QAction *actionShow_Other;
    QAction *actionOnly_Use_CodeWizard_Built_In;
    QAction *actionNo_Autocomplete;
    QAction *actionAuto_Save;
    QAction *actionExtras;
    QAction *actionRandomly_Choose_Program_Type_On_Save;
    QAction *actionShortcuts;
    QAction *actionUse_File_Tree;
    QAction *actionOpen_Folder;
    QAction *actionUse_File_Tree_If_Fullscreen;
    QAction *actionSet_Syntax_Colors;
    QAction *actionUse_Speaker;
    QAction *actionSet_Groq_AI_API_Key;
    QAction *actionCompare_2_Files;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QTreeView *treeView;
    MyTextEdit *textEdit_4;
    MyTextEdit *textEdit;
    QHBoxLayout *findLayout;
    QVBoxLayout *verticalLayout_4;
    MyTextEdit *textEdit_2;
    MyTextEdit *textEdit_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    MyTextEdit *textEdit_5;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menuOp1;
    QMenu *menuOpen_Recent;
    QMenu *menuRun;
    QMenu *menuEdit;
    QMenu *menuFonts;
    QMenu *menuSilly;
    QMenu *menuFixit;
    QMenu *menuView;
    QMenu *menuHelp;
    QMenu *menuLanguage;
    QMenu *menuLSP_Settings;
    QMenu *menuWarnings;
    QMenu *menuAutocomplete;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(702, 786);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName("actionNew");
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName("actionSave_As");
        actionRun_Module_F5 = new QAction(MainWindow);
        actionRun_Module_F5->setObjectName("actionRun_Module_F5");
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName("actionUndo");
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName("actionRedo");
        actionIncrement_Ctrl = new QAction(MainWindow);
        actionIncrement_Ctrl->setObjectName("actionIncrement_Ctrl");
        actionDe_Increment_Ctrl = new QAction(MainWindow);
        actionDe_Increment_Ctrl->setObjectName("actionDe_Increment_Ctrl");
        actionFix_It = new QAction(MainWindow);
        actionFix_It->setObjectName("actionFix_It");
        actionComment_Alt_3 = new QAction(MainWindow);
        actionComment_Alt_3->setObjectName("actionComment_Alt_3");
        actionUn_Comment_Alt_4 = new QAction(MainWindow);
        actionUn_Comment_Alt_4->setObjectName("actionUn_Comment_Alt_4");
        actionComment_Ctrl_Alt = new QAction(MainWindow);
        actionComment_Ctrl_Alt->setObjectName("actionComment_Ctrl_Alt");
        actionComment_Ctrl_Shift_Alt = new QAction(MainWindow);
        actionComment_Ctrl_Shift_Alt->setObjectName("actionComment_Ctrl_Shift_Alt");
        actionSwitch_Theme = new QAction(MainWindow);
        actionSwitch_Theme->setObjectName("actionSwitch_Theme");
        actionUn_Comment_Alt_5 = new QAction(MainWindow);
        actionUn_Comment_Alt_5->setObjectName("actionUn_Comment_Alt_5");
        actionDark_Mode = new QAction(MainWindow);
        actionDark_Mode->setObjectName("actionDark_Mode");
        actionLight_Mode = new QAction(MainWindow);
        actionLight_Mode->setObjectName("actionLight_Mode");
        actionIncrease_Text_Size = new QAction(MainWindow);
        actionIncrease_Text_Size->setObjectName("actionIncrease_Text_Size");
        actionDecrease_Text_Size = new QAction(MainWindow);
        actionDecrease_Text_Size->setObjectName("actionDecrease_Text_Size");
        actionReset_Text_Size = new QAction(MainWindow);
        actionReset_Text_Size->setObjectName("actionReset_Text_Size");
        actionChange_to_IDLE_format = new QAction(MainWindow);
        actionChange_to_IDLE_format->setObjectName("actionChange_to_IDLE_format");
        actionChoose_Font = new QAction(MainWindow);
        actionChoose_Font->setObjectName("actionChoose_Font");
        actionAnonymousPro_ttf = new QAction(MainWindow);
        actionAnonymousPro_ttf->setObjectName("actionAnonymousPro_ttf");
        actionCourier_New_ttf = new QAction(MainWindow);
        actionCourier_New_ttf->setObjectName("actionCourier_New_ttf");
        actionDroidSansMono = new QAction(MainWindow);
        actionDroidSansMono->setObjectName("actionDroidSansMono");
        actionErika_Type = new QAction(MainWindow);
        actionErika_Type->setObjectName("actionErika_Type");
        actionMonaco = new QAction(MainWindow);
        actionMonaco->setObjectName("actionMonaco");
        actionMonospace = new QAction(MainWindow);
        actionMonospace->setObjectName("actionMonospace");
        actionAnonymousPro = new QAction(MainWindow);
        actionAnonymousPro->setObjectName("actionAnonymousPro");
        actionCourier_New = new QAction(MainWindow);
        actionCourier_New->setObjectName("actionCourier_New");
        actionCourier_Prime = new QAction(MainWindow);
        actionCourier_Prime->setObjectName("actionCourier_Prime");
        actionSourceCodePro = new QAction(MainWindow);
        actionSourceCodePro->setObjectName("actionSourceCodePro");
        actionUbuntoMono = new QAction(MainWindow);
        actionUbuntoMono->setObjectName("actionUbuntoMono");
        actionUbuntuMono = new QAction(MainWindow);
        actionUbuntuMono->setObjectName("actionUbuntuMono");
        actionPython = new QAction(MainWindow);
        actionPython->setObjectName("actionPython");
        actionRunning_Files = new QAction(MainWindow);
        actionRunning_Files->setObjectName("actionRunning_Files");
        actionFix_It_2 = new QAction(MainWindow);
        actionFix_It_2->setObjectName("actionFix_It_2");
        actionThe_Fix_It_Button = new QAction(MainWindow);
        actionThe_Fix_It_Button->setObjectName("actionThe_Fix_It_Button");
        actionCodeWizard = new QAction(MainWindow);
        actionCodeWizard->setObjectName("actionCodeWizard");
        actionPython_2 = new QAction(MainWindow);
        actionPython_2->setObjectName("actionPython_2");
        actionC = new QAction(MainWindow);
        actionC->setObjectName("actionC");
        actionRust = new QAction(MainWindow);
        actionRust->setObjectName("actionRust");
        actionJavaScript = new QAction(MainWindow);
        actionJavaScript->setObjectName("actionJavaScript");
        actionHTML = new QAction(MainWindow);
        actionHTML->setObjectName("actionHTML");
        actionPlaintext = new QAction(MainWindow);
        actionPlaintext->setObjectName("actionPlaintext");
        actionWGSL = new QAction(MainWindow);
        actionWGSL->setObjectName("actionWGSL");
        actionCourier_New_2 = new QAction(MainWindow);
        actionCourier_New_2->setObjectName("actionCourier_New_2");
        actionCourier_Prime_2 = new QAction(MainWindow);
        actionCourier_Prime_2->setObjectName("actionCourier_Prime_2");
        actionDroidSansMono_2 = new QAction(MainWindow);
        actionDroidSansMono_2->setObjectName("actionDroidSansMono_2");
        actionMonaco_2 = new QAction(MainWindow);
        actionMonaco_2->setObjectName("actionMonaco_2");
        actionMonospace_2 = new QAction(MainWindow);
        actionMonospace_2->setObjectName("actionMonospace_2");
        actionSourceCodePro_2 = new QAction(MainWindow);
        actionSourceCodePro_2->setObjectName("actionSourceCodePro_2");
        actionUbuntuMono_2 = new QAction(MainWindow);
        actionUbuntuMono_2->setObjectName("actionUbuntuMono_2");
        actionGo = new QAction(MainWindow);
        actionGo->setObjectName("actionGo");
        actionLua = new QAction(MainWindow);
        actionLua->setObjectName("actionLua");
        actionC_2 = new QAction(MainWindow);
        actionC_2->setObjectName("actionC_2");
        actionGLSL = new QAction(MainWindow);
        actionGLSL->setObjectName("actionGLSL");
        actionJava = new QAction(MainWindow);
        actionJava->setObjectName("actionJava");
        actionOp1 = new QAction(MainWindow);
        actionOp1->setObjectName("actionOp1");
        actionTypeScript = new QAction(MainWindow);
        actionTypeScript->setObjectName("actionTypeScript");
        actionTab_Width = new QAction(MainWindow);
        actionTab_Width->setObjectName("actionTab_Width");
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName("actionSettings");
        actionStart_Macro_Recording = new QAction(MainWindow);
        actionStart_Macro_Recording->setObjectName("actionStart_Macro_Recording");
        actionEnd_Macro_Recording = new QAction(MainWindow);
        actionEnd_Macro_Recording->setObjectName("actionEnd_Macro_Recording");
        actionReplay_Macro = new QAction(MainWindow);
        actionReplay_Macro->setObjectName("actionReplay_Macro");
        actionSet_Text_Size = new QAction(MainWindow);
        actionSet_Text_Size->setObjectName("actionSet_Text_Size");
        actionMacros = new QAction(MainWindow);
        actionMacros->setObjectName("actionMacros");
        actionC_3 = new QAction(MainWindow);
        actionC_3->setObjectName("actionC_3");
        actionLSP = new QAction(MainWindow);
        actionLSP->setObjectName("actionLSP");
        actionLSP_2 = new QAction(MainWindow);
        actionLSP_2->setObjectName("actionLSP_2");
        actionHover = new QAction(MainWindow);
        actionHover->setObjectName("actionHover");
        actionHover->setCheckable(true);
        actionHover->setChecked(true);
        actionShow_Warnings = new QAction(MainWindow);
        actionShow_Warnings->setObjectName("actionShow_Warnings");
        actionShow_Warnings->setCheckable(true);
        actionShow_Warnings->setChecked(true);
        actionShow_Errors = new QAction(MainWindow);
        actionShow_Errors->setObjectName("actionShow_Errors");
        actionShow_Errors->setCheckable(true);
        actionShow_Errors->setChecked(true);
        actionShow_Other = new QAction(MainWindow);
        actionShow_Other->setObjectName("actionShow_Other");
        actionShow_Other->setCheckable(true);
        actionShow_Other->setChecked(true);
        actionOnly_Use_CodeWizard_Built_In = new QAction(MainWindow);
        actionOnly_Use_CodeWizard_Built_In->setObjectName("actionOnly_Use_CodeWizard_Built_In");
        actionOnly_Use_CodeWizard_Built_In->setCheckable(true);
        actionNo_Autocomplete = new QAction(MainWindow);
        actionNo_Autocomplete->setObjectName("actionNo_Autocomplete");
        actionNo_Autocomplete->setCheckable(true);
        actionAuto_Save = new QAction(MainWindow);
        actionAuto_Save->setObjectName("actionAuto_Save");
        actionAuto_Save->setCheckable(true);
        actionExtras = new QAction(MainWindow);
        actionExtras->setObjectName("actionExtras");
        actionRandomly_Choose_Program_Type_On_Save = new QAction(MainWindow);
        actionRandomly_Choose_Program_Type_On_Save->setObjectName("actionRandomly_Choose_Program_Type_On_Save");
        actionRandomly_Choose_Program_Type_On_Save->setCheckable(true);
        actionShortcuts = new QAction(MainWindow);
        actionShortcuts->setObjectName("actionShortcuts");
        actionUse_File_Tree = new QAction(MainWindow);
        actionUse_File_Tree->setObjectName("actionUse_File_Tree");
        actionUse_File_Tree->setCheckable(true);
        actionOpen_Folder = new QAction(MainWindow);
        actionOpen_Folder->setObjectName("actionOpen_Folder");
        actionUse_File_Tree_If_Fullscreen = new QAction(MainWindow);
        actionUse_File_Tree_If_Fullscreen->setObjectName("actionUse_File_Tree_If_Fullscreen");
        actionUse_File_Tree_If_Fullscreen->setCheckable(true);
        actionSet_Syntax_Colors = new QAction(MainWindow);
        actionSet_Syntax_Colors->setObjectName("actionSet_Syntax_Colors");
        actionUse_Speaker = new QAction(MainWindow);
        actionUse_Speaker->setObjectName("actionUse_Speaker");
        actionUse_Speaker->setCheckable(true);
        actionSet_Groq_AI_API_Key = new QAction(MainWindow);
        actionSet_Groq_AI_API_Key->setObjectName("actionSet_Groq_AI_API_Key");
        actionCompare_2_Files = new QAction(MainWindow);
        actionCompare_2_Files->setObjectName("actionCompare_2_Files");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        treeView = new QTreeView(centralwidget);
        treeView->setObjectName("treeView");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(treeView->sizePolicy().hasHeightForWidth());
        treeView->setSizePolicy(sizePolicy1);
        treeView->setMinimumSize(QSize(300, 0));
        treeView->setMaximumSize(QSize(300, 16777215));
        treeView->setDragEnabled(false);

        horizontalLayout_3->addWidget(treeView);

        textEdit_4 = new MyTextEdit(centralwidget);
        textEdit_4->setObjectName("textEdit_4");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(textEdit_4->sizePolicy().hasHeightForWidth());
        textEdit_4->setSizePolicy(sizePolicy2);
        textEdit_4->setMinimumSize(QSize(50, 0));
        textEdit_4->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(textEdit_4);

        textEdit = new MyTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        QFont font;
        font.setFamilies({QString::fromUtf8("Courier New")});
        font.setItalic(false);
        textEdit->setFont(font);

        horizontalLayout_3->addWidget(textEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        findLayout = new QHBoxLayout();
        findLayout->setSpacing(5);
        findLayout->setObjectName("findLayout");
        findLayout->setContentsMargins(5, 0, 5, -1);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(1);
        verticalLayout_4->setObjectName("verticalLayout_4");
        textEdit_2 = new MyTextEdit(centralwidget);
        textEdit_2->setObjectName("textEdit_2");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(textEdit_2->sizePolicy().hasHeightForWidth());
        textEdit_2->setSizePolicy(sizePolicy3);
        textEdit_2->setMinimumSize(QSize(0, 28));
        textEdit_2->setMaximumSize(QSize(16777215, 28));

        verticalLayout_4->addWidget(textEdit_2);

        textEdit_3 = new MyTextEdit(centralwidget);
        textEdit_3->setObjectName("textEdit_3");
        sizePolicy3.setHeightForWidth(textEdit_3->sizePolicy().hasHeightForWidth());
        textEdit_3->setSizePolicy(sizePolicy3);
        textEdit_3->setMinimumSize(QSize(0, 28));
        textEdit_3->setMaximumSize(QSize(16777215, 28));

        verticalLayout_4->addWidget(textEdit_3);


        findLayout->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(1);
        verticalLayout_3->setObjectName("verticalLayout_3");
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");

        verticalLayout_3->addWidget(pushButton_4);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout_3->addWidget(pushButton_2);


        findLayout->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");

        verticalLayout_2->addWidget(pushButton_3);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");

        verticalLayout_2->addWidget(pushButton);


        findLayout->addLayout(verticalLayout_2);

        textEdit_5 = new MyTextEdit(centralwidget);
        textEdit_5->setObjectName("textEdit_5");
        textEdit_5->setMaximumSize(QSize(200, 28));

        findLayout->addWidget(textEdit_5);


        verticalLayout->addLayout(findLayout);


        horizontalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 702, 17));
        sizePolicy2.setHeightForWidth(menuBar->sizePolicy().hasHeightForWidth());
        menuBar->setSizePolicy(sizePolicy2);
        menuOp1 = new QMenu(menuBar);
        menuOp1->setObjectName("menuOp1");
        menuOpen_Recent = new QMenu(menuOp1);
        menuOpen_Recent->setObjectName("menuOpen_Recent");
        menuRun = new QMenu(menuBar);
        menuRun->setObjectName("menuRun");
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName("menuEdit");
        menuFonts = new QMenu(menuEdit);
        menuFonts->setObjectName("menuFonts");
        menuSilly = new QMenu(menuEdit);
        menuSilly->setObjectName("menuSilly");
        menuFixit = new QMenu(menuBar);
        menuFixit->setObjectName("menuFixit");
        menuView = new QMenu(menuBar);
        menuView->setObjectName("menuView");
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName("menuHelp");
        menuLanguage = new QMenu(menuBar);
        menuLanguage->setObjectName("menuLanguage");
        menuLSP_Settings = new QMenu(menuLanguage);
        menuLSP_Settings->setObjectName("menuLSP_Settings");
        menuWarnings = new QMenu(menuLSP_Settings);
        menuWarnings->setObjectName("menuWarnings");
        menuAutocomplete = new QMenu(menuLSP_Settings);
        menuAutocomplete->setObjectName("menuAutocomplete");
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuOp1->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuRun->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuFixit->menuAction());
        menuBar->addAction(menuLanguage->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuOp1->addAction(actionNew);
        menuOp1->addAction(actionOpen);
        menuOp1->addAction(actionOpen_Folder);
        menuOp1->addAction(menuOpen_Recent->menuAction());
        menuOp1->addAction(actionSave);
        menuOp1->addAction(actionSave_As);
        menuOp1->addAction(actionCompare_2_Files);
        menuOp1->addAction(actionExit);
        menuOpen_Recent->addAction(actionOp1);
        menuRun->addAction(actionRun_Module_F5);
        menuEdit->addSeparator();
        menuEdit->addAction(actionIncrement_Ctrl);
        menuEdit->addAction(actionDe_Increment_Ctrl);
        menuEdit->addAction(actionComment_Ctrl_Alt);
        menuEdit->addAction(actionUn_Comment_Alt_5);
        menuEdit->addSeparator();
        menuEdit->addAction(actionStart_Macro_Recording);
        menuEdit->addAction(actionEnd_Macro_Recording);
        menuEdit->addAction(actionReplay_Macro);
        menuEdit->addSeparator();
        menuEdit->addAction(menuFonts->menuAction());
        menuEdit->addAction(actionTab_Width);
        menuEdit->addAction(actionDark_Mode);
        menuEdit->addAction(actionLight_Mode);
        menuEdit->addSeparator();
        menuEdit->addAction(actionAuto_Save);
        menuEdit->addAction(menuSilly->menuAction());
        menuFonts->addAction(actionCourier_New_2);
        menuFonts->addAction(actionCourier_Prime_2);
        menuFonts->addAction(actionDroidSansMono_2);
        menuFonts->addAction(actionMonaco_2);
        menuFonts->addAction(actionMonospace_2);
        menuFonts->addAction(actionSourceCodePro_2);
        menuFonts->addAction(actionUbuntuMono_2);
        menuSilly->addAction(actionRandomly_Choose_Program_Type_On_Save);
        menuSilly->addAction(actionUse_Speaker);
        menuFixit->addAction(actionFix_It);
        menuFixit->addAction(actionChange_to_IDLE_format);
        menuFixit->addAction(actionSet_Groq_AI_API_Key);
        menuView->addAction(actionIncrease_Text_Size);
        menuView->addAction(actionDecrease_Text_Size);
        menuView->addAction(actionSet_Text_Size);
        menuView->addAction(actionReset_Text_Size);
        menuView->addSeparator();
        menuView->addAction(actionUse_File_Tree);
        menuView->addAction(actionUse_File_Tree_If_Fullscreen);
        menuView->addSeparator();
        menuView->addAction(actionSet_Syntax_Colors);
        menuHelp->addAction(actionCodeWizard);
        menuHelp->addAction(actionRunning_Files);
        menuHelp->addAction(actionThe_Fix_It_Button);
        menuHelp->addAction(actionSettings);
        menuHelp->addAction(actionMacros);
        menuHelp->addAction(actionLSP_2);
        menuHelp->addAction(actionExtras);
        menuLanguage->addAction(actionPython_2);
        menuLanguage->addAction(actionC);
        menuLanguage->addAction(actionC_2);
        menuLanguage->addAction(actionC_3);
        menuLanguage->addAction(actionJava);
        menuLanguage->addAction(actionRust);
        menuLanguage->addAction(actionWGSL);
        menuLanguage->addAction(actionGLSL);
        menuLanguage->addAction(actionJavaScript);
        menuLanguage->addAction(actionTypeScript);
        menuLanguage->addAction(actionHTML);
        menuLanguage->addAction(actionLua);
        menuLanguage->addAction(actionGo);
        menuLanguage->addAction(actionPlaintext);
        menuLanguage->addSeparator();
        menuLanguage->addAction(actionLSP);
        menuLanguage->addAction(menuLSP_Settings->menuAction());
        menuLSP_Settings->addAction(menuWarnings->menuAction());
        menuLSP_Settings->addAction(menuAutocomplete->menuAction());
        menuLSP_Settings->addAction(actionHover);
        menuWarnings->addAction(actionShow_Warnings);
        menuWarnings->addAction(actionShow_Errors);
        menuWarnings->addAction(actionShow_Other);
        menuAutocomplete->addAction(actionOnly_Use_CodeWizard_Built_In);
        menuAutocomplete->addAction(actionNo_Autocomplete);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        actionSave_As->setText(QCoreApplication::translate("MainWindow", "Save As", nullptr));
        actionRun_Module_F5->setText(QCoreApplication::translate("MainWindow", "Run Module (F5)", nullptr));
        actionUndo->setText(QCoreApplication::translate("MainWindow", "Undo (Ctrl + Z)", nullptr));
        actionRedo->setText(QCoreApplication::translate("MainWindow", "Redo (Ctrl + Shift + Z)", nullptr));
        actionIncrement_Ctrl->setText(QCoreApplication::translate("MainWindow", "Indent (Ctrl + ])", nullptr));
        actionDe_Increment_Ctrl->setText(QCoreApplication::translate("MainWindow", "De-Indent (Ctrl + [)", nullptr));
        actionFix_It->setText(QCoreApplication::translate("MainWindow", "Fix It", nullptr));
        actionComment_Alt_3->setText(QCoreApplication::translate("MainWindow", "Comment (Alt + 3)", nullptr));
        actionUn_Comment_Alt_4->setText(QCoreApplication::translate("MainWindow", "Un-Comment (Alt + Shift + 3)", nullptr));
        actionComment_Ctrl_Alt->setText(QCoreApplication::translate("MainWindow", "Comment (Alt + 3)", nullptr));
        actionComment_Ctrl_Shift_Alt->setText(QCoreApplication::translate("MainWindow", "Un Comment (Alt + 4)", nullptr));
        actionSwitch_Theme->setText(QCoreApplication::translate("MainWindow", "Switch Theme", nullptr));
        actionUn_Comment_Alt_5->setText(QCoreApplication::translate("MainWindow", "Un Comment (Alt + 4)", nullptr));
        actionDark_Mode->setText(QCoreApplication::translate("MainWindow", "Dark Mode", nullptr));
        actionLight_Mode->setText(QCoreApplication::translate("MainWindow", "Light Mode", nullptr));
        actionIncrease_Text_Size->setText(QCoreApplication::translate("MainWindow", "Increase Text Size (Ctrl+)", nullptr));
        actionDecrease_Text_Size->setText(QCoreApplication::translate("MainWindow", "Decrease Text Size (Ctrl-)", nullptr));
        actionReset_Text_Size->setText(QCoreApplication::translate("MainWindow", "Reset Text Size", nullptr));
        actionChange_to_IDLE_format->setText(QCoreApplication::translate("MainWindow", "Change to IDLE Format", nullptr));
        actionChoose_Font->setText(QCoreApplication::translate("MainWindow", "Choose Font", nullptr));
        actionAnonymousPro_ttf->setText(QCoreApplication::translate("MainWindow", "AnonymousPro", nullptr));
        actionCourier_New_ttf->setText(QCoreApplication::translate("MainWindow", "Courier_New", nullptr));
        actionDroidSansMono->setText(QCoreApplication::translate("MainWindow", "DroidSansMono", nullptr));
        actionErika_Type->setText(QCoreApplication::translate("MainWindow", "Erika_Type", nullptr));
        actionMonaco->setText(QCoreApplication::translate("MainWindow", "Monaco", nullptr));
        actionMonospace->setText(QCoreApplication::translate("MainWindow", "Monospace", nullptr));
        actionAnonymousPro->setText(QCoreApplication::translate("MainWindow", "AnonymousPro", nullptr));
        actionCourier_New->setText(QCoreApplication::translate("MainWindow", "Courier_New", nullptr));
        actionCourier_Prime->setText(QCoreApplication::translate("MainWindow", "Courier_Prime", nullptr));
        actionSourceCodePro->setText(QCoreApplication::translate("MainWindow", "SourceCodePro", nullptr));
        actionUbuntoMono->setText(QCoreApplication::translate("MainWindow", "UbuntoMono", nullptr));
        actionUbuntuMono->setText(QCoreApplication::translate("MainWindow", "UbuntuMono", nullptr));
        actionPython->setText(QCoreApplication::translate("MainWindow", "Python", nullptr));
        actionRunning_Files->setText(QCoreApplication::translate("MainWindow", "Running Files", nullptr));
        actionFix_It_2->setText(QCoreApplication::translate("MainWindow", "Fix It", nullptr));
        actionThe_Fix_It_Button->setText(QCoreApplication::translate("MainWindow", "The Fix It Button", nullptr));
        actionCodeWizard->setText(QCoreApplication::translate("MainWindow", "CodeWizard", nullptr));
        actionPython_2->setText(QCoreApplication::translate("MainWindow", "Python", nullptr));
        actionC->setText(QCoreApplication::translate("MainWindow", "C++", nullptr));
        actionRust->setText(QCoreApplication::translate("MainWindow", "Rust", nullptr));
        actionJavaScript->setText(QCoreApplication::translate("MainWindow", "JavaScript", nullptr));
        actionHTML->setText(QCoreApplication::translate("MainWindow", "HTML", nullptr));
        actionPlaintext->setText(QCoreApplication::translate("MainWindow", "Plaintext", nullptr));
        actionWGSL->setText(QCoreApplication::translate("MainWindow", "WGSL", nullptr));
        actionCourier_New_2->setText(QCoreApplication::translate("MainWindow", "Courier_New", nullptr));
        actionCourier_Prime_2->setText(QCoreApplication::translate("MainWindow", "Courier_Prime", nullptr));
        actionDroidSansMono_2->setText(QCoreApplication::translate("MainWindow", "DroidSansMono", nullptr));
        actionMonaco_2->setText(QCoreApplication::translate("MainWindow", "Monaco", nullptr));
        actionMonospace_2->setText(QCoreApplication::translate("MainWindow", "Monospace", nullptr));
        actionSourceCodePro_2->setText(QCoreApplication::translate("MainWindow", "SourceCodePro", nullptr));
        actionUbuntuMono_2->setText(QCoreApplication::translate("MainWindow", "UbuntuMono", nullptr));
        actionGo->setText(QCoreApplication::translate("MainWindow", "Go", nullptr));
        actionLua->setText(QCoreApplication::translate("MainWindow", "Lua", nullptr));
        actionC_2->setText(QCoreApplication::translate("MainWindow", "C#", nullptr));
        actionGLSL->setText(QCoreApplication::translate("MainWindow", "GLSL", nullptr));
        actionJava->setText(QCoreApplication::translate("MainWindow", "Java", nullptr));
        actionOp1->setText(QCoreApplication::translate("MainWindow", "Op1", nullptr));
        actionTypeScript->setText(QCoreApplication::translate("MainWindow", "TypeScript", nullptr));
        actionTab_Width->setText(QCoreApplication::translate("MainWindow", "Tab Width", nullptr));
        actionSettings->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        actionStart_Macro_Recording->setText(QCoreApplication::translate("MainWindow", "Start Macro Recording", nullptr));
        actionEnd_Macro_Recording->setText(QCoreApplication::translate("MainWindow", "End Macro Recording", nullptr));
        actionReplay_Macro->setText(QCoreApplication::translate("MainWindow", "Replay Macro (Ctrl + P)", nullptr));
        actionSet_Text_Size->setText(QCoreApplication::translate("MainWindow", "Set Text Size", nullptr));
        actionMacros->setText(QCoreApplication::translate("MainWindow", "Macros", nullptr));
        actionC_3->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        actionLSP->setText(QCoreApplication::translate("MainWindow", "Set LSP For Language", nullptr));
        actionLSP_2->setText(QCoreApplication::translate("MainWindow", "LSP", nullptr));
        actionHover->setText(QCoreApplication::translate("MainWindow", "Hover", nullptr));
        actionShow_Warnings->setText(QCoreApplication::translate("MainWindow", "Show Warnings", nullptr));
        actionShow_Errors->setText(QCoreApplication::translate("MainWindow", "Show Errors", nullptr));
        actionShow_Other->setText(QCoreApplication::translate("MainWindow", "Show Other", nullptr));
        actionOnly_Use_CodeWizard_Built_In->setText(QCoreApplication::translate("MainWindow", "Only Use CodeWizard Built In", nullptr));
        actionNo_Autocomplete->setText(QCoreApplication::translate("MainWindow", "No Autocomplete", nullptr));
        actionAuto_Save->setText(QCoreApplication::translate("MainWindow", "Auto Save", nullptr));
        actionExtras->setText(QCoreApplication::translate("MainWindow", "Extras", nullptr));
        actionRandomly_Choose_Program_Type_On_Save->setText(QCoreApplication::translate("MainWindow", "Randomly Choose Program Type On Save", nullptr));
        actionShortcuts->setText(QCoreApplication::translate("MainWindow", "Shortcuts", nullptr));
        actionUse_File_Tree->setText(QCoreApplication::translate("MainWindow", "Use File Tree", nullptr));
        actionOpen_Folder->setText(QCoreApplication::translate("MainWindow", "Open Folder", nullptr));
        actionUse_File_Tree_If_Fullscreen->setText(QCoreApplication::translate("MainWindow", "Use File Tree If Fullscreen", nullptr));
        actionSet_Syntax_Colors->setText(QCoreApplication::translate("MainWindow", "Set Syntax Colors", nullptr));
        actionUse_Speaker->setText(QCoreApplication::translate("MainWindow", "Use Speaker", nullptr));
        actionSet_Groq_AI_API_Key->setText(QCoreApplication::translate("MainWindow", "Set Groq AI API Key", nullptr));
        actionCompare_2_Files->setText(QCoreApplication::translate("MainWindow", "Compare 2 Files", nullptr));
        textEdit_4->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        textEdit_2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Find First", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Replace", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Replace All", nullptr));
        menuOp1->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuOpen_Recent->setTitle(QCoreApplication::translate("MainWindow", "Open Recent", nullptr));
        menuRun->setTitle(QCoreApplication::translate("MainWindow", "Run", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuFonts->setTitle(QCoreApplication::translate("MainWindow", "Fonts", nullptr));
        menuSilly->setTitle(QCoreApplication::translate("MainWindow", "Silly", nullptr));
        menuFixit->setTitle(QCoreApplication::translate("MainWindow", "Fix It", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        menuLanguage->setTitle(QCoreApplication::translate("MainWindow", "Language", nullptr));
        menuLSP_Settings->setTitle(QCoreApplication::translate("MainWindow", "LSP Settings", nullptr));
        menuWarnings->setTitle(QCoreApplication::translate("MainWindow", "Warnings", nullptr));
        menuAutocomplete->setTitle(QCoreApplication::translate("MainWindow", "Autocomplete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
