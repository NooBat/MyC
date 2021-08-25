//Tính S(n) = CanBac2(x^n + CanBac2(x^(n-1) + ... + CanBac2(x^2 + CanBac2(x))))
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    int i = 1;
    double S = static_cast<double>(0);

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
        S = pow(S + pow (x,i),1.0 / 2);
        i++;
    }

    if (n == 1)
    {
        cout << "S = CanBac2(" << x << "^1) = " << S << "\n" ;
    }
    else
    {
        if (n == 2)
        {
            cout << "S = CanBac2(" << x << "^2 + CanBac2(" << x << "^1)) = " << S << "\n";
        }
        else
        {
            if (n == 3)
            {
                cout << "S = CanBac2(" << x << "^3 + CanBac2(" << x << "^2 + CanBac2(" << x << "^1))) = " << S << "\n";
            }
            else
            {
                if (n == 4)
                {
                    cout << "S = CanBac2(" << x << "^4 + CanBac2(" << x << "^3 + CanBac2(" << x << "^2 + CanBac2(" << x << "^1)))) = " << S << "\n";
                }
                else
                {
                    cout << "S = CanBac2(" << x << "^" << n << " + CanBac2(" << x << "^" << n -1 << " + ... + CanBac2(" << x << "^2 + CanBac2(" << x << "^1)))) = " << setprecision(10) << S << "\n";
                }
            }
        }
    }
    return 0;
}