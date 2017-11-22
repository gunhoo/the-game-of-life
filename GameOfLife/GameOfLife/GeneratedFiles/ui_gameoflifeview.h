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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GameOfLifeViewClass)
    {
        if (GameOfLifeViewClass->objectName().isEmpty())
            GameOfLifeViewClass->setObjectName(QStringLiteral("GameOfLifeViewClass"));
        GameOfLifeViewClass->resize(717, 400);
        actionNew = new QAction(GameOfLifeViewClass);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionOpen = new QAction(GameOfLifeViewClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(GameOfLifeViewClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_As = new QAction(GameOfLifeViewClass);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        centralWidget = new QWidget(GameOfLifeViewClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(640, 320, 75, 23));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(560, 320, 75, 23));
        GameOfLifeViewClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GameOfLifeViewClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 717, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        GameOfLifeViewClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GameOfLifeViewClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GameOfLifeViewClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GameOfLifeViewClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GameOfLifeViewClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);

        retranslateUi(GameOfLifeViewClass);

        QMetaObject::connectSlotsByName(GameOfLifeViewClass);
    } // setupUi

    void retranslateUi(QMainWindow *GameOfLifeViewClass)
    {
        GameOfLifeViewClass->setWindowTitle(QApplication::translate("GameOfLifeViewClass", "GameOfLifeView", 0));
        actionNew->setText(QApplication::translate("GameOfLifeViewClass", "New", 0));
        actionOpen->setText(QApplication::translate("GameOfLifeViewClass", "Open", 0));
        actionSave->setText(QApplication::translate("GameOfLifeViewClass", "Save", 0));
        actionSave_As->setText(QApplication::translate("GameOfLifeViewClass", "Save As", 0));
        pushButton->setText(QApplication::translate("GameOfLifeViewClass", "run", 0));
        pushButton_2->setText(QApplication::translate("GameOfLifeViewClass", "next", 0));
        menuFile->setTitle(QApplication::translate("GameOfLifeViewClass", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class GameOfLifeViewClass: public Ui_GameOfLifeViewClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOFLIFEVIEW_H
