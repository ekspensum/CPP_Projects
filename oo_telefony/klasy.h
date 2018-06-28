#include <iostream>

using namespace std;

class Filtr
{
char znaki[3]{'\40', '\t', '#'};
bool sp;
//string *temp;

public:

    string filtr_znakow(string *tekst);
};


class Ksiazka
{
string linia, imie, nazwisko, telefon, ab;
char wybor, podmenu;
string str;
int x, poz;
char znaki[3]{'\40', '\t', '#'};
bool sp;
fstream plik;
    void odczyt_pliku(string *tab1, string *tab2, string *tab3, int *rodzaj);
    void odczyt_temp(string *tab4, int *rodzaj);
    void wyswietl(string *t_imie, string *t_nazwisko, string *t_telefon, int *x);
    void sortuj(string *tab1, string *tab2, string *tab3, int *ile);
    void quicksort(string *tablica, int lewy, int prawy, string *tab2, string *tab3);
    int rt(int *rodzaj);
    void menu1(int *x);
    void menu2();
    void menu3();
    string filtr_znakow(string *tekst);

public:

friend class Filtr;
int rodzaj;
Ksiazka(int=1);
~Ksiazka();

    int obsluga_ksiazki();
    Filtr f;
};

