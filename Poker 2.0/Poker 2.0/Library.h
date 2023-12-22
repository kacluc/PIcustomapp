#pragma once
#include "Library_en.h"
#include <iostream>
#include <math.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <Windows.h>

using namespace std;

void ptc(bool);
void info_panel(string, int);
void phase_panel(int);
void Game_GUI(string, int, int);
void Start_menu();
void swap(int, int);
void fill_card(cards& c, colour colour, face_card facecard, owner owner);

void ptc(bool clear)
{
	cout << endl << "naci�nij dowolny klawisz by kontynuowa�";
	_getch();
	if (clear) system("cls");
}

void info_panel(string name, int balance)
{
	cout << name << " twoje saldo wynosi: " << balance << " Dogecoin'�w" << endl;
	cout << "------------------------------------------------" << endl;
}

void phase_panel(int phase_status)
{
	cout << "Obecna faza: ";
	switch (phase_status)
	{
	default:
	case 0:
	{
		cout << "Pre-flop";
		break;
	}
	case 1:
	{
		cout << "flop";
		break;
	}
	case 2:
	{
		cout << "turn";
		break;
	}
	case 3:
	{
		cout << "river";
		break;
	}
	}
	cout << endl << "------------------------------------------------" << endl;
}

void Game_GUI(string name, int balance, int phase_status)
{
	system("cls");
	info_panel(name, balance);
	phase_panel(phase_status);
}

void Start_menu()
{
	cout << "INFORMACJA WST�PNA!!" << endl << "Rozgrywka odbywa si� mi�dzy graczem a komputerem o nazwie Johnny" << endl;
	ptc(false);
	system("cls");
	cout << "Witaj w konsolowej grze: Poker Texass Hold'em!!!" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Dost�pne opcje: " << endl;
	cout << "1: Zaczynamy gierk�!" << endl;
	cout << "2: Jendak nie mam ochoty na gr�" << endl;
	cout << "------------------------------------------------" << endl;
}

void swap(int* fir, int* sec)
{
	int temp;
	temp = *fir;
	*fir = *sec;
	*sec = temp;
}

void fill_card(cards& c, colour colour, face_card facecard, owner owner)
{
	c.colours = colour;
	c.facecards = facecard;
	c.owners = owner;
}
