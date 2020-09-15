/*
The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.

There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.

What 12-digit number do you form by concatenating the three terms in this sequence?
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

std::vector<bool> prime_sieve(uint N)
{
    auto sieve = std::vector<bool>(N, true);
    sieve[0] = sieve[1] = false;
    for (uint i = 2; i < N; ++i)
        if (sieve[i])
            for (uint j = 2 * i; j < N; j += i)
                sieve[j] = false;
    return sieve;
}

bool is_permutation(int a, int b, int c)
{
    std::set<int> A = {};
    std::set<int> B = {};
    std::set<int> C = {};
    for (; a > 0; a /= 10)
        A.insert(a % 10);
    for (; b > 0; b /= 10)
        B.insert(b % 10);
    for (; c > 0; c /= 10)
        C.insert(c % 10);
    return A == B && A == C;
}

int main()
{
    auto is_prime = prime_sieve(30000);
    for (int p1 = 1488; p1 < 10000; ++p1)
        for (int p2 = p1 + 1; p2 < 10000; ++p2)
        {
            auto p3 = p2 + (p2 - p1);
            if (p3 > 9999 ||
                !is_prime[p1] || !is_prime[p2] || !is_prime[p3] ||
                !is_permutation(p1, p2, p3))
                continue;
            std::cout << p1 << p2 << p3 << std::endl;
            return 0;
        }
}