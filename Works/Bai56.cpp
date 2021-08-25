//Kiểm tra số nguyên dương n có toàn chữ số lẻ hay không?
#include <iostream>
using namespace std;

int main()
{
    bool Sole = true;
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
        if ((i % 10) % 2 == 0 )
        {
            Sole = false;
            break;
        }
        else
        {
            i = i / 10;
        }
    }

    if (Sole == true)
    {
        cout << n << " chi toan chu so le.\n";
    }
    else
    {
        cout << n << " co chu so chan.\n";
    }
    
    return 0;
}