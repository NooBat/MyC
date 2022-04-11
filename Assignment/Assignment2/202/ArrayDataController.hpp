//
//  ArrayDataController.hpp
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//

// Students can remove the final initial return of the functions

#ifndef ArrayDataController_h
#define ArrayDataController_h

#include "dataStructure.hpp"
#include <vector>
#include <string>

using namespace std;
//Functions used to manage Array
void print(Array& array){
    if (!array.size) {
        cout << "Array is empty" << endl;
        return;
    }
    cout <<"[";
    for(int i=0;i<array.size;i++){
        cout << array.arr[i].ID << " ";
    }
    cout <<"]" << endl;
}

void initArray (Array& array, int cap){
    //Init a new array with capacity equals to cap
    //TODO
    if (cap == 0) cap = 1;
    array.arr = new Soldier[cap];
    
    array.capacity = cap;
}

bool insertAt(Array& array, Soldier element, int pos){
    //Insert element into a pos in the array
    //Return true if insert successfully, false otherwise
    //TODO
    if (array.capacity == 0) return false;

    if (pos < 0 || pos >= array.capacity) return false;

    if (pos >= array.size) pos = array.size;

    if (array.size == array.capacity) array.capacity++;
    array.size++;

    for (int i = 0; i < array.size - pos - 1; i++) {
        array.arr[array.size - 1 - i] = array.arr[array.size - 2 - i]; 
    }
    array.arr[pos].hppP = element.hppP;
    array.arr[pos].ID = element.ID;
    array.arr[pos].isSpecial = element.isSpecial;

    return true;
}

bool removeAt (Array& array, int idx){
    //Remove element at index idx in the array
    //Return true if remove successfully, false otherwise
    //TODO
    if (idx < 0 || idx >= array.size || array.capacity == 0) return false;

    for (int i = 0; i < array.size - idx - 1; i++) {
        array.arr[idx + i] = array.arr[idx + 1 + i]; 
    }
    array.size--;

    return true;
}

bool removeFirstItemWithHP (Array& array, int HP){
    //Remove the first element with HP equals to HP
    //Return true if remove successfully, false otherwise
    //TODO
    if (array.capacity == 0) return false;
    for (int i = 0; i < array.size; i++) {
        if (array.arr[i].hppP == HP) {
            for (int j = 0; j < array.size - i - 1; i++) {
                array.arr[i + j] = array.arr[i + j + 1];
            }
            array.size--;
            return true;
        }
    }

    return false;
}

void ensureCapacity(Array& array, int newCap){
    //Extend the capacity of the array
    //TODO
    if (newCap == 0) newCap = 1; 
    Array newArray;
    newArray.arr = new Soldier[newCap];

    for (int i = 0; i < array.size; i++) {
        newArray.arr[i].hppP = array.arr[i].hppP;
        newArray.arr[i].ID = array.arr[i].ID;
        newArray.arr[i].isSpecial = array.arr[i].isSpecial;
    }

    array.capacity = newCap;
    array.arr = newArray.arr;
}

int indexOf(Array& array, Soldier soldier){
    //Find index of soldier (start from 0)
    //Return -1 if the soldier does not exist
    //TODO
    if (array.capacity == 0) return -1;
    for (int i = 0; i < array.size; i++) {
        if (array.arr[i].hppP == soldier.hppP && array.arr[i].ID == soldier.ID && array.arr[i].isSpecial == soldier.isSpecial) 
            return i;
    }
    return -1;
}

int size(Array& array){
    //Return size of the array
    //TODO
    if (array.capacity == 0) return 0;
    return array.size;
}

bool empty(Array& array){
    //Check whether the array is empty
    //TODO
    if (array.size == 0) return true;
    return false;
}

string getIDAt(Array& array, int pos){
    //Get ID of the Soldier at pos
    //TODO
    if (array.capacity == 0 || pos < 0 || pos >= array.size) return "-1";

    return array.arr[pos].ID;
}

int getHPAt(Array& array, int pos){
    //Get HP of the Soldier at pos
    //TODO
    if (array.capacity == 0 || pos < 0 || pos >= array.size) return -1;
    return array.arr[pos].hppP;
}

bool setHPAt(Array& array, int HP, int pos){
    //Set value of HP at pos
    //TODO
    //Return true if set successfully, false otherwise
    if (array.capacity == 0 || pos < 0 || pos >= array.size) return false;
    array.arr[pos].hppP = HP;
    return true;
}

void clear(Array& array){
    //Delete all of the elements in array
    //TODO
    array.capacity = 0;
    array.size = 0;
    delete[] array.arr;
}

bool contains (Array& array, Soldier soldier){
    //Check if array contains soldier
    //TODO
    if (array.capacity == 0) return false;
    for (int i = 0; i < array.size; i++) {
        if (array.arr[i].hppP == soldier.hppP && array.arr[i].ID == soldier.ID && array.arr[i].isSpecial == soldier.isSpecial) {
            return true;
        }
    }
    return false;
}

//You can write your own functions here

//End your own functions

#endif /* ArrayDataController_h */
