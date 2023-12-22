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
    cards card[aoc];
    constexpr int all_cards = 52, cards_in_set = 13, colours_in_set = 4;
    int avaiable_cards = all_cards;
    int rand_card[all_cards];

    for (int i = 0; i < all_cards; i++)
    {
        rand_card[i] = i;
    }

    int balance = 10000, phase = 0;
    int r_id, temp, pc1 = 3, pc2 = 4;
    face_card r_numb;
    colour r_colour;
    owner Owner;

    do {
        phase = 0;
        avaiable_cards = all_cards;

        for (int i = 0; i < aoc; i++) // losowanie kart (0 - 2) karty wspólne, (3-4) gracz (5-6) johnny 
        {
            r_id = rand() % avaiable_cards;
            avaiable_cards--;
            temp = rand_card[r_id] % colours_in_set; // cerr << endl << r_colour;
            r_colour = (colour)temp;
            temp = (rand_card[r_id] % cards_in_set) + 2; // cerr << endl << r_numb;
            r_numb = (face_card)temp;
            swap(rand_card[r_id],rand_card[avaiable_cards]);

            switch (i)
            {
            default:
            case 0:
            case 1:
            case 2:
            {
                Owner = (owner)0;
                break;
            }
            case 3:
            case 4:
            {
                Owner = (owner)1;
                break;
            }
            case 5:
            case 6:
            {
                Owner = (owner)2;
                break;
            }
            }

            fill_card(card[i],r_colour,r_numb,Owner);
        }

        Game_GUI(name, balance, phase);
        show_ur_cards(card[pc1],card[pc2]);
        show_cards(card[0], card[1], card[2], phase);
        
        ptc(false);

    } while (true);
}

