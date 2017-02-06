/* 
*initials.c
*assignment 2a week 2 minor programming
*student Carlijn Quik ID: 11334231 
*asks for your full name, then returns your initials
*shows the use of an array, a string, the commands toupper and strlen
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// opens main body and creates integer argc and array argv
int main(int argc, char * argv[])
{
    // asks users input
    string fullname = GetString();
    // prints the first letter of the name in capital
    printf("%c", toupper(fullname[0]));
    // runs the loop as long as i is smaller than the length of fullname
    for (int i=0; i < strlen(fullname); i++)
    {
        // analyses whether the ith letter of the fullname is a spacebar
        if (fullname[i] == 32)
        {
            // prints the character after the spacebar in capital
            printf("%c", toupper(fullname[i + 1]));
        }
    }
    // prints an enter
    printf("\n");
}



