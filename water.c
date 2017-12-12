#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //ask user how long he take a show in minutes
    int unsigned minInShower;
    minInShower = get_int("How long in minutes do you usually take a shower?\n");
    
    //calculate and show result how many bottles user used in shower
    printf("%i minutes in shower are equal to %i bottle of water!\n", minInShower, minInShower * 12);
}