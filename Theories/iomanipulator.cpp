#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

    cout << "Kteam Solutions and Entertainment" << endl;
    cout << "HowKteam.com" << endl;
    
    //độ rộng 5 kí tự, ID canh trái
    cout << setw(5) << left << "ID";
    //độ rộng 30 kí tự, Name canh trái
    cout << setw(30) << left << "Name";
    //độ rộng 20 kí tự, Address canh phải
    cout << setw(20) << right << "Address" << "\n";
    //độ rộng trên cùng 1 dòng cộng dồn với nhau
    //set fill bằng kí tự '-' thay vì ' '
    cout << setfill('-');
    //fill 55 kí tự '-'
    cout << setw(55) << "-" << endl;
    //reset fill bằng kí tự ' '
    cout << setfill(' ');

    cout << setw(5) << left << "1";
    cout << setw(30) << left << "Nguyen Tran Khoi";
    cout << setw(20) << right << "Thanh pho Ho Chi Minh" << "\n";

    cout << setw(5) << left << "2";
    cout << setw(30) << left << "Tran Van A";
    cout << setw(20) << right << "Da Lat" << "\n";

    return 0;
}