/**
 * mario.c
 *
 * Michael S. Dogan
 * michaeldogan@gmail.com
 * 
 * CS50 pset1 - mario
 * 
 * Prints a half pyramid (a la mario video game)
 * height set by user input & constrained by spec
 * to be between 0 and 23 inclusive
 *
*/

#include <cs50.h>
#include <stdio.h>

// printChars function prototype
void printChars(int number, char character);

int main(void)
{
    // prompt and validate user input 0-23 inclusive
    int height;
    
    do
    {
        printf("Please enter an integer between 0 and 23 inclusive:");
        height = GetInt();    
    } 
    while (height < 0 || height > 23);
    
    // Define the initial rows spaces and blocks
    int spaces = height - 1 ;
    int blocks =  2;
    
    // Draw the half-pyramid
    for (int i = 0; i < height; i++)
    {
        // print spaces blocks & newline
        printChars(spaces,' ');
        printChars(blocks,'#');
        printf("\n");
        
        // decrement & increment in preparation for printing next row
        spaces--;
        blocks++;
    }
}

/**
 * Prints NUMBER of CHARACTERs on a single line
 */
void printChars(int number, char character)
{
    for (int j = 0; j < number; j++)
    {
        printf("%c",character); 
    }
}

