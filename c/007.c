/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10001st prime number?
*/

#include <stdio.h>

int main()
{
    int primes[10001] = {0}, index = 0, i, p = 2;
    for (; index < 10001; p++)
    {
        for (i = 0; i < index; i++)
            if (p % primes[i] == 0)
                break;
        if (i == index)
            primes[index++] = p;
    }
    printf("%d", primes[10000]);
}