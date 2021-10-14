#include<string>
#include<iostream>
#include<stack>
#include<queue>

using namespace std;

class ETNode
{
public:
    char val;
    ETNode* left;
    ETNode* right;

    ETNode()
    {
        this->left = this->right = nullptr;
    }

    ETNode(char val)
    {
        this->val = val;
        this->left = this->right = nullptr;
    }

    ETNode(char val, ETNode* left, ETNode* right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }

    static void printInorder(ETNode* root)
    {
        if (!root) return;

        printInorder(root->left);
        cout << root->val << " ";
        printInorder(root->right);
    }
};

ETNode* constructET(string s)
{
    stack<ETNode*> st;
    stack<ETNode*> st2;
    queue<ETNode*> q;

    for (int i = 0; i < s.length(); i++)
    {
        ETNode* newNodePtr = new ETNode(s[i]);
        q.push(newNodePtr);    
    }

    while (!q.empty())
    {
        ETNode* front = q.front();
        q.pop();

        if (front->val >= '0' && front->val <= '9')
        {
            st.push(front);
        }
        else
        {
            ETNode* right = st.top();
            st.pop();

            ETNode* left = st.top();
            st.pop();

            front->left = left;
            front->right = right;

            st.push(front);
        }
    }

    return st.top();
}

void recur(ETNode* root, queue<char>& result)
{
    if (!root) return;

    recur(root->left, result);
    recur(root->right, result);
    result.push(root->val);
}

int evaluateET(ETNode* root)
{
    stack<int> st;
    queue<char> q;

    recur(root, q);

    while (!q.empty())
    {
        char front = q.front();

        q.pop();

        if (front >= '0' && front <= '9')
        {
            st.push(front - '0');
        }
        else
        {
            int right = st.top();
            st.pop();

            int left = st.top();
            st.pop();

            int temp;

            switch (front)
            {
                case '+':
                    temp = right + left;
                    break;
                case '-':
                    temp = left - right;
                    break;
                case '*':
                    temp = left * right;
                    break;
            }

            st.push(temp);
        }
    }

    return st.top() % 2002;
}

int main()
{
    string s = "47*17-3++"; 
    ETNode* root = constructET(s); 
    cout << evaluateET(root);

    return 0;
}