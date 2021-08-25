//Tính S(n) = 1/2 + 2/3 + ... + n/(n+1)
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int i = 1;
    double S = 0;
    cout << "Nhap so nguyen n: ";
    int n;
    cin >> n;

    while (n == 0)
    {
        cout << "Nhap lai so nguyen n:";
        cin >> n;
    }
    while (i <= n)
    {
        S += (double) i / (i + 1);
        i++;
    }
    if (n == 1)
    {
        cout << "Tong S = " << S << "\n";
    }
    else
    {
        if (n == 2)
        {
            cout << "Tong S = 1/2 + 2/3 = " << S << "\n";
        }
        else 
        {
            if (n == 3)
            {
                cout << "Tong S = 1/2 + 2/3 + 3/4 = " << S << "\n";
            }
            else 
            {
                cout << "Tong S = 1/2 + 2/3 + ... + " << n << "/" << n + 1 << " = " << setprecision(9) << S << "\n";
            }    
        } 
    }
    return 0;
}