#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include "main.h"

class Node {
private:
    string type;
    string id;
    string item;
    Node* next;
public:
    static int scope;
    Node() {
        this->setNext(nullptr);
    }

    Node(const string& type, const string& id) {
        this->setType(type);
        this->setId(id);
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

    void setNext(Node* next) {
        this->next = nullptr;
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

    Node* getNext() const {
        return this->next;
    }
};



class SymbolTable {
private:
    Node* headPtr;

    Node* getPtrTo(const string& target_variable) const;
public:
    SymbolTable() {}
    void run(string filename);
};
#endif