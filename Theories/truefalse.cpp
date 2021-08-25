#include <iostream>
using namespace std;

int main()
{
    //boolalpha sẽ cho ra true/false thay vì 1/0 như bình thường(mặc định là 1/0)
    cout << boolalpha;
    //in "true" ra màn hình
    cout << true << endl;
    //in "false" ra màn hình
    cout << false << endl;

    //noboolalpha sẽ cho ra 1/0 như bình thường (không cần thiết nếu trước đó không dùng đến boolalpha)
    cout << noboolalpha;
    //in giá trị 1 ra màn hình
    cout << true << endl;
    //in giá trị 0 ra màn hình
    cout << false << endl;
    
    return 0;

}