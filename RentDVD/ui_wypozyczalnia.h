/********************************************************************************
** Form generated from reading UI file 'wypozyczalnia.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WYPOZYCZALNIA_H
#define UI_WYPOZYCZALNIA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Wypozyczalnia
{
public:
    QTabWidget *tabWidget;
    QWidget *tabWypozyczenie;
    QTableWidget *tableWidgetWyszukajFilm;
    QComboBox *comboBoxGatunekWyszukaj;
    QPushButton *pushButtonWyszukajRokGatunek;
    QLabel *label_15;
    QPushButton *pushButtonWyszukajTytulOpis;
    QLabel *label_16;
    QLabel *komunikatyWypozycz;
    QPushButton *pushButtonWypozyczenie;
    QPushButton *pushButtonRezerwacja;
    QWidget *layoutWidget4;
    QGridLayout *gridLayout_8;
    QLabel *label_13;
    QLineEdit *lineEditOpisWyszukaj;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_9;
    QLabel *label_12;
    QLineEdit *lineEditTytulWyszukaj;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout_7;
    QLineEdit *lineEditRokWyszukaj;
    QLabel *label_14;
    QTableWidget *tableWidgetWyszukajKlienta;
    QLineEdit *lineEditImieWyszukaj;
    QLineEdit *lineEditNazwiskoWyszukaj;
    QLineEdit *lineEditMiastoWyszukaj;
    QLineEdit *lineEditUlicaWyszukaj;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QPushButton *pushButtonWyszukajKlienta;
    QLabel *label_21;
    QDateTimeEdit *dateTimeEditTerminZwrotu;
    QLabel *label_33;
    QLabel *label_34;
    QDateTimeEdit *dateTimeEditTerminRezerwacji;
    QWidget *tabZwrotOdwolanieRezerwacji;
    QPushButton *pushButtonWyszukajWypozyczoneKlientFilm;
    QTableWidget *tableWidgetWyszukajWypozyczone;
    QLabel *komunikatyZwrotOdwolanie;
    QLabel *label_37;
    QPushButton *pushButtonZwrot;
    QTableWidget *tableWidgetWyszukajZarezerwowane;
    QLabel *label_40;
    QLabel *label_41;
    QLineEdit *lineEditNazwiskoWyszukajZarezerwowane;
    QLabel *label_42;
    QLabel *label_43;
    QLineEdit *lineEditIdFilmuWyszukajZarezerwowane;
    QPushButton *pushButtonOdwolanie;
    QLineEdit *lineEditIdKlientaWyszukajZarezerwowane;
    QPushButton *pushButtonWyszukajZarezerwowaneKlientFilm;
    QLineEdit *lineEditIdFilmuWyszukajZwrot;
    QLabel *label_38;
    QLineEdit *lineEditIdKlientaWyszukajZwrot;
    QLabel *label_36;
    QLabel *label_39;
    QLineEdit *lineEditNazwiskoWyszukajZwrot;
    QWidget *tabDodajKlienta;
    QPushButton *pushButtonDodajKlienta;
    QLabel *label_29;
    QLabel *label_30;
    QLineEdit *lineEditEmail;
    QLabel *label_44;
    QLabel *label_45;
    QLineEdit *lineEditNazwiskoWyszukajEdytuj;
    QTableWidget *tableWidgetWyszukajKlientaEdycja;
    QLabel *label_46;
    QLabel *label_47;
    QLabel *komunikatyDodajKlienta;
    QPushButton *pushButtonDodajKlienta_2;
    QLabel *label_48;
    QLabel *label_49;
    QLabel *label_22;
    QLineEdit *lineEditImieKlienta;
    QLabel *label_23;
    QLineEdit *lineEditNazwiskoKlienta;
    QLabel *label_25;
    QLabel *label_24;
    QLineEdit *lineEditKodPocztowy;
    QLineEdit *lineEditMiasto;
    QLabel *label_26;
    QLabel *label_27;
    QLineEdit *lineEditUlica;
    QLineEdit *lineEditNrDomu;
    QLabel *label_28;
    QLineEdit *lineEditNrLokalu;
    QWidget *tabDodajFilm;
    QPushButton *pushButtonDodajFilm;
    QLabel *komunikatyDodajFilm;
    QWidget *layoutWidget5;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLineEdit *lineEditTytul;
    QWidget *layoutWidget6;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QLineEdit *lineEditRok;
    QWidget *layoutWidget7;
    QGridLayout *gridLayout_3;
    QSpinBox *spinBoxIleKopii;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_2;
    QWidget *layoutWidget8;
    QGridLayout *gridLayout_4;
    QLabel *label_11;
    QComboBox *comboBoxGatunek1;
    QLabel *label_7;
    QComboBox *comboBoxGatunek2;
    QLabel *label_10;
    QComboBox *comboBoxGatunek3;
    QLabel *label_31;
    QLabel *label_32;
    QSpacerItem *horizontalSpacer;
    QWidget *layoutWidget9;
    QGridLayout *gridLayout_6;
    QLabel *label_35;
    QLineEdit *lineEditCenaWypozyczenia;
    QWidget *layoutWidget10;
    QGridLayout *gridLayout_5;
    QLabel *label_9;
    QPlainTextEdit *plainTextEditOpis;
    QWidget *tabUstawienia;
    QWidget *tabDodajUzytkownika;
    QWidget *layoutWidget11;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEditLogin;
    QLabel *label_2;
    QLineEdit *lineEditHaslo;
    QLabel *label_3;
    QLineEdit *lineEditImieUzytkownika;
    QLabel *label_4;
    QLineEdit *lineEditNazwiskoUzytkownika;
    QPushButton *pushButtonDodajUzytkownika;
    QLabel *komunikatyDodajUzytkownika;

    void setupUi(QWidget *Wypozyczalnia)
    {
        if (Wypozyczalnia->objectName().isEmpty())
            Wypozyczalnia->setObjectName(QStringLiteral("Wypozyczalnia"));
        Wypozyczalnia->resize(1122, 658);
        tabWidget = new QTabWidget(Wypozyczalnia);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(10, 10, 1101, 641));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        tabWidget->setFont(font);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWypozyczenie = new QWidget();
        tabWypozyczenie->setObjectName(QStringLiteral("tabWypozyczenie"));
        tableWidgetWyszukajFilm = new QTableWidget(tabWypozyczenie);
        if (tableWidgetWyszukajFilm->columnCount() < 8)
            tableWidgetWyszukajFilm->setColumnCount(8);
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font1);
        tableWidgetWyszukajFilm->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font1);
        tableWidgetWyszukajFilm->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font1);
        tableWidgetWyszukajFilm->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font1);
        tableWidgetWyszukajFilm->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font1);
        tableWidgetWyszukajFilm->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font1);
        tableWidgetWyszukajFilm->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font1);
        tableWidgetWyszukajFilm->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font1);
        tableWidgetWyszukajFilm->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tableWidgetWyszukajFilm->setObjectName(QStringLiteral("tableWidgetWyszukajFilm"));
        tableWidgetWyszukajFilm->setGeometry(QRect(10, 90, 1071, 261));
        comboBoxGatunekWyszukaj = new QComboBox(tabWypozyczenie);
        comboBoxGatunekWyszukaj->setObjectName(QStringLiteral("comboBoxGatunekWyszukaj"));
        comboBoxGatunekWyszukaj->setGeometry(QRect(190, 52, 141, 22));
        pushButtonWyszukajRokGatunek = new QPushButton(tabWypozyczenie);
        pushButtonWyszukajRokGatunek->setObjectName(QStringLiteral("pushButtonWyszukajRokGatunek"));
        pushButtonWyszukajRokGatunek->setGeometry(QRect(360, 51, 80, 25));
        pushButtonWyszukajRokGatunek->setFont(font1);
        label_15 = new QLabel(tabWypozyczenie);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(240, 9, 61, 25));
        pushButtonWyszukajTytulOpis = new QPushButton(tabWypozyczenie);
        pushButtonWyszukajTytulOpis->setObjectName(QStringLiteral("pushButtonWyszukajTytulOpis"));
        pushButtonWyszukajTytulOpis->setGeometry(QRect(590, 10, 80, 25));
        pushButtonWyszukajTytulOpis->setFont(font1);
        label_16 = new QLabel(tabWypozyczenie);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(150, 50, 21, 25));
        komunikatyWypozycz = new QLabel(tabWypozyczenie);
        komunikatyWypozycz->setObjectName(QStringLiteral("komunikatyWypozycz"));
        komunikatyWypozycz->setGeometry(QRect(710, 10, 371, 51));
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(true);
        font2.setWeight(75);
        komunikatyWypozycz->setFont(font2);
        komunikatyWypozycz->setFrameShape(QFrame::StyledPanel);
        komunikatyWypozycz->setTextFormat(Qt::AutoText);
        komunikatyWypozycz->setScaledContents(false);
        komunikatyWypozycz->setWordWrap(true);
        pushButtonWypozyczenie = new QPushButton(tabWypozyczenie);
        pushButtonWypozyczenie->setObjectName(QStringLiteral("pushButtonWypozyczenie"));
        pushButtonWypozyczenie->setGeometry(QRect(950, 380, 130, 40));
        QPalette palette;
        QBrush brush(QColor(138, 124, 244, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Link, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Link, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Link, brush);
        pushButtonWypozyczenie->setPalette(palette);
        QFont font3;
        font3.setPointSize(11);
        font3.setBold(true);
        font3.setWeight(75);
        pushButtonWypozyczenie->setFont(font3);
        pushButtonRezerwacja = new QPushButton(tabWypozyczenie);
        pushButtonRezerwacja->setObjectName(QStringLiteral("pushButtonRezerwacja"));
        pushButtonRezerwacja->setGeometry(QRect(951, 541, 130, 40));
        pushButtonRezerwacja->setFont(font3);
        layoutWidget4 = new QWidget(tabWypozyczenie);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(320, 10, 249, 24));
        gridLayout_8 = new QGridLayout(layoutWidget4);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(layoutWidget4);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_8->addWidget(label_13, 0, 0, 1, 1);

        lineEditOpisWyszukaj = new QLineEdit(layoutWidget4);
        lineEditOpisWyszukaj->setObjectName(QStringLiteral("lineEditOpisWyszukaj"));
        lineEditOpisWyszukaj->setMinimumSize(QSize(150, 0));

        gridLayout_8->addWidget(lineEditOpisWyszukaj, 0, 1, 1, 1);

        layoutWidget2 = new QWidget(tabWypozyczenie);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 10, 224, 24));
        gridLayout_9 = new QGridLayout(layoutWidget2);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(layoutWidget2);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_9->addWidget(label_12, 0, 0, 1, 1);

        lineEditTytulWyszukaj = new QLineEdit(layoutWidget2);
        lineEditTytulWyszukaj->setObjectName(QStringLiteral("lineEditTytulWyszukaj"));
        lineEditTytulWyszukaj->setMinimumSize(QSize(120, 0));

        gridLayout_9->addWidget(lineEditTytulWyszukaj, 0, 1, 1, 1);

        layoutWidget3 = new QWidget(tabWypozyczenie);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 50, 125, 24));
        gridLayout_7 = new QGridLayout(layoutWidget3);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        lineEditRokWyszukaj = new QLineEdit(layoutWidget3);
        lineEditRokWyszukaj->setObjectName(QStringLiteral("lineEditRokWyszukaj"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEditRokWyszukaj->sizePolicy().hasHeightForWidth());
        lineEditRokWyszukaj->setSizePolicy(sizePolicy);
        lineEditRokWyszukaj->setMaximumSize(QSize(60, 16777215));

        gridLayout_7->addWidget(lineEditRokWyszukaj, 0, 1, 1, 1);

        label_14 = new QLabel(layoutWidget3);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_7->addWidget(label_14, 0, 0, 1, 1);

        tableWidgetWyszukajKlienta = new QTableWidget(tabWypozyczenie);
        if (tableWidgetWyszukajKlienta->columnCount() < 8)
            tableWidgetWyszukajKlienta->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font1);
        tableWidgetWyszukajKlienta->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font1);
        tableWidgetWyszukajKlienta->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font1);
        tableWidgetWyszukajKlienta->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFont(font1);
        tableWidgetWyszukajKlienta->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setFont(font1);
        tableWidgetWyszukajKlienta->setHorizontalHeaderItem(4, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setFont(font1);
        tableWidgetWyszukajKlienta->setHorizontalHeaderItem(5, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setFont(font1);
        tableWidgetWyszukajKlienta->setHorizontalHeaderItem(6, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setFont(font1);
        tableWidgetWyszukajKlienta->setHorizontalHeaderItem(7, __qtablewidgetitem15);
        tableWidgetWyszukajKlienta->setObjectName(QStringLiteral("tableWidgetWyszukajKlienta"));
        tableWidgetWyszukajKlienta->setGeometry(QRect(10, 430, 701, 161));
        lineEditImieWyszukaj = new QLineEdit(tabWypozyczenie);
        lineEditImieWyszukaj->setObjectName(QStringLiteral("lineEditImieWyszukaj"));
        lineEditImieWyszukaj->setGeometry(QRect(41, 400, 70, 22));
        lineEditNazwiskoWyszukaj = new QLineEdit(tabWypozyczenie);
        lineEditNazwiskoWyszukaj->setObjectName(QStringLiteral("lineEditNazwiskoWyszukaj"));
        lineEditNazwiskoWyszukaj->setGeometry(QRect(223, 400, 70, 22));
        lineEditMiastoWyszukaj = new QLineEdit(tabWypozyczenie);
        lineEditMiastoWyszukaj->setObjectName(QStringLiteral("lineEditMiastoWyszukaj"));
        lineEditMiastoWyszukaj->setGeometry(QRect(394, 400, 70, 22));
        lineEditUlicaWyszukaj = new QLineEdit(tabWypozyczenie);
        lineEditUlicaWyszukaj->setObjectName(QStringLiteral("lineEditUlicaWyszukaj"));
        lineEditUlicaWyszukaj->setGeometry(QRect(553, 400, 70, 22));
        label_17 = new QLabel(tabWypozyczenie);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(15, 400, 21, 22));
        label_18 = new QLabel(tabWypozyczenie);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(118, 400, 101, 22));
        label_19 = new QLabel(tabWypozyczenie);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(300, 400, 91, 22));
        label_20 = new QLabel(tabWypozyczenie);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(470, 400, 81, 22));
        pushButtonWyszukajKlienta = new QPushButton(tabWypozyczenie);
        pushButtonWyszukajKlienta->setObjectName(QStringLiteral("pushButtonWyszukajKlienta"));
        pushButtonWyszukajKlienta->setGeometry(QRect(632, 398, 80, 25));
        pushButtonWyszukajKlienta->setFont(font1);
        label_21 = new QLabel(tabWypozyczenie);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(15, 374, 191, 16));
        dateTimeEditTerminZwrotu = new QDateTimeEdit(tabWypozyczenie);
        dateTimeEditTerminZwrotu->setObjectName(QStringLiteral("dateTimeEditTerminZwrotu"));
        dateTimeEditTerminZwrotu->setGeometry(QRect(748, 387, 171, 31));
        dateTimeEditTerminZwrotu->setFont(font3);
        label_33 = new QLabel(tabWypozyczenie);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(748, 367, 171, 16));
        label_34 = new QLabel(tabWypozyczenie);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setGeometry(QRect(751, 528, 171, 16));
        dateTimeEditTerminRezerwacji = new QDateTimeEdit(tabWypozyczenie);
        dateTimeEditTerminRezerwacji->setObjectName(QStringLiteral("dateTimeEditTerminRezerwacji"));
        dateTimeEditTerminRezerwacji->setGeometry(QRect(750, 548, 171, 31));
        dateTimeEditTerminRezerwacji->setFont(font3);
        tabWidget->addTab(tabWypozyczenie, QString());
        tabZwrotOdwolanieRezerwacji = new QWidget();
        tabZwrotOdwolanieRezerwacji->setObjectName(QStringLiteral("tabZwrotOdwolanieRezerwacji"));
        pushButtonWyszukajWypozyczoneKlientFilm = new QPushButton(tabZwrotOdwolanieRezerwacji);
        pushButtonWyszukajWypozyczoneKlientFilm->setObjectName(QStringLiteral("pushButtonWyszukajWypozyczoneKlientFilm"));
        pushButtonWyszukajWypozyczoneKlientFilm->setGeometry(QRect(360, 9, 80, 25));
        pushButtonWyszukajWypozyczoneKlientFilm->setFont(font1);
        tableWidgetWyszukajWypozyczone = new QTableWidget(tabZwrotOdwolanieRezerwacji);
        if (tableWidgetWyszukajWypozyczone->columnCount() < 10)
            tableWidgetWyszukajWypozyczone->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setFont(font1);
        tableWidgetWyszukajWypozyczone->setHorizontalHeaderItem(0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem17->setFont(font1);
        tableWidgetWyszukajWypozyczone->setHorizontalHeaderItem(1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setFont(font1);
        tableWidgetWyszukajWypozyczone->setHorizontalHeaderItem(2, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setFont(font1);
        tableWidgetWyszukajWypozyczone->setHorizontalHeaderItem(3, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem20->setFont(font1);
        tableWidgetWyszukajWypozyczone->setHorizontalHeaderItem(4, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setFont(font1);
        tableWidgetWyszukajWypozyczone->setHorizontalHeaderItem(5, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        __qtablewidgetitem22->setFont(font1);
        tableWidgetWyszukajWypozyczone->setHorizontalHeaderItem(6, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        __qtablewidgetitem23->setFont(font1);
        tableWidgetWyszukajWypozyczone->setHorizontalHeaderItem(7, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        __qtablewidgetitem24->setFont(font1);
        tableWidgetWyszukajWypozyczone->setHorizontalHeaderItem(8, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        __qtablewidgetitem25->setFont(font1);
        tableWidgetWyszukajWypozyczone->setHorizontalHeaderItem(9, __qtablewidgetitem25);
        tableWidgetWyszukajWypozyczone->setObjectName(QStringLiteral("tableWidgetWyszukajWypozyczone"));
        tableWidgetWyszukajWypozyczone->setGeometry(QRect(10, 70, 871, 201));
        komunikatyZwrotOdwolanie = new QLabel(tabZwrotOdwolanieRezerwacji);
        komunikatyZwrotOdwolanie->setObjectName(QStringLiteral("komunikatyZwrotOdwolanie"));
        komunikatyZwrotOdwolanie->setGeometry(QRect(710, 10, 371, 51));
        komunikatyZwrotOdwolanie->setFont(font2);
        komunikatyZwrotOdwolanie->setFrameShape(QFrame::StyledPanel);
        komunikatyZwrotOdwolanie->setTextFormat(Qt::AutoText);
        komunikatyZwrotOdwolanie->setScaledContents(false);
        komunikatyZwrotOdwolanie->setWordWrap(true);
        label_37 = new QLabel(tabZwrotOdwolanieRezerwacji);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setGeometry(QRect(350, 40, 301, 22));
        pushButtonZwrot = new QPushButton(tabZwrotOdwolanieRezerwacji);
        pushButtonZwrot->setObjectName(QStringLiteral("pushButtonZwrot"));
        pushButtonZwrot->setGeometry(QRect(926, 70, 130, 40));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Link, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Link, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Link, brush);
        pushButtonZwrot->setPalette(palette1);
        pushButtonZwrot->setFont(font3);
        tableWidgetWyszukajZarezerwowane = new QTableWidget(tabZwrotOdwolanieRezerwacji);
        if (tableWidgetWyszukajZarezerwowane->columnCount() < 10)
            tableWidgetWyszukajZarezerwowane->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        __qtablewidgetitem26->setFont(font1);
        tableWidgetWyszukajZarezerwowane->setHorizontalHeaderItem(0, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        __qtablewidgetitem27->setFont(font1);
        tableWidgetWyszukajZarezerwowane->setHorizontalHeaderItem(1, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        __qtablewidgetitem28->setFont(font1);
        tableWidgetWyszukajZarezerwowane->setHorizontalHeaderItem(2, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        __qtablewidgetitem29->setFont(font1);
        tableWidgetWyszukajZarezerwowane->setHorizontalHeaderItem(3, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        __qtablewidgetitem30->setFont(font1);
        tableWidgetWyszukajZarezerwowane->setHorizontalHeaderItem(4, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        __qtablewidgetitem31->setFont(font1);
        tableWidgetWyszukajZarezerwowane->setHorizontalHeaderItem(5, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        __qtablewidgetitem32->setFont(font1);
        tableWidgetWyszukajZarezerwowane->setHorizontalHeaderItem(6, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        __qtablewidgetitem33->setFont(font1);
        tableWidgetWyszukajZarezerwowane->setHorizontalHeaderItem(7, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        __qtablewidgetitem34->setFont(font1);
        tableWidgetWyszukajZarezerwowane->setHorizontalHeaderItem(8, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        __qtablewidgetitem35->setFont(font1);
        tableWidgetWyszukajZarezerwowane->setHorizontalHeaderItem(9, __qtablewidgetitem35);
        tableWidgetWyszukajZarezerwowane->setObjectName(QStringLiteral("tableWidgetWyszukajZarezerwowane"));
        tableWidgetWyszukajZarezerwowane->setGeometry(QRect(10, 381, 871, 201));
        label_40 = new QLabel(tabZwrotOdwolanieRezerwacji);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setGeometry(QRect(203, 322, 91, 22));
        label_41 = new QLabel(tabZwrotOdwolanieRezerwacji);
        label_41->setObjectName(QStringLiteral("label_41"));
        label_41->setGeometry(QRect(350, 351, 301, 22));
        lineEditNazwiskoWyszukajZarezerwowane = new QLineEdit(tabZwrotOdwolanieRezerwacji);
        lineEditNazwiskoWyszukajZarezerwowane->setObjectName(QStringLiteral("lineEditNazwiskoWyszukajZarezerwowane"));
        lineEditNazwiskoWyszukajZarezerwowane->setGeometry(QRect(190, 351, 150, 22));
        lineEditNazwiskoWyszukajZarezerwowane->setMinimumSize(QSize(150, 0));
        label_42 = new QLabel(tabZwrotOdwolanieRezerwacji);
        label_42->setObjectName(QStringLiteral("label_42"));
        label_42->setGeometry(QRect(13, 351, 171, 22));
        label_43 = new QLabel(tabZwrotOdwolanieRezerwacji);
        label_43->setObjectName(QStringLiteral("label_43"));
        label_43->setGeometry(QRect(13, 322, 111, 22));
        lineEditIdFilmuWyszukajZarezerwowane = new QLineEdit(tabZwrotOdwolanieRezerwacji);
        lineEditIdFilmuWyszukajZarezerwowane->setObjectName(QStringLiteral("lineEditIdFilmuWyszukajZarezerwowane"));
        lineEditIdFilmuWyszukajZarezerwowane->setGeometry(QRect(138, 322, 40, 22));
        sizePolicy.setHeightForWidth(lineEditIdFilmuWyszukajZarezerwowane->sizePolicy().hasHeightForWidth());
        lineEditIdFilmuWyszukajZarezerwowane->setSizePolicy(sizePolicy);
        lineEditIdFilmuWyszukajZarezerwowane->setMaximumSize(QSize(60, 16777215));
        pushButtonOdwolanie = new QPushButton(tabZwrotOdwolanieRezerwacji);
        pushButtonOdwolanie->setObjectName(QStringLiteral("pushButtonOdwolanie"));
        pushButtonOdwolanie->setGeometry(QRect(926, 381, 130, 40));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Link, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Link, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Link, brush);
        pushButtonOdwolanie->setPalette(palette2);
        pushButtonOdwolanie->setFont(font3);
        lineEditIdKlientaWyszukajZarezerwowane = new QLineEdit(tabZwrotOdwolanieRezerwacji);
        lineEditIdKlientaWyszukajZarezerwowane->setObjectName(QStringLiteral("lineEditIdKlientaWyszukajZarezerwowane"));
        lineEditIdKlientaWyszukajZarezerwowane->setGeometry(QRect(300, 322, 40, 22));
        lineEditIdKlientaWyszukajZarezerwowane->setMinimumSize(QSize(30, 0));
        pushButtonWyszukajZarezerwowaneKlientFilm = new QPushButton(tabZwrotOdwolanieRezerwacji);
        pushButtonWyszukajZarezerwowaneKlientFilm->setObjectName(QStringLiteral("pushButtonWyszukajZarezerwowaneKlientFilm"));
        pushButtonWyszukajZarezerwowaneKlientFilm->setGeometry(QRect(360, 320, 80, 25));
        pushButtonWyszukajZarezerwowaneKlientFilm->setFont(font1);
        lineEditIdFilmuWyszukajZwrot = new QLineEdit(tabZwrotOdwolanieRezerwacji);
        lineEditIdFilmuWyszukajZwrot->setObjectName(QStringLiteral("lineEditIdFilmuWyszukajZwrot"));
        lineEditIdFilmuWyszukajZwrot->setGeometry(QRect(138, 11, 40, 22));
        sizePolicy.setHeightForWidth(lineEditIdFilmuWyszukajZwrot->sizePolicy().hasHeightForWidth());
        lineEditIdFilmuWyszukajZwrot->setSizePolicy(sizePolicy);
        lineEditIdFilmuWyszukajZwrot->setMaximumSize(QSize(60, 16777215));
        label_38 = new QLabel(tabZwrotOdwolanieRezerwacji);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setGeometry(QRect(13, 11, 111, 22));
        lineEditIdKlientaWyszukajZwrot = new QLineEdit(tabZwrotOdwolanieRezerwacji);
        lineEditIdKlientaWyszukajZwrot->setObjectName(QStringLiteral("lineEditIdKlientaWyszukajZwrot"));
        lineEditIdKlientaWyszukajZwrot->setGeometry(QRect(300, 11, 40, 22));
        lineEditIdKlientaWyszukajZwrot->setMinimumSize(QSize(30, 0));
        label_36 = new QLabel(tabZwrotOdwolanieRezerwacji);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(203, 11, 91, 22));
        label_39 = new QLabel(tabZwrotOdwolanieRezerwacji);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setGeometry(QRect(13, 40, 171, 22));
        lineEditNazwiskoWyszukajZwrot = new QLineEdit(tabZwrotOdwolanieRezerwacji);
        lineEditNazwiskoWyszukajZwrot->setObjectName(QStringLiteral("lineEditNazwiskoWyszukajZwrot"));
        lineEditNazwiskoWyszukajZwrot->setGeometry(QRect(190, 40, 150, 22));
        lineEditNazwiskoWyszukajZwrot->setMinimumSize(QSize(150, 0));
        tabWidget->addTab(tabZwrotOdwolanieRezerwacji, QString());
        tabDodajKlienta = new QWidget();
        tabDodajKlienta->setObjectName(QStringLiteral("tabDodajKlienta"));
        pushButtonDodajKlienta = new QPushButton(tabDodajKlienta);
        pushButtonDodajKlienta->setObjectName(QStringLiteral("pushButtonDodajKlienta"));
        pushButtonDodajKlienta->setGeometry(QRect(410, 40, 140, 25));
        pushButtonDodajKlienta->setFont(font1);
        label_29 = new QLabel(tabDodajKlienta);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(270, 99, 131, 16));
        label_30 = new QLabel(tabDodajKlienta);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(270, 210, 131, 16));
        lineEditEmail = new QLineEdit(tabDodajKlienta);
        lineEditEmail->setObjectName(QStringLiteral("lineEditEmail"));
        lineEditEmail->setGeometry(QRect(138, 235, 108, 22));
        label_44 = new QLabel(tabDodajKlienta);
        label_44->setObjectName(QStringLiteral("label_44"));
        label_44->setGeometry(QRect(61, 235, 45, 16));
        label_45 = new QLabel(tabDodajKlienta);
        label_45->setObjectName(QStringLiteral("label_45"));
        label_45->setGeometry(QRect(270, 240, 131, 16));
        lineEditNazwiskoWyszukajEdytuj = new QLineEdit(tabDodajKlienta);
        lineEditNazwiskoWyszukajEdytuj->setObjectName(QStringLiteral("lineEditNazwiskoWyszukajEdytuj"));
        lineEditNazwiskoWyszukajEdytuj->setGeometry(QRect(197, 320, 150, 22));
        lineEditNazwiskoWyszukajEdytuj->setMinimumSize(QSize(150, 0));
        tableWidgetWyszukajKlientaEdycja = new QTableWidget(tabDodajKlienta);
        if (tableWidgetWyszukajKlientaEdycja->columnCount() < 10)
            tableWidgetWyszukajKlientaEdycja->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        __qtablewidgetitem36->setFont(font1);
        tableWidgetWyszukajKlientaEdycja->setHorizontalHeaderItem(0, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        __qtablewidgetitem37->setFont(font1);
        tableWidgetWyszukajKlientaEdycja->setHorizontalHeaderItem(1, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        __qtablewidgetitem38->setFont(font1);
        tableWidgetWyszukajKlientaEdycja->setHorizontalHeaderItem(2, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        __qtablewidgetitem39->setFont(font1);
        tableWidgetWyszukajKlientaEdycja->setHorizontalHeaderItem(3, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        __qtablewidgetitem40->setFont(font1);
        tableWidgetWyszukajKlientaEdycja->setHorizontalHeaderItem(4, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        __qtablewidgetitem41->setFont(font1);
        tableWidgetWyszukajKlientaEdycja->setHorizontalHeaderItem(5, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        __qtablewidgetitem42->setFont(font1);
        tableWidgetWyszukajKlientaEdycja->setHorizontalHeaderItem(6, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        __qtablewidgetitem43->setFont(font1);
        tableWidgetWyszukajKlientaEdycja->setHorizontalHeaderItem(7, __qtablewidgetitem43);
        QFont font4;
        font4.setPointSize(8);
        font4.setBold(true);
        font4.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        __qtablewidgetitem44->setFont(font4);
        tableWidgetWyszukajKlientaEdycja->setHorizontalHeaderItem(8, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        __qtablewidgetitem45->setFont(font1);
        tableWidgetWyszukajKlientaEdycja->setHorizontalHeaderItem(9, __qtablewidgetitem45);
        tableWidgetWyszukajKlientaEdycja->setObjectName(QStringLiteral("tableWidgetWyszukajKlientaEdycja"));
        tableWidgetWyszukajKlientaEdycja->setGeometry(QRect(17, 350, 941, 201));
        label_46 = new QLabel(tabDodajKlienta);
        label_46->setObjectName(QStringLiteral("label_46"));
        label_46->setGeometry(QRect(357, 320, 301, 22));
        label_47 = new QLabel(tabDodajKlienta);
        label_47->setObjectName(QStringLiteral("label_47"));
        label_47->setGeometry(QRect(20, 320, 171, 22));
        komunikatyDodajKlienta = new QLabel(tabDodajKlienta);
        komunikatyDodajKlienta->setObjectName(QStringLiteral("komunikatyDodajKlienta"));
        komunikatyDodajKlienta->setGeometry(QRect(710, 10, 371, 51));
        komunikatyDodajKlienta->setFont(font2);
        komunikatyDodajKlienta->setFrameShape(QFrame::StyledPanel);
        komunikatyDodajKlienta->setFrameShadow(QFrame::Plain);
        komunikatyDodajKlienta->setWordWrap(true);
        pushButtonDodajKlienta_2 = new QPushButton(tabDodajKlienta);
        pushButtonDodajKlienta_2->setObjectName(QStringLiteral("pushButtonDodajKlienta_2"));
        pushButtonDodajKlienta_2->setGeometry(QRect(978, 350, 100, 25));
        pushButtonDodajKlienta_2->setFont(font1);
        label_48 = new QLabel(tabDodajKlienta);
        label_48->setObjectName(QStringLiteral("label_48"));
        label_48->setGeometry(QRect(20, 290, 141, 16));
        label_49 = new QLabel(tabDodajKlienta);
        label_49->setObjectName(QStringLiteral("label_49"));
        label_49->setGeometry(QRect(36, 10, 141, 16));
        label_22 = new QLabel(tabDodajKlienta);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(61, 39, 24, 16));
        lineEditImieKlienta = new QLineEdit(tabDodajKlienta);
        lineEditImieKlienta->setObjectName(QStringLiteral("lineEditImieKlienta"));
        lineEditImieKlienta->setGeometry(QRect(138, 39, 108, 22));
        label_23 = new QLabel(tabDodajKlienta);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(61, 67, 48, 16));
        lineEditNazwiskoKlienta = new QLineEdit(tabDodajKlienta);
        lineEditNazwiskoKlienta->setObjectName(QStringLiteral("lineEditNazwiskoKlienta"));
        lineEditNazwiskoKlienta->setGeometry(QRect(138, 67, 108, 22));
        label_25 = new QLabel(tabDodajKlienta);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(61, 123, 35, 16));
        label_24 = new QLabel(tabDodajKlienta);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(61, 95, 71, 16));
        lineEditKodPocztowy = new QLineEdit(tabDodajKlienta);
        lineEditKodPocztowy->setObjectName(QStringLiteral("lineEditKodPocztowy"));
        lineEditKodPocztowy->setGeometry(QRect(138, 95, 108, 22));
        lineEditKodPocztowy->setMaxLength(6);
        lineEditMiasto = new QLineEdit(tabDodajKlienta);
        lineEditMiasto->setObjectName(QStringLiteral("lineEditMiasto"));
        lineEditMiasto->setGeometry(QRect(138, 123, 108, 22));
        label_26 = new QLabel(tabDodajKlienta);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(61, 151, 26, 16));
        label_27 = new QLabel(tabDodajKlienta);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(61, 179, 44, 16));
        lineEditUlica = new QLineEdit(tabDodajKlienta);
        lineEditUlica->setObjectName(QStringLiteral("lineEditUlica"));
        lineEditUlica->setGeometry(QRect(138, 151, 108, 22));
        lineEditNrDomu = new QLineEdit(tabDodajKlienta);
        lineEditNrDomu->setObjectName(QStringLiteral("lineEditNrDomu"));
        lineEditNrDomu->setGeometry(QRect(138, 179, 108, 22));
        label_28 = new QLabel(tabDodajKlienta);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(61, 207, 45, 16));
        lineEditNrLokalu = new QLineEdit(tabDodajKlienta);
        lineEditNrLokalu->setObjectName(QStringLiteral("lineEditNrLokalu"));
        lineEditNrLokalu->setGeometry(QRect(138, 207, 108, 22));
        tabWidget->addTab(tabDodajKlienta, QString());
        tabDodajFilm = new QWidget();
        tabDodajFilm->setObjectName(QStringLiteral("tabDodajFilm"));
        pushButtonDodajFilm = new QPushButton(tabDodajFilm);
        pushButtonDodajFilm->setObjectName(QStringLiteral("pushButtonDodajFilm"));
        pushButtonDodajFilm->setGeometry(QRect(980, 420, 91, 25));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButtonDodajFilm->sizePolicy().hasHeightForWidth());
        pushButtonDodajFilm->setSizePolicy(sizePolicy1);
        pushButtonDodajFilm->setFont(font4);
        komunikatyDodajFilm = new QLabel(tabDodajFilm);
        komunikatyDodajFilm->setObjectName(QStringLiteral("komunikatyDodajFilm"));
        komunikatyDodajFilm->setGeometry(QRect(710, 10, 371, 51));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(komunikatyDodajFilm->sizePolicy().hasHeightForWidth());
        komunikatyDodajFilm->setSizePolicy(sizePolicy2);
        komunikatyDodajFilm->setFont(font2);
        komunikatyDodajFilm->setFrameShape(QFrame::StyledPanel);
        komunikatyDodajFilm->setWordWrap(true);
        layoutWidget5 = new QWidget(tabDodajFilm);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(20, 110, 607, 26));
        gridLayout = new QGridLayout(layoutWidget5);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget5);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(99, 0));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        lineEditTytul = new QLineEdit(layoutWidget5);
        lineEditTytul->setObjectName(QStringLiteral("lineEditTytul"));
        lineEditTytul->setMinimumSize(QSize(500, 0));
        QFont font5;
        font5.setPointSize(10);
        font5.setBold(true);
        font5.setWeight(75);
        lineEditTytul->setFont(font5);
        lineEditTytul->setMaxLength(100);

        gridLayout->addWidget(lineEditTytul, 0, 1, 1, 1);

        layoutWidget6 = new QWidget(tabDodajFilm);
        layoutWidget6->setObjectName(QStringLiteral("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(20, 140, 215, 26));
        gridLayout_2 = new QGridLayout(layoutWidget6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget6);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);
        label_6->setMinimumSize(QSize(99, 0));

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        lineEditRok = new QLineEdit(layoutWidget6);
        lineEditRok->setObjectName(QStringLiteral("lineEditRok"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lineEditRok->sizePolicy().hasHeightForWidth());
        lineEditRok->setSizePolicy(sizePolicy3);
        QFont font6;
        font6.setPointSize(10);
        lineEditRok->setFont(font6);
        lineEditRok->setMaxLength(4);

        gridLayout_2->addWidget(lineEditRok, 0, 1, 1, 1);

        layoutWidget7 = new QWidget(tabDodajFilm);
        layoutWidget7->setObjectName(QStringLiteral("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(20, 320, 198, 25));
        gridLayout_3 = new QGridLayout(layoutWidget7);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        spinBoxIleKopii = new QSpinBox(layoutWidget7);
        spinBoxIleKopii->setObjectName(QStringLiteral("spinBoxIleKopii"));
        spinBoxIleKopii->setValue(1);

        gridLayout_3->addWidget(spinBoxIleKopii, 0, 1, 1, 1);

        label_8 = new QLabel(layoutWidget7);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(99, 0));

        gridLayout_3->addWidget(label_8, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        layoutWidget8 = new QWidget(tabDodajFilm);
        layoutWidget8->setObjectName(QStringLiteral("layoutWidget8"));
        layoutWidget8->setGeometry(QRect(20, 351, 384, 80));
        gridLayout_4 = new QGridLayout(layoutWidget8);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(layoutWidget8);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMinimumSize(QSize(99, 0));

        gridLayout_4->addWidget(label_11, 2, 0, 1, 1);

        comboBoxGatunek1 = new QComboBox(layoutWidget8);
        comboBoxGatunek1->setObjectName(QStringLiteral("comboBoxGatunek1"));
        comboBoxGatunek1->setMinimumSize(QSize(120, 0));
        comboBoxGatunek1->setMaximumSize(QSize(16777215, 16777215));
        QFont font7;
        font7.setPointSize(9);
        comboBoxGatunek1->setFont(font7);
        comboBoxGatunek1->setMinimumContentsLength(0);

        gridLayout_4->addWidget(comboBoxGatunek1, 0, 1, 1, 1);

        label_7 = new QLabel(layoutWidget8);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(99, 0));

        gridLayout_4->addWidget(label_7, 0, 0, 1, 1);

        comboBoxGatunek2 = new QComboBox(layoutWidget8);
        comboBoxGatunek2->setObjectName(QStringLiteral("comboBoxGatunek2"));
        comboBoxGatunek2->setMinimumSize(QSize(120, 0));
        comboBoxGatunek2->setMaximumSize(QSize(16777215, 16777215));
        comboBoxGatunek2->setFont(font7);

        gridLayout_4->addWidget(comboBoxGatunek2, 1, 1, 1, 1);

        label_10 = new QLabel(layoutWidget8);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(99, 0));

        gridLayout_4->addWidget(label_10, 1, 0, 1, 1);

        comboBoxGatunek3 = new QComboBox(layoutWidget8);
        comboBoxGatunek3->setObjectName(QStringLiteral("comboBoxGatunek3"));
        comboBoxGatunek3->setMinimumSize(QSize(120, 0));
        comboBoxGatunek3->setMaximumSize(QSize(16777215, 16777215));
        comboBoxGatunek3->setFont(font7);

        gridLayout_4->addWidget(comboBoxGatunek3, 2, 1, 1, 1);

        label_31 = new QLabel(layoutWidget8);
        label_31->setObjectName(QStringLiteral("label_31"));

        gridLayout_4->addWidget(label_31, 2, 2, 1, 1);

        label_32 = new QLabel(layoutWidget8);
        label_32->setObjectName(QStringLiteral("label_32"));

        gridLayout_4->addWidget(label_32, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 2, 3, 1, 1);

        layoutWidget9 = new QWidget(tabDodajFilm);
        layoutWidget9->setObjectName(QStringLiteral("layoutWidget9"));
        layoutWidget9->setGeometry(QRect(20, 290, 215, 24));
        gridLayout_6 = new QGridLayout(layoutWidget9);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        label_35 = new QLabel(layoutWidget9);
        label_35->setObjectName(QStringLiteral("label_35"));

        gridLayout_6->addWidget(label_35, 0, 0, 1, 1);

        lineEditCenaWypozyczenia = new QLineEdit(layoutWidget9);
        lineEditCenaWypozyczenia->setObjectName(QStringLiteral("lineEditCenaWypozyczenia"));
        lineEditCenaWypozyczenia->setMaxLength(5);

        gridLayout_6->addWidget(lineEditCenaWypozyczenia, 0, 1, 1, 1);

        layoutWidget10 = new QWidget(tabDodajFilm);
        layoutWidget10->setObjectName(QStringLiteral("layoutWidget10"));
        layoutWidget10->setGeometry(QRect(20, 171, 1021, 111));
        gridLayout_5 = new QGridLayout(layoutWidget10);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget10);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(99, 0));

        gridLayout_5->addWidget(label_9, 0, 0, 1, 1);

        plainTextEditOpis = new QPlainTextEdit(layoutWidget10);
        plainTextEditOpis->setObjectName(QStringLiteral("plainTextEditOpis"));
        plainTextEditOpis->setFont(font6);

        gridLayout_5->addWidget(plainTextEditOpis, 0, 1, 1, 1);

        tabWidget->addTab(tabDodajFilm, QString());
        tabUstawienia = new QWidget();
        tabUstawienia->setObjectName(QStringLiteral("tabUstawienia"));
        tabWidget->addTab(tabUstawienia, QString());
        tabDodajUzytkownika = new QWidget();
        tabDodajUzytkownika->setObjectName(QStringLiteral("tabDodajUzytkownika"));
        layoutWidget11 = new QWidget(tabDodajUzytkownika);
        layoutWidget11->setObjectName(QStringLiteral("layoutWidget11"));
        layoutWidget11->setGeometry(QRect(60, 37, 251, 111));
        formLayout = new QFormLayout(layoutWidget11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget11);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEditLogin = new QLineEdit(layoutWidget11);
        lineEditLogin->setObjectName(QStringLiteral("lineEditLogin"));
        lineEditLogin->setFont(font7);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditLogin);

        label_2 = new QLabel(layoutWidget11);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEditHaslo = new QLineEdit(layoutWidget11);
        lineEditHaslo->setObjectName(QStringLiteral("lineEditHaslo"));
        lineEditHaslo->setFont(font7);
        lineEditHaslo->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditHaslo);

        label_3 = new QLabel(layoutWidget11);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        lineEditImieUzytkownika = new QLineEdit(layoutWidget11);
        lineEditImieUzytkownika->setObjectName(QStringLiteral("lineEditImieUzytkownika"));
        lineEditImieUzytkownika->setFont(font7);

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditImieUzytkownika);

        label_4 = new QLabel(layoutWidget11);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        lineEditNazwiskoUzytkownika = new QLineEdit(layoutWidget11);
        lineEditNazwiskoUzytkownika->setObjectName(QStringLiteral("lineEditNazwiskoUzytkownika"));
        lineEditNazwiskoUzytkownika->setFont(font7);

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEditNazwiskoUzytkownika);

        pushButtonDodajUzytkownika = new QPushButton(tabDodajUzytkownika);
        pushButtonDodajUzytkownika->setObjectName(QStringLiteral("pushButtonDodajUzytkownika"));
        pushButtonDodajUzytkownika->setGeometry(QRect(230, 160, 81, 25));
        sizePolicy1.setHeightForWidth(pushButtonDodajUzytkownika->sizePolicy().hasHeightForWidth());
        pushButtonDodajUzytkownika->setSizePolicy(sizePolicy1);
        pushButtonDodajUzytkownika->setFont(font4);
        komunikatyDodajUzytkownika = new QLabel(tabDodajUzytkownika);
        komunikatyDodajUzytkownika->setObjectName(QStringLiteral("komunikatyDodajUzytkownika"));
        komunikatyDodajUzytkownika->setGeometry(QRect(710, 10, 371, 51));
        komunikatyDodajUzytkownika->setFont(font2);
        komunikatyDodajUzytkownika->setFrameShape(QFrame::StyledPanel);
        komunikatyDodajUzytkownika->setWordWrap(true);
        tabWidget->addTab(tabDodajUzytkownika, QString());
#ifndef QT_NO_SHORTCUT
        label_13->setBuddy(lineEditOpisWyszukaj);
        label_12->setBuddy(lineEditTytulWyszukaj);
        label_40->setBuddy(lineEditTytulWyszukaj);
        label_42->setBuddy(lineEditOpisWyszukaj);
        label_36->setBuddy(lineEditTytulWyszukaj);
        label_39->setBuddy(lineEditOpisWyszukaj);
        label_47->setBuddy(lineEditOpisWyszukaj);
        label_5->setBuddy(lineEditTytul);
        label_6->setBuddy(lineEditRok);
        label_8->setBuddy(spinBoxIleKopii);
        label_11->setBuddy(comboBoxGatunek3);
        label_7->setBuddy(comboBoxGatunek1);
        label_10->setBuddy(comboBoxGatunek2);
        label->setBuddy(lineEditLogin);
        label_2->setBuddy(lineEditHaslo);
        label_3->setBuddy(lineEditImieUzytkownika);
        label_4->setBuddy(lineEditNazwiskoUzytkownika);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(lineEditTytul, lineEditRok);
        QWidget::setTabOrder(lineEditRok, spinBoxIleKopii);
        QWidget::setTabOrder(spinBoxIleKopii, comboBoxGatunek1);
        QWidget::setTabOrder(comboBoxGatunek1, comboBoxGatunek2);
        QWidget::setTabOrder(comboBoxGatunek2, comboBoxGatunek3);
        QWidget::setTabOrder(comboBoxGatunek3, lineEditLogin);
        QWidget::setTabOrder(lineEditLogin, lineEditHaslo);
        QWidget::setTabOrder(lineEditHaslo, lineEditImieUzytkownika);
        QWidget::setTabOrder(lineEditImieUzytkownika, lineEditNazwiskoUzytkownika);
        QWidget::setTabOrder(lineEditNazwiskoUzytkownika, pushButtonDodajUzytkownika);
        QWidget::setTabOrder(pushButtonDodajUzytkownika, tabWidget);

        retranslateUi(Wypozyczalnia);

        tabWidget->setCurrentIndex(0);
        comboBoxGatunek1->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(Wypozyczalnia);
    } // setupUi

    void retranslateUi(QWidget *Wypozyczalnia)
    {
        Wypozyczalnia->setWindowTitle(QApplication::translate("Wypozyczalnia", "Wypo\305\274yczalnia p\305\202yt DVD", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetWyszukajFilm->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Wypozyczalnia", "Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetWyszukajFilm->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Wypozyczalnia", "Tytu\305\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetWyszukajFilm->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Wypozyczalnia", "Rok prod.", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetWyszukajFilm->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Wypozyczalnia", "Gatunek g\305\202.", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetWyszukajFilm->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Wypozyczalnia", "Opis", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetWyszukajFilm->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Wypozyczalnia", "Cena", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetWyszukajFilm->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("Wypozyczalnia", "Wypo\305\274yczenie", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetWyszukajFilm->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("Wypozyczalnia", "Rezerwacja", nullptr));
        pushButtonWyszukajRokGatunek->setText(QApplication::translate("Wypozyczalnia", "Wyszukaj", nullptr));
        label_15->setText(QApplication::translate("Wypozyczalnia", "LUB / ORAZ", nullptr));
        pushButtonWyszukajTytulOpis->setText(QApplication::translate("Wypozyczalnia", "Wyszukaj", nullptr));
        label_16->setText(QApplication::translate("Wypozyczalnia", "LUB", nullptr));
        komunikatyWypozycz->setText(QString());
        pushButtonWypozyczenie->setText(QApplication::translate("Wypozyczalnia", "Wypo\305\274yczenie", nullptr));
        pushButtonRezerwacja->setText(QApplication::translate("Wypozyczalnia", "Rezerwacja", nullptr));
        label_13->setText(QApplication::translate("Wypozyczalnia", "Fragment opisu:", nullptr));
        label_12->setText(QApplication::translate("Wypozyczalnia", "Fragment tytu\305\202u:", nullptr));
        label_14->setText(QApplication::translate("Wypozyczalnia", "Rok prod.:", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetWyszukajKlienta->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("Wypozyczalnia", "Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidgetWyszukajKlienta->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("Wypozyczalnia", "Imi\304\231", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidgetWyszukajKlienta->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QApplication::translate("Wypozyczalnia", "Nazwisko", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidgetWyszukajKlienta->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QApplication::translate("Wypozyczalnia", "Miasto", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidgetWyszukajKlienta->horizontalHeaderItem(4);
        ___qtablewidgetitem12->setText(QApplication::translate("Wypozyczalnia", "Ulica", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidgetWyszukajKlienta->horizontalHeaderItem(5);
        ___qtablewidgetitem13->setText(QApplication::translate("Wypozyczalnia", "Nr domu", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidgetWyszukajKlienta->horizontalHeaderItem(6);
        ___qtablewidgetitem14->setText(QApplication::translate("Wypozyczalnia", "Wypo\305\274yczenie", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidgetWyszukajKlienta->horizontalHeaderItem(7);
        ___qtablewidgetitem15->setText(QApplication::translate("Wypozyczalnia", "Rezerwacja", nullptr));
        label_17->setText(QApplication::translate("Wypozyczalnia", "Imi\304\231:", nullptr));
        label_18->setText(QApplication::translate("Wypozyczalnia", "LUB/ORAZ Nazwisko:", nullptr));
        label_19->setText(QApplication::translate("Wypozyczalnia", "LUB/ORAZ Miasto:", nullptr));
        label_20->setText(QApplication::translate("Wypozyczalnia", "LUB/ORAZ Ulica:", nullptr));
        pushButtonWyszukajKlienta->setText(QApplication::translate("Wypozyczalnia", "Wyszukaj", nullptr));
        label_21->setText(QApplication::translate("Wypozyczalnia", "Wyszukaj wg ca\305\202o\305\233ci lub fragmentu:", nullptr));
        label_33->setText(QApplication::translate("Wypozyczalnia", "Planowana data i godzina zwrotu:", nullptr));
        label_34->setText(QApplication::translate("Wypozyczalnia", "Czas zako\305\204czenia rezerwacji:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabWypozyczenie), QApplication::translate("Wypozyczalnia", "Wypo\305\274yczenie / Rezerwacja", nullptr));
        pushButtonWyszukajWypozyczoneKlientFilm->setText(QApplication::translate("Wypozyczalnia", "Wyszukaj", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidgetWyszukajWypozyczone->horizontalHeaderItem(0);
        ___qtablewidgetitem16->setText(QApplication::translate("Wypozyczalnia", "Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidgetWyszukajWypozyczone->horizontalHeaderItem(1);
        ___qtablewidgetitem17->setText(QApplication::translate("Wypozyczalnia", "id Filmu", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidgetWyszukajWypozyczone->horizontalHeaderItem(2);
        ___qtablewidgetitem18->setText(QApplication::translate("Wypozyczalnia", "Tytu\305\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidgetWyszukajWypozyczone->horizontalHeaderItem(3);
        ___qtablewidgetitem19->setText(QApplication::translate("Wypozyczalnia", "Cena", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidgetWyszukajWypozyczone->horizontalHeaderItem(4);
        ___qtablewidgetitem20->setText(QApplication::translate("Wypozyczalnia", "id Klienta", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidgetWyszukajWypozyczone->horizontalHeaderItem(5);
        ___qtablewidgetitem21->setText(QApplication::translate("Wypozyczalnia", "Imie", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidgetWyszukajWypozyczone->horizontalHeaderItem(6);
        ___qtablewidgetitem22->setText(QApplication::translate("Wypozyczalnia", "Nazwisko", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidgetWyszukajWypozyczone->horizontalHeaderItem(7);
        ___qtablewidgetitem23->setText(QApplication::translate("Wypozyczalnia", "Data wypo\305\274ycz.", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidgetWyszukajWypozyczone->horizontalHeaderItem(8);
        ___qtablewidgetitem24->setText(QApplication::translate("Wypozyczalnia", "Plan. data zwrotu", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidgetWyszukajWypozyczone->horizontalHeaderItem(9);
        ___qtablewidgetitem25->setText(QApplication::translate("Wypozyczalnia", "ZWROT", nullptr));
        komunikatyZwrotOdwolanie->setText(QString());
        label_37->setText(QApplication::translate("Wypozyczalnia", "- wyszukiwanie dynamiczne po wprowadzaniu ka\305\274dej litery", nullptr));
        pushButtonZwrot->setText(QApplication::translate("Wypozyczalnia", "ZWROT", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidgetWyszukajZarezerwowane->horizontalHeaderItem(0);
        ___qtablewidgetitem26->setText(QApplication::translate("Wypozyczalnia", "Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidgetWyszukajZarezerwowane->horizontalHeaderItem(1);
        ___qtablewidgetitem27->setText(QApplication::translate("Wypozyczalnia", "id Filmu", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidgetWyszukajZarezerwowane->horizontalHeaderItem(2);
        ___qtablewidgetitem28->setText(QApplication::translate("Wypozyczalnia", "Tytu\305\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidgetWyszukajZarezerwowane->horizontalHeaderItem(3);
        ___qtablewidgetitem29->setText(QApplication::translate("Wypozyczalnia", "Cena", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidgetWyszukajZarezerwowane->horizontalHeaderItem(4);
        ___qtablewidgetitem30->setText(QApplication::translate("Wypozyczalnia", "id Klienta", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidgetWyszukajZarezerwowane->horizontalHeaderItem(5);
        ___qtablewidgetitem31->setText(QApplication::translate("Wypozyczalnia", "Imie", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidgetWyszukajZarezerwowane->horizontalHeaderItem(6);
        ___qtablewidgetitem32->setText(QApplication::translate("Wypozyczalnia", "Nazwisko", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidgetWyszukajZarezerwowane->horizontalHeaderItem(7);
        ___qtablewidgetitem33->setText(QApplication::translate("Wypozyczalnia", "Data rezerwacji", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidgetWyszukajZarezerwowane->horizontalHeaderItem(8);
        ___qtablewidgetitem34->setText(QApplication::translate("Wypozyczalnia", "Termin rezerw.", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidgetWyszukajZarezerwowane->horizontalHeaderItem(9);
        ___qtablewidgetitem35->setText(QApplication::translate("Wypozyczalnia", "ODWO\305\201ANIE", nullptr));
        label_40->setText(QApplication::translate("Wypozyczalnia", "LUB    Id klienta:", nullptr));
        label_41->setText(QApplication::translate("Wypozyczalnia", "- wyszukiwanie dynamiczne po wprowadzaniu ka\305\274dej litery", nullptr));
        label_42->setText(QApplication::translate("Wypozyczalnia", "Wyszukaj wg fragmentu nazwiska:", nullptr));
        label_43->setText(QApplication::translate("Wypozyczalnia", "Wyszukaj wg Id filmu:", nullptr));
        pushButtonOdwolanie->setText(QApplication::translate("Wypozyczalnia", "ODWO\305\201ANIE", nullptr));
        pushButtonWyszukajZarezerwowaneKlientFilm->setText(QApplication::translate("Wypozyczalnia", "Wyszukaj", nullptr));
        label_38->setText(QApplication::translate("Wypozyczalnia", "Wyszukaj wg Id filmu:", nullptr));
        label_36->setText(QApplication::translate("Wypozyczalnia", "LUB    Id klienta:", nullptr));
        label_39->setText(QApplication::translate("Wypozyczalnia", "Wyszukaj wg fragmentu nazwiska:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabZwrotOdwolanieRezerwacji), QApplication::translate("Wypozyczalnia", "Zwrot / Odwo\305\202anie rezerwacji", nullptr));
        pushButtonDodajKlienta->setText(QApplication::translate("Wypozyczalnia", "Dodaj nowego Klienta", nullptr));
        label_29->setText(QApplication::translate("Wypozyczalnia", "* pole NIE jest wymagane", nullptr));
        label_30->setText(QApplication::translate("Wypozyczalnia", "* pole NIE jest wymagane", nullptr));
        label_44->setText(QApplication::translate("Wypozyczalnia", "E-mail:", nullptr));
        label_45->setText(QApplication::translate("Wypozyczalnia", "* pole NIE jest wymagane", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidgetWyszukajKlientaEdycja->horizontalHeaderItem(0);
        ___qtablewidgetitem36->setText(QApplication::translate("Wypozyczalnia", "Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidgetWyszukajKlientaEdycja->horizontalHeaderItem(1);
        ___qtablewidgetitem37->setText(QApplication::translate("Wypozyczalnia", "Imi\304\231", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidgetWyszukajKlientaEdycja->horizontalHeaderItem(2);
        ___qtablewidgetitem38->setText(QApplication::translate("Wypozyczalnia", "Nazwisko", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidgetWyszukajKlientaEdycja->horizontalHeaderItem(3);
        ___qtablewidgetitem39->setText(QApplication::translate("Wypozyczalnia", "Kod poczt.", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidgetWyszukajKlientaEdycja->horizontalHeaderItem(4);
        ___qtablewidgetitem40->setText(QApplication::translate("Wypozyczalnia", "Miasto", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidgetWyszukajKlientaEdycja->horizontalHeaderItem(5);
        ___qtablewidgetitem41->setText(QApplication::translate("Wypozyczalnia", "Ulica", nullptr));
        QTableWidgetItem *___qtablewidgetitem42 = tableWidgetWyszukajKlientaEdycja->horizontalHeaderItem(6);
        ___qtablewidgetitem42->setText(QApplication::translate("Wypozyczalnia", "Nr domu", nullptr));
        QTableWidgetItem *___qtablewidgetitem43 = tableWidgetWyszukajKlientaEdycja->horizontalHeaderItem(7);
        ___qtablewidgetitem43->setText(QApplication::translate("Wypozyczalnia", "Nr lokalu", nullptr));
        QTableWidgetItem *___qtablewidgetitem44 = tableWidgetWyszukajKlientaEdycja->horizontalHeaderItem(8);
        ___qtablewidgetitem44->setText(QApplication::translate("Wypozyczalnia", "E-mail", nullptr));
        QTableWidgetItem *___qtablewidgetitem45 = tableWidgetWyszukajKlientaEdycja->horizontalHeaderItem(9);
        ___qtablewidgetitem45->setText(QApplication::translate("Wypozyczalnia", "EDYTUJ", nullptr));
        label_46->setText(QApplication::translate("Wypozyczalnia", "- wyszukiwanie dynamiczne po wprowadzaniu ka\305\274dej litery", nullptr));
        label_47->setText(QApplication::translate("Wypozyczalnia", "Wyszukaj wg fragmentu nazwiska:", nullptr));
        komunikatyDodajKlienta->setText(QString());
        pushButtonDodajKlienta_2->setText(QApplication::translate("Wypozyczalnia", "Zapisz zmiany", nullptr));
        label_48->setText(QApplication::translate("Wypozyczalnia", "Edytuj wybranego Klienta:", nullptr));
        label_49->setText(QApplication::translate("Wypozyczalnia", "Dodaj nowego Klienta:", nullptr));
        label_22->setText(QApplication::translate("Wypozyczalnia", "Imi\304\231:", nullptr));
        label_23->setText(QApplication::translate("Wypozyczalnia", "Nazwisko:", nullptr));
        label_25->setText(QApplication::translate("Wypozyczalnia", "Miasto:", nullptr));
        label_24->setText(QApplication::translate("Wypozyczalnia", "Kod pocztowy:", nullptr));
        lineEditKodPocztowy->setInputMask(QApplication::translate("Wypozyczalnia", "99-999", nullptr));
        label_26->setText(QApplication::translate("Wypozyczalnia", "Ulica:", nullptr));
        label_27->setText(QApplication::translate("Wypozyczalnia", "Nr domu:", nullptr));
        label_28->setText(QApplication::translate("Wypozyczalnia", "Nr lokalu:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabDodajKlienta), QApplication::translate("Wypozyczalnia", "Dodaj / Edytuj Klienta", nullptr));
        pushButtonDodajFilm->setText(QApplication::translate("Wypozyczalnia", "Dodaj film", nullptr));
        komunikatyDodajFilm->setText(QString());
        label_5->setText(QApplication::translate("Wypozyczalnia", "Tytu\305\202:", nullptr));
        label_6->setText(QApplication::translate("Wypozyczalnia", "Rok produkcji:", nullptr));
        lineEditRok->setInputMask(QApplication::translate("Wypozyczalnia", "9999", nullptr));
        lineEditRok->setText(QString());
        label_8->setText(QApplication::translate("Wypozyczalnia", "Ilo\305\233\304\207 kopii:", nullptr));
        label_11->setText(QApplication::translate("Wypozyczalnia", "Gatunek3:", nullptr));
        label_7->setText(QApplication::translate("Wypozyczalnia", "Gatunek1:", nullptr));
        label_10->setText(QApplication::translate("Wypozyczalnia", "Gatunek2:", nullptr));
        label_31->setText(QApplication::translate("Wypozyczalnia", "* pole NIE jest wymagane", nullptr));
        label_32->setText(QApplication::translate("Wypozyczalnia", "* pole NIE jest wymagane", nullptr));
        label_35->setText(QApplication::translate("Wypozyczalnia", "Cena wypo\305\274yczenia:", nullptr));
        lineEditCenaWypozyczenia->setInputMask(QApplication::translate("Wypozyczalnia", "99.99", nullptr));
        label_9->setText(QApplication::translate("Wypozyczalnia", "Opis:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabDodajFilm), QApplication::translate("Wypozyczalnia", "Dodaj / Edytuj film", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabUstawienia), QApplication::translate("Wypozyczalnia", "Ustawienia", nullptr));
        label->setText(QApplication::translate("Wypozyczalnia", "Login:", nullptr));
        label_2->setText(QApplication::translate("Wypozyczalnia", "Has\305\202o:", nullptr));
        label_3->setText(QApplication::translate("Wypozyczalnia", "Imi\304\231:", nullptr));
        label_4->setText(QApplication::translate("Wypozyczalnia", "Nazwisko:", nullptr));
        pushButtonDodajUzytkownika->setText(QApplication::translate("Wypozyczalnia", "Dodaj", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabDodajUzytkownika), QApplication::translate("Wypozyczalnia", "Dodaj / Edytuj U\305\274ytkownika", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Wypozyczalnia: public Ui_Wypozyczalnia {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WYPOZYCZALNIA_H
