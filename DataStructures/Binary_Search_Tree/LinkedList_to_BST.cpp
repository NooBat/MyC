#include<iostream>
#include<queue>
#include<vector>

using namespace std;

//Class for linked list node
class ListNode {
    public: 
    int data;
    ListNode *next;
};

//Class for tree node
class TreeNode {
    public: 
    int data;
    TreeNode *left;
    TreeNode *right;
};

void merge(vector<int> &arr, int l, int r, int mid) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for(int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + j + 1];
    }

    int k = l;  //index for sorted arr
    int i = 0;  //index for L
    int j = 0;  //index for R

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
        ++k;
        ++i;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<int> &arr, int l, int r) {
    if (l >= r) return;

    int mid = (l + r) / 2;

    mergeSort(arr, 0, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, r, mid);
}

ListNode *createNode(int data) {
    ListNode *newNode = new ListNode();

    newNode->data = data;   
    newNode->next = NULL;

    return newNode;
}

void insertList(ListNode **head, int data) {
    if (*head == NULL) {
        *head = createNode(data);
        return;
    }

    ListNode *temp = createNode(data);
    temp->next = *head;
    *head = temp;
}

void printList(ListNode *p) {
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

vector<int> input(ListNode *head) {
    vector<int> v;

    if (head == NULL) return v;

    while (head != NULL) {
        v.push_back(head->data);
        head = head->next;
    }

    return v;
}

void SortList(ListNode **head) {
    vector<int> v = input(*head);

    mergeSort(v, 0, v.size() - 1);

    ListNode *p = *head;
    for (int i = 0; i < v.size(); i++) {
        p->data = v[i];
        p = p->next;
    }
}

TreeNode *createTreeNode(int data) {
    TreeNode *newNode = new TreeNode();

    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

int countListNode(ListNode *p) {
    int count = 0; 
    while (p != NULL) {
        ++count;
        p = p->next;
    }

    return count;
}

TreeNode *createBST(ListNode **head, int n) {
    if (n <= 0) return NULL;

    TreeNode *left = createBST(head, n / 2);

    TreeNode *root = createTreeNode((*head)->data);
    root->left = left;

    *head = (*head)->next;

    root->right = createBST(head, n - n/2 - 1);

    return root;
}

void printTree(TreeNode *root) {
    if (root == NULL) {
        cout << "Tree is empty!\n";
        return;
    }

    queue<TreeNode *> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode *curr = q.front();
        q.pop();

        if (curr == NULL) cout << "N ";
        else cout << curr->data << " ";

        if (curr != NULL) {
            q.push(curr->left);
            q.push(curr->right);
        }
    }

    cout << endl;
}

int main() {
    ListNode *head = NULL;
    TreeNode *root = NULL;

    int n;
    cout << "Input number of List nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int data;
        cout << "Input data " << i + 1 << ": ";
        cin >> data;

        insertList(&head, data);
    }

    cout << endl;
    cout << "List: ";
    printList(head);

    SortList(&head);

    cout << endl << "Binary Search Tree from List: ";
    int k = countListNode(head);

    root = createBST(&head, k);

    printTree(root);

    return 0;
}