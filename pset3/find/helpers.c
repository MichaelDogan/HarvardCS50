/**
 * helpers.c
 *
 * Michael S. Dogan
 * michaeldogan@gmail.com
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

int midpoint(int min, int max)
{
    return min + ((max - min) / 2);
}

bool binarySearch(int value, int values[], int imin, int imax)
{
    // a binary search algorithm!
    // credit disclosure:
    // implementation of pseudo code found on wikipedia.org
    // with minor modifications
    
    // test if array is empty
    if (imax < imin)
    {
        // set is empty, so return value FALSE showing not found
        return false;
    }
    else
    {
        // calculate midpoint to cut set in half
        int imid = midpoint(imin, imax);
 
        // three-way comparison
        if (values[imid] > value)
        {
            // key is in lower subset
            return binarySearch(value, values, imin, imid - 1);
        }
        else if (values[imid] < value)
        { 
            // key is in upper subset
            return binarySearch(value, values, imid + 1, imax);
        }
        else
        {
            // key has been found
            return true;
        }
    }   
    
}    

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // a binary search algorithm!
    // credit disclosure:
    // implementation of pseudo code found on wikipedia.org 
    // binarySearch_algorithm with some modifications to 
    // adhere to our search declaration
    
    int imin = 0;
    int imax = n - 1;
    
    return binarySearch(value, values, imin, imax);
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int new_length;
    int tempValue;

    // Implement Bubble Sort
    do
    {
        new_length = 0;
        for (int i = 1; i < n - 1; i++)
        {
            // Swap the values if the second is larger
            if (values[i - 1] > values[i])
            {
                tempValue = values[i - 1];
                values[i - 1] = values[i];
                values[i] = tempValue;
                new_length = i;
            }
        }
        n = new_length;
    }
    while (n != 0);
    return;
}
