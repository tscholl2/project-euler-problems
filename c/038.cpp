/*
Take the number 192 and multiply it by each of 1, 2, and 3:

192 × 1 = 192
192 × 2 = 384
192 × 3 = 576
By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)

The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).

What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?
*/
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>

uint64_t concatenated_product(uint64_t a, uint64_t n)
{
    std::string s = "";
    for (uint64_t i = 1; i <= n; i++)
        s += std::to_string(a * i);
    return (uint64_t)std::stoll(s);
}

uint64_t is_pandigital(uint64_t a)
{
    int goal[10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int counts[10] = {0};
    for (; a > 0; a /= 10)
        counts[a % 10]++;
    return std::memcmp(counts, goal, 10 * sizeof(goal[0])) == 0;
}

int main()
{
    uint64_t max;
    uint64_t min_pandigital = 123456789;
    uint64_t max_pandigital = 987654321;
    for (uint64_t a = 1; a < 10000; a++)
        for (uint64_t n = 2; n < 9; n++)
        {
            auto b = concatenated_product(a, n);
            if (b < min_pandigital)
                continue;
            if (b > max_pandigital)
                break;
            if (is_pandigital(b) && b > max)
                max = b;
        }
    std::cout << max << std::endl;
}
