//Tính tổng các chữ số chẵn của số nguyên dương n
#include <iostream>
using namespace std;

int main()
{
    int i;
    int a = 0;

    cout << "Nhap so nguyen duong n: ";
    long n;
    cin >> n;

    while (n <= 0)
    {
        cout << "Nhap lai so nguyen duong n: ";
        cin >> n;
    }
    
    i = n;

    while (i != 0)
    {
        if (i % 2 == 0)
        {
            a = a + (i % 10);
        }
        i = i / 10;
    }

    cout << "Tong cac chu so chan cua " << n << " la: " << a << "\n";

    return 0;
}