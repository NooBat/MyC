//Tính S(n) = CanBac2(n! + CanBac2((n-1)! + ... CanBac2(2! + CanBac2(1!)))
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int GiaiThua(int n)
{
    int P = 1;
    int i = 1;
    
    while(i <= n)
    {
        P = P * i;
        i++;
    }

    return P;
}
int main()
{
    int i = 1;
    double S = 0;
    int N;

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
        N = GiaiThua(i);
        S = sqrt(N + S);
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
            cout << "S = CanBac2(2! + CanBac2(1!)) = " << S << "\n";
        }   
        else 
        {
            if (n == 3)
            {
                cout << "S = CanBac2(3! + CanBac2(2! + CanBac2(1!))) = " << S << "\n";
            }
            else
            {
                if (n == 4)
                {
                    cout << "S = CanBac2(4! + CanBac2(3! + CanBac2(2! + CanBac2(1!)))) = " << S << "\n";
                }
                else
                {
                    cout << "S = CanBac2(" << n << "! + CanBac2(" << n - 1 << "! + ... + CanBac2(2! + CanBac2(1!)))) = " << setprecision(10) << S << "\n";
                } 
            }
        }
    }

    return 0;
}
