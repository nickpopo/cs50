#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name = get_string();
    
    char initials[6];
    
    int counter = 0;
    
    for(int i = 0, n = strlen(name); i < n ; i++)
    {

        if( i==0 || name[i-1] == ' ')
        {
            initials[counter] = toupper(name[i]);
            counter ++;
        }
        
    }
    initials[counter] = '\0';
    
    printf("%s\n", initials);
    
}