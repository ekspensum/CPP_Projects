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

private:
    Ui::Wypozyczalnia *ui;
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
    QCheckBox *boxKlienci;
    QCheckBox **tablicaBoxKlienci;
    QCheckBox *boxFilmy;
    QCheckBox **tablicaBoxFilmy;
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

};

#endif // WYPOZYCZALNIA_H
