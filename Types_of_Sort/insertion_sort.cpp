#include<iostream>

using namespace std;
//insertion sort:
// - iterate from arr[1] to arr[n - 1]
// - compare the current element (key) to its predecessor
// - if key <= predecessor, compare key to the elements before
// - move the greater elements one position up to make space    4 5 1 3 2 

template<class ItemType>
void insertionSort(ItemType arr[], int n) 
{
    for (int unsorted = 1; unsorted < n; unsorted++) 
    {
        ItemType nextItem = arr[unsorted];
        int loc = unsorted;

        while (loc > 0 && arr[loc - 1] > nextItem) {
            arr[loc] = arr[loc - 1];
            loc--;
        }

        arr[loc] = nextItem;
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {29, 34, 10, 10, 13, 14};

    int size = (int)(sizeof(arr) / sizeof(arr[0]));

    insertionSort(arr, size);

    print_array(arr, size);
    
    return 0;
}