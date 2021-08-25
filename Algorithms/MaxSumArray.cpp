#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int MaximumSumArray1(int arr[], int n) {
        int Max = arr[0];
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += arr[k];
                }
                Max = max(Max, sum);
            }
        }
        return Max;
    }
    int MaximumSumArray2(int arr[], int n) {
        int Max = arr[0];
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                Max = max(sum, Max);
            }
        }
        return Max;
    }
    int MaximumSumArray3(int arr[], int n) {    //Kadane's algorithm
        int Max = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum = max(arr[i], sum + arr[i]);
            Max = max(Max, sum);
        }
        
        return Max;
    }
};

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Solution obj;
    cout << obj.MaximumSumArray3(arr, n);

    return 0;
}