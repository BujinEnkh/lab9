#include "header.h"

Division::Division()
{
    DivisionName = new char[13];
    stpcpy(DivisionName,"Not Acquired");
}

Division::Division(char *name)
{
    DivisionName = new char[strlen(name) + 1];
    strcpy(DivisionName, name);
}

Division::~Division()
{
    delete[] DivisionName;
}

char *Division::getDivisionName()
{
    return DivisionName;
}

void Division::setDivisionName(char *name)
{
    DivisionName = new char[strlen(name) + 1];
    strcpy(DivisionName, name);
}