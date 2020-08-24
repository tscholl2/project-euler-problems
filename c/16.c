/*
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?
*/

#include <stdio.h>

int main()
{
    int total[9999] = {0};
    total[0] = 1;
    for (int i = 0; i < 1000; i++)
    {
        int carry = 0;
        for (int j = 0; j < 9999; j++)
        {
            int digit = 2 * (total[j]) + carry;
            total[j] = (digit % 10);
            carry = digit / 10;
        }
    }
    int sum = 0;
    for (int i = 0; i < 9999; i++)
        sum += total[i];
    printf("%d", sum);
}
