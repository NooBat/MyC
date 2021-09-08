#ifndef _CITY
#define _CITY

#include "/Users/danielnguyen/Repo/C++/ADT/Node.h"
#include<vector>

using namespace std;

class City {
private:
    string name;
    int flightName;
    int price;
    bool visited;

public:
    City();

    City(const string& name);

    City(const string& name, const int& price);

    City(const string& name, const int& price, const int& flightName);

    void setName(const string& name);

    void setPrice(const int& price);

    void setFlightName(const int& flightName);

    void setVisited(const bool& visited);

    string getName() const;

    int getPrice() const;

    int getFlightName() const;

    bool isVisited() const;
};

City::City() {
    this->setPrice(INT_MAX);
    this->setVisited(false);
}

City::City(const string& name) {
    this->setName(name);
    this->setPrice(INT_MAX);
    this->setVisited(false);
}

City::City(const string& name, const int& price) {
    this->setName(name);
    this->setVisited(false);
    this->setPrice(price);
}

City::City(const string& name, const int& price, const int& flightName) {
    this->setName(name);
    this->setVisited(false);
    this->setPrice(price);
    this->setFlightName(flightName);
}

void City::setName(const string& name) {
    this->name = name;
}

void City::setPrice(const int& price) {
    this->price = price;
}

void City::setFlightName(const int& flightName) {
    this->flightName = flightName;
}

void City::setVisited(const bool& visited) {
    this->visited = visited;
}

string City::getName() const {
    return name;
}

int City::getPrice() const {
    return price;
}

int City::getFlightName() const {
    return flightName;
}

bool City::isVisited() const {
    return this->visited == true;
}







class CityList {
private:
    Node<City*>* headPtr;

public:
    CityList();

    virtual ~CityList();

    bool add(City* newCity);

    void clear();

    void unmarkAll(); 

    Node<City*>* getPtrTo(const string& name);

    vector<City*> toVector() const;
};

CityList::CityList() {
    headPtr = nullptr;
}

CityList::~CityList() {
    clear();
}

bool CityList::add(City* newCity) {
    if (headPtr == nullptr) {
        Node<City*>* temp = new Node<City*>(newCity);
        headPtr = temp;
        temp = nullptr;
        return true;
    }

    Node<City*>* temp = new Node<City*>(newCity);

    Node<City*>* curr = headPtr;

    while (curr->getNext() != nullptr) {
        curr = curr->getNext();
    }

    curr->setNext(temp);

    //delete pointers
    curr = nullptr;
    temp = nullptr;

    return true;
}

void CityList::clear() {
    if (headPtr == nullptr) return;

    Node<City*>* curr = headPtr;

    while (curr != nullptr) {
        Node<City*>* next = curr->getNext();

        delete curr;

        curr = next;
    }

    headPtr = nullptr;
}

void CityList::unmarkAll() {
    if (headPtr == nullptr) return;

    Node<City*>* curr = headPtr;

    while (curr != nullptr) {
        curr->getItem()->setVisited(false);
        curr = curr->getNext();
    }
}

Node<City*>* CityList::getPtrTo(const string& name) {
    if (headPtr == nullptr) return nullptr;

    Node<City*>* curr = headPtr;

    while (curr != nullptr) {
        if (curr->getItem()->getName() == name) {
            return curr;
        }
    }

    return nullptr;
}

vector<City*> CityList::toVector() const {
    vector<City*> result;

    Node<City*>* curr = headPtr;

    while (curr != nullptr) {
        result.push_back(curr->getItem());
        curr = curr->getNext();
    }

    return result;
}
#endif