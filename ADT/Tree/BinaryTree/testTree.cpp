#include "BinaryNodeTree.hpp"
#include "BinaryNodeTree.cpp"
#include<iostream>
#include<string>

using namespace std;

void visit(string &a) 
{
    cout << a << " ";
}

void testTree(BinaryNodeTree<string>& tree)
{
    cout << "The initial tree is empty" << endl;
    cout << "isEmpty(): returns " << tree.isEmpty() << "; should be 1 (true)." << endl;
    cout << endl << endl;

    string arr[] = {"adam", "eve", "genesis", "new", "geneva"};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; ++i)
    {
        tree.add(arr[i]);
    }

    cout << "isEmpty(): returns " << tree.isEmpty() << "; should be 0 (false)." << endl;
    cout << "getRootData(): returns " << tree.getRootData() << "; should be \"adam\"." << endl;
    cout << "Inorder traversal: ";
    tree.inorderTraverse(visit); 
    cout << "; should be new eve adam geneva genesis";
    cout << endl << endl;

    cout << "remove(\"bronson\"): returns " << tree.remove("bronson") << "; should be 0 (false)." << endl;
    cout << "remove(\"geneva\"): returns " << tree.remove("geneva") << "; should be 1 (true)." << endl;
    cout << "Inorder traversal: ";
    tree.inorderTraverse(visit);
    cout << "; should be new eve adam genesis" << endl;
    cout << "remove(\"adam\"): returns " << tree.remove("adam") << "; should be 1 (true)." << endl;
    cout << "Inorder traversal: ";
    tree.inorderTraverse(visit);
    cout << "; should be new eve genesis" << endl;  
    cout << endl << endl;
}

int main()
{
    BinaryNodeTree<string> tree;
    cout << "Testing link-based binary tree";
    testTree(tree);

    cout << "All done!";

    return 0;
}