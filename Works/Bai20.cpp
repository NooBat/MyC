#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int i = 1;
    
    cout << "Nhap so nguyen n: ";
    int n;
    cin >> n;

    while (n <= 1)
    {
        cout << "Nhap lai n: ";
        cin >>n;
    }
    cout << "Cac uoc so cua " << n << " la: ";
    
    while (i <= n)
    {
        if (n % i == 0 && i != n)
        {
            cout << setw(5) << left << i;
        }
    
        if (i == n)
        {
            cout << i << endl;
        }
    
        i++;
    }
    
    return 0;
}