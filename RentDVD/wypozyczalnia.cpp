#include "wypozyczalnia.h"
#include "ui_wypozyczalnia.h"

Wypozyczalnia::Wypozyczalnia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wypozyczalnia)
{
    ui->setupUi(this);
    ui->tabWidget->setTabEnabled(6, false);
    if (ObslugaBD::idZalogowanyUzytkownik == 1 || ObslugaBD::idZalogowanyUzytkownik == 23)
        ui->tabWidget->setTabEnabled(6, true);
    ui->tabWidget->setCurrentIndex(0);
    bd = new ObslugaBD();
    bd->wyszukajGatunki();
    for(int i=0; i<bd->getListaGatunkow().size(); i++)
    {
        ui->comboBoxGatunekWyszukaj->addItem(bd->getListaGatunkow().at(i)->getNazwa(), QVariant(bd->getListaGatunkow().at(i)->getIdGatunku()));
        ui->comboBoxGatunek1->addItem(bd->getListaGatunkow().at(i)->getNazwa(), QVariant(bd->getListaGatunkow().at(i)->getIdGatunku()));
        ui->comboBoxGatunek2->addItem(bd->getListaGatunkow().at(i)->getNazwa(), QVariant(bd->getListaGatunkow().at(i)->getIdGatunku()));
        ui->comboBoxGatunek3->addItem(bd->getListaGatunkow().at(i)->getNazwa(), QVariant(bd->getListaGatunkow().at(i)->getIdGatunku()));
    }
    //    ui->tabWidget->setStyleSheet("QTabWidget::pane { border: 1px solid #000033; }");
    ui->plainTextEditOpis->setStyleSheet("QWidget::pane > QWidget { background-color: #C3C3AE; }");
    ui->lineEditCenaWypozyczenia->setStyleSheet("QWidget::pane > QWidget { background-color: #C3C3AE; }");
    ui->lineEditTytul->setStyleSheet("QWidget::pane > QWidget { background-color: #C3C3AE; }");
    ui->lineEditRok->setStyleSheet("QWidget::pane > QWidget { background-color: #C3C3AE; }");
    ui->tabWidget->setStyleSheet("QTabWidget::pane > QWidget { background-color: #b8b8b8; }");
    ui->tableWidgetWyszukajFilm->setStyleSheet("QWidget::pane > QWidget { background-color: #C3C3AE; }");
    ui->tableWidgetWyszukajFilm->verticalHeader()->close();
    ui->tableWidgetWyszukajFilm->setColumnWidth(0,35);
    ui->tableWidgetWyszukajFilm->setColumnWidth(1,185);
    ui->tableWidgetWyszukajFilm->setColumnWidth(2,75);
    ui->tableWidgetWyszukajFilm->setColumnWidth(3,85);
    ui->tableWidgetWyszukajFilm->setColumnWidth(4,410);
    ui->tableWidgetWyszukajFilm->setColumnWidth(5,50);
    ui->tableWidgetWyszukajFilm->setColumnWidth(6,105);
    ui->tableWidgetWyszukajFilm->setColumnWidth(7,85);
    ui->tableWidgetWyszukajKlienta->setStyleSheet("QWidget::pane > QWidget { background-color: #C3C3AE; }");
    ui->tableWidgetWyszukajKlienta->verticalHeader()->close();
    ui->tableWidgetWyszukajKlienta->setColumnWidth(0,35);
    ui->tableWidgetWyszukajKlienta->setColumnWidth(1,75);
    ui->tableWidgetWyszukajKlienta->setColumnWidth(2,105);
    ui->tableWidgetWyszukajKlienta->setColumnWidth(3,90);
    ui->tableWidgetWyszukajKlienta->setColumnWidth(4,100);
    ui->tableWidgetWyszukajKlienta->setColumnWidth(5,65);
    ui->tableWidgetWyszukajKlienta->setColumnWidth(6,105);
    ui->tableWidgetWyszukajKlienta->setColumnWidth(7,85);
    ui->dateTimeEditTerminZwrotu->setDateTime(planowaDataZwrotu.currentDateTime().addDays(2));
    ui->dateTimeEditTerminRezerwacji->setDateTime(czasRezerwacji.currentDateTime().addDays(1));
    ui->dateTimeEditStatystykaOd->setDateTime(statystykaDataOd.currentDateTime().addDays(-7));
    ui->dateTimeEditStatystykaDo->setDateTime(statystykaDataDo.currentDateTime());
    p.setColor(QPalette::ButtonText, Qt::blue);
    ui->pushButtonWypozyczenie->setPalette(p);
    ui->pushButtonZwrot->setPalette(p);
    jedenFilmRezerwuj.setText("Proszę zazanaczyć jeden film do rezerwacji.");
    jedenKlientRezerwuj.setText("Proszę zazanaczyć jednego klienta do rezerwacji.");
    jedenFilmWypozycz.setText("Proszę zazanaczyć jeden film do wypożyczenia.");
    jedenKlientWypozycz.setText("Proszę zazanaczyć jednego klienta do wypożyczenia.");
    jedenKlientEdytuj.setText("Proszę zazanaczyć jednego klienta do edycji.");
    jedenFilmZwrot.setText("Proszę zazanaczyć jeden film do zwrotu");
    jedenFilmOdwolaj.setText("Proszę zazanaczyć jeden film do odwołania rezerwacji");
    jedenFilmEdytuj.setText("Proszę zazanaczyć jeden film do edycji.");
    jedenUzytkownikEdytuj.setText("Proszę zazanaczyć jednego użytkownika do edycji.");
    zmianaHaslaUzytkownik.setText("Hasło użytkownika zostało zmienione.");
    nowyGatunekPustePole.setText("Proszę wprowadzić nazwę gatunku filmowego.");
    ui->tableWidgetWyszukajWypozyczone->setStyleSheet("QWidget::pane > QWidget { background-color: #C3C3AE; }");
    ui->tableWidgetWyszukajWypozyczone->verticalHeader()->close();
    ui->tableWidgetWyszukajWypozyczone->setColumnWidth(0,35);
    ui->tableWidgetWyszukajWypozyczone->setColumnWidth(1,55);
    ui->tableWidgetWyszukajWypozyczone->setColumnWidth(2,170);
    ui->tableWidgetWyszukajWypozyczone->setColumnWidth(3,60);
    ui->tableWidgetWyszukajWypozyczone->setColumnWidth(4,65);
    ui->tableWidgetWyszukajWypozyczone->setColumnWidth(5,60);
    ui->tableWidgetWyszukajWypozyczone->setColumnWidth(6,110);
    ui->tableWidgetWyszukajWypozyczone->setColumnWidth(7,105);
    ui->tableWidgetWyszukajWypozyczone->setColumnWidth(8,110);
    ui->tableWidgetWyszukajWypozyczone->setColumnWidth(9,60);
    ui->tableWidgetWyszukajZarezerwowane->setStyleSheet("QWidget::pane > QWidget { background-color: #C3C3AE; }");
    ui->tableWidgetWyszukajZarezerwowane->verticalHeader()->close();
    ui->tableWidgetWyszukajZarezerwowane->setColumnWidth(0,35);
    ui->tableWidgetWyszukajZarezerwowane->setColumnWidth(1,60);
    ui->tableWidgetWyszukajZarezerwowane->setColumnWidth(2,170);
    ui->tableWidgetWyszukajZarezerwowane->setColumnWidth(3,55);
    ui->tableWidgetWyszukajZarezerwowane->setColumnWidth(4,65);
    ui->tableWidgetWyszukajZarezerwowane->setColumnWidth(5,60);
    ui->tableWidgetWyszukajZarezerwowane->setColumnWidth(6,100);
    ui->tableWidgetWyszukajZarezerwowane->setColumnWidth(7,100);
    ui->tableWidgetWyszukajZarezerwowane->setColumnWidth(8,100);
    ui->tableWidgetWyszukajZarezerwowane->setColumnWidth(9,85);
    ui->tableWidgetWyszukajKlientaEdycja->setStyleSheet("QWidget::pane > QWidget { background-color: #C3C3AE; }");
    ui->tableWidgetWyszukajKlientaEdycja->verticalHeader()->close();
    ui->tableWidgetWyszukajKlientaEdycja->setColumnWidth(0,35);
    ui->tableWidgetWyszukajKlientaEdycja->setColumnWidth(1,80);
    ui->tableWidgetWyszukajKlientaEdycja->setColumnWidth(2,120);
    ui->tableWidgetWyszukajKlientaEdycja->setColumnWidth(3,80);
    ui->tableWidgetWyszukajKlientaEdycja->setColumnWidth(4,120);
    ui->tableWidgetWyszukajKlientaEdycja->setColumnWidth(5,130);
    ui->tableWidgetWyszukajKlientaEdycja->setColumnWidth(6,60);
    ui->tableWidgetWyszukajKlientaEdycja->setColumnWidth(7,60);
    ui->tableWidgetWyszukajKlientaEdycja->setColumnWidth(8,160);
    ui->tableWidgetWyszukajKlientaEdycja->setColumnWidth(9,110);
    ui->tableWidgetWyszukajKlientaEdycja->setColumnWidth(10,60);
    ui->tableWidgetWyszukajFilmEdycja->setStyleSheet("QWidget::pane > QWidget { background-color: #C3C3AE; }");
    ui->tableWidgetWyszukajFilmEdycja->verticalHeader()->close();
    ui->tableWidgetWyszukajFilmEdycja->setColumnWidth(0,35);
    ui->tableWidgetWyszukajFilmEdycja->setColumnWidth(1,150);
    ui->tableWidgetWyszukajFilmEdycja->setColumnWidth(2,50);
    ui->tableWidgetWyszukajFilmEdycja->setColumnWidth(3,230);
    ui->tableWidgetWyszukajFilmEdycja->setColumnWidth(4,55);
    ui->tableWidgetWyszukajFilmEdycja->setColumnWidth(5,70);
    ui->tableWidgetWyszukajFilmEdycja->setColumnWidth(6,125);
    ui->tableWidgetWyszukajFilmEdycja->setColumnWidth(7,125);
    ui->tableWidgetWyszukajFilmEdycja->setColumnWidth(8,120);
    ui->tableWidgetWyszukajFilmEdycja->setColumnWidth(9,60);
    ui->tableWidgetWyszukajUzytkownikaEdycja->setStyleSheet("QWidget::pane > QWidget { background-color: #C3C3AE; }");
    ui->tableWidgetWyszukajUzytkownikaEdycja->verticalHeader()->close();
    ui->tableWidgetWyszukajUzytkownikaEdycja->setColumnWidth(0,35);
    ui->tableWidgetWyszukajUzytkownikaEdycja->setColumnWidth(1,110);
    ui->tableWidgetWyszukajUzytkownikaEdycja->setColumnWidth(2,110);
    ui->tableWidgetWyszukajUzytkownikaEdycja->setColumnWidth(3,120);
    ui->tableWidgetWyszukajUzytkownikaEdycja->setColumnWidth(4,120);
    ui->tableWidgetWyszukajUzytkownikaEdycja->setColumnWidth(5,80);
    ui->tableWidgetStatystyka->setStyleSheet("QWidget::pane > QWidget { background-color: #C3C3AE; }");

}

Wypozyczalnia::~Wypozyczalnia()
{
    delete bd;
    delete ui;
}

void Wypozyczalnia::on_pushButtonDodajUzytkownika_clicked()
{
    QString login, haslo, imie, nazwisko, telefon;
    login = ui->lineEditLogin->text();
    haslo = ui->lineEditHaslo->text();
    imie = ui->lineEditImieUzytkownika->text();
    nazwisko = ui->lineEditNazwiskoUzytkownika->text();
    telefon = ui->lineEditTelefonUzytkownika->text();
    regex.setPattern("^[a-zA-Z1-9]+$");
    match = regex.match(login);


    if(login == "" || haslo == "" || imie == "" || nazwisko == "")
        ui->komunikatyDodajUzytkownika->setText("Proszę uzupełnić wszystkie pola forlmularza.");
    else
    {
        if (!match.hasMatch())
            ui->komunikatyDodajUzytkownika->setText("Login zawiera niedozwolone znaki.");
        else
        {
            if (bd->dodajUzytkownika(login, haslo, imie, nazwisko, telefon))
            {
                ui->komunikatyDodajUzytkownika->setText("Dodano nowego użytkownika do bazy danych.");
                ui->lineEditLogin->clear();
                ui->lineEditHaslo->clear();
                ui->lineEditImieUzytkownika->clear();
                ui->lineEditNazwiskoUzytkownika->clear();
                ui->lineEditTelefonUzytkownika->clear();
            }
            else
                ui->komunikatyDodajUzytkownika->setText("Błąd: nie udało się dodać użytkownika do bazy danych.");
        }
    }
}

void Wypozyczalnia::on_pushButtonDodajKlienta_clicked()
{
    QString imie, nazwisko, kodPocztowy, miasto, ulica, nrDomu, nrlokalu, email, telefon;
    imie = ui->lineEditImieKlienta->text();
    nazwisko = ui->lineEditNazwiskoKlienta->text();
    kodPocztowy = ui->lineEditKodPocztowy->text();
    miasto = ui->lineEditMiasto->text();
    ulica = ui->lineEditUlica->text();
    nrDomu = ui->lineEditNrDomu->text();
    nrlokalu = ui->lineEditNrLokalu->text();
    email = ui->lineEditEmail->text();
    telefon = ui->lineEditTelefon->text();
    if(imie == "" || nazwisko == "" || miasto == "" || ulica == "" || nrDomu == "")
        ui->komunikatyDodajKlienta->setText("Proszę uzupełnić wymagane pola forlmularza.");
    else
    {
        if (bd->dodajKlienta(imie, nazwisko, kodPocztowy, miasto, ulica, nrDomu, nrlokalu, email, telefon))
        {
            ui->komunikatyDodajKlienta->setText("Dodano nowego klienta do bazy danych.");
            ui->lineEditImieKlienta->clear();
            ui->lineEditNazwiskoKlienta->clear();
            ui->lineEditKodPocztowy->clear();
            ui->lineEditMiasto->clear();
            ui->lineEditUlica->clear();
            ui->lineEditNrDomu->clear();
            ui->lineEditNrLokalu->clear();
            ui->lineEditEmail->clear();
            ui->lineEditTelefon->clear();
        }
        else
            ui->komunikatyDodajKlienta->setText("Błąd: nie udało się dodać klienta do bazy danych.");
    }
}

void Wypozyczalnia::on_pushButtonDodajFilm_clicked()
{
    QString tytul, opis;
    int rok, ilosckopii, gatunek1, gatunek2, gatunek3;
    double cenaWypozyczenia;
    tytul = ui->lineEditTytul->text();
    rok = ui->lineEditRok->text().toInt();
    opis = ui->plainTextEditOpis->toPlainText();
    cenaWypozyczenia = ui->lineEditCenaWypozyczenia->text().toDouble();
    ilosckopii = ui->spinBoxIleKopii->text().toInt();
    gatunek1 = ui->comboBoxGatunek1->itemData(ui->comboBoxGatunek1->currentIndex()).toInt();
    gatunek2 = ui->comboBoxGatunek2->itemData(ui->comboBoxGatunek2->currentIndex()).toInt();
    gatunek3 = ui->comboBoxGatunek3->itemData(ui->comboBoxGatunek3->currentIndex()).toInt();
    if (tytul == "" || opis == "" || cenaWypozyczenia == 0.00 || rok == 0 || ilosckopii == 0 || gatunek1 == 0)
        ui->komunikatyDodajFilm->setText("Proszę uzupełnić wymagane pola forlmularza.");
    else {
        if (bd->dodajFilm(tytul, rok, opis, cenaWypozyczenia, ilosckopii, gatunek1, gatunek2, gatunek3))
        {
            ui->komunikatyDodajFilm->setText("Dodano nowy film do bazy danych.");
            ui->lineEditTytul->clear();
            ui->lineEditRok->clear();
            ui->plainTextEditOpis->clear();
            ui->lineEditCenaWypozyczenia->clear();
            ui->spinBoxIleKopii->setValue(1);
            ui->comboBoxGatunek1->setCurrentIndex(0);
            ui->comboBoxGatunek2->setCurrentIndex(0);
            ui->comboBoxGatunek3->setCurrentIndex(0);
        }
        else
            ui->komunikatyDodajFilm->setText("Błąd: nie udało się dodać filmu do bazy danych.");
    }
}

void Wypozyczalnia::on_pushButtonWyszukajRokGatunek_clicked()
{
    int rok, gatunek;
    rok = ui->lineEditRokWyszukaj->text().toInt();
    gatunek = ui->comboBoxGatunekWyszukaj->itemData(ui->comboBoxGatunekWyszukaj->currentIndex()).toInt();
    listaBoxWypozyczenieFilmy.clear();
    listaBoxRezerwacjaFilmy.clear();
    bd->wyszukajFilmRokGatunek(rok, gatunek);
    ui->tableWidgetWyszukajFilm->setRowCount(bd->getListaFilmy().size());
    for(int i=0; i<bd->getListaFilmy().size(); i++)
    {
        ui->tableWidgetWyszukajFilm->setItem(i,0, new QTableWidgetItem(QString("%1").arg(bd->getListaFilmy().at(i)->getIdFilmu())));
        ui->tableWidgetWyszukajFilm->item(i, 0)->setFlags(Qt::ItemIsEditable);
        ui->tableWidgetWyszukajFilm->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetWyszukajFilm->setItem(i,1, new QTableWidgetItem(bd->getListaFilmy().at(i)->getTytul()));
        ui->tableWidgetWyszukajFilm->setItem(i,2, new QTableWidgetItem(QString("%1").arg(bd->getListaFilmy().at(i)->getRokProdukcji())));
        ui->tableWidgetWyszukajFilm->setItem(i,3, new QTableWidgetItem(bd->getListaFilmy().at(i)->getNazwaGatunku()));
        ui->tableWidgetWyszukajFilm->setItem(i,4, new QTableWidgetItem(bd->getListaFilmy().at(i)->getOpis()));
        ui->tableWidgetWyszukajFilm->setItem(i,5, new QTableWidgetItem(QString("%1").arg(bd->getListaFilmy().at(i)->getCenaWypozyczenia())));
        boxWypozyczenie = new QCheckBox();
        boxWypozyczenie->setStyleSheet("margin-left:40%; margin-right:60%;");
        listaBoxWypozyczenieFilmy.append(boxWypozyczenie);
        ui->tableWidgetWyszukajFilm->setCellWidget(i,6, listaBoxWypozyczenieFilmy.value(i));
        boxRezerwacja = new QCheckBox();
        boxRezerwacja->setStyleSheet("margin-left:40%; margin-right:60%;");
        listaBoxRezerwacjaFilmy.append(boxRezerwacja);
        ui->tableWidgetWyszukajFilm->setCellWidget(i,7, listaBoxRezerwacjaFilmy.value(i));
    }
}

void Wypozyczalnia::on_pushButtonWyszukajTytulOpis_clicked()
{
    QString tytul, opis;
    tytul = ui->lineEditTytulWyszukaj->text();
    opis = ui->lineEditOpisWyszukaj->text();
    listaBoxWypozyczenieFilmy.clear();
    listaBoxRezerwacjaFilmy.clear();
    bd->wyszukajFilmTytulOpis(tytul, opis);
    ui->tableWidgetWyszukajFilm->setRowCount(bd->getListaFilmy().size());
    for(int i=0; i<bd->getListaFilmy().size(); i++)
    {
        ui->tableWidgetWyszukajFilm->setItem(i,0, new QTableWidgetItem(QString("%1").arg(bd->getListaFilmy().at(i)->getIdFilmu())));
        ui->tableWidgetWyszukajFilm->item(i, 0)->setFlags(Qt::ItemIsEditable);
        ui->tableWidgetWyszukajFilm->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetWyszukajFilm->setItem(i,1, new QTableWidgetItem(bd->getListaFilmy().at(i)->getTytul()));
        ui->tableWidgetWyszukajFilm->setItem(i,2, new QTableWidgetItem(QString("%1").arg(bd->getListaFilmy().at(i)->getRokProdukcji())));
        ui->tableWidgetWyszukajFilm->setItem(i,3, new QTableWidgetItem(bd->getListaFilmy().at(i)->getNazwaGatunku()));
        ui->tableWidgetWyszukajFilm->setItem(i,4, new QTableWidgetItem(bd->getListaFilmy().at(i)->getOpis()));
        ui->tableWidgetWyszukajFilm->setItem(i,5, new QTableWidgetItem(QString("%1").arg(bd->getListaFilmy().at(i)->getCenaWypozyczenia())));
        boxWypozyczenie = new QCheckBox();
        boxWypozyczenie->setStyleSheet("margin-left:40%; margin-right:60%;");
        listaBoxWypozyczenieFilmy.append(boxWypozyczenie);
        ui->tableWidgetWyszukajFilm->setCellWidget(i,6, listaBoxWypozyczenieFilmy.value(i));
        boxRezerwacja = new QCheckBox();
        boxRezerwacja->setStyleSheet("margin-left:40%; margin-right:60%;");
        listaBoxRezerwacjaFilmy.append(boxRezerwacja);
        ui->tableWidgetWyszukajFilm->setCellWidget(i,7, listaBoxRezerwacjaFilmy.value(i));
    }
}

void Wypozyczalnia::on_pushButtonWyszukajKlienta_clicked()
{
    QString imie, nazwisko, miasto, ulica;
    imie = ui->lineEditImieWyszukaj->text();
    nazwisko = ui->lineEditNazwiskoWyszukaj->text();
    miasto = ui->lineEditMiastoWyszukaj->text();
    ulica = ui->lineEditUlicaWyszukaj->text();
    listaBoxWypozyczenieKlienci.clear();
    listaBoxRezerwacjaKlienci.clear();
    bd->wyszukajKlienta(imie, nazwisko, miasto, ulica);
    ui->tableWidgetWyszukajKlienta->setRowCount(bd->getListaKlienci().size());
    for(int i=0; i<bd->getListaKlienci().size(); i++)
    {
        ui->tableWidgetWyszukajKlienta->setItem(i,0, new QTableWidgetItem(QString("%1").arg(bd->getListaKlienci().at(i)->getIdKlienta())));
        ui->tableWidgetWyszukajKlienta->item(i, 0)->setFlags(Qt::ItemIsEditable);
        ui->tableWidgetWyszukajKlienta->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetWyszukajKlienta->setItem(i,1, new QTableWidgetItem(bd->getListaKlienci().at(i)->getImie()));
        ui->tableWidgetWyszukajKlienta->setItem(i,2, new QTableWidgetItem(bd->getListaKlienci().at(i)->getNazwisko()));
        ui->tableWidgetWyszukajKlienta->setItem(i,3, new QTableWidgetItem(bd->getListaKlienci().at(i)->getMiasto()));
        ui->tableWidgetWyszukajKlienta->setItem(i,4, new QTableWidgetItem(bd->getListaKlienci().at(i)->getUlica()));
        ui->tableWidgetWyszukajKlienta->setItem(i,5, new QTableWidgetItem(bd->getListaKlienci().at(i)->getNrDomu()));
        boxWypozyczenie = new QCheckBox();
        boxWypozyczenie->setStyleSheet("margin-left:40%; margin-right:60%;");
        listaBoxWypozyczenieKlienci.append(boxWypozyczenie);
        ui->tableWidgetWyszukajKlienta->setCellWidget(i, 6, listaBoxWypozyczenieKlienci.value(i));
        boxRezerwacja = new QCheckBox();
        boxRezerwacja->setStyleSheet("margin-left:40%; margin-right:60%;");
        listaBoxRezerwacjaKlienci.append(boxRezerwacja);
        ui->tableWidgetWyszukajKlienta->setCellWidget(i, 7, listaBoxRezerwacjaKlienci.value(i));
    }
}

void Wypozyczalnia::on_pushButtonRezerwacja_clicked()
{
    // sprawdzenie czy zaznaczono film oraz czy zaznaczonych filmów jest więcej niż jeden
    int ileFilmow = 0;
    for(int i=0; i<bd->getListaFilmy().size(); i++)
    {
        if (listaBoxRezerwacjaFilmy.value(i)->isChecked())
            ileFilmow++;
    }
    if (ileFilmow != 1)
        jedenFilmRezerwuj.exec();

    // sprawdzenie czy zaznaczono klienta oraz czy zaznaczonych klientow jest więcej niż jeden
    int ileKlientow = 0;
    for(int i=0; i<bd->getListaKlienci().size(); i++)
    {
        if (listaBoxRezerwacjaKlienci.value(i)->isChecked())
            ileKlientow++;
    }
    if (ileKlientow != 1)
        jedenKlientRezerwuj.exec();

    if (ileFilmow == 1 && ileKlientow == 1)
    {
        int wybraneIdFilmu = 0;
        int wybraneIdKlienta = 0;
        QDateTime terminRezerwacji;
        for(int i=0; i<bd->getListaFilmy().size(); i++)
        {
            if (listaBoxRezerwacjaFilmy.value(i)->isChecked())
                wybraneIdFilmu = ui->tableWidgetWyszukajFilm->item(i, 0)->text().toInt();
        }
        for(int i=0; i<bd->getListaKlienci().size(); i++)
        {
            if (listaBoxRezerwacjaKlienci.value(i)->isChecked())
                wybraneIdKlienta = ui->tableWidgetWyszukajKlienta->item(i, 0)->text().toInt();
        }
        if (bd->czyMozliwaRezerwacjaWypozyczenie(wybraneIdFilmu))
        {
            terminRezerwacji = ui->dateTimeEditTerminRezerwacji->dateTime();
            if (bd->wykonajRezerwacje(wybraneIdKlienta, wybraneIdFilmu, terminRezerwacji))
                ui->komunikatyWypozycz->setText("Dokonano rezerwacji wybranego filmu.");
            else
                ui->komunikatyWypozycz->setText("Błąd! Nie udało się dokonać rezerwacji wybranego filmu.");
        }
        else
            ui->komunikatyWypozycz->setText("Rezerwacja niemożliwa. Wszystkie posiadane kopie filmu są wypożyczone lub zarezerwowane.");
    }
}

void Wypozyczalnia::on_pushButtonWypozyczenie_clicked()
{
    // sprawdzenie czy zaznaczono film oraz czy zaznaczonych filmów jest więcej niż jeden
    int ileFilmow = 0;
    for(int i=0; i<bd->getListaFilmy().size(); i++)
    {
        if (listaBoxWypozyczenieFilmy.value(i)->isChecked())
            ileFilmow++;
    }
    if (ileFilmow != 1)
        jedenFilmWypozycz.exec();

    // sprawdzenie czy zaznaczono klienta oraz czy zaznaczonych klientow jest więcej niż jeden
    int ileKlientow = 0;
    for(int i=0; i<bd->getListaKlienci().size(); i++)
    {
        if (listaBoxWypozyczenieKlienci.value(i)->isChecked())
            ileKlientow++;
    }
    if (ileKlientow != 1)
        jedenKlientWypozycz.exec();

    if (ileFilmow == 1 && ileKlientow == 1)
    {
        int wybraneIdFilmu = 0;
        int wybraneIdKlienta = 0;
        QDateTime planowaDataZwrotu;
        for(int i=0; i<bd->getListaFilmy().size(); i++)
        {
            if (listaBoxWypozyczenieFilmy.value(i)->isChecked())
                wybraneIdFilmu = ui->tableWidgetWyszukajFilm->item(i, 0)->text().toInt();
        }
        for(int i=0; i<bd->getListaKlienci().size(); i++)
        {
            if (listaBoxWypozyczenieKlienci.value(i)->isChecked())
                wybraneIdKlienta = ui->tableWidgetWyszukajKlienta->item(i, 0)->text().toInt();
        }
        if (bd->czyMozliwaRezerwacjaWypozyczenie(wybraneIdFilmu))
        {
            planowaDataZwrotu = ui->dateTimeEditTerminZwrotu->dateTime();
            if (bd->wykonajWypozyczenie(wybraneIdKlienta, wybraneIdFilmu, planowaDataZwrotu))
                ui->komunikatyWypozycz->setText("Dokonano wypożyczenia wybranego filmu.");
            else
                ui->komunikatyWypozycz->setText("Błąd! Nie udało się dokonać wypożyczenia wybranego filmu.");
        }
        else
            ui->komunikatyWypozycz->setText("Wypożyczenie niemożliwe. Wszystkie posiadane kopie filmu są wypożyczone lub zarezerwowane.");
    }
}

void Wypozyczalnia::on_pushButtonWyszukajWypozyczoneKlientFilm_clicked()
{
    ui->komunikatyZwrotOdwolanie->clear();
    ui->lineEditNazwiskoWyszukajZwrot->clear();
    int idFilmu, idKlienta;
    idFilmu = ui->lineEditIdFilmuWyszukajZwrot->text().toInt();
    idKlienta = ui->lineEditIdKlientaWyszukajZwrot->text().toInt();
    listaBoxWypozyczenie.clear();
    bd->wyszukajWypozyczoneFilmyIdFilmuIdKlienta(idFilmu, idKlienta);
    ui->tableWidgetWyszukajWypozyczone->setRowCount(bd->getListaWypozyczenia().size());
    for(int i=0; i<bd->getListaWypozyczenia().size(); i++)
    {
        ui->tableWidgetWyszukajWypozyczone->setItem(i,0, new QTableWidgetItem(QString("%1").arg(bd->getListaWypozyczenia().at(i)->getIdWypozyczenia())));
        ui->tableWidgetWyszukajWypozyczone->item(i, 0)->setFlags(Qt::ItemIsEditable);
        ui->tableWidgetWyszukajWypozyczone->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetWyszukajWypozyczone->setItem(i,1, new QTableWidgetItem(QString("%1").arg(bd->getListaWypozyczenia().at(i)->getIdFilmu())));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,2, new QTableWidgetItem(bd->getListaWypozyczenia().at(i)->getTytul()));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,3, new QTableWidgetItem(QString("%1").arg(bd->getListaWypozyczenia().at(i)->getCenaWypozyczenia())));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,4, new QTableWidgetItem(QString("%1").arg(bd->getListaWypozyczenia().at(i)->getIdKlienta())));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,5, new QTableWidgetItem(bd->getListaWypozyczenia().at(i)->getImie()));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,6, new QTableWidgetItem(bd->getListaWypozyczenia().at(i)->getNazwisko()));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,7, new QTableWidgetItem(bd->getListaWypozyczenia().at(i)->getDataWypozyczenia().toString("yyyy-MM-dd hh:mm")));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,8, new QTableWidgetItem(bd->getListaWypozyczenia().at(i)->getPlanowaDataZwrotu().toString("yyyy-MM-dd hh:mm")));
        if (QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm") > ui->tableWidgetWyszukajWypozyczone->item(i,8)->text())
            ui->tableWidgetWyszukajWypozyczone->item(i,8)->setBackgroundColor(Qt::red);
        boxWypozyczenie = new QCheckBox();
        boxWypozyczenie->setStyleSheet("margin-left:25%;");
        listaBoxWypozyczenie.append(boxWypozyczenie);
        ui->tableWidgetWyszukajWypozyczone->setCellWidget(i,9, listaBoxWypozyczenie.value(i));
    }
    ui->lineEditIdFilmuWyszukajZwrot->clear();
    ui->lineEditIdKlientaWyszukajZwrot->clear();
}

void Wypozyczalnia::on_lineEditNazwiskoWyszukajZwrot_textChanged(const QString &nazwisko)
{
    ui->komunikatyZwrotOdwolanie->clear();
    listaBoxWypozyczenie.clear();
    bd->wyszukajWypozyczoneFilmyNazwisko(nazwisko);
    ui->tableWidgetWyszukajWypozyczone->setRowCount(bd->getListaWypozyczenia().size());
    for(int i=0; i<bd->getListaWypozyczenia().size(); i++)
    {
        ui->tableWidgetWyszukajWypozyczone->setItem(i,0, new QTableWidgetItem(QString("%1").arg(bd->getListaWypozyczenia().at(i)->getIdWypozyczenia())));
        ui->tableWidgetWyszukajWypozyczone->item(i, 0)->setFlags(Qt::ItemIsEditable);
        ui->tableWidgetWyszukajWypozyczone->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetWyszukajWypozyczone->setItem(i,1, new QTableWidgetItem(QString("%1").arg(bd->getListaWypozyczenia().at(i)->getIdFilmu())));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,2, new QTableWidgetItem(bd->getListaWypozyczenia().at(i)->getTytul()));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,3, new QTableWidgetItem(QString("%1").arg(bd->getListaWypozyczenia().at(i)->getCenaWypozyczenia())));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,4, new QTableWidgetItem(QString("%1").arg(bd->getListaWypozyczenia().at(i)->getIdKlienta())));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,5, new QTableWidgetItem(bd->getListaWypozyczenia().at(i)->getImie()));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,6, new QTableWidgetItem(bd->getListaWypozyczenia().at(i)->getNazwisko()));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,7, new QTableWidgetItem(bd->getListaWypozyczenia().at(i)->getDataWypozyczenia().toString("yyyy-MM-dd hh:mm")));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,8, new QTableWidgetItem(bd->getListaWypozyczenia().at(i)->getPlanowaDataZwrotu().toString("yyyy-MM-dd hh:mm")));
        if (QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm") > ui->tableWidgetWyszukajWypozyczone->item(i,8)->text())
            ui->tableWidgetWyszukajWypozyczone->item(i,8)->setBackgroundColor(Qt::red);
        boxWypozyczenie = new QCheckBox();
        boxWypozyczenie->setStyleSheet("margin-left:25%");
        listaBoxWypozyczenie.append(boxWypozyczenie);
        ui->tableWidgetWyszukajWypozyczone->setCellWidget(i,9, listaBoxWypozyczenie.value(i));
    }
}

void Wypozyczalnia::on_pushButtonZwrot_clicked()
{
    // sprawdzenie czy zaznaczono film oraz czy zaznaczonych filmów jest więcej niż jeden
    int ileFilmow = 0;
    for(int i=0; i<bd->getListaWypozyczenia().size(); i++)
    {
        if (listaBoxWypozyczenie.value(i)->isChecked())
            ileFilmow++;
    }
    if (ileFilmow != 1)
        jedenFilmZwrot.exec();
    //wykonanie zwrotu wybranego filmu wg idWypozyczenia
    if (ileFilmow == 1)
    {
        int wybraneIdWypozyczenia = 0;
        for(int i=0; i<bd->getListaWypozyczenia().size(); i++)
        {
            if (listaBoxWypozyczenie.value(i)->isChecked())
                wybraneIdWypozyczenia = ui->tableWidgetWyszukajWypozyczone->item(i, 0)->text().toInt();
        }

        if (bd->wykonajZwrotFilmu(wybraneIdWypozyczenia))
            ui->komunikatyZwrotOdwolanie->setText("Dokonano zwrotu wybranego filmu.");
        else
            ui->komunikatyZwrotOdwolanie->setText("Błąd! Nie udało się dokonać zwrotu wybranego filmu.");
    }
}

void Wypozyczalnia::on_pushButtonWyszukajZarezerwowaneKlientFilm_clicked()
{
    ui->komunikatyZwrotOdwolanie->clear();
    ui->lineEditNazwiskoWyszukajZarezerwowane->clear();
    int idFilmu, idKlienta;
    idFilmu = ui->lineEditIdFilmuWyszukajZarezerwowane->text().toInt();
    idKlienta = ui->lineEditIdKlientaWyszukajZarezerwowane->text().toInt();
    listaBoxRezerwacja.clear();
    bd->wyszukajRezerwacjeFilmyIdFilmuIdKlienta(idFilmu, idKlienta);
    ui->tableWidgetWyszukajZarezerwowane->setRowCount(bd->getListaRezerwacje().size());
    for(int i=0; i<bd->getListaRezerwacje().size(); i++)
    {
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,0, new QTableWidgetItem(QString("%1").arg(bd->getListaRezerwacje().at(i)->getIdRezerwacji())));
        ui->tableWidgetWyszukajZarezerwowane->item(i, 0)->setFlags(Qt::ItemIsEditable);
        ui->tableWidgetWyszukajZarezerwowane->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,1, new QTableWidgetItem(QString("%1").arg(bd->getListaRezerwacje().at(i)->getIdFilmu())));
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,2, new QTableWidgetItem(bd->getListaRezerwacje().at(i)->getTytul()));
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,3, new QTableWidgetItem(QString("%1").arg(bd->getListaRezerwacje().at(i)->getCenaWypozyczenia())));
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,4, new QTableWidgetItem(QString("%1").arg(bd->getListaRezerwacje().at(i)->getIdKlienta())));
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,5, new QTableWidgetItem(bd->getListaRezerwacje().at(i)->getImie()));
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,6, new QTableWidgetItem(bd->getListaRezerwacje().at(i)->getNazwisko()));
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,7, new QTableWidgetItem(bd->getListaRezerwacje().at(i)->getDataRezerwacji().toString("yyyy-MM-dd hh:mm")));
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,8, new QTableWidgetItem(bd->getListaRezerwacje().at(i)->getTerminRezerwacji().toString("yyyy-MM-dd hh:mm")));
        if (QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm") > ui->tableWidgetWyszukajZarezerwowane->item(i,8)->text())
            ui->tableWidgetWyszukajZarezerwowane->item(i,8)->setBackgroundColor(Qt::red);
        boxRezerwacja = new QCheckBox();
        boxRezerwacja->setStyleSheet("margin-left:35%;");
        listaBoxRezerwacja.append(boxRezerwacja);
        ui->tableWidgetWyszukajZarezerwowane->setCellWidget(i,9, listaBoxRezerwacja.value(i));
    }
    ui->lineEditIdFilmuWyszukajZarezerwowane->clear();
    ui->lineEditIdKlientaWyszukajZarezerwowane->clear();
}

void Wypozyczalnia::on_lineEditNazwiskoWyszukajZarezerwowane_textChanged(const QString &nazwisko)
{
    ui->komunikatyZwrotOdwolanie->clear();
    listaBoxRezerwacja.clear();
    bd->wyszukajRezerwacjeFilmyNazwisko(nazwisko);
    ui->tableWidgetWyszukajZarezerwowane->setRowCount(bd->getListaRezerwacje().size());
    for(int i=0; i<bd->getListaRezerwacje().size(); i++)
    {
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,0, new QTableWidgetItem(QString("%1").arg(bd->getListaRezerwacje().at(i)->getIdRezerwacji())));
        ui->tableWidgetWyszukajZarezerwowane->item(i, 0)->setFlags(Qt::ItemIsEditable);
        ui->tableWidgetWyszukajZarezerwowane->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,1, new QTableWidgetItem(QString("%1").arg(bd->getListaRezerwacje().at(i)->getIdFilmu())));
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,2, new QTableWidgetItem(bd->getListaRezerwacje().at(i)->getTytul()));
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,3, new QTableWidgetItem(QString("%1").arg(bd->getListaRezerwacje().at(i)->getCenaWypozyczenia())));
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,4, new QTableWidgetItem(QString("%1").arg(bd->getListaRezerwacje().at(i)->getIdKlienta())));
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,5, new QTableWidgetItem(bd->getListaRezerwacje().at(i)->getImie()));
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,6, new QTableWidgetItem(bd->getListaRezerwacje().at(i)->getNazwisko()));
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,7, new QTableWidgetItem(bd->getListaRezerwacje().at(i)->getDataRezerwacji().toString("yyyy-MM-dd hh:mm")));
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,8, new QTableWidgetItem(bd->getListaRezerwacje().at(i)->getTerminRezerwacji().toString("yyyy-MM-dd hh:mm")));
        if (QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm") > ui->tableWidgetWyszukajZarezerwowane->item(i,8)->text())
            ui->tableWidgetWyszukajZarezerwowane->item(i,8)->setBackgroundColor(Qt::red);
        boxRezerwacja = new QCheckBox();
        boxRezerwacja->setStyleSheet("margin-left:35%;");
        listaBoxRezerwacja.append(boxRezerwacja);
        ui->tableWidgetWyszukajZarezerwowane->setCellWidget(i,9, listaBoxRezerwacja.value(i));
    }
}

void Wypozyczalnia::on_pushButtonOdwolanie_clicked()
{
    // sprawdzenie czy zaznaczono film oraz czy zaznaczonych filmów jest więcej niż jeden
    int ileFilmow = 0;
    for(int i=0; i<bd->getListaRezerwacje().size(); i++)
    {
        if (listaBoxRezerwacja.value(i)->isChecked())
            ileFilmow++;
    }
    if (ileFilmow != 1)
        jedenFilmOdwolaj.exec();
    //wykonanie zwrotu wybranego filmu wg idWypozyczenia
    if (ileFilmow == 1)
    {
        int wybraneIdRezerwacji = 0;
        for(int i=0; i<bd->getListaRezerwacje().size(); i++)
        {
            if (listaBoxRezerwacja.value(i)->isChecked())
                wybraneIdRezerwacji = ui->tableWidgetWyszukajZarezerwowane->item(i, 0)->text().toInt();
        }

        if (bd->wykonajOdwolanieRezerwacji(wybraneIdRezerwacji))
            ui->komunikatyZwrotOdwolanie->setText("Dokonano odwołania rezerwacji wybranego filmu.");
        else
            ui->komunikatyZwrotOdwolanie->setText("Błąd! Nie udało się dokonać odwołania rezerwacji wybranego filmu.");
    }
}


void Wypozyczalnia::on_lineEditNazwiskoWyszukajEdytuj_textChanged(const QString &nazwisko)
{
    ui->komunikatyDodajKlienta->clear();
    bd->wyszukajKlienta(nazwisko);
    ui->tableWidgetWyszukajKlientaEdycja->setRowCount(bd->getListaKlienciEdycja().size());
    for(int i=0; i<bd->getListaKlienciEdycja().size(); i++)
    {
        ui->tableWidgetWyszukajKlientaEdycja->setItem(i,0, new QTableWidgetItem(QString("%1").arg(bd->getListaKlienciEdycja().at(i)->getIdKlienta())));
        ui->tableWidgetWyszukajKlientaEdycja->item(i, 0)->setFlags(Qt::ItemIsEditable);
        ui->tableWidgetWyszukajKlientaEdycja->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetWyszukajKlientaEdycja->setItem(i,1, new QTableWidgetItem(bd->getListaKlienciEdycja().at(i)->getImie()));
        ui->tableWidgetWyszukajKlientaEdycja->setItem(i,2, new QTableWidgetItem(bd->getListaKlienciEdycja().at(i)->getNazwisko()));
        ui->tableWidgetWyszukajKlientaEdycja->setItem(i,3, new QTableWidgetItem(bd->getListaKlienciEdycja().at(i)->getKod()));
        ui->tableWidgetWyszukajKlientaEdycja->setItem(i,4, new QTableWidgetItem(bd->getListaKlienciEdycja().at(i)->getMiasto()));
        ui->tableWidgetWyszukajKlientaEdycja->setItem(i,5, new QTableWidgetItem(bd->getListaKlienciEdycja().at(i)->getUlica()));
        ui->tableWidgetWyszukajKlientaEdycja->setItem(i,6, new QTableWidgetItem(bd->getListaKlienciEdycja().at(i)->getNrDomu()));
        ui->tableWidgetWyszukajKlientaEdycja->setItem(i,7, new QTableWidgetItem(bd->getListaKlienciEdycja().at(i)->getNrLokalu()));
        ui->tableWidgetWyszukajKlientaEdycja->setItem(i,8, new QTableWidgetItem(bd->getListaKlienciEdycja().at(i)->getEmail()));
        ui->tableWidgetWyszukajKlientaEdycja->setItem(i,9, new QTableWidgetItem(bd->getListaKlienciEdycja().at(i)->getTelefon()));
        boxKlienci = new QCheckBox();
        boxKlienci->setStyleSheet("margin-left:25%;");
        ui->tableWidgetWyszukajKlientaEdycja->setCellWidget(i,10, boxKlienci);
    }
}

void Wypozyczalnia::on_pushButtonEdytujKlienta_clicked()
{
    int wierszeTabeli = ui->tableWidgetWyszukajKlientaEdycja->rowCount();
    if (wierszeTabeli > 0)
    {
        // sprawdzenie czy zaznaczono klienta oraz czy zaznaczonych klientów jest więcej niż jeden
        int iluKlientow = 0;
        for(int i=0; i<bd->getListaKlienciEdycja().size(); i++)
        {
            boxKlienci = (QCheckBox *)ui->tableWidgetWyszukajKlientaEdycja->cellWidget(i, 10);
            if (boxKlienci->isChecked())
                iluKlientow++;
        }
        if (iluKlientow != 1)
            jedenKlientEdytuj.exec();
        //wykonanie edycji wybranego klienta wg idKlienta
        if (iluKlientow == 1)
        {
            int wybraneIdKlienta = 0;
            QString imie, nazwisko, kod, miasto, ulica, nrDomu, nrLokalu, email, telefon;
            for(int i=0; i<bd->getListaKlienciEdycja().size(); i++)
            {
                boxKlienci = (QCheckBox *)ui->tableWidgetWyszukajKlientaEdycja->cellWidget(i, 10);
                if (boxKlienci->isChecked())
                {
                    wybraneIdKlienta = ui->tableWidgetWyszukajKlientaEdycja->item(i, 0)->text().toInt();
                    imie = ui->tableWidgetWyszukajKlientaEdycja->item(i, 1)->text();
                    nazwisko = ui->tableWidgetWyszukajKlientaEdycja->item(i, 2)->text();
                    kod = ui->tableWidgetWyszukajKlientaEdycja->item(i, 3)->text();
                    miasto = ui->tableWidgetWyszukajKlientaEdycja->item(i, 4)->text();
                    ulica = ui->tableWidgetWyszukajKlientaEdycja->item(i, 5)->text();
                    nrDomu = ui->tableWidgetWyszukajKlientaEdycja->item(i, 6)->text();
                    nrLokalu = ui->tableWidgetWyszukajKlientaEdycja->item(i, 7)->text();
                    email = ui->tableWidgetWyszukajKlientaEdycja->item(i, 8)->text();
                    telefon = ui->tableWidgetWyszukajKlientaEdycja->item(i, 9)->text();
                    break;
                }
            }
            if (bd->wykonajEdycjeKlienta(wybraneIdKlienta, imie, nazwisko, kod, miasto, ulica, nrDomu, nrLokalu, email, telefon))
                ui->komunikatyDodajKlienta->setText("Dokonano edycji wybranego klienta.");
            else
                ui->komunikatyDodajKlienta->setText("Błąd! Nie udało się dokonać edycji wybranego klienta.");
        }
    }
    else
        ui->komunikatyDodajKlienta->setText("Proszę wyszukać klienta do edycji.");
}

void Wypozyczalnia::on_lineEditTytulWyszukajEdytuj_textChanged(const QString &tytul)
{
    ui->komunikatyDodajFilm->clear();
    bd->wyszukajFilm(tytul);
    ui->tableWidgetWyszukajFilmEdycja->setRowCount(bd->getListaFilmyEdycja().size());
    for(int i=0; i<bd->getListaFilmyEdycja().size(); i++)
    {
        ui->tableWidgetWyszukajFilmEdycja->setItem(i,0, new QTableWidgetItem(QString("%1").arg(bd->getListaFilmyEdycja().at(i)->getIdFilmu())));
        ui->tableWidgetWyszukajFilmEdycja->item(i, 0)->setFlags(Qt::ItemIsEditable);
        ui->tableWidgetWyszukajFilmEdycja->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetWyszukajFilmEdycja->setItem(i,1, new QTableWidgetItem(bd->getListaFilmyEdycja().at(i)->getTytul()));
        ui->tableWidgetWyszukajFilmEdycja->setItem(i,2, new QTableWidgetItem(QString("%1").arg(bd->getListaFilmyEdycja().at(i)->getRokProdukcji())));
        ui->tableWidgetWyszukajFilmEdycja->setItem(i,3, new QTableWidgetItem(bd->getListaFilmyEdycja().at(i)->getOpis()));
        ui->tableWidgetWyszukajFilmEdycja->setItem(i,4, new QTableWidgetItem(QString("%1").arg(bd->getListaFilmyEdycja().at(i)->getIloscKopii())));
        ui->tableWidgetWyszukajFilmEdycja->setItem(i,5, new QTableWidgetItem(QString("%1").arg(bd->getListaFilmyEdycja().at(i)->getCenaWypozyczenia())));
        comboGatunek1 = new QComboBox();
        for(int j=0; j<bd->getListaGatunkow().size(); j++)
            comboGatunek1->addItem(bd->getListaGatunkow().at(j)->getNazwa(), QVariant(bd->getListaGatunkow().at(j)->getIdGatunku()));
        comboGatunek1->setCurrentIndex(bd->getListaFilmyEdycja().at(i)->getGatunek1());
        ui->tableWidgetWyszukajFilmEdycja->setCellWidget(i, 6, comboGatunek1);
        comboGatunek2 = new QComboBox();
        for(int j=0; j<bd->getListaGatunkow().size(); j++)
            comboGatunek2->addItem(bd->getListaGatunkow().at(j)->getNazwa(), QVariant(bd->getListaGatunkow().at(j)->getIdGatunku()));
        comboGatunek2->setCurrentIndex(bd->getListaFilmyEdycja().at(i)->getGatunek2());
        ui->tableWidgetWyszukajFilmEdycja->setCellWidget(i, 7, comboGatunek2);
        comboGatunek3 = new QComboBox();
        for(int j=0; j<bd->getListaGatunkow().size(); j++)
            comboGatunek3->addItem(bd->getListaGatunkow().at(j)->getNazwa(), QVariant(bd->getListaGatunkow().at(j)->getIdGatunku()));
        comboGatunek3->setCurrentIndex(bd->getListaFilmyEdycja().at(i)->getGatunek3());
        ui->tableWidgetWyszukajFilmEdycja->setCellWidget(i, 8, comboGatunek3);
        boxFilmy = new QCheckBox();
        boxFilmy->setStyleSheet("margin-left:25%;");
        ui->tableWidgetWyszukajFilmEdycja->setCellWidget(i, 9, boxFilmy);
    }
}

void Wypozyczalnia::on_pushButtonEdytujFilm_clicked()
{
    int wierszeTabeli = ui->tableWidgetWyszukajFilmEdycja->rowCount();
    if (wierszeTabeli > 0)
    {
        // sprawdzenie czy zaznaczono film oraz czy zaznaczonych filmów jest więcej niż jeden
        int ileFilmow = 0;
        for(int i=0; i<bd->getListaFilmyEdycja().size(); i++)
        {
            boxFilmy = (QCheckBox *)ui->tableWidgetWyszukajFilmEdycja->cellWidget(i, 9);
            if (boxFilmy->isChecked())
                ileFilmow++;
        }
        if (ileFilmow != 1)
            jedenFilmEdytuj.exec();
        //wykonanie edycji wybranego klienta wg idKlienta
        if (ileFilmow == 1)
        {
            int wybraneIdFilmu = 0;
            int rokProdukcji, iloscKopii, gatunek1, gatunek2, gatunek3;
            double cenaWypozyczenia;
            QString tytul, opis;
            for(int i=0; i<bd->getListaFilmyEdycja().size(); i++)
            {
                boxFilmy = (QCheckBox *)ui->tableWidgetWyszukajFilmEdycja->cellWidget(i, 9);
                if (boxFilmy->isChecked())
                {
                    wybraneIdFilmu = ui->tableWidgetWyszukajFilmEdycja->item(i, 0)->text().toInt();
                    tytul = ui->tableWidgetWyszukajFilmEdycja->item(i, 1)->text();
                    rokProdukcji = ui->tableWidgetWyszukajFilmEdycja->item(i, 2)->text().toInt();
                    opis = ui->tableWidgetWyszukajFilmEdycja->item(i, 3)->text();
                    iloscKopii = ui->tableWidgetWyszukajFilmEdycja->item(i, 4)->text().toInt();
                    cenaWypozyczenia = ui->tableWidgetWyszukajFilmEdycja->item(i, 5)->text().toDouble();
                    comboGatunek1 = (QComboBox *)ui->tableWidgetWyszukajFilmEdycja->cellWidget(i, 6);
                    gatunek1 = comboGatunek1->itemData(comboGatunek1->currentIndex()).toInt();
                    comboGatunek2 = (QComboBox *)ui->tableWidgetWyszukajFilmEdycja->cellWidget(i, 7);
                    gatunek2 = comboGatunek2->itemData(comboGatunek2->currentIndex()).toInt();
                    comboGatunek3 = (QComboBox *)ui->tableWidgetWyszukajFilmEdycja->cellWidget(i, 8);
                    gatunek3 = comboGatunek3->itemData(comboGatunek3->currentIndex()).toInt();
                    break;
                }
            }
            if (bd->wykonajEdycjeFilmu(wybraneIdFilmu, tytul, rokProdukcji, opis, iloscKopii, cenaWypozyczenia, gatunek1, gatunek2, gatunek3))
                ui->komunikatyDodajFilm->setText("Dokonano edycji wybranego filmu.");
            else
                ui->komunikatyDodajFilm->setText("Błąd! Nie udało się dokonać edycji wybranego filmu.");
        }
    }
    else
        ui->komunikatyDodajFilm->setText("Proszę wyszukać film do edycji.");
}


void Wypozyczalnia::on_lineEditNazwiskolWyszukajEdytuj_textChanged(const QString &nazwisko)
{
    ui->komunikatyDodajUzytkownika->clear();
    bd->wyszukajUzytkownika(nazwisko);
    ui->tableWidgetWyszukajUzytkownikaEdycja->setRowCount(bd->getListaUzytkownicy().size());
    for(int i=0; i<bd->getListaUzytkownicy().size(); i++)
    {
        ui->tableWidgetWyszukajUzytkownikaEdycja->setItem(i,0, new QTableWidgetItem(QString("%1").arg(bd->getListaUzytkownicy().at(i)->getIdUzytkownika())));
        ui->tableWidgetWyszukajUzytkownikaEdycja->item(i, 0)->setFlags(Qt::ItemIsEditable);
        ui->tableWidgetWyszukajUzytkownikaEdycja->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetWyszukajUzytkownikaEdycja->setItem(i,1, new QTableWidgetItem(bd->getListaUzytkownicy().at(i)->getLogin()));
        ui->tableWidgetWyszukajUzytkownikaEdycja->setItem(i,2, new QTableWidgetItem(bd->getListaUzytkownicy().at(i)->getImie()));
        ui->tableWidgetWyszukajUzytkownikaEdycja->setItem(i,3, new QTableWidgetItem(bd->getListaUzytkownicy().at(i)->getNazwisko()));
        ui->tableWidgetWyszukajUzytkownikaEdycja->setItem(i,4, new QTableWidgetItem(bd->getListaUzytkownicy().at(i)->getTelefon()));
        boxUzytkownicy = new QCheckBox();
        boxUzytkownicy->setStyleSheet("margin-left:25%;");
        ui->tableWidgetWyszukajUzytkownikaEdycja->setCellWidget(i,5, boxUzytkownicy);
    }
}

void Wypozyczalnia::on_pushButtonEdytujUzytkownika_clicked()
{
    int wierszeTabeli = ui->tableWidgetWyszukajUzytkownikaEdycja->rowCount();
    if (wierszeTabeli > 0)
    {
        // sprawdzenie czy zaznaczono klienta oraz czy zaznaczonych klientów jest więcej niż jeden
        int iluUzytkownikow = 0;
        for(int i=0; i<bd->getListaUzytkownicy().size(); i++)
        {
            boxUzytkownicy = (QCheckBox *)ui->tableWidgetWyszukajUzytkownikaEdycja->cellWidget(i, 5);
            if (boxUzytkownicy->isChecked())
                iluUzytkownikow++;
        }
        if (iluUzytkownikow != 1)
            jedenUzytkownikEdytuj.exec();
        //wykonanie edycji wybranego klienta wg idKlienta
        if (iluUzytkownikow == 1)
        {
            int wybraneIdUzytkownika = 0;
            QString login, imie, nazwisko, telefon;
            for(int i=0; i<bd->getListaUzytkownicy().size(); i++)
            {
                boxUzytkownicy = (QCheckBox *)ui->tableWidgetWyszukajUzytkownikaEdycja->cellWidget(i, 5);
                if (boxUzytkownicy->isChecked())
                {
                    wybraneIdUzytkownika = ui->tableWidgetWyszukajUzytkownikaEdycja->item(i, 0)->text().toInt();
                    login = ui->tableWidgetWyszukajUzytkownikaEdycja->item(i, 1)->text();
                    imie = ui->tableWidgetWyszukajUzytkownikaEdycja->item(i, 2)->text();
                    nazwisko = ui->tableWidgetWyszukajUzytkownikaEdycja->item(i, 3)->text();
                    telefon = ui->tableWidgetWyszukajUzytkownikaEdycja->item(i, 4)->text();
                    break;
                }
            }
            if (bd->wykonajEdycjeUzytkownika(wybraneIdUzytkownika, login, imie, nazwisko, telefon))
                ui->komunikatyDodajUzytkownika->setText("Dokonano edycji wybranego użytkownika.");
            else
                ui->komunikatyDodajUzytkownika->setText("Błąd! Nie udało się dokonać edycji wybranego użytkownika.");
        }
    }
    else
        ui->komunikatyDodajUzytkownika->setText("Proszę wyszukać użytkownika do edycji.");
}

void Wypozyczalnia::on_pushButtonZmienHaslo_clicked()
{
    QString login, haslo, noweHaslo, powtorzHaslo;
    login = ui->lineEditZmianaHaslaLogin->text();
    haslo = ui->lineEditZmianaHaslaHaslo->text();
    noweHaslo = ui->lineEditZmianaHaslaNowe->text();
    powtorzHaslo = ui->lineEditZmianaHaslaPowtorz->text();
    int idUzytkownika;
    if (noweHaslo == powtorzHaslo)
    {
        if (bd->znajdzUzytkownika(login, haslo))
        {
            idUzytkownika = bd->znajdzUzytkownika(login, haslo);
            if (bd->wykonajZmianeHasla(idUzytkownika, noweHaslo))
                zmianaHaslaUzytkownik.exec();
        }
        else
            ui->komunikatyUstawienia->setText("Dotychczasowy login lub hasło są niepoprawne.");
    }
    else
        ui->komunikatyUstawienia->setText("Brak zgodności pomiędzy polem Nowe hasło i Powtórz hasło.");

}

void Wypozyczalnia::on_tabWidget_tabBarClicked(int index)
{
    if (index == 5)
    {
        bd->wyszukajGatunki();
        ui->tableWidgetGatunki->setRowCount(bd->getListaGatunkow().size());
        ui->tableWidgetGatunki->verticalHeader()->close();
        ui->tableWidgetGatunki->setColumnWidth(0, 35);
        ui->tableWidgetGatunki->setColumnWidth(1, 120);
        ui->tableWidgetGatunki->setStyleSheet("QWidget::pane > QWidget { background-color: #C3C3AE; }");
        for(int i=0; i<bd->getListaGatunkow().size(); i++)
        {
            ui->tableWidgetGatunki->setItem(i, 0, new QTableWidgetItem(QString("%1").arg(bd->getListaGatunkow().at(i)->getIdGatunku())));
            ui->tableWidgetGatunki->item(i, 0)->setFlags(Qt::ItemIsEditable);
            ui->tableWidgetGatunki->item(i, 0)->setTextAlignment(Qt::AlignCenter);
            ui->tableWidgetGatunki->setItem(i, 1, new QTableWidgetItem(bd->getListaGatunkow().at(i)->getNazwa()));
        }
        ui->tableWidgetGatunki->item(0, 1)->setFlags(Qt::ItemIsEditable);
    }
}

void Wypozyczalnia::on_pushButtonGatunekDodaj_clicked()
{
    QString nowyGatunek = ui->lineEditDodajGatunek->text();
    if (!nowyGatunek.isEmpty())
    {
        if (bd->dodajGatunek(nowyGatunek))
        {
            ui->komunikatyUstawienia->setText("Dodano nowy gatunek filmowy do bazy danych.");
            bd->wyszukajGatunki();
            ui->comboBoxGatunekWyszukaj->clear();
            ui->comboBoxGatunek1->clear();
            ui->comboBoxGatunek2->clear();
            ui->comboBoxGatunek3->clear();
            for(int i=0; i<bd->getListaGatunkow().size(); i++)
            {
                ui->comboBoxGatunekWyszukaj->addItem(bd->getListaGatunkow().at(i)->getNazwa(), QVariant(bd->getListaGatunkow().at(i)->getIdGatunku()));
                ui->comboBoxGatunek1->addItem(bd->getListaGatunkow().at(i)->getNazwa(), QVariant(bd->getListaGatunkow().at(i)->getIdGatunku()));
                ui->comboBoxGatunek2->addItem(bd->getListaGatunkow().at(i)->getNazwa(), QVariant(bd->getListaGatunkow().at(i)->getIdGatunku()));
                ui->comboBoxGatunek3->addItem(bd->getListaGatunkow().at(i)->getNazwa(), QVariant(bd->getListaGatunkow().at(i)->getIdGatunku()));
            }
        }
        else
            ui->komunikatyUstawienia->setText("Błąd. Nie udało się dodać nowego gatunku filmowego do bazy danych.");
    }
    else
        nowyGatunekPustePole.exec();
}

void Wypozyczalnia::on_pushButtonGatunkiEdytuj_clicked()
{
    QString nazwaGatunku;
    int idGatunku;
    for (int i=0; i<ui->tableWidgetGatunki->rowCount(); i++)
    {
        idGatunku = ui->tableWidgetGatunki->item(i, 0)->text().toInt();
        nazwaGatunku = ui->tableWidgetGatunki->item(i, 1)->text();
        bd->edytujGatunki(idGatunku, nazwaGatunku);
    }
    ui->komunikatyUstawienia->setText("Wykonano edycję gatunków.");
}

void Wypozyczalnia::on_pushButtonWyswietlPrzychod_clicked()
{
    QDateTime dataOd = ui->dateTimeEditStatystykaOd->dateTime();
    QDateTime dataDo = ui->dateTimeEditStatystykaDo->dateTime();
    ui->lineEditPrzychod->setText(QString("%1").arg(bd->obliczPrzychod(dataOd, dataDo)));
}

void Wypozyczalnia::on_pushButtonWyswietlFilmyNajWyp_clicked()
{
    QDateTime dataOd = ui->dateTimeEditStatystykaOd->dateTime();
    QDateTime dataDo = ui->dateTimeEditStatystykaDo->dateTime();
    bd->wyszukajNajczesciejWypozyczane(dataOd, dataDo);
    ui->tableWidgetStatystyka->setColumnCount(6);
    QStringList naglowek;
    naglowek.append("Wypożyczono");
    naglowek.append("Tytuł");
    naglowek.append("Rok prod.");
    naglowek.append("Gatunek");
    naglowek.append("Ilość kopii");
    naglowek.append("Cena wyp.");
    ui->tableWidgetStatystyka->setHorizontalHeaderLabels(naglowek);
    ui->tableWidgetStatystyka->horizontalHeader()->setFont(QFont("Arial",8));
    ui->tableWidgetStatystyka->verticalHeader()->close();
    ui->tableWidgetStatystyka->setColumnWidth(0, 100);
    ui->tableWidgetStatystyka->setColumnWidth(1, 200);
    ui->tableWidgetStatystyka->setColumnWidth(2, 70);
    ui->tableWidgetStatystyka->setColumnWidth(3, 100);
    ui->tableWidgetStatystyka->setColumnWidth(4, 90);
    ui->tableWidgetStatystyka->setColumnWidth(5, 90);
    ui->tableWidgetStatystyka->setRowCount(bd->getListaFilmyWypozyczenia().size());
    for(int i=0; i<bd->getListaFilmyWypozyczenia().size(); i++)
    {
        ui->tableWidgetStatystyka->setItem(i,0, new QTableWidgetItem(QString("%1").arg(bd->getListaFilmyWypozyczenia().at(i)->getIloscWypozyczonych())));
        ui->tableWidgetStatystyka->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetStatystyka->setItem(i,1, new QTableWidgetItem(bd->getListaFilmyWypozyczenia().at(i)->getTytul()));
        ui->tableWidgetStatystyka->setItem(i,2, new QTableWidgetItem(QString("%1").arg(bd->getListaFilmyWypozyczenia().at(i)->getRokProdukcji())));
        ui->tableWidgetStatystyka->setItem(i,3, new QTableWidgetItem(bd->getListaFilmyWypozyczenia().at(i)->getNazwaGatunku()));
        ui->tableWidgetStatystyka->setItem(i,4, new QTableWidgetItem(QString("%1").arg(bd->getListaFilmyWypozyczenia().at(i)->getIloscKopii())));
        ui->tableWidgetStatystyka->item(i, 4)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetStatystyka->setItem(i,5, new QTableWidgetItem(QString("%1").arg(bd->getListaFilmyWypozyczenia().at(i)->getCenaWypozyczenia())));
        ui->tableWidgetStatystyka->item(i, 5)->setTextAlignment(Qt::AlignRight);
    }
}

void Wypozyczalnia::on_pushButtonWyswietlKlientowNajWyp_clicked()
{
    QDateTime dataOd = ui->dateTimeEditStatystykaOd->dateTime();
    QDateTime dataDo = ui->dateTimeEditStatystykaDo->dateTime();
    bd->wyszukajNajczestszychKlientow(dataOd, dataDo);
    ui->tableWidgetStatystyka->setColumnCount(7);
    QStringList naglowek;
    naglowek.append("Wypożyczono");
    naglowek.append("Imię");
    naglowek.append("Nazwisko");
    naglowek.append("Miejscowość");
    naglowek.append("Email");
    naglowek.append("Telefon");
    naglowek.append("Data rejestr.");
    ui->tableWidgetStatystyka->setHorizontalHeaderLabels(naglowek);
    ui->tableWidgetStatystyka->horizontalHeader()->setFont(QFont("Arial",8));
    ui->tableWidgetStatystyka->verticalHeader()->close();
    ui->tableWidgetStatystyka->setColumnWidth(0, 100);
    ui->tableWidgetStatystyka->setColumnWidth(1, 100);
    ui->tableWidgetStatystyka->setColumnWidth(2, 150);
    ui->tableWidgetStatystyka->setColumnWidth(3, 100);
    ui->tableWidgetStatystyka->setColumnWidth(4, 150);
    ui->tableWidgetStatystyka->setColumnWidth(5, 90);
    ui->tableWidgetStatystyka->setColumnWidth(6, 90);
    ui->tableWidgetStatystyka->setRowCount(bd->getListaKlienciWypozyczenia().size());
    for(int i=0; i<bd->getListaKlienciWypozyczenia().size(); i++)
    {
        ui->tableWidgetStatystyka->setItem(i,0, new QTableWidgetItem(QString("%1").arg(bd->getListaKlienciWypozyczenia().at(i)->getIloscWypozyczonych())));
        ui->tableWidgetStatystyka->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetStatystyka->setItem(i,1, new QTableWidgetItem(bd->getListaKlienciWypozyczenia().at(i)->getImie()));
        ui->tableWidgetStatystyka->setItem(i,2, new QTableWidgetItem(bd->getListaKlienciWypozyczenia().at(i)->getNazwisko()));
        ui->tableWidgetStatystyka->setItem(i,3, new QTableWidgetItem(bd->getListaKlienciWypozyczenia().at(i)->getMiasto()));
        ui->tableWidgetStatystyka->setItem(i,4, new QTableWidgetItem(bd->getListaKlienciWypozyczenia().at(i)->getEmail()));
        ui->tableWidgetStatystyka->setItem(i,5, new QTableWidgetItem(bd->getListaKlienciWypozyczenia().at(i)->getTelefon()));
        ui->tableWidgetStatystyka->setItem(i,6, new QTableWidgetItem(bd->getListaKlienciWypozyczenia().at(i)->getDataRejestracji().toString("yyyy-MM-dd")));
    }
}
