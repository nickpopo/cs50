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
    
    
    // Bubble sort
    int swapCounter = -1;

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
                swap(&values[i], &values[i+1]);
            
                swapCounter++;
                
            }
        }

        ordered--;
    }
    
    // Selection Sort
    // int min;
    // int counter;
    
    // for (int i = 0; i < n; i++)
    // {
    //     min = i;
        
    //     counter = 1;
        
    //     while(counter < n - i)
    //     {
    //         if(values[min] > values[i+counter])
    //         {
    //             min = i+counter;
    //         }
            
    //         counter++;
    //     }
        
    //     // swap
    //     swap(&values[min], &values[i]);
    //     // int temp = values[min];
    //     // values[min] = values[i];
    //     // values[i] = temp;
        
    // }
    
    // Print sorted list
    for(int i=0; i<n; i++)
    {
        printf("%i ", values[i]);
    }
    printf("\n");
    
    return;
}
