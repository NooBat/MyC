#include<iostream>
#include<string>
#include<iterator>

using namespace std;

class BSTNode
{
public:
    int val;
    BSTNode* left;
    BSTNode* right;
    BSTNode()
    {
        this->left = this->right = nullptr;
    }

    BSTNode(int val)
    {   
        this->val = val;
        this->left = this->right = nullptr;
    }

    BSTNode(int val, BSTNode* left, BSTNode* right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }

    BSTNode* addNode(BSTNode* root, int value)
    {
        if (!root) 
        {
            root = new BSTNode(value);
            return root;
        }

        if (value > root->val) root->right = addNode(root->right, value);
        else root->left = addNode(root->left, value);

        return root;
    }

    template<class BirdIt>
    static BSTNode* createBSTree(BirdIt first, BirdIt last)
    {
        BSTNode* root = nullptr;

        for (; first != last; first++)
        {
            int value = *first;

            root = root->addNode(root, value);
        }

        return root;
    }

    static void printPreorder(BSTNode* root)
    {
        if (!root) return;

        cout << root->val << " ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
};

int inOrderSuccessor(BSTNode* root)
{
    while (!root->left)
    {
        root = root->left;
    }

    return root->val;
}

BSTNode* deleteNode(BSTNode* root, int value)
{
    if (!root) return root;

    if (value < root->val) root->left = deleteNode(root->left, value);
    else if (value > root->val) root->right = deleteNode(root->right, value);
    else
    {
        if (!root->left && !root->right)
        {
            delete root;
            return nullptr;
        }
        else if (!root->left)
        {
            BSTNode* rightChild = root->right;
            delete root;
            root = root->right;
        }
        else if (!root->right)
        {
            BSTNode* leftChild = root->left;
            delete root;
            root = root->left;
        }
        else
        {
            int newValue = inOrderSuccessor(root->right);
            root->val = newValue;
            root->right = deleteNode(root->right, newValue);
        }
    }

    return root;
}

BSTNode* subtreeWithRange(BSTNode* root, int lo, int hi) {
    if (!root)
        return root;
    
    root->left = subtreeWithRange(root->left, lo, hi);
    root->right = subtreeWithRange(root->right, lo, hi);

    if (root->val < lo || root->val > hi)
    {
        root = deleteNode(root, root->val);
    }

    return root;
}

int main()
{
    int arr[] = {13, 18, 12, 8, 10, 4, 5, 15, 19, 14, 16, 1, 9, 7, 6, 3, 11, 0, 17, 2};
    int lo = 4, hi = 14;
    BSTNode* root = BSTNode::createBSTree(arr, arr + sizeof(arr)/sizeof(int));
    root = subtreeWithRange(root, lo, hi);
    BSTNode::printPreorder(root);

    return 0;
}
