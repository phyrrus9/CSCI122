/*
 CSCI 221 Project 2: Dice
 Due date: Monday, October 1, 2012
 File: main.cpp
 Description: This file is responsible for controlling about eleven million
 dice rolls and computing statistics on those rolls, then displaying the
 frequency tables on screen so the user can see that most die rolls, no matter
 the sides, will usually come up the same..or something like that. The point
 of this program is to demonstrate new and delete usage along with array
 handling. Abstract programming...fun stuff
 Programmer: Ethan Laur
 */


#include "die.h"
#include <iostream>
#include <iomanip>
#define MILLION 100000

using namespace std;


int main(int argc, const char * argv[])
/*
 * Function main, the only one we were allowed
 * obviously, this does all of the handling for
 * the program, responsible for calling all of
 * the die functions and computing statistics
 * Last modified: 9/27/12
 */
{
    die *first; //pointer for the first die
    die *second; //pointer for the second diehttp://www.facebook.com/video/video.php?v=4157813702645
    die *third; //pointer for the third die
    die *fourth;//pointer for the fourth die
    int loop;   //variable used for looping controls
    int *countA;//used for statistics
    int *countB;//also used in stats
    int total;  //used in math operations
    
    srand(2);
    
    /*
     * begin ex 1 of this program
     */
    countA = new int[6];
    for (loop = 0; loop < 6; loop++) //set up the die faces from 1-6
        countA[loop] = loop + 1;
    first = new die(6, countA); //init the first and second dice
    second = new die(6, countA);
    countA[2] = 2; //this part is where it gets weird
    countA[3] = 3; //I know there is probably some way
    countA[4] = 3; //to do this with like an algorithm
    countA[5] = 4; //or something, but i do not know how
    third = new die(6, countA);
    countA[0] = 1;
    countA[1] = 3;
    countA[2] = 4;
    countA[3] = 5;
    countA[4] = 6;
    countA[5] = 8;
    fourth = new die(6, countA);
    delete countA; //delete the count var so we can use it for stats
    countA = new int[13];
    countB = new int[13];
    for (loop = 0; loop < 13; loop++)
    {
        //zero out the array so we dont get weird stats
        countA[loop] = 0;
        countB[loop] = 0;
    }
    for (loop = 0; loop < 5; loop++)
    {
        //roll the dice, face them, then increment the array
        countA[first->face(first->roll()) + second->face(first->roll())]++;
        countB[third->face(third->roll()) + fourth->face(fourth->roll())]++;
    }
    //now, display all of the stats
    cout << "Excersize 1: frequency table" << endl;
    for (loop = 2; loop < 13; loop++)
    {
        cout << setw(5) << left << fixed << loop << " ";
    }
    cout << endl;
    for (loop = 2; loop < 13; loop++)
    {
        cout << setw(5) << left << setprecision(2) << fixed << ((double)countA[loop] / MILLION) * 100 << " ";
    }
    cout << endl;
    for (loop = 2; loop < 13; loop++)
    {
        cout << setw(5) << left << setprecision(2) << fixed << ((double)countB[loop] / MILLION) * 100 << " ";
    }
    cout << endl << endl;
    //now, lets delete all of our vars so we can use them in ex2
    delete first;
    delete second;
    delete third;
    delete fourth;
    delete countA;
    delete countB;
    
    /*
     ex2
     */
    countA = new int[8];
    for (loop = 0; loop < 8; loop++) //from 1-8
        countA[loop] = loop + 1;
    first = new die(8, countA);
    second = new die(8, countA);
    third = new die(8, countA);
    fourth = new die(0); //placeholder allocation
    delete countA;
    countA = new int[26];
    for (loop = 0; loop < MILLION; loop++)
    {
        //once again, take care of all the stuff for stats
        total = first->face(first->roll()) + second->face(second->roll()) + third->face(third->roll());
        countA[total]++; //do some statwork
    }
    total = 0; //so we can (stupidly) re-use total
    //display the frequency table
    cout << "Excersize 2: frequency table" << endl;
    for (loop = 4; loop < 25; loop++)
    {
        cout << setw(5) << left << fixed << loop << " ";
    }
    cout << endl;
    for (loop = 4; loop < 25; loop++)
    {
        cout << setw(5) << left << setprecision(2) << fixed << ((double)countA[loop] / MILLION) * 100 << " ";
    }
    cout << endl;
    //delete some variables so we can reconfigure the dice
    delete countA;
    delete first;
    delete second;
    delete third;
    delete fourth;
    countA = new int[6];
    for (loop = 0; loop < 6; loop++) //1-6
        countA[loop] = loop + 1;
    first = new die(6, countA);
    second = new die(6, countA);
    third = new die(6, countA);
    fourth = new die(6, countA);
    delete countA;
    countA = new int[26];
    for (loop = 0; loop < MILLION; loop++)
    {
        total= first->face(first->roll()) + second->face(second->roll()) + third->face(third->roll()) + fourth->face(fourth->roll()) + 1;
        countA[total]++;
    }
    for (loop = 5; loop < 26; loop++)
    {
        cout << setw(5) << left << setprecision(2) << fixed << ((double)countA[loop] / MILLION) * 100 << " ";
    }
    cout << endl;
    //delete variables for re-use
    delete countA;
    delete first;
    delete second;
    delete third;
    delete fourth;
    
    /*
     ex3
     */
    countA = new int[7];
    for (loop = 0; loop < 7; loop++) //oh fun, the other ex
        countA[loop] = loop + 1; //configure one 1-7
    first = new die(7, countA);
    delete countA;
    //now, we config some really really really weird die.
    countA = new int[7];
    countA[0] = 2;
    countA[1] = 3;
    countA[2] = 5;
    countA[3] = 7;
    countA[4] = 11;
    countA[5] = 13;
    countA[6] = 17;
    second = new die(7, countA);
    delete countA;
    countA = new int[102];
    countB = new int;
    total = 0;
    countB[0] = 0;
    //I worked my way into making this part a little bit shorter
    //and by shorter I mean condensing 102 lines of code into
    //20, so it is a tad confusing at times. sorry
    for (loop = 0; loop < 1; loop++, countB[0]++)
        countA[loop] = 12;
    total += countB[0];
    for (loop = total, countB[0] = 0; loop < total + 1; loop++, countB[0]++)
        countA[loop] = -7;
    total += countB[0];
    for (loop = total, countB[0] = 0; loop < total + 1; loop++, countB[0]++)
        countA[loop] = 19;
    total += countB[0];
    for (loop = total, countB[0] = 0; loop < total + 33; loop++, countB[0]++)
        countA[loop] = -3;
    total += countB[0];
    for (loop = total, countB[0] = 0; loop < total + 31; loop++, countB[0]++)
        countA[loop] = 6;
    total += countB[0];
    for (loop = total, countB[0] = 0; loop < total + 2; loop++, countB[0]++)
        countA[loop] = -2;
    total += countB[0];
    for (loop = total, countB[0] = 0; loop < total + 33; loop++, countB[0]++)
        countA[loop] = 1;
    total += countB[0];
    third = new die(total, countA);
    delete countB;
    delete countA;
    countA = new int[26];
    countB = new int[2];
    countB[0] = 0;
    countB[1] = 0;
    total = 0;
    for (loop = 0; loop < 25; loop++)
        countA[loop] = 0;
    for (loop = 0; loop < MILLION; loop++)
    {
        //roll another million loops, face them, 
        countB[0] = first->face(first->roll()) + second->face(second->roll()) + third->face(third->roll());
        if (countB[0] > total)
            total = countB[0];
        if (countB[0] >= 15)
        {
            countB[1]++;
            countA[countB[0] - 15]++;
        }
    }
    total = 0;
    //display the frequency table
    cout << "Exercise 3: frequency table" << endl;
    for (loop = 0; loop < 25; loop++)
    {
        cout << setw(5) << left << fixed << loop + 16 << " ";
    }
    cout << endl;
    for (loop = 0; loop < 25; loop++)
    {
        cout << setprecision(2) << setw(5) << fixed << ((double)countA[loop] / countB[1]) * 100 << " ";
    }
    cout << endl;
}