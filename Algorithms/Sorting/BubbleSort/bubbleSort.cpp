#include <bits/stdc++.h>
#include "../../../arrayPrinter.hpp"

using namespace std;

template<class T>
class BubbleSort {
public:
    void bubbleSort(T arr[], int n) {
        for (int step = 0; step < n; step++) {
            for (int i = 0; i < n - 1; i++) {
                if (arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
            }
        }
    }
};

int main() {
    int arr[] = {19, 12, 4, 133, 200};
    int size = sizeof(arr) / sizeof(arr[0]);

    printArr<int>(arr, size);

    BubbleSort<int> sorter;

    sorter.bubbleSort(arr, size);

    printArr<int>(arr, size);

    return 0;
}