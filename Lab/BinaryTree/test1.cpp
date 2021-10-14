#include "Ex1.hpp"

int main()
{
    BinaryTree<int, int> binaryTree;
    binaryTree.addNode("", 2, 4); // Add to root 
    binaryTree.addNode("L", 3, 2); // Add to root's left node 
    binaryTree.addNode("R", 5, 9); // Add to root's right node
    binaryTree.addNode("LL", 4, 1);
    binaryTree.addNode("LR", 7, 7);
    binaryTree.addNode("RL", 1, 6);
    binaryTree.addNode("RR", 10, 10);


    cout << binaryTree.isBST();

    return 0;
}