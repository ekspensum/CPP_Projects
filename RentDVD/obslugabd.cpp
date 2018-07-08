#include "obslugabd.h"

//QString idZalogowanyUzytkownik; //zmienna globalna

int ObslugaBD::idZalogowanyUzytkownik; //zmienna statyczna
int ObslugaBD::ileWierszyFilm;
int ObslugaBD::ileWierszyKlient;
int ObslugaBD::ileWierszyWypozyczone;
int ObslugaBD::ileWierszyRezerwacja;
QVector<int> ObslugaBD::idFilmuVector;
QVector<int> ObslugaBD::idKlientaVector;
QVector<int> ObslugaBD::idWypozyczeniaVector;
QVector<int> ObslugaBD::idRezerwacjiVector;

ObslugaBD::ObslugaBD()
{
    QString sciezkaDoBazy = QDir::currentPath();
    sciezkaDoBazy = sciezkaDoBazy + "/rentdvd.db";
    baza = QSqlDatabase::addDatabase("QSQLITE");
//    qDebug() << sciezkaDoBazy;
    baza.setDatabaseName(sciezkaDoBazy);
//    baza.open();
    if (!baza.open())
        qDebug()<< "Błąd połączenia z bazą danych";
    else
        qDebug()<< "Połączenie OK";
}

ObslugaBD::~ObslugaBD()
{
    if (baza.isOpen())
        baza.close();
    qDebug() << "zamykam połączenie z bazą";
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

bool ObslugaBD::dodajKlienta(QString &imie, QString &nazwisko, QString &kodPocztowy, QString &miasto, QString &ulica, QString &nrDomu, QString &nrLokalu)
{
    bool dodano = false;
    QSqlQuery query;
    query.prepare("insert into klienci (imie, nazwisko, kod, miasto, ulica, nrDomu, nrLokalu, dataRejestracji, idUzytkownika) values (:imie, :nazwisko, :kodPocztowy, :miasto, :ulica, :nrDomu, :nrLokalu, :dataRejestracji, :idUzytkownika)");
    query.bindValue(":imie", imie);
    query.bindValue(":nazwisko", nazwisko);
    query.bindValue(":kodPocztowy", kodPocztowy);
    query.bindValue(":miasto", miasto);
    query.bindValue(":ulica", ulica);
    query.bindValue(":nrDomu", nrDomu);
    query.bindValue(":nrLokalu", nrLokalu);
    query.bindValue(":dataRejestracji", QDateTime::currentDateTime());
    query.bindValue(":idUzytkownika", ObslugaBD::idZalogowanyUzytkownik);
    if (query.exec())
        dodano = true;
    else
        qDebug() << "Nie udało się dodać użytkownika";

    return dodano;
}

bool ObslugaBD::dodajFilm(QString &tytul, int &rokProdukcji, QString &opis, double &cenaWypozyczenia, int &iloscKopii, int &gatunek1, int &gatunek2, int &gatunek3)
{
    bool dodano = false;
    QSqlQuery query;
    query.prepare("insert into filmy(tytul, rokProdukcji, opis, cenaWypozyczenia, iloscKopii, gatunek1, gatunek2, gatunek3, dataDodania, idUzytkownika) values(:tytul, :rokProdukcji, :opis, :cenaWypozyczenia, :iloscKopii, :gatunek1, :gatunek2, :gatunek3, :dataDodania, :idUzytkownika)");
    query.bindValue(":tytul", tytul);
    query.bindValue(":rokProdukcji", rokProdukcji);
    query.bindValue(":opis", opis);
    query.bindValue(":cenaWypozyczenia", cenaWypozyczenia);
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
    ileWierszyFilm = 0;
    listaFilmy.clear();
    idFilmuVector.clear();
    QSqlQuery query;
    query.prepare("SELECT tytul, rokProdukcji, nazwa, opis, cenaWypozyczenia, idFilmu FROM filmy LEFT JOIN gatunki ON filmy.Gatunek1 = gatunki.idGatunku WHERE Tytul like (:tytul) AND Opis LIKE (:opis)");
    query.bindValue(":tytul", "%" + tytul + "%");
    query.bindValue(":opis", "%" + opis + "%");
    if (query.exec())
    {
        while (query.next())
        {
            filmy = new Filmy(query.value(0).toString(), query.value(1).toInt(), query.value(2).toString(), query.value(3).toString(), query.value(4).toDouble());
            listaFilmy.append(filmy);
            idFilmuVector.append(query.value(5).toInt());
            ileWierszyFilm++;
        }
    }
    else
        qDebug() << "Nie udało się wyszukać filmu";
}

void ObslugaBD::wyszukajFilmRokGatunek(int &rokProdukcji, int &gatunek)
{
    ileWierszyFilm = 0;
    listaFilmy.clear();
    idFilmuVector.clear();
    QSqlQuery query;
    query.prepare("SELECT tytul, rokProdukcji, nazwa, opis, cenaWypozyczenia, idFilmu FROM filmy LEFT JOIN gatunki ON filmy.Gatunek1 = gatunki.idGatunku WHERE RokProdukcji = (:rokProdukcji) OR Gatunek1 = (:gatunek)");
    query.bindValue(":rokProdukcji", rokProdukcji);
    query.bindValue(":gatunek", gatunek);
    if (query.exec())
    {
        while (query.next())
        {
            filmy = new Filmy(query.value(0).toString(), query.value(1).toInt(), query.value(2).toString(), query.value(3).toString(), query.value(4).toDouble());
            listaFilmy.append(filmy);
            idFilmuVector.append(query.value(5).toInt());
            ileWierszyFilm++;
        }
    }
    else
        qDebug() << "Nie udało się wyszukać filmu";
}

void ObslugaBD::wyszukajKlienta(QString &imie, QString &nazwisko, QString &miasto, QString &ulica)
{
    ileWierszyKlient = 0;
    idKlientaVector.clear();
    listaKlienci.clear();
    QSqlQuery query;
    query.prepare("SELECT idKlienta, Imie, Nazwisko, Miasto, Ulica, nrDomu FROM klienci WHERE Imie LIKE (:imie) AND Nazwisko LIKE (:nazwisko) AND Miasto LIKE (:miasto) AND Ulica LIKE (:ulica)");
    query.bindValue(":imie", "%" + imie + "%");
    query.bindValue(":nazwisko", "%" + nazwisko + "%");
    query.bindValue(":miasto", "%" + miasto + "%");
    query.bindValue(":ulica", "%" + ulica + "%");
    if (query.exec())
    {
        while (query.next())
        {
            idKlientaVector.append(query.value(0).toInt());
            klienci = new Klienci(query.value(1).toString(), query.value(2).toString(), query.value(3).toString(), query.value(4).toString(), query.value(5).toString());
            listaKlienci.append(klienci);
            ileWierszyKlient++;
        }
    }
    else
        qDebug() << "Nie udało się wyszukać klienta";
}

bool ObslugaBD::czyMozliwaRezerwacjaWypozyczenie(int &idFilmu)
{
    bool sprawdzenie = false;
    int ileKopii, ileRezerwacji, ileWypozyczen;
    QSqlQuery query1;
    query1.prepare("SELECT COUNT(filmy.idFilmu) as ileFilmow FROM filmy LEFT JOIN rezerwacje ON rezerwacje.idFilmu = filmy.idFilmu WHERE filmy.idFilmu = (:idFilmu) AND ((:dateTimeNow) BETWEEN dataRezerwacji AND terminRezerwacji OR terminRezerwacji IS NULL) AND odwolanieRezerwacji IS NULL");
    query1.bindValue(":idFilmu", idFilmu);
    query1.bindValue(":dateTimeNow", QDateTime::currentDateTime());
    QSqlQuery query2;
    query2.prepare("SELECT COUNT(filmy.idFilmu) as ileFilmow FROM filmy LEFT JOIN wypozyczenia ON wypozyczenia.idFilmu = filmy.idFilmu WHERE filmy.idFilmu = (:idFilmu) AND dataWypozyczenia IS NOT NULL AND dataZwrotu IS NULL");
    query2.bindValue(":idFilmu", idFilmu);
    QSqlQuery query3;
    query3.prepare("SELECT iloscKopii FROM filmy WHERE idFilmu = (:idFilmu)");
    query3.bindValue(":idFilmu", idFilmu);
    if (query1.exec() && query2.exec() && query3.exec())
    {
        query1.next();
        ileRezerwacji = query1.value(0).toInt();
        query2.next();
        ileWypozyczen = query2.value(0).toInt();
        query3.next();
        ileKopii =  query3.value(0).toInt();
        if (ileKopii > (ileRezerwacji + ileWypozyczen))
        {
            sprawdzenie = true;
            qDebug() << "Wykonano sprawdzenie możliwości wypożyczenie lub rezerwacji.";
        }
    }
    else
        qDebug() << "Nie udało się wykonać kweredny sprawdzenia możliwości wypożyczenie lub rezerwacji.";
    return sprawdzenie;
}

bool ObslugaBD::wykonajRezerwacje(int &idKlienta, int &idFilmu, QDateTime &terminRezerwacji)
{
    bool wykonano = false;
    QSqlQuery query;
    query.prepare("INSERT INTO rezerwacje (DataRezerwacji, TerminRezerwacji, idKlienta, idFilmu, idUzytkownikaRezerwacja) VALUES (:DataRezerwacji, :TerminRezerwacji, :idKlienta, :idFilmu, :idUzytkownikaRezerwacja)");
    query.bindValue(":DataRezerwacji", QDateTime::currentDateTime());
    query.bindValue(":TerminRezerwacji", terminRezerwacji);
    query.bindValue(":idKlienta", idKlienta);
    query.bindValue(":idFilmu", idFilmu);
    query.bindValue(":idUzytkownikaRezerwacja", ObslugaBD::idZalogowanyUzytkownik);
    if (query.exec())
        wykonano = true;
    return wykonano;
}

bool ObslugaBD::wykonajWypozyczenie(int &idKlienta, int &idFilmu, QDateTime &planowaDataZwrotu)
{
    bool wykonano = false;
    QSqlQuery query;
    query.prepare("INSERT INTO wypozyczenia (dataWypozyczenia, planowaDataZwrotu, idKlienta, idFilmu, idUzytkownikaWypozyczenie) VALUES (:dataWypozyczenia, :planowaDataZwrotu, :idKlienta, :idFilmu, :idUzytkownikaWypozyczenie)");
    query.bindValue(":dataWypozyczenia", QDateTime::currentDateTime());
    query.bindValue(":planowaDataZwrotu", planowaDataZwrotu);
    query.bindValue(":idKlienta", idKlienta);
    query.bindValue(":idFilmu", idFilmu);
    query.bindValue(":idUzytkownikaWypozyczenie", ObslugaBD::idZalogowanyUzytkownik);
    if (query.exec())
        wykonano = true;
    return wykonano;
}

void ObslugaBD::wyszukajWypozyczoneFilmyIdFilmuIdKlienta(int &idFilmu, int &idKlienta)
{
    ileWierszyWypozyczone = 0;
    listaWypozyczenia.clear();
    idWypozyczeniaVector.clear();
    QSqlQuery query;
    query.prepare("SELECT wypozyczenia.idFilmu, tytul, cenaWypozyczenia, wypozyczenia.idKlienta, imie, nazwisko, dataWypozyczenia, planowaDataZwrotu, idWypozyczenia FROM wypozyczenia LEFT JOIN klienci ON wypozyczenia.idKlienta = klienci.idKlienta LEFT JOIN filmy ON wypozyczenia.idFilmu = filmy.idFilmu WHERE dataZwrotu IS NULL AND (wypozyczenia.idFilmu = (:idFilmu) OR wypozyczenia.idKlienta = (:idKlienta)) ORDER BY wypozyczenia.idFilmu");
    query.bindValue(":idFilmu", idFilmu);
    query.bindValue(":idKlienta", idKlienta);
    if (query.exec())
    {
        while (query.next())
        {
            wypozyczenia = new Wypozyczenia(query.value(0).toInt(), query.value(1).toString(), query.value(2).toDouble(), query.value(3).toInt(), query.value(4).toString(), query.value(5).toString(), query.value(6).toDateTime(), query.value(7).toDateTime());
            listaWypozyczenia.append(wypozyczenia);
            idWypozyczeniaVector.append(query.value(8).toInt());
            ileWierszyWypozyczone++;
        }
    }
    else
        qDebug() << "Nie udało się wyszukać wypożyczonych filmów";
}

void ObslugaBD::wyszukajWypozyczoneFilmyNazwisko(const QString &nazwisko)
{
    ileWierszyWypozyczone = 0;
    listaWypozyczenia.clear();
    idWypozyczeniaVector.clear();
    QSqlQuery query;
    query.prepare("SELECT wypozyczenia.idFilmu, tytul, cenaWypozyczenia, wypozyczenia.idKlienta, imie, nazwisko, dataWypozyczenia, planowaDataZwrotu, idWypozyczenia FROM wypozyczenia LEFT JOIN klienci ON wypozyczenia.idKlienta = klienci.idKlienta LEFT JOIN filmy ON wypozyczenia.idFilmu = filmy.idFilmu WHERE dataZwrotu IS NULL AND nazwisko LIKE (:nazwisko) ORDER BY wypozyczenia.idFilmu");
    query.bindValue(":nazwisko", "%" + nazwisko + "%");
    if (query.exec())
    {
        while (query.next())
        {
            wypozyczenia = new Wypozyczenia(query.value(0).toInt(), query.value(1).toString(), query.value(2).toDouble(), query.value(3).toInt(), query.value(4).toString(), query.value(5).toString(), query.value(6).toDateTime(), query.value(7).toDateTime());
            listaWypozyczenia.append(wypozyczenia);
            idWypozyczeniaVector.append(query.value(8).toInt());
            ileWierszyWypozyczone++;
        }
    }
    else
        qDebug() << "Nie udało się wyszukać wypożyczonych filmów";
}

bool ObslugaBD::wykonajZwrotFilmu(int &idWypozyczenia)
{
    bool wykonano = false;
    QSqlQuery query;
    query.prepare("UPDATE wypozyczenia SET dataZwrotu = (:dataZwrotu), idUzytkownikaZwrot = (:idUzytkownikaZwrot) WHERE idWypozyczenia = (:idWypozyczenia)");
    query.bindValue(":dataZwrotu", QDateTime::currentDateTime());
    query.bindValue(":idUzytkownikaZwrot", ObslugaBD::idZalogowanyUzytkownik);
    query.bindValue(":idWypozyczenia", idWypozyczenia);
    if (query.exec())
        wykonano = true;
    return wykonano;
}

void ObslugaBD::wyszukajRezerwacjeFilmyIdFilmuIdKlienta(int &idFilmu, int &idKlienta)
{
    ileWierszyRezerwacja = 0;
    listaRezerwacje.clear();
    idRezerwacjiVector.clear();
    QSqlQuery query;
    query.prepare("SELECT rezerwacje.idFilmu, tytul, cenaWypozyczenia, rezerwacje.idKlienta, imie, nazwisko, dataRezerwacji, terminRezerwacji, idRezerwacji FROM rezerwacje LEFT JOIN klienci ON rezerwacje.idKlienta = klienci.idKlienta LEFT JOIN filmy ON rezerwacje.idFilmu = filmy.idFilmu WHERE odwolanieRezerwacji IS NULL AND (rezerwacje.idFilmu = (:idFilmu) OR rezerwacje.idKlienta = (:idKlienta)) ORDER BY rezerwacje.idFilmu");
    query.bindValue(":idFilmu", idFilmu);
    query.bindValue(":idKlienta", idKlienta);
    if (query.exec())
    {
        while (query.next())
        {
            rezerwacje = new Rezerwacje(query.value(0).toInt(), query.value(1).toString(), query.value(2).toDouble(), query.value(3).toInt(), query.value(4).toString(), query.value(5).toString(), query.value(6).toDateTime(), query.value(7).toDateTime());
            listaRezerwacje.append(rezerwacje);
            idRezerwacjiVector.append(query.value(8).toInt());
            ileWierszyRezerwacja++;
        }
    }
    else
        qDebug() << "Nie udało się wyszukać zarezerwowanych filmów";
}

void ObslugaBD::wyszukajRezerwacjeFilmyNazwisko(const QString &nazwisko)
{
    ileWierszyRezerwacja = 0;
    listaRezerwacje.clear();
    idRezerwacjiVector.clear();
    QSqlQuery query;
    query.prepare("SELECT rezerwacje.idFilmu, tytul, cenaWypozyczenia, rezerwacje.idKlienta, imie, nazwisko, dataRezerwacji, terminRezerwacji, idRezerwacji FROM rezerwacje LEFT JOIN klienci ON rezerwacje.idKlienta = klienci.idKlienta LEFT JOIN filmy ON rezerwacje.idFilmu = filmy.idFilmu WHERE odwolanieRezerwacji IS NULL AND nazwisko LIKE (:nazwisko) ORDER BY rezerwacje.idFilmu");
    query.bindValue(":nazwisko", "%" + nazwisko + "%");
    if (query.exec())
    {
        while (query.next())
        {
            rezerwacje = new Rezerwacje(query.value(0).toInt(), query.value(1).toString(), query.value(2).toDouble(), query.value(3).toInt(), query.value(4).toString(), query.value(5).toString(), query.value(6).toDateTime(), query.value(7).toDateTime());
            listaRezerwacje.append(rezerwacje);
            idRezerwacjiVector.append(query.value(8).toInt());
            ileWierszyRezerwacja++;
        }
    }
    else
        qDebug() << "Nie udało się wyszukać zarezerwowanych filmów";
}

bool ObslugaBD::wykonajOdwolanieRezerwacji(int &idRezerwacji)
{
    bool wykonano = false;
    QSqlQuery query;
    query.prepare("UPDATE rezerwacje SET odwolanieRezerwacji = (:dataOdwolania), idUzytkownikaOdwolanie = (:idUzytkownikaOdwolanie) WHERE idRezerwacji = (:idRezerwacji)");
    query.bindValue(":dataOdwolania", QDateTime::currentDateTime());
    query.bindValue(":idUzytkownikaOdwolanie", ObslugaBD::idZalogowanyUzytkownik);
    query.bindValue(":idRezerwacji", idRezerwacji);
    if (query.exec())
        wykonano = true;
    return wykonano;
}
