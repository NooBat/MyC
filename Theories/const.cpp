//////////////////////////////////////////////////////////////
//  - Cách khai báo hằng số trong C++:                      // 
//  * const double PI{ 3.14159 };  (cách này thông dụng hơn)// 
//  * double const PI{ 3,14159 };                           //
//  - Hằng số phải được khởi tạo khi khai báo               //
//  const double PI;  (sai khi chưa khởi tạo hằng số)       // 
//  const double PI{ 3.14159 };  (Khởi tạo hằng số PI)      //
//  PI = 3;     (sai vì hằng số không thể thay đổi)         //
//////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

//định nghĩa 1 macro bằng chỉ thị tiền xử lí #define
#define YEAR_OF_BIRTH 2016

int main()  
{
    cout << "Year of birth: " << YEAR_OF_BIRTH << endl;
    

    //khởi tạo 1 biến int với giá trị 2016
    int nYear{ YEAR_OF_BIRTH };

    cout << nYear << endl;
    return 0;
}
//không nên dùng chỉ thị tiền xử lí #define thay cho từ khoá const