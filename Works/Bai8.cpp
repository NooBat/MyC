//Tính S(n) = 1/2 + 3/4 + ... + (2n+1)/(2n+2)
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int i = 0;
    double S = 0;
    cout << "Nhap so nguyen n: ";
    int n;
    cin >> n;

    while (i <= n)
    {
        S += (double) (2 * i + 1) / (2 * i + 2);
        i++;
    }
    if (n == 0)
    {
        cout << "Tong S = 1/2 = " << S << "\n";
    }
    else 
    {
        if (n == 1)
        {
            cout << "Tong S = 1/2 + 3/4 = " << S << "\n";
        }
        else
            if (n == 2)
            {
                cout << "Tong S = 1/2 + 3/4 + 5/6 = " << setprecision(9) << S << "\n";
            }
            else
            {
                cout << "Tong S = 1/2 + 3/4 + ... + " << 2 * i + 1 << "/" << 2 * i + 2 << " = " << setprecision(9) << S << "\n";         
            }   
    }
    return 0;
}