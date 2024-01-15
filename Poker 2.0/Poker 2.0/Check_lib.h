#pragma once
#include "Library_en.h"
#include <iostream>
#include <math.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <Windows.h>
#include "Library.h"

using namespace std;

bool High_card(int cards[], float* add);	//+
bool Pair(int cards[], float* add);			//+
bool Two_Pairs(int cards[], float* add);	//+
bool Three(int cards[], float* add);		//+
bool Straight(int cards[], float* add);		//+
bool Flush(int Colour[], float* add);		//+
bool Full_house(int cards[], float* add);	//+
bool Four(int cards[], float* add);			//+
bool Straight_flush(int cards[], int Colour[], float* add);

bool High_card(int cards[], float* add)
{
	int card[7];
	int counter = 0;
	for (int i = 0; i < 7; i++)
	{
		card[i] = cards[i];
	}
	*add = card[6];
	return true;
}

bool Pair(int cards[], float* add)
{
	int card[7];
	int counter = 0;
	for (int i = 0; i < 7; i++)
	{
		card[i] = cards[i];
	}

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (card[j] > card[j + 1]) swap(card[j], card[j + 1]);
		}
	}

	bool if_correct = true;

	for (int i = 5; i > -1; i--)
	{
		if (card[i] == card[i + 1])
		{
			counter++;
			*add = card[i];
			break;
		}
	}

	if (counter == 1)
	{
		if_correct = true;
	}
	else
	{
		if_correct = false;
	}

	return if_correct;
}

bool Two_Pairs(int cards[], float* add)
{
	int card[7];
	int counter = 0;
	for (int i = 0; i < 7; i++)
	{
		card[i] = cards[i];
	}

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (card[j] > card[j + 1]) swap(card[j], card[j + 1]);
		}
	}

	bool if_correct = true;

	for (int i = 0; i < 6; i++)
	{
		if (card[i] == card[i + 1])
		{
			counter++;
			*add = card[i];
			break;
		}
	}
	int temp = 0;
	if (counter == 1)
	{
		for (int i = 0; i < 6; i++)
		{
			if ((card[i] == card[i + 1]) && (*add != card[i]))
			{
				counter++;
				temp = *add;
				*add = card[i];
				break;
			}
		}
		if (counter == 2)
		{
			for (int i = 0; i < 6; i++)
			{
				if ((card[i] == card[i + 1]) && (*add != card[i]) && (temp != card[i]))
				{
					counter++;
					*add = card[i];
					break;
				}
			}
		}
		else
		{
			if_correct = false;
		}
	}
	else
	{
		if_correct = false;
	}

	return if_correct;
}

bool Three(int cards[], float* add)
{
	int card[7];
	int counter = 0;
	for (int i = 0; i < 7; i++)
	{
		card[i] = cards[i];
	}

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (card[j] > card[j + 1]) swap(card[j], card[j + 1]);
		}
	}

	bool if_correct = true;

	for (int i = 0; i < 5; i++)
	{
		if (card[i] == card[i + 1])
		{
			if (card[i + 1] == card[i + 2]) 
			{
				counter++;
				*add = card[i];
			}
		}
	}

	if (counter == 1)
	{
		if_correct = true;
	}
	else
	{
		if_correct = false;
	}

	return if_correct;
}

bool Straight(int cards[], float* add)
{
	int card[7];
	for (int i = 0; i < 7; i++)
	{
		card[i] = cards[i];
	}

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (card[j] > card[j + 1]) swap(card[j], card[j + 1]);
		}
	}
	bool if_corr = false;
	for (int i = 0; i < 4; i++)
	{
		if (card[i + 2] == (card[i + 3] + 1))
		{
			if_corr = true;
		}
		else
		{
			if_corr = false;
			break;
		}
	}

	if (!if_corr)
	{
		for (int i = 0; i < 4; i++)
		{
			if (card[i + 1] == (card[i + 2] + 1))
			{
				if_corr = true;
			}
			else
			{
				if_corr = false;
				break;
			}
		}
	}

	if (!if_corr)
	{
		for (int i = 0; i < 4; i++)
		{
			if (card[i] == (card[i + 1] + 1))
			{
				if_corr = true;
			}
			else
			{
				if_corr = false;
				break;
			}
		}
	}

	return if_corr;
}

bool Flush(int Colour[], float* add)
{
	int Colours[7];
	bool if_correct = false;
	for (int i = 0; i < 7; i++)
	{
		Colours[i] = Colour[i];
	}

	int counter = 0;
	for (int i = 0; i < 7; i++)
	{
		counter = 0;
		for (int j = 0; j < 7; j++)
		{
			if ((Colours[i] == Colours[j]) && (i != j)) counter++;
		}
		if (counter > 3)
		{
			if_correct = true;
			*add = Colours[i];
			break;
		}
	}

	return if_correct;
}

bool Full_house(int cards[], float* add)
{
	int Cards[7];
	float additional = *add;
	for (int i = 0; i < 7; i++)
	{
		Cards[i] = cards[i];
	}
	bool if_correct = false, temp1 = false, temp2 = false;

	temp1 = Three(Cards, &additional);
	temp2 = Pair(Cards, &additional);

	if ((temp1 == true) && (temp2 == true)) return true;
	else return false;
}

bool Four(int cards[], float* add)
{
	int card[7];
	int counter = 0;
	for (int i = 0; i < 7; i++)
	{
		card[i] = cards[i];
	}

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (card[j] > card[j + 1]) swap(card[j], card[j + 1]);
		}
	}

	bool if_correct = true;

	for (int i = 0; i < 4; i++)
	{
		if (card[i] == card[i + 1])
		{
			if (card[i + 1] == card[i + 2])
			{
				if (card[i + 2] == card[i + 3])
				{
					counter++;
					*add = card[i];
					break;
				}
			}
		}
	}

	if (counter == 1)
	{
		if_correct = true;
	}
	else
	{
		if_correct = false;
	}

	return if_correct;
}

bool Straight_flush(int cards[], int Colour[], float* add)
{

	int Cards[7], Colours[7];
	float additional = *add;
	for (int i = 0; i < 7; i++)
	{
		Cards[i] = cards[i];
		Colours[i] = Colour[i];
	}

	bool if_correct = false, temp1 = false, temp2 = false;

	temp1 = Straight(Cards, &additional);
	temp2 = Flush(Cards, &additional);

	if ((temp1 == true) && (temp2 == true)) return true;
	else return false;
}

float Check(cards& a, cards& b, cards& c, cards& d, cards& e, cards& f, cards& g)
{
	constexpr int cards = 7;
	int faces[cards], Colour[cards];
	float main = 0, additional = 0;
	faces[0] = a.facecards;
	faces[1] = b.facecards;
	faces[2] = c.facecards;
	faces[3] = d.facecards;
	faces[4] = e.facecards;
	faces[5] = f.facecards;
	faces[6] = g.facecards;

	Colour[0] = a.colours;
	Colour[1] = b.colours;
	Colour[2] = c.colours;
	Colour[3] = d.colours;
	Colour[4] = e.colours;
	Colour[5] = f.colours;
	Colour[6] = g.colours;

	bool correct;
	int temp = 9;
	switch (temp)
	{
	case 9:
	{
		// cerr << "\nspr 1";
		correct = Straight_flush(faces, Colour, &additional);
		main = 9;
		if (correct) break;
	}
	case 8:
	{
		correct = Four(faces, &additional);
		main = 8;
		if (correct) break;
	}
	case 7:
	{
		correct = Full_house(faces, &additional);
		main = 7;
		if (correct) break;
	}
	case 6:
	{
	//	cerr << "\nspr2";
		correct = Flush(Colour, &additional);
		main = 6;
		if (correct) break;
	}
	case 5:
	{
		correct = Straight(faces, &additional);
		main = 5;
		if (correct) break;
	}
	case 4:
	{
		correct = Three(faces, &additional);
		main = 4;
		if (correct) break;
	}
	case 3:
	{
		correct = Two_Pairs(faces, &additional);
		main = 3;
		if (correct) break;
	}
	case 2:
	{
		correct = Pair(faces, &additional);
		main = 2;
		if (correct) break;
	}
	case 1:
	{
		correct = Four(faces, &additional);
		main = 1;
		if (correct) break;
	}
	case 0:
	{
		correct = High_card(faces, &additional);
		main = 0;
		if (correct) break;
	}
	default:
	{
		break;
	}
	}

	main += additional * 0.01;
	return main;
}