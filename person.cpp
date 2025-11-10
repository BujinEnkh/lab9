#include "header.h"

Person::Person()
{
    Name = new char[13];
    strcpy(Name, "Not Acquired");
    SSNum = new char[13];
    strcpy(SSNum, "Not Acquired");
    Age = 0;
}

Person::Person(char *name, char *ssnum, int age)
{
    this->Name = new char[strlen(name) + 1];
    strcpy(this->Name, name);
    this->SSNum = new char[strlen(ssnum) + 1];
    strcpy(this->SSNum, ssnum);
    this->Age = age;
}

Person::~Person()
{
    delete[] Name;
    delete[] SSNum;
}

char *Person::getName()
{
    return this->Name;
}

char *Person::getSSNum()
{
    return this->SSNum;
}

int Person::getAge()
{
    return this->Age;
}

void Person::setName(char *name)
{
    this->Name = new char[strlen(name) + 1];
    strcpy(this->Name, name);
}

void Person::setSSNum(char *ssnum)
{
    this->SSNum = new char[strlen(ssnum) + 1];
    strcpy(this->Name, ssnum);
}

void Person::setAge(int age)
{
    this->Age = age;
}