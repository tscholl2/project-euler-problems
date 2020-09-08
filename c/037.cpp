/*
The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
*/
#include <iostream>
#include <vector>

std::vector<int> prime_sieve(uint N)
{
    std::vector<int> sieve(N, 1);
    sieve[0] = 0;
    sieve[1] = 0;
    for (uint i = 2; i < N; i++)
        if (!sieve[i])
            continue;
        else
            for (uint j = 2 * i; j < N; j += i)
                sieve[j] = 0;
    return sieve;
}

int main()
{
    int sum = 0;
    std::vector<int> sieve = prime_sieve(1000000);
    for (int p = 10; p < (int)sieve.size(); p++)
    {
        bool ok = sieve[p];
        if (!ok)
            continue;
        for (int k = p; k > 0; k /= 10)
            ok &= sieve[k];
        if (!ok)
            continue;
        int d = 1;
        while (d < p)
            d *= 10;
        for (int k = p; k > 0; k %= d, d /= 10)
            ok &= sieve[k];
        if (!ok)
            continue;
        sum += p;
    }
    std::cout << sum << std::endl;
}