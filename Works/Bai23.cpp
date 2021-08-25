//Đếm số lượng ước số của số nguyên n
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
    
    cout << "Cac uoc so cua " << n << " la: ";

    while (i <= n)
    {
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
    cout << "So luong uoc so cua " << n << " la: " << T << "\n";

    return 0;
}