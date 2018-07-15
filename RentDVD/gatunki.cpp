#include "gatunki.h"

int Gatunki::getIdGatunku() const
{
    return idGatunku;
}

QString Gatunki::getNazwa() const
{
    return nazwa;
}

Gatunki::Gatunki()
{

}

Gatunki::Gatunki(int idGatunku, QString nazwa)
{
    this->idGatunku = idGatunku;
    this->nazwa = nazwa;
}
