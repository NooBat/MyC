//Tính tích các ước số của số nguyên n
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

    while (n <= 0)
    {
        cout << "Nhap lai n: ";
        cin >> n;
    }
    cout << "Cac uoc so cua " << n << " la: ";
    while (i <= n)
    {
        if (n % i == 0 && n != i)
        {
            cout << setw(5) << left << i;
            P = P * i;
        }
        
        if (n == i)
        {
            cout << i << endl;
            P = P * i;
        }
        
        i++; 
    }
    
    cout << "Tich cac uoc so cua " << n << " la: " << P << "\n";
    
    return 0;
}