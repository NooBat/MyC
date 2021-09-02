#include "Board.h"
#include "Ex1.h"

using namespace std;

int main() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        Board* newBoard = new Board();
        Queen::setBoard(newBoard);
        newBoard->doEightQueens(i);

        newBoard->display();
        if (i < BOARD_SIZE - 1) cout << endl << endl;
    }

    return 0;
}