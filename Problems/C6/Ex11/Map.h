#ifndef _FLIGHT_MAP
#define _FLIGHT_MAP

#include<string>
#include<fstream>
#include<stack>
#include<utility>
#include<vector>
#include "/Users/danielnguyen/Repo/C++/ADT/Node.h"
#include "FileReader.h"
#include "City.h"

#define NO_CITY

using namespace std;

class Map {
private:
    vector<City*> cities;

    unsigned int numberOfCities;

public:
    Map();

    Map(const string& cityList, const string& flightFile);

    void unvisitAll();

    City* getNextCity(City* fromCity) const;

    bool isPath(City* originCity, City* destinationCity);
};

Map::Map() {
    numberOfCities = 0;
}

Map::Map(const string& cityList, const string& flightFile) {
    FileReader city(cityList);

    vector<string> cityName = city.getName();

    for (int i = 0; i < cityName.size(); i++) {
        City* A = new City(cityName[i]);
        cities.push_back(A);
        numberOfCities++;
    }
}

#endif