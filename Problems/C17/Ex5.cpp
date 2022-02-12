#include<iostream>
#include<stdexcept>
#include<string>
#include "../../ADT/Heap/MinHeap/ArrayMinHeap.hpp"
#include "../../ADT/Heap/MinHeap/ArrayMinHeap.cpp"

using namespace std;

template<class T>
T kSmallestValue(T arr[], int size, int k) {
    if (k >= size) {
        throw out_of_range("k (value = " + to_string(k) + ") is larger than size (value = " + to_string(size) + ")");
    }

    ArrayMinHeap<T> heap(arr, size);
    T result;
    for (int i = 0; i < k; i++) {
        result = heap.peekTop();
        heap.remove();       
    }

    return result;
}

int main() {
    int arr[] = {10, 29, 19, 1002, 282, 12, 3, 40};

    int size = sizeof(arr) / sizeof(arr[0]);

    int k;
    cout << "Input the desired k: ";
    cin >> k;

    cout << "The k-th smallest value in the array is: " << kSmallestValue(arr, size, k) << endl;

    return 0;
}