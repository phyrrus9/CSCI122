#include "die.h"
/*
 CSCI 221 Project 2: Dice
 Due date: Monday, October 1, 2012
 File: die.cpp
 Description: Die class code file. This file contains all of the
 basic dice abilities, such as the contructor for the class, a
 few different functions to return values the user can use for
 statistical purposes, and a destructor (which is currently blank)
 Programmer: Ethan Laur
 */

die::die(int _sides, int __sides[])
/*
 * constructor number one, a more complicated version that allows
 * direct setting of the faces using an array and dynamically
 * allocating the faces array
 * Last modified: 10/2/12
 */
{
    sides = _sides;
    faces = new int[sides];
    for (int i = 0; i < sides; i++)
        faces[i] = __sides[i];
}

die::die(int _side)
/*
 * constructor number two, allows for a simple setup of the number
 * of sides on the die, useful when you don't exactly know all of
 * the faces upon program init (like if you wanted user entered ones).
 * Last modified: 10/2/12
 */
{
    sides = _side;
    faces = new int[sides];
    for (int i = 0; i < sides; i++)
        faces[i] = 0;
}

die::~die()
/*
 * simple blank destructor
 * Last modified: 10/2/12
 */
{
}

int die::roll(void)
/*
 * Roll function, returns a random number within the range of sides
 * usually, completely useless unless the result is put into the
 * face function.
 * Last modified: 10/2/12
 */
{
    return rand() % sides + 1;
}

int die::face(int rollval)
/*
 * Face function, accepts any integer value (usually from the roll
 * function), and without performing any range checks on it, will
 * return the integer in the faces array that matches with the
 * integer passed to the function.
 * Last modified: 10/2/12
 */
{
    return faces[rollval - 1];
}

void die::setface(int fnum, int face)
/*
 * setface function, accepts two integer parameters, one (fnum) that
 * is used as the faces array index, and the other (face), which is
 * used as the raw face value for the array. No returns.
 * Last modified: 10/2/12
 */
{
    faces[fnum] = face;
}