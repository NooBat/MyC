#ifndef _SHELL_SORT
#define _SHELL_SORT

#include<iostream>

using namespace std;

template<class ItemType>
class ShellSort {
private:
    int comparisonCounter;
public:
    ShellSort();
    void shellSort(ItemType arr[], int n);
    int getComparison() const;
};

template<class ItemType>
ShellSort<ItemType>::ShellSort()
{
    comparisonCounter = 0;
}

template<class ItemType>
void ShellSort<ItemType>::shellSort(ItemType arr[], int n)
{
    for (int h = n / 2; h > 0; h = h / 2)
    {   
        for (int unsorted = h; unsorted < n; unsorted++)
        {
            ItemType nextItem = arr[unsorted];
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

template<class ItemType>
int ShellSort<ItemType>::getComparison() const 
{
    return comparisonCounter;
}

#endif