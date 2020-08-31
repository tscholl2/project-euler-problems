/*
The Fibonacci sequence is defined by the recurrence relation:

Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
Hence the first 12 terms will be:

F1 = 1
F2 = 1
F3 = 2
F4 = 3
F5 = 5
F6 = 8
F7 = 13
F8 = 21
F9 = 34
F10 = 55
F11 = 89
F12 = 144
The 12th term, F12, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
*/
#include <iostream>
#include <vector>

std::vector<int> add(std::vector<int> &v, std::vector<int> &w)
{
    std::vector<int> u;
    uint carry = 0;
    for (uint i = 0; i < std::max(v.size(), w.size()); i++)
    {
        uint a = i >= v.size() ? 0 : v[i];
        uint b = i >= w.size() ? 0 : w[i];
        carry += a + b;
        u.push_back(carry % 10);
        carry /= 10;
    }
    if (carry)
        u.push_back(carry);
    return u;
}

int main()
{
    int n = 1;
    std::vector<int> fn = {1};
    std::vector<int> fnp1 = {1};
    while (fn.size() < 1000)
    {
        n++;
        fn = add(fn, fnp1);
        std::swap(fn, fnp1);
    }
    std::cout << n << std::endl;
}