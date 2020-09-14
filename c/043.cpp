/*
The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.

Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:

d2d3d4=406 is divisible by 2
d3d4d5=063 is divisible by 3
d4d5d6=635 is divisible by 5
d5d6d7=357 is divisible by 7
d6d7d8=572 is divisible by 11
d7d8d9=728 is divisible by 13
d8d9d10=289 is divisible by 17
Find the sum of all 0 to 9 pandigital numbers with this property.
*/

#include <iostream>
#include <algorithm>

bool has_divisible_property(uint64_t a)
{
    return ((a / 1000000) % 1000) % 2 == 0 &&
           ((a / 100000) % 1000) % 3 == 0 &&
           ((a / 10000) % 1000) % 5 == 0 &&
           ((a / 1000) % 1000) % 7 == 0 &&
           ((a / 100) % 1000) % 11 == 0 &&
           ((a / 10) % 1000) % 13 == 0 &&
           ((a / 1) % 1000) % 17 == 0;
}

int main()
{
    uint64_t sum = 0;
    int v[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    do
    {
        if (v[0] == 0)
            continue;
        uint64_t a = 0;
        for (auto d : v)
            a = a * 10 + d;
        if (has_divisible_property(a))
            sum += a;
    } while (std::next_permutation(&v[0], &v[10]));
    std::cout << sum << std::endl;
}
