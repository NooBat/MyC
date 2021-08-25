#include<iostream> 
#include<queue>

using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;
};

void merge(int arr[], int l, int r, int mid) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    } 
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

    int k = l;
    int i = 0;
    int j = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        }
        else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void MergeSort(int arr[], int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;

    MergeSort(arr, l, mid);
    MergeSort(arr, mid + 1, r);
    merge(arr, l, r, mid);
}

Node *createNode(int data) {
    Node *newNode = new Node();

    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

Node *createBST(int arr[], int l, int r) { 
    if (l > r) return NULL;
    int mid = (l + r) / 2;
    Node *root = createNode(arr[mid]);

    root->left = createBST(arr, l, mid - 1);

    root->right = createBST(arr, mid + 1, r);

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

        if (curr == NULL) cout << "N ";
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
    cout << "Input number of elements in array: ";
    cin >> n;

    int arr[n];

    cout << "Input data: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << endl << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    MergeSort(arr, 0, n - 1);

    root = createBST(arr, 0, n - 1);
    
    cout << "Binary Search Tree: ";
    print(root);

    return 0;
}