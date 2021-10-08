#ifndef _BANK_SIMULATION
#define _BANK_SIMULATION

#include<iostream>
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

    void processArrival(Event& arrivalEvent);

    void processDeparture(Event& departureEvent);

public:
    BankSimulation();

    void simulation(string inputFileName);

    double getAverageTransactionTime() const;

    int getNumberOfCustomer() const;
};

#endif