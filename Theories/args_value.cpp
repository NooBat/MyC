#include <iostream>
using namespace std;

void callByValue(int y)
{
    cout << "y =" << y << endl;
    
    y = 69;

    cout << "y = " << y << endl;
}   // y bị huỷ tại đây
int main()
{
    int x = 1;
    cout << "x = " << x << endl;

    callByValue(x);

    cout << "x = "<< x << endl;

    return 0;
}
//Không nên sử dụng cách này khi đối số là các mảng (arrays), kiểu cấu trúc (structs), các lớp (classes)