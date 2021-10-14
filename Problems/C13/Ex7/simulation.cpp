#include "BankSimulation2.hpp"
#include "BankSimulation2.cpp"

using namespace std;

int main()
{
    BankSimulation newBank(3, 1);

    cout << "Simulation starts." << endl << endl;
    newBank.simulation("/Users/danielnguyen/Repo/C++/Problems/C13/Ex6/event.txt");
    cout << "Simulation ends." << endl;

    cout << endl << endl;
    cout << "Final Statistics:\n";
    cout << "\tTotal number of people processed: " << newBank.getNumberOfCustomer() << endl;
    cout << "\tAverage amount of time spent waiting: " << setprecision(2) << newBank.getAverageWaitTime() << endl;
    cout << "\tMaximum length of line: " << newBank.getMaximumLength() << endl;
    cout << "\tAverage length of line: " << setprecision(2) << newBank.getAverageLineLength() << endl;

    return 0;
}