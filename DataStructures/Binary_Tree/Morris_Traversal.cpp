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

Node *createTree(string str) {
    if (str.length() == 0 || str[0] == '\0') {
        return NULL;
    }
    vector<string> v;
    stringstream ss(str);

    for (string str; ss >> str; ) {
        v.push_back(str);
    }

    Node *root = createNode(stoi(v[0]));

    int i = 1;
    queue<Node *> q;
    q.push(root);
    Node *curr;

    while (!q.empty() && i < v.size()) {
        curr = q.front();
        q.pop();

        if (v[i] != "N") {
            curr->left = createNode(stoi(v[i]));
        }

        ++i;
        if (i >= v.size()) {
            break;
        }

        if (v[i] != "N") {
            curr->right = createNode(stoi(v[i]));
        }

        ++i;
    }

    return root;
}

void Traverse(Node *root) {
    Node *curr = root;
    Node *pre;

    if (root == NULL) {
        cout << "Tree is empty!\n";
        return;
    }

    while (curr != NULL) {
        if (curr->left == NULL) {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else {
            pre = curr->left;
            
            while(pre->right != NULL && pre->right != curr) {
                pre = pre->right;
            }

            if (pre->right == NULL) {
                pre->right = curr;
                curr = curr->left;
            }

            else {
                pre->right = NULL; 
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    } 
}

int main() {
    Node *root = NULL;

    string str;
    cout << "Input tree: ";
    getline(cin, str);

    root = createTree(str);

    cout << endl << "Tree: ";
    Traverse(root);
    cout << endl;

    return 0;
}