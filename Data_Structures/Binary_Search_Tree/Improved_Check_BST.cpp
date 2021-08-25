#include<iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;
};

Node *CreateNewNode(int data) {
    Node *new_node = new Node();
    
    new_node->data = data;
    new_node->left = new_node->right = NULL;

    return new_node;
}

bool IsBinarySearchTree(Node *root, int minValue, int maxValue) {
    if (root == NULL) return true;
    else if (root->data > minValue && root->data < maxValue
            && IsBinarySearchTree(root->left, minValue, root->data)
            && IsBinarySearchTree(root->right, root->data, maxValue))
        return true;
    else return false;
}

int temp;
bool Inorder(Node *root, int value) {
    if (root == NULL) {
        return true;
    }

    Inorder(root->left, root->data);

    if (root->data > value) return false;   

    Inorder(root->right, root->data);

    if (temp < root->data) return;
}

int main() {
    Node *root;
    Node *leftChild = CreateNewNode(9);
    Node *rightChild = CreateNewNode(20);

    root = CreateNewNode(10);
    root->left = leftChild;
    root->right = rightChild;

    cout << IsBinarySearchTree(root, INT_MIN, INT_MAX);

    return 0;
}