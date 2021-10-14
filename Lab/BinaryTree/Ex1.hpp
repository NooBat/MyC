#ifndef _BINARY_TREE
#define _BINARY_TREE

#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;

template<class K, class V>
class BinaryTree
{
public:
    class Node;
private:
    Node* root;

public:
    BinaryTree(): root(nullptr) {};
    ~BinaryTree()
    {

    }
    class Node
    {
    private:
        K key;
        V value;
        Node* pLeft;
        Node* pRight;
        friend class BinaryTree<K, V>;
    public:
        Node(K key, V value): key(key), value(value), pLeft(nullptr), pRight(nullptr) {}
        ~Node() {}
    };
    void addNode(string posFromRoot, K key, V value)
    {
        if (posFromRoot == "")
        {
            this->root = new Node(key, value);
            return;
        }
        Node* walker = this->root;
        int l = posFromRoot.length();
        for (int i = 0; i < l - 1; i++)
        {
            if (!walker)
            {
                return;
            }
            if (posFromRoot[i] == 'L')
            {
                walker = walker->pLeft;
            }
            if (posFromRoot[i] == 'R')
            {
                walker = walker->pRight;
            }
        }
        if (posFromRoot[l - 1] == 'L')
        {
            walker->pLeft = new Node(key, value);
        }
        if (posFromRoot[l - 1] == 'R')
        {
            walker->pRight = new Node(key, value);
        }
    }

    int getHeightRecur(Node* curr)
    {
        if (curr == nullptr) return -1;

        int left = getHeightRecur(curr->pLeft);
        int right = getHeightRecur(curr->pRight);

        return (left >= right) ? (1 + left) : (1 + right);
    }

    int getHeight()
    {
        Node* curr = this->root;
        return getHeightRecur(curr);
    }

    void preOrderUtil(Node* curr, string& result)
    {
        if (!curr) return;

        result += to_string(curr->value) + " ";
        preOrderUtil(curr->pLeft, result);
        preOrderUtil(curr->pRight, result);
    }

    string preOrder()
    {
        string result;
        preOrderUtil(root, result);

        result = result.substr(0, result.length() - 1);

        return result;
    }

    void inOrderUtil(Node* curr, string& result)
    {
        if (!curr) return;

        inOrderUtil(curr->pLeft, result);
        result += to_string(curr->value) + " ";
        inOrderUtil(curr->pRight, result);
    }

    string inOrder()
    {
        string result;
        inOrderUtil(root, result);

        result = result.substr(0, result.length() - 1);

        return result;
    }

    void postOrderUtil(Node* curr, string& result)
    {
        if (!curr) return;

        postOrderUtil(curr->pLeft, result);
        postOrderUtil(curr->pRight, result);
        result += to_string(curr->value) + " ";
    }

    string postOrder()
    {
        string result;

        postOrderUtil(root, result);

        result = result.substr(0, result.length() - 1);

        return result;
    }

    void sumOfLeafsRecur(Node* curr, int& result)
    {
        if (!curr) return;

        if (!curr->pLeft && !curr->pRight)
        {
            result += curr->value;
        }
        sumOfLeafsRecur(curr->pLeft, result);
        sumOfLeafsRecur(curr->pRight, result);
    }

    int sumOfLeafs()
    {
        int result = 0;
        
        sumOfLeafsRecur(root, result);

        return result;
    }

    void countRecur(Node* curr, int& result)
    {
        if (!curr) return;

        if (curr->pLeft && curr->pRight) result++;
        countRecur(curr->pLeft, result);
        countRecur(curr->pRight, result);
    }

    int countTwoChildrenNode()
    {
        int result = 0;

        countRecur(root, result);

        return result;
    }

    bool isBSTUtil(Node* root, int left, int right)
    {
        if (!root) return true;

        if (root->value > left && root->value < right
            && isBSTUtil(root->pLeft, left, root->value) && isBSTUtil(root->pRight, root->value, right))
            return true;

        return false;
    }

    bool isBST()
    {
        if (!root) return true;
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }
};

#endif