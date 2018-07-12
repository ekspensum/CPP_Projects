#ifndef UZYTKOWNICY_H
#define UZYTKOWNICY_H

#include <QString>

class Uzytkownicy
{
private:
    int idUzytkownika;
    QString login;
    QString haslo;
    QString imie;
    QString nazwisko;
    QString telefon;

public:
    Uzytkownicy();
    Uzytkownicy(int idUzytkownika, QString login, QString imie, QString nazwisko, QString telefon);
    int getIdUzytkownika() const;
    QString getLogin() const;
    QString getImie() const;
    QString getNazwisko() const;
    QString getTelefon() const;
};

#endif // UZYTKOWNICY_H
