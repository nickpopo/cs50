/**
 * Prompts user for as many as MAX values until EOF is reached, 
 * then proceeds to search that "haystack" of values for given needle.
 *
 * Usage: ./find needle
 *
 * where needle is the value to find in a haystack of values
 */
       
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"

// maximum amount of hay
const int MAX = 65536;

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./find needle\n");
        return -1;
    }

    // remember needle
    int needle = atoi(argv[1]);

    // fill haystack
    int size;
    int haystack[MAX];
    for (size = 0; size < MAX; size++)
    {
        // wait for hay until EOF
        printf("\nhaystack[%i] = ", size);
        int straw = get_int();
        if (straw == INT_MAX)
        {
            break;
        }
     
        // add hay to stack
        haystack[size] = straw;
    }
    printf("\n");

    // sort the haystack
    sort(haystack, size);

    // try to find needle in haystack
    if (search(needle, haystack, size))
    {
        printf("\nFound needle in haystack!\n\n");
        return 0;
    }
    else
    {
        printf("\nDidn't find needle in haystack.\n\n");
        return 1;
    }
}

// Merge sort
void mergeSort(int values[], int n)
{
    if(n < 2)
    {
        return;
    }
    
    //
    // left
    //
    printf("left\n");
    
    int leftLength = n/2;
    
    int leftList[leftLength];
    
    // print
    printf("%i\n", leftLength);
    
    for(int i=0; i < leftLength; i++)
    {
        leftList[i] = values[i];
    }
    
    // print
    for(int i=0; i<leftLength; i++)
    {
        printf("%i ", *(leftList+i));
    }
    printf("\n");
    
    mergeSort(leftList, leftLength);
    
    // 
    // right
    //
    printf("right\n");
    
    int rightLength = n-n/2;
    
    int rightList[rightLength];
    
    printf("%i\n", rightLength);
    
    for(int i=0; i< rightLength; i++)
    {
        rightList[i] = values[leftLength+i];
    }
    // print
    for(int i=0; i < rightLength; i++)
    {
        printf("%i ", *(rightList+i));
    }
    printf("\n");
    
    mergeSort(rightList, rightLength);
    
    //
    // merge
    //
    
    // print leftList
    for(int i=0; i < leftLength; i++)
    {
        printf("%i ", *(leftList+i));
    }
    printf("\n");
     // print rightList
    for(int i=0; i < rightLength; i++)
    {
        printf("%i ", *(rightList+i));
    }
    printf("\n");
    
    // leftLength = n/2;
    // rightLength = n - n/2;
    
    int leftCounter = 0;
    int rightCounter = 0;
    
    for(int i=0; i < n; i++)
    {   
        printf("left: %i\n", leftList[i]);
        printf("right: %i\n", rightList[i]);
        
        if (leftCounter >= leftLength)
        {
            values[i] = rightList[rightCounter];
            rightCounter++;
        }
        else if (rightCounter >= rightLength)
        {
            values[i] = leftList[leftCounter];
            leftCounter++;
        }
        else if (leftList[leftCounter] < rightList[rightCounter])
        {
            values[i] = leftList[leftCounter];
            leftCounter++;
        }
        else
        {
            values[i] = rightList[rightCounter];
            rightCounter++;
        }
    }
}
