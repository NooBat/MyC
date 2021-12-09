#include "database.cpp"
#include "database.hpp"
#include<iostream>

using namespace std;

int main()
{
    Database data;

    data.start();

    data.show();
    cout << endl << endl;
    // Person people[] = {Person("Adam", 24, 12, 2000), Person("John", 27, 1, 2003), 
    //                    Person("Bert", 10, 7, 2002), Person("Adam", 25, 12, 2003),
    //                    Person("Jacinta", 21, 11, 2003), Person("Luke", 21, 11, 2003)};

    // for (int i = 0; i < 6; i++) 
    // {
    //     data.add(people[i]);
    // }

    data.show();

    data.end();
    return 0;
}