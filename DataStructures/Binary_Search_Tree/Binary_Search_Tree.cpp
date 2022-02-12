#include<iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *right;
    Node *left;
};

Node *CreateNewNode(int data) {
    Node *new_node = new Node();

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void insert(Node **root, int data) {
    Node *new_node = CreateNewNode(data);

    if (*root == NULL) {
        *root = new_node;
        return;
    }  
    else if (data <= (*root)->data) {
        return insert(&((*root)->left), data);
    }
    else return insert(&((*root)->right), data);
}

bool search(Node *root, int data) {
    bool result = false;

    if (root == NULL) return result;
    else if (data == root->data) {
        result = true;
    }
    else if (data <= root->data) {
        result = search(root->left, data);
    }
    else result = search(root->right, data);

    return result;
}

int FindMin(Node *root) {
    if (root == NULL) {
        cout << "Cây không tồn tại nên không có giá trị nhỏ nhất!\n";
        return -1;
    }

    Node *curr = root;

    while (curr->left != NULL) {
        curr = curr->left;
    }
    return curr->data;
}

int FindMax(Node *root) {
    if (root == NULL) {
        cout << "Cây không tồn tại nên không có giá trị lớn nhất!\n";
        return -1;
    }

    Node *curr = root;

    while (curr->right != NULL) {
        curr = curr->right;
    }
    return curr->data;
}

int FindHeight(Node *root) {
    if (root == NULL) {
        return -1;
    }

    int leftHeight = FindHeight(root->left);

    int rightHeight = FindHeight(root->right);


    return (leftHeight >= rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}

void print(Node *root) {
    cout << root->data << " ";
    if (root->left != NULL) {
        print(root->left);
    }
    if (root->right != NULL) {
        print(root->right);
    }
}

int main() {
    Node *root;
    root = NULL;

    int n;
    cout << "Nhập số liệu: ";
    cin >> n;

    while (n--) {
        int data;
        cout << "Nhập data: ";
        cin >> data;

        insert(&root, data);
    }

    cout << "Cây hiện tại: ";
    print(root);
    cout << endl;    

    int x;
    cout << "Nhập số cần tìm: ";
    cin >> x;

    bool result = search(root, x);
    if (result) {
        cout << "Có tồn tại " << x << endl;
    }
    else cout << "Không tồn tại " << x << endl;

    char a;
    cout << "Tìm max(M) hay min(m) hay cả hai(b): ";
    cin.ignore();
    cin >> a;

    if (a == 'm' || a == 'b') {
        int min = FindMin(root);
        if (root != NULL) cout << "Giá trị nhỏ nhất: " << min << endl;
    }
    if (a == 'M' || a == 'b') {
        int max = FindMax(root);
        if (root != NULL) cout << "Giá trị lớn nhất: " << max << endl;
    }

    if (FindHeight(root) > -1) cout << "Chiều cao của cây là: " << FindHeight(root) << endl;
    else cout << "Cây không tồn tại nên không có chiều cao!\n"; 

    return 0;
}