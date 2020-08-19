/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/

#include <stdio.h>

int main()
{
    int sieve[2000000] = {0};
    long long sum = 0;
    for (int i = 0; i < 2000000; i++)
    {
        if (sieve[i] < 0)
            continue;
        int p = sieve[i] = i + 2;
        for (int j = i + p; j < 2000000; j += p)
            sieve[j] = -1;
        if (p < 2000000)
            sum += p;
    }
    printf("%lld\n", sum);
}
