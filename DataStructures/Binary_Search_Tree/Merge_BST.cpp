#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;
};

Node *createNewNode(int data) {
    Node *newNode = new Node();

    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

Node *insert(Node *root, int data) {
    if (root == NULL) {
        root = createNewNode(data);
        return root;
    }

    if (data > root->data) root->right = insert(root->right, data);
    else if (data < root->data) root->left = insert(root->left, data);

    return root;
}

void StoreInorder(Node *root, vector<int> &arr) {
    if (root == NULL) return;

    StoreInorder(root->left, arr);

    arr.push_back(root->data);

    StoreInorder(root->right, arr);
}

void mergeVector(vector<int> &arr1, vector<int> arr2) {
    for (int i = 0; i < arr2.size(); i++) {
        arr1.push_back(arr2[i]);
    }
    sort(arr1.begin(), arr1.end());
}

Node *mergeBST(vector<int> arr, int l, int r) {
    if (arr.size() <= 0) return NULL;

    int mid = (l + r) / 2;
    Node *root = createNewNode(arr[mid]);

    root->left = mergeBST(arr, l, mid - 1);
    root->right = mergeBST(arr, mid + 1, r);

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
    Node *root1 = NULL;
    Node *root2 = NULL;

    int n1; 
    cout << "Input number of nodes for tree NO.1: ";
    cin >> n1;

    for (int i = 0; i < n1; i++) {
        int data;
        cout << "Input data NO." << i + 1 << ": ";
        cin >> data;

        root1 = insert(root1, data);
    }

    cout << endl << "Tree 1: ";
    printTree(root1);
    cout << endl;

    int n2; 
    cout << "Input number of nodes for tree NO.1: ";
    cin >> n2;

    for (int i = 0; i < n2; i++) {
        int data;
        cout << "Input data NO." << i + 1 << ": ";
        cin >> data;

        root2 = insert(root2, data);
    }

    cout << endl << "Tree 2: ";
    printTree(root2);
    cout << endl;

    vector<int> arr1;
    StoreInorder(root1, arr1);

    vector<int> arr2;
    StoreInorder(root2, arr2);

    mergeVector(arr1, arr2);

    Node *root = NULL;
    root = mergeBST(arr1, 0, arr1.size() - 1);

    cout << "Merged Tree: ";
    printTree(root);
    cout << endl;

    return 0;
}