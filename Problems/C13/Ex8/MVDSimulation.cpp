#include "MVDSimulation.hpp"
#include<iostream>

using namespace std;

MVDSimulation::MVDSimulation()
{
    eventList = new OurPriorityQueue<Event>();
    lrLine = new OurPriorityQueue<Event>();
    rrLine = new OurQueue<Event>();
    siLine = new OurQueue<Event>();
    cLine = new OurQueue<Event>();

    cashier = licenseTeller = registerTeller = signTeller = true;
    numberOfLicense = numberOfRegister = 0.0;
}

void MVDSimulation::processArrival(Event arrival)
{   
    eventList->dequeue();

    cout << "Process an arrival event for " << arrival.getName() << " at " << arrival.getArrivalTime() << endl;

    if (siLine->isEmpty() && signTeller)
    {
        signTeller = false;
        Event nextLine(arrival.getTransaction(), arrival.getMOP(), arrival.getTransaction(), currentTime + arrival.getProcessTime(), 90, arrival.getName(), arrival.getApproved());
        eventList->enqueue(nextLine);
    }
    else
    {
        Event signIn(arrival.getTransaction(), arrival.getMOP(), "S", currentTime, 10, arrival.getName(), arrival.getApproved());
        siLine->enqueue(arrival);
    }
}

void MVDSimulation::processSignIn(Event SignIn)
{
    eventList->dequeue();

    cout << "Process a sign in event for " << SignIn.getName() << " at " << SignIn.getArrivalTime() << endl;
}