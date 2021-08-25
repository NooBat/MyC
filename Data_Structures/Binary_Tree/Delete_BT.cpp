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

void insert(Node *&root, int data) {
    if (root == NULL) {
        root = CreateNewNode(data);
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node *curr = q.front();
        q.pop();

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
    
    return;
}

Node *deleteLowest(Node *root, Node *far) {
    queue<Node*> q;
    q.push(root);
    Node *temp;

    while (!q.empty()) {
        temp = q.front();
        q.pop();

        if (temp->right != NULL) {
            if (temp->right == far) {
                temp->right = NULL;
                return root;
            }
            else q.push(temp->right);
        }
        if (temp->left != NULL) {
            if (temp->left == far) {
                temp->left = NULL;
                return root;
            }
            else q.push(temp->left);
        }
    }
    return root;
}

Node *deletionBT(Node *root, int x) {
    if (root == NULL) {
        return root;
    }

    //if the node has no child
    if (root->left == NULL && root->right == NULL) {
        if (root->data == x) {
            return NULL;
        }
        return root;
    }

    queue<Node*> q;
    q.push(root);
    Node *node_x = NULL;
    Node *temp;

    //Do a Level Order Traversal to find the node
    while (!q.empty()) {
        temp = q.front();
        q.pop();

        if (temp->data == x) {
            node_x = temp;
        }
        if (temp->left != NULL) {
            q.push(temp->left);
        }
        if (temp->right != NULL) {
            q.push(temp->right);
        }
    }

    int value = temp->data;
    root = deleteLowest(root, temp);
    node_x->data = value;
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

int main() {
    Node *root = NULL;

    int n;
    cout << "Input number of nodes: ";
    cin >> n;

    while (n--) {
        int data;
        cout << "Input data: ";
        cin >> data;

        insert(root, data);
    }
    cout << endl;
    cout << "Tree Inorder: ";
    print(root);
    cout << endl;
    cout << endl;

    int x;
    cout << "Input number to delete: ";
    cin >> x;
    cout << endl;

    root = deletionBT(root, x);

    cout << "Tree after deletion: ";
    print(root);
    cout << endl;

    return 0;
}