#define _WIN32_WINNT 0x0500
#include <iostream>
#include <fstream>
#include <algorithm>
#include <conio.h>
#include <windows.h>
#include <time.h>
//#include <vector>
#include "klasy.h"

using namespace std;



void menu()
{
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),55);
cout<<  "\nWybor ksiazki telefonicznej:     "
        "\n----------------------------     "
        "\nPrywatna   :1                    "
        "\nFirmowa    :2                    "
        "\n-------------                    "
        "\nWyjscie  :ESC                    "
        "\n                                 ";
cout<<  "\nWybierz opcje menu startowego:   "
        "\n                                 ";
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}

int main()
{
FlushConsoleInputBuffer( GetStdHandle( STD_INPUT_HANDLE ) );
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); // uchwyt standardowego wyjœcia
COORD c2; // struktura potrzebna do ustawienia rozmiarów bufora pamiêci
c2.X = 60; // szerokoœæ na 120 szerokoœci znaków
c2.Y = 60; // wysokoœæ na 40 wysokoœci znaków
SetConsoleScreenBufferSize(handle, c2); // ustawia rozmiar bufora (wyœwietlanego tekstu)
SMALL_RECT sr; // struktura wykorzystywana do ustawienia rozmiaru okna
sr.Left = 0; // na zero
sr.Top = 0; // na zero
sr.Right = c2.X-1; // szerokoœæ o 1 mniejsza od bufora
sr.Bottom = c2.Y-1; // wysokoœæ o 1 mniejsza od bufora
HWND uchwytKonsoli = GetConsoleWindow(); // zmienna przechowuje uchwyt do okna konsoli
MoveWindow( uchwytKonsoli, 0, 0, 5000, 5000, TRUE );
SetConsoleWindowInfo(handle,true,&sr); // ustawia rozmiar okna (jednostka to szerokoœæ i wysokoœæ pojedynczego znaku)

Ksiazka kt1, kt2; //obsluguje ksiazke tel.

char rodzaj_kt;

menu();
while(rodzaj_kt !=27)
    {
        system("cls");
        menu();
        rodzaj_kt=getch();
        switch(rodzaj_kt)
        {
            case '1':
            if (rodzaj_kt=='1') kt1.rodzaj=1;
            kt1.obsluga_ksiazki();
            break;

            case '2':
            if (rodzaj_kt=='2') kt2.rodzaj=2;
            kt2.obsluga_ksiazki();
            break;

            case 27:  exit(0);

            default : cout << "\nBrak takiej opcji w podmenu \n\n";
            Sleep(1500);
        }
    }
    //system("pause");
    return 0;
}
