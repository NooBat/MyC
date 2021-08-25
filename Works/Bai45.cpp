//Tính tích các chữ số của số nguyên dương n
#include <iostream>
using namespace std;

int main()
{
    int i;
    int a = 1;

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
        a = a * (i % 10);
        i = i / 10;
    }

    cout << "Tich cac chu so cua " << n << " la " << a << "\n";

    return 0;
}