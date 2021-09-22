#include "Board.hpp"
#include "Ex4-3.hpp"

using namespace std;

int main() {
    Maze newMaze = Maze(7, 20, 18, 12);
    Creature goblin = Creature(12, 6);
    string arr[] = {
                    "x     x        xxx x",
                    "x xxxxx  xxxxx  xx x",
                    "x xxxxx xxxxxxx xx x",
                    "x x          xx xx x",
                    "x xxxxxxxxxx xx    x",
                   };

    newMaze.createMaze(arr);
    newMaze.display();

    cout << endl << endl;

    findExit(newMaze, goblin);

    newMaze.setPath(12, 5);
    newMaze.display();

    return 0;
}