#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    int num = 0;
    
    if (argc < 2 || atoi(argv[1]) < 0)
    {
        printf("Please enter a non negative interger\n");
        return 1;
    }
    else
    {
        num = atoi(argv[1]);
    }
    
    printf("plaintext: ");
    string text = get_string();
    int t = strlen(text);
    
    printf("ciphertext: ");
    
    for (int i = 0; i < t; i++)
    {
        if (islower (text[i]) && isalpha (text[i]))
        {
            text[i] = (text[i] - 'a' + num) % 26 + 97;
        }
        else if(isupper (text[i]) && isalpha (text[i]))
        {
            text[i] = (text[i] - 'A' + num) % 26 + 65;
        }
        printf("%c", text[i]); 
    }
    printf("\n"); 
    return 0; 
}