//Tính S(n) = 1 + x + (x^3) / 3! + (x^5) / 5! + ... + (x^(2n+1)) / (2n+1)!
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int i = 1;
    int x;
    int a;
    double S = 1;
    long P = x;
    long T = 1;
    
    cout << "Nhap x: ";
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
        a = 2 * i;
        T = T * a * (a + 1);
        P = P * x * x;
        i++;
        S = S + (double)P / T;
    }

    if (n == 1)
        cout << "S = 1 + " << x << " + (" << x << "^3) / 3! = " << S << "\n";

    else
    {
        if (n == 2)
            cout << "S = 1 + " << x << " + (" << x << "^3) / 3! + (" << x << "^5) / 5! = " << S << "\n";
        
        else 
        {
            if (n == 3)
                cout << "S = 1 + " << x << " + (" << x << "^3) / 3! + (" << x << "^5) / 5! + (" << x << "^7) / 7! = " << S << "\n";
            else
                 cout << "S = 1 + " << x << " + (" << x << "^3) / 3! + (" << x << "^5) / 5! + ... + (" << x << "^" << 2 * n + 1 << ") / " << 2 * n + 1 << "! = " << setprecision(10) << S << "\n";
        }
    }
    return 0;
}