#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "/Users/danielnguyen/Repo/C++/ADT/Tree/BinaryTree/BinaryTreeInterface.hpp"
#include "/Users/danielnguyen/Repo/C++/ADT/Tree/BinaryTree/BinaryNodeTree.hpp"
#include "/Users/danielnguyen/Repo/C++/ADT/Tree/BinaryTree/BinaryNodeTree.cpp"
#include<string>
#include<fstream>

using namespace std;

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

    // Recursively finds where the given node should be placed and
    // inserts it in a leaf at that point.
    BinaryNode<T>* insertInorder(BinaryNode<T>* subTreePtr, BinaryNode<T>* newNodePtr);

    // Removes the given target value from the tree while maintaining a 
    // binary search tree.
    BinaryNode<T>* removeValue(BinaryNode<T>* subTreePtr, const T& target, bool& success);

    //Removes the given node from the tree while maintaining a
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

    //Take array and turn it into a balanced binary search tree.
    BinaryNode<T>* createTree(BinaryNode<T>* subTreePtr, T arr[], int left, int right);

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
    void readTree(T arr[], int n);

//----------------------------------------------------------
//      Public Traversals Section.
//----------------------------------------------------------
    void preorderTraverse(void visit(T&)) const;
    void inorderTraverse(void visit(T&)) const;
    void postorderTraverse(void visit(T&)) const;

//----------------------------------------------------------
//      Overloaded Operator Section.
//----------------------------------------------------------
    BinarySearchTree<T>& operator=(const BinarySearchTree<T>& rightHandSide);
};

#endif