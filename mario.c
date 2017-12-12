#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    
    do
    {
        //ask user height of half-pyramide
        printf("Height: ");
        height = get_int();
    }
    while( height < 0 || height > 23);
    
    for (int i = 0; i < height; i++)
    {   
        int row = i+1;
        int spaces = height;
        int hashes = 0;
        
        //print spaces
        while(spaces > row)
        {
            printf(" ");
            spaces--;
        }

        //print hashes
        while(hashes < row + 1)
        {
            printf("#");
            hashes++;
        }

        //print \n
        printf("\n");
    }
}