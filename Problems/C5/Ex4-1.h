#ifndef _MAZE
#define _MAZE

#include "Ex4-2.h"
#include<string>
#include<cstring>
#include<iostream>

using namespace std;

class Maze {
private:
    int height;
    int width;
    string maze[7];
    int exitCol;
    int startCol;

public:
    Maze();

    Maze(const int& height, const int& width, const int& exitCol, const int& startCol);

    void createMaze(string arr[]);

    bool isWall(const int& col, const int& row) const;

    bool isVisited(const int& col, const int& row) const;

    bool isClear(const int& col, const int& row) const;

    int getExitColumn() const;

    void setVisited(const int& col, const int& row);

    void setPath(const int& col, const int& row);

    void display() const;
};

Maze::Maze() {
    height = 0;
    width = 0;
    exitCol = 0;
    startCol = 0;
}

Maze::Maze(const int& height, const int& width, const int& exitCol, const int& startCol) {
    this->height = height;
    this->width = width;

    this->startCol = startCol;
    this->exitCol = exitCol;
}

void Maze::createMaze(string arr[]) {
    for (int i = 0; i < width; i++) {
        if (i != exitCol) {
            maze[0] += "x";
        } 
        else maze[0] += " ";
    }

    for (int i = 0; i < height - 2; i++) {
        maze[i + 1] = arr[i];
    }

    for (int i = 0; i < width; i++) {
        if (i != startCol) {
            maze[height - 1] += "x";
        }
        else maze[height - 1] += "o";
    }
}

bool Maze::isWall(const int& col, const int& row) const {
    if (col >= width || col < 0 || row >= height || row < 0) return false;
    if (maze[row][col] == 'x') return true;
    return false;
}

bool Maze::isVisited(const int& col, const int& row) const {
    if (col >= width || col < 0 || row >= height || row < 0) return false;
    if (maze[row][col] == 'v') return true;
    return false;
}

bool Maze::isClear(const int& col, const int& row) const {
    if (col >= width || col < 0 || row >= height || row < 0) return false;
    if (maze[row][col] == 'x' || maze[row][col] == 'v') return false;
    return true;
}

int Maze::getExitColumn() const {
    return exitCol;
}

void Maze::setVisited(const int& col, const int& row) {
    maze[row][col] = 'v';
}

void Maze::setPath(const int& col, const int& row) {
    maze[row][col] = 'p';
}

void Maze::display() const {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << maze[i][j];
        }
        cout << endl;
    }
}

Creature::Creature() {

}

Creature::Creature(const int& col, const int& row) {
    this->col = col;
    this->row = row;
}

void Creature::setColumn(const int& newCol) {
    this->col = newCol;
}

void Creature::setRow(const int& newRow) {
    this->row = newRow;
}

int Creature::getColumn() const {
    return col;
}

int Creature::getRow() const {
    return row;
}

void Creature::moveNorth() {
    this->setRow(row - 1);
}

void Creature::moveSouth() {
    this->setRow(row + 1);
}

void Creature::moveEast() {
    this->setColumn(col + 1);
}

void Creature::moveWest() {
    this->setColumn(col - 1);
}
#endif