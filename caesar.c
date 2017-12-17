#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    
    if(argc < 2 || argc > 2)
    {
        eprintf("you must pass one argument\n");
        
        return 1;
    }
    
    int key = atoi(argv[1]);
    
    string plaintext = get_string("plaintext: ");
    
    int l = strlen(plaintext);
    
    char ciphertext[l];
    
    for (int i = 0; i < l ; i++)
    {
        if(isalpha(plaintext[i]))
        {
            
            if(isupper(plaintext[i]))
            {   
                plaintext[i] = plaintext[i] - 'A';
                ciphertext[i] = (plaintext[i] + key) % 26;
                ciphertext[i] = ciphertext[i] + 'A';
            }
            else
            {   
                plaintext[i] = plaintext[i] - 'a';
                ciphertext[i] = (plaintext[i] + key) % 26;
                ciphertext[i] = ciphertext[i] + 'a';
            }
            
            
            
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    printf("ciphertext: %s\n", ciphertext);
    
    return 0;
    
}