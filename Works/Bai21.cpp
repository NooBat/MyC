//Tính tổng các ước số của số nguyên n
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
        cout << "Nhap lai so nguyen n: ";
        cin >> n;
    }

    cout << "Cac uoc so cua " << n << " la: ";

    while (i <= n)
    {
        if (n % i == 0 && n != i) 
        {
            cout << setw(5) << left << i;
            S += i;
        }

        if (n == i)
        {
            cout << i << endl;
            S += i;
        }
    
        i++;
    }
    
    cout << "Tong cac uoc so cua " << n << " la: " << S << endl;
    
    return 0;
}