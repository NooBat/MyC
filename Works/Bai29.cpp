//Tìm ước số lẻ lớn nhất của số nguyên n
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int i = 1;
    int max;
    int a;

    cout << "Nhap so nguyen n: ";
    int n;
    cin >> n;

    while (n <= 0)
    {
        cout << "Nhap lai n: ";
        cin >> n;
    }

    while (i <= n)
    {   
        if (n % i == 0 and i % 2 == 1)
        {
            cout << setw(5) << left << i;
            max = i;
        }

        i++ ;
    }

    cout << endl;
    
    cout << "Uoc so le lon nhat cua " << n << " la: " << max << endl;

    return 0;
}