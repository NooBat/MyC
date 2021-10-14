#include "BankSimulation2.hpp"

using namespace std;

int BankSimulation::getFirstFree() const
{
    int firstFree = -1;
    for (int i = 0; i < numberOfTeller; i++)
    {
        if (tellerAvailable[i]) 
        {
            firstFree = i;
            break;
        }
    }   

    return firstFree;
}

int BankSimulation::getShortestLine() const
{
    int shortestIdx = 0;
    for (int i = 1; i < numberOfQueue; i++)
    {
        if (queueLength[i] < queueLength[shortestIdx])
        {
            shortestIdx = i;
        }
    }

    return shortestIdx;
}

void BankSimulation::processArrival(Event& arrivalEvent)
{
    int minLengthIdx = getShortestLine();
    int firstFreeIdx = getFirstFree();

    cout << "Processing an arrival event at:\t" << arrivalEvent.getStartTime() << " " 
         << "\nIn line: " << minLengthIdx + 1 << endl << endl;
    eventList->dequeue();

    if (bankQueue[minLengthIdx].isEmpty() && firstFreeIdx != -1)
    {
        tellerAvailable[firstFreeIdx] = false;
        Event newDepartureEvent('D', currentTime + arrivalEvent.getProcessTime(), 0, minLengthIdx, firstFreeIdx);
        eventList->enqueue(newDepartureEvent);
    }
    else 
    {
        bankQueue[minLengthIdx].enqueue(arrivalEvent);
        queueLength[minLengthIdx]++;
        maximumLength = max(queueLength[minLengthIdx], maximumLength);
        lengthHash->push_back(queueLength);
    }
}

void BankSimulation::processDeparture(Event& departureEvent)
{
    eventList->dequeue();

    int lineIdx = departureEvent.getFromLine();
    int tellerIdx = departureEvent.getFromTeller();

    cout << "Processing a departure event at:\t" << departureEvent.getStartTime() 
        << "\nAt teller: " << tellerIdx + 1 << endl << endl;

    if (!bankQueue[lineIdx].isEmpty())
    {
        Event newCustomer = bankQueue[lineIdx].peekFront();

        totalWaitTime += currentTime - newCustomer.getStartTime();

        bankQueue[lineIdx].dequeue();

        queueLength[lineIdx]--;
        lengthHash->push_back(queueLength);

        Event newDepartureEvent('D', currentTime + newCustomer.getProcessTime(), 0, lineIdx, tellerIdx);
        eventList->enqueue(newDepartureEvent);
    }
    else tellerAvailable[tellerIdx] = true;
}

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

BankSimulation::BankSimulation()
{
    numberOfQueue = 1;
    numberOfTeller = 1;
    tellerAvailable = new bool[numberOfTeller];
    bankQueue = new OurQueue<Event>[numberOfQueue];
    eventList = new OurPriorityQueue<Event>();
    currentTime = 0;
    totalWaitTime = 0.0;
    numberOfCustomer = 0;
    maximumLength = 0;
    
    for (int i = 0; i < numberOfTeller; i++)
    {
        tellerAvailable[i] = true;
    }

    for (int i = 0; i < numberOfQueue; i++)
    {
        queueLength.push_back(0);
    }

    lengthHash = new vector< vector<int> >();
}

BankSimulation::BankSimulation(const int& numberOfTeller, const int& numberOfQueue)
{
    this->numberOfQueue = numberOfQueue;
    this->numberOfTeller = numberOfTeller;
    tellerAvailable = new bool[numberOfTeller];
    bankQueue = new OurQueue<Event>[numberOfQueue];
    eventList = new OurPriorityQueue<Event>();
    currentTime = 0;
    totalWaitTime = 0.0;
    numberOfCustomer = 0;
    maximumLength = 0;
    
    for (int i = 0; i < numberOfTeller; i++)
    {
        tellerAvailable[i] = true;
    }

    for (int i = 0; i < numberOfQueue; i++)
    {
        queueLength.push_back(0);
    }

    lengthHash = new vector< vector<int> >();
}

void BankSimulation::simulation(string inputFileName)
{
    ifstream myfile(inputFileName);

    if (myfile.is_open())
    {
        string instruction;
        while (getline(myfile, instruction))
        {
            string temp;
            double* arr = new double[2];
            int idx = 0;
            bool flag = true;
            for (int i = 0; i < instruction.length(); i++)
            {
                if (instruction[i] != ' ')
                {
                    temp.push_back(instruction[i]);
                    flag = true;
                }
                else if (flag)
                {
                    flag = false;
                    arr[idx] = stoi(temp);
                    idx++;
                    temp.clear();
                }
            }
            arr[idx] = stoi(temp);

            Event newArrival('A', arr[0], arr[1]);
            eventList->enqueue(newArrival);
            numberOfCustomer++;
            delete[] arr;
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
}

double BankSimulation::getAverageWaitTime() const
{
    double result = totalWaitTime / (double)numberOfCustomer;

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
    double totalLength = 0;

    for (vector< vector<int> >::iterator i = lengthHash->begin(); i != lengthHash->end(); i++)
    {
        for (int j = 0; j < queueLength.size(); j++)
        {
            totalLength += i->at(j);
        }

        totalLength /= double(queueLength.size());
    }

    result = totalLength / (double)lengthHash->size();

    return result;
}