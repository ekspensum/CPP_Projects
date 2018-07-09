#ifndef WYPOZYCZALNIA_H
#define WYPOZYCZALNIA_H

#include <QWidget>
#include <QMessageBox>
#include <QString>
#include <QDateTime>
#include "obslugabd.h"
#include <QCheckBox>
#include <QList>

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

    void on_pushButtonDodajKlienta_2_clicked();

private:
    Ui::Wypozyczalnia *ui;
    QCheckBox *boxWypozyczenie;
    QCheckBox *boxRezerwacja;
    QCheckBox *boxKlienci;
    QList<QCheckBox *> listaBoxWypozyczenie;
    QList<QCheckBox *> listaBoxRezerwacja;
    QCheckBox **tablicaBoxWypozyczenie;
    QCheckBox **tablicaBoxRezerwacja;
    QCheckBox **tablicaBoxKlienci;
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

};

#endif // WYPOZYCZALNIA_H
