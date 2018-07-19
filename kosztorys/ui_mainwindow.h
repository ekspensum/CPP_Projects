/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionUstawienia;
    QAction *actionNowy_kosztorys;
    QAction *actionOtworz;
    QAction *actionZapisz_jako;
    QAction *actionZapisz;
    QWidget *centralWidget;
    QTableWidget *tableWidget;
    QPushButton *pushButtonWstawWiersz;
    QPushButton *pushButtonUsunWiersz;
    QPushButton *pushButtonDodajWiersz;
    QLabel *ogolem;
    QLabel *label;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menuOpcje;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1500, 750);
        MainWindow->setMinimumSize(QSize(1500, 750));
        actionUstawienia = new QAction(MainWindow);
        actionUstawienia->setObjectName(QStringLiteral("actionUstawienia"));
        QIcon icon;
        icon.addFile(QStringLiteral("../../_Materialy/Ikonki/tools-cross-settings-symbol-for-interface.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUstawienia->setIcon(icon);
        actionNowy_kosztorys = new QAction(MainWindow);
        actionNowy_kosztorys->setObjectName(QStringLiteral("actionNowy_kosztorys"));
        actionOtworz = new QAction(MainWindow);
        actionOtworz->setObjectName(QStringLiteral("actionOtworz"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../../_Materialy/Ikonki/open-folder-with-document.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOtworz->setIcon(icon1);
        actionZapisz_jako = new QAction(MainWindow);
        actionZapisz_jako->setObjectName(QStringLiteral("actionZapisz_jako"));
        actionZapisz = new QAction(MainWindow);
        actionZapisz->setObjectName(QStringLiteral("actionZapisz"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../../_Materialy/Ikonki/save-icon-silhouette.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZapisz->setIcon(icon2);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font);
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font);
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(30, 80, 1191, 561));
        tableWidget->setMinimumSize(QSize(971, 0));
        pushButtonWstawWiersz = new QPushButton(centralWidget);
        pushButtonWstawWiersz->setObjectName(QStringLiteral("pushButtonWstawWiersz"));
        pushButtonWstawWiersz->setGeometry(QRect(1290, 150, 130, 33));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        pushButtonWstawWiersz->setFont(font1);
        pushButtonUsunWiersz = new QPushButton(centralWidget);
        pushButtonUsunWiersz->setObjectName(QStringLiteral("pushButtonUsunWiersz"));
        pushButtonUsunWiersz->setGeometry(QRect(1290, 200, 130, 33));
        pushButtonUsunWiersz->setFont(font1);
        pushButtonDodajWiersz = new QPushButton(centralWidget);
        pushButtonDodajWiersz->setObjectName(QStringLiteral("pushButtonDodajWiersz"));
        pushButtonDodajWiersz->setGeometry(QRect(1290, 100, 130, 33));
        pushButtonDodajWiersz->setFont(font1);
        ogolem = new QLabel(centralWidget);
        ogolem->setObjectName(QStringLiteral("ogolem"));
        ogolem->setGeometry(QRect(1080, 650, 131, 31));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        ogolem->setFont(font2);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(804, 650, 231, 31));
        QFont font3;
        font3.setPointSize(10);
        label->setFont(font3);
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1500, 28));
        menuBar->setFont(font2);
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        menuOpcje = new QMenu(menuBar);
        menuOpcje->setObjectName(QStringLiteral("menuOpcje"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuOpcje->menuAction());
        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addSeparator();
        menuMenu->addAction(actionUstawienia);
        menuOpcje->addAction(actionNowy_kosztorys);
        menuOpcje->addAction(actionOtworz);
        menuOpcje->addAction(actionZapisz_jako);
        menuOpcje->addAction(actionZapisz);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Kosztorys", nullptr));
        actionUstawienia->setText(QApplication::translate("MainWindow", "Ustawienia", nullptr));
        actionNowy_kosztorys->setText(QApplication::translate("MainWindow", "Nowy kosztorys", nullptr));
        actionOtworz->setText(QApplication::translate("MainWindow", "Otw\303\263rz", nullptr));
#ifndef QT_NO_SHORTCUT
        actionOtworz->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionZapisz_jako->setText(QApplication::translate("MainWindow", "Zapisz jako...", nullptr));
        actionZapisz->setText(QApplication::translate("MainWindow", "Zapisz", nullptr));
#ifndef QT_NO_SHORTCUT
        actionZapisz->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Ozn. normy", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Opis czynno\305\233ci", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Jedn. miary", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Ilo\305\233\304\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Cena", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Warto\305\233\304\207", nullptr));
        pushButtonWstawWiersz->setText(QApplication::translate("MainWindow", "Wstaw wiersz", nullptr));
        pushButtonUsunWiersz->setText(QApplication::translate("MainWindow", "Usu\305\204 wiersz", nullptr));
        pushButtonDodajWiersz->setText(QApplication::translate("MainWindow", "Dodaj wiersz", nullptr));
        ogolem->setText(QApplication::translate("MainWindow", "0,00", nullptr));
        label->setText(QApplication::translate("MainWindow", "Warto\305\233\304\207 kosztorysu og\303\263\305\202em:", nullptr));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Opcje", nullptr));
        menuOpcje->setTitle(QApplication::translate("MainWindow", "Plik", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
