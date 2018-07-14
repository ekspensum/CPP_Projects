#include "klienci.h"


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
