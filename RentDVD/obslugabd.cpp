#include "obslugabd.h"

//QString idZalogowanyUzytkownik; //zmienna globalna

QString ObslugaBD::idZalogowanyUzytkownik; //zmienna statyczna

ObslugaBD::ObslugaBD()
{
    baza = QSqlDatabase::addDatabase("QSQLITE");
    baza.setDatabaseName(sciezkaDoBazy);
    if (!baza.open())
        qDebug()<< "Błąd połączenia z bazą danych";
    else
        qDebug()<< "Połączenie OK";
}

ObslugaBD::~ObslugaBD()
{
    if (baza.isOpen())
        baza.close();
    qDebug() << "zamykam baze";
}

bool ObslugaBD::logowanie(QString &login, QString &haslo)
{
    bool zalogowano = false;
    QByteArray hasloByteArray;
    QString hasloHash = QString(QCryptographicHash::hash(hasloByteArray.append(haslo), QCryptographicHash::Md5).toHex());
    QString idUzytkownikaBaza, loginBaza, hasloBaza;
    QSqlQuery query;
    query.exec("SELECT idUzytkownika, login, haslo FROM uzytkownicy");
    while (query.next())
    {
       idUzytkownikaBaza = query.value(0).toString();
       loginBaza = query.value(1).toString();
       hasloBaza = query.value(2).toString();
       qDebug() << idUzytkownikaBaza << loginBaza << hasloBaza << endl;
       if (login == loginBaza && hasloHash == hasloBaza)
       {
           idZalogowanyUzytkownik = idUzytkownikaBaza;
           zalogowano = true;
           break;
       }
    }
    qDebug() << "Zalogowany" << idZalogowanyUzytkownik;

    return zalogowano;
}

bool ObslugaBD::dodajUzytkownika(QString &login, QString &haslo, QString &imie, QString &nazwisko)
{
    bool dodano = false;
    QByteArray hasloByteArray;
    QString hasloHash = QString(QCryptographicHash::hash(hasloByteArray.append(haslo), QCryptographicHash::Md5).toHex());
    QSqlQuery query;
    query.prepare("insert into uzytkownicy (login, haslo, imie, nazwisko, dataRejestracji) values (:login, :haslo, :imie, :nazwisko, :dataRejestracji)");
    query.bindValue(":login", login);
    query.bindValue(":haslo", hasloHash);
    query.bindValue(":imie", imie);
    query.bindValue(":nazwisko", nazwisko);
    query.bindValue(":dataRejestracji", QDateTime::currentDateTime());
    if (query.exec())
    {
        dodano = true;
        qDebug()<< hasloHash;
    }
    else
        qDebug() << "Nie udało się dodać użytkownika";

    return dodano;
}

bool ObslugaBD::dodajFilm(QString &tytul, int &rokProdukcji, QString &opis, int &iloscKopii, int &wypozyczono, int &zarezerwowano, int &gatunek1, int &gatunek2, int &gatunek3)
{
    bool dodano = false;
    QSqlQuery query;
    query.prepare("insert into filmy(tytul, rokProdukcji, opis, iloscKopii, wypozyczono, zarezerwowano, gatunek1, gatunek2, gatunek3, dataDodania) values(:tytul, :rokProdukcji, :opis, :iloscKopii, :wypozyczono, :zarezerwowano, :gatunek1, :gatunek2, :gatunek3, :dataDodania)");
    query.bindValue(":tytul", tytul);
    query.bindValue(":rokProdukcji", rokProdukcji);
    query.bindValue(":opis", opis);
    query.bindValue(":iloscKopii", iloscKopii);
    query.bindValue(":wypozyczono", wypozyczono);
    query.bindValue(":zarezerwowano", zarezerwowano);
    query.bindValue(":gatunek1", gatunek1);
    query.bindValue(":gatunek2", gatunek2);
    query.bindValue(":gatunek3", gatunek3);
    query.bindValue(":dataDodania", QDateTime::currentDateTime());
    if (query.exec())
        dodano = true;
    else
        qDebug() << "Nie udało się dodać filmu";

    return dodano;
}
