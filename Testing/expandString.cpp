#include<iostream>
#include<string>

using namespace std;

string expand(string s) {
    string t;
    string temp;
    int i = 0;
    for (; i < s.length(); i++) {
        if (s[i] != ')') {
            temp.push_back(s[i]);
        }
        else {
            for (int j = temp.length() - 1; j >= 0; j--) {
                if (temp[j] == '(') {
                    if (temp[j - 1] == '0') {
                        temp.erase(j - 1, temp.length());
                        break;
                    }
                    else if (temp[j - 1] >= '1' && temp[j - 1] <= '9'){
                        for (int x = 1; x <= temp[j - 1] - '0'; x++) {
                            t = temp.substr(j + 1, temp.length() - 1 - j) + t;
                        }
                    }
                    temp.erase(j - 1, temp.length());
                    temp += t;
                    t.clear();
                    break;
                }
            }   
        }
    }

    return temp;
}

int main() {
    string s = "0(x)";
    cout << expand(s);

    return 0;
}