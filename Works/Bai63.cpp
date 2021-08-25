//Tìm bội số chung nhỏ nhất của số nguyên dương a và b
#include <iostream>
using namespace std;

int main()
{
    int min;
    int i = 1;

    cout << "Nhap so nguyen duong a: ";
    int a;
    cin >> a;

    cout << "Nhap so nguyen duong b: ";
    int b;
    cin >> b;

    while (a <= 0 or b <= 0)
    {
        if (a <= 0)
        {
            cout << "Nhap lai a: ";
            cin >> a;
        }

        if (b <= 0)
        {
            cout << "Nhap lai b: ";
            cin >> b;
        }
    }
    
    if (a >= b)
    {
        min = a;
    }
    else
    {
        min = b;
    }

    if (min == a)
    {
        while (min % b != 0)
        {
            min *= i;
            i++;
        }
    }
    else
    {
        while (min % a != 0)
        {
            min *= i;
            i++;
        }
    }
    
    cout << "Boi so chung nho nhat cua " << a << " va " << b << " la: " << min << endl;
    
    return 0;
}