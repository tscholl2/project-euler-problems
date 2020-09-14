/*
It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.

9 = 7 + 2×12
15 = 7 + 2×22
21 = 3 + 2×32
25 = 7 + 2×32
27 = 19 + 2×22
33 = 31 + 2×12

It turns out that the conjecture was false.

What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
*/
#include <iostream>
#include <cstring>

#define SIZE 10000

bool *prime_sieve(uint N)
{
    auto sieve = new bool[N];
    std::memset(sieve, true, N);
    sieve[0] = sieve[1] = false;
    for (uint i = 2; i < N; i++)
        if (sieve[i])
            for (uint j = 2 * i; j < N; j += i)
                sieve[j] = false;
    return sieve;
}

bool *square_sieve(uint N)
{
    auto sieve = new bool[N];
    std::memset(sieve, false, N);
    for (uint i = 0; i < N; i++)
        if (i * i < N)
            sieve[i * i] = true;
        else
            break;
    return sieve;
}

int main()
{
    auto is_prime = prime_sieve(SIZE);
    auto is_square = square_sieve(SIZE);
    for (uint i = 3; i < SIZE; i += 2)
    {
        if (is_prime[i])
            continue;
        for (uint p = 3; p < i; p += 2)
            if (is_prime[p] && is_square[(i - p) / 2])
                goto next;
        std::cout << i << std::endl;
        break;
    next:;
    }
}