#ifndef GATUNKI_H
#define GATUNKI_H

#include <QString>

class Gatunki
{
private:
    int idGatunku;
    QString nazwa;

public:
    Gatunki();
    Gatunki(int idGatunku, QString nazwa);
    int getIdGatunku() const;
    QString getNazwa() const;
};

#endif // GATUNKI_H
