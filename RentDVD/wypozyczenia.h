#ifndef WYPOZYCZENIA_H
#define WYPOZYCZENIA_H

#include <QString>
#include <QDateTime>
#include "filmy.h"
#include "klienci.h"

class Wypozyczenia : public Filmy , public Klienci
{
private:
    int idWypozyczenia;
    QDateTime dataWypozyczenia;
    QDateTime planowaDataZwrotu;
    QDateTime dataZwrotu;

public:
    Wypozyczenia();
    Wypozyczenia(int idFilmu, QString tytul, double cenaWypozyczenia, int idKlienta, QString imie, QString nazwisko, QDateTime dataWypozyczenia, QDateTime planowaDataZwrotu, int idWypozyczenia);

    QDateTime getDataWypozyczenia() const;
    QDateTime getPlanowaDataZwrotu() const;
    QDateTime getDataZwrotu() const;
    int getIdWypozyczenia() const;
};

#endif // WYPOZYCZENIA_H
