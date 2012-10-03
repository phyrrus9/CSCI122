/*
 CSCI 221 Project 2: Dice
 Due date: Monday, October 1, 2012
 File: die.h
 Description: die class header file, the definition of where
 life begins for these 102 sided little annoying pieces of code
 but, i digress
 Programmer: Ethan Laur
 */
#include <time.h>
#include <cstdlib>
class die
{
    int sides; //keeps track of the number of sides on the die
    int *faces; //keeps all of the face values
public:
    die(int _sides, int __sides[]); //initialization constructor
    die(int); //default constructor (with a side init)
    ~die(); //default destructor
    void setface(int, int); //set a specific face (used in larger die)
    int roll(void); //roll a random value
    int face(int); //return the face side of a value
};