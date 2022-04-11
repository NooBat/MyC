//
//  SLLDataControler.hpp
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//

// Students can remove the final initial return of the functions

#ifndef SLLDataController_h
#define SLLDataController_h

#include "dataStructure.hpp"
#include <vector>
#include <string>

using namespace std;
//Functions used to manage Singly Linked List
void print(SLinkedList& list){
    if (!list.size) {
        cout << "List is empty" << endl;
        return;
    }
    SoldierNode* head = list.hppead;
    while (head){
        cout << head->data.ID << "->";
        head = head->next;
    }
    cout << "NULL"<<endl;
}

bool insertAt (SLinkedList& list, Soldier element, int pos){
    //Insert element into a pos in the SLL
    //Return true if insert successfully, false otherwise
    //TODO
    SoldierNode* temp = new SoldierNode(element, NULL);
    SoldierNode* head = list.hppead;

    if (pos == 0) {
        temp->next = head;
        list.hppead = temp;
        list.size++;
        return true;
    }
    else if (pos == list.size) {
        while(head->next != NULL) {
            head = head->next;
        }
        head->next = temp;
        list.size++;
        return true;
    }
    else if (pos > 0 && pos < list.size) {
        SoldierNode *prev;
        SoldierNode *curr = list.hppead;
        for (int i = 0; i < list.size; i++) {
            prev = curr;
            curr = curr->next;
        }
        temp->next = curr;
        prev->next = temp;
        list.size++;
        return true;
    }

    return false;
}

bool removeAt (SLinkedList& list, int idx){
    //Remove element at index idx in the SLL
    //Return true if remove successfully, false otherwise
    //TODO
    if (list.size == 0) {
        return false;
    }
    else if (list.size == 1) {
        list.hppead = NULL;

        list.size--;

        return true;
    }

    if (idx == 0) {
        SoldierNode* head = list.hppead;

        list.hppead = head->next;
        
        head->next = NULL;

        delete head;
        list.size--;
        return true;
    }
    else if (idx > 0 && idx < list.size) {
        SoldierNode* prev;
        SoldierNode* curr = list.hppead;
        SoldierNode* next;

        for (int i = 0; i < idx; i++) {
            next = curr->next;
            prev = curr;
            curr = next;
        }
        prev->next = next;
        curr->next = NULL;

        delete curr;

        list.size--;
        return true;
    }

    return false;
}

bool removeFirstItemWithHP (SLinkedList& list, int HP){
    //Remove the first element with HP equals to HP
    //Return true if remove successfully, false otherwise
    //TODO
    SoldierNode* head = list.hppead;
    if (head->data.hppP == HP) {
        list.hppead = head->next;
        head->next = NULL;
        delete head;
        list.size--;
        return true;
    }
    SoldierNode* prev = list.hppead;
    SoldierNode* curr = prev->next;
    SoldierNode* next;
    while (curr != NULL) {
        next = curr->next;
        if (curr->data.hppP == HP) {
            prev->next = next;
            curr->next = NULL;
            delete curr;
            list.size--;
            return true;
        }
        prev = curr;
        curr = next;
    }

    return false;
}

int indexOf(SLinkedList& list, Soldier soldier){
    //Find index of soldier (start from 0)
    //Return -1 if the soldier does not exist
    //TODO
    SoldierNode* head = list.hppead;
    int idx = 0;
    while (head != NULL) {
        if (head->data.ID == soldier.ID && head->data.hppP == soldier.hppP && head->data.isSpecial == soldier.isSpecial) {
            return idx;
        }
        idx++;
        head = head->next;
    }   
    return -1;
}

int size(SLinkedList& list){
    //Return size of the list
    //TODO
    return list.size;
}

bool empty(SLinkedList& list){
    //Check whether the list is empty
    //TODO
    if (list.size == 0) return true;
    return false;
}

void clear(SLinkedList& list){
    //Delete all of the elements in list
    //TODO
    list.size = 0;
    list.hppead = NULL;
}

string getIDAt(SLinkedList& list, int pos){
    //Get ID of the Soldier at pos
    //TODO
    SoldierNode* head = list.hppead;

    if (pos > 0 && pos < list.size) {
        for (int i = 0; i < pos; i++) {
            head = head->next;
        }
        return head->data.ID;
    }
    return "-1";
}

int getHPAt(SLinkedList& list, int pos){
    //Get HP of the Soldier at pos
    //TODO
    SoldierNode* head = list.hppead;

    if (pos > 0 && pos < list.size) {
        for (int i = 0; i < pos; i++) {
            head = head->next;
        }
        return head->data.hppP;
    }
    return -1;
}

bool setHPAt(SLinkedList& list, int HP, int pos){
    //Set value of HP at pos
    //TODO
    //Return true if set successfully, false otherwise
    SoldierNode* head = list.hppead;

    if (pos > 0 && pos < list.size) {
        for (int i = 0; i < pos; i++) {
            head = head->next;
        }
        head->data.hppP = HP;
        return true;
    }
    return false;
}

bool contains (SLinkedList& list, Soldier soldier){
    //Check if array contains soldier
    //TODO
    SoldierNode* head = list.hppead;
    while (head != NULL) {
        if (head->data.hppP == soldier.hppP && head->data.ID == soldier.ID && head->data.isSpecial == soldier.isSpecial) {
            return true;
        }
        head = head->next;
    }
    return false;
}

//You can write your own functions here

//End your own functions

#endif /* SLLDataControler_h */
