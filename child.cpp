#include "header.h"

Child::Child() : Person()
{
    Name = new char[13];
    strcpy(Name, "Not Acquired");
}
Child::Child(char *name, char *ssnum, int age, char *toy) : Person(name, ssnum, age)
{
    FavoriteToy = new char[strlen(toy) + 1];
    strcpy(FavoriteToy, toy);
}

Child::~Child()
{
    delete[] FavoriteToy;
}

char *Child::getFavoriteToy()
{
    return FavoriteToy;
}
void Child::setFavoriteToy(char *toy)
{
    FavoriteToy = new char[strlen(toy) + 1];
    strcpy(FavoriteToy, toy);
}