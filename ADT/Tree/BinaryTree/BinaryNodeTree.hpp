#ifndef _BINARY_NODE_TREE
#define _BINARY_NODE_TREE

#include "BinaryTreeInterface.hpp"
#include "../BinaryNode.hpp"
#include "../../NotFoundException.hpp"
#include "../../PrecondViolatedException.hpp"

template<class T>
class BinaryNodeTree : public BinaryTreeInterface<T>
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

public:
//----------------------------------------------------------
//      Constructor and Destructor Section.
//----------------------------------------------------------

    BinaryNodeTree();
    BinaryNodeTree(const T& item, 
                   const BinaryNodeTree<T>* leftTreePtr = nullptr, 
                   const BinaryNodeTree<T>* rightTreePtr = nullptr);
    BinaryNodeTree(const BinaryNodeTree<T>& tree);  
    virtual ~BinaryNodeTree();

//----------------------------------------------------------
//      Public BinaryTreeInterface Methods Section.
//----------------------------------------------------------

    bool isEmpty() const;
    int getHeight() const;
    int getNumberOfNodes() const;
    T getRootData() const;
    void setRootData(const T& newData);
    bool add(const T& newData);
    bool remove(const T& data);
    void clear();
    T getEntry(const T& anEntry) const;
    bool contains(const T& anEntry) const;
    bool replace(T item, T replacementItem);

//----------------------------------------------------------
//      Public Traversals Section.
//----------------------------------------------------------

    void preorderTraverse(void visit(T&)) const;
    void inorderTraverse(void visit(T&)) const;
    void postorderTraverse(void visit(T&)) const;

//----------------------------------------------------------
//      Overloaded Operator Section.
//----------------------------------------------------------
    BinaryNodeTree<T>& operator=(const BinaryNodeTree<T>& rightHandSide);
};

#endif