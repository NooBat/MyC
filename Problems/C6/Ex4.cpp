#include<stack>
#include<string>
#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

// Grammar for this language:
// L = {s$s' : s is a possibly empty string of characters other than $, s' = reverse(s)}

vector<string> tokenize(string filename) {
    ifstream myfile(filename);
    string temp;
    vector<string> result;

    if (myfile.is_open()) {
        while (getline(myfile, temp)) {
            if (temp == "DONE") return result;
            result.push_back(temp);
        }
    }

    return result;
}

bool checkLanguage(const string& L) {
    stack<char> st;
    int i;
    for (i = 0; i < L.length() && L[i] != '$'; i++) {
        st.push(L[i]);
    }

    i++;    //skip the $

    for (; i < L.length(); i++) {
        if (st.top() != L[i] || L[i] == '$') return false;
        st.pop();
    }

    if (!st.empty()) return false;
    return true;
}

int main() {
    string filename = "/Users/danielnguyen/Repo/C++/Problems/C6/Ex4.txt";

    vector<string> instruction = tokenize(filename);

    for (int i = 0; i < instruction.size(); i++) {
        cout << checkLanguage(instruction[i]) << endl;
    }

    return 0;
}