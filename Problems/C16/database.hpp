#ifndef _DATABASE
#define _DATABASE

#include "/Users/danielnguyen/Repo/C++/ADT/Tree/BinarySearchTree/BinarySearchTree.cpp"
#include "/Users/danielnguyen/Repo/C++/ADT/Tree/BinarySearchTree/BinarySearchTree.hpp"
#include "Person.hpp"
#include "Person.cpp"
#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

class Database
{
private: 
    BinarySearchTree<Person>* database;

protected:
    vector<Person> convertFile();

public:
    Database();
    void start();
    bool add(Person& person);
    bool removePerson(const string& name, const int& day, const int& month, const int& year);
    void show() const;
    void end();
};

#endif