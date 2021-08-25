//Tính S(n) = 1 + (x^2) / 2! + (x^4) / 4! + ... + (x^2n) / (2n)!
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a = 1;
    int i = 1;
    double S = 1;
    long P = 1;
    long T = 1;

    cout << "Nhap x: ";
    int x;
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
        P = P * x * x;
        a = 2 * i;
        T = T * a * (a - 1);
        i += 1;
        S += (double)P / T;
    }
    
    if (n == 1)
        cout << "S = 1 + (" << x << "^2) / 2! = " << S << "\n";

    else
    {
        if (n == 2)
            cout << "S = 1 + (" << x << "^2) / 2! + (" << x << "^4) / 4! = " << S << "\n"; 

        else
        {
            if (n == 3)
                cout << "S = 1 + (" << x << "^2) / 2! + (" << x << "^4) / 4! + (" << x << "^6) / 6! = " << S << "\n";
            
            else
                cout << "S = 1 + (" << x << "^2) / 2! + (" << x << "^4) / 4! + (" << x << "^6) / 6! + ... + (" << x << "^" << 2 * n << ") / " << 2 * n << "! = " << setprecision(9) << S << "\n";
        }
    }
    
    return 0;
}