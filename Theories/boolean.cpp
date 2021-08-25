#include <iostream>
using namespace std;

int main()
{
    bool b1(true);
    //in giá trị 1 ra màn hình
    cout << b1 << endl;
    //in giá trị 0 ra màn hình
    cout << !b1 << endl;

    bool b2{ false };
    //in giá trị 0 ra màn hình
    cout << b2 << endl;
    //in giá trị 1 ra màn hình
    cout << !b2 << endl;

    bool b3 = 1;
    cout << b3 << endl;
    cout << !b3 << endl;

    //với các số nguyên khác 0 thì mặc định coi đó là 1 (true)
    bool b4 = -9;
    cout << b4 << endl;
    cout << !b4 << endl;

    return 0;
}