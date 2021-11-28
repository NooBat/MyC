#include "BinarySearchTree.hpp"

//----------------------------------------------------------
//      Protected Utility Methods Section:  
//      Recursive helper methods for the public methods.
//----------------------------------------------------------

template<class T>
BinaryNode<T>* BinarySearchTree<T>::insertNode(BinaryNode<T>* subTreePtr, BinaryNode<T>* newNodePtr)
{
    if (!subTreePtr) return newNodePtr;

    if (newNodePtr->getItem() > subTreePtr->getItem()) subTreePtr->setRightPtr(insertNode(subTreePtr->getRightPtr(), newNodePtr));
    else subTreePtr->setLeftPtr(insertNode(subTreePtr->getLeftPtr(), newNodePtr));

    return subTreePtr;
}

template<class T>
BinaryNode<T>* BinarySearchTree<T>::removeValue(BinaryNode<T>* subTreePtr, const T& target, bool& success)
{
    if (!subTreePtr) 
}