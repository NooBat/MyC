#include "Person.hpp"

Person::Person(const string& name, const int& day, const int& month, const int& year)
{
    this->name = name;
    this->day = day;
    this->month = month;
    this->year = year;
}

void Person::setName(const string& name)
{
    this->name = name;
}

string Person::getName() const
{
    return name;
}

void Person::setDOB(const int& day, const int& month, const int& year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

int Person::getDay() const
{
    return day;
}

int Person::getMonth() const
{
    return month;
}

int Person::getYear() const
{
    return year;
}

bool Person::operator>(const Person& rightHandSide) const
{
    if (this->name > rightHandSide.name) return true;
    else if (this->name == rightHandSide.name) 
    {
        if (this->year < rightHandSide.year) return true;
        else if (this->year == rightHandSide.year) 
        {
            if (this->month < rightHandSide.month) return true;
            else if (this->month == rightHandSide.month) 
            {
                if (this->day < rightHandSide.day) return true;
            }
        }
    }
    return false;
}

bool Person::operator==(const Person& rightHandSide) const
{
    if (rightHandSide.name == this->name && rightHandSide.day == this->day && rightHandSide.month == this->month && rightHandSide.year == this->year) return true;

    return false;
}