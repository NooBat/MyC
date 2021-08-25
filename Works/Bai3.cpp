//Tính S(n) = 1 + 1/2 + ... + 1/n
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int i;
    double S;
    double A;
    A = 1 + (double) 1/2;
    
    cout << "Nhap so n (n > 0): ";
    int n;
    cin >> n;
    S = 0; 
    i = 1;
    
    while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << "Nhap lai n: "; 
        cin >> n;
    }
    
    while (n <= 0)
    {
        cout << "Nhap lai so n: ";
        cin >> n;
    }
    while (i <= n)
    {
        S = S + (double) 1/i;
        i++;
    }
    if (n == 1)
        {
            cout << "Tong S = 1" << "\n";
        }
    else
    {
        if (n == 2)
        {
            cout << "Tong S = 1 + 1/2 = " << setprecision(2) << fixed << A << "\n";
        }
        else
        {
            cout << "Tong S = 1 + 1/2 + ... + 1/" << n << " = " << setprecision(6) << fixed << S << "\n";
        }
    }
    return 0;
}