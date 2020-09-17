/*
There are exactly ten ways of selecting three from five, 12345:

123, 124, 125, 134, 135, 145, 234, 235, 245, and 345

In combinatorics, we use the notation, 
.

In general, 
 
, where , , and .

It is not until , that a value exceeds one-million: 
.

How many, not necessarily distinct, values of 
 for , are greater than one-million?
*/
#include <iostream>
#include <array>
#include <map>

const std::array<int, 25> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

std::map<int, std::array<int, 100>> factor_cache{};

std::array<int, 100> factor(int a)
{
    if (factor_cache.find(a) != factor_cache.end())
        return factor_cache[a];
    std::array<int, 100> f{};
    for (const auto &p : primes)
        for (int b = a; b % p == 0; b /= p)
            f[p]++;
    factor_cache[a] = f;
    return f;
}

bool is_large_binomial(int n, int r)
{
    std::array<int, 100> f{};
    for (int i = n; i > n - r; --i)
    {
        auto g = factor(i);
        for (int j = 0; j < 100; ++j)
            f[j] += g[j];
    }
    for (int i = 1; i <= r; ++i)
    {
        auto g = factor(i);
        for (int j = 0; j < 100; ++j)
            f[j] -= g[j];
    }
    uint64_t total = 1;
    for (uint64_t i = 0; i < 100; ++i)
        for (int k = f[i]; k > 0; --k)
            if ((total *= i) > 1000000)
                return true;
    return false;
}

int main()
{
    int count = 0;
    for (int n = 1; n <= 100; ++n)
        for (int r = 1; r <= n; ++r)
            if (is_large_binomial(n, r))
                count++;
    std::cout << count << std::endl;
}