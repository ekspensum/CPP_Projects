#include "uzytkownicy.h"

int Uzytkownicy::getIdUzytkownika() const
{
    return idUzytkownika;
}

QString Uzytkownicy::getLogin() const
{
    return login;
}

QString Uzytkownicy::getImie() const
{
    return imie;
}

QString Uzytkownicy::getNazwisko() const
{
    return nazwisko;
}

QString Uzytkownicy::getTelefon() const
{
    return telefon;
}

Uzytkownicy::Uzytkownicy()
{

}

Uzytkownicy::Uzytkownicy(int idUzytkownika, QString login, QString imie, QString nazwisko, QString telefon)
{
    this->idUzytkownika = idUzytkownika;
    this->login = login;
    this->imie = imie;
    this->nazwisko = nazwisko;
    this->telefon = telefon;
}
