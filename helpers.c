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
    if(n<0)
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

    
    while(lengthList > 0)
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
    if(n<0)
    {
        return;
    }
    
    int swapCounter = -1;
    
    printf("\n");
    
    for(int i=0; i<n; i++)
    {
        printf("%i ", values[i]);
    }
    printf("\n\n");
    
    int ordered = n;
    
    while(swapCounter != 0)
    {
        swapCounter = 0;
        
        for(int i = 0; i < ordered-1; i++)
        {   
            // eprintf("%i;%i\n", values[i], values[i+1]);
            
            // check if not in order
            if(values[i] > values[i+1])
            {   
                // swap adjacent element
                int temp = values[i];
                values[i] = values[i+1];
                values[i+1] = temp;
                
                // eprintf("swap: %i : %i\n", values[i], values[i+1]);

                
                swapCounter++;
                
            }
            
        }
        
        ordered--;
        
        
    }
    
    for(int i=0; i<n; i++)
    {
        printf("%i ", values[i]);
    }
    printf("\n");
    
    return;
}
