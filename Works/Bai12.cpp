//Tính S(n) = x + x^2 + x^3 + ... + x^n
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    //Số lần mũ
    int i = 1;
    long S = 0;
    long P = 1;
    cout << "Nhap x: ";
    int x;
    cin >> x;
    cout << "Nhap n: ";
    int n;
    cin >> n;
    while (n <= 1)
    {
        cout << "Nhap lai n: ";
        cin >> n; 
    }
    while (i <= n)
    {
        P = (long)P * x;
        S = (long)S + P;
        i++;
    }
    if (n == 2)
    {
        cout << "S = " << x << " + " << x << "^2 = " << setprecision(9)<< S << "\n"; 
    }
    else
    {
        if (n == 3)
        {
            cout << "S = " << x << " + " << x << "^2 + " << x << "^3 = " << setprecision(9) << S << "\n";
        }
        else 
        {
            if (n == 4)
            {
                cout << "S = " << x << " + " << x << "^2 + " << x << "^3 + " << x << "^4 = " << setprecision(9) << S << "\n";
            }
            else
            {
                cout << "S = " << x << "+ " << x << "^2 + " << x << "^3 + " << x << "/n" << n << " = " << setprecision(10) << S << "\n";
            }
        }
    }
    return 0;
}