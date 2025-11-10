#include "header.h"

Employee::Employee() : Person()
{
    setSpouse(new Spouse("Not Acquired", "Not Acquired", 0, Date(0, 0, 0)));
    setJobDivision(new Division("Not Acquired"));
    CompanyID = new char[13];
    strcpy(CompanyID, "Not Acquired");
    Title = new char[13];
    strcpy(Title,"Not Acquired");
}

Employee::Employee(char *name, char *ssnum, int age, char *cmpnID, char *title, Date date) : Person(name, ssnum, age)
{
    setSpouse(new Spouse("Not Acquired", "Not Acquired", 0, Date(0, 0, 0)));
    setJobDivision(new Division("Not Acquired"));
    CompanyID = new char[strlen(cmpnID) + 1];
    strcpy(this->CompanyID, cmpnID);
    Title = new char[strlen(title) + 1];
    strcpy(this->Title, title);
    StartDate = date;
}

Employee::~Employee()
{
    delete[] CompanyID;
    delete[] Title;
}

char *Employee::getCompanyID()
{
    return CompanyID;
}

char *Employee::getTitle()
{
    return Title;
}

Date Employee::getStartDate()
{
    return StartDate;
}

Spouse *Employee::getSpouse()
{
    return spouse;
}

vector<Child *> Employee::getChildren()
{
    return children;
}

Division *Employee::getDivision()
{
    return div;
}

vector<JobDescription *> Employee::getJobDescriptions()
{
    return description;
}

void Employee::setCompanyID(char *cmpnID)
{
    CompanyID = new char[strlen(cmpnID) + 1];
    strcpy(this->CompanyID, cmpnID);
}

void Employee::setTitle(char *title)
{
    Title = new char[strlen(title) + 1];
    strcpy(this->Title, title);
}

void Employee::setStartDate(Date date)
{
    StartDate = date;
}

void Employee::setSpouse(Spouse *s)
{
    spouse = s;
}

void Employee::addChild(Child *child)
{
    children.push_back(child);
}

void Employee::setJobDivision(Division *div)
{
    this->div = div;
}

void Employee::addJobDescription(JobDescription *jd)
{
    description.push_back(jd);
}

void Employee::display()
{
    cout << "Name: " << this->getName() << endl;
    cout << "ID: " << this->getSSNum() << endl;
    cout << "Age: " << this->getAge() << endl;
    cout << "Spouse: " << this->spouse->getName() << endl;
    cout << "Anniversary Date: ";
    this->spouse->getAnniversaryDate().display();
    cout << endl;
    if (!children.empty())
    {
        cout << "Children:" << endl;
        for (auto i : children)
        {
            cout << "-" << "Name: " << i->getName() << " | Age: " << i->getAge() << endl;
        }
    }
    cout << "Company ID: " << this->getCompanyID() << endl;
    cout << "Division: " << this->div->getDivisionName() << endl;
    cout << "Title: " << this->getTitle() << endl;
    if (!description.empty())
    {
        cout << "Job Description:" << endl;
        for (auto i : description)
            {
                cout << i->getJobDesciption() << endl;
            }
    }
}