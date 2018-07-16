#include "klienci.h"


int Klienci::getIloscWypozyczonych() const
{
    return iloscWypozyczonych;
}

QDateTime Klienci::getDataRejestracji() const
{
    return dataRejestracji;
}

Klienci::Klienci()
{
    
}

Klienci::Klienci(int idKlienta, QString imie, QString nazwisko, QString miasto, QString ulica, QString nrDomu)
{
    this->idKlienta = idKlienta;
    this->imie = imie;
    this->nazwisko = nazwisko;
    this->miasto = miasto;
    this->ulica = ulica;
    this->nrDomu = nrDomu;
}

Klienci::Klienci(int idKlienta, QString imie, QString nazwisko, QString kod, QString miasto, QString ulica, QString nrDomu, QString nrLokalu, QString email, QString telefon)
{
    this->idKlienta = idKlienta;
    this->imie = imie;
    this->nazwisko = nazwisko;
    this->kod = kod;
    this->miasto = miasto;
    this->ulica = ulica;
    this->nrDomu = nrDomu;
    this->nrLokalu = nrLokalu;
    this->email = email;
    this->telefon = telefon;
}

Klienci::Klienci(int iloscWypozyczonych, QString imie, QString nazwisko, QString miasto, QString email, QString telefon, QDateTime dataRejestracji)
{
    this->iloscWypozyczonych = iloscWypozyczonych;
    this->imie = imie;
    this->nazwisko = nazwisko;
    this->miasto = miasto;
    this->email = email;
    this->telefon = telefon;
    this->dataRejestracji = dataRejestracji;
}

int Klienci::getIdKlienta() const
{
    return idKlienta;
}

QString Klienci::getImie() const
{
    return imie;
}

QString Klienci::getNazwisko() const
{
    return nazwisko;
}

QString Klienci::getKod() const
{
    return kod;
}

QString Klienci::getMiasto() const
{
    return miasto;
}

QString Klienci::getUlica() const
{
    return ulica;
}

QString Klienci::getNrDomu() const
{
    return nrDomu;
}

QString Klienci::getNrLokalu() const
{
    return nrLokalu;
}

QString Klienci::getEmail() const
{
    return email;
}

QString Klienci::getTelefon() const
{
    return telefon;
}
