/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

#include <stdio.h>

int main()
{
    unsigned long long int N = 600851475143, max = 0, p = 0;
    while (N != 1)
    {
        for (p = 2; N % p != 0; p++)
            ;
        N /= p;
        if (p > max)
            max = p;
    }
    printf("%ld", max);
}
