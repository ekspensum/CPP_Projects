#ifndef WYPOZYCZALNIA_H
#define WYPOZYCZALNIA_H

#include <QWidget>
#include <QMessageBox>
#include <QString>
#include <QDateTime>
#include "obslugabd.h"
#include <QCheckBox>
#include <QList>
#include <QComboBox>

namespace Ui {
class Wypozyczalnia;
}

class Wypozyczalnia : public QWidget
{
    Q_OBJECT

public:
    explicit Wypozyczalnia(QWidget *parent = 0);
    ~Wypozyczalnia();

private slots:
    void on_pushButtonDodajUzytkownika_clicked();

    void on_pushButtonDodajFilm_clicked();

    void on_pushButtonWyszukajRokGatunek_clicked();

    void on_pushButtonWyszukajTytulOpis_clicked();

    void on_pushButtonDodajKlienta_clicked();

    void on_pushButtonWyszukajKlienta_clicked();

    void on_pushButtonRezerwacja_clicked();

    void on_pushButtonWypozyczenie_clicked();

    void on_pushButtonWyszukajWypozyczoneKlientFilm_clicked();

    void on_lineEditNazwiskoWyszukajZwrot_textChanged(const QString &nazwisko);

    void on_pushButtonZwrot_clicked();

    void on_pushButtonWyszukajZarezerwowaneKlientFilm_clicked();

    void on_lineEditNazwiskoWyszukajZarezerwowane_textChanged(const QString &nazwisko);

    void on_pushButtonOdwolanie_clicked();

    void on_lineEditNazwiskoWyszukajEdytuj_textChanged(const QString &nazwisko);

    void on_pushButtonEdytujKlienta_clicked();

    void on_lineEditTytulWyszukajEdytuj_textChanged(const QString &tytul);

    void on_pushButtonEdytujFilm_clicked();

    void on_lineEditNazwiskolWyszukajEdytuj_textChanged(const QString &nazwisko);

    void on_pushButtonEdytujUzytkownika_clicked();

    void on_pushButtonZmienHaslo_clicked();

    void on_tabWidget_tabBarClicked(int index);

    void on_pushButtonGatunekDodaj_clicked();

    void on_pushButtonGatunekUsun_clicked();

    void on_pushButtonGatunkiEdytuj_clicked();

private:
    Ui::Wypozyczalnia *ui;
    ObslugaBD *bd;
    QCheckBox *boxFilmy;
    QCheckBox *boxKlienci;
    QCheckBox *boxUzytkownicy;
    QCheckBox *boxWypozyczenie;
    QCheckBox *boxRezerwacja;
    QComboBox *comboGatunek1;
    QComboBox *comboGatunek2;
    QComboBox *comboGatunek3;
    QList<QCheckBox *> listaBoxWypozyczenieFilmy;
    QList<QCheckBox *> listaBoxRezerwacjaFilmy;
    QList<QCheckBox *> listaBoxWypozyczenieKlienci;
    QList<QCheckBox *> listaBoxRezerwacjaKlienci;
    QList<QCheckBox *> listaBoxWypozyczenie;
    QList<QCheckBox *> listaBoxRezerwacja;
    QDateTime planowaDataZwrotu;
    QDateTime czasRezerwacji;
    QPalette p;
    QMessageBox jedenFilmWypozycz;
    QMessageBox jedenFilmRezerwuj;
    QMessageBox jedenFilmZwrot;
    QMessageBox jedenFilmOdwolaj;
    QMessageBox jedenKlientWypozycz;
    QMessageBox jedenKlientRezerwuj;
    QMessageBox jedenKlientEdytuj;
    QMessageBox jedenFilmEdytuj;
    QMessageBox jedenUzytkownikEdytuj;
    QMessageBox zmianaHaslaUzytkownik;
};

#endif // WYPOZYCZALNIA_H
