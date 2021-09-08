#ifndef _FLIGHT_MAP
#define _FLIGHT_MAP

#include<string>
#include<fstream>
#include<utility>
#include<vector>
#include "/Users/danielnguyen/Repo/C++/ADT/Node.h"
#include "/Users/danielnguyen/Repo/C++/ADT/Stack.h"
#include "/Users/danielnguyen/Repo/C++/ADT/LinkedBag.h"
#include "FileReader.h"
#include "City.h"

#define NO_CITY nullptr

using namespace std;

class Map {
private:
    vector<City*> cities; 

    vector<CityList*> flightList;

    unsigned int numberOfCities;

    int findCityIdx(const string& name) const;

public:
    Map();

    void unvisitAll();

    void markCity(City* city);

    City* getNextCity(City* fromCity);

    City* findCity(const string& name) const;

    OurStack<City*>* isPath(int& minimumPrice, City* originCity, City* destinationCity);
};

int Map::findCityIdx(const string& name) const {
    for (int i = 0; i < numberOfCities; i++) {
        if (cities[i]->getName() == name) {
            return i;
        }
    }

    return -1;
}

Map::Map() {
    FileReader city;
    numberOfCities = 0;
    vector<string> cityList = city.getName();

    for (int i = 0; i < cityList.size(); i++) {
        City* newCity = new City(cityList[i]);
        cities.push_back(newCity);

        CityList* head = new CityList();
        head->add(newCity);
        flightList.push_back(head);

        numberOfCities++;
    }

    vector< vector<string> > flightPath = city.getNamePair();

    for (int i = 0; i < flightPath.size(); i++) {
        // addCityList(findCity(flightList[i][0]), flightList[i][1], stoi(flightList[i][2]), stoi(flightList[i][3]));
        int idx = findCityIdx(flightPath[i][0]);

        City* newCity = new City(flightPath[i][1], stoi(flightPath[i][2]), stoi(flightPath[i][3]));
        flightList[idx]->add(newCity);
    }
}

void Map::unvisitAll() {
    for (int i = 0; i < numberOfCities; i++) {
        CityList* p = flightList[i];

        p->unmarkAll();
    }
}

void Map::markCity(City* city) {
    for (int i = 0; i < numberOfCities; i++) {
        Node<City*>* p = flightList[i]->getPtrTo(city->getName());

        if (p != nullptr) p->getItem()->setVisited(true);

        p = nullptr;
    }
}

City* Map::getNextCity(City* fromCity) {
    int idx = findCityIdx(fromCity->getName());
    int id = -1;
    vector<City*> flight = flightList[idx]->toVector();

    int minPrice = flight[0]->getPrice();

    for (int i = 1; i < flight.size(); i++) {
        if (flight[i]->getPrice() < minPrice && !flight[i]->isVisited()) {
            minPrice = flight[i]->getPrice();
            id = i;
        }
    }

    if (id == -1) return NO_CITY;
    return flight[id];
}

City* Map::findCity(const string& name) const {
    for (int i = 0; i < numberOfCities; i++) {
        if (cities[i]->getName() == name) {
            return cities[i];
        }
    }

    return NO_CITY;
}

OurStack<City*>* Map::isPath(int& minimumPrice, City* originCity, City* destinationCity) {
    OurStack<City*>* st = new OurStack<City*>();

    unvisitAll();

    OurStack<City*>* result = new OurStack<City*>();

    markCity(originCity);
    st->push(originCity);

    int price = 0;

    City* topCity = st->peek();

    while (!st->isEmpty() && topCity->getName() != destinationCity->getName()) {
        City* nextCity = getNextCity(topCity);

        if (nextCity == NO_CITY) {
            price -= topCity->getPrice();
            st->pop();
        }
        else {
            markCity(nextCity);
            st->push(nextCity);
            price += nextCity->getPrice();
        }
        if (!st->isEmpty()) topCity = st->peek();
    }

    minimumPrice = price;
    return st;
}

#endif