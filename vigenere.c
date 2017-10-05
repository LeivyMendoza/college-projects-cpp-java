#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Please enter a non negative interger\n");
        return 1;
    }
    
    string key = argv[1]; 
    
    for (int i = 0 ; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {   
            printf("Please enter a key = alphabetical\n");
            return 1;
        }
    }  
    
    printf("plaintext: ");
    string input = get_string();
    int inputLenght = strlen(input);
    
    printf("ciphertext: ");
    int v = 0;
    
    for (int i = 0; i < inputLenght; i++)
    {
        v = v % strlen(argv[1]);
        
        if (islower(input[i]) && islower(argv[1][v]))
        {
            input[i] = (((input[i] - 97) + (argv[1][v] - 97)) % 26) + 97;
        }
        else if (isupper(input[i]) && islower(argv[1][v]))
        {    
            input[i] = (((input[i] - 65) + (argv[1][v] - 97)) % 26) + 65;
        }
        else if (islower(input[i]) && isupper(argv[1][v]))
        {    
            input[i] = (((input[i] - 97) + (argv[1][v] - 65)) % 26) + 97;
        }
        else if (isupper(input[i]) && isupper(argv[1][v]))
        {       
            input[i] = (((input[i] - 65) + (argv[1][v] - 65)) % 26) + 65;
        }
        v++;
        printf("%c", input[i]); 
    }
    printf("\n"); 
    return 0; 
}