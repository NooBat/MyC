//Tính S(n) = 1/2 + 1/4 + ... 1/2n
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int i = 1;
    double S = 0;
    cout << "Nhap so n: ";
    int n;
    cin >> n;
    
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
    while (i <=n)
    {
        S += (double) 1 / (2 * i);
        i++;
    }
    if (n == 1)
    {
        cout << "Tong S = 1/2" << "\n";
    }
    else
    {
        if (n == 2) 
        {
            cout << "Tong S = 1/2 + 1/4 = " << (double) 1 / 2 + (double) 1 / 4 << "\n";
        }
        else 
        {
            cout << "Tong S = 1/2 + 1/4 + ... + 1/" << 2 * n << " = " << setprecision(10) << fixed << S << "\n"; 
        }
    }
    return 0;
}