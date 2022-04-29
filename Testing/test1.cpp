#include<bits/stdc++.h>

class Solution {
private:
    bool isPalindrome(string s) {
        if (s.length() <= 1) return true;
        
        for (int i = 0; i < s.length() / 2; i++) {
            if (s[i] != s[s.length() - i - 1]) return false;
        }
        
        return true;
    }
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) return s;
        
        int maxLength = 1;
        string res;
        
        for (int i = 1; i < s.length() - 1; i++) {
            string temp = s.substr(i, 1);
            for (int j = i - 1, k = i + 1; j >= 0 && k < s.length(); j--, k++) {
                temp = s.substr(j, 1) + temp + s.substr(k, 1);
                
                if (!isPalindrome(temp)) {
                    break;
                } else {
                    if (temp.length() > maxLength) {
                        maxLength = temp.length();
                        res = temp;
                    }            
                }
            }
        }
        
        return res;
    }
};

int main() {
    string s = "cbbd";

    Solution solve;

    cout << solve.longestPalindrome(s);

    return 0;
}