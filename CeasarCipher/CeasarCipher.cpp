
// FILE     :   CeasarCipher.cpp
// PROJECT  :   CeasarCipher
// PROGRAMMER : Nick Iden
// DATE :       December 27st, 2019
// DESCRIPTION  :
//                  This program is based on the CS50 Cipher game. It is modified to not use the CS50 library.
//                  How it works:
//                                  1. User enters the name of the program and a second argument that is the key 
//                                      eg// CeasarCipher.exe 12
//                                  2. The program will check to make sure there are 2 arguments and the 2nd is a number
//                                  3. User enters a phrase
//                                  4. If phrase is valid it will code the phrase based on the key




#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define PHRASE_COUNT 3000
#define ERROR 1;

int main(int argc, char* argv[])
{
    // check input is valid is it 2 arguments and a number
    if (argc != 2 && isdigit(*argv[1]))
    {
        printf(" Sorry the input is invalid! \n");
    }
    else
    {

        // store value entered at 2nd argument in key varialble
        int key = atoi(argv[1]);

        // create an array that stores the user phrase
        char userPhase[PHRASE_COUNT] = { 0 };
      
        // ask user for phrase
        printf("please enter something: ");
        fgets(userPhase, PHRASE_COUNT, stdin);

        // get user input phrase count
        int phraseNum = strlen(userPhase);

        // validate phrase being entered
        if (userPhase != "\0" && phraseNum < PHRASE_COUNT)
        {
            // iterate through phrase and convert
            for (int i = 0; i < phraseNum; i++)
            {
                // check if lowercase, then print with key
                if (userPhase[i] >= 'a' && userPhase[i] <= 'z')
                {
                    printf("%c", (((userPhase[i] - 'a') + key) % 26) + 'a'); 
                }
                // check if uppercase, if so print with key
                else if (userPhase[i] >= 'A' && userPhase[i] <= 'Z')
                {
                    printf("%c", (((userPhase[i] - 'A') + key) % 26) + 'A'); 
                }
                // if neither upper lower (special character)
                else

                {
                    printf("%c", userPhase[i]);
                }
            }

        // error message if input from user is invalid
        }
        else
        {
            printf("The phrase you entered is invalid!!1\n");
            return ERROR;
        }
    }

    return 0;
}

