#include "/Users/danielnguyen/Repo/C++/Types_of_Sort/shell_sort.cpp"
#include "/Users/danielnguyen/Repo/C++/Types_of_Sort/insertion_sort.cpp"

using namespace std;

int main()
{
    int size;

    srand(time(0));

    size = rand() % 100;

    int arr1[size];

    for (int i = 0; i < size; i++)
    {
        arr1[i] = rand() % 100;
    }

    int arr2[size];
    cout << "Array has " << size << " elements: ";

    for (int i = 0; i < size; i++)
    {
        cout << arr1[i] << " ";
        arr2[i] = arr1[i];
    }

    cout << endl;

    InsertionSort<int> sort1;

    ShellSort<int> sort2;

    sort1.insertionSort(arr1, size);

    sort2.shellSort(arr2, size);

    cout << sort1.getComparison() << endl;
    cout << sort2.getComparison() << endl;

    return 0;
}