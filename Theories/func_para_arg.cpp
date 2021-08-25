#include <iostream>
using namespace std;
//Hàm này không cần tham số và đối số
void sayHello()
{
    cout << "Hello World!" << endl;
}
//Hàm này dùng 1 tham số int là x
//Lời gọi hàm sẽ cung cấp giá trị của x
void printValue(int x)
{
    cout << x << endl;
}
//Hàm này có 2 tham số là x và y
//Lời gọi hàm sẽ cung cấp giá trị của x và y
int add(int x, int y)
{
    return x + y;
}
int main()
{
    sayHello();
    //69 là đối số được cung cấp cho hàm printValue()
    printValue(69);
    //6 và 9 là đối số được cung cấp cho hàm add()
    cout << "x + y = " << add(6, 9) << endl;

    return 0;
}
