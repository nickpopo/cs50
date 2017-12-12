#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    
    do
    {
        //ask user height of half-pyramide
        height = get_int("How height pyramide do you want?\n");
    }
    while(height < 0 && height > 23);
    
    for (int i = 0; i < height; i++)
    {
        int count = 1;
        int hashes = 2;
        
        //print spaces
        while(height-count>i)
        {
            printf(" ");
            count++;
        }
        
        //print hashes
        while(hashes<height+i){
            printf("#");
            hashes++;
        }

        //print \n
        printf("\n");
    }
}