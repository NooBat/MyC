//Đếm số lượng chữ số lớn nhất của số nguyên dương n
#include <iostream>
using namespace std;

int main()
{
    int i;
    int a;
    int max = 0;
    int soluong = 0;

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

        if (a > max)
        {
            max = a;
        }

        i /= 10;
    }

    i = n;

    while (i != 0)
    {
        a = i % 10;
        if (a == max)
        {
            soluong++;
        }

        i = i / 10;
    }

    cout << "So luong cac chu so lon nhat (" << max << ") cua " << n << " la: " << soluong << "\n";

    return 0;
}