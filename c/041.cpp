/*
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists?
*/
#include <iostream>
#include <vector>
#include <cstring>

bool *prime_sieve(uint N)
{
    auto sieve = new bool[N];
    std::memset(sieve, true, N);
    sieve[0] = sieve[1] = false;
    for (uint i = 2; i < N; i++)
        if (!sieve[i])
            continue;
        else
            for (uint j = 2 * i; j < N; j += i)
                sieve[j] = false;
    return sieve;
}

int is_pandigital(int a)
{
    int goal[10] = {0};
    goal[1] = 1;
    int n = 1;
    for (int k = 1; 10 * k <= a; k *= 10)
        goal[++n] = 1;
    int counts[10] = {0};
    for (; a > 0; a /= 10)
        counts[a % 10]++;
    return std::memcmp(counts, goal, 10 * sizeof(goal[0])) == 0;
}

int main()
{
    // cant be 9 digits cause 1+..+9 = 0 mod 9, so 9 | n
    // cant be 8 for same reason
    auto primes = prime_sieve(7654322);
    int i;
    for (i = 7654322 - 1; i >= 0; i--)
        if (primes[i] && is_pandigital(i))
            break;
    std::cout << i << std::endl;
}