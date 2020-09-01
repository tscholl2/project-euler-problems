/*
145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: As 1! = 1 and 2! = 2 are not sums they are not included.
*/
#include <iostream>

int factorials[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int main()
{
    int sum = 0;
    for (int i = 3; i < 9999999; i++)
    /*
    10^(n-1) > n*9! for n > 7.5
    */
    {
        int k = 0;
        for (int d = i; d > 0; d /= 10)
            k += factorials[d % 10];
        if (k == i)
            sum += i;
    }
    std::cout << sum << std::endl;
}