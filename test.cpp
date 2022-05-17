#include<bits/stdc++.h>

class Node {
public: 
    int priority;
    string fileName;
    Node* next;
    
    Node(const string& fileName="", const int& priority=0, Node* next=nullptr) {
        this->fileName = fileName;
        this->priority = priority;
        this->next = next;
    }
};

class PrinterQueue
{
    // your attributes
private:
    Node* head;
public:
    // your methods
    PrinterQueue() {
        head = nullptr;
    }

    void addNewRequest(int priority, string fileName)
    {
        Node* newNode = new Node(fileName, priority);
        
        if (!head) {
            head = newNode;
        } else {
            Node* prev = nullptr;
            Node* curr = head;
            
            while (curr != nullptr) {
                if (priority > curr->priority) {
                    if (prev) {
                        prev->next = newNode;
                    }
                    head = newNode;
                    newNode->next = curr;
                    
                    return;
                }
                
                prev = curr;
                curr = curr->next;
            }
            
            prev->next = newNode;
        }
    }

    void print()
    {
        // your code here
        // After some logic code, you have to print fileName with endline 
        if (!head) {
            cout << "No file to print" << endl;
            return;
        }
        
        cout << head->fileName << endl;
        
        Node* nextNode = head->next;
        delete head;
        head = nextNode;
    }
};

int main() {
    PrinterQueue* myPrinterQueue = new PrinterQueue();
    myPrinterQueue->addNewRequest(1, "hello.pdf");
    myPrinterQueue->addNewRequest(1, "goodbye.pdf");
    myPrinterQueue->addNewRequest(1, "goodnight.pdf");
    myPrinterQueue->print();
    myPrinterQueue->print();
    myPrinterQueue->print();
}