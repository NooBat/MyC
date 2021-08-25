//Kiểm tra số nguyên dương n có toàn số chẵn hay không?
#include <iostream>
using namespace std;

int main()
{
    bool Sochan = true;
    int i;

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
        if ((i % 10) % 2 != 0)
        {
            Sochan = false;
            break;
        }
        else
        {
            i = i / 10;
        }
    }

    if (Sochan == true)
    {
        cout << n << " chi toan chu so chan.\n";
    }
    else
    {
        cout << n << " co chu so le.\n";
    }
    
    return 0;
}