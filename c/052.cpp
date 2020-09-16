/*
It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.

Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.
*/
#include <iostream>
#include <set>

std::set<int> digits(int a)
{
    std::set<int> s{};
    while (a > 0)
        s.insert(a % 10), a /= 10;
    return s;
}

int main()
{
    for (int a = 1; 1; ++a)
    {
        auto S = digits(a);
        bool ok = true;
        for (int x = 2; x < 7 && ok; ++x)
            ok &= digits(x * a) == S;
        if (ok)
        {
            std::cout << a << std::endl;
            return 0;
        }
    }
}