#ifndef GAME_CPP
#define GAME_CPP

#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>

using namespace std;

int ManhattanDistance(int x1, int y1, int x2, int y2);

class Monster {
public:
    int         x;
    int         y;
    int         id;
    int         hp;
    int         moveSpeed;
    int         distancefromTower;

    void setPosition(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void move(string direction) {
        if (direction == "L") x -= moveSpeed;
        else if (direction == "R") x += moveSpeed;
        else if (direction == "U") y += moveSpeed;
        else y -= moveSpeed;
    }
};

vector<Monster*> monsterSet;

bool rule(Monster* A, Monster* B) {
    if (A->distancefromTower > B->distancefromTower) return false;
    else if (A->distancefromTower == B->distancefromTower){
        if (A->id > B->id) return true;
        else if (A->id < B->id) return false;
    }
    return true;
}

class Tower {
public:
    int         x;
    int         y;
    int         id;
    int         range;
    int         damage;

    void setPosition(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int getTarget() {
        vector<Monster*> inRange;
        for (int i = 0; i < monsterSet.size(); i++) {
            if (monsterSet[i]->hp > 0) {
                monsterSet[i]->distancefromTower = ManhattanDistance(x, y, monsterSet[i]->x, monsterSet[i]->y);
                if (monsterSet[i]->distancefromTower <= range) {
                    inRange.push_back(monsterSet[i]);
                }
                sort(inRange.begin(), inRange.end(), rule);
                if (inRange.size() > 0) return inRange[0]->id;
            }
        }
        return -1;
    }

    void attack() {
        int attackedMonsterID = getTarget();

        if (attackedMonsterID == -1) return;

        for (int i = 0; i < monsterSet.size(); i++) {
            if (monsterSet[i]->id == attackedMonsterID) {
                monsterSet[i]->hp -= this->damage;
                if (monsterSet[i]->hp < 0) monsterSet[i]->hp = 0; 
            }
        }
    }
};

vector<Tower*> towerSet;

class GameManager {
public:
    Tower* createTower(string type, int id, int x, int y) {
        Tower *result = new Tower();

        result->setPosition(x, y);
        if (id >= 5000) result->id = 4999;
        else if (id == 0) result->id = 1;
        else result->id = id;

        if (type == "tower_1") {
            result->range = 5;
            result->damage = 20;
        }
        else if (type == "tower_2") {
            result->range = 3;
            result->damage = 30;
        }

        towerSet.push_back(result);

        return result;
    }

    Monster* createMonster(string type, int id, int x, int y) {
        Monster *result = new Monster();

        result->setPosition(x, y);
        if (id >= 5000) result->id = 4999;
        else if (id == 0) result->id = 1;
        else result->id = id;

        if (type == "monster_1") {
            result->hp = 500;
            result->moveSpeed = 1;
        }
        else if (type == "monster_2") {
            result->hp = 50;
            result->moveSpeed = 3;
        }

        monsterSet.push_back(result);
        return result;
    }
};

int ManhattanDistance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

#endif