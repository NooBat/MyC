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

Node* insert(Node *root, int data) {
    if (root == NULL) {
        root = CreateNewNode(data);
        return root;
    }
    else if (data <= root->data) {
        root->left = insert(root->left, data);
    }
    else root->right = insert(root->right, data);

    return root;
}

void printPreorder(Node *root) {
    if (root == NULL) return;

    cout << root->data << " ";

    printPreorder(root->left);

    printPreorder(root->right);
}

void printInorder(Node *root) {
    if (root == NULL) return;

    printInorder(root->left);

    cout << root->data << " ";

    printInorder(root->right);
}

int main() {
    Node *root = NULL;

    int n;
    cout << "Nhập số liệu: ";
    cin >> n;

    while(n--) {
        int data;
        cout << "Nhập data: ";
        cin >> data;

        root = insert(root, data);
    }
    cout << "Cây theo preorder: ";
    printPreorder(root);
    cout << endl;

    cout << "Cây theo inorder: ";
    printInorder(root);
    cout << endl;

    return 0;
}