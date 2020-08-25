/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <stdio.h>

int is_palindrome(int n)
{
    int digits[6] = {0};
    for (int i = 0; i < 6; i++)
        digits[i] = n % 10, n /= 10;
    return digits[5] == digits[0] && digits[4] == digits[1] && digits[3] == digits[2];
}

int main()
{
    int max = 0;
    for (int i = 100; i < 1000; i++)
        for (int j = i; j < 1000; j++)
            if (i * j > max && is_palindrome(i * j))
                max = i * j;
    printf("%d", max);
}