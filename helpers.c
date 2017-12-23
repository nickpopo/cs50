/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    //ensure proper usage
    if(n < 0)
    {
        return false;
    }
    
    // linear search
    // for (int i = 0; i < n; i++)
    // {
    //     if(values[i] == value)
    //     {
    //         return true;
    //     }
    // }
    
    // Binary search
    int lengthList = n;
    int start = 0;
    int end = n-1;
    int middleList;

    
    while(lengthList >= 0)
    {   
        // calculate middle of list
        middleList = ( start + end ) / 2;
        
        if(values[middleList] == value)
        {
            return true;
        }
        
        if(values[middleList] > value)
        {
            end =  middleList - 1;  
        }
        else
        {
            start = middleList + 1;
        }
        
        lengthList = end - start;
        
    }
    
    
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    //ensure proper usage
    if(n < 0)
    {
        return;
    }
    
    // Print unsorted list
    printf("\n");
    
    for(int i=0; i<n; i++)
    {
        printf("%i ", values[i]);
    }
    printf("\n\n");
    
    
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
    
    sort(leftList, leftLength);
    
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
    
    sort(rightList, rightLength);
    
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
    
    // Print sorted list
    for(int i=0; i<n; i++)
    {
        printf("%i ", values[i]);
    }
    printf("\n");
    
    return;
}