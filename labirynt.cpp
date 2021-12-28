#include <iostream>
#include <conio.h>

using namespace std;
void menu()
{
	cout << "Menu:" << endl;
	cout << "Wybierz postac" << endl;
	cout << "Jak grac?" << endl;
	cout << "Wyjscie" << endl;
	cout << "Tworcy" << endl;
}

int ruch_strzalkami(int x, int y)
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
                //...
                break;
            case 80: //strzałka w dół
                //...
                break;
            case 75: //strzałka w lewo
                //...
                break;
            case 77: //strzałka w prawo
                //...
                break;
            }
            znak = 0;
            break;
        case 13: //ENTER
            break;
        case 27: //ESC
            koniec = true;
            //...
            break;
        }
    }
    return 0;
}
int main()
{
    int x = 1;
    int y = 1;
    ruch_strzalkami(x,y);
	return 0;
}

