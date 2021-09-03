#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<sstream>
#include<regex>
#include<cmath>
#include<algorithm>
#include<fstream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>::iterator it1 = numbers.begin();
        vector<int>::iterator it2 = numbers.end() - 1;
        vector<int> result;
        
        while (it1 != it2) {
            int sum = *it1 + *it2;
            
            if (sum == target) {
                result.push_back(it1 - numbers.begin());
                result.push_back(it2 - numbers.begin());
                break;
            }
            else if (sum > target) {
                it2--;
            }
            else it1++;
        }
        
        return result;
    }
};

int main() {
    // string filename = "/Users/danielnguyen/Repo/C++/Assignment1-2/testcase/test1.txt";
    // ifstream myfile(filename);
    // string tmp;
    // if (myfile.is_open()) {
    //     while (getline(myfile, tmp)) {
    //         cout << checkValid(tmp) << " ";
    //     } 
    // }
    // string a = " \'a b c\'";
    // int start = 0;
    // int end = (int)a.find(" ");

    // while (end != -1) {
    //     start = (int)end + 1;
    //     if (a[start] != '\'') end = (int)a.find(" ", start);
    //     else {
    //         end = (int)a.find("\'", start + 1);
    //         cout << start << " " << end;
    //     }
    // }
    Solution obj;

    int target = 9;
    vector<int> v;
    v.push_back(2);
    v.push_back(5);
    v.push_back(7);

    obj.twoSum(v, target);
	return 0;
}
