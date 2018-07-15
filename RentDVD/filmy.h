#ifndef FILMY_H
#define FILMY_H

#include <QString>

class Filmy
{
protected:
    QString tytul;
    QString nazwaGatunku;
    QString opis;
    int idFilmu;
    int rokProdukcji;
    int iloscKopii;
    int gatunek1;
    int gatunek2;
    int gatunek3;
    double cenaWypozyczenia;
    int iloscWypozyczonych;

public:
    Filmy();
    Filmy(QString tytul, int rokProdukcji, QString nazwaGatunku, QString opis, double cenaWypozyczenia, int idFilmu);
    Filmy(int idFilmu, QString tytul, int rokProdukcji, QString opis, int iloscKopii, double cenaWypozyczenia, int gatunek1, int gatunek2, int gatunek3);
    Filmy(int iloscWypozyczonych, QString tytul, int rokProdukcji, QString nazwaGatunku, int iloscKopii, double cenaWypozyczenia);

    int getIdFilmu() const;
    QString getTytul() const;
    QString getNazwaGatunku() const;
    QString getOpis() const;
    int getRokProdukcji() const;
    double getCenaWypozyczenia() const;
    int getIloscKopii() const;
    int getGatunek1() const;
    int getGatunek2() const;
    int getGatunek3() const;
    int getIloscWypozyczonych() const;
};

#endif // FILMY_H
