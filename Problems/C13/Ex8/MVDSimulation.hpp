#ifndef _MVD_SIMULATION
#define _MVD_SIMULATION

#include "/Users/danielnguyen/Repo/C++/Problems/C13/OurPriorityQueue.hpp"
#include "/Users/danielnguyen/Repo/C++/Problems/C13/OurQueue.hpp"
#include "Event.hpp"

using namespace std;

auto comparator = [](const Event& a, const Event& b)
{
    return a.getName() > b.getName();
};

class MVDSimulation
{
private:
    OurPriorityQueue<Event, less<Event> >* eventList;
    OurPriorityQueue<Event, decltype(comparator)>* lrLine;    //license renewal waiting line
    OurQueue<Event>* rrLine;            //registration renewal waiting line
    OurQueue<Event>* siLine;            //sign in waiting line
    OurQueue<Event>* cLine;             //cashier waiting line

    bool signTeller;                    //for sign in line
    bool licenseTeller;                 //for license renewal line
    bool registerTeller;                //for registration renewal line
    bool cashier;                       //for cashier line

    double currentTime;
    int numberOfLicense;
    int numberOfRegister;

    void processArrival(Event arrival);
    void processSignIn(Event SignIn);
    void processRegistrationRenewal(Event registration);
    void processLicenseRenewal(Event license);
    void processCashierLine(Event c);
    void processDeparture(Event departure);


public:
    MVDSimulation();

    void simulation();
};

#endif