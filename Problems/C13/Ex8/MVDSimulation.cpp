#include "MVDSimulation.hpp"
#include<iostream>

using namespace std;

MVDSimulation::MVDSimulation()
{
    eventList = new OurPriorityQueue<Event, greater<Event> >();
    lrLine = new OurPriorityQueue<Event, decltype(&comparator)>();
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
        Event nextEvent(arrival.getTransaction(), arrival.getMOP(), arrival.getTransaction(), currentTime + arrival.getProcessTime(), 90, arrival.getName(), arrival.getApproved(), arrival.getTotalTime());
        if (nextEvent.getTransaction() == "R") nextEvent.setProcessTime(60.0);
        eventList->enqueue(nextEvent);
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
    if (!siLine->isEmpty())
    {
        Event nextEvent = siLine->peekFront();
        nextEvent.setTotalTime(nextEvent.getTotalTime() + currentTime - nextEvent.getArrivalTime());
        siLine->dequeue();

    }
        if (SignIn.getState() == "L")
        {
            if (lrLine->isEmpty() && licenseTeller)
            {
                licenseTeller = false;
                Event nextLine(SignIn.getTransaction(), SignIn.getMOP(), "CC", SignIn.getProcessTime() + currentTime, 90, SignIn.getName(), SignIn.getTotalTime(), SignIn.getApproved());
                eventList->enqueue(nextLine);
            }
            else
            {
                // Event licenseRenewal(SignIn.getTransaction(), SignIn.getMOP(), "L", )
            }
        }
}