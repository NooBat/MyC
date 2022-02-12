#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int data) {
    Node *newNode = new Node();

    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

Node *createBST(int data, Node *root) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    if (data >= root->data) root->right = createBST(data, root->right);
    else root->left = createBST(data, root->left);

    return root;
}

Node *ConstructBST(Node *root, int arr[], int n) {
    if (n == 0) return NULL;

    for (int i = 0; i < n; i++) {
        root = createBST(arr[i], root);
    }

    return root;
}

void printTree(Node *root) {
    if (root == NULL) {
        cout << "Tree is empty!\n";
        return;
    }

    queue<Node *> q;
    q.push(root);

    while(!q.empty()) {
        Node *curr = q.front();
        q.pop();

        if (curr == NULL) cout << "N ";
        else cout << curr->data << " ";

        if (curr != NULL) {
            q.push(curr->left);
            q.push(curr->right);
        }
    }

    cout << endl;
}


int main() {
    Node *root = NULL;

    int n;
    cout << "Input number of elements in array: ";
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cout << "Input data NO." << i + 1 << ": ";
        cin >> arr[i];
    }

    root = ConstructBST(root, arr, n);
    cout << "Binary Search Tree: ";
    printTree(root);

    return 0;
}