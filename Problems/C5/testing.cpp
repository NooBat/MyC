#include "Board.h"
#include "Ex1.h"

using namespace std;

int main() {
    Board* newBoard = new Board();

    Queen::setBoard(newBoard);

    newBoard->doEightQueens();

    newBoard->display();

    return 0;
}