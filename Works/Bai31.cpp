//Kiểm tra n có phải là số nguyên tố hay không?
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int i = 1;
    int a = 0;

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
        if (n % i == 0)
        {
            cout << setw(5) << left << i;
            a++;
        }

        i++;
    }

    cout << endl;

    if (a == 2)
    {
        cout << n << " la so nguyen to.\n";
    }
    else 
    {
        cout << n << " khong phai la so nguyen to.\n";
    }

    return 0;
}