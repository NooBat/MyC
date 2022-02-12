#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;
    int height;
};

int max(int a, int b) {
    return (a >= b) ? (a) : (b);
}

int getHeight(Node *N) {
    if (N == NULL) return -1;

    return N->height;
}

int BalanceFactor(Node *N) {
    if (N == NULL) return 0;
    return getHeight(N->left) - getHeight(N->right);
}

Node *findMinValNode(Node *root) {
    Node *curr = root;

    while (curr->left != NULL) {
        curr = curr->left;
    }

    return curr;
}

Node *createNode(int data) {
    Node *newNode = new Node();

    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->height = 0;

    return newNode;
}

Node *leftRotation(Node *N) {
    Node *RightChild = N->right;
    Node *leftSubtree = RightChild->left;

    RightChild->left = N;
    N->right = leftSubtree;

    RightChild->height = max(getHeight(RightChild->left), getHeight(RightChild->right)) + 1;
    N->height = max(getHeight(N->left), getHeight(N->right)) + 1;

    return RightChild;
}

Node *rightRotation(Node *N) {
    Node *LeftChild = N->left;
    Node *rightSubtree = LeftChild->right;

    LeftChild->right = N;
    N->left = rightSubtree;

    LeftChild->height = max(getHeight(LeftChild->left), getHeight(LeftChild->right)) + 1;
    N->height = max(getHeight(N->left), getHeight(N->right)) + 1;

    return LeftChild;
}

Node *insert(Node *root, int data) {
    if (root == NULL) return createNode(data);
    if (data > root->data) root->right = insert(root->right, data);
    else if (data < root->data) root->left = insert(root->left, data);
    else return root;

    //update height
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    int bf = BalanceFactor(root);

    if (bf > 1 && data < root->left->data) {
        return rightRotation(root);
    }
    else if (bf > 1 && data > root->left->data) {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    else if (bf < -1 && data > root->right->data) {
        return leftRotation(root);
    }
    else if (bf < -1 && data < root->right->data) {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
}

Node *deleteNode(Node *root, int data) {
    if (root == NULL) return root;

    if (data > root->data) root->right = deleteNode(root->right, data);
    else if (data < root->data) root->left = deleteNode(root->left, data);
    else {
        //Found the node to be deleted
        //if the node has no children
        if (root->left == NULL && root->right == NULL) {
            return NULL;
        }
        //if the node has 1 child
        else if (root->left == NULL) {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL){
            Node *temp = root->left;
            delete root;
            return temp;
        }
        //if the node has 2 children
        else {
            Node *temp = findMinValNode(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }

        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

        int bf = BalanceFactor(root);

        if (bf > 1 && BalanceFactor(root->left) >= 0) {
            return rightRotation(root);
        }
        else if (bf > 1 && BalanceFactor(root->left) < 0) {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
        else if (bf < -1 && BalanceFactor(root->right) >= 0) {
            return leftRotation(root);
        }
        else if (bf < -1 && BalanceFactor(root->right) < 0) {
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    } 

    return root;
}

void printTree(Node *root) {
    if (root == NULL) {
        cout << "Tree is empty!\n";
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node *curr = q.front();
        q.pop();

        if (curr == NULL) {
            cout << "N ";
        }
        else {
            cout << curr->data << " ";
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    cout << endl;
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

        root = insert(root, data);
    }

    cout << endl << "AVL tree: ";
    printTree(root);

    int x;
    cout << "Input number of nodes to be deleted: ";
    cin >> x;

    for (int i = 0; i < x; i++) {
        int data;
        cout << "Input data NO." << i + 1 << ": ";
        cin >> data;

        root = deleteNode(root, data);

        cout << "Tree after delete: ";
        printTree(root);
    }

    return 0;
}