#include "header.h"

int main()
{
    vector<Employee *> emps;
    vector<Spouse *> spouses;
    vector<Child *> children;
    vector<Division *> divs;
    vector<JobDescription *> descs;
    emps.push_back(new Employee("Josh","AR2342", 23,"S12","Hardware Engineer", Date(2023, 9, 30)));
    emps.push_back(new Employee("Ben","KR6216", 30,"S12","Senior Developer", Date(2017, 4, 2)));
    emps.push_back(new Employee("Kate","AR2342", 25,"S12","Junior Developer", Date(2022, 3, 15)));
    spouses.push_back(new Spouse("Eve","TK7836", 29, Date(2015, 8, 2)));
    spouses.push_back(new Spouse("Hayden","AC6592", 25, Date(2023, 12, 10)));
    children.push_back(new Child("Tim","RE2318", 1,"Dinosaur"));
    children.push_back(new Child("Layla","RE8212", 3,"Barbie"));
    children.push_back(new Child("Ray","RE4182", 5,"Boomerang"));
    divs.push_back(new Division("Software"));
    divs.push_back(new Division("Hardware"));
    char *txt ="222";
    descs.push_back(new JobDescription(txt));
    txt ="111";
    descs.push_back(new JobDescription(txt));
    emps[0]->setJobDivision(divs[1]);
    emps[0]->addJobDescription(descs[0]);
    emps[1]->setSpouse(spouses[0]);
    for (auto i : children)
    {
        emps[1]->addChild(i);
    }
    emps[1]->setJobDivision(divs[0]);
    emps[1]->addJobDescription(descs[1]);
    emps[2]->setSpouse(spouses[1]);
    emps[2]->setJobDivision(divs[0]);
    emps[2]->addJobDescription(descs[1]);
    for (auto i : emps)
    {
        i->display();
        cout << "______________________________________________________" << endl;
    }
    return 0;
}