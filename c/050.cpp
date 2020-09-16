/*
The prime 41, can be written as the sum of six consecutive primes:

41 = 2 + 3 + 5 + 7 + 11 + 13
This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes?
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

int main()
{
    auto is_prime = prime_sieve(1000000);
    std::vector<uint64_t> primes;
    for (uint i = 0; i < is_prime.size(); ++i)
        if (is_prime[i])
            primes.push_back(i);
    uint max_length = 0;
    uint64_t max_sum = 0;
    for (uint i = 0; i < primes.size(); ++i)
    {
        uint64_t sum = 0;
        for (uint j = i; j < primes.size(); ++j)
        {
            sum += primes[j];
            if (sum >= is_prime.size())
                break;
            if (is_prime[sum] && 1 + j - i > max_length)
                max_sum = sum, max_length = 1 + j - i;
        }
    }
    std::cout << max_sum << std::endl;
}
