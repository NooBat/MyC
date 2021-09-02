#ifndef _BOARD
#define _BOARD
#define BOARD_SIZE 8

#include "Ex1.h"
#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

class Board {
private:
    vector<Queen*> queens;

    /** Sees whether a queen exists in position (inRow, inCol). */
    bool isQueen(const int& inRow, const int& inCol) const;

    /** Attempts to place queens on board, starting with the designated queen. */
    bool placeQueens(Queen* queenPtr);

    /** Removes the last queen from the board, but does not deallocate it. */
    void removeQueen();

    /** Places a queen on the board. */
    void setQueen(Queen* queenPtr);

public:
    /** Supplies the Queen class with a pointer to the board. */
    Board();

    /** Clears the board and removes pointer from queens. */
    ~Board();

    /** Clears board. */
    void clear();

    /** Displays board. */
    void display() const;

    /** Initiates the Eight Queens problem. */
    void doEightQueens();

    /** @return The number of queens on the board. */
    int getNumQueens() const;

    /** @return A pointer to the queen at the designated index. */
    Queen* getQueen(const int& index) const;
};

void Queen::setBoard(Board* bPtr) {
    boardPtr = bPtr;
}

Queen::Queen(): row(0), col(0) {

}

Queen::Queen(int inRow, int inCol) {
    row = inRow;
    col = inCol;
}

int Queen::getCol() const {
    return col;
}

int Queen::getRow() const {
    return row;
}

void Queen::nextRow() {
    this->row++;
}

bool Queen::isUnderAttack() const {
    for (int i = 0; i < boardPtr->getNumQueens(); i++) {
        Queen* curr = boardPtr->getQueen(i);

        int distance = abs(this->col - curr->col) + abs(this->row - curr->row);

        if (distance == this->col - curr->col || distance / 2 == this->col - curr->col) return false;
    }

    return true;
}

bool Board::isQueen(const int& inRow, const int& inCol) const {
    if (inRow >= BOARD_SIZE || inCol >= BOARD_SIZE) return false;
    for (int i = 0; i < queens.size(); i++) {
        if (queens[i]->getCol() == inCol && queens[i]->getRow() == inRow) return true;
    }

    return false;
}

bool Board::placeQueens(Queen* queenPtr) {
    // Base class: Try to place a queen in a nonexistent column.
    if (queenPtr->getCol() >= BOARD_SIZE || queenPtr->getRow() >= BOARD_SIZE) {
        delete queenPtr;
        queenPtr = nullptr;
        return true;
    }

    bool isPlaced = false;
    while (!isPlaced && queenPtr->getRow() < BOARD_SIZE) {
        //If the queen can be attacked, try moving it
        //to the next row in the current column
        if (queenPtr->isUnderAttack()) queenPtr->nextRow();
        else {
            // Put this queen on the board and try putting a
            // new queen in the first row of the next column
            setQueen(queenPtr);
            Queen* newQueenPtr = new Queen(0, queenPtr->getCol() + 1);
            isPlaced = placeQueens(newQueenPtr);

            if (!isPlaced) {
                delete newQueenPtr;
                removeQueen();
                queenPtr->nextRow();
            }
        }
    }

    return isPlaced;
}

void Board::removeQueen() {
    queens.erase(queens.end() - 1);
}

void Board::setQueen(Queen* queenPtr) {
    queens.push_back(queenPtr);
}

Board::Board() {

}

Board::~Board() {
    clear();
}

void Board::clear() {
    if (queens.size() == 0) return;

    Queen *curr = nullptr;
    for (int i = 0; i < queens.size(); i++) {
        curr = queens[i];

        delete curr;

        curr = nullptr;
    }

    queens.clear();
}

void Board::display() const {
    for (int i = 0; i < queens.size(); i++) {
        cout << "Queen number " << i + 1 << " is at: " 
             << queens[i]->getRow() << " " << queens[i]->getCol() << endl; 
    }
}

void Board::doEightQueens() {
    Queen* firstQueen = new Queen();

    placeQueens(firstQueen);
}

int Board::getNumQueens() const {
    return queens.size();
}

Queen* Board::getQueen(const int& index) const {
    return queens[index];
}
#endif