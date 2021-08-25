//Tính S = x + (x^2) / (1 + 2) + (x^3) / (1 + 2 + 3) + ... + (x^n) / (1 + 2 + 3 + ... + n)
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int i = 1;
    double S = 0;
    long P = 1;
    long T = 0;
    
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
        T = T + i;
        S += (double)P / T;
        i++; 
    }
    
    if (n == 2)
    {
        cout << "S = " << x << " + (" << x << "^2) / (1 + 2) = " << S << "\n"; 
    }
    
    else
    {
        if (n == 3)
        {
            cout << "S = " << x << " + (" << x << "^2) / (1 + 2) + (" << x << "^3) / (1 + 2 + 3) = " << S << "\n";
        }
    
        else
        {
            if (n == 4)
            {
                cout << "S = " << x << " + (" << x << "^2) / (1 + 2) + (" << x << "^3) / (1 + 2 + 3) + (" << x << "^4) / (1 + 2 + 3 + 4) = " << S << "\n";
            } 
    
            else
            {
                cout << "S = " << x << " + (" << x << "^2) / (1 + 2) + (" << x << "^3) / (1 + 2 + 3) + ... + (" << x << "^" << n << ") + (1 + 2 + 3 + ... + " << n << ") = " << setprecision(10) << S << "\n";
            }
        }
    }
    
    return 0;    
}