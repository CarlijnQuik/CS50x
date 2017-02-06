/* 
*greedy.c
*assignment 1d week 1 minor computer programming
*asks the user to enter how much change is owed, then calculates the number of coins needed in order to give the user this amount of change
*/

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // ask user for an integer
     float n;
     do
     {
         printf("O hai! How much change is owed?\n");
         n = GetFloat();
     }
    while (n < 0.f);
    
    int m = nearbyintf(n*100);
    int l = 0;
    
    // analyse user's input
    l += l/25;
    l %= 25;
    l += l/10;
    l %= 10;
    etc.
    
    
    
    while (m >= 25)
    {
        m = m - 25;
        l++;
    }
    
    while (m >= 10)
    {
        m = m - 10;
        l++;
    }
    
    while (m >= 5)
    {
        m = m - 5;
        l++;
    }
   
    while (m >= 1)
    {
        m = m - 1;
        l++;
    }
    
    //print the result
    printf("%i\n", l);
    
    //terminate program
    return 0;
}