#include<iostream>
#include<string>
#include<iterator>
#include<vector>
#include<queue>
#include<stack>

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
};

vector<int> levelAfterTraverse(BSTNode* root)
{
    int i = 0;

    vector<int> result;

    queue<BSTNode*> q;
    stack<BSTNode*> st;
    q.push(root);
    result.push_back(root->val);

    while (!q.empty() || !st.empty())
    {
        if (!q.empty())
        {
            while (!q.empty())
            {
                BSTNode* curr = q.front();

                if (curr->left)
                {
                    st.push(curr->left);
                }
                if (curr->right)
                {
                    st.push(curr->right);
                }

                q.pop();
            }
        }
        else if (!st.empty())
        {
            stack<BSTNode*> st2;

            while (!st.empty())
            {
                st2.push(st.top());
                result.push_back(st.top()->val);
                st.pop();
            }

            while (!st2.empty())
            {
                BSTNode* curr = st2.top();

                if (curr->left) 
                {
                    q.push(curr->left);
                    result.push_back(curr->left->val);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                    result.push_back(curr->right->val);
                }

                st2.pop();
            }
        }
    }

    return result;
}

void rightSum(BSTNode* node, int& max)
{
    if (!node) 
    {
        return;
    };
    
    rightSum(node->right, max);
    node->val += max;
    max = node->val;
    rightSum(node->left, max);
}

BSTNode* enlarge(BSTNode* root)
{
    if (!root)
        return NULL;

    int max = 0;
    rightSum(root, max);
        
    return root;
}

void printInorder(BSTNode* root)
{
    if (!root) return;
    
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

void printVector(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
}

void inorder(BSTNode* root, vector<int>& res)
{
    if (!root) return;

    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
}

bool binarySearch(vector<int> arr, int l, int r, int key)
{
    if (l > r) return false;

    int mid = l + (r - l) / 2;

    if (arr[mid] > key)
    {
        return binarySearch(arr, l, mid - 1, key);
    }
    else if (arr[mid] < key)
    {
        return binarySearch(arr, mid + 1, r, key);
    }
    return true;
}

bool findTarget(BSTNode* root, int k)
{
    vector<int> arr;
    bool result = false;

    inorder(root, arr);

    vector<int>::iterator it1 = arr.begin();
    vector<int>::iterator it2 = arr.end() - 1;

    while (it1 != it2)
    {
        int sum = *it1 + *it2;

        if (sum > k) it2--;
        else if (sum < k) it1++;
        else return true;
    }

    return result;
}

int main()
{
int arr[] = {188793564, 759254429, 542202996, 36681895, 149237981, 56870772, 283859815, 131598871, 122103719, 481212681, 74392903, 402801505, 659419817, 501716170, 373049766, 370321387, 117973136, 52557505, 73855985, 275300792, 662294517, 961938153, 1572526, 167590848, 2469431, 139462404, 208481448, 9685776, 132033609, 564353318, 718726421, 64649940, 442919096, 91225488, 115039684, 154680359, 534270628, 358775726, 58096489, 672117015, 128639810, 397731328, 436597349, 569333603, 247833704, 108354105, 83977716, 170055976, 132512831, 15237905, 614226059, 23850799, 78551421, 307873357, 103923014, 195774165, 201410008, 142637599, 103793051, 99582888, 80863102, 3872631, 484978002, 390251581, 94217880, 398428244, 148699388, 3415746, 20555601, 155751403, 12758259, 523923823, 41988701, 101850856, 10300196, 87746138, 860448344, 121498214, 448678085, 167448185, 23611249, 57229595, 158706537, 321632659, 417183490, 107283962, 868502773, 99033000, 555699463, 51387071, 112821731, 5525530, 748114748, 344781956, 5173270, 14553813, 228656155, 172095173, 325383320, 677904079};
int k = 100000;
BSTNode* root = BSTNode::createBSTree(arr, arr + sizeof(arr)/sizeof(int));
cout << findTarget(root, k);
}