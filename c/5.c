/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include <stdio.h>

int main()
{
    int i = 1, j = 0;
    for (; i < 0xffffffff; i++)
    {
        for (j = 1; j <= 20; j++)
            if (i % j != 0)
                break;
        if (j == 21)
            return printf("%d", i);
    }
}