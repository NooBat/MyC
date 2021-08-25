//Tính S(n) = CanBac2(2 + CanBac2(2 + ... + CanBac2(2 + CanBac2(2)))) với n dấu căn
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    int i = 1;
    long double S = 0;

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
        S = sqrt(2 + S);
        i++;
    }

    if (n == 1)
    {
        cout << "S = CanBac2(2) = " << S << "\n";
    }
    else
    {
        if (n == 2)
        {
            cout << "S = CanBac2(2 + CanBac2(2)) = " << S << "\n";
        }
        else
        {
            if (n == 3)
            {
                cout << "S = CanBac2(2 + CanBac2(2 + CanBac2(2))) = " << S << "\n";
            }
            else
            {
                cout << "S = CanBac2(2 + CanBac2(2 + ... + CanBac2(2 + CanBac2(2)))) voi (" << n << " lan can) = " << setprecision(10) << S << "\n";
            }
        }
    }
    
    return 0;
}