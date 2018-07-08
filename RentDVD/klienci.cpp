#include "klienci.h"

Klienci::Klienci()
{

}

Klienci::Klienci(QString imie, QString nazwisko, QString miasto, QString ulica, QString nrDomu)
{
    this->imie = imie;
    this->nazwisko = nazwisko;
    this->miasto = miasto;
    this->ulica = ulica;
    this->nrDomu = nrDomu;
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

