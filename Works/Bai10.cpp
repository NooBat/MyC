//Tính T(x, n) = x ^ n
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    long double T = 1;
    int x;
    int n;
    cout << "Nhap x: ";
    cin >> x;
    cout << "Nhap n: ";
    cin >> n;

    int i = 1;
    if (n == 0)
    {
        T = 0;
    }
    else
    {
        if (n > 0)
        {
            while (i <= n)
            {
                T = (long double)T * x;
                i++;
            }
        }
        else
        {
            while (i <= -n)
            {
                T = (long double)T / x;
                i++;
            }
        }
    }
    if (n>=0)
    {
        cout << "T(" << x << ", " << n << ") = " << x << "^" << n << " = " << setprecision(10) << T << "\n";
    }
    else
    {
         cout << "T(" << x << ", " << n << ") = (" << x << ")^(" << n << ") = " << setprecision(10) << T << "\n";   
    }
    return 0;
}