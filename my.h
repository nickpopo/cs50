#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

// create new data structure
typedef struct node
{
    bool is_word;
    struct node *children[27];
}
node;

// prototypes
int size_dic(node *cursor);
int free_dic(node *cursor);
