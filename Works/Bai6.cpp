//Tính tổng S(n) = 1/(1x2) + 1/(2x3) + ... + 1/(n(n+1))
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
        cout << "Nhap lai so n: ";
        cin >> n;
    }
    while (i <= n)
    {
        S = (double) 1 / (i * (i + 1));
        i++;
    }
    if (n == 1)
    {
        cout << "Tong S = 1/(1x2) = 1/2" << "\n";
    } 
    else
        {
            if (n == 2)
            {
                cout << "Tong S = 1/(1x2) + 1/(2x3) = " << S << "\n";
            }
            else
            {
                if (n == 3)
                {
                    cout << "Tong S = 1/(1x2) + 1/(2x3) + 1/(3x4) = " << S << "\n";
                }
                else
                {
                    cout << "Tong S = 1/(1*2) + 1/(2*3) + ... + 1/(" << n << "*" << n+1 << ") = " << setprecision(10) << S << "\n";
                }
            }
        }    
    return 0;
}