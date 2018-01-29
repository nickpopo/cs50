#include <ctype.h>

// create new data structure
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Protopypes
int hash(const char *word);

