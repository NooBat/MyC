#include <iostream>
#include "Constants.h"
using namespace std;

int main()
{
    cout << "PI = " << constants::PI << endl;
    cout << "Speed of sound = " << constants::SPEED_OF_SOUND << endl;
    cout << "Year of birth = " << constants::YEAR_OF_BIRTH << endl;

    return 0;
}
//////////////////////////////////////////////////////////////////////////////////       
// Có 2 cách để định nghĩa hằng số dùng được cho cả chương trình:               //
//      - Cách 1: Trong file constdefinition.cpp.                               //
//      - Cách 2:                                                               //
//              + Tạo 1 thư viện riêng (trong trường hợp này là Constants.h).   //
//              + Dùng thư viện với hằng số đã được định nghĩa vào chương trình.//
//////////////////////////////////////////////////////////////////////////////////