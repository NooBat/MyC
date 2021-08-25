#ifndef HEAP_CPP
#define HEAP_CPP

#include<bits/stdc++.h>

using namespace std;

class MinHeap {
private:
    int *heap_array;
    //maximum numbers of nodes in 1 heap
    int capacity;
    //current numbers of nodes in 1 heap
    int heap_size;
public:
    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    int getMin() {
        return heap_array[0];
    }

    MinHeap() {
        heap_array = new int[0];
    }

    MinHeap(int cap) {
        if (cap == 0) {
            cap = 1;
        }

        heap_array = new int[cap];

        heap_size = 0;
        capacity = cap;
    }

    void MinHeapify(int index) {
        int leftIndex = left(index);
        int rightIndex = right(index);
        int indexOfMin = index;

        if (leftIndex >= heap_size) return;

        if (leftIndex < heap_size && heap_array[leftIndex] < heap_array[index]) {
            indexOfMin = leftIndex;
        }
        if (rightIndex < heap_size && heap_array[rightIndex] < heap_array[indexOfMin]) {
            indexOfMin = rightIndex;
        }

        if (indexOfMin != index) {
            swap(heap_array[indexOfMin], heap_array[index]);
            MinHeapify(indexOfMin);
        }
    }

    void Insert(int data) {
        if (heap_size == capacity) {
            throw invalid_argument("Heap overflow!\n");
        }
        heap_size++;

        int i = heap_size - 1;

        heap_array[i] = data;

        while (i >= 0 && data < heap_array[parent(i)]) {
            swap(heap_array[i], heap_array[parent(i)]);
            i = parent(i);
        }
    }

    void Delete(int index) {
        if (index >= heap_size) {
            throw invalid_argument("Out of bound!\n");
        }

        decrease(index, INT_MIN);

        extractMin();
    }

    void decrease(int index, int data) {
        if (data > heap_array[index]) {
            throw invalid_argument("");
        }
        else if (data == heap_array[index]) return;
        
        heap_array[index] = data;

        while (index > 0 && heap_array[index] < heap_array[parent(index)]) {
            swap(heap_array[index], heap_array[parent(index)]);
            index = parent(index);
        }
    }

    int extractMin() {
        if (heap_size == 0) throw invalid_argument("Heap is empty!\n");
        else if (heap_size == 1) {
            heap_size--;
            return heap_array[0];
        }

        int min = heap_array[0];

        heap_array[0] = heap_array[heap_size - 1];
        heap_size--;
        MinHeapify(0);

        return min;
    }

    void printHeap() {
        if (heap_size == 0) {
            cout << "[]" << endl;
            return;
        }
        cout << "["; 
        for (int i = 0; i < heap_size - 1; i++) {
            cout << heap_array[i] << ", ";
        }

        cout << heap_array[heap_size - 1] << "]";
        cout << endl;
    }
};

class MaxHeap {
private:
    int *heap_array;
    int heap_size;
    int capacity;
public:
    MaxHeap() {
        heap_array = new int[0];
        heap_size = 0;
        capacity = 0;
    }

    MaxHeap(int cap) {
        if (cap == 0) cap = 1;

        heap_array = new int[cap];
        heap_size = 0;
        capacity = cap;
    }

    int getParentIndex(int index) {
        if (index == 0) throw invalid_argument("This has no parent!\n");
        return (index - 1) / 2;
    }

    int getLeftIndex(int index) {
        return index * 2 + 1;
    }

    int getRightIndex(int index) {
        return index * 2 + 2;
    }

    int getMax() {
        return heap_array[0];
    }

    void MaxHeapify(int index) {
        int leftIndex = getLeftIndex(index);
        int rightIndex = getRightIndex(index);
        int indexOfMin = index;

        if (leftIndex >= heap_size) return;

        if (leftIndex < heap_size && heap_array[leftIndex] > heap_array[index]) {
            indexOfMin = leftIndex;
        }
        if (rightIndex < heap_size && heap_array[rightIndex] > heap_array[indexOfMin]) {
            indexOfMin = rightIndex;
        }

        if (indexOfMin != index) {
            swap(heap_array[indexOfMin], heap_array[index]);
            MaxHeapify(indexOfMin);
        }
    }

    void Insert(int data) {
        if (heap_size == capacity) {
            throw invalid_argument("Overflow!\n");
        }
        heap_size++;
        int i = heap_size - 1;

        heap_array[i] = data;

        while (i > 0 && heap_array[i] > heap_array[getParentIndex(i)]) {
            swap(heap_array[i], heap_array[getParentIndex(i)]);
            i = getParentIndex(i);
        }
    }

    void increase(int index, int data) {
        if (index >= heap_size) {
            throw invalid_argument("Out of bound\n");
        }
        if (heap_array[index] >= data) {
            throw invalid_argument("New data must be larger than current node ");
        }
        
        heap_array[index] = data;
        while (index > 0 && heap_array[index] > heap_array[getParentIndex(index)]) {
            swap(heap_array[index], heap_array[getParentIndex(index)]);
            index = getParentIndex(index);
        }
    }

    int extractMax() {
        if (heap_size == 0) {
            throw invalid_argument("Heap is empty!\n");
        }
        else if (heap_size == 1) {
            heap_size--;
            return heap_array[0];
        }

        int Max = heap_array[0];

        heap_size--;
        heap_array[0] = heap_array[heap_size];
        
        MaxHeapify(0);

        return Max;
    }

    void Delete(int index) {
        if (index >= heap_size) {
            throw invalid_argument("Out of bound!\n");
        }
        increase(index, INT_MAX);
        extractMax();
    }

    void printHeap() {
        if (heap_size == 0) {
            cout << "[]" << endl;
            return;
        }
        cout << "["; 
        for (int i = 0; i < heap_size - 1; i++) {
            cout << heap_array[i] << ", ";
        }

        cout << heap_array[heap_size - 1] << "]";
        cout << endl;
    }
};
#endif

// int main()
// {
//     MaxHeap h(10);
//     h.Insert(3);
//     h.Insert(2);
//     h.Delete(1);
//     h.Insert(15);
//     h.Insert(5);
//     h.Insert(4);
//     h.Insert(45);
//     cout << h.extractMax() << " ";
//     cout << h.getMax() << " ";
//     h.increase(3, 1000);
//     cout << h.getMax() << endl;
//     h.printHeap();
//     return 0;
// }
