//
//  thirdBattle.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//
// Students can remove the final initial return of the functions

#ifndef thirdBattle_h
#define thirdBattle_h

#include "SLLDataController.h"
#include "ArrayDataController.h"
#include <vector>
#include <string>

using namespace std;

//////////////////////////////////////////////////////
/// TASK 1
//////////////////////////////////////////////////////

bool push(Array& array, Soldier soldier){
    //Return true if push successfully, false otherwise
    //TODO
    if (array.capacity == 0) {
        initArray(array, 1);
    }
    else {
        int newCap = 1.5 * array.capacity;
        ensureCapacity(array, newCap);
    }

    return insertAt(array, soldier, 0);
}

bool pop(Array& array){
    //Return true if pop successfully, false otherwise
    //TODO
    return removeAt(array, 0);
}

Soldier top(Array& array){
    //TODO
    if (array.capacity == 0) {
        return Soldier();//return this if cannot get top
    }
    return array.arr[0];
}

//////////////////////////////////////////////////////
/// TASK 2
//////////////////////////////////////////////////////

bool enqueue(SLinkedList& list, Soldier soldier){
    //Return true if enqueue successfully, false otherwise
    //TODO
    return insertAt(list, soldier, list.size);
}

bool dequeue(SLinkedList& list){
    //Return true if dequeue successfully, false otherwise
    //TODO
    
    return removeAt(list, 0);
}

Soldier front(SLinkedList& list){
    //TODO
    if (list.size == 0) return Soldier();//Return this if cannot get front
    return list.head->data;
}

//////////////////////////////////////////////////////
/// TASK 3
//////////////////////////////////////////////////////

void reverse(SLinkedList& list){
    //TODO
    if (list.size == 0 || list.size == 1) return;
    SoldierNode *prev = NULL;
    SoldierNode *curr = list.head;
    SoldierNode *next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    list.head = prev;
}

//////////////////////////////////////////////////////
/// TASK 4
//////////////////////////////////////////////////////
int rule(Soldier A, Soldier B);
void sortArray(Soldier *A, int size);

SLinkedList merge(SLinkedList& list1, SLinkedList& list2){
    //TODO
    SLinkedList result = SLinkedList();
    int size = list1.size + list2.size;

    Soldier *A = new Soldier[size];

    int idx = 0;

    SoldierNode *head1 = list1.head;
    SoldierNode *head2 = list2.head;

    while (head1 != NULL) {
        A[idx] = head1->data;
        idx++;
        head1 = head1->next;
    }

    while (head2 != NULL) {
        A[idx] = head2->data;
        idx++;
        head2 = head2->next;
    }

    sortArray(A, size);

    for (int i = 0; i < size; i++) {
        bool check = insertAt(result, A[i], i);
    }
    return result;
}

//You can write your own functions here
int rule(Soldier A, Soldier B) {
    if (A.HP < B.HP) return 1;
    else if (A.HP > B.HP) return 2;
    else {
        if (A.isSpecial == 0 && B.isSpecial == 1) return 1;
        else if (A.isSpecial == 1 && B.isSpecial == 0) return 2;
        else {
            if (A.ID[0] < B.ID[0]) return 1;
            else if (A.ID[0] > B.ID[0]) return 2;
        }
    }

    return 0;
}

void sortArray(Soldier *A, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (rule(A[i], A[j]) == 2) swap(A[i], A[j]);
        }
    }
}
//End your own functions

#endif /* thirdBattle_h */
