#include <iostream>
#include <fstream>
#include <algorithm>
#include <conio.h>
#include <windows.h>
//#include "void_glowny.cpp"
#include "klasy.h"


using namespace std;

void Ksiazka::odczyt_pliku(string *tab1, string *tab2, string *tab3, int *rodzaj)
{
        switch(*rodzaj)
        {
            case 1:
            plik.open("prywatna.txt", ios_base::in);
            break;
            case 2:
            plik.open("firmowa.txt", ios_base::in);
            break;
        }
        if (plik.good()==false)
           {
             cout<< "Brak wpis\242w w ksi\245\276ce lub plik ksi\245\276ki nie istnieje\n";
           }
        while(getline(plik, linia))
           {
             *tab1=linia.substr(0, linia.find('#', 0));
             *tab2=linia.substr(linia.find('#', 0)+1, linia.find('#', linia.find('#', 0)+1)-(linia.find('#', 0)+1));
             *tab3=linia.substr((linia.find('#', linia.find('#', 0)+1))+1);
             tab1++;
             tab2++;
             tab3++;
           }
        plik.close();
}

void Ksiazka::odczyt_temp(string *tab4, int *rodzaj)
    {
        switch(*rodzaj)
        {
            case 1:
            plik.open("prywatna.txt", ios_base::in);
            break;
            case 2:
            plik.open("firmowa.txt", ios_base::in);
            break;
        }
        if (plik.good()==false)
           {
             cout<< "Brak wpis\242w w ksi\245\276ce lub plik ksi\245\276ki nie istnieje\n";
           }
        while(getline(plik, linia))
           {
             *tab4=linia;
             tab4++;
           }
        plik.close();
    }

void Ksiazka::wyswietl(string *t_imie, string *t_nazwisko, string *t_telefon, int *x)
    {
        for(int i=0; i<*x ; i++)
        {
            t_imie[i].resize(15,' ');
            t_nazwisko[i].resize(20,' ');
            cout<< i+1 << ". " << t_imie[i] << t_nazwisko[i] << t_telefon[i] << "\n";
        }
        cout<< "\n\n";
    }

void Ksiazka::sortuj(string *tab1, string *tab2, string *tab3, int *ile)
{
    string temp;
    int n=0;
    for (int i=*ile-1; i>=0; i--)
    {

        for (int j=(*ile-1); j>n; j--)
        {
            if(tab2[j]<tab2[j-1])
            {
                temp=tab2[j];
                tab2[j]=tab2[j-1];
                tab2[j-1]=temp;
                temp=tab1[j];
                tab1[j]=tab1[j-1];
                tab1[j-1]=temp;
                temp=tab3[j];
                tab3[j]=tab3[j-1];
                tab3[j-1]=temp;
            }
        }
        n++;
    }
}

void Ksiazka::quicksort(string *tablica, int lewy, int prawy, string *tab2, string *tab3)
{
    string v=tablica[(lewy+prawy)/2];
    int i,j; string x;
    i=lewy;
    j=prawy;
    do
    {
        while(tablica[i]<v) i++;
        while(tablica[j]>v) j--;
        if(i<=j)
        {
            x=tablica[i];
            tablica[i]=tablica[j];
            tablica[j]=x;
            x=tab2[i];
            tab2[i]=tab2[j];
            tab2[j]=x;
            x=tab3[i];
            tab3[i]=tab3[j];
            tab3[j]=x;
            i++;
            j--;
        }
    }
    while(i<=j);
    if(j>lewy) quicksort(tablica,lewy, j, tab2, tab3);
    if(i<prawy) quicksort(tablica, i, prawy, tab2, tab3);
}


int Ksiazka::rt(int *rodzaj)
{
    switch(*rodzaj)
    {
        case 1:
        plik.open("prywatna.txt", ios_base::in);
        break;
        case 2:
        plik.open("firmowa.txt", ios_base::in);
        break;
    }
    if (plik.good()==false)
        cout<< "Brak wpis\242w w ksi\245\276ce lub plik ksi\245\276ki nie istnieje\n";
    x=0;
    while(getline(plik, linia))
        x++;
    plik.close();
    return x;
}

void Ksiazka::menu1(int *x)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),55);
        cout << "\n";
        if (rodzaj==1) cout << "PRYWATNA KSI\244\275KA TELEFONICZNA       \n";
        else if (rodzaj==2) cout << "FIRMOWA KSI\244\275KA TELEFONICZNA        \n";
        cout << "===============================     \n";
        cout << "Wybierz opcj\251:                      " << "\n";
        cout << "--------------                      " << "\n";
        cout << "Odczytywanie wpis\242w            : 1  " << "\n";
        cout << "Wprowadzanie danych do ksi\245\276ki : 2  " << "\n";
        cout << "Usuwanie wpis\242w do ksi\245\276ki     : 3  " << "\n";
        cout << "Wyszukiwanie                   : 4  " << "\n";
        cout << "Edycja danych                  : 5  " << "\n";
        cout << "Powr\242t do menu startowego      : 6  " << "\n";
        cout << "Wyj\230cie z programu             : ESC" << "\n";
        cout << "----------------------------------- \n";
        cout << "Ilo\230\206 wpis\242w w ksi\245\276ce         :"<<*x<< "  \n";
        cout << "----------------------------------- \n";
        cout << "\n\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    }

void Ksiazka::menu2()
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),55);
        cout << "\n";
        if (rodzaj==1) cout << "PRYWATNA KSI\244\275KA TELEFONICZNA        \n";
        else if (rodzaj==2) cout << "FIRMOWA KSI\244\275KA TELEFONICZNA         \n";
        cout << "===============================      \n";
        cout << "Wyszukiwarka                         \n";
        cout << "~~~~~~~~~~~~                         \n";
        cout << "Wybierz opcj\251:                       \n";
        cout << "--------------                       \n";
        cout << "Wyszukiwanie wg nazwiska     : 1     \n";
        cout << "Wyszukiwanie wg nr telefonu  : 2     \n";
        cout << "Powr\242t do menu g\210\242wnego      : 3     \n";
        cout << "Wyj\230cie z programu           : ESC   \n";
        cout << "-------------------------------------";
        cout << "\n\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    }

void Ksiazka::menu3()
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),55);
        cout << "\n";
        if (rodzaj==1) cout << "PRYWATNA KSI\244\275KA TELEFONICZNA                   \n";
        else if (rodzaj==2) cout << "FIRMOWA KSI\244\275KA TELEFONICZNA                    \n";
        cout << "===============================                 \n";
        cout << "Sortowanie                                      \n";
        cout << "~~~~~~~~~~                                      \n";
        cout << "Wybierz opcj\251:                                  \n";
        cout << "--------------                                  \n";
        cout << "Sortowanie wg nazwiska     : 1 (b\245belkowe)      \n";
        cout << "Sortowanie wg nr telefonu  : 2 (rekurencyjne)   \n";
        cout << "Powr\242t do menu g\210\242wnego    : 3                  \n";
        cout << "Wyj\230cie z programu         : ESC                \n";
        cout << "---------------------------------------------   \n";
        cout << "\n\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    }

    Ksiazka::Ksiazka(int r)
    {
        rodzaj=r;
    }

    Ksiazka::~Ksiazka()
    {
        cout<< "\nDziala destruktor";
    }

string Filtr::filtr_znakow(string *tekst)
    {
        cin.sync(); //w linuxie moze nie dzialac, mozna wtedy probowac cin.ignore()
        do
        {
            getline(cin, *tekst);
            if((*tekst)[0]==' ') tekst->erase(0,1);
            if((*tekst)[tekst->size()-1]==' ') tekst->erase(tekst->size()-1,1);
            sp=true;
            if(tekst->size()==0) sp=false;
            for (short i=0; i<tekst->size(); i++)
            for (short j=0; j<sizeof(znaki); j++)
            {
                if((*tekst)[i]==znaki[j]) sp=false;
            }
            if (sp==false) cout<< "Wprowadzony tekst nie mo\276e by\206 pusty i zawiera\206 znak\242w:\n- spacji (wewn\245trz tekstu) \n- tabulacji \n- znaku #\nWprowad\253 tekst ponownie: ";
        }
        while(sp==false);
        return *tekst;
    }
