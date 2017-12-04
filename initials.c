#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    string s = get_string();
    int n = strlen(s);

    printf("%c", toupper(s[0]));

    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
        {
            printf("%c", toupper(s[i + 1]));
        }
    } 

   printf("\n"); 
   return 0;
}