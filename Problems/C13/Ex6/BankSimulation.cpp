#include "BankSimulation.hpp"
#include<fstream>
#include<vector>
#include<iostream>

using namespace std;

void BankSimulation::displayEventQueue()
{
    vector<Event>* temp = new vector<Event>();
    while (!eventList->isEmpty())
    {
        temp->push_back(eventList->peekFront());
        eventList->dequeue();
    }

    cout << "Current event list: " << endl; 
    if (temp->empty()) 
    {
        cout << "No more events." << endl << endl << endl;
        return;
    }

    for (int i = 0; i < temp->size(); i++)
    {
        Event curr = temp->at(i);
        eventList->enqueue(curr);

        cout << curr.getState() << " " << curr.getStartTime() << " " << curr.getProcessTime() << endl;
    }

    delete temp;
    temp = nullptr;

    cout << endl << endl;
}

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
        maximumLength++;
        totalLength++;
        lengthHash.push_back(totalLength);
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

        totalLength--;
        lengthHash.push_back(totalLength);

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
    maximumLength = 0;
    totalLength = 0;
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

        displayEventQueue();

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
    double result = totalTransactionTime / (double)(numberOfCustomer);

    return result;
}

int BankSimulation::getNumberOfCustomer() const
{
    return numberOfCustomer;
}

int BankSimulation::getMaximumLength() const
{
    return maximumLength;
}

double BankSimulation::getAverageLineLength() const
{
    double result = 0;
    for (int i = 0; i < lengthHash.size(); i++)
    {
        result += lengthHash[i];
    } 

    result = result / double(lengthHash.size());

    return result;
}