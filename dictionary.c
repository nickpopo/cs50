// Implements a dictionary's functionality
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"
#include "my.h"

// declare constant of top linked lists
// node *head = NULL;
node *hashtable[6000];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    node *cursor = hashtable[hash(word)];

    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
  
        cursor = cursor->next;
    }

    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{   
    
    // Open the file dictionary for reading
    FILE *dic = fopen(dictionary, "r");
    
    // Check it's opened
    if(dic == NULL)
    {
        printf("Can't open dictionary file\n");
        return false;
    }

    // Define variable
    char word[LENGTH+1];

    while (fscanf(dic, "%s", word) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        new_node->next = NULL;

        if (new_node == NULL)
        {
            unload();
            printf("Can't allocate memory, over memory\n");
            return 2;
        }

        strcpy(new_node->word, word);
        int hash_index = hash(word);

        if(hashtable[hash_index] != NULL)
        {
            new_node->next = hashtable[hash_index];
            hashtable[hash_index] = new_node;
        }
        else
        {
            hashtable[hash_index] = new_node;
        }
    }
    fclose(dic);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    unsigned int counter = 0;
    node *cursor = NULL;
    
    for ( int i = 0; i < 6000; i++)
    {
        if (hashtable[i] != NULL)
        {
            cursor = hashtable[i];

            while (cursor != NULL)
            {
                cursor = cursor->next;
                counter++;
            } 
        }
    }

    return counter;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    node *cursor = NULL;

    for (int i = 0; i < 6000; i++)
    {
        if (hashtable[i] != NULL)
        {
            cursor = hashtable[i];
            
            while (cursor != NULL)
            {
                cursor = cursor->next;
                free(hashtable[i]);
                hashtable[i] = cursor;
            }
        }
    }

    return true;
}

int hash(const char *x) 
{
   
  int xlength = strlen(x);
   
  int i, sum;
  for (sum=0, i=0; i < xlength; i++)
     sum += x[i];
  return sum % 6000;
}
 
// int hash(const char *word)
// {   
//     int a = 0;
//     int b = 0;
    
//     if(strlen(word)>2)
//     {
//         a = toupper(word[0]) - 65;
        
//         b = (word[1] != '\'') ? toupper(word[1]) - 64 : 27;
//     }
//     else
//     {
//         a = toupper(word[0]) - 65;
//     }
    
//     return a+b;
// }
