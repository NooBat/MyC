#include "LinkedList.hpp"
#include "LinkedList.cpp"

int main()
{
    int arr[] = {20, 30, 10, 60, 40, 45, 55};
    LinkedList* l1 = new LinkedList();

    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        l1->add(arr[i]);
    }

    l1->partition(45);

    cout << l1->toString() << "\n";

    return 0;
}