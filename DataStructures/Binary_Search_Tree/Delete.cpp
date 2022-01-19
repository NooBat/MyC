#include<iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;
};

Node *CreateNewNode(int data) {
    Node *new_node = new Node();

    new_node->data = data;
    new_node->left = new_node->right = NULL;

    return new_node;
}

Node* insert(Node *root, int data) {
    if (root == NULL) {
        root = CreateNewNode(data);
        return root;
    }
    else if (data <= root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);

    return root;
}

int checkHeight(Node *root) {
    if (root == NULL) {
        return -1;
    }

    int leftTree = checkHeight(root->left);

    int rightTree = checkHeight(root->right);
    
    return (leftTree >= rightTree) ? (leftTree + 1) : (rightTree + 1);
}

Node *FindMin(Node *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    
    return root;
}

Node *Delete(Node *root, int data) {
    if (root == NULL) return root;
    else if (data < root->data) root->left = Delete(root->left, data);
    else if (data > root->data) root->right = Delete(root->right, data);
    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL) {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL) {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        else {
            Node *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

void inorder(Node *root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right); 
}

int main() {
    Node *root = NULL;

    int n;
    cout << "Nhập số liệu: ";
    cin >> n;

    while (n--) {
        int data;
        cout << "Nhập data: ";
        cin >> data;

        root = insert(root, data);
    }
    cout << "Cây hiện tại: ";
    inorder(root);
    cout << endl;

    cout << "Nhập giá trị cần xoá: ";
    int x;
    cin >> x;

    root = Delete(root, x);
    cout << "Cây sau khi xoá: ";
    inorder(root);
    cout << endl;

    return 0;
}