#ifndef _CREATURE
#define _CREATURE

class Creature {
private:
    int col;
    int row;

public:
    Creature();

    Creature(const int& col, const int& row);

    void setColumn(const int& newCol);

    void setRow(const int& newRow);

    int getColumn() const;

    int getRow() const;

    void moveNorth();

    void moveSouth();

    void moveEast();

    void moveWest();
};
#endif