#include "/Users/danielnguyen/Documents/Code/C++/Data_Structures/Heap.cpp"
#include<bits/stdc++.h>

using namespace std;

void HeapSort1(int *arr, int n) {
    MinHeap h = MinHeap(n);
    for (int i = 0; i < n; i++) {
        h.Insert(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        arr[i] = h.extractMin();
    } 
}

void HeapSort2(int *arr, int n) {
    MaxHeap h = MaxHeap(n);

    for (int i = 0; i < n; i++) {
        h.Insert(arr[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
        arr[i] = h.extractMax();
    }
}

void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    HeapSort2(arr, n);

    printArray(arr, n);

    return 0;
}