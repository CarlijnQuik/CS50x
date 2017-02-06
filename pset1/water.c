/* 
*water.c
*assignment 1b week 1 minor computer programming
*asks the user to enter a number of minutes showering, then calculates the number of waterbottles will be used
*/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // ask user for an integer
    printf("minutes:");
    int n = GetInt();
    
    // analyse user's input
    if (n > 0)
    {
        printf("bottles:%i\n", n*12);
    }
}