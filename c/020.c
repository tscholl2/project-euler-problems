/*
n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void add(char *dest, char *src, size_t s_dest, size_t s_src)
{
    char c = 0;
    for (int i = 0; i < s_dest; i++)
    {
        c = dest[i] + c + (i < s_src ? src[i] : 0);
        dest[i] = c % 10;
        c /= 10;
    }
}

void mul(char *dest, char *src, size_t s_dest, size_t s_src)
{
    char *T1 = calloc(s_dest, sizeof(char));
    char *T2 = calloc(s_dest, sizeof(char));
    for (int i = 0; i < s_src; i++)
    {
        memset(T1, 0, s_dest);
        char c = 0;
        for (int j = 0; j < s_dest; j++)
        {
            c = dest[j] * src[i] + c;
            T1[j] = c % 10;
            c /= 10;
        }
        memmove(&T1[i], T1, s_dest - i);
        memset(T1, 0, i);
        add(T2, T1, s_dest, s_dest);
    }
    memcpy(dest, T2, s_dest);
    free(T1);
    free(T2);
}

int main()
{
    char N[1000] = {0};
    N[0] = 1;
    for (int i = 1; i <= 100; i++)
    {
        char M[3] = {i % 10, (i / 10) % 10, (i / 100) % 10};
        mul(N, M, sizeof(N), sizeof(M));
    }
    int sum = 0;
    for (int i = sizeof(N) - 1; i >= 0; i--)
        sum += N[i];
    printf("%d", sum);
}