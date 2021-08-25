//Tính S(n) = CanBac(n+1)(n! + CanBacn((n - 1)! + ... CanBac3(2! + CanBac2(1!)))))
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    int i  = 1;
    double S = static_cast<double>(0);
    int M = 1;

    cout << "Nhap so nguyen n: ";
    int n;
    cin >> n;

    while (n <= 0)
    {
        cout << "Nhap lai n: ";
        cin >> n;
    }

    while (i <= n)
    {
        M = M * i;
        S = pow(S + M,1.0 / (i + 1));
        i++;
    }

    if (n == 1)
    {
        cout << "S = CanBac2(1!) = " << S << "\n";
    }
    else
    {
        if (n == 2)
        {
            cout << "S = CanBac3(2! + CanBac2(1!)) = " << S << "\n";
        }
        else
        {
            if (n == 3)
            {
                cout << "S  = CanBac4(3! + CanBac3(2! + CanBac2(1!))) = " << S << "\n";
            }
            else
            {
                if (n == 4)           
                {
                    cout << "S = CanBac5(4! + CanBac4(3! + CanBac3(2! + CanBac2(1!)))) = " << S << "\n";
                }
                else 
                {
                    cout << "S = CanBac" << n + 1 << "(" << n << "! + CanBac" << n << "(" << n - 1 << "! + ... + CanBac3(2! + CanBac2(1!)))) = " << setprecision(10) << S << "\n";
                }
            }
        }
    }

    return 0;  
}