#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<cmath>
#include<algorithm>

using namespace std;

class Solution {
private:
    int getSmallestSize(vector<string>& strs) {
        int min = strs[0].length();
        for (int i = 1; i < strs.size(); i++) {
            if (strs[i].length() < min) {
                min = strs[i].length();
            }
        }
        
        return min;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        int n = getSmallestSize(strs);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < strs.size() - 1; j++) {
                if (strs[j][i] != strs[j + 1][i]) {
                    if (result.length() < 2)
                    return "";
                }
            }
            result += strs[0][i];
        }
        
        return result;
    }
};

int main() {  
    vector<string> strs;
    strs.push_back("flower");
    strs.push_back("flow");
    strs.push_back("flight");
    Solution obj;

    cout << obj.longestCommonPrefix(strs);
    // cout << obj.reverse(a);

    return 0;
}
