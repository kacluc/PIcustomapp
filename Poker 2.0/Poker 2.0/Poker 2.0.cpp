#include <iostream>
#include "Library.h"
#include "Library_en.h"
#include <math.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <Windows.h>


using namespace std;

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "pl_PL");

    string name, SI_name = "Johnny";
    char choice;
    do {
        Start_menu();
        choice = _getch();
        switch (choice)
        {
        case '1':
        {
            system("cls");
            cout << "Wprowadź nazwę użytkownika: ";
            cin >> name;
            break;
        }
        case '2':
        {
            exit(0);
            break;
        }
        default:
        {
            cout << "proszę wybrać z listy!";
            Sleep(2500);
            break;
        }
        }
    } while (choice != '1');

    constexpr int aoc = 7;
    constexpr int all_cards = 52;
    cards card[aoc];

    int balance = 10000, phase = 0;
    int r_suit, r_numb;
    do {
        phase = 0;
        Game_GUI(name, balance, phase);

        ptc(false);

    } while (true);
}

