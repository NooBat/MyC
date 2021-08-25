//Kiểm tra các chữ số của số nguyên dương n có giảm dần từ trái sang phải hay không?
#include <iostream>
using namespace std;

int main()
{
    int i;
    int a = 0;
    bool Giam = true;

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
        if (i % 10 > a)
        {
            a = i % 10;
            i /= 10;
        }
        else
        {
            Giam = false;  
            break; 
        }
    }
    
    if (Giam == true)
    {
        cout << "Cac chu so cua " << n << " giam dan.\n";
    }
    else
    {
        cout << "Cac chu so cua " << n << " khong giam dan.\n";
    }
    
    return 0;
}