#ifndef PERSON_ADT
#define PERSON_ADT

#include<string>
using namespace std;

class Person
{
private:
    string name;
    int age;

public:
    Person();

    Person(const string& name, const int& age);

    virtual void setName(const string& name);

    virtual void setAge(const int& age);

    virtual string getName() const;

    virtual int getAge() const;

    void display() const;
};

Person::Person()
{
    
}

#endif