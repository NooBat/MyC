//Đếm các chữ số lẻ của số nguyên dương n
#include <iostream>
using namespace std;

int main()
{
    int i;
    int a = 0;
    
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
        if (i % 2 != 0)
        {
            a++;
        }
        i = i / 10;
    }

    cout << "So cac chu so le cua " << n << " la: " << a << ".\n";

    return 0;
}