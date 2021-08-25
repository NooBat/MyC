#include <iostream>
using namespace std;

int main() 
{
    int n(6); //biến n được khởi tạo tại đây
    double d(9.0); //biến d được khởi tạo tại đây

    cout << "Enter a value for n: ";
    cin >> n;
    cout << "You entered: " << n << endl;

    return 0;
} //n và d đã ra khỏi tầm vực và bị huỷ tại đây
////////////////////////////////////////////////////////////////////////////
// ở đây n và d là 2 biến cục bộ, được tạo ra khi tại thời điểm định nghĩa 
//và bị huỷ khi ra khỏi khối lệnh mà biến đó được định nghĩa