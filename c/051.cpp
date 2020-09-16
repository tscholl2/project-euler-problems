/*
By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.

By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being the first member of this family, is the smallest prime with this property

Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.
*/
#include <iostream>

#include <vector>

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

std::vector<int> to_digits(int a)
{
    std::vector<int> digits;
    while (a > 0)
        digits.push_back(a % 10), a /= 10;
    return digits;
}

int from_digits(const std::vector<int> &digits)
{
    int a = 0;
    for (auto itr = digits.rbegin(); itr != digits.rend(); ++itr)
        a = 10 * a + *itr;
    return a;
}

int test(int p, std::vector<bool> is_prime)
{
    auto digits = to_digits(p);
    auto N = 1 << digits.size();
    for (int i = 1; i < N-1; ++i)
    {
        auto v = digits;
        int count = 0;
        for (int d = 9; d >= i>>(digits.size()-1) ? 1 : 0; --d)
        {
            for (uint j = 0; j < v.size(); ++j)
                if ((i >> j) & 1)
                    v[j] = d;
            if (is_prime[from_digits(v)])
                ++count;
        }
        if (count == 8)
            return from_digits(v);
    }
    return 0;
}

int main()
{
    auto is_prime = prime_sieve(1000000);
    for (int i = 120383; i < 120383+1; ++i)
    {
        if (!is_prime[i])
            continue;
        int ok;
        if ((ok = test(i, is_prime)))
        {
            std::cout << ok << std::endl;
            break;
        }
    }
}