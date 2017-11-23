/********************************************************************************
** Form generated from reading UI file 'initialview.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INITIALVIEW_H
#define UI_INITIALVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_InitialView
{
public:
    QLabel *label;
    QPushButton *newButton;
    QPushButton *openButton;

    void setupUi(QDialog *InitialView)
    {
        if (InitialView->objectName().isEmpty())
            InitialView->setObjectName(QStringLiteral("InitialView"));
        InitialView->resize(400, 300);
        InitialView->setMinimumSize(QSize(400, 300));
        InitialView->setMaximumSize(QSize(400, 300));
        label = new QLabel(InitialView);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(75, 60, 250, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("\353\202\230\353\210\224\353\260\224\353\245\270\352\263\240\353\224\225"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        newButton = new QPushButton(InitialView);
        newButton->setObjectName(QStringLiteral("newButton"));
        newButton->setGeometry(QRect(135, 150, 130, 40));
        openButton = new QPushButton(InitialView);
        openButton->setObjectName(QStringLiteral("openButton"));
        openButton->setGeometry(QRect(135, 200, 130, 40));

        retranslateUi(InitialView);

        QMetaObject::connectSlotsByName(InitialView);
    } // setupUi

    void retranslateUi(QDialog *InitialView)
    {
        InitialView->setWindowTitle(QApplication::translate("InitialView", "Game of Life", 0));
        label->setText(QApplication::translate("InitialView", "Game of Life", 0));
        newButton->setText(QApplication::translate("InitialView", "New", 0));
        openButton->setText(QApplication::translate("InitialView", "Open", 0));
    } // retranslateUi

};

namespace Ui {
    class InitialView: public Ui_InitialView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INITIALVIEW_H