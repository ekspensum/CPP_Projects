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


class ObslugaBD
{

public:
    ObslugaBD();
    ~ObslugaBD();
    bool dodajUzytkownika(QString &login, QString &haslo, QString &imie, QString &nazwisko);
    bool dodajKlienta(QString &imie, QString &nazwisko, QString &kodPocztowy, QString &miasto, QString &ulica, QString &nrDomu, QString &nrLokalu);
    bool dodajFilm(QString &tytul, int &rokProdukcji, QString &opis, int &iloscKopii, int &gatunek1, int &gatunek2, int &gatunek3);
    bool logowanie(QString &login, QString &haslo);
    void wyszukajFilmTytulOpis(QString &tytul, QString &opis);
    void wyszukajFilmRokGatunek(int &rokProdukcji, int &gatunek);
    void wyszukajKlienta(QString &imie, QString &nazwisko, QString &miasto, QString &ulica);
    QStringList odczytGatunki();
    static int idZalogowanyUzytkownik;
    QStringList listaTytul;
    QStringList listaOpis;
    QVector<int> listaRok;
    QStringList listaGatunek;
    static int ileWierszyFilm;
    static int ileWierszyKlient;
    static QVector<int> idFilmu;
    static QVector<int> idKlienta;
    QStringList listaImie;
    QStringList listaNazwisko;
    QStringList listaMiasto;
    QStringList listaUlica;
    QStringList listaNrDomu;

signals:

public slots:

private:
    QSqlDatabase baza;
    const QString sciezkaDoBazy = "C:\\Users\\Andrzej\\Documents\\Projekty_Cpp\\_Projekty_QT\\Projekty-GitHub\\RentDVD\\rentdvd.db";

};

#endif // OBSLUGABD_H
