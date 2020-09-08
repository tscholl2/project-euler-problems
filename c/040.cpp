/*
An irrational decimal fraction is created by concatenating the positive integers:

0.123456789101112131415161718192021...

It can be seen that the 12th digit of the fractional part is 1.

If dn represents the nth digit of the fractional part, find the value of the following expression.

d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000
*/
#include <iostream>

int main()
{
    int product = 1;
    int n = 1;
    for (int k = 1; n < 1000000; k++)
    {
        int i = 1;
        while (i * 10 <= k)
            i *= 10;
        for (; i > 0; i /= 10, n++)
            if (n == 1 || n == 10 || n == 100 || n == 1000 || n == 10000 || n == 100000 || n == 1000000)
                product *= (k / i) % 10;
    }
    std::cout << product << std::endl;
}