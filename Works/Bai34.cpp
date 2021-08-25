//Tính S(n) = CanBac2(n + CanBac2((n - 1) + CanBac2((n - 2) + ... + CanBac2(2 + CanBac2(1)))) với n dấu căn
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
        cout << "Nhap lai so nguyen n: ";
        cin >> n;
    }

    while (i <= n)
    {
        S = sqrt(i + S);
        i++;
    }

    if (n == 1)
    {
        cout << "S = CanBac2(1) = " << S << "\n";
    }
    else
    {
        if (n == 2)
        {
            cout << "S  = CanBac2(2 + CanBac(1)) = " << S << "\n";
        }
        else
        {
            if (n == 3)
            {
                cout << "S = CanBac2(3 + CanBac2(2 + CanBac2(1))) = " << S << "\n";
            }
            else
            {
                cout << "S = CanBac2(" << n << " + CanBac2(" << n - 1 << " + ... + CanBac2(2 + CanBac2(1)))) = " << setprecision(10) << S << "\n";
            }
        }
    }
    
    return 0;
}