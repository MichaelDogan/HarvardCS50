/**
 * caesar.c
 *
 * Michael S. Dogan
 * michaeldogan@gmail.com
 * 
 * CS50 pset2 - caesar
 * 
 * a program that encrypts messages using Caesar's
 * cipher.  
 *
*/

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define ALPHABET 26

void PrintShift(char c, int offset, int shift);

int main(int argc, string argv[])
{
    // if bad command line args, exit and return 1
    if (argc != 2)
    {
        printf("Usage: ./caesar <key>\n");
        return 1;
    }
    
    int k = atoi(argv[1]);
    
    if (k < 1)
    {
        printf("Key must be a non-negative integer\n");
        return 1;
    }
    
    // get the user input
    string s = GetString();
    
    // encrypt the string
    for (int i=0; i < strlen(s); i++)
    {
        // cypher alpha characters
        if isalpha(s[i])
        {
            if isupper(s[i])
            {
                PrintShift(s[i], k, 'A');      
            }
            else
            {
                PrintShift(s[i], k, 'a');
            }
        }
        
        // just print non alpha chars as is
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");   
}

/**
 * PrintShift takes a single character "c" and
 * prints a new character based upon the "offset"
 * and the "shift" which is based upon the case of
 * the character "c".
 **/
void PrintShift(char c, int offset, int shift)
{
    printf("%c", ((c + offset - shift) % ALPHABET) + shift);
}
