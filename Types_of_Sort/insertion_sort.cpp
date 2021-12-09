#ifndef _INSERTION_SORT
#define _INSERTION_SORT
#include<iostream>

using namespace std;
//insertion sort:
// - iterate from arr[1] to arr[n - 1]
// - compare the current element (key) to its predecessor
// - if key <= predecessor, compare key to the elements before
// - move the greater elements one position up to make space    4 5 1 3 2 

template<class T>
class InsertionSort 
{
private:
    int comparisonCounter;

public:
    InsertionSort();
    void insertionSort(T arr[], int n);
    int getComparison() const;
};

template<class T>
InsertionSort<T>::InsertionSort()
{
    comparisonCounter = 0;
}

template<class T>
void InsertionSort<T>::insertionSort(T arr[], int n) 
{
    for (int unsorted = 1; unsorted < n; unsorted++) 
    {
        T nextItem = arr[unsorted];
        int loc = unsorted;

        while (loc > 0 && arr[loc - 1] > nextItem) {
            comparisonCounter += 2;
            arr[loc] = arr[loc - 1];
            loc--;
        }

        arr[loc] = nextItem;
    }
}

template<class T>
int InsertionSort<T>::getComparison() const 
{
    return comparisonCounter;
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {29, 28, 27, 26, 25, 24, 23};

    int size = (int)(sizeof(arr) / sizeof(arr[0]));

    InsertionSort<int> s;

    s.insertionSort(arr, size);

    cout << s.getComparison() << endl;

    print_array(arr, size);
    
    return 0;
}
#endif