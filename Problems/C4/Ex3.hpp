#ifndef _BOOK_PILE
#define _BOOK_PILE

#include "/Users/danielnguyen/Repo/C++/ADT/Node.hpp"
#include<iostream>
 
using namespace std;

template<class ItemType>
class Pile {
private:
    int             bookCount;      //number of books in the pile
    Node<ItemType>* head;           //head of the pile

public:
    /** The default constructor for class Pile. */
    Pile();

    /** The destructor for class Pile.
     * @post Destroy the pile of book. */
    virtual ~Pile();

    /** Adds a new book on top of the pile.
     * @param newBook the book to be added to the pile.
     * @returns True if successful, false otherwise. */
    bool addBook(const ItemType& newBook);

    /** Removes the top of the pile.
     * @pre Pile must not be empty.
     * @post The top book must be remove from the pile.
     * @return True if successful, false otherwise. */
    bool popBook();

    /** Clears the entire pile.
     * @post bookCount = 0 and head = nullptr */
    void clear();

    /** Returns the current number of books.
     * @return current amount of books.
    */
    int getCurrentSize() const;
};

template<class ItemType>
Pile<ItemType>::Pile(): bookCount(0), head(nullptr) {

}

template<class ItemType>
Pile<ItemType>::~Pile() {
    clear();
}

template<class ItemType>
bool Pile<ItemType>::addBook(const ItemType& newBook) {
    Node<ItemType>* temp = new Node<ItemType>(newBook);

    temp->setNext(head);

    head = temp;

    bookCount++;

    return true;
}

template<class ItemType>
bool Pile<ItemType>::popBook() {
    if (head == nullptr) return false;

    Node<ItemType>* p = head;

    head = head->getNext();

    delete p;
    
    p = nullptr;

    bookCount--;

    return true;
}

template<class ItemType>
void Pile<ItemType>::clear() {
    if (head == nullptr) return;

    Node<ItemType>* curr = head;

    while (curr != nullptr) {
        Node<ItemType>* next = curr->getNext();

        delete curr;

        curr = next;
    }

    head = nullptr;

    bookCount = 0;
}

template<class ItemType>
int Pile<ItemType>::getCurrentSize() const {
    return bookCount;
}
#endif