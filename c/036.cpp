/*
The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.)
*/
#include <iostream>
#include <vector>

bool is_double_palindrome(int a)
{
    for (int base : std::vector<int>{2, 10})
    {
        std::vector<int> digits;
        for (int b = a; b > 0; b /= base)
            digits.push_back(b % base);
        for (uint i = 0; i < digits.size() / 2; i++)
            if (digits[i] != digits[digits.size() - i - 1])
                return false;
    }
    return true;
}

int main()
{
    int sum = 0;
    for (int i = 0; i < 1000000; i++)
        if (is_double_palindrome(i))
            sum += i;
    std::cout << sum << std::endl;
}