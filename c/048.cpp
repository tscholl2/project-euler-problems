/*
The series, 11 + 22 + 33 + ... + 1010 = 10405071317.

Find the last ten digits of the series, 11 + 22 + 33 + ... + 10001000.
*/
#include <iostream>

int main()
{
    uint64_t sum = 0;
    for (uint64_t a = 1; a <= 1000; a++)
    {
        uint64_t b = 1;
        for (uint64_t i = 0; i < a; i++)
            b = (a * b) % 10000000000;
        sum = (sum + b) % 10000000000;
    }
    std::cout << sum << std::endl;
}