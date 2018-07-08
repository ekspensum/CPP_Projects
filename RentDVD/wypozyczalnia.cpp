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
    ui->tableWidgetWyszukajFilm->setColumnWidth(0,200);
    ui->tableWidgetWyszukajFilm->setColumnWidth(1,70);
    ui->tableWidgetWyszukajFilm->setColumnWidth(2,80);
    ui->tableWidgetWyszukajFilm->setColumnWidth(3,460);
    ui->tableWidgetWyszukajFilm->setColumnWidth(4,50);
    ui->tableWidgetWyszukajFilm->setColumnWidth(5,90);
    ui->tableWidgetWyszukajFilm->setColumnWidth(6,80);
    ui->tableWidgetWyszukajKlienta->setStyleSheet("QWidget::pane > QWidget { background-color: #C3C3AE; }");
    ui->tableWidgetWyszukajKlienta->setColumnWidth(0,100);
    ui->tableWidgetWyszukajKlienta->setColumnWidth(1,120);
    ui->tableWidgetWyszukajKlienta->setColumnWidth(2,100);
    ui->tableWidgetWyszukajKlienta->setColumnWidth(3,110);
    ui->tableWidgetWyszukajKlienta->setColumnWidth(4,60);
    ui->tableWidgetWyszukajKlienta->setColumnWidth(5,90);
    ui->tableWidgetWyszukajKlienta->setColumnWidth(6,80);
    tablicaBoxWypozyczenie = new QCheckBox*[ObslugaBD::ileWierszyKlient];
    tablicaBoxRezerwacja = new QCheckBox*[ObslugaBD::ileWierszyKlient];
    ui->dateTimeEditTerminZwrotu->setDateTime(planowaDataZwrotu.currentDateTime().addDays(2));
    ui->dateTimeEditTerminRezerwacji->setDateTime(czasRezerwacji.currentDateTime().addDays(1));
    p.setColor(QPalette::ButtonText, Qt::blue);
    ui->pushButtonWypozyczenie->setPalette(p);
    jedenFilmRezerwuj.setText("Proszę zazanaczyć jeden film do rezerwacji.");
    jedenKlientRezerwuj.setText("Proszę zazanaczyć jednego klienta do rezerwacji.");
    jedenFilmWypozycz.setText("Proszę zazanaczyć jeden film do wypożyczenia.");
    jedenKlientWypozycz.setText("Proszę zazanaczyć jednego klienta do wypożyczenia.");
    ui->tableWidgetWyszukajWypozyczone->setStyleSheet("QWidget::pane > QWidget { background-color: #C3C3AE; }");
    ui->tableWidgetWyszukajWypozyczone->setColumnWidth(0,60);
    ui->tableWidgetWyszukajWypozyczone->setColumnWidth(1,200);
    ui->tableWidgetWyszukajWypozyczone->setColumnWidth(2,60);
    ui->tableWidgetWyszukajWypozyczone->setColumnWidth(3,60);
    ui->tableWidgetWyszukajWypozyczone->setColumnWidth(4,60);
    ui->tableWidgetWyszukajWypozyczone->setColumnWidth(5,110);
    ui->tableWidgetWyszukajWypozyczone->setColumnWidth(6,110);
    ui->tableWidgetWyszukajWypozyczone->setColumnWidth(7,110);
    ui->tableWidgetWyszukajWypozyczone->setColumnWidth(8,60);

}

Wypozyczalnia::~Wypozyczalnia()
{
    delete [] tablicaBoxWypozyczenie;
    delete [] tablicaBoxRezerwacja;
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
    QString imie, nazwisko, kodPocztowy, miasto, ulica, nrDomu, nrlokalu;
    imie = ui->lineEditImieKlienta->text();
    nazwisko = ui->lineEditNazwiskoKlienta->text();
    kodPocztowy = ui->lineEditKodPocztowy->text();
    miasto = ui->lineEditMiasto->text();
    ulica = ui->lineEditUlica->text();
    nrDomu = ui->lineEditNrDomu->text();
    nrlokalu = ui->lineEditNrLokalu->text();
    if(imie == "" || nazwisko == "" || miasto == "" || ulica == "" || nrDomu == "")
        ui->komunikatyDodajKlienta->setText("Proszę uzupełnić wymagane pola forlmularza.");
    else
    {
        ObslugaBD bd;
        if (bd.dodajKlienta(imie, nazwisko, kodPocztowy, miasto, ulica, nrDomu, nrlokalu))
        {
            ui->komunikatyDodajKlienta->setText("Dodano nowego klienta do bazy danych.");
            ui->lineEditImieKlienta->clear();
            ui->lineEditNazwiskoKlienta->clear();
            ui->lineEditKodPocztowy->clear();
            ui->lineEditMiasto->clear();
            ui->lineEditUlica->clear();
            ui->lineEditNrDomu->clear();
            ui->lineEditNrLokalu->clear();
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
    listaBoxWypozyczenie.clear();
    listaBoxRezerwacja.clear();
    bd.wyszukajFilmRokGatunek(rok, gatunek);
    ui->tableWidgetWyszukajFilm->setRowCount(ObslugaBD::ileWierszyFilm);
    for(int i=0; i<bd.ileWierszyFilm; i++)
    {
        ui->tableWidgetWyszukajFilm->setItem(i,0, new QTableWidgetItem(bd.listaFilmy.at(i)->getTytul()));
        ui->tableWidgetWyszukajFilm->setItem(i,1, new QTableWidgetItem(QString("%1").arg(bd.listaFilmy.at(i)->getRokProdukcji())));
        ui->tableWidgetWyszukajFilm->setItem(i,2, new QTableWidgetItem(bd.listaFilmy.at(i)->getNazwaGatunku()));
        ui->tableWidgetWyszukajFilm->setItem(i,3, new QTableWidgetItem(bd.listaFilmy.at(i)->getOpis()));
        ui->tableWidgetWyszukajFilm->setItem(i,4, new QTableWidgetItem(QString("%1").arg(bd.listaFilmy.at(i)->getCenaWypozyczenia())));
        boxWypozyczenie = new QCheckBox();
        boxWypozyczenie->setStyleSheet("margin-left:40%; margin-right:60%;");
        listaBoxWypozyczenie.append(boxWypozyczenie);
        ui->tableWidgetWyszukajFilm->setCellWidget(i,5, listaBoxWypozyczenie.value(i));
        boxRezerwacja = new QCheckBox();
        boxRezerwacja->setStyleSheet("margin-left:40%; margin-right:60%;");
        listaBoxRezerwacja.append(boxRezerwacja);
        ui->tableWidgetWyszukajFilm->setCellWidget(i,6, listaBoxRezerwacja.value(i));
    }
}

void Wypozyczalnia::on_pushButtonWyszukajTytulOpis_clicked()
{
    ObslugaBD bd;
    QString tytul, opis;
    tytul = ui->lineEditTytulWyszukaj->text();
    opis = ui->lineEditOpisWyszukaj->text();
    listaBoxWypozyczenie.clear();
    listaBoxRezerwacja.clear();
    bd.wyszukajFilmTytulOpis(tytul, opis);
    ui->tableWidgetWyszukajFilm->setRowCount(ObslugaBD::ileWierszyFilm);
    for(int i=0; i<ObslugaBD::ileWierszyFilm; i++)
    {
        ui->tableWidgetWyszukajFilm->setItem(i,0, new QTableWidgetItem(bd.listaFilmy.at(i)->getTytul()));
        ui->tableWidgetWyszukajFilm->setItem(i,1, new QTableWidgetItem(QString("%1").arg(bd.listaFilmy.at(i)->getRokProdukcji())));
        ui->tableWidgetWyszukajFilm->setItem(i,2, new QTableWidgetItem(bd.listaFilmy.at(i)->getNazwaGatunku()));
        ui->tableWidgetWyszukajFilm->setItem(i,3, new QTableWidgetItem(bd.listaFilmy.at(i)->getOpis()));
        ui->tableWidgetWyszukajFilm->setItem(i,4, new QTableWidgetItem(QString("%1").arg(bd.listaFilmy.at(i)->getCenaWypozyczenia())));
        boxWypozyczenie = new QCheckBox();
        boxWypozyczenie->setStyleSheet("margin-left:40%; margin-right:60%;");
        listaBoxWypozyczenie.append(boxWypozyczenie);
        ui->tableWidgetWyszukajFilm->setCellWidget(i,5, listaBoxWypozyczenie.value(i));
        boxRezerwacja = new QCheckBox();
        boxRezerwacja->setStyleSheet("margin-left:40%; margin-right:60%;");
        listaBoxRezerwacja.append(boxRezerwacja);
        ui->tableWidgetWyszukajFilm->setCellWidget(i,6, listaBoxRezerwacja.value(i));
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
    bd.wyszukajKlienta(imie, nazwisko, miasto, ulica);
    ui->tableWidgetWyszukajKlienta->setRowCount(ObslugaBD::ileWierszyKlient);
    for(int i=0; i<ObslugaBD::ileWierszyKlient; i++)
    {
        ui->tableWidgetWyszukajKlienta->setItem(i,0, new QTableWidgetItem(bd.listaKlienci.at(i)->getImie()));
        ui->tableWidgetWyszukajKlienta->setItem(i,1, new QTableWidgetItem(bd.listaKlienci.at(i)->getNazwisko()));
        ui->tableWidgetWyszukajKlienta->setItem(i,2, new QTableWidgetItem(bd.listaKlienci.at(i)->getMiasto()));
        ui->tableWidgetWyszukajKlienta->setItem(i,3, new QTableWidgetItem(bd.listaKlienci.at(i)->getUlica()));
        ui->tableWidgetWyszukajKlienta->setItem(i,4, new QTableWidgetItem(bd.listaKlienci.at(i)->getNrDomu()));
        boxWypozyczenie = new QCheckBox();
        boxWypozyczenie->setStyleSheet("margin-left:40%; margin-right:60%;");
        tablicaBoxWypozyczenie[i] = boxWypozyczenie;
        ui->tableWidgetWyszukajKlienta->setCellWidget(i,5, tablicaBoxWypozyczenie[i]);
        boxRezerwacja = new QCheckBox();
        boxRezerwacja->setStyleSheet("margin-left:40%; margin-right:60%;");
        tablicaBoxRezerwacja[i] = boxRezerwacja;
        ui->tableWidgetWyszukajKlienta->setCellWidget(i,6, tablicaBoxRezerwacja[i]);
    }
}

void Wypozyczalnia::on_pushButtonRezerwacja_clicked()
{
    // sprawdzenie czy zaznaczono film oraz czy zaznaczonych filmów jest więcej niż jeden
    int ileFilmow = 0;
    for(int i=0; i<ObslugaBD::ileWierszyFilm; i++)
    {
        if (listaBoxRezerwacja.value(i)->isChecked())
            ileFilmow++;
    }
    if (ileFilmow != 1)
        jedenFilmRezerwuj.exec();

    // sprawdzenie czy zaznaczono klienta oraz czy zaznaczonych klientow jest więcej niż jeden
    int ileKlientow = 0;
    for(int i=0; i<ObslugaBD::ileWierszyKlient; i++)
    {
        if (tablicaBoxRezerwacja[i]->isChecked())
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
            if (listaBoxRezerwacja.value(i)->isChecked())
                wybraneIdFilmu = ObslugaBD::idFilmuVector.at(i);
        }
        for(int i=0; i<ObslugaBD::ileWierszyKlient; i++)
        {
            if (tablicaBoxRezerwacja[i]->isChecked())
                wybraneIdKlienta = ObslugaBD::idKlientaVector.at(i);
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
        if (listaBoxWypozyczenie.value(i)->isChecked())
            ileFilmow++;
    }
    if (ileFilmow != 1)
        jedenFilmWypozycz.exec();

    // sprawdzenie czy zaznaczono klienta oraz czy zaznaczonych klientow jest więcej niż jeden
    int ileKlientow = 0;
    for(int i=0; i<ObslugaBD::ileWierszyKlient; i++)
    {
        if (tablicaBoxWypozyczenie[i]->isChecked())
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
            if (listaBoxWypozyczenie.value(i)->isChecked())
                wybraneIdFilmu = ObslugaBD::idFilmuVector.at(i);
        }
        for(int i=0; i<ObslugaBD::ileWierszyKlient; i++)
        {
            if (tablicaBoxWypozyczenie[i]->isChecked())
                wybraneIdKlienta = ObslugaBD::idKlientaVector.at(i);
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
    ObslugaBD bd;
    int idFilmu, idKlienta;
    idFilmu = ui->lineEditIdFilmuWyszukajZwrot->text().toInt();
    idKlienta = ui->lineEditIdKlientaWyszukajZwrot->text().toInt();
    listaBoxWypozyczenie.clear();
    bd.wyszukajWypozyczoneFilmyIdFilmuIdKlienta(idFilmu, idKlienta);
    ui->tableWidgetWyszukajWypozyczone->setRowCount(ObslugaBD::ileWierszyWypozyczone);
    for(int i=0; i<ObslugaBD::ileWierszyWypozyczone; i++)
    {
        ui->tableWidgetWyszukajWypozyczone->setItem(i,0, new QTableWidgetItem(QString("%1").arg(bd.listaWypozyczenia.at(i)->getIdFilmu())));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,1, new QTableWidgetItem(bd.listaWypozyczenia.at(i)->getTytul()));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,2, new QTableWidgetItem(QString("%1").arg(bd.listaWypozyczenia.at(i)->getCenaWypozyczenia())));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,3, new QTableWidgetItem(QString("%1").arg(bd.listaWypozyczenia.at(i)->getIdKlienta())));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,4, new QTableWidgetItem(bd.listaWypozyczenia.at(i)->getImie()));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,5, new QTableWidgetItem(bd.listaWypozyczenia.at(i)->getNazwisko()));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,6, new QTableWidgetItem(bd.listaWypozyczenia.at(i)->getDataWypozyczenia().toString("yyyy-MM-dd hh:mm")));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,7, new QTableWidgetItem(bd.listaWypozyczenia.at(i)->getPlanowaDataZwrotu().toString("yyyy-MM-dd hh:mm")));
        if (QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm") > ui->tableWidgetWyszukajWypozyczone->item(i,7)->text())
            ui->tableWidgetWyszukajWypozyczone->item(i,7)->setBackgroundColor(Qt::red);
        boxWypozyczenie = new QCheckBox();
        boxWypozyczenie->setStyleSheet("margin-left:25%;");
        listaBoxWypozyczenie.append(boxWypozyczenie);
        ui->tableWidgetWyszukajWypozyczone->setCellWidget(i,8, listaBoxWypozyczenie.value(i));
    }
    ui->lineEditIdFilmuWyszukajZwrot->clear();
    ui->lineEditIdKlientaWyszukajZwrot->clear();
}

void Wypozyczalnia::on_lineEditNazwiskoWyszukajZwrot_textChanged(const QString &nazwisko)
{
    ObslugaBD bd;
    listaBoxWypozyczenie.clear();
    bd.wyszukajWypozyczoneFilmyNazwisko(nazwisko);
    ui->tableWidgetWyszukajWypozyczone->setRowCount(ObslugaBD::ileWierszyWypozyczone);
    for(int i=0; i<ObslugaBD::ileWierszyWypozyczone; i++)
    {
        ui->tableWidgetWyszukajWypozyczone->setItem(i,0, new QTableWidgetItem(QString("%1").arg(bd.listaWypozyczenia.at(i)->getIdFilmu())));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,1, new QTableWidgetItem(bd.listaWypozyczenia.at(i)->getTytul()));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,2, new QTableWidgetItem(QString("%1").arg(bd.listaWypozyczenia.at(i)->getCenaWypozyczenia())));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,3, new QTableWidgetItem(QString("%1").arg(bd.listaWypozyczenia.at(i)->getIdKlienta())));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,4, new QTableWidgetItem(bd.listaWypozyczenia.at(i)->getImie()));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,5, new QTableWidgetItem(bd.listaWypozyczenia.at(i)->getNazwisko()));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,6, new QTableWidgetItem(bd.listaWypozyczenia.at(i)->getDataWypozyczenia().toString("yyyy-MM-dd hh:mm")));
        ui->tableWidgetWyszukajWypozyczone->setItem(i,7, new QTableWidgetItem(bd.listaWypozyczenia.at(i)->getPlanowaDataZwrotu().toString("yyyy-MM-dd hh:mm")));
        if (QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm") > ui->tableWidgetWyszukajWypozyczone->item(i,7)->text())
            ui->tableWidgetWyszukajWypozyczone->item(i,7)->setBackgroundColor(Qt::red);
        boxWypozyczenie = new QCheckBox();
        boxWypozyczenie->setStyleSheet("margin-left:25%");
        listaBoxWypozyczenie.append(boxWypozyczenie);
        ui->tableWidgetWyszukajWypozyczone->setCellWidget(i,8, listaBoxWypozyczenie.value(i));
    }
}
