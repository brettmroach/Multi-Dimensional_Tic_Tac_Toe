// functions.cpp
// functions for each turn in ttt4D

#include <iostream>
#include <string>
#include <cmath>
#include "functions.h"
#include "utility.h"

using namespace std;

Player *createPlayer_4D() {
    Player *p1 = new Player, *p2 = new Player;
    cout << "Player 1: ";
    getline(cin, p1->name);
    p1->piece = 'x';
    cout << "Player 2: ";
    getline(cin, p2->name);
    p2->piece = 'o';
    return p1;
}

int gameSize_4D() {
    int size;
    char response;
    do {
        cout << "Enter the size of the desired game: ";
        cin >> size;
        cout << "Play on " << size << "x" << size << "x"
             << size << "x" << size << " game board? Y/N" << endl;
        cin >> response;
    } while ((response != 'Y') && (response != 'y')); 
    return size;
}

/* For the vector P for a position on the gameboard: 
 * P = <cube, level, row, column>
 * The index I of P in the game-string can be calculated like so:
 * I = (cube*size*size*size)+(level*size*size)+(row*size)+(column)
 */
string newGame_string_4D(int size) {
    string game;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                for (int l = 0; l < size; l++) {
                    game += " ";
                }
            }
        }
    }
    return game;
}

int coordinate_4D(int size, string game) {
    int cube, level, row, column;
    int placement;
    bool valid;
    do {
        cout << "  Cube: ";
        cin >> cube;
        cout << "  Level: ";
        cin >> level;
        cout << "  Row: ";
        cin >> row;
        cout << "  Column: ";
        cin >> column;
        placement = (cube * pow(size, 3)) + (level * pow(size, 2)) + (row * size) + column;
        if ((cube < 0) || (cube >= size) || (level < 0) || (level >= size) || (row < 0) || 
                   (row >= size) || (column < 0) || (column >= size)) {
            cout << "Cube/Level/Row/Collumn # must be a number from 0 to " << (size-1)<< endl;
            valid = false;
        } else if (game[placement] != ' ') {
            cout << "That space is taken.\n";
            valid = false;
        } else {
            valid = true;
        }
    }   while (!valid);
    return placement;
}

void takeTurn_4D(int size, string& game, Player *player) {
    cout << player->name << ": " << player->piece << endl;
    int position = coordinate_4D(size, game);
    cout << position << endl;
    game[position] = player->piece;
    return;
}

/* "column", "row", "level", and "cube" are all vectors[0, size-1]
 * (row) x (column) makes the 2D square
 * (level) x (row) x (column) makes the 3D cube
 * (cube) x (level) x (row) x (column) makes the 4D hypercube
 */
void placeOnGrid_4D(int size, string game) {
    // outputs the current gameboard
    // initialize the column 0, row 0, level 0, cube 0
    string grid = "";
    // label each cube
    for (int cube = 0; cube < size; cube++) {
        grid += "Cube ";
        grid += to_string(cube);
        grid += "\n";
        // label each level in the current cube
        for (int level = 0; level < size; level++) {
            grid += "Level ";
            grid += to_string(level);
            grid += " ";
            for (int column = 2; column < size; column++) {
                grid += "    ";
            }
        }
        grid += "\n ";
        // cube [0,size-1], level 0, row 0, column 0
        grid += game[(cube * pow(size, 3))];
        for (int column = 1; column < size; column++) {
            // cube [0,size-1], level 0, row 0, column [1,size-1]
            grid += " \u2502 ";
            grid += game[(cube * pow(size, 3)) + column];
        }
        for (int level = 1; level < size; level++) {
            // cube [0,size-1], level [1,size-1], row 0, column 0
            grid += "   ";
            grid += game[(cube * pow(size, 3)) + (level * pow(size, 2))];
            for (int column = 1; column < size; column++) {
                // cube [0,size-1], level [1,size-1], row 0, column [1,size-1]
                grid += " \u2502 ";
                grid += game[(cube * pow(size, 3)) + (level * pow(size, 2)) + column];
            }
        }
        for (int row = 1; row < size; row++) {
            // set breaks above column 0 on level 0, for rows [1,size-1]
            grid += " \n\u2500\u2500\u2500";
            for (int column = 1; column < size; column++) {
                // set breaks above columns [1,size-1]
                grid += "\u253C\u2500\u2500\u2500";
            }
            for (int level = 1; level < size; level++) {
                // set breaks above column 0, on levels [1,size-1]
                grid += " \u2500\u2500\u2500";
                for (int column = 1; column < size; column++) {
                    // set breaks above columns [1,size-1]
                    grid += "\u253C\u2500\u2500\u2500";
                }
            }
            grid += "\n ";
            // cube [0,size-1], level 0, row [1,size-1], column 0
            grid += game[(cube * pow(size, 3)) + (row * size)];
            for (int column = 1; column < size; column++) {
                // cube [0,size-1], level 0, row [1,size-1], column [1,size-1]
                grid += " \u2502 ";
                grid += game[(cube * pow(size, 3)) + (row * size) +  column];
            }
            for (int level = 1; level < size; level++) {
                // cube [0,size-1], level 0, row [1,size-1], column 0
                grid += "   ";
                grid += game[(cube * pow(size, 3)) + (level * pow(size, 2)) + (row * size)];
                for (int column = 1; column < size; column++) {
                    // cube [0,size-1], level [1,size-1], row [1,size-1], column [1,size-1]
                    grid += " \u2502 ";
                    grid += game[(cube * pow(size, 3)) + (level * pow(size, 2)) + (row * size) + column];
                }
            }
        }
        grid += " \n";
    }
    cout << grid;
}

/* This was an alternative method for holding the game data
 * using a multidimensional array. I elected to continue to
 * store the game data in a string as it it uses less data 
 * and would be potentially more manageable if/when I adapt
 * this program to recursively create a game in any number 
 * of dimensions.

char *newGame1(int size) {
    char *game = new char;
    for (int i=0; i < size; i++) {
        *(game+i) = 060 + i;
    }
    return game;
}
char **newGame2(int size) {
    char **game = new char *;
    for (int i=0; i < size; i++) {
        *(game+i) = newGame1(size);
    }
    *game = newGame1(size);
    return game;
}
char ***newGame3(int size) {
    char ***game = new char **;
    for (int i=0; i < size; i++) {
        *(game+i) = newGame2(size);
    }
    *game = newGame2(size);
    return game;
}
char ****newGame4(int size) {
    char ****game = new char ***;
    for (int i=0; i < size; i++) {
        *(game+i) = newGame3(size);
    }
    *game = newGame3(size);
    return game;
}
*/
