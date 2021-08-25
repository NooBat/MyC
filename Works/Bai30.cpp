//Kiểm tra n có phải là số hoàn thiện hay không?
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int i = 1;
    int S = 0;

    cout << "Nhap so nguyen n: ";
    int n;
    cin >> n;

    while (n <= 0)
    {
        cout << "Nhap lai n:";
        cin >> n;
    }

    cout << "Cac uoc so cua " << n << " la: ";

    while (i <= n)
    {
        if (n % i == 0 and n != i)
        {
            cout << setw(5) << left << i;
            S += i;
        }
        
        i++;
    }

    cout << endl;

    if (S == n)
    {
        cout << n << " la so hoan thien.\n";
    }

    else
    {
        cout << n << " khong phai la so hoan thien.\n";
    }
    return 0;
}