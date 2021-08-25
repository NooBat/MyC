//Kiểm tra n có phải số chính phương hay không?
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int i = 1;
    bool T = false;

    cout << "Nhap so nguyen n: ";
    int n;
    cin >> n;

    while (n <= 0)
    {
        cout << "Nhap lai n: ";
        cin >> n;
    }
    
    while (i <= n)
    {
        if (n / i == i)
        {
            T = true;
        }
        
        i++;
    }
    
    if (T == true)
    {
        cout << n << " la so chinh phuong.\n";
    }
    
    else
    {
        cout << n << " khong phai la so chinh phuong.\n";
    }
    
    return 0;
}