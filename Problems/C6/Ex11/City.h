#ifndef _CITY
#define _CITY

#include "/Users/danielnguyen/Repo/C++/ADT/Node.h"

using namespace std;

class City {
private:
    string name;
    City* next;
    bool visited;
public:
    City();

    City(const string& name);

    void setVisitState(bool result);

    void setName(const string& name);

    void setNext(City *next);

    void markVisited();

    string getName() const;

    City* getNext() const;

    bool isVisited() const;
};

void City::setVisitState(bool result) {
    this->visited = result;
}

City::City() {
    this->setNext(nullptr);
    this->visited = false;
}

City::City(const string& name) {
    this->setName(name);
    this->setNext(nullptr);
    this->visited = false;
}

void City::setName(const string& name) {
    this->name = name;
}

void City::setNext(City* next) {
    this->next = next;
}

void City::markVisited() {
    this->visited = true;
}

string City::getName() const {
    return name;
}

City* City::getNext() const {
    return next;
}

bool City::isVisited() const {
    return this->visited == true;
}

#endif