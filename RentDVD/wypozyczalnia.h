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

private:
    Ui::Wypozyczalnia *ui;
    QCheckBox *boxWypozyczenie;
    QCheckBox *boxRezerwacja;
    QList<QCheckBox *> listaBoxWypozyczenie;
    QList<QCheckBox *> listaBoxRezerwacja;
};

#endif // WYPOZYCZALNIA_H
