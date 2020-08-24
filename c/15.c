/*
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.


How many such routes are there through a 20×20 grid?
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int *prime_sieve(int k)
{
    int *sieve = calloc(k, sizeof(int));
    sieve[0] = -1;
    sieve[1] = -1;
    for (int i = 2; i < k; i++)
    {
        if (sieve[i] < 0)
            continue;
        int p = sieve[i] = i;
        for (int j = i + p; j < k; j += p)
            sieve[j] = -1;
    }
    return sieve;
}

int main()
{
    int *sieve = prime_sieve(41);
    // answer = (40 choose 20) = 40! / (20!)^2 = 40*39*38*...*21 / 20*19*18*...*1
    int numerator_factors[40] = {0}, denominator_factors[40] = {0};
    for (int i = 0; i <= 40; i++)
    {
        int p = sieve[i];
        if (p < 0)
            continue;
        for (int n = 21; n <= 40; n++)
            for (int a = n; a % p == 0; a /= p)
                numerator_factors[p]++;
        for (int d = 1; d <= 20; d++)
            for (int a = d; a % p == 0; a /= p)
                denominator_factors[p]++;
    }
    unsigned long long int result = 1;
    for (int i = 0; i < 40; i++)
    {
        int k = numerator_factors[i] - denominator_factors[i];
        assert(k >= 0);
        for (; k > 0; k--)
            result *= i;
    }
    free(sieve);
    printf("%lld", result);
}