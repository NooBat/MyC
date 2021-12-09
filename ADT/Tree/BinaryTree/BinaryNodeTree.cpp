#include "BinaryNodeTree.hpp"

using namespace std;

//----------------------------------------------------------
//      Protected Utility Methods Section:  
//      Recursive helper methods for the public methods.
//----------------------------------------------------------

template<class T>
int BinaryNodeTree<T>::getHeightHelper(BinaryNode<T>* subTreePtr) const
{
    if (!subTreePtr) return 0;

    int leftHeight = getHeightHelper(subTreePtr->getLeftPtr());
    int rightHeight = getHeightHelper(subTreePtr->getRightPtr());

    return (leftHeight >= rightHeight) ? (leftHeight + 1) : (rightHeight + 1); 
}

template<class T>
int BinaryNodeTree<T>::getNumberOfNodesHelper(BinaryNode<T>* subTreePtr) const
{
    if (!subTreePtr) return 0;

    int numberOfLeftNodes = getNumberOfNodesHelper(subTreePtr->getLeftPtr());
    int numberOfRightNodes = getNumberOfNodesHelper(subTreePtr->getRightPtr());

    return 1 + numberOfLeftNodes + numberOfRightNodes;
}

template<class T>
void BinaryNodeTree<T>::destroyTree(BinaryNode<T>* subTreePtr)
{
    if (!subTreePtr) return;

    destroyTree(subTreePtr->getLeftPtr());
    destroyTree(subTreePtr->getRightPtr());
    delete subTreePtr;
}

template<class T>
BinaryNode<T>* BinaryNodeTree<T>::balancedAdd(BinaryNode<T>* subTreePtr, BinaryNode<T>* newNodePtr)
{
    if (!subTreePtr)
    {
        subTreePtr = newNodePtr;
    }
    else
    {
        if (getHeightHelper(subTreePtr->getLeftPtr()) <= getHeightHelper(subTreePtr->getRightPtr()))
        {
            BinaryNode<T>* newLeftPtr = balancedAdd(subTreePtr->getLeftPtr(), newNodePtr);
            subTreePtr->setLeftPtr(newLeftPtr);
        }
        else
        {
            BinaryNode<T>* newRightPtr = balancedAdd(subTreePtr->getRightPtr(), newNodePtr);
            subTreePtr->setRightPtr(newRightPtr);
        }
    }

    return subTreePtr;
}

template<class T>
BinaryNode<T>* BinaryNodeTree<T>::removeValue(BinaryNode<T>* subTreePtr, const T& target, bool& success)
{
    if (!subTreePtr) return nullptr;

    if (subTreePtr->getItem() == target) 
    {
        if (subTreePtr->isLeaf()) 
        {
            delete subTreePtr;
            subTreePtr = nullptr; 
        }
        else subTreePtr = moveValuesUpTree(subTreePtr);
        success = true;
    }
    else 
    {
        subTreePtr->setLeftPtr(removeValue(subTreePtr->getLeftPtr(), target, success));
        if (!success) subTreePtr->setRightPtr(removeValue(subTreePtr->getRightPtr(), target, success));
    }

    return subTreePtr;
}

template<class T>
BinaryNode<T>* BinaryNodeTree<T>::moveValuesUpTree(BinaryNode<T>* subTreePtr)
{
    if (!subTreePtr) return nullptr;

    if (subTreePtr->isLeaf()) 
    {
        delete subTreePtr;
        subTreePtr = nullptr;
    }
    else if (!subTreePtr->getRightPtr()) 
    {
        subTreePtr->setItem(subTreePtr->getLeftPtr()->getItem());
        subTreePtr->setLeftPtr(moveValuesUpTree(subTreePtr->getLeftPtr()));
    }
    else
    {
        subTreePtr->setItem(subTreePtr->getRightPtr()->getItem());
        subTreePtr->setRightPtr(moveValuesUpTree(subTreePtr->getRightPtr()));
    }

    return subTreePtr;
}

template<class T>
BinaryNode<T>* BinaryNodeTree<T>::findNode(BinaryNode<T>* treePtr, const T& target, bool& success) const
{
    if (!treePtr) return nullptr;

    if (treePtr->getItem() == target)
    {
        success = true;
    }
    else
    {
        treePtr->setLeftPtr(findNode(treePtr->getLeftPtr(), target, success));
        treePtr->setRightPtr(findNode(treePtr->getRightPtr(), target, success));
    }

    return treePtr;
}

template<class T>
BinaryNode<T>* BinaryNodeTree<T>::copyTree(const BinaryNode<T>* treePtr) const
{
    if (!treePtr) return nullptr;

    BinaryNode<T>* newTreePtr = treePtr;

    newTreePtr->setLeftPtr(copyTree(treePtr->getLeftPtr()));
    newTreePtr->setRightPtr(copyTree(treePtr->getRightPtr()));

    return newTreePtr;
}

template<class T>
void BinaryNodeTree<T>::preorder(void visit(T&), BinaryNode<T>* treePtr) const
{
    if (!treePtr) return;

    T theItem = treePtr->getItem();
    visit(theItem);
    preorder(visit, treePtr->getLeftPtr());
    preorder(visit, treePtr->getRightPtr());
}

template<class T>
void BinaryNodeTree<T>::inorder(void visit(T&), BinaryNode<T>* treePtr) const
{
    if (!treePtr) return;

    inorder(visit, treePtr->getLeftPtr());
    T theItem = treePtr->getItem();
    visit(theItem);
    inorder(visit, treePtr->getRightPtr());
}

template<class T>
void BinaryNodeTree<T>::postorder(void visit(T&), BinaryNode<T>* treePtr) const
{
    if (!treePtr) return;

    postorder(visit, treePtr->getLeftPtr());
    postorder(visit, treePtr->getRightPtr());
    T theItem = treePtr->getItem();
    visit(theItem);
}


//----------------------------------------------------------
//      Constructor and Destructor Section.
//----------------------------------------------------------
template<class T>
BinaryNodeTree<T>::BinaryNodeTree(): rootPtr(nullptr)
{
    
}

template<class T>
BinaryNodeTree<T>::BinaryNodeTree(const T& item,
                                  const BinaryNodeTree<T>* leftTreePtr,
                                  const BinaryNodeTree<T>* rightTreePtr)
{
    rootPtr = new BinaryNode<T>(item, leftTreePtr, rightTreePtr);
}

template<class T>
BinaryNodeTree<T>::BinaryNodeTree(const BinaryNodeTree<T>& tree)
{
    rootPtr = copyTree(tree.rootPtr);
}

template<class T>
BinaryNodeTree<T>::~BinaryNodeTree() 
{
    destroyTree(rootPtr);
}


//----------------------------------------------------------
//      Public BinaryTreeInterface Methods Section.
//----------------------------------------------------------

template<class T>
bool BinaryNodeTree<T>::isEmpty() const
{
    return rootPtr == nullptr;
}

template<class T>
int BinaryNodeTree<T>::getHeight() const
{
    return getHeightHelper(rootPtr);
}

template<class T>
int BinaryNodeTree<T>::getNumberOfNodes() const
{
    return getNumberOfNodesHelper(rootPtr);
}

template<class T>
T BinaryNodeTree<T>::getRootData() const
{
    if (!rootPtr)
    {
        string msg = "getRootData() was called with an empty tree.";
        throw PrecondViolatedException(msg);
    }

    return rootPtr->getItem();
}

template<class T>
void BinaryNodeTree<T>::setRootData(const T& newData)
{
    if (!rootPtr) return;

    rootPtr->setItem(newData);
}

template<class T>
bool BinaryNodeTree<T>::add(const T& newData)
{
    BinaryNode<T>* newNodePtr = new BinaryNode<T>(newData);
    rootPtr = balancedAdd(rootPtr, newNodePtr);

    return true;
}

template<class T>
bool BinaryNodeTree<T>::remove(const T& data)
{
    bool isRemoved = false;
    rootPtr = removeValue(rootPtr, data, isRemoved);

    return isRemoved;
}

template<class T>
void BinaryNodeTree<T>::clear()
{
    destroyTree(rootPtr);
}

template<class T>
T BinaryNodeTree<T>::getEntry(const T& anEntry) const
{
    bool isInTree = false;
    findNode(rootPtr, anEntry, isInTree);

    if (!isInTree)
    {
        string msg = "getEntry() was called with an empty tree or nonexisted item!";
        throw NotFoundException(msg);
    }

    return anEntry;
}

template<class T>
bool BinaryNodeTree<T>::contains(const T& anEntry) const
{
    bool isInTree = false;
    findNode(rootPtr, anEntry, isInTree);

    return isInTree;
}

template<class T>
void BinaryNodeTree<T>::preorderTraverse(void visit(T&)) const
{
    preorder(visit, rootPtr);
}

template<class T>
void BinaryNodeTree<T>::inorderTraverse(void visit(T&)) const
{
    inorder(visit, rootPtr);
}

template<class T>
void BinaryNodeTree<T>::postorderTraverse(void visit(T&)) const
{
    postorder(visit, rootPtr);
}

template<class T>
BinaryNodeTree<T>& BinaryNodeTree<T>::operator=(const BinaryNodeTree<T>& rightHandSide)
{
    if (rootPtr != rightHandSide)
    {
        this->clear();
        this = this->copyTree(rightHandSide);
    }

    return *this;
}