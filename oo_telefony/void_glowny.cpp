#include <iostream>
#include <fstream>
#include <algorithm>
#include <conio.h>
#include <windows.h>
#include "klasy.h"

using namespace std;

int Ksiazka::obsluga_ksiazki()
{
    wybor='0';
    while(wybor !='6')
    {
        //dynamiczne alokowanie pamieci dla tablic
        x=rt(&rodzaj);
        string *t_imie = new string [x];
        string *t_nazwisko = new string [x];
        string *t_telefon = new string [x];
        string *temp = new string [x];
        system("cls");
        menu1(&x);
        cout<< "\nWprowad\253 opcje: "; wybor=getch();
        cout<<"\n\n";
        switch(wybor)
        {
            case '1':
            {
                system("cls");
                menu3();
                cout<< "Wpisy sortowane wg kolejno\230ci wpis\242w:"<< "\n";
                cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< "\n";
                odczyt_pliku(t_imie, t_nazwisko, t_telefon, &rodzaj);
                cout<<"\n\n";
                wyswietl(t_imie, t_nazwisko, t_telefon, &x);
                podmenu='0';
                    while(podmenu !='3')
                    {
                        cout<< "Wprowad\253 opcj\251 menu \"Sortowanie\": "; podmenu=getch();
                        cout<< "\n";
                        switch(podmenu)
                        {
                          case '1':
                          {

                            system("cls");
                            menu3();
                            cout<< "\n";
                            cout<< "Wpisy sortowane wg nazwiska: "<< "\n";
                            cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< "\n";
                            odczyt_pliku(t_imie, t_nazwisko, t_telefon, &rodzaj);
                            sortuj(t_imie, t_nazwisko, t_telefon, &x);
                            wyswietl(t_imie, t_nazwisko, t_telefon, &x);
                            break;
                          }
                          case '2':
                          {
                              system("cls");
                              menu3();
                              cout<< "\n";
                              cout<< "Wpisy sortowane wg nr telefonu: "<< "\n";
                              cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< "\n";
                              odczyt_pliku(t_imie, t_nazwisko, t_telefon, &rodzaj);
                              quicksort(t_telefon, 0, x-1, t_imie, t_nazwisko);
                              wyswietl(t_imie, t_nazwisko, t_telefon, &x);
                              break;
                          }
                          case '3':
                          system("cls");
                          menu1(&x);
                          break;
                          case 27: exit(0);
                          default : cout << "Brak takiej opcji w podmenu \n\n";
                        }
                    }
                break;
            }

            case '2':
                {
                    system("cls");
                    menu1(&x);
                    cout << "Podaj imi\251: ";
                    imie=f.filtr_znakow(&imie);
                    cout << "Podaj nazwisko: ";
                    nazwisko=f.filtr_znakow(&nazwisko);
                    cout << "Podaj nr telefonu: ";
                    telefon=f.filtr_znakow(&telefon);
                    cout << "\n\n";
                    //cout << "Wprowadzono dane: " << imie << "\ " << nazwisko<< "\ "<< telefon;
                    switch(rodzaj)
                    {
                        case 1:
                        plik.open("prywatna.txt", ios_base::app);
                        break;
                        case 2:
                        plik.open("firmowa.txt", ios_base::app);
                        break;
                    }
                    plik<<imie<<"#"<<nazwisko<<"#"<<telefon<<"\n";
                    plik.close();
                    cout << "Wprowadzono dane: " << imie << "\ " << nazwisko<< "\ "<< telefon;
                    cout<< "\n\n";
                    Sleep(1500);
                    break;
                }
            case '3':
                {
                    system("cls");
                    menu1(&x);
                    cout<< "Wpisy sortowane wg kolejno\230ci wpis\242w:"<< "\n";
                    cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< "\n";
                    odczyt_pliku(t_imie, t_nazwisko, t_telefon, &rodzaj);
                    cout<<"\n\n";
                    wyswietl(t_imie, t_nazwisko, t_telefon, &x);
                    cout<<"\n\n";
                    cout << "Podaj nr pozycji z ksi\245\276ki do kasowania: ";
                    str=f.filtr_znakow(&str);
                    poz=atoi(str.c_str());
                    cout<< "\n\n";
                    if(poz>x || poz<1)
                    {
                        cout<< "Brak takiej pozycji w ksi\245\276ce telefonicznej \n\n";
                        Sleep(1500);
                        break;
                    }
                    odczyt_temp(temp, &rodzaj);
                    switch(rodzaj)
                    {
                        case 1:
                        plik.open("prywatna.txt", ios_base::out);
                        break;
                        case 2:
                        plik.open("firmowa.txt", ios_base::out);
                        break;
                    }
                    for(int i=0; i<x; i++)
                        {
                            if(i !=poz-1)
                            {
                                plik<<temp[i]<<"\n";
                            }
                        }
                    plik.close();
                    cout<< "Usuni\251to wpis: " << poz << ". " << temp[poz-1];
                    cout<< "\n\n";
                    Sleep(1500);
                    break;
                }

            case '4':
                {
                    system("cls");
                    menu2();
                    podmenu='0';
                    while(podmenu !='3')
                    {
                        cout<< "Wprowad\253 opcj\251 menu \"Wyszukiwarka\": "; podmenu=getch();
                        cout<< "\n\n";
                        switch(podmenu)
                        {
                            case '1':
                            {
                                cout<< "Podaj nazwisko lub jego fragment: "; cin>> nazwisko;
                                transform(nazwisko.begin(), nazwisko.end(), nazwisko.begin(), ::tolower);
                                cout<< "\n\n";
                                odczyt_pliku(t_imie, t_nazwisko, t_telefon, &rodzaj);
                                for(int i=0; i<x ; i++)
                                    {
                                       transform(t_nazwisko[i].begin(), t_nazwisko[i].end(), t_nazwisko[i].begin(), ::tolower);
                                       int nr=t_nazwisko[i].find(nazwisko, 0);
                                       if(nr>=0)
                                       {
                                        t_imie[i].resize(15,' ');
                                        t_nazwisko[i].resize(20,' ');
                                        cout<< i+1 << ". " << t_imie[i] << t_nazwisko[i] << t_telefon[i] << "\n";
                                       }
                                    }
                                cout<< "\n\n";
                                break;
                            }

                            case '2':
                            {
                                cout<< "Podaj nr telefonu lub jego fragment: "; cin>> telefon;
                                cout<< "\n\n";
                                odczyt_pliku(t_imie, t_nazwisko, t_telefon, &rodzaj);
                                for(int i=0; i<x ; i++)
                                    {
                                       int nr=t_telefon[i].find(telefon, 0);
                                       if(nr>=0)
                                       {
                                        t_imie[i].resize(15,' ');
                                        t_nazwisko[i].resize(20,' ');
                                        cout<< i+1 << ". " << t_imie[i] << t_nazwisko[i] << t_telefon[i] << "\n";
                                       }
                                    }
                                    cout<< "\n\n";
                                break;
                            }

                            case '3': break;

                            case 27: exit(0);

                            default : cout << "Brak takiej opcji w podmenu \n\n";
                        }
                    }
                    system("cls");
                    menu1(&x);
                    break;
                }

            case '5':
            {
                system("cls");
                menu1(&x);
                odczyt_pliku(t_imie, t_nazwisko, t_telefon, &rodzaj);
                wyswietl(t_imie, t_nazwisko, t_telefon, &x);
                cout << "Podaj nr pozycji z ksi\245\276ki do edycji: ";
                str=f.filtr_znakow(&str);
                poz=atoi(str.c_str());
                cout<< "\n\n";
                if(poz>x || poz<1)
                  {
                     cout<< "Brak takiej pozycji w ksi\245\276ce telefonicznej \n\n";
                     break;
                  }
                cout<<poz<<". "<<t_imie[poz-1]<<" "<<t_nazwisko[poz-1]<<" "<<t_telefon[poz-1]<<"\n\n";
                odczyt_temp(temp, &rodzaj);
                cout<< "Podaj nowy nr telefonu: ";
                telefon=f.filtr_znakow(&telefon);
                temp[poz-1].replace(temp[poz-1].rfind('#')+1,15,telefon);
                switch(rodzaj)
                {
                    case 1:
                    plik.open("prywatna.txt", ios_base::out);
                    break;
                    case 2:
                    plik.open("firmowa.txt", ios_base::out);
                    break;
                }
                for(int i=0; i<x; i++)
                   {
                      plik<<temp[i]<<"\n";
                   }
                plik.close();
                cout<< "\n\n";
                cout<< "Zaktualizowano nr telefonu dla poz.: " << poz << ". " << temp[poz-1];
                cout<< "\n\n";
                Sleep(1500);
                break;
            }

            case '6':  break;

            case 27: exit(0);

            default : cout << "Brak takiej opcji w menu \n\n";
            Sleep(1500);
        }
        delete [] t_imie;
        delete [] t_nazwisko;
        delete [] t_telefon;
        delete [] temp;
    }

}
