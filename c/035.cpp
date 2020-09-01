/*
The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?
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

int rotate(int a)
{
    int b = 0;
    int k;
    for (k = 10; k <= a; k *= 10)
        b += (k / 10) * ((a / k) % 10);
    return b + (k / 10) * (a % 10);
}

int main()
{
    int total = 0;
    std::vector<int> sieve = prime_sieve(1000000);
    for (int i = 0; i < (int)sieve.size(); i++)
    {
        if (!sieve[i])
            continue;
        bool ok = true;
        for (int j = i; j > 0; j /= 10)
            ok &= j % 10 != 0;
        for (int j = rotate(i); ok && j != i; j = rotate(j))
            ok &= sieve[j];
        total += ok;
    }
    std::cout << total << std::endl;
}
