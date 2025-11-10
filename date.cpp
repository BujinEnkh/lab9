#include "header.h"

Date::Date()
{
    Year = 0;
    Month = 0;
    Day = 0;
}

Date::Date(int year, int month, int day)
{
    Year = year;
    Month = month;
    Day = day;
}

void Date::display()
{
    cout << Year << "/" << Month << "/" << Day;
}