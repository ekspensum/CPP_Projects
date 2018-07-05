#ifndef FILTRZNAKOW_H
#define FILTRZNAKOW_H
#include <QTextStream>

class FiltrZnakow
{
private:
    char znaki[2]{'#', '\''};
    char cyfry[12]{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-', '.'};

public:
    FiltrZnakow();
    QString usunSpacje(QString *tekst);
    bool filtrZnakow(QString *tekst);
    bool filtrCyfr(QString *tekst);
    char getZnaki(int i);
};

#endif // FILTRZNAKOW_H
