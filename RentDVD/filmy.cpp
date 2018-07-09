#include "filmy.h"


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


