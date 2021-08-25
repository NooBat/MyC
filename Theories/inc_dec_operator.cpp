#include <iostream>
using namespace std;

int main()
{
    //prefix: tăng giảm giá trị của x, sau đó sử dụng x để tính toán
    int x = 69;
    //x bây giờ bằng 70, và y mang giá trị 70
    int y = ++x;
    cout << x << endl;
    cout << y << endl;

    //postfix: sử dụng x để tính toán sau đó tăng giảm giá trị của x
    int a = 69;
    int b = a++;
    //a bây giờ bằng 70, và b mang giá trị 69
    cout << a << endl;
    cout << b << endl;
    return 0;
}