#include "SymbolTable.h"

bool checkValidInstruction(const string& str) {
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
        else if (single == "\'") {
            if (i + 1 >= str.length()) return false;
            int end = (int)str.find("\'", i + 1);
            if (end == -1) return false;
            else i = end;
        }
        else if (regex_match(single, letters)) {
            out = false;
            if (!in) countWord++;
            in = true;
        }
    }

    return countSpace == countWord - 1;
}

bool checkValidId(const string& id) {
    regex letter("[a-zA-Z0-9_]");
    regex digit("[0-9]");
    
    string a = id.substr(0, 1);
    if (regex_match(a, digit)) return false;
    
    for (int i = 0; i < id.length(); i++) {
        string temp = id.substr(i, 1);
        if (!regex_match(temp, letter)) return false;
    }

    return true;
}

bool checkValidItem(const string& type, const string& item) {
    if (type == "number") {
        if (item[0] != 'n') return false;
        regex digit("[0-9]");

        for (int i = 1; i < item.length(); i++) {
            string temp = item.substr(i, 1);
            if (!regex_match(temp, digit)) return false;
        }
    }
    else if (type == "string") {
        if (item[0] != '\'' || item[item.length() - 1] != '\'') return false;
        regex letter("[a-zA-Z0-9 ]");

        for (int i = 1; i < item.length() - 1; i++) {
            string temp = item.substr(i, 1);
            if (!regex_match(temp, letter)) return false;
        }
    }

    return true;
}

vector<string> tokenize(string str, string del = " ") {
    vector<string> result;
    int start = 0;
    int end = (int)str.find(del);

    while (end != -1) {
        result.push_back(str.substr(start, end - start));
        start = (int)end + 1;
        if (str[start] != '\'') end = (int)str.find(del, start);
        else {
            end = (int)str.find("\'", start + 1);

        }
    }

    result.push_back(str.substr(start, end - start));
    return result;
}

Node* SymbolTable::getPtrTo(const string& target_id, const int& scope) const {
    if (headPtr == nullptr) return nullptr;

    Node* p = headPtr;

    while (p != nullptr) {
        if (p->getId() == target_id && p->getScope() == scope) return p;
        p = p->getNext();
    }

    return nullptr;
}

void SymbolTable::run(string filename) {
    ifstream myfile(filename); 
    if (myfile.is_open()){
        string instruction;
        int scope = 0;

        while (getline(myfile, instruction)) {
            if (!checkValidInstruction(instruction)) throw InvalidInstruction(instruction);
            vector<string> token = tokenize(instruction);
            if (token.size() > 3) throw InvalidInstruction(instruction);

            if (token[0] == "INSERT") {
                string id = token[1];
                string type = token[2];
                if (type != "number" && type != "string") throw InvalidInstruction(instruction);
                if (!checkValidId(id)) throw InvalidInstruction(instruction);

                if (headPtr == nullptr) {
                    headPtr = new Node(type, id, scope);
                    cout << "success" << endl;
                }
                else {
                    Node* p = headPtr;

                    while (p->getNext() != nullptr) {
                        if (p->getId() == id && p->getScope() == scope) throw Redeclared(instruction);
                        p = p->getNext(); 
                    }

                    if (p->getId() == id && p->getScope() == scope) throw Redeclared(instruction);
                    else {
                        Node* temp = new Node(type, id, scope);
                        p->setNext(temp);
                        cout << "success" << endl; 
                    }
                }
            }
            else if (token[0] == "ASSIGN") {
                string id = token[1];
                string item = token[2];

                Node* p = getPtrTo(id, scope);

                if (p == nullptr) {
                    throw Undeclared(instruction);
                }
                else {
                    if (!checkValidItem(p->getType(), item)) throw TypeMismatch(instruction);

                    if (p->getType() == "number") {
                        string temp = item.substr(1, item.length() - 1);
                        p->setItem(temp);
                        cout << "success" << endl;
                    }
                    else if (p->getType() == "string") {
                        string temp = item.substr(1, item.length() - 2);
                        p->setItem(temp);
                        cout << "success" << endl;
                    }
                }
            }
            else if (token[0] == "BEGIN") {
                scope++;
            }
            else if (token[0] == "END") {
                if (scope == 0) throw UnknownBlock();
                else scope--;
            }
        }
        if (scope > 0) throw UnclosedBlock(scope);
    }
    cout << "success";
}