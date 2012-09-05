/*
 CSCI 221 Project 1: Letters
 Start date: Monday, August 27, 2012
 Due date: Monday, September 17, 2012
 File: letter.cpp
 Description: Read file and parse each character for letters, and vowels, then sort the lists
 into a top five and display all of the statistics on screen. Comments are much more detailed
 than this block when you begin reading through functions where more lengthy, and specific
 comments live.
 Programmer: Ethan Laur
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <stdlib.h>

using namespace std;

bool isvowel(char c)
{
    /*
     * Function isvowel: Check character for vowel status
     * if the character is a vowel, the function will
     * return true, otherwise false if the character
     * reaches the end of the file.
     * Parameters:
     * char c: input character tested against a list of
     *         known vowels and determine end result
     * Return: bool. If the variable is a vowel return
     * will be true otherwise it will be false.
     * Last modified: 08/27/12
     */
    
    c = tolower(c);
    if (c == 'a')
        return true;
    if (c == 'e')
        return true;
    if (c == 'i')
        return true;
    if (c == 'o')
        return true;
    if (c == 'u')
        return true;
    if (c == 'y')
        return true;
    return false;
    EOF;
}

int main(int argc, const char * argv[])
{
    /*
     * Program function main, parses the input filename
     * from the command line (argc and argv parameters),
     * and is then responsible for reading lines from 
     * the file, counting characters, letters, and vowels
     * and then sorting them into the top 5 by greatest
     * to least (using the bubble sort algorithm) and
     * displaying all of the statistics on the terminal
     * for the user to understand or use at will.
     * Parameters:
     * int argc: the count of how many arguments that
     *           are given to the program via the OS
     *           command line.
     * const char * * argv: The array holding all of the
     *           command line arguments given by the OS
     *           shell and are parsible by the program.
     * Return value: int used to notify the OS what type
     * of exit or error occured during program execution
     * Last modified: 09/04/12
     */
    
    if (argc < 2)
    {
        cout << "Error! Too few arguments." << endl
             << "Please specify the file you wish to parse." << endl
             << "Your command line should look something like this:" << endl
        << argv[0] << " file.txt" << endl;
        exit(-1);
    }
    
    /* variable definitions. Sorry they are not at the top but segfaults hurt */
    char * filename = new char[strlen(argv[1] + 5)]; //dynamic allocation
    int num_letters = 0, num_vowels = 0, num_words = 0; //total count
    char letters_c[26]; //character (A-Z) for display
    int letters_i[26];  //total counts for A-Z letters
    const int line_length = 5000; //5kb buffer count, increase for a larger buffer
    char * line = new char[line_length + 5]; //5.1kb buffer
    int word_buffer_count; //for checking if it is a word or not
    ifstream inputfile;
    bool last_character_is_letter = false; //used to count last word..
    /* end variable definitions */
    
    strcpy(filename, argv[1]);
    inputfile.open(filename);
    
    if (!inputfile)
    {
        cout << "Error! Could not open input file" << endl
             << "Check to ensure that the input file exists and that"
        << "you have permission to read it." << endl;
        exit(-1);
    }
    

    for (int i = 0, j = 65; i < 26; i++, j++)
    {
        //initialize all of our letter arrays
        letters_c[i] = (char)j;
        letters_i[i] = 0;
    }
    
    word_buffer_count = 0;
    while (!inputfile.eof())
    {
        /*
         * While we are not at the end of the file,
         * continue to read lines up to 5kb in size
         * and parse them for letters and numbers 
         * and deal with them at that point.
         * At the same time, this will also count
         * the number of words in the file.
         */
        
        long buffered_line_length = 0;
        inputfile.getline(line, line_length, '\n'); //this just gets an entire line of length (defined above as line_length constant)
        buffered_line_length = strlen(line);
        for (int i = 0; i < buffered_line_length; i++)
        {
            if (isalpha(line[i]))
            {
                word_buffer_count++;
                num_letters++;
                if (isvowel(line[i]))
                    num_vowels++;
                letters_i[(int)toupper(line[i]) - 65]++;
                last_character_is_letter = false;
            }
            else
            {
                if (word_buffer_count < 1)
                    continue;
                word_buffer_count = 0;
                num_words++;
                last_character_is_letter = true;
            }
        }
    }
    if (last_character_is_letter == false)
        num_words++;
    
    /*
     * The following is a bubble sort algorithm to sort our
     * array of numbered letters from greatest to least so
     * that we can display the top five letters below.
     */
    for (int i = 0; i < 26; i++)
    {
        for(int i = 0; i < 26; i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(letters_i[i] > letters_i[j] && letters_i[i] > 0)
                {
                    int temp_i = letters_i[i]; //swap
                    letters_i[i] = letters_i[j];
                    letters_i[j] = temp_i;
                    char temp_c = letters_c[i]; //swap
                    letters_c[i] = letters_c[j];
                    letters_c[j] = temp_c;
                }
                
            }
            
        }
    }
    
    //lets display the number of vowels and total letters
    cout << setprecision(3)
         << "Vowels:     " << num_vowels << " " << (num_vowels / (float)num_letters) * 100 << "%" << endl
         << "Consonants: " << num_letters - num_vowels << " " << ((num_letters - num_vowels) / (float)num_letters) * 100 << "%" << endl
    << "Words:  " << num_words << "   "
    << "Average vowels per word: " << num_vowels / (float)num_words << endl;
    
    //Now we display the top five (sorted above in bubble sort)
    cout << "Top five most used letters:" << endl;
    cout << "Letter:  ";
    for (int i = 0; i < 5; i++)
        cout << left << setw(7) << letters_c[i];
    cout << endl;
    cout << "Count:   ";
    for (int i = 0; i < 5; i++)
        cout << left << setw(7) << letters_i[i];
    cout << endl;
    cout << "Percent: ";
    for (int i = 0; i < 5; i++)
    {
        cout << left << setw(5) << setprecision(2) << fixed << (letters_i[i]/(float)num_letters) * 100 << setw(2) << "%";
    }
    cout << endl;
}
