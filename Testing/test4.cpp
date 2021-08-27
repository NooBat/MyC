#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<sstream>
#include<cmath>
#include<algorithm>

using namespace std;

class TreeNode {
public: 
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() {
        val = 0;
        left = right = nullptr;
    }

    TreeNode(int val) {
        this->val = val;
        left = right = nullptr;
    }
};

TreeNode *createTree(string str) {
    if (str.length() == 0 || str[0] == 'N') {
        return NULL;
    }

    vector<string> v;

    istringstream iss(str);
    for (string str; iss >> str; ) {
        v.push_back(str);
    }

    TreeNode *root = new TreeNode(stoi(v[0]));

    int i = 1;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty() && i < v.size()) {
        TreeNode *curr = q.front();
        q.pop();

        string currVal = v[i];

        //Implementing left child
        if (currVal != "N") {
            curr->left = new TreeNode(stoi(currVal));
            q.push(curr->left);
        }

        ++i;

        if (i >= v.size()) break;
        
        currVal = v[i];

        //Implementing right child
        if (currVal != "N") {
            curr->right = new TreeNode(stoi(currVal));
            q.push(curr->right);
        }

        ++i;
    }

    return root;
}

class Solution {
public:
    void sumNode(TreeNode* root) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) return;
        
        if (root->left == nullptr) {
            root->right->val += root->val;
            sumNode(root->right);
            return;
        }
        if (root->right == nullptr) {
            root->left->val += root->val;
            sumNode(root->left);
            return;
        }
        
        root->right->val += root->val;
        root->left->val += root->val;
        sumNode(root->right);
        sumNode(root->left);
    }
    void traverse(TreeNode* root, int targetSum, bool& result) {
        if (root == nullptr) return;
        
        traverse(root->left, targetSum, result);
        if (root->left == nullptr && root->right == nullptr) {
            if (root->val == targetSum) result = true;
            return;
        }
        traverse(root->right, targetSum, result);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        sumNode(root);
        
        bool result;
        traverse(root, targetSum, result);

        return result;
    }
};

void print(TreeNode *root) {
    if (root == NULL) {
        cout << "Tree is empty!\n";
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode *curr = q.front();
        q.pop();

        if (curr == NULL) {
            cout << "N ";
        }
        else {
            cout << curr->val << " ";
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    cout << endl;
}

int main() {  
    TreeNode* root = nullptr;
    int a = 22;

    string str = "5 4 8 11 N 13 4 7 2 N N N 1";

    root = createTree(str);

    print(root);

    Solution obj;

    cout << obj.hasPathSum(root, a) << endl;

    print(root);
    return 0;
}
