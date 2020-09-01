/*
In the United Kingdom the currency is made up of pound (£) and pence (p). There are eight coins in general circulation:

1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).
It is possible to make £2 in the following way:

1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
How many different ways can £2 be made using any number of coins?
*/
#include <iostream>
#include <vector>

const std::vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200};

int count(int target, int current_coin)
{
    target -= coins[current_coin];
    if (target < 0)
        return 0;
    if (target == 0)
        return 1;
    int sum = 0;
    for (uint i = current_coin; i < coins.size(); i++)
        sum += count(target, i);
    return sum;
}

int main()
{
    int c = 0;
    for (uint i = 0; i < coins.size(); i++)
        c += count(200, i);
    std::cout << c << std::endl;
}
