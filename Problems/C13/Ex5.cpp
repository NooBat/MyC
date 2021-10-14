#include<iostream>
#include<string>
#include "OurQueue.hpp"

using namespace std;

int greatestNumbDigit(int arr[], int size)
{
    int result = 0;
    for (int i = 0; i < size; i++)
    {
        int temp = arr[i];
        int count = 0;

        while (temp > 0)
        {
            temp /= 10;
            count++;
        }

        result = max(count, result);
    }

    return result;
}

void radixSort(int arr[], int size)
{   
    OurQueue<int> hash[10];

    int digits = greatestNumbDigit(arr, size);

    for (int digit = 1; digit <= digits; digit++)
    {
        for (int i = 0; i < size; i++)
        {
            int temp = arr[i];

            for (int time = 1; time < digit; time++)
            {
                temp /= 10;
            }

            int index = temp % 10;

            hash[index].enqueue(arr[i]);
        }

        int index = 0;

        for (int i = 0; i < 10; i++)
        {
            while (!hash[i].isEmpty())
            {
                arr[index] = hash[i].peekFront();
                hash[i].dequeue();
                index++;
            }
        }
    }
}

string printArray(int arr[], int size)
{
    string result = "[";

    for (int i = 0; i < size; i++)
    {
        result += to_string(arr[i]) + ", ";
    }

    result = result.substr(0, result.length() - 2);

    result += "]";

    return result;
}

int main()
{
    int arr[] = {10, 11, 1, 30, 399, 40};

    int size = int(sizeof(arr) / sizeof(int));
    radixSort(arr, size);

    cout << printArray(arr, size);

    return 0;
}