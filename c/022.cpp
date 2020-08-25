/*
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
int main()
{
    std::fstream f;
    f.open("c/names.txt", std::ios::in);
    std::string buf;
    std::vector<std::string> v;
    while (!f.eof())
    {
        std::getline(f, buf, '"');
        if (buf == "," || buf.empty())
            continue;
        v.push_back(buf);
    }
    std::sort(v.begin(), v.end());
    unsigned long int sum = 0;
    for (unsigned int i = 0; i < v.size(); i++)
        for (unsigned int j = 0; j < v[i].size(); j++)
            sum += (i + 1) * (v[i][j] - 'A' + 1);
    std::cout << sum << std::endl;
}