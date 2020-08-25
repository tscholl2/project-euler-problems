/*
The sum of the squares of the first ten natural numbers is,

The square of the sum of the first ten natural numbers is,

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is .

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/
#include <stdio.h>

int main()
{
    double sum = 0, sum_of_squares = 0;
    for (double i = 1; i <= 100; i++)
    {
        sum += i;
        sum_of_squares += i * i;
    }
    printf("%lf", sum * sum - sum_of_squares);
}