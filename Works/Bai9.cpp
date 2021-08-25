//Tính cấp số nhân T(N) = 1 x 2 x ... x N
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int i = 1;
    long long T = 1;
    cout << "Nhap so nguyen N: ";
    int N;
    cin >> N;

    while (N == 0)
    {
        cout << "Nhap lai so nguyen N: ";
        cin >> N;
    }
    while (i <= N)
    {
        T = (long long) (T * i);
        i++;
    }
    if (N == 1)
    {
        cout << "T(N) = " << T << "\n";
    }
    else
    {
        if (N == 2)
        {
            cout << "T(N) = 1 x 2 = " << T << "\n";
        }
        else 
        {
            if (N == 3)
            {
                cout << "T(N) = 1 x 2 x 3 = " << T << "\n";
            }
            else
            {
                cout << "T(N) = 1 x 2 x ... x " << N << " = " << setprecision(10) << T << "\n";
            }
        }
    }    
    return 0;
}