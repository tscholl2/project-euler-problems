/*
The first two consecutive numbers to have two distinct prime factors are:

14 = 2 × 7
15 = 3 × 5

The first three consecutive numbers to have three distinct prime factors are:

644 = 2² × 7 × 23
645 = 3 × 5 × 43
646 = 2 × 17 × 19.

Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?
*/
#include <iostream>
#include <cstring>

#define SIZE 1000000
#define CONSECUTIVE 4

int main()
{
    int state = 0;
    for (int i = 0; i < SIZE; i++)
    {
        int a = i;
        int d = 0;
        for (int p = 2; p <= a && a > 1; p == 2 ? p = 3 : p += 2)
            if (a % p == 0 && ++d)
                while (a % p == 0)
                    a /= p;
        state = d == CONSECUTIVE ? state + 1 : 0;
        if (state == CONSECUTIVE)
        {
            std::cout << i - state + 1 << std::endl;
            break;
        }
    }
}