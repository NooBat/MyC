//Tính S(n) = CanBac2(1 + CanBac2(2 + ... + CanBac2((n-1) + CanBac2(n)))) với n dấu căn
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    int i = 1;
    double S = 0;

    cout << "Nhap so nguyen n: ";
    int n;
    cin >> n;

    while (n <= 0)
    {
        cout << "Nhap lai n: ";
        cin >> n;
    }

    i = n;
    while (i >= 1)
    {
        S = sqrt(i + S);
        i--;
    }

    if (n == 1)
    {
        cout << "S = CanBac2(1) = " << S << "\n";
    }
    else 
    {
        if (n == 2)
        {
            cout << "S = CanBac2(1 + CanBac2(2)) = " << S << "\n";
        }
        else
        {
            if (n == 3)
            {
                cout << "S = CanBac2(1 + CanBac2(2 + CanBac2(3))) = " << S << "\n";
            }     
            else
            {
                cout << "S = CanBac2(1 + CanBac2(2 + ... + CanBac2(" << n - 1 << " + CanBac2(" << n << ")))) = " << setprecision(10) << S << "\n";
            }               
        }
    }

    return 0;
}