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

template<class T>
BinaryNode<T>::BinaryNode(): leftPtr(nullptr), rightPtr(nullptr)
{

}

template<class T>
BinaryNode<T>::BinaryNode(const T& anItem, BinaryNode<T>* leftPtr, BinaryNode<T>* rightPtr)
{
    item = anItem;
    this->leftPtr = leftPtr;
    this->rightPtr = rightPtr;
}

template<class T>
void BinaryNode<T>::setItem(const T& anItem)
{
    item = anItem;
}

template<class T>
T BinaryNode<T>::getItem() const
{ 
    return item;
}

template<class T>
bool BinaryNode<T>::isLeaf() const
{
    if (!leftPtr && !rightPtr) return true;
    return false;
}

template<class T>
void BinaryNode<T>::setLeftPtr(BinaryNode<T>* leftPtr) 
{
    this->leftPtr = leftPtr;
}

template<class T>
void BinaryNode<T>::setRightPtr(BinaryNode<T>* rightPtr)
{
    this->rightPtr = rightPtr;
}

template<class T>
BinaryNode<T>* BinaryNode<T>::getLeftPtr() const
{
    return leftPtr;
}

template<class T>
BinaryNode<T>* BinaryNode<T>::getRightPtr() const
{
    return rightPtr;
}

#endif