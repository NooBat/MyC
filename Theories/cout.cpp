//sử dụng cout
//lệnh include <iostream> để thêm file iostream vào mã nguồn, để sử dụng cout và những thứ liên quan đến cout
#include <iostream>
int main()
{
    //lệnh \n là để tạo ra 1 dòng mới trên màn hình và đưa con trỏ xuống dòng đó
    cout << "Hello there.\n";
    //lệnh \n luôn nằm trong 2 dấu ngoặc kép ""
    cout << "Here is 5: " << 5 << "\n";
    //lệnh endl có chức năng giống \n nhưng trong các chương trình lớn, \n dùng tốt hơn endl
    cout << "The manipulator endl ";
    cout << "writes a new line to the screen.";
    cout << endl;
    //lệnh \t cho 1 khoảng Tab như khi ấn Tab
    cout << "Here is a very big number:\t" << 70000;
    cout << endl;
    cout << "Here is the sum of 8 and 5:\t";
    cout << 8 + 5 << endl;
    cout << "Here is a fraction:\t\t";
    //(float) để chương trình coi 5/8 là một số thập phân
    cout << (float) 5/8 << endl;
    cout << "And a very very big number:\t";
    cout << (double) 7000 * 7000 << endl;
    cout << "Don't forget to replace Jesse Liberty ";
    cout << "with your name Nguyễn Trần Khôi\n";
    cout << "Nguyễn Trần Khôi is a C++ programmer!\n";
    return 0;
}