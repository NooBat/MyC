#include<iostream>

using namespace std;

class Node {
    public:
    int data;
    int count;
    Node *left;
    Node *right;
};

Node *CreateNode(int data) {
    Node *new_node = new Node();

    new_node->data = data;
    new_node->count = 1;
    new_node->left = new_node->right = NULL;

    return new_node;
}

Node *insert(Node *root, int data) {
    if (root == NULL) {
        root = CreateNode(data);
        return root;
    }
    else if (data == root->data) {
        root->count += 1;
        return root;
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    else root->left = insert(root->left, data);

    return root;
}

void print(Node *root) {
    if (root == NULL) return;

    print(root->left);

    cout << root->data << "(" << root->count << ") ";

    print(root->right);
}

int main() {
    Node *root = NULL;

    int n;
    cout << "Input number of data: ";
    cin >> n;
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << "Input data " << i + 1 << ": ";
        int data;
        cin >> data;

        root = insert(root, data);
    }

    cout << endl;

    cout << "Tree is: ";
    print(root);

    cout << endl;

    return 0;
}