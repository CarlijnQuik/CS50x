/* 
*caesar.c
*assignment 2b week 2 minor programming
*student Carlijn Quik ID: 11334231 
*turns a text into a cipher using a numerical key
*shows the function of argc, argv[], atoi, modulo and the ASCII table
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// opens main body and creates integer argc and array argv
int main(int argc, char * argv[])
{
     // creates the string input
    string input;
    // checks whether the key is valid
    if (argv[1] > 0 && argc == 2)
    {
        // asks the user to enter a string
        input = GetString();
    }
    // gives an error if the condition is not met
    else
    {
        printf("Try again\n");
        return 1;
    }
    // converts argv[1] into integer key
    int key = atoi(argv[1]);
    // runs the loop as long as i is smaller than the length of input
    for (int i = 0; i < strlen(input); i++)
    {
        // checks whether the input is a lower case letter
        if (islower(input[i]))
        {
            // prints the lowercase character key times further in the alphabet
            printf("%c", (((input[i] - 97) + key) % 26) + 97);
        }
        // checks whether the input is an upper case letter
        else if (isupper(input[i]))
        {
            // prints the uppercase character key times further in the alphabet
            printf("%c", (((input[i] - 65) + key) % 26) + 65);
        }
       // decides what to do with all other characters
        else 
        {
            // prints the character
            printf("%c", input[i]);
        }
    }
    printf("\n");
    return 0;
}