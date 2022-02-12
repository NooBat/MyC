//SST is Smaller Sum Tree, meaning each node in this tree
//contains sum of all the smaller node

#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;
};

Node *CreateNode(int data) {
    Node *newNode = new Node();

    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

Node *insertBST(Node *root, int data) {
    if (root == NULL) {
        root = CreateNode(data);
        return root;
    }

    if (data > root->data) root->right = insertBST(root->right, data);
    else if (data < root->data) root->left = insertBST(root->left, data);
    else return root;

    return root;
}

Node *changeSST(Node *root, int &sum) {
    if (root == NULL) return root;

    root->left = changeSST(root->left, sum);

    sum = sum + root->data;
    
    root->data = sum - root->data;

    root->right = changeSST(root->right, sum);

    return root;
}

void print(Node *root) {
    if (root == NULL) {
        return;
    }
    print(root->left);

    cout << root->data << " ";

    print(root->right);
}

int main() {
    Node *root = NULL;

    int n;
    cout << "Input number of nodes: ";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int data;
        cout << "Input data NO." << i + 1 << ": ";
        cin >> data;

        root = insertBST(root, data);
    }

    cout << endl << "Binary Search Tree: ";
    print(root);
    
    int sum = 0;
    root = changeSST(root, sum);

    cout << endl << "Change to Smaller Sum Tree: ";
    print(root);

    return 0;
}