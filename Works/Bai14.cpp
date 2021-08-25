//Tính S(n) = x + x^3 + x^5 + ... + x^(2n+1)
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
        S = S + P;
        i = i + 2;
    }
    
    if (n == 1)
    {
        cout << "S = " << x << " + " << x << "^3 = " << S << "\n";
    }
    
    else 
    {
        if (n == 2)
        {
            cout << "S = " << x << " + " << x << "^3 + " << x << "^5 = " << S << "\n"; 
        }
    
        else
        {
            if (n == 3)
            {
                cout << "S = " << x << " + " << x << "^3 + " << x << "^5 + " << x << "^7 =" << S << "\n";
            }
    
            else
            {
                if (n == 4)
                {
                    cout << "S = " << x << " + " << x << "^3 + " << x << "^5 + " << x << "^7 + " << x << "^9 = " << S << "\n";
                }
    
                else
                {
                    cout << "S = " << x << " + " << x << "^3 + " << x << "^5 + ... + " << x << "^" << 2 * n + 1 << " = " << setprecision(9) << S << "\n";
                }   
            }
        }
    }
    return 0;
}