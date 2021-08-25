//Tính S(x, n) = -x + (x^2)/(1 + 2) - (x^3)/(1 + 2 + 3) + ... + ((-1)^n) * ((x^n)/(1 + 2 + 3 + ... + n))
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int i = 1;
    double S = 0;
    int a = 0;

    cout << "Nhap x: ";
    double x;
    cin >> x;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << "Nhap lai x: ";
        cin >> x;
    }

    cout << "Nhap n: ";
    int n;
    cin >> n;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << "Nhap lai n: ";
        cin >> n;
    }

    while (n <= 0)
    {
        cout << "Nhap lai n: ";
        cin >> n;
    }

    while (i <= n)
    {
        a += i;
        S += pow(-1, i) * (pow(x, i) / a);
        i++;
    }

    switch (n)
    {
        case 1:
            cout << "S = -" << x << endl;
            break;
        case 2:
            cout << "S = -" << x << " + (" << x << "^2)/(1 + 2) = " << S << "\n";
            break;
        case 3:
            cout << "S = -" << x << " + (" << x << "^2)/(1 + 2) - (" << x << "^3)/(1 + 2 + 3) = " << S << "\n";
            break;
        case 4:
            cout << "S = -" << x << " + (" << x << "^2)/(1 + 2) - (" << x << "^3)/(1 + 2 + 3) + (" << x << "^4)/(1 + 2 + 3 + 4) = " << S << "\n";
            break; 
    }

    if (n > 4)
    {
        if (pow(-1, i) < 0)
        {
            cout << "S = -" << x << " + (" << x << "^2)/(1 + 2) - (" << x << "^3)/(1 + 2 + 3) + ... - (" << x << "^" << n << ")/(1 + 2 + 3 + ... + " << n << ") = " << S << "\n";
        }
        if (pow(-1, i) > 0)
        {
            cout << "S = -" << x << " + (" << x << "^2)/(1 + 2) - (" << x << "^3)/(1 + 2 + 3) + ... + (" << x << "^" << n << ")/(1 + 2 + 3 + ... + " << n << ") = " << S << "\n";
        } 
    }

    return 0;
}