#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
//radix sort:
// - sort the array digit by digit using any stable sort
// - preferably counting sort (since digit varies from 0 to 9)

template<class ItemType>
class RadixSort 
{
private:
    int getMaxDigit(ItemType arr[], int n);
public:
    void radixSort(ItemType arr[], int n);
    void print_array(ItemType arr[], int n);
};

template<class ItemType>
int RadixSort<ItemType>::getMaxDigit(ItemType arr[], int n) {
    int max = arr[0];
    int count = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }

    while (max > 0) {
        max /= 10;
        count++;
    }

    return count;
}

template<class ItemType>
void RadixSort<ItemType>::radixSort(ItemType arr[], int n) 
{
    int d = getMaxDigit(arr, n);

    for (int digit = 1; digit <= d; digit++) 
    {
        int idx = 0;
        vector<int>* tempArr = new vector<int>[10];

        for (int i = 0; i < n; i++) 
        {
            int temp = arr[i];
            for (int times = 1; times < digit; times++) 
            {
                if (temp == 0) break;
                temp /= 10;
            }
            int k = temp % 10;

            tempArr[k].push_back(arr[i]);
        }

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < tempArr[i].size(); j++) 
            {
                arr[idx + j] = tempArr[i][j];
            }
            idx += tempArr[i].size();
        }
        
        delete[] tempArr;
    }
}

template<class ItemType>
void RadixSort<ItemType>::print_array(ItemType arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void counting_sort(vector<int> &arr, int exp) {
    vector<int> output(arr.size());
    int count[10] = { 0 };

    for (int i = 0; i < arr.size(); i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        --count[(arr[i] / exp) % 10];
    }

    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

void radix_sort(vector<int> &arr) {
    int M = *max_element(arr.begin(), arr.end());

    for (int exp = 1; M / exp > 0; exp *= 10) {
        counting_sort(arr, exp);
    }
}

int main() {
    int arr[] = {9, 10, 19833, 129, 1992, 12041};

    int size = (int)(sizeof(arr) / sizeof(arr[0]));

    RadixSort<int> sortFunction;

    sortFunction.radixSort(arr, size);

    sortFunction.print_array(arr, size);

    return 0;
}