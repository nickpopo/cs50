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

    if(n < 0 || n < 2)
    {
        return;
    }
    
    //
    // left
    //
    int leftLength = n/2;
    
    int leftList[leftLength];
    
    for(int i=0; i < leftLength; i++)
    {
        leftList[i] = values[i];
    }
    
    sort(leftList, leftLength);
    
    // 
    // right
    //

    int rightLength = n-n/2;
    
    int rightList[rightLength];
    
    for(int i=0; i< rightLength; i++)
    {
        rightList[i] = values[leftLength+i];
    }

    sort(rightList, rightLength);

    //
    // merge
    //
    
    int leftCounter = 0;
    int rightCounter = 0;
    
    for(int i=0; i < n; i++)
    {
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
    
    return;
}