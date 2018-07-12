#ifndef OBSLUGABD_H
#define OBSLUGABD_H

#include <QString>
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QCryptographicHash>
#include <QByteArray>
#include <QStringList>
#include <QDir>
#include <QList>
#include "klienci.h"
#include "filmy.h"
#include "uzytkownicy.h"
#include "wypozyczenia.h"
#include "rezerwacje.h"


class ObslugaBD
{

public:
    ObslugaBD();
    ~ObslugaBD();
    bool dodajUzytkownika(QString &login, QString &haslo, QString &imie, QString &nazwisko);
    bool dodajKlienta(QString &imie, QString &nazwisko, QString &kodPocztowy, QString &miasto, QString &ulica, QString &nrDomu, QString &nrLokalu, QString &email);
    bool dodajFilm(QString &tytul, int &rokProdukcji, QString &opis, double &cenaWypozyczenia, int &iloscKopii, int &gatunek1, int &gatunek2, int &gatunek3);
    bool logowanie(QString &login, QString &haslo);
    void wyszukajFilmTytulOpis(QString &tytul, QString &opis);
    void wyszukajFilmRokGatunek(int &rokProdukcji, int &gatunek);
    void wyszukajKlienta(QString &imie, QString &nazwisko, QString &miasto, QString &ulica);
    bool czyMozliwaRezerwacjaWypozyczenie(int &idFilmu); // sprawdza czy zakupiona ilość kopii filmu > od sumy istniejących wypożyczeń i rezerwacji
    bool wykonajRezerwacje(int &idKlienta, int &idFilmu, QDateTime &terminRezerwacji);
    bool wykonajWypozyczenie(int &idKlienta, int &idFilmu, QDateTime &planowaDataZwrotu);
    void wyszukajWypozyczoneFilmyIdFilmuIdKlienta(int &idFilmu, int &idKlienta);
    void wyszukajWypozyczoneFilmyNazwisko(const QString &nazwisko);
    bool wykonajZwrotFilmu(int &idWypozyczenia);
    void wyszukajRezerwacjeFilmyIdFilmuIdKlienta(int &idFilmu, int &idKlienta);
    void wyszukajRezerwacjeFilmyNazwisko(const QString &nazwisko);
    bool wykonajOdwolanieRezerwacji(int &idRezerwacji);
    void wyszukajKlienta(const QString &nazwisko);
    bool wykonajEdycjeKlienta(int &idKlienta, QString &imie, QString &nazwisko, QString &kod, QString &miasto, QString &ulica, QString &nrDomu, QString &nrLokalu, QString &email);
    void wyszukajFilm(const QString &tytul);
    bool wykonajEdycjeFilmu(int &idFilmu, QString &tytul, int &rokProdukcji, QString &opis, int &iloscKopii, double &cenaWypozyczenia, int &gatunek1, int &gatunek2, int &gatunek3);
    void wyszukajUzytkownika(const QString &nazwisko);
    bool wykonajEdycjeUzytkownika(int &idUzytkownika, QString login, QString &imie, QString &nazwisko, QString &telefon);
    QStringList odczytGatunki();
    QList<Filmy *> getListaFilmy() const;
    QList<Klienci *> getListaKlienci() const;
    QList<Filmy *> getListaFilmyEdycja() const;
    QList<Klienci *> getListaKlienciEdycja() const;
    QList<Wypozyczenia *> getListaWypozyczenia() const;
    QList<Rezerwacje *> getListaRezerwacje() const;
    QList<Uzytkownicy *> getListaUzytkownicy() const;
    static int idZalogowanyUzytkownik;

signals:

public slots:

private:
    QSqlDatabase baza;
//    const QString sciezkaDoBazy = "C:\\Users\\Andrzej\\Documents\\Projekty_Cpp\\_Projekty_QT\\Projekty-GitHub\\RentDVD\\rentdvd.db";
    QStringList listaGatunki;
    Filmy *filmy;
    Klienci *klienci;
    Uzytkownicy *uzytkownicy;
    Wypozyczenia *wypozyczenia;
    Rezerwacje *rezerwacje;
    QList<Filmy *> listaFilmy;
    QList<Klienci *> listaKlienci;
    QList<Filmy *> listaFilmyEdycja;
    QList<Klienci *> listaKlienciEdycja;
    QList<Uzytkownicy *> listaUzytkownicy;
    QList<Wypozyczenia *> listaWypozyczenia;
    QList<Rezerwacje *> listaRezerwacje;
};

#endif // OBSLUGABD_H
