//Đếm số lượng ước số chẵn của số nguyên n
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int i = 1;
    int T = 0;
    
    cout << "Nhap so nguyen n: ";
    int n;
    cin >> n;

    while (n <= 0)
    {
        cout << "Nhap lai so nguyen n: ";
        cin >> n;
    }
    
    cout << "Cac uoc so chan cua " << n << " la: ";

    while (i <= n)
    {
        if (i % 2 == 1)
        {
            i++;
        }

        if (n % i == 0 && n != i)
        {
            cout << setw(5) << left << i;
            T++;
        }
        
        if (n == i)
        {
            cout << i << "\n";
            T++;
        }
        
        i++;
    }

    if (n % 2 == 1)
    {
        cout << endl;
    }
    cout << "So luong uoc so chan cua " << n << " la: " << T << "\n";

    return 0;
}