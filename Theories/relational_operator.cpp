#include <iostream>
using namespace std;

int sum(int a, int b)
{
    return a + b;
}
int main()
{
    cout << "Enter an integer: ";
    int x;
    cin >> x;

    cout << "Enter another integer: ";
    int y;
    cin >> y;
    
    if (x == y) 
        cout << x << " == " << y << "\n";
    if (x != y)
        cout << x << " != " << y << "\n";
    if (x > y)
        cout << x << " > " << y << "\n";
    if (x < y)
        cout << x << " < " << y << "\n";
    if (x <= y)
        cout << x << " <= " << y << "\n";
    if (x >= y)
        cout << x << " >= " << y << "\n";
    return 0;

}
////////////////////////////////////////////////////////////////////
//  CHÚ Ý: không nên so sánh 2 số chấm động bằng nhau hay không.  //  
//  Thay vào đó nên tìm khoảng cách giữa 2 số, nếu khoảng cách    //
//  rất nhỏ thì ta coi như bằng nhau.                             //
////////////////////////////////////////////////////////////////////