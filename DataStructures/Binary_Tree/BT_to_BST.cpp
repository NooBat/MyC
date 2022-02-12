#include<iostream>
#include<vector>
#include<queue>
#include<sstream>
#include<string>

using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int data) {
    Node *newNode = new Node();

    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode; 
}

void merge(vector<int> &arr, int l, int r, int mid) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    int i, j;
    int k = l; 
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (i = 0; i < n2; i++) {
        R[i] = arr[mid + i + 1];
    }
    i = 0;
    j = 0;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        k++;
        i++;
    }

    while (j < n2) {
        arr[k] = R[j];
        k++;
        j++;
    }
}

void mergeSort(vector<int> &arr, int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    mergeSort(arr, 0, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, r, mid);
}

Node *createTree(string str) {
    if (str.length() == 0 || str[0] == 'N') {
        return NULL;
    }

    vector<string> input;
    stringstream ss(str);

    while (ss >> str) {
        input.push_back(str);
    }

    Node *root = newNode(stoi(input[0]));

    queue<Node *> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < input.size()) {
        Node *curr = q.front();
        q.pop();

        string value = input[i];
        
        //Implement left child first
        if (value != "N") {
            curr->left = newNode(stoi(value));
            q.push(curr->left);
        } 
        ++i;

        if (i >= input.size()) break;

        value = input[i];

        //Implement right child after left
        if (value != "N") {
            curr->right = newNode(stoi(value));
            q.push(curr->right);
        }
        ++i;
    }

    return root;
}

void InorderInput(Node *root, vector<int> &v) {
    if (root == NULL) return;

    InorderInput(root->left, v);

    v.push_back(root->data);

    InorderInput(root->right, v);
}

void change(Node *&root, vector<int> v, int &i) {
    if (root == NULL) return;

    change(root->left, v, i);

    root->data = v[i];
    ++i;

    change(root->right, v, i);
}

Node *changeBT(Node *root) {
    if (root == NULL) return root;

    vector<int> v;

    InorderInput(root, v);

    mergeSort(v, 0, v.size() - 1);
    int i = 0;
    change(root, v, i);

    return root;
}

int findHeight(Node *root) {
    if (root == NULL) {
        return -1;
    }

    int left = findHeight(root->left);
    int right = findHeight(root->right);

    return (left >= right) ? (left + 1) : (right + 1);
}

bool checkBalanced(Node *root) {
    if (root == NULL) {
        return true;
    }

    int left = findHeight(root->left);
    int right = findHeight(root->right);

    int diff = (left >= right) ? (left - right) : (right - left);

    if (diff <= 1 && checkBalanced(root->left)
        && checkBalanced(root->right)) {
            return true;
        }
    else return false;
}

void print(Node *root) {
    if (root == NULL) return;

    print(root->left);

    cout << root->data << " ";

    print(root->right);
}

int main() {
    Node *root;

    string str;
    cout << "Input tree in level order: ";
    getline(cin, str);

    root = createTree(str);

    cout << "Binary Tree: ";
    print(root);
    cout << endl << endl;

    if (checkBalanced(root)) {
        cout << "Tree is balanced\n";
    }
    else cout << "Tree is not balanced\n";

    root = changeBT(root);

    cout << "Binary Search Tree: ";
    print(root);
    cout << endl << endl;

    if (checkBalanced(root)) {
        cout << "Tree is balanced\n";
    }
    else cout << "Tree is not balanced\n";

    return 0;
}