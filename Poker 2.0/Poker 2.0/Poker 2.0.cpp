#include <iostream>
#include "Library.h"
#include "Library_en.h"
#include "Check_lib.h"
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
    char choice = '0';
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
 
    constexpr int aoc = 9;
    cards card[aoc];
    constexpr int all_cards = 52, cards_in_set = 13, colours_in_set = 4;
    int avaiable_cards = all_cards;
    int rand_card[all_cards];

    for (int i = 0; i < all_cards; i++)
    {
        rand_card[i] = i;
    }

    int balance = 10000, SI_balance = 10000, phase = 0;
    int r_id, temp, pc1 = 5, pc2 = 6;
    moves Move = fault;
    face_card r_numb;
    colour r_colour;
    owner Owner;
    bool eop = false, player_beat = false, SI_beat = false, Player_Win, SI_Win, tie = false;
    int all_beat = 0;
    bool stop = false;
    float Player_score = 0, SI_score = 0;

    do {
        tie = false;
        Player_Win = false;
        SI_Win = false;
        stop = false;
        phase = 0;
        all_beat = 0;
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
            case 3:
            case 4:
            {
                Owner = (owner)None;
                break;
            }
            case 5:
            case 6:
            {
                Owner = (owner)Player;
                break;
            }
            case 7:
            case 8:
            {
                Owner = (owner)Johnny;
                break;
            }
            }

            fill_card(card[i],r_colour,r_numb,Owner);
        }
        // losowanie kart

        for (phase; phase < 5; phase++)
        {
            int  beat_sum = 0;
            do {

                if (balance == 0 || SI_balance == 0) stop = true;
                if(!stop)
                  {
                    player_beat = false;
                    SI_beat = false;
                    eop = false;
                    Game_GUI(name, balance, SI_name, SI_balance, phase, all_beat);
                    show_ur_cards(card[pc1], card[pc2]);
                    show_cards(card[0], card[1], card[2], card[3], card[4], phase);

                    player_beat = move((owner)Player, &Move);
                    if (player_beat)
                    {
                        int rest = 0;
                        switch (Move)
                        {
                        default:
                        case rise:
                        {
                            bool prop_numb = false;
                            rest = call(&balance, &beat_sum, &all_beat);
                            SI_balance += rest;
                            rest = 0;
                            do {
                                Game_GUI(name, balance, SI_name, SI_balance, phase, all_beat);
                                show_ur_cards(card[pc1], card[pc2]);
                                show_cards(card[0], card[1], card[2], card[3], card[4], phase);
                                SI_beat = false;
                                cout << "Podaj wartość zakładu: ";
                                cin >> beat_sum;
                                if (beat_sum << balance)
                                {
                                    prop_numb = true;
                                    balance -= beat_sum;
                                    all_beat += beat_sum;
                                }
                            } while (!prop_numb);

                            break;
                        }
                        case check_call:
                        {
                            rest = call(&balance, &beat_sum, &all_beat);
                            SI_balance += rest;
                            rest = 0;
                            break;
                        }
                        }
                        player_beat = false;

                        // --------------------------------------

                        SI_beat = move((owner)Johnny, &Move);
                        switch (Move)
                        {
                        default:
                        case rise:
                        {
                            // cerr << "SI rise";
                            bool prop_numb = false;
                            rest = call(&SI_balance, &beat_sum, &all_beat);
                            balance += rest;
                            rest = 0;
                            do {
                                if (SI_balance < 1000)
                                {
                                    beat_sum = SI_balance;
                                    stop = true;
                                }
                                else if (SI_balance < 4000)
                                {
                                    beat_sum = rand() % (SI_balance / 5);
                                }
                                else
                                {
                                    beat_sum = rand() % (SI_balance/3);
                                }

                                if (beat_sum << SI_balance)
                                {
                                    prop_numb = true;
                                    SI_balance -= beat_sum;
                                    cout << "\nJohnny podbija o: " << beat_sum;
                                    all_beat += beat_sum;
                                    ptc(false);
                                }
                            } while (!prop_numb);
                            player_beat = true;
                            break;
                        }
                        case check_call:
                        {
                           // cerr << "SI check/call";
                            rest = call(&SI_balance, &beat_sum, &all_beat);
                            balance += rest;
                            rest = 0;
                            break;
                        }
                        case fold:
                        {
                            // cerr << "SI_ fold";
                            stop = true;
                            Player_Win = true;
                            break;
                        }
                        }
                        SI_beat = false;

                    }
                    else
                    {
                        stop = true;
                        SI_Win = true;
                    }


                    if (player_beat == false && SI_beat == false) eop = true;
                   // cerr << endl << player_beat << " " << SI_beat << " " << eop;
                }
            } while (!eop);
            
           // cerr << endl <<"faza przebiegła pomyślnie";
        }
        
        
       // cerr << endl << "Przed spr: " << Player_Win << " " << SI_Win;
        if ((Player_Win == false) && (SI_Win == false))
        {
          //  cerr << "\nrozpoczęcie sprawdzania\n";
            Player_score = Check(card[0], card[1], card[2], card[3], card[4], card[5], card[6]);
            SI_score = Check(card[0], card[1], card[2], card[3], card[4], card[7], card[8]);

            if (SI_score < Player_score)
            {
                Player_Win = true;
            }
            else if (Player_score > SI_score)
            {
                SI_Win = true;
            }
            else
            {
                tie = true;
            }
        }
        
        if (Player_Win == true)
        {
            balance = balance + all_beat;
            cout << endl << endl << "Wygrał gracz: " << name;
        }
        else if (SI_Win == true)
        {
            SI_balance = SI_balance + all_beat;
            cout << endl << endl << "Wygrał gracz: " << SI_name;
        }
        else if (tie == true)
        {
            balance = balance + (all_beat / 2);
            SI_balance = SI_balance + (all_beat / 2);
            cout << endl << endl << "Remis!!!";
        }
        ptc(false);
    } while (true);
}

