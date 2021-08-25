//Đếm số lượng chữ số đầu tiên của số nguyên dương n
#include <iostream>
using namespace std;

int main()
{
    int i;
    int a;
    int soluong = 0;
    int f = 0;

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
        f = i % 10;
        i = i / 10;        
    }

    i = n;

    while (i != 0)
    {
        a = i % 10;
        if (a == f)
        {
            soluong++;
        }

        i /= 10;
    }

    cout << "So luong chu so dau tien (" << f << ") cua " << n << " la: " << soluong << endl;

    return 0;
}