//Tìm chữ số nhỏ nhất của số nguyên dương n
#include <iostream>
using namespace std;

int main()
{
    int i;
    int a;
    int min = 10;

    cout << "Nhap so nguyen duong n: ";
    int n;
    cin >> n;

    while (n <= 0)
    {
        cout << "Nhap lai so nguyen duong n: ";
        cin >> n;
    }

    i = n;

    while (i != 0)
    {
        a = i % 10;
        if (a < min)
        {
            min = a;
        }
        i = i / 10;
    }

    cout << "Chu so nho nhat cua " << n << " la: " << min << "\n";

    return 0;
}