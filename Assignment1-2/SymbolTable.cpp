#include "SymbolTable.h"
bool checkValid(const string& str) {
    bool in = false;
    bool out = false;
    int countWord = 0;
    int countSpace = 0;
    regex letters("[a-zA-Z0-9]");

    for (int i = 0; i < str.length(); i++) {
        string single = str.substr(i, 1);

        if (single == " ") {
            out = true;
            in = false;
            countSpace++;
        }
        else if (regex_match(single, letters)) {
            out = false;
            if (!in) countWord++;
            in = true;
        }
    }

    return countSpace == countWord - 1;
}


vector<string> tokenize(string str, string del = " ") {
    vector<string> result;
    int start = 0;
    int end = (int)str.find(del);

    while (end != -1) {
        result.push_back(str.substr(start, end - start));
        start = (int)end + 1;
        end = (int)str.find(del, start);
    }

    return result;
}

Node* SymbolTable::getPtrTo(const string& target_variable) const {
    if (headPtr == nullptr) return nullptr;

    Node* p = headPtr;

    while (p != nullptr) {
        if (p->getVariable() == target_variable) return p;
        p = p->getNext();
    }

    return nullptr;
}

void SymbolTable::run(string filename) {
    ifstream myfile(filename); 
    if (myfile.is_open()){
        string tmp;
        while (getline(myfile, tmp)) {
            if (!checkValid(tmp)) throw InvalidInstruction(tmp);
        }


    }
    cout << "success";
}