#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "ADT/Tree/BinaryTree/BinaryTreeInterface.hpp"
#include "ADT/Tree/BinaryTree/BinaryNodeTree.hpp"
#include "ADT/Tree/BinaryTree/BinaryNodeTree.cpp"

template<class T>
class BinarySearchTree : public BinaryNodeTree<T>
{
private:
    BinaryNode<T>* rootPtr;

protected:
//----------------------------------------------------------
//      Protected Utility Methods Section:  
//      Recursive helper methods for the public methods.
//----------------------------------------------------------

    //Recursively adds a new node to the tree in a left/right fashion to
    //keep the tree balanced.
    BinaryNode<T>* insertNode(BinaryNode<T>* subTreePtr, BinaryNode<T>* newNodePtr);

    //Removes the target value from the tree by calling moveValuesUpTree
    //to overwrite value with value from child.
    BinaryNode<T>* removeValue(BinaryNode<T>* subTreePtr, const T& target, bool& success);

    //Removes the given target value from the tree while maintaining a
    //binary search tree.
    BinaryNode<T>* removeNode(BinaryNode<T>* nodePtr);

    //Removes the leftmost node in the left subtree of the node
    //pointed to by nodePtr.
    //Sets inorderSuccessor to the value in this node.
    //Returns a pointer to the revised subtree.
    BinaryNode<T>* removeLeftmostNode(BinaryNode<T>* subTreePtr, T& inorderSuccessor);

    //Returns a pointer to the node containing the given value,
    //or nullptr if not found.
    BinaryNode<T>* findNode(BinaryNode<T>* treePtr, const T& target) const;

public:
//----------------------------------------------------------
//      Constructor and Destructor Section.             
//----------------------------------------------------------

    BinarySearchTree();
    BinarySearchTree(const T& rootItem);
    BinarySearchTree(const BinarySearchTree<T>& tree);
    virtual ~BinarySearchTree();

//----------------------------------------------------------
//      Public methods Section.
//----------------------------------------------------------

    bool isEmpty() const;
    int getHeight() const;
    int getNumberOfNodes() const;
    T getRootData() const;
    void setRootData(const T& newData);
    bool add(const T& newEntry);
    bool remove(const T& anEntry);
    void clear();
    T getEntry(const T& anEntry) const;
    bool contains(const T& anEntry) const;

//----------------------------------------------------------
//      Public Traversals Section.
//----------------------------------------------------------
    void preorderTraversal(void visit(T&)) const;
    void inorderTraversal(void visit(T&)) const;
    void postorderTraversal(void visit(T&)) const;

//----------------------------------------------------------
//      Overloaded Operator Section.
//----------------------------------------------------------
    BinarySearchTree<T>& operator=(const BinarySearchTree<T>& rightHandSide);
};

#endif