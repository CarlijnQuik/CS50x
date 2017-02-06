/**
 * helpers.c
 *
 * Edited by student Carlijn Quik 11334231
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int begin = 0;
    int end = n - 1;
    int middle;
    while (n > 0)
    {
        middle = (int) round(((double) (begin + end)) / 2);
        if (values[middle] == value)
        {
            return true;
        }
        if (values[middle] > value)
        {
            end = middle;
        }
        if (values[middle] < value)
        {
            begin = middle;
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // bubble sort
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (values[j] > values[j + 1])
            {
                int tmp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = tmp;
            }
        }
    }
}