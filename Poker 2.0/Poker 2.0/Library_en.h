#pragma once
#include "Library.h"

enum colour
{
    hearts = 0,     // kier
    diamonds = 1,   // karo
    clubs = 2,      // trefl
    spades = 3,     // pik
};

enum face_card
{
    two = 2,
    three = 3,
    four = 4,
    five = 5,
    six = 6,
    seven = 7,
    eight = 8,
    nine = 9,
    ten = 10,
    jack = 11,     
    queen = 12,
    king = 13,
    ace = 14,
};

enum owner
{
    None = 0,
    Player = 1,
    Johnny = 2,
};

enum moves
{
    fault = 0,
    rise = 1,
    check_call = 2,
    fold = 3,
};

enum Hand_values
{
    high_card =  1,
    pair = 2,
    two_pairs = 3,
    three_of_kaind = 4,
    straight = 5,
    flush = 6,
    full_house = 7,
    four_of_kaind = 8,
    straight_flush = 9,
};

struct cards
{
    colour  colours;
    face_card facecards;
    owner owners;
};

