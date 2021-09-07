#include "FileReader.h"
#include "flightMap.h"
#include<iostream>

using namespace std;

int main() {
    string filename = "/Users/danielnguyen/Repo/C++/Problems/C6/Ex11/requestFile.txt";

    Map flightHPAir;

    ifstream myfile(filename);

    if (myfile.is_open()) {
        string temp;
        while (getline(myfile, temp)) {
            int i;
            for (i = 0; i < temp.length(); i++) {
                if (temp[i] == ',') break;
            }

            string first = temp.substr(0, i);
            string second = temp.substr(i + 2, temp.length() - first.length() - 2);

            City *origin = flightHPAir.findCity(first);
            City *destination = flightHPAir.findCity(second);

            cout << "Request fly from " << first << " to " << second << endl;
            if (origin == NO_CITY) {
                cout << "Sorry. The HPAir does not serve " << first << endl;
                cout << endl << endl;
                continue;
            }
            if (destination == NO_CITY) {
                cout << "Sorry. The HPAir does not serve " << second << endl;
                cout << endl << endl;
                continue;
            }

            OurStack<City*> st;
            if (flightHPAir.isPath(origin, destination)) {
                cout << "HPAir flies from " << first << " to " << second << endl;
            }
            else {
                cout << "Sorry. HPair does not fly from " << first << " to " << second << endl;
            }
            cout << endl << endl;
        }
    }
}