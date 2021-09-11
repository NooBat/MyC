#include<iostream>
#include "LinkedList.h"

using namespace std;

template<class ItemType>
bool swap(LinkedList<ItemType>& aList, int pos1, int pos2) {
    if (pos1 < 1 || pos1 > aList.getLength() || 
        pos2 < 1 || pos2 > aList.getLength()) {
        return false;
    }

    ItemType temp = aList.getEntry(pos1);

    aList.setEntry(pos1, aList.getEntry(pos2));
    aList.setEntry(pos2, temp);

    return true;
}

int main() {
    LinkedList<int> a;

    a.insert(1, 2);
    a.insert(1, 3);
    a.insert(1, 6);

    swap(a, 1, 3);
}