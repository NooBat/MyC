#include<iostream>
#include<string>
#include<sstream>

using namespace std;

#define SEPARATOR "#<ab@17943918#@>#"

template<class T>
class BinarySearchTree
{
public:
    class Node;
private:
    Node* root;
public:
    BinarySearchTree(): root(nullptr) {}
    ~BinarySearchTree() {}

    string inOrderRecur(Node* root)
    {
        stringstream ss;

        if (root != nullptr)
        {
            ss << inOrderRecur(root->pLeft);
            ss << root->value << " ";
            ss << inOrderRecur(root->pRight);
        }

        return ss.str();
    }

    string inOrder()
    {
        return inOrderRecur(root);
    }

    Node* addRecur(Node* root, T value)
    {
        if (!root) 
        {
            root = new Node(value);
            return root;
        }

        if (value <= root->value) root->pLeft = addRecur(root->pLeft, value);
        else root->pRight = addRecur(root->pRight, value);

        return root;
    }

    void add(T value)
    {
        //stub
        root = addRecur(root, value);
    }

    T inOrderSuccessor(Node* root)
    {
        while (root->pLeft != nullptr)
        {
            root = root->pLeft;
        }

        T temp = root->value;

        return temp;
    }

    Node* deleteNodeRecur(Node* root, T value)
    {
        if (!root) return nullptr;

        if (value < root->value) root->pLeft = deleteNodeRecur(root->pLeft, value);
        else if (value > root->value) root->pRight = deleteNodeRecur(root->pRight, value);
        else 
        {
            if (root->pLeft == nullptr && root->pRight == nullptr) 
            {
                delete root;
                root = nullptr;
            }
            else if (root->pLeft == nullptr)
            {
                Node* rightChild = root->pRight;
                delete root;
                root = rightChild;
            }
            else if (root->pRight == nullptr)
            {
                Node* leftChild = root->pLeft;
                delete root;
                root = leftChild;
            }
            else
            {
                T newValue = inOrderSuccessor(root->pRight);
                root->value = newValue;

                root->pRight = deleteNodeRecur(root->pRight, newValue);
            }
        }

        return root;
    }

    void deleteNode(T value)
    {
        root = deleteNodeRecur(root, value);
    }

    class Node
    {
    private:
        T value;
        Node* pLeft, * pRight;
        friend class BinarySearchTree<T>;
    public:
        Node(T value): value(value), pLeft(nullptr), pRight(nullptr) {}
        ~Node() {}
    };
};

int main()
{
    BinarySearchTree<int> bst; 
    bst.add(9);
    bst.add(2);
    bst.add(10); 
    bst.deleteNode(9);
    cout << bst.inOrder();

    return 0;
}