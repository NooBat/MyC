#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include "main.h"

using namespace std;

class Node {
private:
    string type;
    string id;
    string item;
    int scope;
    Node* next;

public:
    Node() {
        this->setNext(nullptr);
    }

    Node(const string& type, const string& id, const int& scope) {
        this->setType(type);
        this->setId(id);
        this->setScope(scope);
        this->setNext(nullptr);
    }

    void setType(const string& type) {
        this->type = type;
    }

    void setId(const string& id) {
        this->id = id;
    }

    void setItem(const string& item) {
        this->item = item;
    }

    void setScope(const int& scope) {
        this->scope = scope;
    }

    void setNext(Node* next) {
        this->next = next;
    }

    string getType() const {
        return this->type;
    }

    string getId() const {
        return this->id;
    }

    string getItem() const {
        return this->item;
    }   

    int getScope() const {
        return scope;
    }

    Node* getNext() const {
        return this->next;
    }
};



class SymbolTable {
private:
    Node* headPtr;

    Node* getPtrTo(const string& target_variable, const int& scope) const;
public:
    SymbolTable() {}
    virtual ~SymbolTable() {
        clear();
    }
    void run(string filename);

    void clear() {
        Node* curr = headPtr;

        while (curr != nullptr) {
            Node *next = curr->getNext();

            delete curr;

            curr = next;
        }

        headPtr = nullptr;
    }
};
#endif