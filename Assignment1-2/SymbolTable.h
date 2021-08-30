#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include "main.h"

class Node {
private:
    string variable;
    string item;
    Node* next;

public:
    Node() {
        this->setNext(nullptr);
    }

    Node(const string& variable, const string& item) {
        this->setVariable(variable);
        this->setItem(item);
        this->setNext(nullptr);
    }

    void setVariable(const string& variable) {
        this->variable = variable;
    }

    void setItem(const string& item) {
        this->item = item;
    }

    void setNext(Node* next) {
        this->next = nullptr;
    }

    string getVariable() const {
        return this->variable;
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
    vector<string> tokenize(string str, string del = " ") const;
public:
    SymbolTable() {}
    void run(string filename);
};
#endif