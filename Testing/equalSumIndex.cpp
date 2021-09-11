#include<vector>
#include<iostream>

using namespace std;

bool recursive(vector<int> nums, vector<int>::iterator& i1, vector<int>::iterator& i2, int sumLeft, int sumRight) {
    if (i1 >= i2) {
        if (sumLeft == sumRight) return true;
        else return false;
    }
    if (sumLeft == sumRight) {
        sumLeft += *i1;
        i1++;
        sumRight += *i2;
        i2--;
    }
    else if (sumLeft > sumRight) {
        sumRight += *i2;
        i2--;
    }
    else {
        sumLeft += *i1;
        i1++;
    }

    return recursive(nums, i1, i2, sumLeft, sumRight);
}

int equalSumIndex(vector<int>& nums) {
    vector<int>::iterator i1 = nums.begin();
    vector<int>::iterator i2 = nums.end() - 1;

    int sumLeft = 0;
    int sumRight = 0;
    bool success = recursive(nums, i1, i2, sumLeft, sumRight);

    int result = i1 - nums.begin();

    if (success) return result;
    return -1;
}

int main() {
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(5);
    // nums.push_back(3);
    // nums.push_back(7);
    // nums.push_back(4);
    // nums.push_back(6);

    cout << equalSumIndex(nums);

    return 0;
}