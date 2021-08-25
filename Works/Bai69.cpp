//Tính S(x, n) = x - x^3 + x^5 + ... + (-1)^n * x^(2n+1)
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int i = 0;
    float S = 0;

    cout << "Nhap x: ";
    float x;
    cin >> x;

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

    while (n < 0)
    {
        cout << "Nhap lai n: "; 
        cin >> n;
    }

    while (i <= n)
    {
        S += pow(-1, i) * pow(x, 2 * i + 1);
        i++;
    }

    switch (n)
    {
        case 1:
            cout << "S = " << x << endl;
            break;
        case 2:
            cout << "S = " << x << " - " << x << "^3 = " << S << "\n";
            break;
        case 3:
            cout << "S = " << x << " - " << x << "^3 + " << x << "^5 = " << S << endl;
            break;
        case 4:
            cout << "S = " << x << " - " << x << "^3 + " << x << "^5 - " << x << "^7 = " << S << endl;
            break;
    }

    if (n > 4)
    {
        if (pow(-1, i) < 0)
        {
            cout << "S = " << x << " - " << x << "^3 + " << x << "^5 + ... - " << x << "^" << 2 * n + 1 << " = " << S << "\n";
        }
        if (pow(-1, i) > 0)
        {
            cout << "S = " << x << " - " << x << "^3 + " << x << "^5 + ... + " << x << "^" << 2 * n + 1 << " = " << S << "\n";
        }
    }

    return 0;
}