// Implements a dictionary's functionality
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>

#include "my.h"
#include "dictionary.h"


// declare root array of pointers
node *root = NULL;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    node *cursor = root;

    for (int i=0; word[i] != '\0'; i++)
    {
        if (word[i] != '\'')
        {
            if (cursor->children[toupper(word[i]) - 65] == NULL)
            {
                return false;
            }
            
            cursor = cursor->children[toupper(word[i]) - 65];
        }
        else
        {
            if (cursor->children[26] == NULL)
            {
                return false;
            }
            
            cursor = cursor->children[26];  
        }
        
    }

    return cursor->is_word;
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

    // Define variable and poiters
    char word[LENGTH+1];
    root = malloc(sizeof(node));
    memset(root, 0, sizeof(node));
    node *cursor = root;

    while (fscanf(dic, "%s", word) != EOF)
    {
        for (int i = 0; word[i] != '\0'; i++)
        {
            
            if (word[i] != '\'')
            {
                if (cursor->children[toupper(word[i]) - 65] != NULL)
                {
                    cursor = cursor->children[toupper(word[i]) - 65];
                }
                else
                {
                    node *new_node = malloc(sizeof(node));
                    memset(new_node, 0, sizeof(node));
    
                    if (new_node == NULL)
                    {
                        unload();
                        printf("Can't allocate memory, over memory\n");
                        return 2;
                    }
    
                    cursor->children[(toupper(word[i]) - 65)] = new_node;
                    cursor = new_node;
                    
                } 
            }
            else
            {
                if (cursor->children[26] != NULL)
                {
                    cursor = cursor->children[26];
                }
                else
                {
                    node *new_node = malloc(sizeof(node));
                    memset(new_node, 0, sizeof(node));
    
                    if (new_node == NULL)
                    {
                        unload();
                        printf("Can't allocate memory, over memory\n");
                        return 2;
                    }

                    cursor->children[26] = new_node;
                    cursor = new_node;
                } 
            }
        }

        cursor->is_word = true;
        cursor = root;
    }

    fclose(dic);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    node *cursor = root;
    
    return size_dic(cursor);
    
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    node *cursor = root;
    
    return free_dic(cursor);
    
}

// size of dictionary in trie
int size_dic(node *cursor)
{
    unsigned int counter = 0;
    
    for (int i = 0; i < 27; i++)
    {
        if (cursor->children[i]!=NULL)
        {
            counter += size_dic(cursor->children[i]);
        }
    }
    
    // chech is_word
    if(cursor->is_word)
    {
        return counter+1;
    }
    
    return counter;
}

// free all memory for dictionary
int free_dic(node *cursor)
{
    for (int i = 0; i < 27; i++)
    {
        if (cursor->children[i]!=NULL)
        {
            free_dic(cursor->children[i]);
        }
    }

    free(cursor);

    return 1;
}