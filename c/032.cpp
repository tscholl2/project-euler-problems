/*
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
*/
#include <iostream>
#include <set>
#include <vector>

bool is_good(int a, int b)
{
    std::set<int> S;
    std::vector<int> digits;
    int c = a * b;
    for (; a > 0; a /= 10)
        digits.push_back(a % 10);
    for (; b > 0; b /= 10)
        digits.push_back(b % 10);
    for (; c > 0; c /= 10)
        digits.push_back(c % 10);
    for (auto d : digits)
        if (d == 0 || S.count(d) > 0)
            return false;
        else
            S.insert(d);
    return S.size() == 9;
}

int main()
{
    std::set<int> S;
    for (int a = 0; a < 999; a++)
        for (int b = a; b < 9999; b++)
            if (is_good(a, b))
                S.insert(a * b);
    int sum = 0;
    for (auto x : S)
        sum += x;
    std::cout << sum << std::endl;
}