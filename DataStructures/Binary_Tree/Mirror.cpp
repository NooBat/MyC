#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;
};

Node *createNode(int data) {
    Node *newNode = new Node();

    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

Node *buildTree(string str) {
    if (str.length() == 0 || str[0] == '\0') return NULL;

    stringstream ss(str);

    vector<string> v;
    for (string str; ss >> str; ) {
        v.push_back(str);
    }

    Node *root = createNode(stoi(v[0]));

    int i = 1;
    queue<Node *> q;
    q.push(root);
    
    while (!q.empty() && i < v.size()) {
        Node *temp = q.front();
        q.pop();

        if (v[i] == "N") temp->left = NULL;
        else {
            temp->left = createNode(stoi(v[i]));
            q.push(temp->left);
        }

        ++i;
        if (i >= v.size()) break;
        
        if (v[i] == "N") temp->right = NULL;
        else {
            temp->right = createNode(stoi(v[i]));
            q.push(temp->right);
        }

        ++i;
    }

    return root;
}

class Solution {
    public:
    void Mirror(Node *root) {
        if (root == NULL) return;

        swap(root->left, root->right);
        
        Mirror(root->left);
        
        Mirror(root->right);
    }
};

void print(Node *root) {
    if (root == NULL) {
        cout << "Tree is empty!\n";
    }

    queue<Node *> q;
    q.push(root);

    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL) cout << "N ";
        else {
            cout << temp->data << " ";
            q.push(temp->left);
            q.push(temp->right);
        }
    }

    cout << endl;
}

int main() {
    Node *root = NULL;

    string str;
    cout << "Input tree: ";
    getline(cin, str);

    root = buildTree(str);

    cout << endl;
    cout << "Tree: ";
    print(root);

    Solution s;
    s.Mirror(root);

    cout << endl;
    cout << "Mirror Tree: ";
    print(root);

    return 0;
}