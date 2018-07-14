#ifndef KLIENCI_H
#define KLIENCI_H

#include <QString>

class Klienci
{
protected:
    int idKlienta;
    QString imie;
    QString nazwisko;
    QString kod;
    QString miasto;
    QString ulica;
    QString nrDomu;
    QString nrLokalu;
    QString email;
    QString telefon;

public:
    Klienci();
    Klienci(int idKlienta, QString imie, QString nazwisko, QString miasto, QString ulica, QString nrDomu);
    Klienci(int idKlienta, QString imie, QString nazwisko, QString kod, QString miasto, QString ulica, QString nrDomu, QString nrLokalu, QString email, QString telefon);

    int getIdKlienta() const;
    QString getImie() const;
    QString getNazwisko() const;
    QString getKod() const;
    QString getMiasto() const;
    QString getUlica() const;
    QString getNrDomu() const;
    QString getNrLokalu() const;
    QString getEmail() const;
    QString getTelefon() const;
};

#endif // KLIENCI_H
