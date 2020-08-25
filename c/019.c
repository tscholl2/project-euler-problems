/*
You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/
#include <stdio.h>

//"jan feb mar apr may jun jul aug sep oct nov dec"
//"0   1   2   3   4   5   6   7   8   9   10  11"
//"31  28  31  30  31  30  31  31  30  31  30  31"

const int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//"M T W R F S S"
//"0 1 2 3 4 5 6"

int main()
{
    int sundays_on_first_of_month = 0;
    int day_of_the_week = 0;
    for (int year = 1900; year < 2001; year++)
    {
        int is_leap_year = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
        for (int month = 0; month < 12; month++)
        {
            sundays_on_first_of_month += (year > 1900) && (day_of_the_week == 6);
            day_of_the_week = (day_of_the_week + days_in_month[month] + (month == 1 && is_leap_year)) % 7;
        }
    }
    printf("%d", sundays_on_first_of_month);
}
