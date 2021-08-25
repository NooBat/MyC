//Tính S(n) = 1^2 + 2^2 + ... + n^2
#include <iostream>
using namespace std;

int main()
{
    int i = 1;
    int n;
    long long S = 0;

    cout << "Nhap so n: ";
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
        cout << "Nhap so n: ";
        cin >> n;
    }

    //tạo vòng lặp tính tổng từ 1^2 đến n^2

    while (i <= n)
    {
        //S = S + i * i
        S += i * i;
        i++;
    }
    //kết thúc vòng lặp
    //trường hợp n == 1 ta không cần đến 2^2 nên ta cần viết lại
    if (n == 1)
    {
        cout << "Tong S = 1^2 = 1" << "\n";
    }
    else
    {
        if (n == 2)
        {
            cout << "Tong S = 1^2 + 2^2 = " << 1 + 2 * 2 << "\n";
        }
        else
        {
            cout << "Tong S = 1^2 + 2^2 + ... + " << n << "^2 = " << S << "\n";  
        }
    }
    return 0;
}