//GST is Greater Sum Tree, meaning each node in the tree 
//contains sum of the nodes greater than it

#include<iostream>
#include<queue>

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

Node *insertBST(Node *root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }
    if (data >= root->data) root->right = insertBST(root->right, data);
    else root->left = insertBST(root->left, data);
    return root;
}

Node *createGST(Node *root, int &sum) {
    if (root == NULL) return root;
    root->right = createGST(root->right, sum);  

    sum = sum + root->data;

    root->data = sum - root->data;

    root->left = createGST(root->left, sum);
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

        if (curr == NULL) {
            cout << "N ";
        }
        else cout << curr->data << " ";

        if (curr != NULL) {
            q.push(curr->left);
            q.push(curr->right);
        }
    }
}

int main() {
    Node *root = NULL;

    int n;
    cout << "Input number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int data;
        cout << "Input data No." << i + 1 << ": ";
        cin >> data;

        root = insertBST(root, data);
    }

    cout << endl << "Binary Search Tree: ";
    print(root);
    cout << endl;

    int sum = 0;
    root = createGST(root, sum);

    cout << endl << "Change to Greater Sum Tree: ";
    print(root);
    cout << endl;
    
    return 0;
}