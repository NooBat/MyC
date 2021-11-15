#ifndef _BINARY_NODE
#define _BINARY_NODE

template<class T>
class BinaryNode
{
private:
    T item;
    BinaryNode<T>* leftPtr;
    BinaryNode<T>* rightPtr;

public:
    BinaryNode();
    BinaryNode(const T& anItem, 
               BinaryNode<T>* leftPtr = nullptr, 
               BinaryNode<T>* rightPtr = nullptr);
    
    void setItem(const T& anItem);
    T getItem() const;

    bool isLeaf() const;

    void setLeftPtr(BinaryNode<T>* leftPtr);
    void setRightPtr(BinaryNode<T>* rightPtr);

    BinaryNode<T>* getLeftPtr() const;
    BinaryNode<T>* getRightPtr() const;
};

#endif