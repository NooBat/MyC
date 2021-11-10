#ifndef _BUBBLE_SORT
#define _BUBBLE_SORT
#include<iostream>

using namespace std;
//bubble sort:
// - continuosly swap adjacent elements if they are in the wrong order

// - best case time complexity: O(n) when the array is already sorted
// - worst case time complexity: O(n ^ 2) when the array is reverse sorted
// - auxiliary space: O(1)

template<class T>
class BubbleSort
{
public:
    void bubbleSort(T arr[], int n);
};

template<class T>
void BubbleSort<T>::bubbleSort(T arr[], int n) 
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i]) swap(arr[j], arr[i]);
        }
    }
}

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) {
                swap(arr[i], arr[j]); //swap if the next element is smaller 
                                      //until it is in the correct order
            }
        }
    }
}

// // int main() {
//     int T, n, arr[1000];
    
//     cout << "Input number of testcase(s): ";
//     cin >> T;

//     while(T--) {
//         cout << "Testcase: " << T << endl;
//         cout << "Input number of element(s): ";
//         cin >> n;
        
//         cout << "Input array value(s): ";
//         for (int i = 0; i < n; i++) {
//             cin >> arr[i];
//         }

//         cout << "Array before sort: ";
//         print_array(arr, n);

//         bubble_sort(arr, n);
//         cout << "Array after sort: ";
//         print_array(arr, n);
//     }
    
//     return 0;
// }
#endif