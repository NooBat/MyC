#ifndef _DOUBLY_NODE
#define _DOUBLE_NODE

template<class ItemType>
class DoublyNode {
private:
    ItemType item;
    DoublyNode<ItemType>* next;
    DoublyNode<ItemType>* previous;

public:
    DoublyNode();

    DoublyNode(const ItemType& item);

    DoublyNode(const ItemType& item, const DoublyNode<ItemType>* next, 
               const DoublyNode<ItemType>* previous);

    void setItem(const ItemType& item);

    void setNext(const DoublyNode<ItemType>* next);

    void setPrevious(const DoublyNode<ItemType>* previous);

    ItemType getItem() const;

    DoublyNode<ItemType>* getNext() const;

    DoublyNode<ItemType>* getPrevious() const;
};