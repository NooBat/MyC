#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;
};

Node *CreateNode(int data) {
    Node *new_node = new Node();

    new_node->data = data;
    new_node->left = new_node->right = NULL;

    return new_node;
}

Node *createTree(string str) {
    if (str.length() == 0 || str[0] == 'N') {
        return NULL;
    }

    vector<string> v;

    istringstream iss(str);
    for (string str; iss >> str; ) {
        v.push_back(str);
    }

    Node *root = CreateNode(stoi(v[0]));

    int i = 1;

    queue<Node *> q;
    q.push(root);

    while (!q.empty() && i < v.size()) {
        Node *curr = q.front();
        q.pop();

        string currVal = v[i];

        //Implementing left child
        if (currVal != "N") {
            curr->left = CreateNode(stoi(currVal));
            q.push(curr->left);
        }

        ++i;

        if (i >= v.size()) break;
        
        currVal = v[i];

        //Implementing right child
        if (currVal != "N") {
            curr->right = CreateNode(stoi(currVal));
            q.push(curr->right);
        }

        ++i;
    }

    return root;
}

void print(Node *root) {
    if (root == NULL) {
        cout << "Tree is empty!\n";
        return;
    }
    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
        Node *curr = q.front();
        q.pop();

        cout << curr->data << " ";
        
        if (curr->left != NULL) {
            q.push(curr->left);
        }
        if (curr->right != NULL) {
            q.push(curr->right);
        }

    }
    cout << endl;
}

int main() {
    Node *root = NULL;
    
    string str;
    cout << "Input tree in level order: ";
    getline(cin, str);

    root = createTree(str);

    cout << "Tree: ";
    print(root);

    return 0;
}