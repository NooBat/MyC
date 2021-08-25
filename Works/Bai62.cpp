//Tìm ước chung lớn nhất của 2 số nguyên dương a và b
#include <iostream>
using namespace std;

int main()
{
    int uocmax;
    
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

    int i = 1;
    uocmax = i;

    while (i <= a)
    {
        if (a % i == 0 and b % i == 0 and i > uocmax)
        {
            uocmax = i;        
        }
        i++;
    }

    cout << "Uoc so chung lon nhat cua " << a << " va " << b << " la: " << uocmax << endl;

    return 0;
}