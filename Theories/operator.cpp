#include <iostream>
using namespace std;

int main()
{
    //chương trình đếm các số tự nhiên chẵn để in ra màn hình
    //số bắt đầu là 1
    int count = 1;
    //loop sẽ tiếp tục cho đến khi đạt số 100
    while (count <= 100)
    {
        //nếu số đếm chia hết cho 2 thì in ra màn hình
        if (count % 2 == 0)
        cout << count << "\t";
        //nếu số đếm chia hết cho 20 thì xuống dòng mới
        if (count % 10 == 0)
        cout << "\n";
        //chuyển sang số tiếp theo
        count =  count + 1;
    }
    //hàm while kết thúc
    return 0;
}