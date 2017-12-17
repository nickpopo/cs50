#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (int argc, string argv[])
{
    
    //check argc
    if(argc < 2 || argc > 2)
    {
    eprintf("error no arg or more than one\n");
    return 1;
    }
    
    int keyword[32];
    int n = strlen(argv[1]);
    char key[n];
    int num[n];
    
    //check alphabetic
    for(int i = 0 ; i<n; i++)
    {
        
        if(!isalpha(argv[1][i]))
        {   
            eprintf("error not alphabetic\n");
            return 1;
        }
        
        key[i] = argv[1][i];
        
        if(isupper(argv[1][i]))
        {
            keyword[i] = argv[1][i] - 'A';
            num[i] = keyword[i];
        }
        else
        {
            keyword[i] = argv[1][i] - 'a';
            num[i] = keyword[i];
        }
        
        printf("%c: ", key[i]);
        printf("%i\n", num[i]);
        
    }
    
    
    keyword[n] = '\0';

    
    string plaintext = get_string("plaintext: ");
    
    int l = strlen(plaintext);
    
    char ciphertext[l];
    
    for(int i = 0; i < l ; i++)
    {
        if( plaintext[i] != ' ')
        {
            ciphertext[i] = plaintext[i]+keyword[i % n];
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    
    
    printf("ciphertext: %s\n", ciphertext);

    return 0;
    
}