/*
The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

Let us list the factors of the first seven triangle numbers:

 1: 1
 3: 1,3
 6: 1,2,3,6
10: 1,2,5,10
15: 1,3,5,15
21: 1,3,7,21
28: 1,2,4,7,14,28
We can see that 28 is the first triangle number to have over five divisors.

What is the value of the first triangle number to have over five hundred divisors?
*/
#include <stdio.h>

int number_of_factors(int n)
{
    int p = 2, t = 1, k;
    while (n > 1)
    {
        for (k = 0; n % p == 0; k++, n /= p)
            ;
        t += t * k;
        p++;
    }
    return t;
}

int main()
{
    int triangle_number = 1;
    int index = 1;
    int factors = 1;
    while (factors < 500)
        factors = number_of_factors(triangle_number += (++index));
    printf("%d\n", triangle_number);
}