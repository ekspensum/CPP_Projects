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
#include "wypozyczenia.h"


class ObslugaBD
{

public:
    ObslugaBD();
    ~ObslugaBD();
    bool dodajUzytkownika(QString &login, QString &haslo, QString &imie, QString &nazwisko);
    bool dodajKlienta(QString &imie, QString &nazwisko, QString &kodPocztowy, QString &miasto, QString &ulica, QString &nrDomu, QString &nrLokalu);
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
    QStringList odczytGatunki();

    static int idZalogowanyUzytkownik;
    static int ileWierszyFilm;
    static int ileWierszyKlient;
    static int ileWierszyWypozyczone;
    static QVector<int> idFilmuVector;
    static QVector<int> idKlientaVector;

    Filmy *filmy;
    QList<Filmy *> listaFilmy;
    Klienci *klienci;
    QList<Klienci *> listaKlienci;
    Wypozyczenia *wypozyczenia;
    QList<Wypozyczenia *> listaWypozyczenia;



signals:

public slots:

private:
    QSqlDatabase baza;
//    const QString sciezkaDoBazy = "C:\\Users\\Andrzej\\Documents\\Projekty_Cpp\\_Projekty_QT\\Projekty-GitHub\\RentDVD\\rentdvd.db";

};

#endif // OBSLUGABD_H
