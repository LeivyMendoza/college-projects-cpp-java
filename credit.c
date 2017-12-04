#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int sum = 0;
    int sum_2 = 0;
    int total = 0;
    long long cc = 0;
    
    do
    {
        printf("Enter your credit card number:\n");
        cc = get_long_long();
    }
    while (cc < 0);
    
    for (long long i = cc; i > 0; i /= 100)
    {
        sum += i % 10;
    }
    
    for (long long x = cc / 10; x > 0; x /= 100)
    {
        if (2 * (x % 10) > 9 )
        {
            sum_2 += (2 * (x % 10)) / 10;
            sum_2 += (2 * (x % 10)) % 10;
        }
        else sum_2 += (2 * (x % 10));
    }
    
    total = sum + sum_2;
    
    if (total % 10 == 0)
    {
        if ((cc >= 340000000000000 && cc < 350000000000000) || (cc >= 370000000000000 && cc < 380000000000000))
            printf("AMEX\n");
        else if (cc >= 5100000000000000 && cc < 5600000000000000)
            printf("MASTERCARD\n");
        else if ((cc >= 4000000000000 && cc < 5000000000000) || (cc >= 4000000000000000 && cc < 5000000000000000))
            printf("VISA\n");
        else
            printf("INVALID\n");
    }
    else
        printf("INVALID\n");

    return 0;
}

