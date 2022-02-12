#include<iostream>
#include<queue>

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
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

Node *insert(Node *root, int data) {
    if (root == NULL) {
        root = CreateNewNode(data);
        return root;
    }
    else if (data <= root->data) {
        root->left = insert(root->left, data);
    }
    else root->right = insert(root->right, data);

    return root;
}

void print(Node *root) {
    if (root == NULL) return;

    queue<Node *> q;
    q.push(root);

    //while there is at least one discovered node
    while (!q.empty()) {
        Node *curr = q.front();

        cout << curr->data << " ";
        
        if (curr->left != NULL) q.push(curr->left);

        if (curr->right != NULL) q.push(curr->right);

        q.pop();
    }
}

int main() {
    Node *root = NULL;

    int n;
    cout << "Nhập số liệu: ";
    cin >> n;
    
    while(n--) {
        int data;
        cout << "Nhập data: ";
        cin >> data;

        root = insert(root, data);
    }

    cout << "Cây hiện tại: ";
    print(root);
    cout << endl;

    return 0;
}