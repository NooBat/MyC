//Tính S(n) = 1 + 1 x 2 + 1 x 2 x 3 + ... + 1 x 2 x 3 x ... x n
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int i = 1;
    long long S = 0;
    long long P = 0;
    cout << "Nhap so nguyen n: ";
    int n;
    cin >> n;
    while (n == 0)
    {
        cout << "Nhap lai so nguyen n: ";
        cin >> n;
    }
    while (i <= n)
    {
        P = P * i;
        S = S + P;
        i++;
    }
    if (n == 1)
    {
        cout << "Tong S(n) = 1" << "\n";
    }
    else
    {
        if (n == 2)
        { 
            cout << "Tong S(n) = 1 + 1 x 2 = " << S << "\n";
        }
        else 
        {
            if (n == 3)
            {
                cout << "Tong S(n) = 1 + 1 x 2 + 1 x 2 x 3 = " << S << "\n";
            }
            else
            {
                cout << "Tong S(n) = 1 + 1 x 2 + ... + 1 x 2 x ... x " << n << " = " << setprecision(10) << S << "\n";
            }
        }
    }
    return 0;
}