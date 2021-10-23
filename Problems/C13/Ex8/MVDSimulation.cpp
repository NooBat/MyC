#include "MVDSimulation.hpp"
#include<iostream>
#include<fstream>
using namespace std;

MVDSimulation::MVDSimulation()
{
    eventList = new OurPriorityQueue<Event, less<Event> >();
    lrLine = new OurPriorityQueue<Event, decltype(comparator)>();
    rrLine = new OurQueue<Event>();
    siLine = new OurQueue<Event>();
    cLine = new OurQueue<Event>();

    cashier = licenseTeller = registerTeller = signTeller = true;
    numberOfLicense = numberOfRegister = 0.0;
}

void MVDSimulation::processArrival(Event arrival)
{   
    eventList->dequeue();

    cout << "Process an arrival event for " << arrival.getName() << " at " << arrival.getStartTime() << endl << endl;

    if (siLine->isEmpty() && signTeller)
    {
        signTeller = false;
        Event nextEvent(arrival.getTransaction(), arrival.getMOP(), arrival.getTransaction(), currentTime + 10, 90, arrival.getName(), arrival.getApproved(), arrival.getTotalTime());
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

    cout << "Process a sign in event for " << SignIn.getName() << " at " << SignIn.getStartTime();

    if (!siLine->isEmpty())
    {
        Event nextCustomer = siLine->peekFront();
        nextCustomer.setTotalTime(nextCustomer.getTotalTime() + currentTime - nextCustomer.getStartTime());
        siLine->dequeue();

        if (nextCustomer.getState() == "L")
        {
            if (lrLine->isEmpty() && licenseTeller)
            {
                licenseTeller = false;
                Event nextLine(nextCustomer.getTransaction(), nextCustomer.getMOP(), "CC", nextCustomer.getProcessTime() + currentTime, 90, nextCustomer.getName(), nextCustomer.getTotalTime(), nextCustomer.getApproved());
                eventList->enqueue(nextLine);
            }
            else
            {
                Event licenseRenewal(nextCustomer.getTransaction(), nextCustomer.getMOP(), "L", nextCustomer.getProcessTime() + currentTime, 90, nextCustomer.getName(), nextCustomer.getTotalTime(), nextCustomer.getApproved());
                lrLine->enqueue(licenseRenewal);
            }
            cout << " to license renewal line." << endl << endl;
        }
        else if (nextCustomer.getState() == "R")
        {
            if (rrLine->isEmpty() && registerTeller)
            {
                registerTeller = false;
                Event nextLine(nextCustomer.getTransaction(), nextCustomer.getMOP(), "CC", nextCustomer.getProcessTime() + currentTime, 60, nextCustomer.getName(), nextCustomer.getTotalTime(), nextCustomer.getApproved());
                eventList->enqueue(nextLine);
            }
            else
            {
                Event registrationRenewal(nextCustomer.getTransaction(), nextCustomer.getMOP(), "R", nextCustomer.getProcessTime() + currentTime, 60, nextCustomer.getName(), nextCustomer.getTotalTime(), nextCustomer.getApproved());
                rrLine->enqueue(registrationRenewal);
            }
            cout << " to registration renewal line." << endl << endl;
        }
    }
    else signTeller = true;
}

void MVDSimulation::processLicenseRenewal(Event license)
{
    eventList->dequeue();

    cout << "Process a license renewal for " << license.getName() << " at " << license.getStartTime();

    if (!lrLine->isEmpty())
    {
        Event nextCustomer = lrLine->peekFront();
        lrLine->dequeue();
        nextCustomer.setTotalTime(nextCustomer.getTotalTime() + currentTime - nextCustomer.getStartTime());

        if (nextCustomer.getMOP() == "$")
        {
            if (cLine->isEmpty() && cashier)
            {
                cashier = false;
                Event nextEvent(nextCustomer.getTransaction(), nextCustomer.getMOP(), "D", nextCustomer.getProcessTime() + currentTime, 30, nextCustomer.getName(), nextCustomer.getTotalTime(), nextCustomer.getApproved());
                eventList->enqueue(nextEvent);  
            }
            else
            {
                Event nextEvent(nextCustomer.getTransaction(), nextCustomer.getMOP(), "D", nextCustomer.getProcessTime() + currentTime, 30, nextCustomer.getName(), nextCustomer.getTotalTime(), nextCustomer.getApproved());
            }
        }
    }
}

void MVDSimulation::processRegistrationRenewal(Event registration)
{

}

void MVDSimulation::processCashierLine(Event c)
{

}

void MVDSimulation::processDeparture(Event departure)
{
    
}

void MVDSimulation::simulation()
{
    ifstream myfile("/Users/danielnguyen/Repo/C++/Problems/C13/Ex8/input.txt");
    string instruction;
    if (myfile.is_open())
    {
        while (getline(myfile, instruction))
        {
            string arr[4];
            string temp;
            int idx = 0;
            int i = 0;

            do
            {
                if (instruction[i] == ' ' || !instruction[i])
                {
                    i++;
                    arr[idx++] = temp;
                    temp.clear();
                }
                else
                {
                    temp.push_back(instruction[i++]);
                }
            } while (i <= instruction.length());
            
            if (arr[0] == "L") numberOfLicense++;
            else numberOfRegister++;

            Event arrivalEvent(arr[0], arr[1], "A", stoi(arr[2]), 0, arr[3], 0);
            if (arrivalEvent.getMOP() == "C") 
            {
                arrivalEvent.setApproved(false);
            }
            eventList->enqueue(arrivalEvent);
        }
    }

    while (!eventList->isEmpty())
    {
        Event newEvent = eventList->peekFront();
        string state = newEvent.getState();
        currentTime = newEvent.getStartTime();
        if (state == "A")
        {
            processArrival(newEvent);
        }
        else if (state == "S")
        {
            processSignIn(newEvent);
        }
        else if (state == "L")
        {
            processLicenseRenewal(newEvent);
        }
        else if (state == "R")
        {
            processRegistrationRenewal(newEvent);
        }
        else if (state == "CC")
        {
            processCashierLine(newEvent);
        }
        else processDeparture(newEvent);
    }
}