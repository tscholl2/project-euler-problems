/*
A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

1/2	= 	0.5
1/3	= 	0.(3)
1/4	= 	0.25
1/5	= 	0.2
1/6	= 	0.1(6)
1/7	= 	0.(142857)
1/8	= 	0.125
1/9	= 	0.(1)
1/10	= 	0.1
Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
 */
#include <iostream>
#include <vector>

int cycle_length(unsigned long long int d)
{
    unsigned long long int x = 1;
    std::vector<unsigned long long int> X = {x};
    while (true)
    {
        auto r = x / d;
        x = 10 * (x - d * r);
        if (x == 0)
            return 0;
        for (uint i = 0; i < X.size(); i++)
            if (x == X[i])
                return X.size() - i;
        X.push_back(x);
    }
}

int main()
{
    int max_n = 0;
    int max_d = 2;
    for (int d = 2; d < 1000; d++)
    {
        auto n = cycle_length(d);
        if (n > max_n)
        {
            max_n = n;
            max_d = d;
        }
    }
    std::cout << max_d << std::endl;
}