/*
The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/

#include <stdio.h>

long long seen[1000000] = {0};

long long sequence_length(long long n)
{
    if (n < (sizeof(seen) / sizeof(long long)) && seen[n] > 0)
        return seen[n];
    long long l = n == 1 ? 1 : 1 + sequence_length(n % 2 ? 3 * n + 1 : n / 2);
    if (n < (sizeof(seen) / sizeof(long long)))
        seen[n] = l;
    return l;
}

int main()
{
    long long max = 0, max_start = 0;
    for (long long start = 1; start < 1000000; start++)
    {
        long long length = sequence_length(start);
        if (length > max)
        {
            max = length;
            max_start = start;
        }
    }
    printf("%lld", max_start);
}