#ifndef KLIENCI_H
#define KLIENCI_H

#include <QString>

class Klienci
{
protected:
    QString imie;
    QString nazwisko;
    QString miasto;
    QString ulica;
    QString nrDomu;
    int idKlienta;

public:
    Klienci();
    Klienci(QString imie, QString nazwisko, QString miasto, QString ulica, QString nrDomu);

    int getIdKlienta() const;
    QString getImie() const;
    QString getNazwisko() const;
    QString getMiasto() const;
    QString getUlica() const;
    QString getNrDomu() const;
};

#endif // KLIENCI_H
