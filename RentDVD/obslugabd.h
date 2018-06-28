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
    QStringList odczytGatunki();
    static int idZalogowanyUzytkownik;

signals:

public slots:

private:
    QSqlDatabase baza;
    const QString sciezkaDoBazy = "C:\\Users\\Andrzej\\Documents\\Projekty_Cpp\\_Projekty_QT\\Projekty-GitHub\\RentDVD\\rentdvd.db";

};

#endif // OBSLUGABD_H
