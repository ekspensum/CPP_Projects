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
    ui->tableWidgetWyszukaj->setColumnWidth(0,200);
    ui->tableWidgetWyszukaj->setColumnWidth(1,70);
    ui->tableWidgetWyszukaj->setColumnWidth(2,100);
    ui->tableWidgetWyszukaj->setColumnWidth(3,500);
    ui->tableWidgetWyszukaj->setColumnWidth(4,90);
    ui->tableWidgetWyszukaj->setColumnWidth(5,80);


}

Wypozyczalnia::~Wypozyczalnia()
{
    delete ui;
}

void Wypozyczalnia::on_pushButtonDodajUzytkownika_clicked()
{
    QString login, haslo, imie, nazwisko;
    login = ui->lineEditLogin->text();
    haslo = ui->lineEditHaslo->text();
    imie = ui->lineEditImie->text();
    nazwisko = ui->lineEditNazwisko->text();
    if(login == "" || haslo == "" || imie == "" || nazwisko == "")
        ui->komunikatyDodajUzytkownika->setText("Proszę uzupełnić wszystkie pola forlmularza.");
    else
    {
        ObslugaBD bd;
        if (bd.dodajUzytkownika(login, haslo, imie, nazwisko))
            ui->komunikatyDodajUzytkownika->setText("Dodano nowego użytkownika do bazy danych.");
        else
            ui->komunikatyDodajUzytkownika->setText("Błąd: nie udało się dodać użytkownika do bazy danych.");
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
        ui->komunikatyDodajFilm->setText("Proszę uzupełnić wszystkie pola forlmularza.");
    else {
        ObslugaBD bd;
        if (bd.dodajFilm(tytul, rok, opis, ilosckopii, gatunek1, gatunek2, gatunek3))
            ui->komunikatyDodajFilm->setText("Dodano nowy film do bazy danych.");
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
    ui->tableWidgetWyszukaj->setRowCount(bd.ileWierszy);
    for(int i=0; i<bd.ileWierszy; i++)
    {
        ui->tableWidgetWyszukaj->setItem(i,0, new QTableWidgetItem(bd.wyszukajTytul.at(i)));
        ui->tableWidgetWyszukaj->setItem(i,1, new QTableWidgetItem(QString("%1").arg(bd.wyszukajRok.at(i))));
        ui->tableWidgetWyszukaj->setItem(i,2, new QTableWidgetItem(bd.wyszukajGatunek.at(i)));
        ui->tableWidgetWyszukaj->setItem(i,3, new QTableWidgetItem(bd.wyszukajOpis.at(i)));
        listaBoxWypozyczenie.append(new QCheckBox);
        ui->tableWidgetWyszukaj->setCellWidget(i,4, listaBoxWypozyczenie.value(i));
        listaBoxRezerwacja.append(new QCheckBox());
        ui->tableWidgetWyszukaj->setCellWidget(i,5, listaBoxRezerwacja.value(i));
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
    ui->tableWidgetWyszukaj->setRowCount(bd.ileWierszy);
    for(int i=0; i<bd.ileWierszy; i++)
    {
        ui->tableWidgetWyszukaj->setItem(i,0, new QTableWidgetItem(bd.wyszukajTytul.at(i)));
        ui->tableWidgetWyszukaj->setItem(i,1, new QTableWidgetItem(QString("%1").arg(bd.wyszukajRok.at(i))));
        ui->tableWidgetWyszukaj->setItem(i,2, new QTableWidgetItem(bd.wyszukajGatunek.at(i)));
        ui->tableWidgetWyszukaj->setItem(i,3, new QTableWidgetItem(bd.wyszukajOpis.at(i)));
        listaBoxWypozyczenie.append(new QCheckBox);
        ui->tableWidgetWyszukaj->setCellWidget(i,4, listaBoxWypozyczenie.value(i));
        listaBoxRezerwacja.append(new QCheckBox());
        ui->tableWidgetWyszukaj->setCellWidget(i,5, listaBoxRezerwacja.value(i));
    }
}

void Wypozyczalnia::on_pushButtonWypozyczenie_clicked()
{
    for(int i=0; i<ObslugaBD::ileWierszy; i++)
    {
        if (listaBoxWypozyczenie.value(i)->isChecked())
        {
            qDebug() << ObslugaBD::wyszukajIdFilmu.at(i);
        }

//        qDebug() << listaBoxRezerwacja.value(i)->isChecked() << ObslugaBD::wyszukajIdFilmu.at(i);

    }
}
