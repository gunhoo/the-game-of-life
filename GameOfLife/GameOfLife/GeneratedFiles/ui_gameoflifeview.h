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
#include <QtWidgets/QToolBar>
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
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *universeSizeX;
    QLabel *label_2;
    QSpinBox *universeSizeY;
    QPushButton *resizeButton;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *runButton;
    QPushButton *nextButton;
    QPushButton *stopButton;
    QPushButton *clearButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GameOfLifeViewClass)
    {
        if (GameOfLifeViewClass->objectName().isEmpty())
            GameOfLifeViewClass->setObjectName(QStringLiteral("GameOfLifeViewClass"));
        GameOfLifeViewClass->resize(450, 450);
        GameOfLifeViewClass->setMinimumSize(QSize(450, 450));
        GameOfLifeViewClass->setMaximumSize(QSize(2000, 1500));
        GameOfLifeViewClass->setAutoFillBackground(false);
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
        centralWidget = new QWidget(GameOfLifeViewClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 0, 431, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(25, 30));
        QFont font;
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        universeSizeX = new QSpinBox(horizontalLayoutWidget);
        universeSizeX->setObjectName(QStringLiteral("universeSizeX"));
        universeSizeX->setMinimumSize(QSize(100, 30));
        universeSizeX->setValue(40);

        horizontalLayout->addWidget(universeSizeX);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(25, 30));
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        universeSizeY = new QSpinBox(horizontalLayoutWidget);
        universeSizeY->setObjectName(QStringLiteral("universeSizeY"));
        universeSizeY->setMinimumSize(QSize(100, 30));
        universeSizeY->setValue(50);

        horizontalLayout->addWidget(universeSizeY);

        resizeButton = new QPushButton(horizontalLayoutWidget);
        resizeButton->setObjectName(QStringLiteral("resizeButton"));
        resizeButton->setMinimumSize(QSize(100, 30));
        resizeButton->setMaximumSize(QSize(100, 30));

        horizontalLayout->addWidget(resizeButton);

        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(5, 40, 441, 41));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        runButton = new QPushButton(horizontalLayoutWidget_2);
        runButton->setObjectName(QStringLiteral("runButton"));
        runButton->setMinimumSize(QSize(100, 30));
        runButton->setMaximumSize(QSize(100, 30));

        horizontalLayout_2->addWidget(runButton);

        nextButton = new QPushButton(horizontalLayoutWidget_2);
        nextButton->setObjectName(QStringLiteral("nextButton"));
        nextButton->setMinimumSize(QSize(100, 30));
        nextButton->setMaximumSize(QSize(100, 30));

        horizontalLayout_2->addWidget(nextButton);

        stopButton = new QPushButton(horizontalLayoutWidget_2);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setMinimumSize(QSize(100, 30));
        stopButton->setMaximumSize(QSize(100, 30));

        horizontalLayout_2->addWidget(stopButton);

        clearButton = new QPushButton(horizontalLayoutWidget_2);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setMinimumSize(QSize(100, 30));
        clearButton->setMaximumSize(QSize(100, 30));

        horizontalLayout_2->addWidget(clearButton);

        GameOfLifeViewClass->setCentralWidget(centralWidget);
        horizontalLayoutWidget->raise();
        universeSizeX->raise();
        horizontalLayoutWidget_2->raise();
        menuBar = new QMenuBar(GameOfLifeViewClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 450, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        GameOfLifeViewClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GameOfLifeViewClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(true);
        GameOfLifeViewClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GameOfLifeViewClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GameOfLifeViewClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
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
        label->setText(QApplication::translate("GameOfLifeViewClass", "row", 0));
        label_2->setText(QApplication::translate("GameOfLifeViewClass", "col", 0));
        resizeButton->setText(QApplication::translate("GameOfLifeViewClass", "resize", 0));
        runButton->setText(QApplication::translate("GameOfLifeViewClass", "run", 0));
        nextButton->setText(QApplication::translate("GameOfLifeViewClass", "next", 0));
        stopButton->setText(QApplication::translate("GameOfLifeViewClass", "stop", 0));
        clearButton->setText(QApplication::translate("GameOfLifeViewClass", "clear", 0));
        menuFile->setTitle(QApplication::translate("GameOfLifeViewClass", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class GameOfLifeViewClass: public Ui_GameOfLifeViewClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOFLIFEVIEW_H