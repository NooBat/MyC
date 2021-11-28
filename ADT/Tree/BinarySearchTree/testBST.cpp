#include "BinarySearchTree.hpp"
#include "BinarySearchTree.cpp"
#include<iostream>
#include<string>

using namespace std;

void visit(string &a)
{
    cout << a << " ";
}

void testBST(BinarySearchTree<string>& tree)
{
    cout << "The initial tree is empty" << endl;
    cout << "isEmpty(): returns " << tree.isEmpty() << "; should be 1 (true)." << endl;
    cout << endl << endl;

    string arr[] = {"genesis", "eve", "new", "adam", "syslink"};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; ++i)
    {
        tree.add(arr[i]);
    }

    cout << "isEmpty(): returns " << tree.isEmpty() << "; should be 0 (false)." << endl;
    cout << "getRootData(): returns " << tree.getRootData() << "; should be \"genesis\"." << endl;
    cout << "getHeight(): returns " << tree.getHeight() << "; should be 3." << endl;
    cout << endl << endl;
    
    cout << "Inorder traversal: ";
    tree.inorderTraverse(visit); 
    cout << "; should be adam eve genesis new syslink";
    cout << endl << endl;

    cout << "remove(\"bronson\"): returns " << tree.remove("bronson") << "; should be 0 (false)." << endl;
    cout << "remove(\"syslink\"): returns " << tree.remove("syslink") << "; should be 1 (true)." << endl;
    cout << "Inorder traversal: ";
    tree.inorderTraverse(visit);
    cout << "; should be adam eve genesis new" << endl;
    cout << "remove(\"genesis\"): returns " << tree.remove("genesis") << "; should be 1 (true)." << endl;
    cout << "Inorder traversal: ";
    tree.inorderTraverse(visit);
    cout << "; should be adam eve new" << endl;  
    cout << endl << endl;
}

int main()
{
    BinarySearchTree<string> tree;

    cout << "Testing link-based Binary Search Tree." << endl;
    testBST(tree);
    cout << "All done!";

    return 0;
}