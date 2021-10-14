#ifndef _BANK_SIMULATION
#define _BANK_SIMULATION

#include<iostream>
#include<vector>
#include<fstream>
#include "/Users/danielnguyen/Repo/C++/Problems/C13/Ex6/Event.hpp"
#include "/Users/danielnguyen/Repo/C++/Problems/C13/OurPriorityQueue.hpp"
#include "/Users/danielnguyen/Repo/C++/Problems/C13/OurQueue.hpp"

using namespace std;

class BankSimulation
{
private:
    int numberOfTeller;
    int numberOfQueue;
    OurQueue<Event>* bankQueue;                 //for 3 distinct lines
    OurPriorityQueue<Event>* eventList;         //for all event
    int currentTime;
    bool* tellerAvailable;


    double totalWaitTime;
    int numberOfCustomer;
    int maximumLength;
    vector<int> queueLength;
    vector< vector<int> >* lengthHash;

    void processArrival(Event& arrivalEvent);

    void processDeparture(Event& departureEvent);

    void displayEventQueue();

    int getShortestLine() const;

    int getFirstFree() const;

public:
    BankSimulation();

    BankSimulation(const int& numberOfTeller, const int& numberOfQueue);

    void simulation(string inputFileName);

    double getAverageWaitTime() const;

    int getNumberOfCustomer() const;

    int getMaximumLength() const;

    double getAverageLineLength() const;
};

#endif