/*
The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
*/
#include <iostream>

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int N = 1;
    int D = 1;
    for (int n = 10; n < 100; n++)
        for (int d = n + 1; d < 100; d++)
        {
            // n/d = a1a2/b1b2
            int a2 = n % 10;
            int a1 = (n - a2) / 10;
            int b2 = d % 10;
            int b1 = (d - b2) / 10;
            if (a2 == 0 && b2 == 0)
                continue;
            int x, y;
            if (a1 == b1)
                x = a2, y = b2;
            else if (a1 == b2)
                x = a2, y = b1;
            else if (a2 == b1)
                x = a1, y = b2;
            else if (a2 == b2)
                x = a1, y = b1;
            else
                continue;
            if (y * n == x * d)
                N *= x, D *= y;
        }
    std::cout << D / gcd(N, D) << std::endl;
}