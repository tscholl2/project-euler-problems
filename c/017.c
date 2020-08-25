/*
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?


NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char *ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char *teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    char *tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    int sum = 0;
    for (int i = 1; i < 1000; i++)
    {
        int characters;

        int d1 = i % 10;
        int d2 = (i / 10) % 10;
        int d3 = (i / 100) % 10;
        if (d3 > 0)
            sum += strlen(ones[d3]) + strlen("hundred") + (d1 + d2 > 0 ? strlen("and") : 0);
        if (d2 == 1)
            sum += strlen(teens[d1]);
        else
        {
            sum += strlen(tens[d2]);
            sum += strlen(ones[d1]);
        }
    }
    sum += 11; // "one thousand"
    printf("%d", sum);
}