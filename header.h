#pragma once

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
class Date
{
public:
    int Year;
    int Month;
    int Day;
    Date();
    Date(int, int, int);
    void display();
};

class Person
{
    protected:
    char *Name;
    char *SSNum;
    int Age;
    public:
    Person();
    Person(char *, char *, int);
    ~Person();
    char *getName();
    char *getSSNum();
    int getAge();
    void setName(char *);
    void setSSNum(char *);
    void setAge(int);
};

class Spouse : public Person
{
    protected:
    Date AnniversaryDate;
    public:
    Spouse();
    Spouse(char *, char *, int, Date);
    Date getAnniversaryDate();
    void setAnniversaryDate(Date);
};

class Child : public Person
{
    protected:
    char *FavoriteToy;
    public:
    Child();
    Child(char *, char *, int, char *);
    ~Child();
    char *getFavoriteToy();
    void setFavoriteToy(char *);
};

class Division
{
    protected:
    char *DivisionName;
    public:
    Division();
    Division(char *);
    ~Division();
    char *getDivisionName();
    void setDivisionName(char *);
};

class JobDescription
{
    protected:
    char *Description;
    public:
    JobDescription();
    JobDescription(char *);
    ~JobDescription();
    char *getJobDesciption();
    void setJobDescription(char *);
};

class Employee : private Person
{
    protected:
    Spouse *spouse = NULL;
    vector<Child *> children;
    Division *div = NULL;
    vector<JobDescription *> description;
    char *CompanyID;
    char *Title;
    Date StartDate;
    public:
    Employee();
    Employee(char *, char *, int, char *, char *, Date);
    ~Employee();
    char *getCompanyID();
    char *getTitle();
    Date getStartDate();
    Spouse *getSpouse();
    vector<Child *> getChildren();
    Division *getDivision();
    vector<JobDescription *> getJobDescriptions();
    void setCompanyID(char *);
    void setTitle(char *);
    void setStartDate(Date);
    void setSpouse(Spouse *);
    void addChild(Child *);
    void setJobDivision(Division *);
    void addJobDescription(JobDescription *);
    void display();
};