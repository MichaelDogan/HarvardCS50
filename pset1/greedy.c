/**
 * greedy.c
 *
 * Michael S. Dogan
 * michaeldogan@gmail.com
 * 
 * CS50 pset1 - greedy
 * 
 * Based upon user input requesting change
 * determines the fewest coins (.25, .10, .05, .01)
 * to be dispensed. 
 *
*/

#include <cs50.h>
#include <stdio.h>
#include <math.h>

// giveCoins function prototype
void giveCoins(int coinValue);

int remaining, coin_count;

int main(void)
{
    // Prompt the User for the amount of change
    float requested;
    
    do
    {
        printf("How much change do you need?: ");
        requested = GetFloat();    
    } 
    while (requested <= 0.0);

    // initialize some variables
    int converted = round(requested * 100 );
    remaining = converted;
    coin_count = 0;
    
    // check for each coin type
    giveCoins(25);
    giveCoins(10);
    giveCoins(5);
    giveCoins(1);
    
    // print the result to the console
    printf("%i\n", coin_count);
      
}


/*
 * Takes a COIN_VALUE, determines if it can be used
 * to dispense change, and decrements the remaining
 * and counts the number of coins dispensed in COIN_COUNT
 *
 */
void giveCoins(int coinValue)
{
    if (remaining / coinValue >= 1)
    {
        coin_count += remaining / coinValue;
        remaining -= ((remaining / coinValue) * coinValue);
    }
}
