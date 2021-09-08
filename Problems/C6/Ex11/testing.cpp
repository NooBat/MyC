#include "FileReader.h"
#include "flightMap.h"
#include<iostream>
#include<iomanip>

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

            City* origin = flightHPAir.findCity(first);
            City* destination = flightHPAir.findCity(second);

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

            int totalPrice = INT_MAX;
            OurStack<City*>* st = flightHPAir.isPath(totalPrice, origin, destination);
            if (!st->isEmpty()) {
                cout << "HPAir flies from " << first << " to " << second << endl;
                vector<City*> v = st->traverse();

                for (i = 0; i < v.size() - 1; i++) {
                    cout << "Flight #" << v[i + 1]->getFlightName() << " from " << v[i]->getName() 
                         << " to " << v[i + 1]->getName() << "\t\t\t\t" << "Cost: $" 
                         << v[i + 1]->getPrice() << endl;
                }

                cout << "Total cost ............. $" << totalPrice << endl;
            }
            else {
                cout << "Sorry. HPair does not fly from " << first << " to " << second << endl;
            }
            cout << endl << endl;
        }
    }
}