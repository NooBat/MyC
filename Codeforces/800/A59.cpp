#include<bits/stdc++.h>

using namespace std;

int main() {
    string word;
    getline(cin, word);

    int lower = 0, upper = 0;

    for (int i = 0; i < word.length(); i++) {
        if (word[i] >= 'a' && word[i] <= 'z') {
            lower++;
        } else if (word[i] >= 'A' && word[i] <= 'Z') {
            upper++;
        }
    }

    if (lower >= upper) {
        for (int i = 0; i < word.length(); i++) {
            if (word[i] >= 'A' && word[i] <= 'Z') {
                word[i] += 32;
            }
        }
    } else {
        for (int i = 0; i < word.length(); i++) {
            if (word[i] >= 'a' && word[i] <= 'z') {
                word[i] -= 32;
            }
        }
    }

    cout << word << endl;

    return 0;
}