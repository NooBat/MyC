//Tính S(x, n) = -x^2 + x^4 - x^6 + ... + (-1)^n * x^(2n)
#include <iostream>
#include <iomanip>
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
        S += pow(-1, i) * static_cast<double>(pow(x, 2 * i));
        i++;
    }

    switch (n)
    {
        case 1:
            cout << "S = -" << x << "^2 = " << S << endl;
            break;
        case 2:
            cout << "S = -" << x << "^2 + " << x << "^4 = " << S << "\n";
            break;
        case 3:
            cout << "S = -" << x << "^2 + " << x << "^4 - " << x << "^6 = " << S << "\n";
            break;
        case 4:
            cout << "S = -" << x << "^2 + " << x << "^4 - " << x << "^6 + " << x << "^8 = " << S << "\n";
            break; 
    }

    if (n > 4)
    {
        if (pow(-1, n) < 0)
        {
            cout << "S = -" << x << "^2 + " << x << "^4 - " << x << "^6 + ... - " << x << "^" << 2 * n << " = " << S << "\n";
        }
        if (pow(-1, n) > 0)
        {
            cout << "S = -" << x << "^2 + " << x << "^4 - " << x << "^6 + ... + " << x << "^" << 2 * n << " = " << S << "\n"; 
        }
    }

    return 0;
}