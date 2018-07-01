#include "wypozyczalnia.h"
#include "ui_wypozyczalnia.h"

Wypozyczalnia::Wypozyczalnia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wypozyczalnia)
{
    ui->setupUi(this);
    ui->tabWidget->setTabEnabled(4, false);
    if (ObslugaBD::idZalogowanyUzytkownik == 1)
        ui->tabWidget->setTabEnabled(4, true);
    ObslugaBD bd;
    ui->comboBoxGatunek1->addItems(bd.odczytGatunki());
    ui->comboBoxGatunek2->addItems(bd.odczytGatunki());
    ui->comboBoxGatunek3->addItems(bd.odczytGatunki());
    ui->comboBoxGatunekWyszukaj->addItems(bd.odczytGatunki());
    //    ui->tabWidget->setStyleSheet("QTabWidget::pane { border: 1px solid #000033; }");
    ui->tabWidget->setStyleSheet("QTabWidget::pane > QWidget { background-color: #b8b8b8; }");
    ui->tableWidgetWyszukajFilm->setColumnWidth(0,200);
    ui->tableWidgetWyszukajFilm->setColumnWidth(1,70);
    ui->tableWidgetWyszukajFilm->setColumnWidth(2,100);
    ui->tableWidgetWyszukajFilm->setColumnWidth(3,500);
    ui->tableWidgetWyszukajFilm->setColumnWidth(4,90);
    ui->tableWidgetWyszukajFilm->setColumnWidth(5,80);

    ui->tableWidgetWyszukajKlienta->setColumnWidth(0,100);
    ui->tableWidgetWyszukajKlienta->setColumnWidth(1,120);
    ui->tableWidgetWyszukajKlienta->setColumnWidth(2,100);
    ui->tableWidgetWyszukajKlienta->setColumnWidth(3,100);
    ui->tableWidgetWyszukajKlienta->setColumnWidth(4,60);
    ui->tableWidgetWyszukajKlienta->setColumnWidth(5,90);
    ui->tableWidgetWyszukajKlienta->setColumnWidth(6,80);
    tablicaBoxWypozyczenie = new QCheckBox*[ObslugaBD::ileWierszyKlient];
    tablicaBoxRezerwacja = new QCheckBox*[ObslugaBD::ileWierszyKlient];

}

Wypozyczalnia::~Wypozyczalnia()
{
    delete ui;
    delete [] tablicaBoxWypozyczenie;
    delete [] tablicaBoxRezerwacja;
    qDebug() << "Działa destruktor";
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
    tytul = ui->lineEditTytul->text();
    rok = ui->lineEditRok->text().toInt();
    opis = ui->plainTextEditOpis->toPlainText();
    ilosckopii = ui->spinBoxIleKopii->text().toInt();
    gatunek1 = ui->comboBoxGatunek1->currentIndex();
    gatunek2 = ui->comboBoxGatunek2->currentIndex();
    gatunek3 = ui->comboBoxGatunek3->currentIndex();
    if (tytul == "" || opis == "" || rok == 0 || ilosckopii == 0 || gatunek1 == 0)
        ui->komunikatyDodajFilm->setText("Proszę uzupełnić wymagane pola forlmularza.");
    else {
        ObslugaBD bd;
        if (bd.dodajFilm(tytul, rok, opis, ilosckopii, gatunek1, gatunek2, gatunek3))
        {
            ui->komunikatyDodajFilm->setText("Dodano nowy film do bazy danych.");
            ui->lineEditTytul->clear();
            ui->lineEditRok->clear();
            ui->plainTextEditOpis->clear();
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
    ui->tableWidgetWyszukajFilm->setRowCount(bd.ileWierszyFilm);
    for(int i=0; i<bd.ileWierszyFilm; i++)
    {
        ui->tableWidgetWyszukajFilm->setItem(i,0, new QTableWidgetItem(bd.listaTytul.at(i)));
        ui->tableWidgetWyszukajFilm->setItem(i,1, new QTableWidgetItem(QString("%1").arg(bd.listaRok.at(i))));
        ui->tableWidgetWyszukajFilm->setItem(i,2, new QTableWidgetItem(bd.listaGatunek.at(i)));
        ui->tableWidgetWyszukajFilm->setItem(i,3, new QTableWidgetItem(bd.listaOpis.at(i)));
        listaBoxWypozyczenie.append(new QCheckBox());
        ui->tableWidgetWyszukajFilm->setCellWidget(i,4, listaBoxWypozyczenie.value(i));
        listaBoxRezerwacja.append(new QCheckBox());
        ui->tableWidgetWyszukajFilm->setCellWidget(i,5, listaBoxRezerwacja.value(i));
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
    ui->tableWidgetWyszukajFilm->setRowCount(bd.ileWierszyFilm);
    for(int i=0; i<bd.ileWierszyFilm; i++)
    {
        ui->tableWidgetWyszukajFilm->setItem(i,0, new QTableWidgetItem(bd.listaTytul.at(i)));
        ui->tableWidgetWyszukajFilm->setItem(i,1, new QTableWidgetItem(QString("%1").arg(bd.listaRok.at(i))));
        ui->tableWidgetWyszukajFilm->setItem(i,2, new QTableWidgetItem(bd.listaGatunek.at(i)));
        ui->tableWidgetWyszukajFilm->setItem(i,3, new QTableWidgetItem(bd.listaOpis.at(i)));
        listaBoxWypozyczenie.append(new QCheckBox());
        ui->tableWidgetWyszukajFilm->setCellWidget(i,4, listaBoxWypozyczenie.value(i));
        listaBoxRezerwacja.append(new QCheckBox());
        ui->tableWidgetWyszukajFilm->setCellWidget(i,5, listaBoxRezerwacja.value(i));
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
        ui->tableWidgetWyszukajKlienta->setItem(i,0, new QTableWidgetItem(bd.listaImie.at(i)));
        ui->tableWidgetWyszukajKlienta->setItem(i,1, new QTableWidgetItem(bd.listaNazwisko.at(i)));
        ui->tableWidgetWyszukajKlienta->setItem(i,2, new QTableWidgetItem(bd.listaMiasto.at(i)));
        ui->tableWidgetWyszukajKlienta->setItem(i,3, new QTableWidgetItem(bd.listaUlica.at(i)));
        ui->tableWidgetWyszukajKlienta->setItem(i,4, new QTableWidgetItem(bd.listaNrDomu.at(i)));
        tablicaBoxWypozyczenie[i] = new QCheckBox();
        ui->tableWidgetWyszukajKlienta->setCellWidget(i,5, tablicaBoxWypozyczenie[i]);
        tablicaBoxRezerwacja[i] = new QCheckBox();
        ui->tableWidgetWyszukajKlienta->setCellWidget(i,6, tablicaBoxRezerwacja[i]);
    }
}

void Wypozyczalnia::on_pushButtonWypozyczenie_clicked()
{
    for(int i=0; i<ObslugaBD::ileWierszyFilm; i++)
    {
        if (listaBoxWypozyczenie.value(i)->isChecked())
        {
            qDebug() << "idFilmu" << ObslugaBD::idFilmu.at(i);
        }

//        qDebug() << listaBoxRezerwacja.value(i)->isChecked() << ObslugaBD::idFilmu.at(i);

    }

    for(int i=0; i<ObslugaBD::ileWierszyKlient; i++)
    {
        if (tablicaBoxWypozyczenie[i]->isChecked())
        {
            qDebug() << "idKlienta" << ObslugaBD::idKlienta.at(i);
        }

    }


}
