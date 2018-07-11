#include "wypozyczalnia.h"
#include "ui_wypozyczalnia.h"

Wypozyczalnia::Wypozyczalnia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wypozyczalnia)
{
    ui->setupUi(this);
    ui->tabWidget->setTabEnabled(5, false);
    if (ObslugaBD::idZalogowanyUzytkownik == 1)
        ui->tabWidget->setTabEnabled(5, true);
    ObslugaBD bd;
    ui->comboBoxGatunek1->addItems(bd.odczytGatunki());
    ui->comboBoxGatunek2->addItems(bd.odczytGatunki());
    ui->comboBoxGatunek3->addItems(bd.odczytGatunki());
    ui->comboBoxGatunekWyszukaj->addItems(bd.odczytGatunki());
    //    ui->tabWidget->setStyleSheet("QTabWidget::pane { border: 1px solid #000033; }");
    ui->tabWidget->setStyleSheet("QTabWidget::pane > QWidget { background-color: #b8b8b8; }");
    ui->tableWidgetWyszukajFilm->setStyleSheet("QWidget::pane > QWidget { background-color: #C3C3AE; }");
    ui->tableWidgetWyszukajFilm->setColumnWidth(0,35);
    ui->tableWidgetWyszukajFilm->setColumnWidth(1,185);
    ui->tableWidgetWyszukajFilm->setColumnWidth(2,70);
    ui->tableWidgetWyszukajFilm->setColumnWidth(3,80);
    ui->tableWidgetWyszukajFilm->setColumnWidth(4,440);
    ui->tableWidgetWyszukajFilm->setColumnWidth(5,50);
    ui->tableWidgetWyszukajFilm->setColumnWidth(6,90);
    ui->tableWidgetWyszukajFilm->setColumnWidth(7,80);
    ui->tableWidgetWyszukajKlienta->setStyleSheet("QWidget::pane > QWidget { background-color: #C3C3AE; }");
    ui->tableWidgetWyszukajKlienta->setColumnWidth(0,35);
    ui->tableWidgetWyszukajKlienta->setColumnWidth(1,80);
    ui->tableWidgetWyszukajKlienta->setColumnWidth(2,120);
    ui->tableWidgetWyszukajKlienta->setColumnWidth(3,90);
    ui->tableWidgetWyszukajKlienta->setColumnWidth(4,100);
    ui->tableWidgetWyszukajKlienta->setColumnWidth(5,60);
    ui->tableWidgetWyszukajKlienta->setColumnWidth(6,90);
    ui->tableWidgetWyszukajKlienta->setColumnWidth(7,80);
    ObslugaBD::ileWierszyKlientEdycja = 100;
    ObslugaBD::ileWierszyFilmEdycja = 100;
    tablicaBoxKlienci = new QCheckBox*[ObslugaBD::ileWierszyKlientEdycja];
    tablicaBoxFilmy = new QCheckBox*[ObslugaBD::ileWierszyFilmEdycja];
    ui->dateTimeEditTerminZwrotu->setDateTime(planowaDataZwrotu.currentDateTime().addDays(2));
    ui->dateTimeEditTerminRezerwacji->setDateTime(czasRezerwacji.currentDateTime().addDays(1));
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
    ui->tableWidgetWyszukajWypozyczone->setStyleSheet("QWidget::pane > QWidget { background-color: #C3C3AE; }");
    ui->tableWidgetWyszukajWypozyczone->setColumnWidth(0,35);
    ui->tableWidgetWyszukajWypozyczone->setColumnWidth(1,55);
    ui->tableWidgetWyszukajWypozyczone->setColumnWidth(2,180);
    ui->tableWidgetWyszukajWypozyczone->setColumnWidth(3,60);
    ui->tableWidgetWyszukajWypozyczone->setColumnWidth(4,60);
    ui->tableWidgetWyszukajWypozyczone->setColumnWidth(5,60);
    ui->tableWidgetWyszukajWypozyczone->setColumnWidth(6,110);
    ui->tableWidgetWyszukajWypozyczone->setColumnWidth(7,105);
    ui->tableWidgetWyszukajWypozyczone->setColumnWidth(8,105);
    ui->tableWidgetWyszukajWypozyczone->setColumnWidth(9,60);
    ui->tableWidgetWyszukajZarezerwowane->setStyleSheet("QWidget::pane > QWidget { background-color: #C3C3AE; }");
    ui->tableWidgetWyszukajZarezerwowane->setColumnWidth(0,35);
    ui->tableWidgetWyszukajZarezerwowane->setColumnWidth(1,60);
    ui->tableWidgetWyszukajZarezerwowane->setColumnWidth(2,180);
    ui->tableWidgetWyszukajZarezerwowane->setColumnWidth(3,55);
    ui->tableWidgetWyszukajZarezerwowane->setColumnWidth(4,60);
    ui->tableWidgetWyszukajZarezerwowane->setColumnWidth(5,60);
    ui->tableWidgetWyszukajZarezerwowane->setColumnWidth(6,100);
    ui->tableWidgetWyszukajZarezerwowane->setColumnWidth(7,100);
    ui->tableWidgetWyszukajZarezerwowane->setColumnWidth(8,100);
    ui->tableWidgetWyszukajZarezerwowane->setColumnWidth(9,80);
    ui->tableWidgetWyszukajKlientaEdycja->setStyleSheet("QWidget::pane > QWidget { background-color: #C3C3AE; }");
    ui->tableWidgetWyszukajKlientaEdycja->setColumnWidth(0,35);
    ui->tableWidgetWyszukajKlientaEdycja->setColumnWidth(1,80);
    ui->tableWidgetWyszukajKlientaEdycja->setColumnWidth(2,120);
    ui->tableWidgetWyszukajKlientaEdycja->setColumnWidth(3,80);
    ui->tableWidgetWyszukajKlientaEdycja->setColumnWidth(4,120);
    ui->tableWidgetWyszukajKlientaEdycja->setColumnWidth(5,130);
    ui->tableWidgetWyszukajKlientaEdycja->setColumnWidth(6,60);
    ui->tableWidgetWyszukajKlientaEdycja->setColumnWidth(7,60);
    ui->tableWidgetWyszukajKlientaEdycja->setColumnWidth(8,160);
    ui->tableWidgetWyszukajKlientaEdycja->setColumnWidth(9,60);
    ui->tableWidgetWyszukajFilmEdycja->setStyleSheet("QWidget::pane > QWidget { background-color: #C3C3AE; }");
    ui->tableWidgetWyszukajFilmEdycja->setColumnWidth(0,35);
    ui->tableWidgetWyszukajFilmEdycja->setColumnWidth(1,150);
    ui->tableWidgetWyszukajFilmEdycja->setColumnWidth(2,45);
    ui->tableWidgetWyszukajFilmEdycja->setColumnWidth(3,350);
    ui->tableWidgetWyszukajFilmEdycja->setColumnWidth(4,45);
    ui->tableWidgetWyszukajFilmEdycja->setColumnWidth(5,65);
    ui->tableWidgetWyszukajFilmEdycja->setColumnWidth(6,90);
    ui->tableWidgetWyszukajFilmEdycja->setColumnWidth(7,90);
    ui->tableWidgetWyszukajFilmEdycja->setColumnWidth(8,90);
    ui->tableWidgetWyszukajFilmEdycja->setColumnWidth(9,50);
}

Wypozyczalnia::~Wypozyczalnia()
{
    delete [] tablicaBoxKlienci;
    delete [] tablicaBoxFilmy;
    delete ui;
}

void Wypozyczalnia::on_pushButtonDodajUzytkownika_clicked()
{
    QString login, haslo, imie, nazwisko;
    login = ui->lineEditLogin->text();
    haslo = ui->lineEditHaslo->text();
    imie = ui->lineEditImieUzytkownika->text();
    nazwisko = ui->lineEditNazwiskoUzytkownika->text();
    if(login == "" || haslo == "" || imie == "" || nazwisko == "")
        ui->komunikatyDodajUzytkownika->setText("Proszę uzupełnić wszystkie pola forlmularza.");
    else
    {
        ObslugaBD bd;
        if (bd.dodajUzytkownika(login, haslo, imie, nazwisko))
        {
            ui->komunikatyDodajUzytkownika->setText("Dodano nowego użytkownika do bazy danych.");
            ui->lineEditLogin->clear();
            ui->lineEditHaslo->clear();
            ui->lineEditImieUzytkownika->clear();
            ui->lineEditNazwiskoUzytkownika->clear();
        }
        else
            ui->komunikatyDodajUzytkownika->setText("Błąd: nie udało się dodać użytkownika do bazy danych.");
    }
}

void Wypozyczalnia::on_pushButtonDodajKlienta_clicked()
{
    QString imie, nazwisko, kodPocztowy, miasto, ulica, nrDomu, nrlokalu, email;
    imie = ui->lineEditImieKlienta->text();
    nazwisko = ui->lineEditNazwiskoKlienta->text();
    kodPocztowy = ui->lineEditKodPocztowy->text();
    miasto = ui->lineEditMiasto->text();
    ulica = ui->lineEditUlica->text();
    nrDomu = ui->lineEditNrDomu->text();
    nrlokalu = ui->lineEditNrLokalu->text();
    email = ui->lineEditEmail->text();
    if(imie == "" || nazwisko == "" || miasto == "" || ulica == "" || nrDomu == "")
        ui->komunikatyDodajKlienta->setText("Proszę uzupełnić wymagane pola forlmularza.");
    else
    {
        ObslugaBD bd;
        if (bd.dodajKlienta(imie, nazwisko, kodPocztowy, miasto, ulica, nrDomu, nrlokalu, email))
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
    gatunek1 = ui->comboBoxGatunek1->currentIndex();
    gatunek2 = ui->comboBoxGatunek2->currentIndex();
    gatunek3 = ui->comboBoxGatunek3->currentIndex();
    if (tytul == "" || opis == "" || cenaWypozyczenia == 0.00 || rok == 0 || ilosckopii == 0 || gatunek1 == 0)
        ui->komunikatyDodajFilm->setText("Proszę uzupełnić wymagane pola forlmularza.");
    else {
        ObslugaBD bd;
        if (bd.dodajFilm(tytul, rok, opis, cenaWypozyczenia, ilosckopii, gatunek1, gatunek2, gatunek3))
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
    ObslugaBD bd;
    int rok, gatunek;
    rok = ui->lineEditRokWyszukaj->text().toInt();
    gatunek = ui->comboBoxGatunekWyszukaj->currentIndex();
    listaBoxWypozyczenieFilmy.clear();
    listaBoxRezerwacjaFilmy.clear();
    bd.wyszukajFilmRokGatunek(rok, gatunek);
    ui->tableWidgetWyszukajFilm->setRowCount(ObslugaBD::ileWierszyFilm);
    for(int i=0; i<ObslugaBD::ileWierszyFilm; i++)
    {
        ui->tableWidgetWyszukajFilm->setItem(i,0, new QTableWidgetItem(QString("%1").arg(bd.getListaFilmy().at(i)->getIdFilmu())));
        ui->tableWidgetWyszukajFilm->item(i, 0)->setFlags(Qt::ItemIsEditable);
        ui->tableWidgetWyszukajFilm->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetWyszukajFilm->setItem(i,1, new QTableWidgetItem(bd.getListaFilmy().at(i)->getTytul()));
        ui->tableWidgetWyszukajFilm->setItem(i,2, new QTableWidgetItem(QString("%1").arg(bd.getListaFilmy().at(i)->getRokProdukcji())));
        ui->tableWidgetWyszukajFilm->setItem(i,3, new QTableWidgetItem(bd.getListaFilmy().at(i)->getNazwaGatunku()));
        ui->tableWidgetWyszukajFilm->setItem(i,4, new QTableWidgetItem(bd.getListaFilmy().at(i)->getOpis()));
        ui->tableWidgetWyszukajFilm->setItem(i,5, new QTableWidgetItem(QString("%1").arg(bd.getListaFilmy().at(i)->getCenaWypozyczenia())));
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
    ObslugaBD bd;
    QString tytul, opis;
    tytul = ui->lineEditTytulWyszukaj->text();
    opis = ui->lineEditOpisWyszukaj->text();
    listaBoxWypozyczenieFilmy.clear();
    listaBoxRezerwacjaFilmy.clear();
    bd.wyszukajFilmTytulOpis(tytul, opis);
    ui->tableWidgetWyszukajFilm->setRowCount(ObslugaBD::ileWierszyFilm);
    for(int i=0; i<ObslugaBD::ileWierszyFilm; i++)
    {
        ui->tableWidgetWyszukajFilm->setItem(i,0, new QTableWidgetItem(QString("%1").arg(bd.getListaFilmy().at(i)->getIdFilmu())));
        ui->tableWidgetWyszukajFilm->item(i, 0)->setFlags(Qt::ItemIsEditable);
        ui->tableWidgetWyszukajFilm->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetWyszukajFilm->setItem(i,1, new QTableWidgetItem(bd.getListaFilmy().at(i)->getTytul()));
        ui->tableWidgetWyszukajFilm->setItem(i,2, new QTableWidgetItem(QString("%1").arg(bd.getListaFilmy().at(i)->getRokProdukcji())));
        ui->tableWidgetWyszukajFilm->setItem(i,3, new QTableWidgetItem(bd.getListaFilmy().at(i)->getNazwaGatunku()));
        ui->tableWidgetWyszukajFilm->setItem(i,4, new QTableWidgetItem(bd.getListaFilmy().at(i)->getOpis()));
        ui->tableWidgetWyszukajFilm->setItem(i,5, new QTableWidgetItem(QString("%1").arg(bd.getListaFilmy().at(i)->getCenaWypozyczenia())));
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
    ObslugaBD bd;
    QString imie, nazwisko, miasto, ulica;
    imie = ui->lineEditImieWyszukaj->text();
    nazwisko = ui->lineEditNazwiskoWyszukaj->text();
    miasto = ui->lineEditMiastoWyszukaj->text();
    ulica = ui->lineEditUlicaWyszukaj->text();
    listaBoxWypozyczenieKlienci.clear();
    listaBoxRezerwacjaKlienci.clear();
    bd.wyszukajKlienta(imie, nazwisko, miasto, ulica);
    ui->tableWidgetWyszukajKlienta->setRowCount(ObslugaBD::ileWierszyKlient);
    for(int i=0; i<ObslugaBD::ileWierszyKlient; i++)
    {
        ui->tableWidgetWyszukajKlienta->setItem(i,0, new QTableWidgetItem(QString("%1").arg(bd.getListaKlienci().at(i)->getIdKlienta())));
        ui->tableWidgetWyszukajKlienta->item(i, 0)->setFlags(Qt::ItemIsEditable);
        ui->tableWidgetWyszukajKlienta->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetWyszukajKlienta->setItem(i,1, new QTableWidgetItem(bd.getListaKlienci().at(i)->getImie()));
        ui->tableWidgetWyszukajKlienta->setItem(i,2, new QTableWidgetItem(bd.getListaKlienci().at(i)->getNazwisko()));
        ui->tableWidgetWyszukajKlienta->setItem(i,3, new QTableWidgetItem(bd.getListaKlienci().at(i)->getMiasto()));
        ui->tableWidgetWyszukajKlienta->setItem(i,4, new QTableWidgetItem(bd.getListaKlienci().at(i)->getUlica()));
        ui->tableWidgetWyszukajKlienta->setItem(i,5, new QTableWidgetItem(bd.getListaKlienci().at(i)->getNrDomu()));
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
    for(int i=0; i<ObslugaBD::ileWierszyFilm; i++)
    {
        if (listaBoxRezerwacjaFilmy.value(i)->isChecked())
            ileFilmow++;
    }
    if (ileFilmow != 1)
        jedenFilmRezerwuj.exec();

    // sprawdzenie czy zaznaczono klienta oraz czy zaznaczonych klientow jest więcej niż jeden
    int ileKlientow = 0;
    for(int i=0; i<ObslugaBD::ileWierszyKlient; i++)
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
        ObslugaBD bd;
        QDateTime terminRezerwacji;
        for(int i=0; i<ObslugaBD::ileWierszyFilm; i++)
        {
            if (listaBoxRezerwacjaFilmy.value(i)->isChecked())
                wybraneIdFilmu = ui->tableWidgetWyszukajFilm->item(i, 0)->text().toInt();
        }
        for(int i=0; i<ObslugaBD::ileWierszyKlient; i++)
        {
            if (listaBoxRezerwacjaKlienci.value(i)->isChecked())
                wybraneIdKlienta = ui->tableWidgetWyszukajKlienta->item(i, 0)->text().toInt();
        }
        if (bd.czyMozliwaRezerwacjaWypozyczenie(wybraneIdFilmu))
        {
            terminRezerwacji = ui->dateTimeEditTerminRezerwacji->dateTime();
            if (bd.wykonajRezerwacje(wybraneIdKlienta, wybraneIdFilmu, terminRezerwacji))
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
    for(int i=0; i<ObslugaBD::ileWierszyFilm; i++)
    {
        if (listaBoxWypozyczenieFilmy.value(i)->isChecked())
            ileFilmow++;
    }
    if (ileFilmow != 1)
        jedenFilmWypozycz.exec();

    // sprawdzenie czy zaznaczono klienta oraz czy zaznaczonych klientow jest więcej niż jeden
    int ileKlientow = 0;
    for(int i=0; i<ObslugaBD::ileWierszyKlient; i++)
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
        ObslugaBD bd;
        QDateTime planowaDataZwrotu;
        for(int i=0; i<ObslugaBD::ileWierszyFilm; i++)
        {
            if (listaBoxWypozyczenieFilmy.value(i)->isChecked())
                wybraneIdFilmu = ui->tableWidgetWyszukajFilm->item(i, 0)->text().toInt();
        }
        for(int i=0; i<ObslugaBD::ileWierszyKlient; i++)
        {
            if (listaBoxWypozyczenieKlienci.value(i)->isChecked())
                wybraneIdKlienta = ui->tableWidgetWyszukajKlienta->item(i, 0)->text().toInt();
        }
        if (bd.czyMozliwaRezerwacjaWypozyczenie(wybraneIdFilmu))
        {
            planowaDataZwrotu = ui->dateTimeEditTerminZwrotu->dateTime();
            if (bd.wykonajWypozyczenie(wybraneIdKlienta, wybraneIdFilmu, planowaDataZwrotu))
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
    ObslugaBD bd;
    int idFilmu, idKlienta;
    idFilmu = ui->lineEditIdFilmuWyszukajZwrot->text().toInt();
    idKlienta = ui->lineEditIdKlientaWyszukajZwrot->text().toInt();
    listaBoxWypozyczenie.clear();
    bd.wyszukajWypozyczoneFilmyIdFilmuIdKlienta(idFilmu, idKlienta);
    ui->tableWidgetWyszukajWypozyczone->setRowCount(ObslugaBD::ileWierszyWypozyczone);
    for(int i=0; i<ObslugaBD::ileWierszyWypozyczone; i++)
    {
        ui->tableWidgetWyszukajWypozyczone->setItem(i,0, new QTableWidgetItem(QString("%1").arg(bd.getListaWypozyczenia().at(i)->getIdWypozyczenia())));
        ui->tableWidgetWyszukajWypozyczone->item(i, 0)->setFlags(Qt::ItemIsEditable);
        ui->tableWidgetWyszukajWypozyczone->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetWyszukajWypozyczone->setItem(i,1, new QTableWidgetItem(QString("%1").arg(bd.getListaWypozyczenia().at(i)->getIdFilmu())));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,2, new QTableWidgetItem(bd.getListaWypozyczenia().at(i)->getTytul()));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,3, new QTableWidgetItem(QString("%1").arg(bd.getListaWypozyczenia().at(i)->getCenaWypozyczenia())));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,4, new QTableWidgetItem(QString("%1").arg(bd.getListaWypozyczenia().at(i)->getIdKlienta())));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,5, new QTableWidgetItem(bd.getListaWypozyczenia().at(i)->getImie()));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,6, new QTableWidgetItem(bd.getListaWypozyczenia().at(i)->getNazwisko()));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,7, new QTableWidgetItem(bd.getListaWypozyczenia().at(i)->getDataWypozyczenia().toString("yyyy-MM-dd hh:mm")));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,8, new QTableWidgetItem(bd.getListaWypozyczenia().at(i)->getPlanowaDataZwrotu().toString("yyyy-MM-dd hh:mm")));
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
    ObslugaBD bd;
    listaBoxWypozyczenie.clear();
    bd.wyszukajWypozyczoneFilmyNazwisko(nazwisko);
    ui->tableWidgetWyszukajWypozyczone->setRowCount(ObslugaBD::ileWierszyWypozyczone);
    for(int i=0; i<ObslugaBD::ileWierszyWypozyczone; i++)
    {
        ui->tableWidgetWyszukajWypozyczone->setItem(i,0, new QTableWidgetItem(QString("%1").arg(bd.getListaWypozyczenia().at(i)->getIdWypozyczenia())));
        ui->tableWidgetWyszukajWypozyczone->item(i, 0)->setFlags(Qt::ItemIsEditable);
        ui->tableWidgetWyszukajWypozyczone->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetWyszukajWypozyczone->setItem(i,1, new QTableWidgetItem(QString("%1").arg(bd.getListaWypozyczenia().at(i)->getIdFilmu())));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,2, new QTableWidgetItem(bd.getListaWypozyczenia().at(i)->getTytul()));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,3, new QTableWidgetItem(QString("%1").arg(bd.getListaWypozyczenia().at(i)->getCenaWypozyczenia())));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,4, new QTableWidgetItem(QString("%1").arg(bd.getListaWypozyczenia().at(i)->getIdKlienta())));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,5, new QTableWidgetItem(bd.getListaWypozyczenia().at(i)->getImie()));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,6, new QTableWidgetItem(bd.getListaWypozyczenia().at(i)->getNazwisko()));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,7, new QTableWidgetItem(bd.getListaWypozyczenia().at(i)->getDataWypozyczenia().toString("yyyy-MM-dd hh:mm")));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,8, new QTableWidgetItem(bd.getListaWypozyczenia().at(i)->getPlanowaDataZwrotu().toString("yyyy-MM-dd hh:mm")));
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
    for(int i=0; i<ObslugaBD::ileWierszyWypozyczone; i++)
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
        ObslugaBD bd;
        for(int i=0; i<ObslugaBD::ileWierszyWypozyczone; i++)
        {
            if (listaBoxWypozyczenie.value(i)->isChecked())
                wybraneIdWypozyczenia = ui->tableWidgetWyszukajWypozyczone->item(i, 0)->text().toInt();
        }

        if (bd.wykonajZwrotFilmu(wybraneIdWypozyczenia))
            ui->komunikatyZwrotOdwolanie->setText("Dokonano zwrotu wybranego filmu.");
        else
            ui->komunikatyZwrotOdwolanie->setText("Błąd! Nie udało się dokonać zwrotu wybranego filmu.");
    }
}

void Wypozyczalnia::on_pushButtonWyszukajZarezerwowaneKlientFilm_clicked()
{
    ui->komunikatyZwrotOdwolanie->clear();
    ui->lineEditNazwiskoWyszukajZarezerwowane->clear();
    ObslugaBD bd;
    int idFilmu, idKlienta;
    idFilmu = ui->lineEditIdFilmuWyszukajZarezerwowane->text().toInt();
    idKlienta = ui->lineEditIdKlientaWyszukajZarezerwowane->text().toInt();
    listaBoxRezerwacja.clear();
    bd.wyszukajRezerwacjeFilmyIdFilmuIdKlienta(idFilmu, idKlienta);
    ui->tableWidgetWyszukajZarezerwowane->setRowCount(ObslugaBD::ileWierszyRezerwacja);
    for(int i=0; i<ObslugaBD::ileWierszyRezerwacja; i++)
    {
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,0, new QTableWidgetItem(QString("%1").arg(bd.getListaRezerwacje().at(i)->getIdRezerwacji())));
        ui->tableWidgetWyszukajZarezerwowane->item(i, 0)->setFlags(Qt::ItemIsEditable);
        ui->tableWidgetWyszukajZarezerwowane->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,1, new QTableWidgetItem(QString("%1").arg(bd.getListaRezerwacje().at(i)->getIdFilmu())));
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,2, new QTableWidgetItem(bd.getListaRezerwacje().at(i)->getTytul()));
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,3, new QTableWidgetItem(QString("%1").arg(bd.getListaRezerwacje().at(i)->getCenaWypozyczenia())));
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,4, new QTableWidgetItem(QString("%1").arg(bd.getListaRezerwacje().at(i)->getIdKlienta())));
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,5, new QTableWidgetItem(bd.getListaRezerwacje().at(i)->getImie()));
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,6, new QTableWidgetItem(bd.getListaRezerwacje().at(i)->getNazwisko()));
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,7, new QTableWidgetItem(bd.getListaRezerwacje().at(i)->getDataRezerwacji().toString("yyyy-MM-dd hh:mm")));
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,8, new QTableWidgetItem(bd.getListaRezerwacje().at(i)->getTerminRezerwacji().toString("yyyy-MM-dd hh:mm")));
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
    ObslugaBD bd;
    listaBoxRezerwacja.clear();
    bd.wyszukajRezerwacjeFilmyNazwisko(nazwisko);
    ui->tableWidgetWyszukajZarezerwowane->setRowCount(ObslugaBD::ileWierszyRezerwacja);
    for(int i=0; i<ObslugaBD::ileWierszyRezerwacja; i++)
    {
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,0, new QTableWidgetItem(QString("%1").arg(bd.getListaRezerwacje().at(i)->getIdRezerwacji())));
        ui->tableWidgetWyszukajZarezerwowane->item(i, 0)->setFlags(Qt::ItemIsEditable);
        ui->tableWidgetWyszukajZarezerwowane->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,1, new QTableWidgetItem(QString("%1").arg(bd.getListaRezerwacje().at(i)->getIdFilmu())));
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,2, new QTableWidgetItem(bd.getListaRezerwacje().at(i)->getTytul()));
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,3, new QTableWidgetItem(QString("%1").arg(bd.getListaRezerwacje().at(i)->getCenaWypozyczenia())));
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,4, new QTableWidgetItem(QString("%1").arg(bd.getListaRezerwacje().at(i)->getIdKlienta())));
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,5, new QTableWidgetItem(bd.getListaRezerwacje().at(i)->getImie()));
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,6, new QTableWidgetItem(bd.getListaRezerwacje().at(i)->getNazwisko()));
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,7, new QTableWidgetItem(bd.getListaRezerwacje().at(i)->getDataRezerwacji().toString("yyyy-MM-dd hh:mm")));
        ui->tableWidgetWyszukajZarezerwowane->setItem(i,8, new QTableWidgetItem(bd.getListaRezerwacje().at(i)->getTerminRezerwacji().toString("yyyy-MM-dd hh:mm")));
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
    for(int i=0; i<ObslugaBD::ileWierszyRezerwacja; i++)
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
        ObslugaBD bd;
        for(int i=0; i<ObslugaBD::ileWierszyRezerwacja; i++)
        {
            if (listaBoxRezerwacja.value(i)->isChecked())
                wybraneIdRezerwacji = ui->tableWidgetWyszukajZarezerwowane->item(i, 0)->text().toInt();
        }

        if (bd.wykonajOdwolanieRezerwacji(wybraneIdRezerwacji))
            ui->komunikatyZwrotOdwolanie->setText("Dokonano odwołania rezerwacji wybranego filmu.");
        else
            ui->komunikatyZwrotOdwolanie->setText("Błąd! Nie udało się dokonać odwołania rezerwacji wybranego filmu.");
    }
}


void Wypozyczalnia::on_lineEditNazwiskoWyszukajEdytuj_textChanged(const QString &nazwisko)
{
    ui->komunikatyDodajKlienta->clear();
    ObslugaBD bd;
    bd.wyszukajKlienta(nazwisko);
    ui->tableWidgetWyszukajKlientaEdycja->setRowCount(ObslugaBD::ileWierszyKlientEdycja);
    for(int i=0; i<ObslugaBD::ileWierszyKlientEdycja; i++)
    {
        ui->tableWidgetWyszukajKlientaEdycja->setItem(i,0, new QTableWidgetItem(QString("%1").arg(bd.getListaKlienci().at(i)->getIdKlienta())));
        ui->tableWidgetWyszukajKlientaEdycja->item(i, 0)->setFlags(Qt::ItemIsEditable);
        ui->tableWidgetWyszukajKlientaEdycja->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetWyszukajKlientaEdycja->setItem(i,1, new QTableWidgetItem(bd.getListaKlienci().at(i)->getImie()));
        ui->tableWidgetWyszukajKlientaEdycja->setItem(i,2, new QTableWidgetItem(bd.getListaKlienci().at(i)->getNazwisko()));
        ui->tableWidgetWyszukajKlientaEdycja->setItem(i,3, new QTableWidgetItem(bd.getListaKlienci().at(i)->getKod()));
        ui->tableWidgetWyszukajKlientaEdycja->setItem(i,4, new QTableWidgetItem(bd.getListaKlienci().at(i)->getMiasto()));
        ui->tableWidgetWyszukajKlientaEdycja->setItem(i,5, new QTableWidgetItem(bd.getListaKlienci().at(i)->getUlica()));
        ui->tableWidgetWyszukajKlientaEdycja->setItem(i,6, new QTableWidgetItem(bd.getListaKlienci().at(i)->getNrDomu()));
        ui->tableWidgetWyszukajKlientaEdycja->setItem(i,7, new QTableWidgetItem(bd.getListaKlienci().at(i)->getNrLokalu()));
        ui->tableWidgetWyszukajKlientaEdycja->setItem(i,8, new QTableWidgetItem(bd.getListaKlienci().at(i)->getEmail()));
        boxKlienci = new QCheckBox();
        boxKlienci->setStyleSheet("margin-left:25%;");
        tablicaBoxKlienci[i] = boxKlienci;
        ui->tableWidgetWyszukajKlientaEdycja->setCellWidget(i,9, tablicaBoxKlienci[i]);
    }
}

void Wypozyczalnia::on_pushButtonEdytujKlienta_clicked()
{
    int wierszeTabeli = ui->tableWidgetWyszukajKlientaEdycja->rowCount();
    if (wierszeTabeli > 0)
    {
        // sprawdzenie czy zaznaczono klienta oraz czy zaznaczonych klientów jest więcej niż jeden
        int iluKlientow = 0;
        for(int i=0; i<ObslugaBD::ileWierszyKlientEdycja; i++)
        {
            if (tablicaBoxKlienci[i]->isChecked())
                iluKlientow++;
        }
        if (iluKlientow != 1)
            jedenKlientEdytuj.exec();
        //wykonanie edycji wybranego klienta wg idKlienta
        if (iluKlientow == 1)
        {
            int wybraneIdKlienta = 0;
            QString imie, nazwisko, kod, miasto, ulica, nrDomu, nrLokalu, email;
            ObslugaBD bd;
            for(int i=0; i<ObslugaBD::ileWierszyKlientEdycja; i++)
            {
                if (tablicaBoxKlienci[i]->isChecked())
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
                }
            }
            if (bd.wykonajEdycjeKlienta(wybraneIdKlienta, imie, nazwisko, kod, miasto, ulica, nrDomu, nrLokalu, email))
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
    ObslugaBD bd;
    bd.wyszukajFilm(tytul);
    ui->tableWidgetWyszukajFilmEdycja->setRowCount(ObslugaBD::ileWierszyFilmEdycja);
    for(int i=0; i<ObslugaBD::ileWierszyFilmEdycja; i++)
    {
        ui->tableWidgetWyszukajFilmEdycja->setItem(i,0, new QTableWidgetItem(QString("%1").arg(bd.getListaFilmy().at(i)->getIdFilmu())));
        ui->tableWidgetWyszukajFilmEdycja->item(i, 0)->setFlags(Qt::ItemIsEditable);
        ui->tableWidgetWyszukajFilmEdycja->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetWyszukajFilmEdycja->setItem(i,1, new QTableWidgetItem(bd.getListaFilmy().at(i)->getTytul()));
        ui->tableWidgetWyszukajFilmEdycja->setItem(i,2, new QTableWidgetItem(QString("%1").arg(bd.getListaFilmy().at(i)->getRokProdukcji())));
        ui->tableWidgetWyszukajFilmEdycja->setItem(i,3, new QTableWidgetItem(bd.getListaFilmy().at(i)->getOpis()));
        ui->tableWidgetWyszukajFilmEdycja->setItem(i,4, new QTableWidgetItem(QString("%1").arg(bd.getListaFilmy().at(i)->getIloscKopii())));
        ui->tableWidgetWyszukajFilmEdycja->setItem(i,5, new QTableWidgetItem(QString("%1").arg(bd.getListaFilmy().at(i)->getCenaWypozyczenia())));
        comboGatunek1 = new QComboBox();
        comboGatunek1->addItems(bd.odczytGatunki());
        comboGatunek1->setCurrentIndex(bd.getListaFilmy().at(i)->getGatunek1());
        ui->tableWidgetWyszukajFilmEdycja->setCellWidget(i, 6, comboGatunek1);
        comboGatunek2 = new QComboBox();
        comboGatunek2->addItems(bd.odczytGatunki());
        comboGatunek2->setCurrentIndex(bd.getListaFilmy().at(i)->getGatunek2());
        ui->tableWidgetWyszukajFilmEdycja->setCellWidget(i, 7, comboGatunek2);
        comboGatunek3 = new QComboBox();
        comboGatunek3->addItems(bd.odczytGatunki());
        comboGatunek3->setCurrentIndex(bd.getListaFilmy().at(i)->getGatunek3());
        ui->tableWidgetWyszukajFilmEdycja->setCellWidget(i, 8, comboGatunek3);
        boxFilmy = new QCheckBox();
        boxFilmy->setStyleSheet("margin-left:25%;");
        tablicaBoxFilmy[i] = boxFilmy;
        ui->tableWidgetWyszukajFilmEdycja->setCellWidget(i, 9, tablicaBoxFilmy[i]);
    }
}

void Wypozyczalnia::on_pushButtonEdytujFilm_clicked()
{
    int wierszeTabeli = ui->tableWidgetWyszukajFilmEdycja->rowCount();
    if (wierszeTabeli > 0)
    {
        // sprawdzenie czy zaznaczono film oraz czy zaznaczonych filmów jest więcej niż jeden
        int ileFilmow = 0;
        for(int i=0; i<ObslugaBD::ileWierszyFilmEdycja; i++)
        {
            if (tablicaBoxFilmy[i]->isChecked())
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
            ObslugaBD bd;
            for(int i=0; i<ObslugaBD::ileWierszyFilmEdycja; i++)
            {
                if (tablicaBoxFilmy[i]->isChecked())
                {
                    wybraneIdFilmu = ui->tableWidgetWyszukajFilmEdycja->item(i, 0)->text().toInt();
                    tytul = ui->tableWidgetWyszukajFilmEdycja->item(i, 1)->text();
                    rokProdukcji = ui->tableWidgetWyszukajFilmEdycja->item(i, 2)->text().toInt();
                    opis = ui->tableWidgetWyszukajFilmEdycja->item(i, 3)->text();
                    iloscKopii = ui->tableWidgetWyszukajFilmEdycja->item(i, 4)->text().toInt();
                    cenaWypozyczenia = ui->tableWidgetWyszukajFilmEdycja->item(i, 5)->text().toDouble();
                    comboGatunek1 = (QComboBox *)ui->tableWidgetWyszukajFilmEdycja->cellWidget(i, 6);
                    gatunek1 = comboGatunek1->currentIndex();
                    comboGatunek2 = (QComboBox *)ui->tableWidgetWyszukajFilmEdycja->cellWidget(i, 7);
                    gatunek2 = comboGatunek2->currentIndex();
                    comboGatunek3 = (QComboBox *)ui->tableWidgetWyszukajFilmEdycja->cellWidget(i, 8);
                    gatunek3 = comboGatunek3->currentIndex();
                }
            }
            if (bd.wykonajEdycjeFilmu(wybraneIdFilmu, tytul, rokProdukcji, opis, iloscKopii, cenaWypozyczenia, gatunek1, gatunek2, gatunek3))
                ui->komunikatyDodajFilm->setText("Dokonano edycji wybranego filmu.");
            else
                ui->komunikatyDodajFilm->setText("Błąd! Nie udało się dokonać edycji wybranego filmu.");
        }
    }
    else
        ui->komunikatyDodajFilm->setText("Proszę wyszukać film do edycji.");
}
