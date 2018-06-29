#include "obslugabd.h"

//QString idZalogowanyUzytkownik; //zmienna globalna

int ObslugaBD::idZalogowanyUzytkownik; //zmienna statyczna
int ObslugaBD::ileWierszy;
QVector<int> ObslugaBD::wyszukajIdFilmu;

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
    QString loginBaza, hasloBaza;
    int idUzytkownikaBaza;
    QSqlQuery query;
    query.exec("SELECT idUzytkownika, login, haslo FROM uzytkownicy");
    while (query.next())
    {
        idUzytkownikaBaza = query.value(0).toInt();
        loginBaza = query.value(1).toString();
        hasloBaza = query.value(2).toString();
        if (login == loginBaza && hasloHash == hasloBaza)
        {
            idZalogowanyUzytkownik = idUzytkownikaBaza;
            zalogowano = true;
            break;
        }
    }

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

bool ObslugaBD::dodajFilm(QString &tytul, int &rokProdukcji, QString &opis, int &iloscKopii, int &gatunek1, int &gatunek2, int &gatunek3)
{
    bool dodano = false;
    QSqlQuery query;
    query.prepare("insert into filmy(tytul, rokProdukcji, opis, iloscKopii, gatunek1, gatunek2, gatunek3, dataDodania, idUzytkownika) values(:tytul, :rokProdukcji, :opis, :iloscKopii, :gatunek1, :gatunek2, :gatunek3, :dataDodania, :idUzytkownika)");
    query.bindValue(":tytul", tytul);
    query.bindValue(":rokProdukcji", rokProdukcji);
    query.bindValue(":opis", opis);
    query.bindValue(":iloscKopii", iloscKopii);
    query.bindValue(":gatunek1", gatunek1);
    query.bindValue(":gatunek2", gatunek2);
    query.bindValue(":gatunek3", gatunek3);
    query.bindValue(":dataDodania", QDateTime::currentDateTime());
    query.bindValue(":idUzytkownika", ObslugaBD::idZalogowanyUzytkownik);
    if (query.exec())
        dodano = true;
    else
        qDebug() << "Nie udało się dodać filmu";

    return dodano;
}

QStringList ObslugaBD::odczytGatunki()
{
    QStringList listaGatunki;
    QSqlQuery query;
    query.exec("SELECT Nazwa FROM gatunki");
    while (query.next())
        listaGatunki.append(query.value(0).toString());
    listaGatunki.insert(0,"Wybierz gatunek");
    return listaGatunki;
}

void ObslugaBD::wyszukajFilmTytulOpis(QString &tytul, QString &opis)
{
    ileWierszy = 0;
    wyszukajTytul.clear();
    wyszukajRok.clear();
    wyszukajOpis.clear();
    wyszukajGatunek.clear();
    wyszukajIdFilmu.clear();
    QSqlQuery query;
    query.prepare("SELECT Tytul, RokProdukcji, Opis, Nazwa, idFilmu FROM filmy LEFT JOIN gatunki ON filmy.Gatunek1 = gatunki.idGatunku WHERE Tytul like (:tytul) AND Opis LIKE (:opis)");
    query.bindValue(":tytul", "%" + tytul + "%");
    query.bindValue(":opis", "%" + opis + "%");
    if (query.exec())
    {
        while (query.next())
        {
            wyszukajTytul.append(query.value(0).toString());
            wyszukajRok.append(query.value(1).toInt());
            wyszukajOpis.append(query.value(2).toString());
            wyszukajGatunek.append(query.value(3).toString());
            wyszukajIdFilmu.append(query.value(4).toInt());
            ileWierszy++;
        }
    }
    else
        qDebug() << "Nie udało się wyszukać filmu";
}

void ObslugaBD::wyszukajFilmRokGatunek(int &rokProdukcji, int &gatunek)
{
    ileWierszy = 0;
    wyszukajTytul.clear();
    wyszukajRok.clear();
    wyszukajOpis.clear();
    wyszukajGatunek.clear();
    wyszukajIdFilmu.clear();
    QSqlQuery query;
    query.prepare("SELECT Tytul, RokProdukcji, Opis, Gatunek1, Nazwa, idFilmu FROM filmy LEFT JOIN gatunki ON filmy.Gatunek1 = gatunki.idGatunku WHERE RokProdukcji = (:rokProdukcji) OR Gatunek1 = (:gatunek)");
    query.bindValue(":rokProdukcji", rokProdukcji);
    query.bindValue(":gatunek", gatunek);
    if (query.exec())
    {
        while (query.next())
        {
            wyszukajTytul.append(query.value(0).toString());
            wyszukajRok.append(query.value(1).toInt());
            wyszukajOpis.append(query.value(2).toString());
            wyszukajGatunek.append(query.value(4).toString());
            wyszukajIdFilmu.append(query.value(5).toInt());
            ileWierszy++;
        }
    }
    else
        qDebug() << "Nie udało się wyszukać filmu";
}
