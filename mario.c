#include <stdio.h>
#include <cs50.h>

int main(void)

{
    

int height;
int row;
int hash;
int space;

do
{
    printf("Height: ");
    height = get_int();
}
while (height < 0 || height > 23);

for (row = 1; row <= height; row++) 
    {
        for (space = (height - row); space >= 1; space--)
        {
            printf(" "); 
        }
        for (hash = 0; hash <= row; hash++)
        {   
            printf("#");
        }
        printf("\n");
    }

}