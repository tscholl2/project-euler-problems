/*
Euler discovered the remarkable quadratic formula:


It turns out that the formula will produce 40 primes for the consecutive integer values . However, when  is divisible by 41, and certainly when  is clearly divisible by 41.

The incredible formula  was discovered, which produces 80 primes for the consecutive values . The product of the coefficients, −79 and 1601, is −126479.

Considering quadratics of the form:

, where  and 

where  is the modulus/absolute value of 
e.g.  and 
Find the product of the coefficients,  and , for the quadratic expression that produces the maximum number of primes for consecutive values of , starting with .
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

#define eval(a,b,n) (n*n+a*n+b)

int main()
{
    int max_primes = 0;
    int max_ab = 0;
    auto sieve = prime_sieve(2000000);
    for (int a = -999; a < 1000; a++)
        for (int b = -999; b < 1000; b++)
        {
            int n = 0;
            while (eval(a, b, n) > 0 && sieve[eval(a, b, n)])
                n++;
            if (n > max_primes)
            {
                max_primes = n;
                max_ab = a * b;
            }
        }
    std::cout << max_ab << std::endl;
}