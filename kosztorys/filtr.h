#ifndef FILTR_H
#define FILTR_H

#include <QTextStream>

class Filtr
{
    char znaki[2]{'#', '\''};
    bool sp;

public:
    Filtr();
    QString usunSpacje(QString *tekst);
    bool filtrZnakow(QString *tekst);
    char getZnaki(int i);
};

#endif // FILTR_H
