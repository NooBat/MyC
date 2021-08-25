//Tính S(n) = 1 + 2 + ... + n
#include <iostream>
using namespace std;

int main()
{

    int i;
    int n;
    long S;

    i = 1;
    S = 0;

    cout << "Nhap so n: ";
    cin >> n;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << "Nhap lai n: "; 
        cin >> n;
    }

    while (n <= 0)
    {
        cout << "Nhap lai n: ";
        cin >> n;
    }
    
    while (i <= n)
    {
        S += i;
        i++;
    }

    cout << "Tong 1 + 2 + 3 + ... + " << n << " = " << S << "\n";

    return 0;
}