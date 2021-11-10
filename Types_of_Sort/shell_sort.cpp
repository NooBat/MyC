#ifndef _SHELL_SORT
#define _SHELL_SORT

#include<iostream>

using namespace std;

template<class T>
class ShellSort {
private:
    int comparisonCounter;
public:
    ShellSort();
    void shellSort(T arr[], int n);
    int getComparison() const;
};

template<class T>
ShellSort<T>::ShellSort()
{
    comparisonCounter = 0;
}

template<class T>
void ShellSort<T>::shellSort(T arr[], int n)
{
    for (int h = n / 2; h > 0; h = h / 2)
    {   
        for (int unsorted = h; unsorted < n; unsorted++)
        {
            T nextItem = arr[unsorted];
            int loc = unsorted;

            while (loc >= h && arr[loc - h] > nextItem)
            {
                comparisonCounter += 2;
                arr[loc] = arr[loc - h];
                loc = loc - h;
            }

            arr[loc] = nextItem;
        }
    }
}

template<class T>
int ShellSort<T>::getComparison() const 
{
    return comparisonCounter;
}

#endif