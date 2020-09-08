/*
If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p ≤ 1000, is the number of solutions maximised?
*/
#include <iostream>
#include <vector>

int main()
{
    int is_square[1000000] = {0};
    int square_root[1000000] = {0};
    std::vector<int> squares;
    for (int i = 0; i < 1000; i++)
    {
        is_square[i * i] = 1;
        squares.push_back(i * i);
        square_root[i * i] = i;
    }
    int solutions[1001] = {0};
    for (auto itr_a = squares.begin(); itr_a != squares.end(); ++itr_a)
        for (auto itr_b = itr_a + 1; itr_b != squares.end(); ++itr_b)
        {
            auto a2 = *itr_a;
            auto b2 = *itr_b;
            auto c2 = a2 + b2;
            if (c2 >= 1000000)
                break;
            if (!is_square[c2])
                continue;
            auto p = square_root[a2] + square_root[b2] + square_root[c2];
            if (p < 1001)
                solutions[p]++;
        }
    int max_idx = 0;
    for (int p = 0; p < 1001; p++)
        if (solutions[p] > solutions[max_idx])
            max_idx = p;
    std::cout << max_idx << std::endl;
}