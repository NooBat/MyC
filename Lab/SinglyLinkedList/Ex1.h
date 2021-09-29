#ifndef _SINGLY_LINKED_LIST
#define _SINGLY_LINKED_LIST

using namespace std;

template <class T> 
class SLinkedList
{
public:
    class Node;
protected:
    Node* head;
    Node* tail;
    int itemCount;
public:
    SLinkedList(): head(NULL), tail(NULL), count(0);
    ~SLinkedList() { };
    void    add(T e);
    void    add(int index, T e);
    int     size();
    bool    empty();
    T       get(int index);
    void    set(int index, T e);
    int     indexOf(T item);
    bool    contains(T item);
public:
    class Node
    {
    private:
        T data;
        Node* next;
        friend class SLinkedList<T>;

    public:
        Node()
        {
            next = 0;   
        }
        
        Node(Node* next)
        {
            this->next = next;
        }

        Node(T data, Node* next = nullptr)
        {
            this->data = data;
            this->next = next;
        }
    };
};

#endif