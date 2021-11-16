#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "BinarySearchTreeInterface.hpp"
#include "/Users/danielnguyen/Repo/C++/ADT/Tree/BinaryNode.hpp"

template<class T>
class BinarySearchTree : public BinarySearchTreeInterface
{
private:
    BinaryNode<T>* rootPtr;

protected:
//----------------------------------------------------------
//      Protected Utility Methods Section:  
//      Recursive helper methods for the public methods.
//----------------------------------------------------------
    int getHeightHelper(BinaryNode<T>* subTreePtr) const;
    int getNumberOfNodesHelper(BinaryNode<T>* subTreePtr) const;

    //Recursively deletes all nodes from the tree.
    void destroyTree(BinaryNode<T>* subTreePtr);

    //Recursively adds a new node to the tree in a left/right fashion to
    //keep the tree balanced.
    BinaryNode<T>* balancedAdd(BinaryNode<T>* subTreePtr, BinaryNode<T>* newNodePtr);

    //Removes the target value from the tree by calling moveValuesUpTree
    //to overwrite value with value from child.
    BinaryNode<T>* removeValue(BinaryNode<T>* subTreePtr, const T& target, bool& success);

    //Copies values up the tree to overwrite value in current node until
    //a leaf is reached; the leaf is then removed, since its value is
    //stored in the parent.
    BinaryNode<T>* moveValuesUpTree(BinaryNode<T>* subTreePtr);

    //Recursively searches for target value in the tree by using a
    //preorder traversal.
    BinaryNode<T>* findNode(BinaryNode<T>* treePtr, const T& target, bool& success) const;

    //Copies the tree rooted at treePtr and returns a pointer to
    //the copy.
    BinaryNode<T>* copyTree(const BinaryNode<T>* treePtr) const;

    //Recursive traversal helper methods:
    void preorder(void visit(T&), BinaryNode<T>* treePtr) const;
    void inorder(void visit(T&), BinaryNode<T>* treePtr) const;
    void postorder(void visit(T&), BinaryNode<T>* treePtr) const;
};

#endif