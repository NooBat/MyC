//Tính S(n) = 1 + 1 / 1 + 1 / (1 + 2) + ... + 1 / (1 + 2 + 3 + ... + n)
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int i = 1;
    double S = 0;
    int P = 0;
    
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
        P = P + i;
        S = (double)S + (double)1 / P;
        i++;    
    }
    if (n == 1)
    {
        cout << "S = 1\n";
    }
    else
    {
        if (n == 2)
        {
            cout << "S = 1 + 1 / (1 + 2) = " << S << "\n";
        }
        else
        {
            if (n == 3)
            {
                cout << "S = 1 + 1 / (1 + 2) + 1 / (1 + 2 + 3) = " << S << "\n";
            }
            else
            {
                cout << "S = 1 + 1 / (1 + 2) + ... + 1 / (1 + 2 + 3 + ... + " << n << ") = " << setprecision(10) << S << "\n";
            }
        }
    }
    return 0;
}