//Kiểm tra các chữ số của số nguyên dương n có tăng dần từ trái sang phải hay không?
#include <iostream>
using namespace std;

int main()
{
    int i;
    int a = 10;
    bool Tang = true;

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
        if (i % 10 < a)
        {
            a = i % 10;
            i /= 10;
        }
        else
        {
            Tang = false;  
            break; 
        }
    }
    
    if (Tang == true)
    {
        cout << "Cac chu so cua " << n << " tang dan.\n";
    }
    else
    {
        cout << "Cac chu so cua " << n << " khong tang dan.\n";
    }
    
    return 0;
}