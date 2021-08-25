#include<iostream>
#include<string>

using namespace std;

/** Writes the string backward
 * @param string needed to be written backward 
 * @post NONE */
void writeBackward2(string s) {
    if (s.length() == 0) return;
    writeBackward2(s.substr(1, s.length() - 1));
    cout << s[0];
}

int main() {
    string str;

    getline(cin, str);

    writeBackward2(str);

    return 0;
}