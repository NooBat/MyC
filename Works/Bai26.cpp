//Tính tích các ước số lẻ của số nguyên n
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int i = 1;
    int P = 1;
    
    cout << "Nhap so nguyen n: ";
    int n;
    cin >> n;

    while (n <= 1)
    {
        cout << "Nhap lai n: ";
        cin >> n;
    }
    
    cout << "Cac uoc so le cua " << n << " la: ";
    
    while (i <= n)
    {
        if (i % 2 == 0)
        {
            i++;
        }

        if (n % i == 0 && i != n)
        {
            cout << setw(5) << left << i;
            P = P * i;
        }
    
        if (i == n) 
        {
            cout << i << endl;
            P = P * i;
        }
    
        i++;
    }

    if (n % 2 == 0)
    {
        cout << endl;
    }
    
    cout << "Tich cac uoc so le cua " << n << " la: " << P << "\n";

    return 0;
}