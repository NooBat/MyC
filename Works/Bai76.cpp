//Kiểm tra số nguyên 4 byte có dạng 3^k hay không.
#include <iostream>
using namespace std;

bool check(int n)
{
    bool a = true;
    if (n < 0)
    {
        n = -n;
    }
    if (n <= 1 and n >= 0)
    {
        a = false;
    }
    while (n > 1)
    {
        int r = n % 3;

        if (r != 0)
        {
            a = false;
        }

        n /= 3;
    }

    return a;
}
int main()
{
    bool a;
    
    cout << "Nhap n: ";
    int n;
    cin >> n;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << "Nhap lai n: ";
        cin >> n;
    }

    a = check(n);

    if (a == false)
    {
        cout << "n khong co dang 3^k." << endl;
    } 
    else
    {
        cout << "n co dang 3^k.\n";
    }
    
    return 0;
}