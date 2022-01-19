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
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

bool IsSubtreeLesser(Node *root, int value) {
    if (root == NULL) return true;
    else if (root->data <= value
            && IsSubtreeLesser(root->left, value)
            && IsSubtreeLesser(root->right, value))
        return true;
    else return false;
}

bool IsSubtreeGreater(Node *root, int value) {
    if (root == NULL) return true;
    else if (root->data > value
            && IsSubtreeGreater(root->left, value)
            && IsSubtreeGreater(root->right, value))
        return true;
    else return false;
}

bool IsBinarySearchTree(Node *root) {
    if (root == NULL) return true;
    else if (IsSubtreeLesser(root->left, root->data)
            && IsSubtreeGreater(root->right, root->data)
            && IsBinarySearchTree(root->left)
            && IsBinarySearchTree(root->right)) 
        return true;
    else return false;
}

int main() {
    Node *root = NULL;

    root = CreateNewNode(10);

    Node *leftchild = CreateNewNode(12);

    bool result = IsBinarySearchTree(root);

    if (result) cout << "Đây là cây nhị phân.\n";
    else cout << "Đây không là cây nhị phân.\n";

    cout << endl;
    
    return 0;
}