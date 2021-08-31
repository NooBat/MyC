#include "SymbolTable.h"
int Node::scope = 0;

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
        else if (regex_match(single, letters)) {
            out = false;
            if (!in) countWord++;
            in = true;
        }
    }

    return countSpace == countWord - 1;
}

bool checkValidType(const string& type, const string& item) {
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
        end = (int)str.find(del, start);
    }
    result.push_back(str.substr(start, end - start));
    return result;
}

Node* SymbolTable::getPtrTo(const string& target_id) const {
    if (headPtr == nullptr) return nullptr;

    Node* p = headPtr;

    while (p != nullptr) {
        if (p->getId() == target_id) return p;
        p = p->getNext();
    }

    return nullptr;
}

void SymbolTable::run(string filename) {
    ifstream myfile(filename); 
    if (myfile.is_open()){
        string temp;
        while (getline(myfile, temp)) {
            if (!checkValidInstruction(temp)) throw InvalidInstruction(temp);
            vector<string> token = tokenize(temp);

            if (token[0] == "INSERT") {
                string id = token[1];
                string type = token[2];

                if (headPtr == nullptr) {
                    headPtr = new Node(type, id);
                    cout << "success" << endl;
                }
                else {
                    Node* p = headPtr;

                    while (p->getNext() != nullptr) {
                        if (p->getId() == id && p) throw Redeclared(temp);
                        p = p->getNext(); 
                    }
                    if (p->getId() == id) throw Redeclared(temp);
                    else {
                        Node* a = new Node(type, id);
                        p->setNext(a);
                        cout << "success" << endl; 
                    }
                }
            }
            else if (token[0] == "ASSIGN") {
                string id = token[1];
                string item = token[2];

                Node* p = getPtrTo(id);

                if (p == nullptr) {
                    throw Undeclared(temp);
                }
                else {
                    if (!checkValidType(p->getType(), item)) throw TypeMismatch(temp);

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
                
            }
        }
    }
    cout << "success";
}