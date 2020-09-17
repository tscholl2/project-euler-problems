/*
If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.

Not all numbers produce palindromes so quickly. For example,

349 + 943 = 1292,
1292 + 2921 = 4213
4213 + 3124 = 7337

That is, 349 took three iterations to arrive at a palindrome.

Although no one has proved it yet, it is thought that some numbers, like 196, never produce a palindrome. A number that never forms a palindrome through the reverse and add process is called a Lychrel number. Due to the theoretical nature of these numbers, and for the purpose of this problem, we shall assume that a number is Lychrel until proven otherwise. In addition you are given that for every number below ten-thousand, it will either (i) become a palindrome in less than fifty iterations, or, (ii) no one, with all the computing power that exists, has managed so far to map it to a palindrome. In fact, 10677 is the first number to be shown to require over fifty iterations before producing a palindrome: 4668731596684224866951378664 (53 iterations, 28-digits).

Surprisingly, there are palindromic numbers that are themselves Lychrel numbers; the first example is 4994.

How many Lychrel numbers are there below ten-thousand?

NOTE: Wording was modified slightly on 24 April 2007 to emphasise the theoretical nature of Lychrel numbers.
*/
#include <iostream>
#include <vector>

class BigInt
{
public:
    BigInt() : BigInt(std::vector<int>()){};
    BigInt(int a)
    {
        for (; a > 0; a /= 10)
            D.push_back(a % 10);
    }
    BigInt(std::vector<int> digits) : D(digits){};
    std::vector<int> D;
    int size() const { return D.size(); }
    BigInt reverse() const
    {
        BigInt a{};
        for (auto i = D.rbegin(); i != D.rend(); ++i)
            a.D.push_back(*i);
        return a;
    }
    BigInt operator+(const BigInt &rhs) const
    {
        const auto &lhs = *this;
        BigInt a{};
        int carry = 0;
        for (int i = 0; i < std::max(lhs.size(), rhs.size()); ++i)
        {
            int d = lhs[i] + rhs[i] + carry;
            a.D.push_back(d % 10);
            carry = d / 10;
        }
        if (carry)
            a.D.push_back(carry);
        return a;
    }
    bool is_palindrome() const
    {
        const auto &a = *this;
        for (int i = 0; i < a.size() / 2; ++i)
            if (a[i] != a[a.size() - 1 - i])
                return false;
        return true;
    }
    bool is_lychrel() const
    {
        auto a = BigInt(this->D);
        for (int j = 0; j < 50; ++j)
        {
            a = a + a.reverse();
            if (a.is_palindrome())
                return false;
        }
        return true;
    };
    int operator[](int i) const { return i > (int)D.size() ? 0 : D[i]; }
};

int main()
{
    int count = 0;
    for (int i = 1; i < 10000; ++i)
        count += BigInt(i).is_lychrel();
    std::cout << count << std::endl;
}