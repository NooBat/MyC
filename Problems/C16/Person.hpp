#ifndef _PERSON
#define _PERSON

#include<string>

using namespace std;

class Person
{
private:
    string name;
    int day; 
    int month; 
    int year;

public:
    Person();
    Person(const string& name, const int& day, const int& month, const int& year);

    void setName(const string& name);
    string getName() const;
    void setDOB(const int& day, const int& month, const int& year);
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    bool operator>(const Person& rightHandSide) const;
    bool operator<(const Person& rightHandSide) const;
    bool operator==(const Person& rightHandSide) const;
};

#endif