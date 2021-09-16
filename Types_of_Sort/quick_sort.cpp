#include<iostream>

using namespace std;
//quick sort:
// - a "divide and conquer" algorithm
// - pick an element as a pivot
// - partition the array around picked pivot 
// - target of partition is put the picked pivot in the correct position
// - put smaller elements to the left side of the pivot and other to the right side

template<class ItemType>
void insertionSort(ItemType arr[], int n) 
{
    for (int unsorted = 1; unsorted < n; unsorted++) 
    {
        ItemType nextItem = arr[unsorted];
        int loc = unsorted;

        while (loc > 0 && arr[loc - 1] > nextItem) 
        {
            arr[loc] = arr[loc - 1];
            loc--;
        }

        arr[loc] = nextItem;
    }
}

template<class ItemType>
class QuickSort 
{
private:
    void sortFirstMiddleLast(ItemType arr[], int first, int mid, int last);
    int partition(ItemType arr[], int first, int last);
public:
    void quickSort(ItemType arr[], int first, int last);
};

template<class ItemType>
void QuickSort<ItemType>::sortFirstMiddleLast(ItemType arr[], int first, int mid, int last) 
{
    if (arr[first] > arr[mid]) 
    {
        swap(arr[first], arr[mid]);
    }

    if (arr[mid] > arr[last]) 
    {
        swap(arr[mid], arr[last]);
    }

    if (arr[first] > arr[mid]) 
    {
        swap(arr[first], arr[mid]);
    }
}

template<class ItemType>
int QuickSort<ItemType>::partition(ItemType arr[], int first, int last) 
{
    int mid = first + (last - first) / 2;

    sortFirstMiddleLast(arr, first, mid, last);
    swap(arr[mid], arr[last - 1]);

    int pivotIdx = last - 1;
    ItemType pivot = arr[last - 1];

    int indexFromLeft = first + 1;
    int indexFromRight = last - 2;

    bool done = false;

    while (!done) 
    {
        while (arr[indexFromLeft] < pivot) 
        {
            indexFromLeft++;
        }

        while (arr[indexFromRight] > pivot) 
        {
            indexFromRight--;
        }

        if (indexFromLeft < indexFromRight) 
        {
            swap(arr[indexFromLeft], arr[indexFromRight]);
            indexFromLeft++;
            indexFromRight--;
        }
        else done = true;
    }

    swap(arr[pivotIdx], arr[indexFromLeft]);
    pivotIdx = indexFromLeft;

    return pivotIdx;
}   

template<class ItemType>
void QuickSort<ItemType>::quickSort(ItemType arr[], int first, int last) 
{   
    if (first >= last) return;
    if (last - first + 1 <= 3) 
    {
        insertionSort(arr, last - first + 1);
        return;
    }

    int pivotIdx = partition(arr, first, last);

    quickSort(arr, first, pivotIdx - 1);

    quickSort(arr, pivotIdx + 1, last);
}

int partition(int arr[], int l, int r) {
    int pivot = arr[r];

    int i = l - 1;

    for (int j = l; j < r; j++) {
        //If current element smaller than pivot 
        if (arr[j] < pivot) {
            i += 1; //increase index of smaller element
            swap(arr[i], arr[j]); 
        } 
    }
    swap(arr[i + 1], arr[r]);
    return (i + 1);
}

void quick_sort(int arr[], int l, int r) {
    if (l >= r) return;

    int pi = partition(arr, l, r);
    quick_sort(arr, l, pi - 1);
    quick_sort(arr, pi + 1, r);
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {9, 10, 1983, 129, 1992, 12041, 12388, 28, 29, -129, 129, 121848, 28, 283, 221, 393, 4, 3, 0, 0, 445, 567};

    int size = (int)(sizeof(arr) / sizeof(arr[0]));

    QuickSort<int> sortFunc;

    sortFunc.quickSort(arr, 0, size - 1);

    print_array(arr, size);
    
    return 0;
}