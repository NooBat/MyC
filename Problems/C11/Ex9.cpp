#include "/Users/danielnguyen/Repo/C++/Types_of_Sort/radix_sort.cpp"
#include "/Users/danielnguyen/Repo/C++/Types_of_Sort/selection_sort.cpp"
#include "/Users/danielnguyen/Repo/C++/Types_of_Sort/bubble_sort.cpp"
#include "/Users/danielnguyen/Repo/C++/Types_of_Sort/insertion_sort.cpp"
#include "/Users/danielnguyen/Repo/C++/Types_of_Sort/merge_sort.cpp"
#include "/Users/danielnguyen/Repo/C++/Types_of_Sort/quick_sort.cpp"

#include<ctime>

using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void copyArray(int originArr[], int copyArr[], int size)
{
    for (int i = 0; i < size; i++)
    {   
        copyArr[i] = originArr[i];
    }
}

int main()
{
    int size;

    srand(time(0));

    cin >> size;

    int arr1[size];

    for (int i = 0; i < size; i++)
    {
        arr1[i] = rand() % 1000;
    }

    cout << "Array has " << size << " elements: ";
    printArray(arr1, size);

    int arr2[size];
    int arr3[size];
    int arr4[size];
    int arr5[size];
    int arr6[size];

    copyArray(arr1, arr2, size);
    copyArray(arr1, arr3, size);
    copyArray(arr1, arr4, size);
    copyArray(arr1, arr5, size);
    copyArray(arr1, arr6, size);

    RadixSort<int> sort1;
    InsertionSort<int> sort3;
    BubbleSort<int> sort4;
    MergeSort<int> sort5;
    QuickSort<int> sort6;
    
    clock_t start1 = clock();
    sort1.radixSort(arr1, size);
    clock_t end1 = clock();
    double overallTime1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC;

    clock_t start2 = clock();
    selectionSort1(arr2, size);
    clock_t end2 = clock();
    double overallTime2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC;

    clock_t start3 = clock();
    sort3.insertionSort(arr3, size);
    clock_t end3 = clock();
    double overallTime3 = static_cast<double>(end3 - start3) / CLOCKS_PER_SEC;

    clock_t start4 = clock();
    sort4.bubbleSort(arr4, size);
    clock_t end4 = clock();
    double overallTime4 = static_cast<double>(end4 - start4) / CLOCKS_PER_SEC;

    clock_t start5 = clock();
    sort5.mergeSort(arr5, 0, size - 1);
    clock_t end5 = clock();
    double overallTime5 = static_cast<double>(end5 - start5) / CLOCKS_PER_SEC;

    clock_t start6 = clock();
    sort6.quickSort(arr6, 0, size - 1);
    clock_t end6 = clock();
    double overallTime6 = static_cast<double>(end6 - start6) / CLOCKS_PER_SEC;

    cout << "Radix Sort takes: " << overallTime1 << endl;
    cout << "Selection Sort takes: " << overallTime2 << endl;
    cout << "Insertion Sort takes: " << overallTime3 << endl;
    cout << "Bubble Sort takes: " << overallTime4 << endl;
    cout << "Merge Sort takes: " << overallTime5 << endl;
    cout << "Quick Sort takes: " << overallTime6 << endl;

    return 0;
}