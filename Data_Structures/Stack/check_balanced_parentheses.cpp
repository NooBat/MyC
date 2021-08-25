#include<iostream>
#include<stack>
#include<string>

using namespace std;

char checkBalanced(stack<char> s) {
    char result;

    int count1 = 0; //counts number of ()
    int count2 = 0; //counts number of []
    int count3 = 0; //counts number of {}

    while (!s.empty()) {
        switch(s.top()) {
        case '(':
            ++count1;
            break;
        case ')':
            --count1;
            break;
        case '[':
            ++count2;
            break;
        case ']':
            --count2;
            break;
        case '{':
            ++count3;
            break;
        case '}':
            --count3;
            break;
        }
        s.pop();
    }
    if (count1 == 0 && count2 == 0 && count3 == 0) {
        result = '0';
        return result;
    }
    
    if (count1 < 0) return '(';
    else return ')';

    if (count2 < 0) return '[';
    else return ']';

    if (count3 < 0) return '{';
    else return '}';
}

int main() {
    string str;
    cout << "Nhập chuỗi: ";
    getline(cin, str);

    stack<char> s;

    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }
    
    char check = checkBalanced(s);

    if (check == '0') {
        cout << "Chuỗi có đủ ngoặc." << endl;
    }
    else cout << "Chuỗi thiếu ngoặc " << check << "." << endl;

    return 0;
}