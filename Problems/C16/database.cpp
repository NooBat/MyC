#ifndef _IMPLEMENT_DATABASE
#define _IMPLEMENT_DATABASE

#include "database.hpp"
#include<sstream>
#include<vector>

void visit(Person& a)
{
    cout << a.getName() << " " << a.getDay() << " " << a.getMonth() << " " << a.getYear() << endl;
}

vector<Person> Database::convertFile()
{
    string filename = "/Users/danielnguyen/Repo/C++/Problems/C16/data.txt";

    ifstream myfile(filename);
    vector<Person> people;

    if (myfile.is_open()) 
    {
        string data;
        while (getline(myfile, data))
        {
            istringstream str(data);

            string word[4];

            for (int i = 0; i < 4; i++)
            {
                str >> word[i];
            }

            people.push_back(Person(word[0], stoi(word[1]), stoi(word[2]), stoi(word[3])));
        }
    }

    return people;
}

Database::Database()
{
    database = new BinarySearchTree<Person>();
}

void Database::start() 
{
    vector<Person> people = convertFile();

    int size = people.size();

    Person arr[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = people[i];
    }

    database->readTree(arr, size);
}

bool Database::add(Person& person)
{
    return database->add(person);
}

bool Database::removePerson(const string& name, const int& day, const int& month, const int& year)
{
    return database->remove(Person(name, day, month, year));
}

void Database::show() const 
{
    database->inorderTraverse(visit);
}

void Database::end()
{
    FILE* fp = freopen("data.txt", "w", stdout);

    database->inorderTraverse(visit);

    database->clear();
    fclose(fp);
}

#endif