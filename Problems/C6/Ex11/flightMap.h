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
    vector<City*> ptr;

    unsigned int numberOfCities;

    void addCityList(City* fromCity, const string& newCity, const int& flightName, const int& price);

public:
    Map();

    void unvisitAll();

    void markCity(City* city);

    City* getNextCity(City* fromCity);

    City* findCity(const string& name) const;

    int getPrice(City* origin, City* destination) const;

    int getFlightName(City* origin, City* destination) const;

    OurStack<City*> isPath(int& minimumPrice, City* originCity, City* destinationCity);
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
        ptr.push_back(A);
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
        
        p = nullptr;

        ptr[i] = cities[i];
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
    }
}

City* Map::getNextCity(City* fromCity) {
    int i;
    for (i = 0; i < numberOfCities; i++) {
        if (fromCity->getName() == cities[i]->getName()) break;
    }

    ptr[i] = ptr[i]->getNext();

    return ptr[i];
}

City* Map::findCity(const string& name) const {
    for (int i = 0; i < numberOfCities; i++) {
        if (cities[i]->getName() == name) return cities[i];
    }

    return NO_CITY;
}

int Map::getPrice(City* origin, City* destination) const {
    City* curr = findCity(origin->getName());

    while (curr != nullptr) {
        if (curr->getName() == destination->getName()) return curr->getPrice();
        curr = curr->getNext();
    }

    return 0;
}

int Map::getFlightName(City* origin, City* destination) const {
    City* curr = findCity(origin->getName());

    while (curr != nullptr) {
        if (curr->getName() == destination->getName()) return curr->getFlightName();
        curr = curr->getNext();
    }

    return 0;
}

OurStack<City*> Map::isPath(int& minimumPrice, City* originCity, City* destinationCity) {
    OurStack<City*> st;

    unvisitAll();

    OurStack<City*> result;

    st.push(originCity);
    markCity(originCity);

    City* topCity = st.peek();
    while (true) {
        int price = 0;
        while (!st.isEmpty() && topCity->getName() != destinationCity->getName()) {
            City* nextCity = getNextCity(topCity);

            if (nextCity == NO_CITY) {
                price -= topCity->getPrice();
                st.pop();
            }
            else {
                st.push(nextCity);
                price += nextCity->getPrice();
                markCity(nextCity);
            }
            if (!st.isEmpty()) topCity = st.peek();
        }

        if (!st.isEmpty()) {
            if (price < minimumPrice) {
                result.clear();
                minimumPrice = price;
                vector<City*> v = st.traverse();

                for (int i = 0; i < v.size(); i++) {
                    result.push(v[i]); 
                }
            }
            st.clear();
            st.push(originCity);
        }
        else break;
    }
    return result;
}

#endif