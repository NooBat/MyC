#include "BinaryNodeTree.hpp"
#include "BinaryNodeTree.cpp"
#include<iostream>
#include<string>

using namespace std;

void v(auto &a) 
{
    cout << a << " ";
}

void testTree(BinaryNodeTree<string>& tree)
{
    cout << "The initial tree is empty" << endl;
    cout << "isEmpty(): returns " << tree.isEmpty() << "; should be 1 (true)." << endl;
    cout << endl << endl;

    string arr[] = {"adam", "eve", "genesis", "new", "geneva", "bronson"};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; ++i)
    {
        tree.add(arr[i]);
    }

    cout << "isEmpty(): returns " << tree.isEmpty() << "; should be 0 (false)." << endl;
    cout << "getRootData(): returns " << tree.getRootData() << "; should be \"adam\"." << endl;
    cout << "Inorder traversal: ";
    tree.inorderTraverse(v); 
    cout << "; should be new eve bronson adam geneva genesis";
    cout << endl << endl;

    cout << "Preorder traversal: ";
    tree.preorderTraverse(v);
    cout << "; should be adam eve new bronson genesis geneva";
    cout << endl << endl;

    cout << "Postorder traversal: ";
    tree.postorderTraverse(v);
    cout << "; should be new bronson eve geneva genesis adam";
    cout << endl << endl;

    cout << "remove(\"bronson\"): returns " << tree.remove("bronson") << "; should be 1 (true)." << endl;
    cout << "remove(\"genevis\"): returns " << tree.remove("genevis") << "; should be 0 (false)." << endl;
    cout << "Inorder traversal: ";
    tree.inorderTraverse(v);
    cout << "; should be new eve adam geneva genesis" << endl;
    cout << "remove(\"adam\"): returns " << tree.remove("adam") << "; should be 1 (true)." << endl;
    cout << "Inorder traversal: ";
    tree.inorderTraverse(v);
    cout << "; should be new eve genesis geneva" << endl;  
    cout << endl << endl;

    cout << "replace(\"new\", \"old\"): returns " << tree.replace("new", "old") << "; should be 1 (true)." << endl;
    cout << "Inorder traversal: ";
    tree.inorderTraverse(v);
    cout << "; should be old eve genesis geneva" << endl; 
    cout << "replace(\"new\", \"old\"): returns " << tree.replace("new", "old") << "; should be 0 (false)." << endl;
    cout << endl << endl;

    cout << "Turn into minimax tree" << endl;
    tree.minimaximizeTree();
    cout << "Inorder traversal: ";
    tree.inorderTraverse(v);
    cout << "; should be old eve genesis geneva" << endl;
    cout << endl << endl;
}

int main()
{
    BinaryNodeTree<string> tree1;
    BinaryNodeTree<int> tree2;
    cout << "Testing link-based binary tree";
    testTree(tree1);

    cout << "All done!";

    return 0;
}