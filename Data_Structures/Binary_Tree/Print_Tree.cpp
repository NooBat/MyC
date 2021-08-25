#include<iostream>
#include<queue>

using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;
};

int FindHeight(Node *root) {
    if (root == NULL) return -1;

    int LeftHeight = FindHeight(root->left);
    int RightHeight = FindHeight(root->right);

    return (LeftHeight >= RightHeight) ? (LeftHeight + 1) : (RightHeight + 1);
}

Node *createNode(int data) {
    Node *new_node = new Node();

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

Node *insert(Node *root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    queue<Node *> q;
    q.push(root);
    Node *curr;

    while (!q.empty()) {
        curr = q.front();
        q.pop();

        if (curr->left == NULL) {
            curr->left = createNode(data);
            break;
        }
        else q.push(curr->left);
        if (curr->right == NULL) {
            curr->right = createNode(data);
            break;
        }
        else q.push(curr->right);
    }
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

void printLeaves(Node *root) {
    if (root == NULL) {
        return;
    }

    printLeaves(root->left);
    
    printLeaves(root->right);

    if (root->left == NULL && root->right == NULL) {
        cout << root->data << " ";
    }
}

void printAtDepth(Node *root, int k) {
    if (root == NULL) {
        return;
    }
    if (k == 0) {
        cout << root->data << " ";
        return;
    }
    printAtDepth(root->left, k - 1);
    printAtDepth(root->right, k - 1);
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

    cout << endl;

    cout << "Left view of tree: ";
    print(root->left);

    cout << endl;

    cout << "Right view of tree: ";
    print(root->right);

    cout << endl;

    cout << "Every leaves of tree: ";
    printLeaves(root);

    cout << endl;

    int h = FindHeight(root);

    int k;
    cout << endl;
    cout << "Input the level to print: ";
    cin >> k;

    while (k > h) {
        cout << "The level must be lower than " << h << "!\n";
        cout << "Input again: ";
        cin >> k;
    }

    printAtDepth(root, k);
    cout << endl;

    return 0;
}  