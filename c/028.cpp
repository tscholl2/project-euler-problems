/*
Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
*/
#include <iostream>

#define _N 1001

int main()
{
    int A[_N][_N] = {0};
    int x, y;
    x = y = _N / 2;
    int n = A[x][y] = 1;
    while (x != _N - 1 || y != 0)
    {
        A[++x][y] = ++n;
        int s = 2 * (x - _N / 2) + 1;
        for (int i = 0; i < s - 2; i++)
            A[x][++y] = ++n;
        for (int i = 0; i < s - 1; i++)
            A[--x][y] = ++n;
        for (int i = 0; i < s - 1; i++)
            A[x][--y] = ++n;
        for (int i = 0; i < s - 1; i++)
            A[++x][y] = ++n;
    }
    int sum = -1;
    for (int i = 0; i < _N; i++)
        sum += A[i][i] + A[i][_N - 1 - i];
    std::cout << sum << std::endl;
}
