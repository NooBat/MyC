#ifndef _MAIN
#define _MAIN

#include "Ex4-1.hpp"
#include "Ex4-2.hpp"

bool goNorth(Maze& maze, Creature& o);
bool goSouth(Maze& maze, Creature& o);
bool goEast(Maze& maze, Creature& o);
bool goWest(Maze& maze, Creature& o);

bool goNorth(Maze& maze, Creature& o) {
    bool success = false;

    if (maze.isClear(o.getColumn(), o.getRow() - 1)) {  
        o.moveNorth();
        maze.setPath(o.getColumn(), o.getRow());

        if (o.getColumn() == maze.getExitColumn() && o.getRow() == 0) success = true;
        else {
            success = goNorth(maze, o);
            if (!success) {
                success = goWest(maze, o);
                if (!success) {
                    success = goEast(maze, o);
                    if (!success) {
                        maze.setVisited(o.getColumn(), o.getRow());
                        o.moveSouth();
                    }
                }
            }
        }
    }
    else success = false;

    return success;
}

bool goSouth(Maze& maze, Creature& o) {
    bool success = false;

    if (maze.isClear(o.getColumn(), o.getRow() + 1)) {
        o.moveSouth();
        maze.setPath(o.getColumn(), o.getRow());

        if (o.getColumn() == maze.getExitColumn() && o.getRow() == 0) success = true;
        else {
            success = goSouth(maze, o);
            if (!success) {
                success = goWest(maze, o);
                if (!success) {
                    success = goEast(maze, o);
                    if (!success) {
                        maze.setVisited(o.getColumn(), o.getRow());
                        o.moveNorth();
                    }
                }
            }
        }
    }
    else success = false;

    return success;
}

bool goEast(Maze& maze, Creature& o) {
    bool success = false;

    if (maze.isClear(o.getColumn() + 1, o.getRow())) {
        o.moveEast();
        maze.setPath(o.getColumn(), o.getRow());

        if (o.getColumn() == maze.getExitColumn() && o.getColumn() == 0) success = true;
        else {
            success = goEast(maze, o);
            if (!success) {
                success = goNorth(maze, o);
                if (!success) {
                    success = goSouth(maze, o);
                    if (!success) {
                        maze.setVisited(o.getColumn(), o.getRow());
                        o.moveWest();
                    }
                }
            }
        }
    }
    else success = false;

    return success;
}

bool goWest(Maze& maze, Creature& o) {
    bool success = false;

    if (maze.isClear(o.getColumn() - 1, o.getRow())) {
        o.moveWest();
        maze.setPath(o.getColumn(), o.getRow());
        
        if (o.getColumn() == maze.getExitColumn() && o.getRow() == 0) success = true;
        else {
            success = goWest(maze, o);
            if (!success) {
                success = goNorth(maze, o);
                if (!success) {
                    success = goSouth(maze, o);
                    if (!success) {
                        maze.setVisited(o.getColumn(), o.getRow());
                        o.moveEast();
                    }
                }
            }
        }
    }
    else success = false;

    return success;
}

bool findExit(Maze& maze, Creature& o) {
    bool success;
    if (o.getColumn() == maze.getExitColumn() && o.getRow() == 0) return true;
    else {
        success = goNorth(maze, o);
        if (!success) {
            success = goWest(maze, o);
            if (!success) {
                success = goSouth(maze, o);
                if (!success) {
                    success = goEast(maze, o);
                }
            }
        }
    }

    return success;
}

#endif