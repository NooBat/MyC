#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    int x = 0;
    
    for (int i = 0; i < n; i++) {
        string cmd;
        getline(cin, cmd);

        if (cmd.substr(0, 2) == "++" || cmd.substr(1, 2) == "++") {
            x += 1;
        } else {
            x -= 1;
        }
    }

    cout << x << endl;

    return 0;
}