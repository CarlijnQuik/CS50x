/**
 * dictionary.c
 *
 * Edited by student Carlijn Quik 11334231
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "dictionary.h"

#define MAX_HASHTABLE 500

// create nodes
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;

// create hashtable
node* hashtable[MAX_HASHTABLE];

// create hash function
int hash(const char* word)
{
    int newindex = 0;
    for(int i = 0; i < strlen(word); i++)
    {
        newindex += word[i];
    }
    return newindex % MAX_HASHTABLE;
}

// create counter
unsigned int count = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    char lowword[strlen(word) + 1];
    // convert word to lower cases
    for (int i = 0; i < strlen(word); i++)
    {
        lowword[i] = tolower(word[i]);
    }
    
    // create null terminator
    lowword[strlen(word)] = '\0';

    // hash the word
    int index = hash(lowword);
     
    // if there is no word
    if (hashtable[index] == NULL)
    {
        return false;
    }
    else
    {
        // create a pointer to the linked list
        node* cursor = hashtable[index];
        
        // while there is no space iterate through linked list
        while(cursor != NULL)
        {
            if (strcmp(cursor->word, lowword) == 0)
            {
                return true;
            }
            cursor = cursor->next;
        }
        return false;
    }
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // open and read the small dictionary
    FILE* dict = fopen(dictionary, "r");
    
    // check whether dict opens
    if (dict == NULL)
    {
        return false;
    }
    
    // define word in dictionary
    char dictword[LENGTH + 1];
    
    // run through dict until the end of the file
    while (fscanf(dict, "%s\n", dictword) != EOF)
    {
        // malloc a node* for each new word
        node* new_node = malloc(sizeof(node));
        
        // create null terminator
        dictword[strlen(dictword)] = '\0';
        
        // put the word in the node created
        strcpy(new_node->word, dictword);
        
        // hash the word
        int index = hash(dictword);
 
        // if space in array
        if (hashtable[index] == NULL)
        {
            // first does not have pointer
            new_node->next = NULL;
            
            // put the node with the word there
            hashtable[index] = new_node;
        }
        else
        {
            new_node->next = hashtable[index];
            hashtable[index] = new_node;
        }
        
        // add one to the counter
        count++;
    }
    
    // close dict
    fclose(dict);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // return counted words
    return count;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    for (int i = 0; i < MAX_HASHTABLE; i++)
    {
        node* cursor = hashtable[i];
        while(cursor != NULL)
        {
            node* tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
