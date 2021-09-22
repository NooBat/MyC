#ifndef _PERSON
#define _PERSON

#include<iostream>
#include<string>

using namespace std;

class Person {
private:
    string name;
    int turn;
    Person* next;
    static int numberOfPeople;

public:
    Person();

    Person(const string& name);

    void setName(const string& name);

    void setNext(Person* next);

    string getName() const;

    int getTurn() const;

    Person* getNext() const;
};

Person::Person(): name(""), turn(0), next(nullptr) {
    numberOfPeople++;
}

Person::Person(const string& name) {
    this->setName(name);
    this->setAge(0);
    this->setNext(nullptr);
    numberOfPeople++;
}

void Person::setName(const string& name) {
    this->name = name;
}

void Person::setNext(Person* next) {
    this->next = next;
}

string Person::getName() const {
    return name;
}

int Person::getTurn() const {
    return turn;
}

Person* Person::getNext() const {
    return this->next;
}
#endif