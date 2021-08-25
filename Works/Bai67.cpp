//Tính S(x, n) = x - x^2 + x^3 + ... + (-1)^(n+1)*(x^n)
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int i = 1;
    double S = 0;

    cout << "Nhap x: ";
    double x;
    cin >> x;

    cout << "Nhap n: ";
    int n;
    cin >> n;

    while (n <= 0)
    {
        cout << "Nhap lai n: ";
        cin >> n;
    }

    while (i <= n)
    {
        S += pow(-1, i + 1) * pow(x, i);
        i++;
    }

    switch (n)
    {
    case 1:
        cout << "S = " << S << endl;
        break;
    case 2:
        cout << "S = " << x << " - " << x << "^2 = " << S << "\n";
        break;
    case 3:
        cout << "S = " << x << " - " << x << "^2 + " << x << "^3 = " << S << "\n";
        break;
    case 4:
        cout << "S = " << x << " - " << x << "^2 + " << x << "^3 - " << x << "^4 = " << S << endl;
        break;
    }

    if (n > 4)
    {
        if (pow(-1, n + 1) < 0)
        {
            cout << "S = " << x << " - " << x << "^2 + " << x << "^3 + ... " << pow(-1, n + 1) * x << "^" << n << " = " << S << endl;
        }
        else
        {
            cout << "S = " << x << " - " << x << "^2 + " << x << "^3 + ... + " << pow(-1, n + 1) * x << "^" << n << " = " << S << endl;
        }     
    }

    return 0;
}