#include <iostream>
using namespace std;

//biến được định nghĩa ngoài khối lệnh là biến toàn cục, thêm 'g_' trước biến để phân biệt
int g_x;
int g_y(2);
void doSomething()
{
    g_x = 3;
    cout << g_y << endl;
    cout << g_x << endl;
} 
int main()
{
    doSomething();

    g_x = 5;
    cout << g_y << endl;
    cout << g_x << endl;

    return 0;
}
