#ifndef KLIENCI_H
#define KLIENCI_H

#include <QString>
#include <QDateTime>

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
    int iloscWypozyczonych;
    QDateTime dataRejestracji;

public:
    Klienci();
    Klienci(int idKlienta, QString imie, QString nazwisko, QString miasto, QString ulica, QString nrDomu);
    Klienci(int idKlienta, QString imie, QString nazwisko, QString kod, QString miasto, QString ulica, QString nrDomu, QString nrLokalu, QString email, QString telefon);
    Klienci(int iloscWypozyczonych, QString imie, QString nazwisko, QString miasto, QString email, QString telefon, QDateTime dataRejestracji);

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
    int getIloscWypozyczonych() const;
    QDateTime getDataRejestracji() const;
};

#endif // KLIENCI_H
