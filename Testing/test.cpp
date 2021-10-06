#include<bits/stdc++.h>

using namespace std;

class Tree
{
public:
    class Node
    {
    private:
        int value;
        int multiplier;
        int leftHeight;
        bool counted;
        Node* left;
        Node* right;
        friend class Tree;
    public:
        Node(): value(0), leftHeight(0), multiplier(1), counted(0), left(nullptr), right(nullptr) { }
        Node(int value, Node* left = nullptr, Node* right = nullptr)
        {
            this->value = value;
            this->leftHeight = 0;
            this->multiplier = 1;
            this->counted = 0;
            this->left = left;
            this->right = right;
        }
    };
private:
    Node* root;
public:
    Tree(): root(nullptr) { }

    void insert(int value)
    {
        Node* curr = root;

        if (root == nullptr) 
        {
            root = new Node(value);
            return;
        }

        while (true)
        {
            if (value < curr->value) 
            {
                curr->leftHeight += curr->multiplier;
                increaseRightSubtree(curr->right);
                if (curr->left == nullptr) 
                {
                    curr->left = new Node(value);
                    break;
                }
                else curr = curr->left;
            }
            else if (value > curr->value) 
            {
                if (curr->right == nullptr) 
                {
                    curr->right = new Node(value);
                    break;
                }

                else curr = curr->right;
            }
            else
            {
                curr->multiplier++;
                increaseRightSubtree(curr->right);
                return;
            }
        }
    }

    int getLeftHeight(int value)
    {
        Node* curr = root;
        while (curr != nullptr)
        {
            if (value < curr->value) 
            {
                curr = curr->left;
            }
            else if (value > curr->value) curr = curr->right;
            else break;
        }

        if (curr == nullptr) return 0;
        if (curr->counted) return 0;
        curr->counted = 1;
        return curr->leftHeight;
    }

    void increaseRightSubtree(Node* curr)
    {
        if (curr == nullptr) return;

        increaseRightSubtree(curr->left);
        curr->leftHeight += curr->multiplier;
        increaseRightSubtree(curr->right);
    }
};

int solve(std::vector<int> arr)
{
    Tree* tree = new Tree();
    int result = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        tree->insert(arr[i]);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        result += tree->getLeftHeight(arr[i]);
    }

    return result;
}

int main()
{
    srand(time(NULL));

    int size = 30000;

    vector<int> temp;

    for (int i = 0; i < size; i++)
    {
        temp.push_back(rand());
    }
    clock_t start = clock();
    int a = solve(temp);
    clock_t end = clock();

    double time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    cout << a << " " << time;

    return 0;
}