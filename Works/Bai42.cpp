//Tìm số nguyên dương k lớn nhất sao cho S(k) < n với S(k) = 1 + 2 + 3 + ... + k.
#include <iostream>
using namespace std;

int main()
{
    int k = 1;
    int S = 0;
    
    cout << "Nhap so nguyen duong n: ";
    int n;
    cin >> n;

    while (n <= 0)
    {
        cout << "Nhap lai n: ";
        cin >> n;
    }

    while (S <= n)
    {
        S = S + k;
        k++;
    }
    
    k = k - 1;
    S = S - k;
    k = k - 1;

    cout << "S(" << k << ") = " << S << "\n";

    cout << "k lon nhat la " << k << ".\n";

    return 0;
}
