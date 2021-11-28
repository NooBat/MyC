#include "BinarySearchTree.hpp"

//----------------------------------------------------------
//      Protected Utility Methods Section:  
//      Recursive helper methods for the public methods.
//----------------------------------------------------------

template<class T>
BinaryNode<T>* BinarySearchTree<T>::insertInorder(BinaryNode<T>* subTreePtr, BinaryNode<T>* newNodePtr)
{
    if (!subTreePtr) return newNodePtr;

    if (newNodePtr->getItem() > subTreePtr->getItem()) subTreePtr->setRightPtr(insertInorder(subTreePtr->getRightPtr(), newNodePtr));
    else subTreePtr->setLeftPtr(insertInorder(subTreePtr->getLeftPtr(), newNodePtr));

    return subTreePtr;
}

template<class T>
BinaryNode<T>* BinarySearchTree<T>::removeValue(BinaryNode<T>* subTreePtr, const T& target, bool& success)
{
    if (!subTreePtr) 
    {
        success = false;
        return nullptr;
    }

    if (subTreePtr->getItem() == target)
    {
        subTreePtr = removeNode(subTreePtr);
        success = true;
    }
    else if (subTreePtr->getItem() > target)
    {
        subTreePtr->setLeftPtr(removeValue(subTreePtr->getLeftPtr(), target, success));
    }
    else 
    {
        subTreePtr->setRightPtr(removeValue(subTreePtr->getRightPtr(), target, success));
    }

    return subTreePtr;
}

template<class T>
BinaryNode<T>* BinarySearchTree<T>::removeNode(BinaryNode<T>* nodePtr)
{
    if (!nodePtr) return nullptr;
    
    if (nodePtr->isLeaf())
    {
        delete nodePtr;
        nodePtr = nullptr;
    }
    else if (!nodePtr->getLeftPtr())
    {
        BinaryNode<T>* nodeToConnect = nodePtr->getRightPtr();
        delete nodePtr;
        nodePtr = nodeToConnect;
    }
    else if (!nodePtr->getRightPtr())
    {
        BinaryNode<T>* nodeToConnect = nodePtr->getLeftPtr();
        delete nodePtr;
        nodePtr = nodeToConnect;
    }
    else
    {
        T newNodeValue;
        nodePtr->setRightPtr(removeLeftmostNode(nodePtr->getRightPtr(), newNodeValue));
        nodePtr->setItem(newNodeValue);
    }

    return nodePtr;
}

template<class T>
BinaryNode<T>* BinarySearchTree<T>::removeLeftmostNode(BinaryNode<T>* subTreePtr, T& inorderSuccessor)
{
    if (!subTreePtr->getLeftPtr())
    {
        inorderSuccessor = subTreePtr->getItem();

        subTreePtr = removeNode(subTreePtr);
    }
    else
    {
        subTreePtr->setLeftPtr(removeLeftmostNode(subTreePtr->getLeftPtr(), inorderSuccessor));
    }
    return subTreePtr;
}

template<class T>
BinaryNode<T>* BinarySearchTree<T>::findNode(BinaryNode<T>* treePtr, const T& target) const
{
    if (!treePtr) return nullptr;

    if (treePtr->getItem() > target) return findNode(treePtr->getLeftPtr(), target);
    else if (treePtr->getItem() < target) return findNode(treePtr->getRightPtr(), target);
    return treePtr;
}

template<class T> 
BinaryNode<T>* BinarySearchTree<T>::createTree(BinaryNode<T>* subTreePtr, T arr[], int left, int right)
{
    if (left <= right)
    {
        int mid = left + (right - left) / 2;
        BinaryNode<T>* treePtr = new BinaryNode<T>(arr[mid]);

        BinaryNode<T>* leftSubtree = createTree(treePtr->getLeftPtr(), arr, left, mid - 1);
        BinaryNode<T>* rightSubtree = createTree(treePtr->getRightPtr(), arr, mid + 1, right);

        treePtr->setLeftPtr(leftSubtree);
        treePtr->setRightPtr(rightSubtree);

        return treePtr;
    }

    return nullptr;
}

//----------------------------------------------------------
//      Constructor and Destructor Section.             
//----------------------------------------------------------

template<class T>
BinarySearchTree<T>::BinarySearchTree(): rootPtr(nullptr)
{

}

template<class T>
BinarySearchTree<T>::BinarySearchTree(const T& rootItem)
{
    rootPtr = new BinaryNode<T>(rootItem);
}

template<class T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& tree)
{
    rootPtr = copyTree(tree.rootPtr);
}

template<class T>
BinarySearchTree<T>::~BinarySearchTree()
{
    BinaryNodeTree<T>::destroyTree(rootPtr);
}

//----------------------------------------------------------
//      Public methods Section.
//----------------------------------------------------------

template<class T>
bool BinarySearchTree<T>::isEmpty() const
{
    return rootPtr == nullptr;
}

template<class T>
int BinarySearchTree<T>::getHeight() const
{
    return BinaryNodeTree<T>::getHeightHelper(rootPtr);
}

template<class T>
int BinarySearchTree<T>::getNumberOfNodes() const
{
    return BinaryNodeTree<T>::getNumberOfNodes();
}

template<class T>
T BinarySearchTree<T>::getRootData() const
{
    if (!rootPtr)
    {
        string msg = "getRootData() was called with an empty tree.";
        throw PrecondViolatedException(msg);
    }

    return rootPtr->getItem();
}

template<class T>
void BinarySearchTree<T>::setRootData(const T& newData)
{
    if (!rootPtr) return;
    rootPtr->setItem(newData);
}

template<class T>
bool BinarySearchTree<T>::add(const T& newEntry)
{
    BinaryNode<T>* newNodePtr = new BinaryNode<T>(newEntry);

    rootPtr = insertInorder(rootPtr, newNodePtr);

    return true;
}

template<class T>
bool BinarySearchTree<T>::remove(const T& anEntry)
{
    bool isRemoved = false;

    rootPtr = removeValue(rootPtr, anEntry, isRemoved);

    return isRemoved;
}

template<class T>
void BinarySearchTree<T>::clear() 
{
    BinaryNodeTree<T>::destroyTree(rootPtr);
}

template<class T>
T BinarySearchTree<T>::getEntry(const T& anEntry) const
{
    if (!contains(anEntry))
    {
        string msg = "getEntry() was called with an empty tree or nonexisted item";
        throw NotFoundException(msg);
    }

    return anEntry;
}

template<class T>
bool BinarySearchTree<T>::contains(const T& anEntry) const
{
    if (findNode(rootPtr, anEntry)->getItem() == anEntry) return true;

    return false;
}

template<class T>
void BinarySearchTree<T>::readTree(const string& filename)
{

}

//----------------------------------------------------------
//      Public Traversals Section.
//----------------------------------------------------------

template<class T>
void BinarySearchTree<T>::preorderTraverse(void visit(T&)) const
{
    if (!rootPtr) return;

    T theItem = rootPtr->getItem();
    visit(theItem);
    BinaryNodeTree<T>::preorder(visit, rootPtr->getLeftPtr());
    BinaryNodeTree<T>::preorder(visit, rootPtr->getRightPtr());
}

template<class T>
void BinarySearchTree<T>::inorderTraverse(void visit(T&)) const
{
    if (!rootPtr) return;

    T theItem = rootPtr->getItem();
    BinaryNodeTree<T>::inorder(visit, rootPtr->getLeftPtr());
    visit(theItem);
    BinaryNodeTree<T>::inorder(visit, rootPtr->getRightPtr());
}

template<class T>
void BinarySearchTree<T>::postorderTraverse(void visit(T&)) const
{
    if (!rootPtr) return;

    T theItem = rootPtr->getItem();

    BinaryNodeTree<T>::postorder(visit, rootPtr->getLeftPtr());
    BinaryNodeTree<T>::postorder(visit, rootPtr->getRightPtr());
    visit(theItem);
}

//----------------------------------------------------------
//      Overloaded Operator Section.
//----------------------------------------------------------

template<class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree<T>& rightHandSide)
{
    if (rootPtr != rightHandSide)
    {
        this->clear();
        this = BinaryNodeTree<T>::copyTree(rightHandSide);
    }

    return *this;
}