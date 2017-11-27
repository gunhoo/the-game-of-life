/********************************************************************************
** Form generated from reading UI file 'gameoflifeview.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOFLIFEVIEW_H
#define UI_GAMEOFLIFEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameOfLifeViewClass
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionQuit;
    QAction *actionSave_Result;
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *mainLayout;
    QVBoxLayout *sideLayout;
    QLabel *title;
    QHBoxLayout *buttonLayout;
    QPushButton *runButton;
    QPushButton *nextButton;
    QPushButton *stopButton;
    QPushButton *clearButton;
    QHBoxLayout *resizeLayout;
    QLabel *label;
    QSpinBox *rowSpinBox;
    QLabel *label_2;
    QSpinBox *colSpinBox;
    QPushButton *resizeButton;
    QVBoxLayout *emptyLayout;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_6;
    QVBoxLayout *gameLayout;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GameOfLifeViewClass)
    {
        if (GameOfLifeViewClass->objectName().isEmpty())
            GameOfLifeViewClass->setObjectName(QStringLiteral("GameOfLifeViewClass"));
        GameOfLifeViewClass->setEnabled(true);
        GameOfLifeViewClass->resize(1580, 780);
        GameOfLifeViewClass->setMinimumSize(QSize(1580, 780));
        GameOfLifeViewClass->setMaximumSize(QSize(1580, 780));
        GameOfLifeViewClass->setAutoFillBackground(false);
        GameOfLifeViewClass->setAnimated(false);
        GameOfLifeViewClass->setDockNestingEnabled(false);
        actionNew = new QAction(GameOfLifeViewClass);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionOpen = new QAction(GameOfLifeViewClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(GameOfLifeViewClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_As = new QAction(GameOfLifeViewClass);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionQuit = new QAction(GameOfLifeViewClass);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionSave_Result = new QAction(GameOfLifeViewClass);
        actionSave_Result->setObjectName(QStringLiteral("actionSave_Result"));
        centralWidget = new QWidget(GameOfLifeViewClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 1564, 720));
        mainLayout = new QHBoxLayout(horizontalLayoutWidget);
        mainLayout->setSpacing(6);
        mainLayout->setContentsMargins(11, 11, 11, 11);
        mainLayout->setObjectName(QStringLiteral("mainLayout"));
        mainLayout->setContentsMargins(0, 0, 0, 0);
        sideLayout = new QVBoxLayout();
        sideLayout->setSpacing(5);
        sideLayout->setObjectName(QStringLiteral("sideLayout"));
        title = new QLabel(horizontalLayoutWidget);
        title->setObjectName(QStringLiteral("title"));
        title->setMinimumSize(QSize(100, 50));
        title->setMaximumSize(QSize(600, 300));
        QFont font;
        font.setFamily(QStringLiteral("Aharoni"));
        font.setPointSize(36);
        font.setBold(true);
        font.setWeight(75);
        title->setFont(font);

        sideLayout->addWidget(title);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setSpacing(0);
        buttonLayout->setObjectName(QStringLiteral("buttonLayout"));
        runButton = new QPushButton(horizontalLayoutWidget);
        runButton->setObjectName(QStringLiteral("runButton"));
        runButton->setMinimumSize(QSize(100, 40));
        runButton->setMaximumSize(QSize(100, 40));

        buttonLayout->addWidget(runButton);

        nextButton = new QPushButton(horizontalLayoutWidget);
        nextButton->setObjectName(QStringLiteral("nextButton"));
        nextButton->setMinimumSize(QSize(100, 40));
        nextButton->setMaximumSize(QSize(100, 40));

        buttonLayout->addWidget(nextButton);

        stopButton = new QPushButton(horizontalLayoutWidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setMinimumSize(QSize(100, 40));
        stopButton->setMaximumSize(QSize(100, 40));

        buttonLayout->addWidget(stopButton);

        clearButton = new QPushButton(horizontalLayoutWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setMinimumSize(QSize(100, 40));
        clearButton->setMaximumSize(QSize(100, 40));

        buttonLayout->addWidget(clearButton);


        sideLayout->addLayout(buttonLayout);

        resizeLayout = new QHBoxLayout();
        resizeLayout->setSpacing(0);
        resizeLayout->setObjectName(QStringLiteral("resizeLayout"));
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(25, 30));
        label->setMaximumSize(QSize(30, 40));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);

        resizeLayout->addWidget(label);

        rowSpinBox = new QSpinBox(horizontalLayoutWidget);
        rowSpinBox->setObjectName(QStringLiteral("rowSpinBox"));
        rowSpinBox->setMinimumSize(QSize(100, 30));
        rowSpinBox->setMaximumSize(QSize(100, 40));
        rowSpinBox->setMinimum(1);
        rowSpinBox->setMaximum(500);
        rowSpinBox->setValue(50);

        resizeLayout->addWidget(rowSpinBox);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(25, 30));
        label_2->setMaximumSize(QSize(30, 40));
        label_2->setFont(font1);

        resizeLayout->addWidget(label_2);

        colSpinBox = new QSpinBox(horizontalLayoutWidget);
        colSpinBox->setObjectName(QStringLiteral("colSpinBox"));
        colSpinBox->setMinimumSize(QSize(100, 30));
        colSpinBox->setMaximumSize(QSize(100, 40));
        colSpinBox->setProperty("showGroupSeparator", QVariant(false));
        colSpinBox->setMinimum(1);
        colSpinBox->setMaximum(500);
        colSpinBox->setValue(40);

        resizeLayout->addWidget(colSpinBox);

        resizeButton = new QPushButton(horizontalLayoutWidget);
        resizeButton->setObjectName(QStringLiteral("resizeButton"));
        resizeButton->setMinimumSize(QSize(150, 40));
        resizeButton->setMaximumSize(QSize(150, 40));

        resizeLayout->addWidget(resizeButton);


        sideLayout->addLayout(resizeLayout);

        emptyLayout = new QVBoxLayout();
        emptyLayout->setSpacing(2);
        emptyLayout->setObjectName(QStringLiteral("emptyLayout"));
        label_5 = new QLabel(horizontalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(100, 30));
        label_5->setMaximumSize(QSize(100, 40));
        label_5->setFont(font1);

        emptyLayout->addWidget(label_5);

        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(100, 30));
        label_4->setMaximumSize(QSize(100, 40));
        label_4->setFont(font1);

        emptyLayout->addWidget(label_4);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(100, 30));
        label_3->setMaximumSize(QSize(100, 40));
        label_3->setFont(font1);

        emptyLayout->addWidget(label_3);

        label_6 = new QLabel(horizontalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(100, 30));
        label_6->setMaximumSize(QSize(100, 40));
        label_6->setFont(font1);

        emptyLayout->addWidget(label_6);


        sideLayout->addLayout(emptyLayout);


        mainLayout->addLayout(sideLayout);

        gameLayout = new QVBoxLayout();
        gameLayout->setSpacing(5);
        gameLayout->setObjectName(QStringLiteral("gameLayout"));

        mainLayout->addLayout(gameLayout);

        GameOfLifeViewClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GameOfLifeViewClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1580, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        GameOfLifeViewClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(GameOfLifeViewClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GameOfLifeViewClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addAction(actionSave_Result);
        menuFile->addAction(actionQuit);

        retranslateUi(GameOfLifeViewClass);

        QMetaObject::connectSlotsByName(GameOfLifeViewClass);
    } // setupUi

    void retranslateUi(QMainWindow *GameOfLifeViewClass)
    {
        GameOfLifeViewClass->setWindowTitle(QApplication::translate("GameOfLifeViewClass", "Game of Life", 0));
        actionNew->setText(QApplication::translate("GameOfLifeViewClass", "New", 0));
        actionOpen->setText(QApplication::translate("GameOfLifeViewClass", "Open", 0));
        actionSave->setText(QApplication::translate("GameOfLifeViewClass", "Save", 0));
        actionSave_As->setText(QApplication::translate("GameOfLifeViewClass", "Save As", 0));
        actionQuit->setText(QApplication::translate("GameOfLifeViewClass", "Quit", 0));
        actionSave_Result->setText(QApplication::translate("GameOfLifeViewClass", "Save Result", 0));
        title->setText(QApplication::translate("GameOfLifeViewClass", "The Game of Life", 0));
        runButton->setText(QApplication::translate("GameOfLifeViewClass", "run", 0));
        nextButton->setText(QApplication::translate("GameOfLifeViewClass", "next", 0));
        stopButton->setText(QApplication::translate("GameOfLifeViewClass", "stop", 0));
        clearButton->setText(QApplication::translate("GameOfLifeViewClass", "clear", 0));
        label->setText(QApplication::translate("GameOfLifeViewClass", "row", 0));
        label_2->setText(QApplication::translate("GameOfLifeViewClass", "col", 0));
        resizeButton->setText(QApplication::translate("GameOfLifeViewClass", "resize", 0));
        label_5->setText(QApplication::translate("GameOfLifeViewClass", "20154716 Lee", 0));
        label_4->setText(QApplication::translate("GameOfLifeViewClass", "20151535 Park", 0));
        label_3->setText(QApplication::translate("GameOfLifeViewClass", "20150249 Kim", 0));
        label_6->setText(QApplication::translate("GameOfLifeViewClass", "20165953 Ju", 0));
        menuFile->setTitle(QApplication::translate("GameOfLifeViewClass", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class GameOfLifeViewClass: public Ui_GameOfLifeViewClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOFLIFEVIEW_H
