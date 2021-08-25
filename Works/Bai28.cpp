//Tính tổng các ước số nhỏ hơn chính nó của số nguyên n
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int i = 1;
    int S = 0;
    
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
        if (n % i == 0 && i != n)
        {
            cout << setw(5) << left << i;
            S += i;
        }
        
        i++;
    }

    cout << endl;

    cout << "Tong cac uoc so nho hon " << n << " la: " << S << endl;
    
    return 0;
}