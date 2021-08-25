#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int binarySearch(int *arr, int left, int right, int key) {
        if (left > right) return -1;

        int mid = (left + right) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] > key) return binarySearch(arr, left, mid - 1, key);
        else return binarySearch(arr, mid + 1, right, key);

        return -1;
    }
public:
    void findSubarray1(int *arr, int n, int givenSum) {
        int *temp = new int[n];
        temp[0] = arr[0];
        for (int i = 1; i < n; i++) {
            temp[i] = arr[i] + temp[i - 1];
        }

        int i, j;

        for (i = 0; i < n; i++) {
            int match = temp[i] - givenSum;
            if (match == 0) {
                j = 0;
                break;
            }
            else if (match > 0) {
                j = binarySearch(temp, 0, i - 1, match);
                if (j != -1) {
                    j++;
                    break;
                }
            } 
        }
        if (j == -1) {
            cout << "-1";
            return;
        }

        for (; j <= i; j++) {
            cout << arr[j] << " ";
        }
    }

    void findSubarray2(int *arr, int n, int givenSum) {
        int curr_sum = arr[0];
        int start = 0;

        for (int i = 1; i < n; i++) {
            while (curr_sum > givenSum && start < i - 1) {
                curr_sum -= arr[start];
                start++;
            }

            if (curr_sum == givenSum) {
                for (; start < i; start++) {
                    cout << arr[start] << " ";
                }

                return;
            }

            if (i < n) {
                curr_sum += arr[i];
            }
        }

        cout << "-1";
    }
};

int main() {
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int givenSum;
    cin >> givenSum;

    Solution obj;
    obj.findSubarray2(arr, n, givenSum);

    return 0;
}