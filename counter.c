#include <stdio.h>

int main(int argc, char *argv[])
{
    
    if (argc != 2)
    {
        return 1;
    }
    
    FILE* dictionary = fopen(argv[1], "r");
    
    if (dictionary == NULL)
    {
        return 2;
    }
    
    int count = 0;
    char word[47];
    
    while(fscanf(dictionary, "%s", word) != EOF)
    {
        count++;
    }
    
    fclose(dictionary);
    
    printf("%i\n", count);
    
    return 0;
    
}