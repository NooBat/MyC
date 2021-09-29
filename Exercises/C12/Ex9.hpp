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

    virtual string display() const;
};

Person::Person()
{
    this->name = "NONE";
    this->age = 0;    
}

Person::Person(const string& name, const int& age)
{
    this->setName(name);
    this->setAge(age);
}

void Person::setName(const string& name)
{
    string correctNameGrammar;
    for (int i = 0; i < name.length(); i++)
    {
        correctNameGrammar.push_back(name[i]);
        correctNameGrammar[i] = toupper(correctNameGrammar[i]);
    }

    for (int i = 1; i < name.length(); i++)
    {
        correctNameGrammar[i] = tolower(correctNameGrammar[i]);
    }

    this->name = correctNameGrammar;
}

void Person::setAge(const int& age)
{
    if (age < 0) this->age = 0;
    else this->age = age;
}

string Person::getName() const
{
    return name;
}

int Person::getAge() const
{
    return age;
}

string Person::display() const
{
    string result = "This person's name is " + name + "\nAge is: " + to_string(age);
    return result;
}

#endif