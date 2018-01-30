// Implements a dictionary's functionality
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"
#include "my.h"

#define M 69800

// declare constant of top linked lists
node *hashtable[M];
int size_dic=0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // make word lowercase
    char wordcheck[LENGTH + 1];
    int letter = 0;

    while (word[letter] != '\0')
    {
        wordcheck[letter] = tolower(word[letter]);
        letter++;
    }

    wordcheck[letter] = '\0';

    node *cursor = hashtable[hash(wordcheck)];

    while (cursor != NULL)
    {
        if (strcasecmp(wordcheck, cursor->word) == 0)
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
    if (dic == NULL)
    {
        printf("Can't open dictionary file\n");
        return false;
    }

    // Define variable
    char word[LENGTH + 1];

    while (fscanf(dic, "%s", word) != EOF)
    {
        node *new_node = malloc(sizeof(node));

        if (new_node == NULL)
        {
            unload();
            printf("Can't allocate memory, over memory\n");
            return 2;
        }

        new_node->next = NULL;

        // Coping word into new_node
        strcpy(new_node->word, word);

        // Get hash code for word
        int hash_index = hash(word);

        if (hashtable[hash_index] != NULL)
        {
            new_node->next = hashtable[hash_index];
            hashtable[hash_index] = new_node;
        }
        else
        {
            hashtable[hash_index] = new_node;
        }
        size_dic ++;
    }

    fclose(dic);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    // unsigned int counter = 0;
    // node *cursor = NULL;

    // for (int i = 0; i < M; i++)
    // {
    //     if (hashtable[i] != NULL)
    //     {
    //         cursor = hashtable[i];

    //         while (cursor != NULL)
    //         {
    //             cursor = cursor->next;
    //             counter++;
    //         }
    //     }
    // }

    return size_dic;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    node *cursor = NULL;

    for (int i = 0; i < M; i++)
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

// Hash fuction for generating code
unsigned long hash(const char *str)
{
    unsigned long hash = 5381;
    int i =0;
    while ( str[i] != '\0')
    {   
        hash = ((hash << 5) + hash) + str[i]; /* hash * 33 + c */
        i++;
    }

    return hash % M;
}