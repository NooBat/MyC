//Tính S(n) = 1 / (1 + (1 / (1 + ... + (1 / (1 + 1))))) với n dấu phân số
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    int i = 1;
    long double S = 1.0;

    cout << "Nhap so nguyen n: ";
    int n;
    cin >> n;

    while(n <= 0)
    {
        cout << "Nhap lai n: ";
        cin >> n;
    }

    while(i <= n)
    {
        S = 1.0 / (S + 1);
        i++;
    }
    
    if (n == 1)
    {
        cout << "S = 1 / (1 + 1) = " << S << "\n";
    }
    else
    {
        if (n == 2)
        {
            cout << "S = 1 / (1 + (1 / (1 + 1))) = " << S << "\n";
        }
        else
        {
            if (n == 3)
            {
                cout << "S = 1 / (1 + (1 / (1 + (1 / (1 + 1))))) = " << S << "\n";
            }
            else
            {
                cout << "S = 1 / (1 + (1 / (1 + ... + (1 / (1 + 1))))) = " << setprecision(10) << S << "\n";
            }
        }
    }
    return 0;
}