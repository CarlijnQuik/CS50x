/**
 * generate.c
 *
 * Edited by student Carlijn Quik 11334231
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// defines the limit
#define LIMIT 65536

int main(int argc, string argv[])
{
    // gives error when number of arguments is not 2 and not 3
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // creates integer n that is equal to array argv[1]
    int n = atoi(argv[1]);

    // when a seed is given use it, else use the time
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    // runs when the times ran is smaller than n
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // stops the program
    return 0;
}