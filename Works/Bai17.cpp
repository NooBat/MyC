//Tính S = x + (x^2) / 2! + (x^3) / 3! + ... + (x^n) / n!
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int i = 1;
    double S = 0;
    long P = 1;
    long T = 1;

    cout << "Nhap x: ";
    int x;
    cin >> x;

    cout << "Nhap n: ";
    int n;
    cin >> n;

    while (n <= 1)
    {
        cout << "Nhap lai n: ";
        cin >> n;
    }
    
    while (i <= n)
    {
        P = P * x;
        T = T * i;
        S += (double)P / T;
        i++;
    }
    
    if (n == 2)
    {
        cout << "S = " << x << " + (" << x << "^2) / 2! = " << S << "\n";
    }
    
    else
    {
        if (n == 3)
        {
            cout << "S = " << x << " + (" << x << "^2) / 2! + (" << x << "^3) / 3! = " << S << "\n"; 
        }
        
        else
        {
            if (n == 4)
            {
                cout << "S = " << x << " + (" << x << "^2) / 2! + (" << x << "^3) / 3! + (" << x << "^4) / 4! = " << S << "\n";
            }
            
            else
            {
                cout << "S = " << x << " + (" << x << "^2) / 2! + (" << x << "^3) / 3! + ... + (" << x << "^" << n << ") / " << n << "! = " << setprecision(9) << S << "\n";
            }
        }
    }
    
    return 0;
}