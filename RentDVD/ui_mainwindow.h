/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *login;
    QLineEdit *haslo;
    QLabel *label;
    QLabel *label_2;
    QPushButton *logowanie;
    QLabel *komunikat;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(417, 198);
        MainWindow->setMinimumSize(QSize(417, 198));
        MainWindow->setMaximumSize(QSize(417, 198));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        login = new QLineEdit(centralWidget);
        login->setObjectName(QStringLiteral("login"));
        login->setGeometry(QRect(251, 21, 108, 22));
        haslo = new QLineEdit(centralWidget);
        haslo->setObjectName(QStringLiteral("haslo"));
        haslo->setGeometry(QRect(251, 49, 108, 22));
        haslo->setEchoMode(QLineEdit::Password);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(180, 22, 47, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(180, 49, 47, 20));
        logowanie = new QPushButton(centralWidget);
        logowanie->setObjectName(QStringLiteral("logowanie"));
        logowanie->setGeometry(QRect(280, 80, 80, 21));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        logowanie->setFont(font);
        komunikat = new QLabel(centralWidget);
        komunikat->setObjectName(QStringLiteral("komunikat"));
        komunikat->setGeometry(QRect(30, 100, 211, 41));
        komunikat->setBaseSize(QSize(0, 0));
        komunikat->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 417, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(false);
        mainToolBar->setMovable(false);
        mainToolBar->setAllowedAreas(Qt::NoToolBarArea);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        logowanie->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Logowanie", nullptr));
        label->setText(QApplication::translate("MainWindow", "Login:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Has\305\202o:", nullptr));
        logowanie->setText(QApplication::translate("MainWindow", "Zaloguj", nullptr));
        komunikat->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
