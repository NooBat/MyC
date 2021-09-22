#ifndef _QUEEN
#define _QUEEN

#include<math.h>

class Board;

class Queen {
private:
    int row;        //row of queen if it is on the board
    int col;        //column of queen if it is on the board

    //All queens share the same board
    static const Board* boardPtr;

public:
    /** Places a queen in upper-left corner of the board. */
    Queen();

    /** Places a queen at given location. */
    Queen(int inRow, int inCol);

    /** @returns Column number. */
    int getCol() const;

    /** @returns Row number. */
    int getRow() const;

    /** Moves queen to the next row. */
    void nextRow();

    /** Sees whether the queen is under attack by another queen.
     * @returns True if another queen is in the same row or
     * the same diagonal; otherwise false. */
    bool isUnderAttack() const;

    static void setBoard(const Board* bPtr);
};
void Queen::setBoard(const Board* bPtr) {
    Queen::boardPtr = bPtr;
}
const Board* Queen::boardPtr = nullptr;
#endif
