#ifndef _BOOK_PILE
#define _BOOK_PILE

#include "/Users/danielnguyen/Repo/C++/ADT/Node.hpp"
#include<iostream>
 
using namespace std;

template<class T>
class Pile {
private:
    int             bookCount;      //number of books in the pile
    Node<T>* head;           //head of the pile

public:
    /** The default constructor for class Pile. */
    Pile();

    /** The destructor for class Pile.
     * @post Destroy the pile of book. */
    virtual ~Pile();

    /** Adds a new book on top of the pile.
     * @param newBook the book to be added to the pile.
     * @returns True if successful, false otherwise. */
    bool addBook(const T& newBook);

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

template<class T>
Pile<T>::Pile(): bookCount(0), head(nullptr) {

}

template<class T>
Pile<T>::~Pile() {
    clear();
}

template<class T>
bool Pile<T>::addBook(const T& newBook) {
    Node<T>* temp = new Node<T>(newBook);

    temp->setNext(head);

    head = temp;

    bookCount++;

    return true;
}

template<class T>
bool Pile<T>::popBook() {
    if (head == nullptr) return false;

    Node<T>* p = head;

    head = head->getNext();

    delete p;
    
    p = nullptr;

    bookCount--;

    return true;
}

template<class T>
void Pile<T>::clear() {
    if (head == nullptr) return;

    Node<T>* curr = head;

    while (curr != nullptr) {
        Node<T>* next = curr->getNext();

        delete curr;

        curr = next;
    }

    head = nullptr;

    bookCount = 0;
}

template<class T>
int Pile<T>::getCurrentSize() const {
    return bookCount;
}
#endif