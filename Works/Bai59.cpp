//Kiểm tra số nguyên dương n có phải số đối xứng hay không?
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
        a = (a * 10) + (i % 10);
        i /= 10;
    }

    if (a == n)
    {
        cout << n << " la so doi xung.\n";
    }
    else
    {
        cout << n << " la so khong doi xung.\n";
    }

    return 0;    
}