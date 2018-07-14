#include "obslugabd.h"

//QString idZalogowanyUzytkownik; //zmienna globalna

int ObslugaBD::idZalogowanyUzytkownik; //zmienna statyczna


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
    {
        baza.close();
        qDebug() << "zamykam połączenie z bazą";
    }
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

bool ObslugaBD::dodajUzytkownika(QString &login, QString &haslo, QString &imie, QString &nazwisko, QString &telefon)
{
    bool dodano = false;
    QByteArray hasloByteArray;
    QString hasloHash = QString(QCryptographicHash::hash(hasloByteArray.append(haslo), QCryptographicHash::Md5).toHex());
    QSqlQuery query;
    query.prepare("insert into uzytkownicy (login, haslo, imie, nazwisko, telefon, dataRejestracji) values (:login, :haslo, :imie, :nazwisko, :telefon, :dataRejestracji)");
    query.bindValue(":login", login);
    query.bindValue(":haslo", hasloHash);
    query.bindValue(":imie", imie);
    query.bindValue(":nazwisko", nazwisko);
    query.bindValue(":telefon", telefon);
    query.bindValue(":dataRejestracji", QDateTime::currentDateTime());
    if (query.exec())
        dodano = true;
    else
        qDebug() << "Nie udało się dodać użytkownika";

    return dodano;
}

bool ObslugaBD::dodajKlienta(QString &imie, QString &nazwisko, QString &kodPocztowy, QString &miasto, QString &ulica, QString &nrDomu, QString &nrLokalu, QString &email, QString &telefon)
{
    bool dodano = false;
    QSqlQuery query;
    query.prepare("insert into klienci (imie, nazwisko, kod, miasto, ulica, nrDomu, nrLokalu, email, telefon, dataRejestracji, idUzytkownika) values (:imie, :nazwisko, :kodPocztowy, :miasto, :ulica, :nrDomu, :nrLokalu, :email, :telefon, :dataRejestracji, :idUzytkownika)");
    query.bindValue(":imie", imie);
    query.bindValue(":nazwisko", nazwisko);
    query.bindValue(":kodPocztowy", kodPocztowy);
    query.bindValue(":miasto", miasto);
    query.bindValue(":ulica", ulica);
    query.bindValue(":nrDomu", nrDomu);
    query.bindValue(":nrLokalu", nrLokalu);
    query.bindValue(":email", email);
    query.bindValue(":telefon", telefon);
    query.bindValue(":dataRejestracji", QDateTime::currentDateTime());
    query.bindValue(":idUzytkownika", ObslugaBD::idZalogowanyUzytkownik);
    if (query.exec())
        dodano = true;
    else
        qDebug() << "Nie udało się dodać klienta";

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
    listaGatunki.clear();
    QSqlQuery query;
    query.exec("SELECT Nazwa FROM gatunki");
    while (query.next())
        listaGatunki.append(query.value(0).toString());
    listaGatunki.insert(0,"Wybierz gatunek");
    return listaGatunki;
}

QList<Rezerwacje *> ObslugaBD::getListaRezerwacje() const
{
    return listaRezerwacje;
}

QList<Uzytkownicy *> ObslugaBD::getListaUzytkownicy() const
{
    return listaUzytkownicy;
}

QList<Filmy *> ObslugaBD::getListaFilmyEdycja() const
{
    return listaFilmyEdycja;
}

QList<Klienci *> ObslugaBD::getListaKlienciEdycja() const
{
    return listaKlienciEdycja;
}

QList<Wypozyczenia *> ObslugaBD::getListaWypozyczenia() const
{
    return listaWypozyczenia;
}

QList<Klienci *> ObslugaBD::getListaKlienci() const
{
    return listaKlienci;
}

QList<Filmy *> ObslugaBD::getListaFilmy() const
{
    return listaFilmy;
}

void ObslugaBD::wyszukajFilmTytulOpis(QString &tytul, QString &opis)
{
    listaFilmy.clear();
    QSqlQuery query;
    query.prepare("SELECT tytul, rokProdukcji, nazwa, opis, cenaWypozyczenia, idFilmu FROM filmy LEFT JOIN gatunki ON filmy.gatunek1 = gatunki.idGatunku WHERE Tytul like (:tytul) AND Opis LIKE (:opis) ORDER BY idFilmu");
    query.bindValue(":tytul", "%" + tytul + "%");
    query.bindValue(":opis", "%" + opis + "%");
    if (query.exec())
    {
        while (query.next())
        {
            filmy = new Filmy(query.value(0).toString(), query.value(1).toInt(), query.value(2).toString(), query.value(3).toString(), query.value(4).toDouble(), query.value(5).toInt());
            listaFilmy.append(filmy);
        }
    }
    else
        qDebug() << "Nie udało się wyszukać filmu";
}

void ObslugaBD::wyszukajFilmRokGatunek(int &rokProdukcji, int &gatunek)
{
    listaFilmy.clear();
    QSqlQuery query;
    query.prepare("SELECT tytul, rokProdukcji, nazwa, opis, cenaWypozyczenia, idFilmu FROM filmy LEFT JOIN gatunki ON filmy.gatunek1 = gatunki.idGatunku WHERE RokProdukcji = (:rokProdukcji) OR gatunek1 = (:gatunek) ORDER BY idFilmu");
    query.bindValue(":rokProdukcji", rokProdukcji);
    query.bindValue(":gatunek", gatunek);
    if (query.exec())
    {
        while (query.next())
        {
            filmy = new Filmy(query.value(0).toString(), query.value(1).toInt(), query.value(2).toString(), query.value(3).toString(), query.value(4).toDouble(), query.value(5).toInt());
            listaFilmy.append(filmy);
        }
    }
    else
        qDebug() << "Nie udało się wyszukać filmu";
}

void ObslugaBD::wyszukajKlienta(QString &imie, QString &nazwisko, QString &miasto, QString &ulica)
{
    listaKlienci.clear();
    QSqlQuery query;
    query.prepare("SELECT idKlienta, Imie, Nazwisko, Miasto, Ulica, nrDomu FROM klienci WHERE Imie LIKE (:imie) AND Nazwisko LIKE (:nazwisko) AND Miasto LIKE (:miasto) AND Ulica LIKE (:ulica) ORDER BY idKlienta");
    query.bindValue(":imie", "%" + imie + "%");
    query.bindValue(":nazwisko", "%" + nazwisko + "%");
    query.bindValue(":miasto", "%" + miasto + "%");
    query.bindValue(":ulica", "%" + ulica + "%");
    if (query.exec())
    {
        while (query.next())
        {
            klienci = new Klienci(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString(), query.value(4).toString(), query.value(5).toString());
            listaKlienci.append(klienci);
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
    listaWypozyczenia.clear();
    QSqlQuery query;
    query.prepare("SELECT wypozyczenia.idFilmu, tytul, cenaWypozyczenia, wypozyczenia.idKlienta, imie, nazwisko, dataWypozyczenia, planowaDataZwrotu, idWypozyczenia FROM wypozyczenia LEFT JOIN klienci ON wypozyczenia.idKlienta = klienci.idKlienta LEFT JOIN filmy ON wypozyczenia.idFilmu = filmy.idFilmu WHERE dataZwrotu IS NULL AND (wypozyczenia.idFilmu = (:idFilmu) OR wypozyczenia.idKlienta = (:idKlienta)) ORDER BY wypozyczenia.idFilmu");
    query.bindValue(":idFilmu", idFilmu);
    query.bindValue(":idKlienta", idKlienta);
    if (query.exec())
    {
        while (query.next())
        {
            wypozyczenia = new Wypozyczenia(query.value(0).toInt(), query.value(1).toString(), query.value(2).toDouble(), query.value(3).toInt(), query.value(4).toString(), query.value(5).toString(), query.value(6).toDateTime(), query.value(7).toDateTime(), query.value(8).toInt());
            listaWypozyczenia.append(wypozyczenia);
        }
    }
    else
        qDebug() << "Nie udało się wyszukać wypożyczonych filmów";
}

void ObslugaBD::wyszukajWypozyczoneFilmyNazwisko(const QString &nazwisko)
{
    listaWypozyczenia.clear();
    QSqlQuery query;
    query.prepare("SELECT wypozyczenia.idFilmu, tytul, cenaWypozyczenia, wypozyczenia.idKlienta, imie, nazwisko, dataWypozyczenia, planowaDataZwrotu, idWypozyczenia FROM wypozyczenia LEFT JOIN klienci ON wypozyczenia.idKlienta = klienci.idKlienta LEFT JOIN filmy ON wypozyczenia.idFilmu = filmy.idFilmu WHERE dataZwrotu IS NULL AND nazwisko LIKE (:nazwisko) ORDER BY wypozyczenia.idFilmu");
    query.bindValue(":nazwisko", "%" + nazwisko + "%");
    if (query.exec())
    {
        while (query.next())
        {
            wypozyczenia = new Wypozyczenia(query.value(0).toInt(), query.value(1).toString(), query.value(2).toDouble(), query.value(3).toInt(), query.value(4).toString(), query.value(5).toString(), query.value(6).toDateTime(), query.value(7).toDateTime(), query.value(8).toInt());
            listaWypozyczenia.append(wypozyczenia);
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
    listaRezerwacje.clear();
    QSqlQuery query;
    query.prepare("SELECT rezerwacje.idFilmu, tytul, cenaWypozyczenia, rezerwacje.idKlienta, imie, nazwisko, dataRezerwacji, terminRezerwacji, idRezerwacji FROM rezerwacje LEFT JOIN klienci ON rezerwacje.idKlienta = klienci.idKlienta LEFT JOIN filmy ON rezerwacje.idFilmu = filmy.idFilmu WHERE odwolanieRezerwacji IS NULL AND (rezerwacje.idFilmu = (:idFilmu) OR rezerwacje.idKlienta = (:idKlienta)) ORDER BY rezerwacje.idFilmu");
    query.bindValue(":idFilmu", idFilmu);
    query.bindValue(":idKlienta", idKlienta);
    if (query.exec())
    {
        while (query.next())
        {
            rezerwacje = new Rezerwacje(query.value(0).toInt(), query.value(1).toString(), query.value(2).toDouble(), query.value(3).toInt(), query.value(4).toString(), query.value(5).toString(), query.value(6).toDateTime(), query.value(7).toDateTime(), query.value(8).toInt());
            listaRezerwacje.append(rezerwacje);
        }
    }
    else
        qDebug() << "Nie udało się wyszukać zarezerwowanych filmów";
}

void ObslugaBD::wyszukajRezerwacjeFilmyNazwisko(const QString &nazwisko)
{
    listaRezerwacje.clear();
    QSqlQuery query;
    query.prepare("SELECT rezerwacje.idFilmu, tytul, cenaWypozyczenia, rezerwacje.idKlienta, imie, nazwisko, dataRezerwacji, terminRezerwacji, idRezerwacji FROM rezerwacje LEFT JOIN klienci ON rezerwacje.idKlienta = klienci.idKlienta LEFT JOIN filmy ON rezerwacje.idFilmu = filmy.idFilmu WHERE odwolanieRezerwacji IS NULL AND nazwisko LIKE (:nazwisko) ORDER BY rezerwacje.idFilmu");
    query.bindValue(":nazwisko", "%" + nazwisko + "%");
    if (query.exec())
    {
        while (query.next())
        {
            rezerwacje = new Rezerwacje(query.value(0).toInt(), query.value(1).toString(), query.value(2).toDouble(), query.value(3).toInt(), query.value(4).toString(), query.value(5).toString(), query.value(6).toDateTime(), query.value(7).toDateTime(), query.value(8).toInt());
            listaRezerwacje.append(rezerwacje);
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

void ObslugaBD::wyszukajKlienta(const QString &nazwisko)
{
    listaKlienciEdycja.clear();
    QSqlQuery query;
    query.prepare("SELECT idKlienta, imie, nazwisko, kod, miasto, ulica, nrDomu, nrLokalu, email, telefon FROM klienci WHERE nazwisko LIKE (:nazwisko)");
    query.bindValue(":nazwisko", "%" + nazwisko + "%");
    if (query.exec())
    {
        while (query.next())
        {
            klienci = new Klienci(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString(), query.value(4).toString(), query.value(5).toString(), query.value(6).toString(), query.value(7).toString(), query.value(8).toString(), query.value(9).toString());
            listaKlienciEdycja.append(klienci);
        }
    }
    else
        qDebug() << "Nie udało się wyszukać klienta";
}

bool ObslugaBD::wykonajEdycjeKlienta(int &idKlienta, QString &imie, QString &nazwisko, QString &kod, QString &miasto, QString &ulica, QString &nrDomu, QString &nrLokalu, QString &email, QString &telefon)
{
    bool wykonano = false;
    QSqlQuery query;
    query.prepare("UPDATE klienci SET imie = (:imie), nazwisko = (:nazwisko), kod = (:kodPocztowy), miasto = (:miasto), ulica = (:ulica), nrDomu = (:nrDomu), nrLokalu = (:nrLokalu), email = (:email), telefon = (:telefon), dataEdycji = (:dataEdycji), idUzytkownikaEdycja = (:idUzytkownika) WHERE idKlienta = (:idKlienta)");
    query.bindValue(":idKlienta", idKlienta);
    query.bindValue(":imie", imie);
    query.bindValue(":nazwisko", nazwisko);
    query.bindValue(":kodPocztowy", kod);
    query.bindValue(":miasto", miasto);
    query.bindValue(":ulica", ulica);
    query.bindValue(":nrDomu", nrDomu);
    query.bindValue(":nrLokalu", nrLokalu);
    query.bindValue(":email", email);
    query.bindValue(":telefon", telefon);
    query.bindValue(":dataEdycji", QDateTime::currentDateTime());
    query.bindValue(":idUzytkownika", ObslugaBD::idZalogowanyUzytkownik);
    if (query.exec())
        wykonano = true;
    else
        qDebug() << "Nie udało się edytować klienta";

    return wykonano;
}

void ObslugaBD::wyszukajFilm(const QString &tytul)
{
    listaFilmyEdycja.clear();
    QSqlQuery query;
    query.prepare("SELECT * FROM filmy WHERE tytul LIKE (:tytul)");
    query.bindValue(":tytul", "%" + tytul + "%");
    if (query.exec())
    {
        while (query.next())
        {
            filmy = new Filmy(query.value(0).toInt(), query.value(1).toString(), query.value(2).toInt(), query.value(3).toString(), query.value(4).toInt(), query.value(5).toDouble(), query.value(6).toInt(), query.value(7).toInt(), query.value(8).toInt());
            listaFilmyEdycja.append(filmy);
        }
    }
    else
        qDebug() << "Nie udało się wyszukać filmu";
}

bool ObslugaBD::wykonajEdycjeFilmu(int &idFilmu, QString &tytul, int &rokProdukcji, QString &opis, int &iloscKopii, double &cenaWypozyczenia, int &gatunek1, int &gatunek2, int &gatunek3)
{
    bool wykonano = false;
    QSqlQuery query;
    query.prepare("UPDATE filmy SET tytul = (:tytul), rokProdukcji = (:rokProdukcji), opis = (:opis), iloscKopii = (:iloscKopii), cenaWypozyczenia = (:cenaWypozyczenia), gatunek1 = (:gatunek1), gatunek2 = (:gatunek2), gatunek3 = (:gatunek3), dataEdycji = (:dataEdycji), idUzytkownikaEdycja = (:idUzytkownika) WHERE idFilmu = (:idFilmu)");
    query.bindValue(":idFilmu", idFilmu);
    query.bindValue(":tytul", tytul);
    query.bindValue(":rokProdukcji", rokProdukcji);
    query.bindValue(":opis", opis);
    query.bindValue(":iloscKopii", iloscKopii);
    query.bindValue(":cenaWypozyczenia", cenaWypozyczenia);
    query.bindValue(":gatunek1", gatunek1);
    query.bindValue(":gatunek2", gatunek2);
    query.bindValue(":gatunek3", gatunek3);
    query.bindValue(":dataEdycji", QDateTime::currentDateTime());
    query.bindValue(":idUzytkownika", ObslugaBD::idZalogowanyUzytkownik);
    if (query.exec())
        wykonano = true;
    else
        qDebug() << "Nie udało się edytować filmu";

    return wykonano;
}

void ObslugaBD::wyszukajUzytkownika(const QString &nazwisko)
{
    listaUzytkownicy.clear();
    QSqlQuery query;
    query.prepare("SELECT idUzytkownika, login, imie, nazwisko, telefon FROM uzytkownicy WHERE nazwisko LIKE (:nazwisko)");
    query.bindValue(":nazwisko", "%" + nazwisko + "%");
    if (query.exec())
    {
        while (query.next())
        {
            uzytkownicy = new Uzytkownicy(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString(), query.value(4).toString());
            listaUzytkownicy.append(uzytkownicy);
        }
    }
    else
        qDebug() << "Nie udało się wyszukać użytkownika";
}

bool ObslugaBD::wykonajEdycjeUzytkownika(int &idUzytkownika, QString &login, QString &imie, QString &nazwisko, QString &telefon)
{
    bool wykonano = false;
    QSqlQuery query;
    query.prepare("UPDATE uzytkownicy SET login = (:login), imie = (:imie), nazwisko = (:nazwisko), telefon = (:telefon), dataEdycji = (:dataEdycji) WHERE idUzytkownika = (:idUzytkownika)");
    query.bindValue(":idUzytkownika", idUzytkownika);
    query.bindValue(":login", login);
    query.bindValue(":imie", imie);
    query.bindValue(":nazwisko", nazwisko);
    query.bindValue(":telefon", telefon);
    query.bindValue(":dataEdycji", QDateTime::currentDateTime());
    if (query.exec())
        wykonano = true;
    else
        qDebug() << "Nie udało się edytować użytkownika";

    return wykonano;
}

int ObslugaBD::znajdzUzytkownika(QString &login, QString &haslo)
{
    int znaleziono = 0;
    QByteArray hasloByteArray;
    QString hasloHash = QString(QCryptographicHash::hash(hasloByteArray.append(haslo), QCryptographicHash::Md5).toHex());
    QString loginBaza, hasloBaza;
    int idUzytkownika;
    QSqlQuery query;
    query.exec("SELECT idUzytkownika, login, haslo FROM uzytkownicy");
    while (query.next())
    {
        idUzytkownika = query.value(0).toInt();
        loginBaza = query.value(1).toString();
        hasloBaza = query.value(2).toString();
        if (login == loginBaza && hasloHash == hasloBaza)
        {
            znaleziono = idUzytkownika;
            break;
        }
    }

    return znaleziono;
}

bool ObslugaBD::wykonajZmianeHasla(int &idUzytkownika, QString &hasloNowe)
{
    bool wykonano = false;
    QByteArray hasloByteArray;
    QString hasloHash = QString(QCryptographicHash::hash(hasloByteArray.append(hasloNowe), QCryptographicHash::Md5).toHex());
    QSqlQuery query;
    query.prepare("UPDATE uzytkownicy SET haslo = (:haslo), dataEdycji = (:dataEdycji) WHERE idUzytkownika = (:idUzytkownika)");
    query.bindValue(":idUzytkownika", idUzytkownika);
    query.bindValue(":haslo", hasloHash);
    query.bindValue(":dataEdycji", QDateTime::currentDateTime());
    if (query.exec())
        wykonano = true;
    else
        qDebug() << "Nie udało się edytować użytkownika";

    return wykonano;
}

bool ObslugaBD::dodajGatunek(QString gatunek)
{
    qDebug() << gatunek;
    bool dodano = false;
    QSqlQuery query;
    query.prepare("INSERT INTO gatunki (nazwa, dataDodania) VALUES (:nazwa, :dataDodania)");
    query.bindValue(":nazwa", gatunek);
    query.bindValue(":dataDodania", QDateTime::currentDateTime());
    if (query.exec())
        dodano = true;
    else
        qDebug() << "Nie udało się dodać gatunku";

    return dodano;
}

bool ObslugaBD::usunGatunki()
{
    bool usunieto = false;
    QSqlQuery query;
    query.prepare("DELETE FROM gatunki");
    if (query.exec())
        usunieto = true;
    else
        qDebug() << "Nie udało się usunąć gatunków";

    return usunieto;
}
