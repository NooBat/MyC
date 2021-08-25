//Đếm số chữ số của số nguyên dương n
#include <iostream>
#include <iomanip>
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
        i = i / 10;
        a = a + 1;
    }

    cout << "So chu so cua " << n << " la: " << a << "\n";
    
    return 0;
}