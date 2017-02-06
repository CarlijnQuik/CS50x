/* 
*mario.c
*assignment 1c week 1 minor computer programming
*asks the user to enter a height, then builds a pyramid of that height
*/

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // ask user for an integer
     int height;
     do
     {
         printf("height:");
         height = GetInt();
     }
    while (height > 23 || height < 0);
    
     // analyse user's input
     int spaces = height - 1;
     
     for (int i = 0; i < height; i++)
     {
    
        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }
        
        int hash = height - spaces;
        
             for (int k = 0; k < hash; k++)
            {
                printf("#");
            }
            
    spaces--;
    printf("#\n");
    
     }
}