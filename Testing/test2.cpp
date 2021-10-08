#include<iostream>
#include<iomanip>

using namespace std;

int main() {

    double a = 0.5;

    for (long long i = 2; i <= 1000000000; i++)
    {
        a *= (2 * i - 1) / (double)(2 * i);
    }

    cout << setprecision(10) << a << endl;
    return 0;
}