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
    double cenaWypozyczenia;

public:
    Filmy();
    Filmy(QString tytul, int rokProdukcji, QString nazwaGatunku, QString opis, double cenaWypozyczenia, int idFilmu);

    int getIdFilmu() const;
    QString getTytul() const;
    QString getNazwaGatunku() const;
    QString getOpis() const;
    int getRokProdukcji() const;
    double getCenaWypozyczenia() const;
};

#endif // FILMY_H
