#ifndef REZERWACJE_H
#define REZERWACJE_H

#include "filmy.h"
#include "klienci.h"
#include <QString>
#include <QDateTime>

class Rezerwacje : public Filmy, public Klienci
{
private:
    int idRezerwacji;
    QDateTime dataRezerwacji;
    QDateTime terminRezerwacji;
    QDateTime dataOdwolaniaRezerwacji;

public:
    Rezerwacje();
    Rezerwacje(int idFilmu, QString tytul, double cenaWypozyczenia, int idKlienta, QString imie, QString nazwisko, QDateTime dataRezerwacji, QDateTime terminRezerwacji, int idRezerwacji);

    QDateTime getDataRezerwacji() const;
    QDateTime getTerminRezerwacji() const;
    QDateTime getDataOdwolaniaRezerwacji() const;
    int getIdRezerwacji() const;
};

#endif // REZERWACJE_H
