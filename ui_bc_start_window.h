/********************************************************************************
** Form generated from reading UI file 'bc_start_window.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BC_START_WINDOW_H
#define UI_BC_START_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BC_Start_Window
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BC_Start_Window)
    {
        if (BC_Start_Window->objectName().isEmpty())
            BC_Start_Window->setObjectName(QStringLiteral("BC_Start_Window"));
        BC_Start_Window->resize(800, 600);
        menubar = new QMenuBar(BC_Start_Window);
        menubar->setObjectName(QStringLiteral("menubar"));
        BC_Start_Window->setMenuBar(menubar);
        centralwidget = new QWidget(BC_Start_Window);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        BC_Start_Window->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(BC_Start_Window);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        BC_Start_Window->setStatusBar(statusbar);

        retranslateUi(BC_Start_Window);

        QMetaObject::connectSlotsByName(BC_Start_Window);
    } // setupUi

    void retranslateUi(QMainWindow *BC_Start_Window)
    {
        BC_Start_Window->setWindowTitle(QApplication::translate("BC_Start_Window", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BC_Start_Window: public Ui_BC_Start_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BC_START_WINDOW_H
