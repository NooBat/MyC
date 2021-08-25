#include <iostream>
using namespace std;

int main()
{
        //sizeof là toán tử để trả về kích thước dữ liệu và biến
        cout << "bool:\t\t" << sizeof(bool) << " bytes" << endl;
        cout << "char:\t\t" << sizeof(char) << " bytes" << endl;
        cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes" << endl;
        cout << "char16_t:\t" << sizeof(char16_t) << " bytes" << endl;
        cout << "char32_t:\t" << sizeof(char32_t) << " bytes" << endl;
        cout << "short:\t\t" << sizeof(short) << " bytes" << endl;
        cout << "int:\t\t" << sizeof(int) << " bytes" << endl;
        cout << "long:\t\t" << sizeof(long) << " bytes" << endl;
        cout << "long long:\t" << sizeof(long long) << " bytes" << endl;
        cout << "float:\t\t" << sizeof(float) << " bytes" << endl;
        cout << "double:\t\t" << sizeof(double) << " bytes" << endl;
        cout << "long double:\t" << sizeof(long double) << " bytes" << endl;
        //tìm kích thước của 1 biến int
        int n;
        cout << "n variable:\t" << sizeof(n) << " bytes" << endl;
        return 0;
}