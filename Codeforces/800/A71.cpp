#include<bits/stdc++.h>

using namespace std;

int main() {
    int times;

    cin >> times;
    cin.ignore();

    while (times--) {
        string w;
        
        getline(cin, w);

        if (w.length() > 10) {
            string newWord = w[0] + to_string(w.length() - 2) + w[w.length() - 1];
            cout << newWord << endl;
        } else {
            cout << w << endl;
        }
    }

    return 0;
}