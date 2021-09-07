#ifndef _CITY
#define _CITY

#include "/Users/danielnguyen/Repo/C++/ADT/Node.h"

using namespace std;

class City : public Node<string> {
private:
    bool visited;

public:
    City();

    City(const string& name);

    void markVisited();

    bool isVisited() const;
};

City::City() {
    this->setNext(nullptr);
    this->visited = false;
}

City::City(const string& name) {
    this->setItem(name);
    this->setNext(nullptr);
    this->visited = false;
}

void City::markVisited() {
    this->visited = true;
}

bool City::isVisited() const {
    return this->visited == true;
}

#endif