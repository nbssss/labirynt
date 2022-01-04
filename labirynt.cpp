#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <conio.h> // odpowiada za mozliwosc zmiany kolorow w konsoli 
#include <Windows.h> // odpowiada za mozliwosc zmiany kolorow w konsoli 

using namespace std;
int postac = 254;

//genaralnie tutaj moznaby sie pobawic kolorkami i zrobic jakis ladnie kolorystycznie ten labirynt,
//bo cyfry sa odpowiednikami konkretnych kolorow
int kolor_tekstu = 6;
int kolor_postaci = 12;
int kolor_celu = 14;
int kolor_sciany = 6;


int wybMenu = 1;
bool wMenu = true;          
bool wGrze = false;
bool wlasciwa_decyzja = false;
bool koniec = false;

int gracz_x = 1;
int gracz_y = 1;
int gracz_nx;
int gracz_ny;

int introCzas = 400;
//uklad labiryntu <-- trzeba go zmodyfikowac i zmniejszyc 
int plansza[23][77] =
{ { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  { 1, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
  { 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1},
  { 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
  { 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1},
  { 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1},
  { 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1},
  { 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 3, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
  { 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1},
  { 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
  { 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1},
  { 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
  { 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1},
  { 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1},
  { 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1},
  { 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
  { 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
  { 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1},
  { 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1},
  { 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
  { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1},
  { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} };

HANDLE konsola = GetStdHandle(STD_OUTPUT_HANDLE);   // odpowiada za mozliwosc zmiany kolorow w konsoli 
void intro()
{
    SetConsoleTextAttribute(konsola, 10);
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    Sleep(introCzas);
    cout << "                " << (char)(219) << (char)(219) << "     " << " " << " " << (char)(219) << " " << "  " << (char)(219) << (char)(219) << (char)(219) << (char)(219) << "  " << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << (char)(219) << "  " << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << "  " << (char)(219) << " " << (char)(219) << (char)(219) << (char)(219) << (char)(219) << (char)(219) << (char)(219) << endl;
    Sleep(introCzas);
    cout << "                " << (char)(219) << (char)(219) << "     " << " " << (char)(219) << (char)(219) << (char)(219) << "  " << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << "    " << (char)(219) << (char)(219) << " " << (char)(219) << " " << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << (char)(219) << " " << (char)(219) << "   " << (char)(219) << (char)(219) << endl;
    Sleep(introCzas);
    cout << "                " << (char)(219) << (char)(219) << "     " << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << (char)(219) << (char)(219) << "  " << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << (char)(219) << "   " << (char)(219) << (char)(219) << (char)(219) << "  " << (char)(219) << (char)(219) << (char)(219) << (char)(219) << (char)(219) << "   " << (char)(219) << (char)(219) << endl;
    Sleep(introCzas);
    cout << "                " << (char)(219) << (char)(219) << "     " << (char)(219) << (char)(219) << (char)(219) << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << " " << (char)(219) << "   " << (char)(219) << "   " << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << "   " << (char)(219) << (char)(219) << endl;
    Sleep(introCzas);
    cout << "                " << (char)(219) << (char)(219) << (char)(219) << (char)(219) << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << (char)(219) << (char)(219) << "  " << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << " " << (char)(219) << "   " << (char)(219) << "   " << (char)(219) << (char)(219) << "  " << (char)(219) << "   " << (char)(219) << (char)(219) << endl;
}

void logo()
{
    cout << endl << endl;
    cout << "                " << (char)(219) << (char)(219) << "     " << " " << " " << (char)(219) << " " << "  " << (char)(219) << (char)(219) << (char)(219) << (char)(219) << "  " << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << (char)(219) << "  " << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << "  " << (char)(219) << " " << (char)(219) << (char)(219) << (char)(219) << (char)(219) << (char)(219) << (char)(219) << endl;
    cout << "                " << (char)(219) << (char)(219) << "     " << " " << (char)(219) << (char)(219) << (char)(219) << "  " << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << "    " << (char)(219) << (char)(219) << " " << (char)(219) << " " << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << (char)(219) << " " << (char)(219) << "   " << (char)(219) << (char)(219) << endl;
    cout << "                " << (char)(219) << (char)(219) << "     " << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << (char)(219) << (char)(219) << "  " << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << (char)(219) << "   " << (char)(219) << (char)(219) << (char)(219) << "  " << (char)(219) << (char)(219) << (char)(219) << (char)(219) << (char)(219) << "   " << (char)(219) << (char)(219) << endl;
    cout << "                " << (char)(219) << (char)(219) << "     " << (char)(219) << (char)(219) << (char)(219) << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << " " << (char)(219) << "   " << (char)(219) << "   " << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << "   " << (char)(219) << (char)(219) << endl;
    cout << "                " << (char)(219) << (char)(219) << (char)(219) << (char)(219) << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << (char)(219) << (char)(219) << "  " << (char)(219) << (char)(219) << " " << (char)(219) << (char)(219) << " " << (char)(219) << "   " << (char)(219) << "   " << (char)(219) << (char)(219) << "  " << (char)(219) << "   " << (char)(219) << (char)(219) << endl;
}
/*
void menu()
{
	cout << "Menu:" << endl;
	cout << "Wybierz postac" << endl;
	cout << "Jak grac?" << endl;
    cout << "Statystyki" << endl;
	cout << "Wyjscie" << endl;
}
*/

void zakonczenie()
{
    system("cls");
    cout << endl << endl << endl << endl;
    cout << "                               Do zobaczenia!" << endl << endl;
    logo();
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << "                                 By Kamil M.";
    Sleep(2500);
}

void rysujPlansza()
{
    for (int i = 0; i < 23; ++i)
    {
        cout << " ";
        for (int j = 0; j < 78; ++j)
            switch (plansza[i][j])
            {
            case 0: cout << " ";
                break;
            case 1: SetConsoleTextAttribute(konsola, kolor_sciany); // ta funkcja ustawia kolor scian labiryntu
                cout << (char)(219); //█
                break;
            case 2: SetConsoleTextAttribute(konsola, kolor_postaci);
                cout << (char)(postac); //■       248 °
                break;
            case 3: SetConsoleTextAttribute(konsola, kolor_celu);
                cout << (char)(207); //¤
                break;
            }
        cout << endl;
    }
}

void menu1()
{
    SetConsoleTextAttribute(konsola, kolor_tekstu);
    system("cls");
    logo();
    cout << endl << endl << endl << endl;
    cout << "                             Witaj w Labiryncie      " << endl << endl;
    cout << "                                   Menu:" << endl << endl;
    cout << "                           " << (char)(175) << "   Rozpocznij gre" << endl;
    cout << "                               Wybierz postac" << endl;
    cout << "                                    Info" << endl << endl;
    cout << "                                  Wyjscie" << endl;
}

void menu2()
{
    SetConsoleTextAttribute(konsola, kolor_tekstu);
    system("cls");
    logo();
    cout << endl << endl << endl << endl;
    cout << "                             Witaj w Labiryncie      " << endl << endl;
    cout << "                                   Menu:" << endl << endl;
    cout << "                               Rozpocznij gre" << endl;
    cout << "                           " << (char)(175) << "   Wybierz postac" << endl;
    cout << "                                    Info" << endl << endl;
    cout << "                                  Wyjscie" << endl;
}

void menu3()
{
    SetConsoleTextAttribute(konsola, kolor_tekstu);
    system("cls");
    logo();
    cout << endl << endl << endl << endl;
    cout << "                             Witaj w Labiryncie      " << endl << endl;
    cout << "                                   Menu:" << endl << endl;
    cout << "                               Rozpocznij gre" << endl;
    cout << "                               Wybierz postac" << endl;
    cout << "                           " << (char)(175) << "        Info" << endl << endl;
    cout << "                                  Wyjscie" << endl;
}

void menu4()
{
    SetConsoleTextAttribute(konsola, kolor_tekstu);
    system("cls");
    logo();
    cout << endl << endl << endl << endl;
    cout << "                             Witaj w Labiryncie      " << endl << endl;
    cout << "                                   Menu:" << endl << endl;
    cout << "                               Rozpocznij gre" << endl;
    cout << "                               Wybierz postac" << endl;
    cout << "                                    Info" << endl << endl;
    cout << "                           " << (char)(175) << "      Wyjscie" << endl;
}

void czyWyjsc()
{
    SetConsoleTextAttribute(konsola, kolor_tekstu);
    system("cls");
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << "                              Czy chcesz wyjsc?" << endl << endl;
    cout << "                           1 - tak        0 - nie" << endl;
    int decyzja;
    cout << "                                     ";
    cin >> decyzja;
    while (wlasciwa_decyzja == false)
    {
        switch (decyzja)
        {
        case 1:
        {
            system("cls");
            wMenu = false;
            wGrze = false;
            koniec = true;
            wlasciwa_decyzja = true;
        }
        break;
        case 0:
        {
            wlasciwa_decyzja = true;
        }
        break;
        default:
        {
            system("cls");
            cout << "                    To nie jest wlasciwa dana!" << endl;
            cout << "                      Czy chcesz wyjsc?" << endl << endl;
            cout << "                      1 - tak        0 - nie" << endl;
            cin >> decyzja;
        }
        break;
        }
    }
}

void wygrana()
{
    SetConsoleTextAttribute(konsola, kolor_tekstu);
    cout << endl << endl << endl << endl << endl;
    cout << "                                 GRATULACJE" << endl << endl;
    cout << "                           Czy chcesz jeszcze raz?" << endl << endl;
    cout << "                           1 - tak        0 - nie" << endl;
    int decyzja;
    cin >> decyzja;
    bool wlasciwa_decyzja = false;
    while (wlasciwa_decyzja == false)
    {
        switch (decyzja)
        {
        case 0:
        {
            plansza[gracz_x][gracz_y] = 0;
            plansza[1][1] = 2;
            gracz_x = 1;
            gracz_nx = 1;
            gracz_y = 1;
            gracz_ny = 1;
            wGrze = false;

            wlasciwa_decyzja = true;
        }
        break;
        case 1:
        {
            plansza[gracz_x][gracz_y] = 0;
            plansza[1][1] = 2;
            gracz_x = 1;
            gracz_nx = 1;
            gracz_y = 1;
            gracz_ny = 1;
            wlasciwa_decyzja = true;
        }
        break;
        default:
        {
            system("cls");
            cout << "                    To nie jest wlasciwa dana!" << endl;
            cout << "                      Czy chcesz jeszcze raz?" << endl << endl;
            cout << "                      1 - tak        0 - nie" << endl;
            cin >> decyzja;
        }
        break;
        }
    }
}

int ruchStrzalkami(int x, int y) // x i y beda pozycjami postaci na planszy
{
    bool koniec = false;
    while (koniec == false)
    {
        unsigned char znak = _getch();
        switch (znak)
        {
        case 224:        //224 to klawisze specjalne wg tablicy kodow ascii
            znak = _getch();
            switch (znak)
            {
            case 72: //strzałka w górę
                if (plansza[x - 1][y] == 3)
                {
                    wygrana();
                }
                else
                {
                    if (plansza[x - 1][y] == 0)
                    {
                        plansza[x][y] = 0;
                        plansza[x - 1][y] = 2;
                        gracz_nx = x - 1;
                        gracz_ny = y;
                    }
                }
                break;
            case 80: //strzałka w dół
                if (plansza[x + 1][y] == 3)
                {
                    wygrana();
                }
                else
                {
                    if (plansza[x + 1][y] == 0)
                    {
                        plansza[x][y] = 0;
                        plansza[x + 1][y] = 2;
                        gracz_nx = x + 1;
                        gracz_ny = y;
                    }
                }
                break;
            case 75: //strzałka w lewo
                if (plansza[x][y - 1] == 3)
                {
                    wygrana();
                }
                else
                {
                    if (plansza[x][y - 1] == 0)
                    {
                        plansza[x][y] = 0;
                        plansza[x][y - 1] = 2;
                        gracz_nx = x;
                        gracz_ny = y - 1;
                    }
                }
                break;
            case 77: //strzałka w prawo
                if (plansza[x][y + 1] == 3)
                {
                    wygrana();
                }
                else
                {
                    if (plansza[x][y + 1] == 0)
                    {
                        plansza[x][y] = 0;
                        plansza[x][y + 1] = 2;
                        gracz_nx = x;
                        gracz_ny = y + 1;
                    }
                }
                break;
            }
            znak = 0;
            break;
        case 27: //ESC
            czyWyjsc();
            break;
        }
    }
    return 0;
}

void info()
{
    system("cls");
    logo();
    cout << endl << endl << endl;
    cout << "                             Witaj w Labiryncie      " << endl << endl;
    cout << "                     Gra zostala napisana w jezyku C++" << endl;
    cout << "               Jestem poczatkujacym programista i samoukiem" << endl;
    cout << "                          Mozliwe sa wiec bledy" << endl;
    cout << "                  Plan jest, ze bede to dalej rozwijal" << endl;
    cout << "                               Milej gry" << endl << endl << endl << endl;
    cout << "                Dowolny przycisk aby powrocic do menu :) " << endl;
    _getch();
    menu3();
}

void wyborPostaci()
{
    int wybierzPostac;
    system("cls");
    logo();
    cout << endl << endl << endl;
    cout << "                            Witaj w Labiryncie      " << endl << endl << endl;
    cout << "                              Wybierz postac:" << endl << endl;
    cout << "                                  1 -> "; SetConsoleTextAttribute(konsola, kolor_postaci); cout << (char)(248) << endl; SetConsoleTextAttribute(konsola, kolor_tekstu);          //°
    cout << "                                  2 -> "; SetConsoleTextAttribute(konsola, kolor_postaci); cout << (char)(254) << endl; SetConsoleTextAttribute(konsola, kolor_tekstu);          //■
    cout << "                                  3 -> "; SetConsoleTextAttribute(konsola, kolor_postaci); cout << (char)(1) << endl; SetConsoleTextAttribute(konsola, kolor_tekstu);          //☺
    cout << "                                  4 -> "; SetConsoleTextAttribute(konsola, kolor_postaci); cout << (char)(2) << endl; SetConsoleTextAttribute(konsola, kolor_tekstu);          //☻
    cout << "                                  5 -> "; SetConsoleTextAttribute(konsola, kolor_postaci); cout << (char)(4) << endl << endl; SetConsoleTextAttribute(konsola, kolor_tekstu);      //♦
    cout << "                             Co wybierasz?    : ";; SetConsoleTextAttribute(konsola, kolor_postaci); cin >> wybierzPostac; SetConsoleTextAttribute(konsola, kolor_tekstu);

    switch (wybierzPostac)
    {
    case 1:
        postac = 248;
        break;
    case 2:
        postac = 254;
        break;
    case 3:
        postac = 1;
        break;
    case 4:
        postac = 2;
        break;
    case 5:
        postac = 4;
        break;
    }
    cout << "            Wybrales : "; SetConsoleTextAttribute(konsola, kolor_postaci); cout << (char)(postac); SetConsoleTextAttribute(konsola, kolor_tekstu); cout << "   Dwolny przycik by kontynuowac";
    _getch();
    menu2();
}

void menuNowe()
{
    unsigned char wybor = _getch();  //wyb1 - sterowanie gora/dol menu
    
    switch (wybor)
    {
    case 0:
    case 224:

        wybor = _getch();
        switch (wybor)
        {
        case 72: //strzalka w gore
            if (wybMenu > 1) wybMenu--;

            switch (wybMenu)
            {
            case 1:
                menu1();
                break;
            case 2:
                menu2();
                break;
            case 3:
                menu3();
                break;
            case 4:
                menu4();
                break;
            }
            break;
        case 80: //strzałka w dół
            if (wybMenu < 4) wybMenu++;

            switch (wybMenu)
            {
            case 1:
                menu1();
                break;
            case 2:
                menu2();
                break;
            case 3:
                menu3();
                break;
            case 4:
                menu4();
                break;
            }
            break;
        }
        wybor = 0;
        break;
    case 13: //ENTER
        switch (wybMenu)
        {
        case 1:
            wMenu = false;
            wGrze = true;
            break;
        case 2:
       //     wyborPostaci();
            break;
        case 3:
        //    info();
            break;
        case 4:
       //     czyWyjsc();
            break;
        }
        break;
    case 27: //ESC
      //  czyWyjsc();
        break;
    }
}


int main()
{
    SetConsoleTextAttribute(konsola, kolor_tekstu);

    while (koniec == false)
    {
        wMenu = true;
        menu1();
        while (wMenu == true)
        {
            menuNowe();
        }
        while (wGrze == true)
        {
            rysujPlansza();
            ruchStrzalkami(gracz_x, gracz_y);
            gracz_x = gracz_nx;
            gracz_y = gracz_ny;
        }
    }
    zakonczenie();
    return 0;
}

