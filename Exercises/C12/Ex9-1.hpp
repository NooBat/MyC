#include "Ex9.hpp"

class Student : public Person
{
    string schoolName;

public:
    Student();

    Student(const string& name, const int& age, const string& schoolName);

    void setSchoolName(const string& schoolName);

    string getSchoolName() const;

    virtual string display() const;
};

Student::Student() : Person::Person()
{
    this->schoolName = "NONE";
}

Student::Student(const string& name, const int& age, const string& schoolName) : Person::Person(name, age)
{
    this->setSchoolName(schoolName);
}

void Student::setSchoolName(const string& schoolName)
{
    this->schoolName = schoolName;
}

string Student::display() const
{
    string result = Person::display() + "\nThis student goes to " + schoolName;
    return result;
}
