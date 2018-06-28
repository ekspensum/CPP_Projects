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
    ObslugaBD bd;
    if (bd.dodajUzytkownika(login, haslo, imie, nazwisko))
        ui->komunikatyDodajUzytkownika->setText("Dodano nowego użytkownika do bazy danych.");
    else
        ui->komunikatyDodajUzytkownika->setText("Błąd: nie udało się dodać użytkownika do bazy danych.");
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
    ObslugaBD bd;
    if (bd.dodajFilm(tytul, rok, opis, ilosckopii, gatunek1, gatunek2, gatunek3))
        ui->komunikatyDodajFilm->setText("Dodano nowy film do bazy danych.");
    else
        ui->komunikatyDodajFilm->setText("Błąd: nie udało się dodać filmu do bazy danych.");
}
