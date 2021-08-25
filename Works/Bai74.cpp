//Tính S(x, n) = 1 - x + (x^3)/3! - (x^5)/5! + ... + (((-1)^(n + 1) * (x^(2n + 1))/(2n + 1)!)
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int i = 1;
    float S = 1;
    int P = 1;

    cout << "Nhap x: ";
    float x;
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

    while (i <= n)
    {
        P = P * (2 * i) * (2 * i + 1);
        S += pow(-1, i + 1) * (pow(x, 2 * i + 1) / P);
        i++;
    }

    switch (n)
    {
        case 0:
            cout << "S = 1 - " << x << " = " << S << "\n";
            break;
        case 1:
            cout << "S = 1 - " << x << " + (" << x << "^3)/3! = " << S << "\n";
            break;
        case 2:
            cout << "S = 1 - " << x << " + (" << x << "^3)/3! - (" << x << "^5)/5! = " << S << "\n";
            break;
        case 3:
            cout << "S = 1 - " << x << " + (" << x << "^3)/3! - (" << x << "^5)/5! + (" << x << "^7)/7! = " << S << "\n";
            break;
    }

    if (n > 4)
    {
        if (pow(-1, n + 1) < 0)
        {
            cout << "S = 1 - " << x << " + (" << x << "^3)/3! - (" << x << "^5)/5! + ... - (" << x << "^" << 2 * n + 1 << ")/" << 2 * n + 1 << "! = " << S << "\n";
        }
        if (pow(-1 , n + 1) > 0)
        {
            cout << "S = 1 - " << x << " + (" << x << "^3)/3! - (" << x << "^5)/5! + ... + (" << x << "^" << 2 * n + 1 << ")/" << 2 * n + 1 << "! = " << S << "\n";
        }
    }

    return 0;
}