#include <iostream>
using namespace std;

int main()
{

    int n{ 0 };
    
    //thông báo user nhập tuổi
    cout << "Enter your age: ";

    //đọc giá trị từ console và lưu vào biến n
    cin >> n;

    //in giá trị biến n (tuổi) lên màn hình
    cout << "Your age: " << n << endl;

    return 0; 
}