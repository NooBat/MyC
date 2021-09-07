#ifndef _FLIGHT_MAP
#define _FLIGHT_MAP

#include<string>
#include<fstream>
#include<utility>
#include<vector>
#include "/Users/danielnguyen/Repo/C++/ADT/Node.h"
#include "/Users/danielnguyen/Repo/C++/ADT/Stack.h"
#include "FileReader.h"
#include "City.h"

#define NO_CITY nullptr

using namespace std;

class Map {
private:
    vector<City*> cities;

    unsigned int numberOfCities;

    void addCityList(City* fromCity, const string& newCity, const int& flightName, const int& price);

public:
    Map();

    void unvisitAll();

    void markCity(City* city);

    City* getNextCity(City* fromCity);

    City* findCity(const string& name) const;

    OurStack<City*>* isPath(int& minimumPrice, City* originCity, City* destinationCity);
};

void Map::addCityList(City* fromCity, const string& newCity, const int& flightName, const int& price) {
    for (int i = 0; i < numberOfCities; i++) {
        if (fromCity->getName() == cities[i]->getName()) {
            City* p = cities[i];

            City* temp = new City(newCity);
            temp->setPrice(price);
            temp->setFlightName(flightName);

            while (p->getNext() != nullptr) {
                p = p->getNext();
            }

            p->setNext(temp);
            break;
        }
    }
}

Map::Map() {
    FileReader city;
    numberOfCities = 0;
    vector<string> cityList = city.getName();

    for (int i = 0; i < cityList.size(); i++) {
        City* A = new City(cityList[i]);
        cities.push_back(A);
        numberOfCities++;
    }

    vector< vector<string> > flightList = city.getNamePair();

    for (int i = 0; i < flightList.size(); i++) {
        addCityList(findCity(flightList[i][0]), flightList[i][1], stoi(flightList[i][2]), stoi(flightList[i][3]));
    }
}

void Map::unvisitAll() {
    for (int i = 0; i < numberOfCities; i++) {
        City* p = cities[i];

        while (p != nullptr) {
            p->setVisitState(false);
            p = p->getNext();
        }
    }
}

void Map::markCity(City* city) {
    for (int i = 0; i < numberOfCities; i++) {
        City* p = cities[i];

        while (p != nullptr) {
            if (p->getName() == city->getName()) {
                p->markVisited();
                break;
            }
            p = p->getNext();
        }

        p = nullptr;
    }
}

City* Map::getNextCity(City* fromCity) {
    for (i = 0; i < numberOfCities; i++) {
        if (fromCity->getName() == cities[i]->getName()) {
            City* curr = cities[i];

            while (curr != nullptr) {
                if (!curr->isVisited()) {
                    City* newCity = new City(curr->getName());
                    newCity->setFlightName(curr->getFlightName());
                    newCity->setPrice(curr->getPrice());
                    newCity->setVisitState(false);

                    return newCity;
                }

                curr = curr->getNext();
            }
        }
    }

    return NO_CITY;
}

City* Map::findCity(const string& name) const {
    for (int i = 0; i < numberOfCities; i++) {
        if (cities[i]->getName() == name) {
            City* newCity = new City(name);
            newCity->setPrice(0);
            
            return newCity;
        }
    }

    return NO_CITY;
}

OurStack<City*>* Map::isPath(int& minimumPrice, City* originCity, City* destinationCity) {
    OurStack<City*>* st = new OurStack<City*>();

    unvisitAll();

    OurStack<City*>* result = new OurStack<City*>();

    City* dest = nullptr;

    markCity(originCity);
    st->push(originCity);

    int price = 0;


    City* topCity = st->peek();

    while (!st->isEmpty() && topCity->getName() != destinationCity->getName()) {
        City* nextCity = getNextCity(topCity);

        if (nextCity->getName() == destinationCity->getName()) {
            dest = nextCity;
            int temp = price + nextCity->getPrice();
            if (temp < minimumPrice) {
                if (!result->isEmpty()) result->clear();
                minimumPrice = temp;
                vector<City*> v = st->traverse();

                for (int i = 0; i < v.size(); i++) {
                    result->push(v[i]); 
                }
            }
            while (!st->isEmpty()) {
                City* nextCity = getNextCity(st->peek());

                if (nextCity == NO_CITY) {
                    price -= st->peek()->getPrice();
                    st->pop();
                }
                else if (nextCity->getName() == destinationCity->getName()) {
                    
                }
                else {
                    st->push(nextCity);
                    price += st->peek()->getPrice();
                    topCity = st->peek();
                    break;
                }
            }
            if (st->isEmpty()) break;

        }

        if (nextCity == NO_CITY) {
            price -= topCity->getPrice();
            st->pop();
        }
        else {
            st->push(nextCity);
            price += nextCity->getPrice();
            markCity(nextCity);
        }
        if (!st->isEmpty()) topCity = st->peek();
    }

    if (dest != nullptr) result->push(dest);

    return result;
}

#endif