#ifndef _BINARY_SEARCH_TREE_INTERFACE
#define _BINARY_SEARCH_TREE_INTERFACE

template<class T>
class BinarySearchTreeInterface 
{
public:
public:
    /** Tests whether this binary search tree is empty.
     * @return True if the binary search tree is empty, or false if not. */
    virtual bool isEmpty() const = 0;

    /** Gets the height of this binary search tree. 
     * @return The height of the binary search tree. */
    virtual int getHeigth() const = 0;

    /** Gets number of nodes in this binary search tree. 
     * @return The number of nodes in the binary search tree. */
    virtual int getNumberOfNodes() const = 0;

    /** Gets the data that is in the root of this binary search tree.
     * @pre The binary search tree is not empty.
     * @post The root's data has been returned, and the binary search tree is unchanged.
     * @return The data in the root of the binary search tree. */
    virtual T getRootData() const = 0;

    /** Replaces the data item in the root of this binary search tree
     * with the given data, if the tree is not empty. However, if
     * the tree is empty, inserts a new root node containing the
     * given data into the tree.
     * @pre None.
     * @post The data in the root of the binary search tree is as given.
     * @param newData The data for the root. */
    virtual void setRootData(const T& newData) = 0;

    /** Adds a new node containing the given data to this tree
     * so that the properties of the binary search tree is maintained.
     * @param newData The data for the new node.
     * @post The binary search tree contains a new node in the correct
     * order of hierarchy.
     * @return True if the addition is successful, otherwise false. */
    virtual bool add(const T& newData) = 0;

    /** Removes the node containing the given data item from this tree
     * so that the properties of the binary search tree is maintained.
     * @param data The data value to remove from the binary search tree.
     * @return True if the removal is successful, otherwise false. */
    virtual bool remove(const T& data) = 0;

    /** Removes all nodes from this binary search tree. */
    virtual void clear() = 0;

    /** Gets a specific entry in this binary search tree.
     * @post The desired entry has been returned, and the binary search tree
     * is unchanged. If no such entry was found, an exception is thrown.
     * @param anEntry The entry to locate.
     * @return The entry in the binary tree that matches the given entry.
     * @throw NotFoundException if the given entry is not in the tree. */
    virtual T getEntry(const T& anEntry) const = 0;

    /** Tests whether a given entry occurs in this binary tree.
     * @post The binary search tree is unchanged.
     * @param anEntry The entry to find.
     * @return True if the search is successful, otherwise false. */
    virtual bool contains(const T& anEntry) const = 0;

    /** Traverse this binary tree in preorder (inorder, postorder) and
     * calls the function visit for each node.
     * @param visit A client-defined function that performs an operation on
     * or with the data in each visited node. */
    virtual void preorderTraverse(void visit(T&)) const = 0;
    virtual void inorderTraverse(void visit(T&)) const = 0;
    virtual void postorderTraverse(void visit(T&)) const = 0;
};

#endif