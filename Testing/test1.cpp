#include<bits/stdc++.h>

using namespace std;

int minimumAmplitude1(vector<int>& nums, int k)
{
    vector<int> maxL(nums.size(), INT_MIN);
    vector<int> minL(nums.size(), INT_MAX);

    maxL[0] = nums[0];
    minL[0] = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        maxL[i] = max(nums[i], maxL[i - 1]);
        minL[i] = min(nums[i], minL[i - 1]);
    }

    vector<int> maxR(nums.size(), INT_MIN);
    vector<int> minR(nums.size(), INT_MAX);

    maxR[nums.size() - 1] = nums[nums.size() - 1];
    minR[nums.size() - 1] = nums[nums.size() - 1];

    for (int i = nums.size() - 2; i >= 0; i--)
    {
        maxR[i] = max(nums[i], maxR[i + 1]);
        minR[i] = min(nums[i], minR[i + 1]);
    }

    int result = INT_MAX;

    for (int i = 0; i < nums.size() - k + 1; i++)
    {
        int Max = INT_MIN;
        int Min = INT_MAX;

        Max = max(Max, maxL[i]);
        Min = min(Min, minL[i]);

        if (i + k < nums.size())
        {
            Max = max(Max, maxR[i + k]);
            Min = min(Min, minR[i + k]);
        }

        result = min(result, Max - Min);
    }

    return result;
}

int minimumAmplitude2(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> maxR(n,-2147483648), minR(n, 2147483647);
    vector<int> maxL(n, -2147483648), minL(n, 2147483647);
    maxR[n - 1] = nums[n - 1];
    minR[n - 1] = nums[n - 1];
    maxL[0] = nums[0];
    minL[0] = nums[0];
    // computing min and max values to the left
    for (int i = 1; i < n; ++i) {
        maxL[i] = max(nums[i], maxL[i - 1]);
        minL[i] = min(nums[i], minL[i - 1]);
    }
    // computing min and max values to the right
    for (int i = n - 2; i >= 0; --i) {
        maxR[i] = max(nums[i], maxR[i + 1]);
        minR[i] = min(nums[i], minR[i + 1]);
    }
    int res = 2147483647;
    for (int i = 0; i + k - 1 < n; i++) {
        int Min = 2147483647, Max = -2147483648;
        if (i - 1 >= 0) 
        {
            Min = min(Min, minL[i - 1]);
            Max = max(Max, maxL[i - 1]);
        }
        if (i + k < n) 
        {
            Min = min(Min, minR[i + k]);
            Max = max(Max, maxR[i + k]);
        }
        res = min(res, Max - Min);
    }

    return res;
}

int main()
{
    srand(time(NULL));

    int size = 10000;

    int k = rand() % (size / (rand() % 9990)) + 1;
    cout << k << endl;

    vector<int> v;

    for (int i = 0; i < size; i++)
    {
        v.push_back(rand() % 9999);
    }

    cout << minimumAmplitude1(v, k) << endl;
    cout << minimumAmplitude2(v, k) << endl;

    return 0;
}