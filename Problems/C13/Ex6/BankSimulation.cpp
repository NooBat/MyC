#include "BankSimulation.hpp"
#include<fstream>
#include<iostream>

void BankSimulation::processArrival(Event& arrivalEvent)
{
    eventList->dequeue();

    cout << "Processing a arrival event at time:\t" << arrivalEvent.getStartTime() << endl;

    if (bankQueue->isEmpty() && tellerAvailable)
    {
        Event newDepartureEvent('D', currentTime + arrivalEvent.getProcessTime());
        eventList->enqueue(newDepartureEvent);
        tellerAvailable = false;
    }
    else 
    {
        bankQueue->enqueue(arrivalEvent);
    }
}

void BankSimulation::processDeparture(Event& departureEvent)
{
    eventList->dequeue();

    cout << "Processing a departure event at time:\t" << departureEvent.getStartTime() << endl;

    if (!bankQueue->isEmpty())
    {
        Event nextEvent = bankQueue->peekFront();
        totalTransactionTime += currentTime - nextEvent.getStartTime();
        bankQueue->dequeue();
        Event newDepartureEvent('D', currentTime + nextEvent.getProcessTime());
        eventList->enqueue(newDepartureEvent);
    }
    else tellerAvailable = true;
}

BankSimulation::BankSimulation()
{
    bankQueue = new OurQueue<Event>();
    eventList = new OurPriorityQueue<Event>();
    currentTime = 0;
    tellerAvailable = true;
    totalTransactionTime = 0;
    numberOfCustomer = 0;
}

void BankSimulation::simulation(string inputFileName)
{
    ifstream myfile(inputFileName);

    string instruction;
    if (myfile.is_open())
    {
        while (getline(myfile, instruction))
        {
            int arr[2];
            string time;
            int idx = 0;
            bool flag = true;
            for (int i = 0; i < instruction.length(); i++)
            {
                if (instruction[i] != ' ') 
                {
                    flag = true;
                    time.push_back(instruction[i]);
                }
                else if (instruction[i] == ' ' && flag)
                {
                    flag = false;
                    arr[idx] = stoi(time);
                    idx++;
                    time.clear();
                }
            }
            arr[idx] = stoi(time);
            Event newArrivalEvent('A', arr[0], arr[1]);
            eventList->enqueue(newArrivalEvent);
            numberOfCustomer++;
        }
    }


    while (!eventList->isEmpty())
    {
        Event newEvent = eventList->peekFront();

        currentTime = newEvent.getStartTime();

        if (newEvent.getState() == 'A')
        {
            processArrival(newEvent);
        }
        else 
        {
            processDeparture(newEvent);
        }
    }
}

double BankSimulation::getAverageTransactionTime() const
{
    double result = totalTransactionTime / (double)(numberOfCustomer - 1);

    return result;
}

int BankSimulation::getNumberOfCustomer() const
{
    return numberOfCustomer;
}