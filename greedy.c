#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //asc user how much changes is owned
    //chech non-negative
    //create float valuable changes
    float changes;
    do
    {
        changes = get_float("How much changes are you owned?\n");
    }
    while (changes < 0);
    
    //convert an amount into cents
    int centsUser = round(changes * 100);
    //print convertion result
    printf("%0.55f$ equal to %ic\n", changes, centsUser);

    //create integer valuable coints
    int coins;

    //25c
    if(centsUser % 25 < 25)
    {
        coins = centsUser / 25;
        printf("25c: %i\n", coins);
        centsUser = centsUser % 25;
    }
    //10c
    if(centsUser % 10 < 10)
    {   
        printf("10c: %i\n", centsUser / 10);
        coins = coins + centsUser / 10;
        centsUser = centsUser % 10;
    }
    //5c
    if(centsUser % 5 < 5)
    {   
        printf("5c: %i\n", centsUser / 10);
        coins = coins + centsUser / 5;
        centsUser = centsUser % 5;
    }
    //1c
    if (centsUser > 0)
    {   
        printf("1c: %i\n", centsUser);
        coins = coins + centsUser;
    }
    
    //print minimun necessary coins to change
    printf("Coins: %i\n", coins);
}