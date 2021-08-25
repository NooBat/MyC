//Tính S(n) = CanBac(n+1)(n + CanBacn((n-1)+ ... + CanBac3(2 + CanBac2(1))))
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    int i = 1;
    float S = static_cast<float>(0);

    cout << "Nhap so nguyen n: ";
    int n;
    cin >> n;

    while(n <= 0)
    {
        cout << "Nhap lai n: ";
        cin >> n;
    }

    while (i <= n)
    {
        S = pow(S + i,1.0/(i + 1));
        i++;
    }

    if (n == 1)
    {
        cout << "CanBac2(1) = " << S << "\n";
    }
    else
    {
        if (n == 2)
        {
            cout << "CanBac3(2 + CanBac2(1)) = " << S << "\n";
        }
        else
        {
            if (n == 3)
            {
                cout << "CanBac4(3 + CanBac3(2 + CanBac2(1))) = " << S << "\n";
            }
            else 
            {
                if (n == 4)
                {    
                    cout << "CanBac5(4 + CanBac4(3 + CanBac3(2 + CanBac2(1)))) = " << S << "\n";
                }
                else
                {
                    cout << "CanBac" << n + 1 << "(" << n << " + CanBac" << n << "(" << n - 1 << " + ... + CanBac3(2 + CanBac2(1)))) = " << setprecision(9) << S << "\n";
                }
            }
        }
        
        return 0;
    }
    
}