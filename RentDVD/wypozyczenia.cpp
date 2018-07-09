#include "wypozyczenia.h"

QDateTime Wypozyczenia::getDataWypozyczenia() const
{
    return dataWypozyczenia;
}

QDateTime Wypozyczenia::getPlanowaDataZwrotu() const
{
    return planowaDataZwrotu;
}

QDateTime Wypozyczenia::getDataZwrotu() const
{
    return dataZwrotu;
}

int Wypozyczenia::getIdWypozyczenia() const
{
    return idWypozyczenia;
}

Wypozyczenia::Wypozyczenia()
{

}

Wypozyczenia::Wypozyczenia(int idFilmu, QString tytul, double cenaWypozyczenia, int idKlienta, QString imie, QString nazwisko, QDateTime dataWypozyczenia, QDateTime planowaDataZwrotu, int idWypozyczenia)
{
    this->idFilmu = idFilmu;
    this->tytul = tytul;
    this->cenaWypozyczenia = cenaWypozyczenia;
    this->idKlienta = idKlienta;
    this->imie = imie;
    this->nazwisko = nazwisko;
    this->dataWypozyczenia = dataWypozyczenia;
    this->planowaDataZwrotu = planowaDataZwrotu;
    this->idWypozyczenia = idWypozyczenia;
}
