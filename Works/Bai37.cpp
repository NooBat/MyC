//Tính  S(n) = CanBacn(n + CanBac(n-1)((n - 1) + ... + CanBac3(3 + CanBac2(2)))))
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    int i = 2;
    double S = static_cast<double>(0);

    cout << "Nhap so nguyen n: ";
    int n;
    cin >> n;

    while(n <= 1)
    {
        cout << "Nhap lai n: ";
        cin >> n;
    }

    while (i <= n)
    {
        S = pow(S + i,1.0 / i);
        i++;
    }

    if (n == 2)
    {
        cout << "S = CanBac2(2) = " << S << "\n";
    }
    else
    {
        if (n == 3)
        {
            cout << "S = CanBac3(3 + CanBac2(2)) = " << S << "\n"; 
        }
        else
        {
            if (n == 4)
            {
                cout << "S = CanBac4(4 + CanBac3(3 + CanBac2(2))) = " << S << "\n";
            }
            else
            {
                if (n == 5)
                {
                    cout << "S = CanBac5(5 + CanBac4(4 + CanBac3(3 + CanBac2(2)))) = " << S << "\n";
                }
                else
                {
                    cout << "S = CanBac" << n << "(" << n << " + CanBac" << n - 1 << "(" << n - 1 << " + ... + CanBac3(3) +CanBac2(2) = " << setprecision(10) << S << "\n";
                }
            }
        }
    }
    
    return 0;
}