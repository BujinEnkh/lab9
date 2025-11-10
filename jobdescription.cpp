#include "header.h"

JobDescription::JobDescription()
{
    Description = new char[13];
    stpcpy(Description,"Not Acquired");
}

JobDescription::JobDescription(char *desc)
{
    Description = new char[strlen(desc) + 1];
    strcpy(Description, desc);
}

JobDescription::~JobDescription()
{
    delete[] Description;
}

char *JobDescription::getJobDesciption()
{
    return Description;
}

void JobDescription::setJobDescription(char *desc)
{
    Description = new char[strlen(desc) + 1];
    strcpy(Description, desc);
}