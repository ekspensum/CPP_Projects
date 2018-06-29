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
    bool dodajFilm(QString &tytul, int &rokProdukcji, QString &opis, int &iloscKopii, int &gatunek1, int &gatunek2, int &gatunek3);
    bool logowanie(QString &login, QString &haslo);
    void wyszukajFilmTytulOpis(QString &tytul, QString &opis);
    void wyszukajFilmRokGatunek(int &rokProdukcji, int &gatunek);
    QStringList odczytGatunki();
    static int idZalogowanyUzytkownik;
    QStringList wyszukajTytul;
    QStringList wyszukajOpis;
    QVector<int> wyszukajRok;
    QStringList wyszukajGatunek;
    static int ileWierszy;
    static QVector<int> wyszukajIdFilmu;

signals:

public slots:

private:
    QSqlDatabase baza;
    const QString sciezkaDoBazy = "C:\\Users\\Andrzej\\Documents\\Projekty_Cpp\\_Projekty_QT\\Projekty-GitHub\\RentDVD\\rentdvd.db";

};

#endif // OBSLUGABD_H
