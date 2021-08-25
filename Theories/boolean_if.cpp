//////////////////////////////////////////////////////
// - If thiếu:                                      //
//  if (condition)    (nếu condition là true        //
//          statement;  thì thực thi câu lệnh này)  //
// - If đủ:                                         //
//  if (condition)    (nếu condition là true        //
//          statement1; thì thực thi câu lệnh này)  //
//  else              (nếu condition là false       //
//          statement2; thì thực thi câu lệnh này)  //
//////////////////////////////////////////////////////
#include <iostream>
using namespace std;

int main()
{

    bool b1(true);
    if (b1)
            cout << "b1 is true" << endl;
    else 
            cout << "b1 is false" << endl;

    bool b2{ false };
    if (b2)
            cout << "b2 is true" << endl;
    else
            cout << "b2 is false" << endl;

    return 0;
    
}