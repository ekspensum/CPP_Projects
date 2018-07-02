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

    void on_pushButtonWypozyczenie_clicked();

    void on_pushButtonDodajKlienta_clicked();

    void on_pushButtonWyszukajKlienta_clicked();

    void on_pushButtonRezerwacja_clicked();

private:
    Ui::Wypozyczalnia *ui;
//    QCheckBox *boxWypozyczenie = new QCheckBox();
//    QCheckBox *boxRezerwacja = new QCheckBox();
    QList<QCheckBox *> listaBoxWypozyczenie;
    QList<QCheckBox *> listaBoxRezerwacja;
    QCheckBox **tablicaBoxWypozyczenie;
    QCheckBox **tablicaBoxRezerwacja;
    QDateTime planowaDataZwrotu;
    QDateTime czasRezerwacji;
    QPalette p;
    QMessageBox jedenFilm;
    QMessageBox jedenKlient;
};

#endif // WYPOZYCZALNIA_H
