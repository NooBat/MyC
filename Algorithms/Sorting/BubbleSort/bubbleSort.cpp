#include<bits/stdc++.h>

using namespace std;

template<class T>
class BubbleSort {
public:
    void bubbleSort(T arr[], int n) {
        for (int step = 0; step < n; step++) {
            for (int i = 0; i < n - step; i++) {
                if (arr[i] < arr[i + 1]) swap(arr[i], arr[i + 1]);
            }
        }
    }
};

int main() {
    int arr[] = {0, 1, 2, 3, 4, 5};

    cout << arr << endl;

    return 0;
}