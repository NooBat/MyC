#ifndef _BANK_SIMULATION
#define _BANK_SIMULATION

#include<iostream>
#include<vector>
#include "Event.hpp"
#include "/Users/danielnguyen/Repo/C++/Problems/C13/OurPriorityQueue.hpp"
#include "/Users/danielnguyen/Repo/C++/Problems/C13/OurQueue.hpp"

using namespace std;

class BankSimulation
{
private:
    OurQueue<Event>* bankQueue;
    OurPriorityQueue<Event>* eventList;
    int currentTime;
    bool tellerAvailable;


    double totalTransactionTime;
    int numberOfCustomer;
    int maximumLength;
    int totalLength;
    vector<int> lengthHash;

    void processArrival(Event& arrivalEvent);

    void processDeparture(Event& departureEvent);

    void displayEventQueue();

public:
    BankSimulation();

    void simulation(string inputFileName);

    double getAverageTransactionTime() const;

    int getNumberOfCustomer() const;

    int getMaximumLength() const;

    double getAverageLineLength() const;
};

#endif