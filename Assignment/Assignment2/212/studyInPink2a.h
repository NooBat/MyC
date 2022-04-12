/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 15.02.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

class Point {
private:
    int x;
    int y;
public:
    Point(int x=0, int y=0) {
        this->x = x;
        this->y = y;
    }

    string toString() const {
        string result = "<Point[";

        result += to_string(this->x) + "," 
                + to_string(this->y) + "]>";

        return result;
    }

    int distanceTo(const Point & otherPoint) const {
        int distance;

        distance = ceil(sqrt(pow(otherPoint.x - this->x, 2) + 
                             pow(otherPoint.y - this->y, 2)));

        return distance;
    }
};

class Node {
private:
    Point point;
    Node * next;

    friend class Path;

public:
    Node(const Point & point=Point(), Node* next=NULL) {
        this->point = point;
        this->next = next;
    }

    string toString() const {
        string result = "<Node[";

        result += this->point.toString() + "]>";

        return result;
    }
};

class Path {
private:
    Node * head;
    Node * tail;
    int count;
    int length;

public:
    Path() : head(nullptr), tail(nullptr), count(0), length(-1) {}

    ~Path() {
        while (head != nullptr) {
            Node* next = head->next;
            delete head;
            head = next;
        }

        tail = nullptr;
        count = 0;
        length = -1;
    }

    void addPoint(int x, int y) {
        Point newPoint(x, y);
        
        Node* newNode = new Node(newPoint);
        ++count;

        if (!head) {
            head = newNode;
            length = 0;
        } else {
            tail->next = newNode;
            length += newPoint.distanceTo(tail->point);
        }

        tail = newNode;
    }

    string toString() const {
        string result = "<Path[";

        result += "count:" + to_string(this->count) + ",length:" + to_string(this->length) + ",[";

        Node* temp = head;
        for (int i = 0; i < this->count; i++) {
            result += temp->toString();
            temp = temp->next;

            if (i < this->count - 1) {
                result += ",";
            }
        }

        result += "]]>";

        return result;
    }

    int getLength() const {
        return length;
    }

    Point getLastPoint() const {
        return tail->point;
    }
};

class Character {
private:
    string name;
    Path * path;

public:
    Character(const string & name="") {
        this->name = name;
        this->path = new Path();
    }

    ~Character() {
        delete path;
        path = nullptr;
    }

    string getName() const {
        return name;
    }

    void setName(const string & name) {
        this->name = name;
    }

    void moveToPoint(int x, int y) {
        path->addPoint(x, y);
    }

    string toString() const {
        string result = "<Character[";

        result += "name:" + name + ",path:" + path->toString() + "]>";

        return result;
    }

    int getLengthFromPath() const {
        return path->getLength();
    }

    int getDistanceFromCharacter(const Character& otherCh) const {
        return this->path->getLastPoint().distanceTo(otherCh.path->getLastPoint());
    }
};

bool rescueSherlock(
        const Character & chMurderer,
        const Character & chWatson,
        int maxLength,
        int maxDistance,
        int & outDistance
        ) {

    int l1 = chWatson.getLengthFromPath();
    int l2 = chMurderer.getLengthFromPath();
    bool saved = false;

    if (l1 - l2 <= maxLength) {
        outDistance = chWatson.getDistanceFromCharacter(chMurderer);
        if (outDistance <= maxDistance) {
            saved = true;
        } else {
            saved = false;
        }
    } else {
        outDistance = -1;
        saved = false;
    }

    return saved;
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */