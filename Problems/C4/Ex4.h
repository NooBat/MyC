#ifndef _POLYNOMIAL
#define _POLYNOMIAL

#include<vector>
#include<iostream>

using namespace std;

class PolyNode {
private:
    int coefficient;
    int power;
    PolyNode* next;

public:
    PolyNode();

    PolyNode(const int& coefficient, const int& power);

    bool setCoefficient(const int& coefficient);

    bool setPower(const int& power);

    void setNext(PolyNode* next);

    int getCoefficient() const;

    int getPower() const;

    PolyNode* getNext() const;
};

PolyNode::PolyNode(): next(nullptr) {

}

PolyNode::PolyNode(const int& coefficient, const int& power) {
    this->setCoefficient(coefficient);
    this->setPower(power);
    this->setNext(nullptr);
}

bool PolyNode::setCoefficient(const int& coefficient) {
    if (coefficient == 0) return false;

    this->coefficient = coefficient;

    return true;
}

bool PolyNode::setPower(const int& power) {
    if (power < 0) return false;

    this->power = power;

    return true;
}

void PolyNode::setNext(PolyNode* next) {
    this->next = next;
}

int PolyNode::getCoefficient() const {
    return this->coefficient;
}

int PolyNode::getPower() const {
    return this->power;
}

PolyNode* PolyNode::getNext() const {
    return this->next;
}




class Polynomial {
private:
    int degree;
    PolyNode* headPtr;

    PolyNode* getPtrTo(const int& targetPower) const;

public:
    Polynomial();

    Polynomial(const vector<vector<int> >& v);

    virtual ~Polynomial();

    void changeCoefficient(const int& newCoefficient, const int& power);

    int coefficient(const int& power) const;

    void clear();

    vector<vector<int> > toVector() const;
};

PolyNode* Polynomial::getPtrTo(const int& targetPower) const {
    if (targetPower > degree) return nullptr;
    if (targetPower == degree) return headPtr;

    PolyNode* curr = headPtr;

    while (curr != nullptr) {
        if (curr->getPower() == targetPower) return curr;
        curr = curr->getNext();
    }

    return nullptr;
}

Polynomial::Polynomial(): degree(0), headPtr(nullptr) {

}

Polynomial::Polynomial(const vector<vector<int> >& v) {
    degree = v[0][1];

    headPtr = new PolyNode(v[0][0], v[0][1]);

    for (int i = 1; i < v.size(); i++) {
        PolyNode* p = headPtr;

        PolyNode* temp = new PolyNode(v[i][0], v[i][1]);

        while (p->getNext() != nullptr) {
            p = p->getNext();
        }

        p->setNext(temp);
    }
}

Polynomial::~Polynomial() {
    clear();
}

void Polynomial::changeCoefficient(const int& newCoefficient, const int& power) {
    if (newCoefficient == 0) return;
    if (power < 0) return;

    PolyNode* p = getPtrTo(power);

    if (p == nullptr) {
        if (power > degree) {
            PolyNode* temp = new PolyNode(newCoefficient, power);

            temp->setNext(headPtr);
            headPtr = temp;

            degree = power;

            return;
        }

        PolyNode* curr = headPtr->getNext();
        PolyNode* prev = headPtr;

        if (curr == nullptr) { 
            PolyNode* temp = new PolyNode(newCoefficient, power);
            headPtr->setNext(temp);

            return;
        }

        while (curr != nullptr) {
            PolyNode* next = curr->getNext();

            if (prev->getPower() > power && power > curr->getPower()) {
                PolyNode* temp = new PolyNode(newCoefficient, power);

                temp->setNext(curr);
                prev->setNext(temp);

                return;
            }

            prev = curr;
            curr = next;
        }

        PolyNode* temp = new PolyNode(newCoefficient, power);

        prev->setNext(temp);
    }
    else {
        p->setCoefficient(newCoefficient);
    }
}

int Polynomial::coefficient(const int& power) const {
    PolyNode* p = getPtrTo(power);

    if (p == nullptr) return 0;

    else return p->getCoefficient();
}

void Polynomial::clear() {
    if (headPtr == nullptr) return;

    PolyNode* p = headPtr;

    while (p != nullptr) {
        PolyNode* next = p->getNext();

        delete p;
        
        p = next;
    }

    headPtr = nullptr;
}

vector<vector<int> > Polynomial::toVector() const {
    vector<vector<int> > result;

    if (headPtr == nullptr) {
        vector<int> temp;
        temp.push_back(1);

        result.push_back(temp);

        return result;
    }

    PolyNode* p = headPtr;

    while (p != nullptr) {
        vector<int> v;
        v.push_back(p->getCoefficient());
        v.push_back(p->getPower());

        result.push_back(v);

        p = p->getNext();
    }

    return result;
}
#endif