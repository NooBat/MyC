//Tính S(n) = x^2 + x^4 + x^6 + ... + x^2n
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int i = 1;
    long S = 0;
    long P = 1;

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
        S = (long)S + P;
        i ++;
    }
    
    if (n == 2)
    {
        cout << "S = " << x << "^2 + " << x << "^4 = " << S << "\n";
    }
    
    else 
    {
        if (n == 3)
        {
            cout << "S = " << x << "^2 + " << x << "^4 + " << x << "^6 = " << S << "\n";
        }
    
        else
        {
            if (n == 4)
            {
                cout << "S = " << x << "^2 + " << x << "^4 + " << x << "^6 + " << x << "^8 = " << setprecision(9) << S << "\n";
            }
    
            else 
            {
                cout << "S = " << x << "^2 + " << x << "^4 + " << x << "^6 + ... + " << x << "^" << 2 * n << " = " << setprecision(10) << S << "\n";
            }
        }
    }
    return 0;
}