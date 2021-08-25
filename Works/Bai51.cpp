//Tìm chữ số lớn nhất trong số nguyên dương n
#include <iostream>
using namespace std;

int main()
{
    int i;
    int a;
    int max = 0;

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

        i = i / 10;
    }

    cout << "Chu so lon nhat cua " << n << " la: " << max << "\n";

    return 0;
}