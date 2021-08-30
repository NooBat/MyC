#include "SymbolTable.h"

Node* SymbolTable::getPtrTo(const string& target_variable) const {
    if (headPtr == nullptr) return nullptr;

    Node* p = headPtr;

    while (p != nullptr) {
        if (p->getVariable() == target_variable) return p;
        p = p->getNext();
    }

    return nullptr;
}

vector<string> SymbolTable::tokenize(string str, string del = " ") const {
    vector<string> result;
    int start = 0;
    int end = (int)str.find(del);

    while (end != -1) {
        result.push_back(str.substr(start, end - start));
        start = (int)end + 1;
        int temp = end;
        end = (int)str.find(del, start);
        if (end == temp + 1) throw InvalidInstruction(str);
    }

    return result;
}

void SymbolTable::run(string filename) {
    ifstream myfile(filename); 
    if (myfile.is_open()){
        string tmp;

    }
    cout << "success";
}