/* 
*vigenere.c
*assignment 2c week 2 minor programming
*student Carlijn Quik ID: 11334231 
*turns a text into a cipher using an alphabetical key
*challenges extra to puzzle with the functions learnt in previous cases
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
    // checks wheter the key is there
    if (argc != 2)
    {
        printf("Try again\n");
        return 1;
    }
    // checks whether the key consists out of letters
    for (int i=0; i < strlen(argv[1]); i++)
    {
        // checks whether the character is a letter
        if (!isalpha(argv[1][i]))
        {
            // gives an error if the condition is not met
            printf("Try again\n");
            return 1; 
        }
    }
    // asks the user to enter a string
    input = GetString();
    // runs the loop as long as i is smaller than the length of the input
    for (int i=0, j=0; i < strlen(input); i++)
    {
        // checks whether the input and key are lower case
        if (islower(input[i]) && islower(argv[1][j]))
        {
            // prints the lowercase character key times further in the alphabet
            printf("%c", (((input[i] - 97) + (argv[1][j] - 97)) % 26) + 97);
           // adds one to j
            j++;
        }
        // checks whether the input and key are upper case
        else if (isupper(input[i]) && isupper(argv[1][j]))
        {
            // prints the uppercase character key times further in the alphabet
            printf("%c", (((input[i] - 65) + (argv[1][j] - 65)) % 26) + 65);
            // adds one to j
            j++;
        }
        // checks whether the input is lowercase and key is uppercase
        else if (islower(input[i]) && isupper(argv[1][j]))
        {
            // prints the upper- and lowercase character key times further
            printf("%c", (((input[i] - 97) + (argv[1][j] - 65)) % 26) + 97);
            // adds one to j
            j++;
        }
        // checks wheter the input is uppercase and key is lowercase
        else if (isupper(input[i]) && islower(argv[1][j]))
        {
            // prints the upper- and lowercase character key times further
            printf("%c", (((input[i] - 65) + (argv[1][j] - 97)) % 26) + 65);
            // adds one to j
            j++;
        }
        else 
        {
            // prints the characters
            printf("%c", input[i]);
        }
        // sets j to 0 if the key is fully ran
        if (j == strlen(argv[1]))
        {
            j = 0;
        }
    }
    printf("\n");
    return 0;
}

