//Tính S(n) = 1 + 1/3 + 1/5 + ... + 1/(2n+1)
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int i = 0;
    double S = 0;
    cout << "Nhap so n: ";
    int n;
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
        cout << "Nhap lai so n: ";
        cin >> n;
    }
    while (i <= n)
    {
        //Ép kiểu double cho S bằng double sau đó thực hiện phép tính lặp
        S += (double)1 / (2 * i + 1);
        i++;
    }
    if (n == 1)
    {
        cout << "Tong S(n) = 1" << "\n";
    }
    else 
    {
        if (n == 2) 
        {
            cout << "Tong S(n) = 1 + 1/3 = " << 1 + (double)1 / 3 << "\n";
        }
        else 
        {
            //xuất S ra màn hình với độ chính xác lên đến 10 chữ số
            cout << "Tong S(n) = 1 + 1/3 + ... + 1/" << 2 * n + 1 << " = " << setprecision(10) << S << "\n";
        }
    }
    return 0;
}