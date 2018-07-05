#include "filtrznakow.h"

FiltrZnakow::FiltrZnakow()
{

}

char FiltrZnakow::getZnaki(int i)
{
    return znaki[i];
}

QString FiltrZnakow::usunSpacje(QString *tekst)
{
    for(short i=0; i<tekst->size()-1; i++)
    if((*tekst)[0]==' ') tekst->remove(0,1); //usuwa pierwsze spacje
    else break;

    for(short i=0; i<tekst->size()-1; i++)
    if((*tekst)[tekst->size()-1]==' ') tekst->remove(tekst->size()-1,1); //usuwa ostatnie spacje
    else break;

    return *tekst;
}

bool FiltrZnakow::filtrZnakow(QString *tekst)
{
    bool sp = true;
    if(tekst->size()==0) sp=false;
    for (short i=0; i<tekst->size(); i++)
    for (short j=0; j<(int)sizeof(znaki); j++)
    {
        if((*tekst)[i]==znaki[j]) sp=false;
    }
    return sp;
}

bool FiltrZnakow::filtrCyfr(QString *tekst)
{
    bool sp = true;
    if(tekst->size()==0) sp=false;
    for (short i=0; i<tekst->size(); i++)
    for (short j=0; j<(int)sizeof(cyfry); j++)
    {
        if((*tekst)[i]!=cyfry[j]) sp=false;
    }
    return sp;
}
