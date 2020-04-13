// functions.cpp
// functions for each turn in ttt3D

#include <iostream>
#include <string>

using namespace std;

void printCube_3D() {
    // INCOMPLETE
    return;
}

string namePlayer_3D(int player_num) {
    // names the players
    string player_name;
    cout << "Player " << player_num << ": ";
    getline(cin, player_name);
    return player_name;
}

int gameSize_3D() {
    // asks for the dimensions of the gameboard
    int size;
    char response;
    cout << "A typical game of 2-dimensional Tic Tac Toe is played on a 3x3 "
         << "game board,\nhowever this program allows for games of other "
         << "sizes in 3 dimensions.\n";
    do {
        cout << "Enter the desired width of the game: ";
        cin >> size;
        cout << "The terminal width must be set to " << 7+(4*size*size)
             << " or greater.\nPlay on " << size << "x" << size << "x"
             << size << " game board? [Y/N] ";
        cin >> response;
    } while ((response != 'Y') && (response != 'y')); 
    return size;
}

string newGame_3D(int size) {
    // creates string of length (size*size*size) for empty gameboard
    string game;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                game += " ";
            }
        }
    }
    return game;
}

int coordinate_3D(int size, string game) {
    // Asks the player for input for where they want to play
    int level, row, column;
    int placement;
    bool valid;
    do {
        cout << "Level: ";
        cin >> level;
        cout << "Row: ";
        cin >> row;
        cout << "Column: ";
        cin >> column;
        placement = ((level * size * size) + (row * size) + column);
        if (game[placement] != ' ') {
            cout << "That space is taken.\n";
            valid = false;
        } else if ((level < 0) || (level >= size) || (row < 0) || 
                   (row >= size) || (column < 0) || (column >= size)) {
            cout << "Level, Row, and Collumn # must be a number from 0 to " << (size-1)<< endl;
            valid = false;
        } else {
            valid = true;
        }
    }   while (!valid);
    return placement;
}

void takeTurn_3D(int size, string& game, string player_name, char player_piece) {
    // Tells the current player to take their turn and places their
    // move on the "game" string
    cout << player_name << "(" << player_piece << ")\n";
    int placement = coordinate_3D(size, game);
    game[placement] = player_piece;
    return;
}

void placeOnGrid_3D(int size, string game) {
    // Prints the current game onto the screen

    string grid = "\nColumns: ";
    grid += to_string(0);
    for (int column = 1; column < size; column++) {
        grid += "   ";
        grid += to_string(column);
    }
    for (int level = 1; level < size; level++) {
        for (int column = 0; column < size; column++) {
            grid += "   ";
            grid += to_string(column);
        }
    }
    grid += " \n Row 0   ";
    // row 0, column 0, level 0
    grid += game[0];
    for (int column = 1; column < size; column++) {
        // row 0, columns [1, size), level 0
        grid += " \u2502 ";
        grid += game[column];
    }
    for (int level = 1; level < size; level++) {
        // row 0, column 0, levels [1, size)
        grid += "   ";
        grid += game[level * size * size];
        for (int column = 1; column < size; column++) {
            // row 0, columns [1, size), levels [1, size)
            grid += " \u2502 ";
            grid += game[(level * size * size) + column];
        }
    }
    for (int row = 1; row < size; row++) {
        // set breaks above column 0 on level 0, for rows [1, size)
        grid += " \n        \u2500\u2500\u2500";
        for (int column = 1; column < size; column++) {
            // set breaks above columns [1, size) on level 0, for rows [1, size)
            grid += "\u253C\u2500\u2500\u2500";
        }
        for (int level = 1; level < size; level++) {
            // set breaks above column 0, on levels [1, size)
            grid += " \u2500\u2500\u2500";
            for (int column = 1; column < size; column++) {
                // set breaks above columns [1, size)
                grid += "\u253C\u2500\u2500\u2500";
            }
        }
        grid += "\n Row ";
        grid += to_string(row);
        grid += "   ";
        grid += game[row * size];
        for (int column = 1; column < size; column++) {
            grid += " \u2502 ";
            grid += game[(row * size) + column];
        }
        for (int level = 1; level < size; level++) {
            grid += "   ";
            grid += game[(level * size * size) + (row * size)];
            for (int column = 1; column < size; column++) {
                grid += " \u2502 ";
                grid += game[(level * size * size) + (row * size) + column];
            }
        }
    }
    grid += "\n       ";
    int y = (4 * (size - 2)) / 2;
    if (y >= 0) {
        for (int level = 0; level < size; level++) {
            for (int x = 0; x <= y; x++) {
                grid += " ";
            }
            grid += "Level ";
            grid += to_string(level);
            for (int x = 0; x < y; x++) {
                grid += " ";
            }
        }
    }
    grid += "\n\n";
    cout << grid;
}
