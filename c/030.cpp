/*
Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

1634 = 14 + 64 + 34 + 44
8208 = 84 + 24 + 04 + 84
9474 = 94 + 44 + 74 + 44
As 1 = 14 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
*/

#include <iostream>

int main()
{
    int sum = 0;
    /*
    n-digit number >= 10^(n-1)
    sum 5th powers <= n*10^5
    so n < 7
    */
    for (int a = 2; a < 1000000; a++)
    {
        int m = 0;
        for (int b = a; b > 0; b /= 10)
            m += (b % 10) * (b % 10) * (b % 10) * (b % 10) * (b % 10);
        sum += (m == a) * m;
    }
    std::cout << sum << std::endl;
}