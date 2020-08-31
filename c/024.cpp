/*
A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*/
#include <iostream>
#include <vector>
#include <algorithm>

int next(std::vector<int> &v, size_t idx)
{
    auto length = v.size() - idx;
    if (length <= 1)
        return 0;
    if (next(v, idx + 1))
        return 1;
    auto idx2 = v.size() - 1;
    while (v[idx] > v[idx2] && idx < idx2)
        idx2--;
    if (idx2 == idx)
        return 0;
    std::swap(v[idx], v[idx2]);
    std::sort(v.begin() + idx + 1, v.end());
    return 1;
}

int next(std::vector<int> &v)
{
    return next(v, 0);
}

int main()
{
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 1000000 - 1; i++)
        next(v);
    std::cout << "v: ";
    for (auto a : v)
        std::cout << a;
    std::cout << std::endl;
}