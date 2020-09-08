/*
The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.

Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?
*/
#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::string> read_words()
{
    int state = 0; // 0 = not word, 1 = word
    std::vector<std::string> words;
    std::string s;
    std::ifstream in("042words.txt", std::ios::out);
    char c;
    while (in.get(c))
    {
        if (c == '"')
        {
            if (state == 0)
                s = "";
            else if (state == 1)
                words.push_back(s);
            state = !state;
        }
        else if (state == 1)
            s += std::string(1, c);
    }
    in.close();
    return words;
}

int is_triangle(int a)
{
    int i = 0;
    while (a > 0)
        a -= i++;
    return a == 0;
}

int main()
{
    const auto words = read_words();
    int count = 0;
    for (auto itr_w = words.begin(); itr_w != words.end(); itr_w++)
    {
        int sum = 0;
        auto w = *itr_w;
        for (auto itr_c = w.begin(); itr_c != w.end(); itr_c++)
            sum += *itr_c - char('A') + 1;
        count += is_triangle(sum);
    }
    std::cout << count << std::endl;
}