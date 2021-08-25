#include<iostream>
#include<queue>

using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;
};

Node *CreateNewNode(int data) {
    Node *new_node = new Node();

    new_node->data = data;
    new_node->left = new_node->right = NULL;

    return new_node;
}
//Do insertion of node by level order traversal
//Traverse through tree to find the first empty child 
Node *insert(Node *root, int data) {
    if (root == NULL) {
        root = CreateNewNode(data);
        return root;
    }
    
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node *curr = q.front();
        q.pop();
        //check whether the current node's children are empty or not
        if (curr->left != NULL) {
            q.push(curr->left);
        }
        else {
            curr->left = CreateNewNode(data);
            break;
        }

        if (curr->right != NULL) {
            q.push(curr->right);
        }
        else {
            curr->right = CreateNewNode(data);
            break;
        } 
    }
    return root;
}
//print the tree by Level Order Traversal
void print(Node *root) {
    if (root == NULL) {
        cout << "Tree is empty!\n";
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node *curr = q.front();

        cout << curr->data << " ";
        if (curr->left != NULL) {
            q.push(curr->left);
        }
        if (curr->right != NULL) {
            q.push(curr->right);
        }
        q.pop();
    }
}

int main() {
    Node *root = NULL;

    int n;
    cout << "Input number of nodes: ";
    cin >> n;

    while (n--) {
        int data;
        cout << "Input data: ";
        cin >> data;

        root = insert(root, data);
    }

    cout << "Tree has: ";
    print(root);
    cout << endl;

    return 0;
}