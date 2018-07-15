#include "filmy.h"


int Filmy::getIloscWypozyczonych() const
{
    return iloscWypozyczonych;
}

Filmy::Filmy()
{
    
}

Filmy::Filmy(QString tytul, int rokProdukcji, QString nazwaGatunku, QString opis, double cenaWypozyczenia, int idFilmu)
{
    this->tytul = tytul;
    this->rokProdukcji = rokProdukcji;
    this->nazwaGatunku = nazwaGatunku;
    this->opis = opis;
    this->cenaWypozyczenia = cenaWypozyczenia;
    this->idFilmu = idFilmu;
}

Filmy::Filmy(int idFilmu, QString tytul, int rokProdukcji, QString opis, int iloscKopii, double cenaWypozyczenia, int gatunek1, int gatunek2, int gatunek3)
{
    this->idFilmu = idFilmu;
    this->tytul = tytul;
    this->rokProdukcji = rokProdukcji;
    this->opis = opis;
    this->iloscKopii = iloscKopii;
    this->cenaWypozyczenia = cenaWypozyczenia;
    this->gatunek1 = gatunek1;
    this->gatunek2 = gatunek2;
    this->gatunek3 = gatunek3;
}

Filmy::Filmy(int iloscWypozyczonych, QString tytul, int rokProdukcji, QString nazwaGatunku, int iloscKopii, double cenaWypozyczenia)
{
    this->iloscWypozyczonych = iloscWypozyczonych;
    this->tytul = tytul;
    this->rokProdukcji = rokProdukcji;
    this->nazwaGatunku = nazwaGatunku;
    this->iloscKopii = iloscKopii;
    this->cenaWypozyczenia = cenaWypozyczenia;
}

int Filmy::getIdFilmu() const
{
    return idFilmu;
}

QString Filmy::getTytul() const
{
    return tytul;
}

QString Filmy::getNazwaGatunku() const
{
    return nazwaGatunku;
}

QString Filmy::getOpis() const
{
    return opis;
}

int Filmy::getRokProdukcji() const
{
    return rokProdukcji;
}

double Filmy::getCenaWypozyczenia() const
{
    return cenaWypozyczenia;
}

int Filmy::getIloscKopii() const
{
    return iloscKopii;
}

int Filmy::getGatunek1() const
{
    return gatunek1;
}

int Filmy::getGatunek2() const
{
    return gatunek2;
}

int Filmy::getGatunek3() const
{
    return gatunek3;
}

