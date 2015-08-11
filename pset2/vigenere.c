/**
 * vigenere.c
 *
 * Michael S. Dogan
 * michaeldogan@gmail.com
 * 
 * CS50 pset2 - vigenere
 * 
 * a program that encrypts messages using vigenere
 * cipher.  
 *
*/

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define ALPHABET 26

void PrintShift(char character, int offset, int shift);

int main(int argc, string argv[])
{
    // if bad number of command line args, exit and return 1
    if (argc != 2)
    {
        printf("Usage: ./vigenere <key>\n");
        return 1;
    }
    
    string key = (argv[1]);
    
    // if key isn't alpha, exit and return 1
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            printf("text must be alpha A-Z or a-z\n");
            return 1;
        }
    }
    
    // we treat upper and lower keys the same so...
    for (int i = 0; i < strlen(key); i++)
    {
        key[i] = toupper(key[i]);
    }
    
    // get the user text
    string text = GetString();
    
    int key_counter = 0;
    int k;
    for (int i = 0; i < strlen(text); i++)
    {
               
        // cypher alpha characters
        if (isalpha(text[i]))
        {
           
            if (isupper(text[i]))
            {
                // find the offset from the key
                k = key[key_counter % strlen(key)] - 'A';
                PrintShift(text[i], k, 'A');
            }   
            else
            {
                // find the offset from the key
                k = key[key_counter % strlen(key)] - 'A';
                PrintShift(text[i], k, 'a');
            }
            key_counter++;
        }
        
        // just print non alpha chars as is
        else
        {
            printf("%c", text[i]);
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
void PrintShift(char character, int offset, int shift)
{
    printf("%c", ((character + offset - shift) % ALPHABET) + shift);
}
