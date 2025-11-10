#include "header.h"

Spouse::Spouse() : Person()
{
    AnniversaryDate = Date(0, 0, 0);
}

Spouse::Spouse(char *name, char *ssnum, int age, Date date) : Person(name, ssnum, age)
{
    AnniversaryDate = date;
}

Date Spouse::getAnniversaryDate()
{
    return AnniversaryDate;
}

void Spouse::setAnniversaryDate(Date date)
{
    AnniversaryDate = date;
}