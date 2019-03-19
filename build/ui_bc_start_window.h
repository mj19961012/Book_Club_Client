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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BC_Start_Window
{
public:
    QWidget *centralwidget;
    QLabel *b;

    void setupUi(QMainWindow *BC_Start_Window)
    {
        if (BC_Start_Window->objectName().isEmpty())
            BC_Start_Window->setObjectName(QStringLiteral("BC_Start_Window"));
        BC_Start_Window->setWindowModality(Qt::ApplicationModal);
        BC_Start_Window->resize(710, 420);
        BC_Start_Window->setMinimumSize(QSize(710, 420));
        BC_Start_Window->setMaximumSize(QSize(710, 420));
        centralwidget = new QWidget(BC_Start_Window);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        b = new QLabel(centralwidget);
        b->setObjectName(QStringLiteral("b"));
        b->setGeometry(QRect(130, 120, 100, 100));
        b->setMinimumSize(QSize(100, 100));
        b->setMaximumSize(QSize(100, 100));
        BC_Start_Window->setCentralWidget(centralwidget);

        retranslateUi(BC_Start_Window);

        QMetaObject::connectSlotsByName(BC_Start_Window);
    } // setupUi

    void retranslateUi(QMainWindow *BC_Start_Window)
    {
        BC_Start_Window->setWindowTitle(QApplication::translate("BC_Start_Window", "MainWindow", nullptr));
        b->setText(QApplication::translate("BC_Start_Window", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BC_Start_Window: public Ui_BC_Start_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BC_START_WINDOW_H
