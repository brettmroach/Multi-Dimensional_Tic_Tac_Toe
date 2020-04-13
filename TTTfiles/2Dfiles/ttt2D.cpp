//ttt2D.cpp
// Brett Roach
// 2 Dimensional game of tic toe at any length and width

#include <iostream>
#include "ttt2D.h"

using namespace std;

int ttt2D(string player1, string player2, int size) {
    // generates a string of whitespaces as placeholders
    // for the gameboard and prints the empty gameboard
    string game = newGame_2D(size);
    placeOnGrid_2D(size, game);
    cout << "First move: ";
    string player_name;
    string result = "Unfinished";
    char player_piece;
    int turn = 0;
    while (result == "Unfinished") {
        if ((turn%2) == 0) {
            player_name = player1;
            player_piece = 'x';
        } else {
            player_name = player2;
            player_piece = 'o';
        }
        turn++;
        game = takeTurn_2D(size, game, player_name, player_piece);
        placeOnGrid_2D(size, game);
        result = gameStatus_2D(size, game);
        if (result == "Unfinished") {
            cout << "Next move: ";
            continue;
        } else if (result == "Draw") {
            cout << "It's a Draw\n";
            break;
        } else if (result == "Win") {
            cout << "\n  Congratulations " << player_name << endl;
            break;
        }
    }
    return 0;
}

string namePlayer_2D(int player_num) {
    // names the players
    string player_name;
    cout << "Player " << player_num << ": ";
    getline(cin, player_name);
    return player_name;
}

int gameSize_2D() {    
    // asks for the dimensions of the gameboard
    int size;
    char response;
    cout << "A typical game of 2-dimensional Tic Tac Toe is played on a 3x3 "
         << "game board,\nhowever this program allows for games of other "
         << "sizes in 2 dimensions.\n";
    do {
        cout << "Enter the desired width of the game: ";
        cin >> size;
        cout << "Play on " << size << "x" << size 
             << " game board? [Y/N] ";
        cin >> response;
    } while ((response != 'Y') && (response != 'y')); 
    return size;
}

string newGame_2D(int size) {
    // creates string of length (size*size) for empty gameboard
    string game;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            game += " ";
        }
    }
    return game;
}

void placeOnGrid_2D(int size, string game) {
    // Prints the current game onto the screen

    string grid = "\nColumns: ";
    grid += to_string(0);
    for (int column = 1; column < size; column++) {
        grid += "   ";
        grid += to_string(column);
    }
    grid += " \n Row 0   ";
    // row 0, column 0
    grid += game[0];
    for (int column = 1; column < size; column++) {
        // row 0, columns [1, size)
        grid += " \u2502 ";
        grid += game[column];
    }
    for (int row = 1; row < size; row++) {
        // set breaks above column 0, for rows [1, size)
        grid += " \n        \u2500\u2500\u2500";
        for (int column = 1; column < size; column++) {
            // set breaks above columns [1, size), for rows [1, size)
            grid += "\u253C\u2500\u2500\u2500";
        }
        grid += "\n Row ";
        grid += to_string(row);
        grid += "   ";
        // rows [1, size), column 0
        grid += game[row * size];
        for (int column = 1; column < size; column++) {
            // rows [1, size), columns [1, size)
            grid += " \u2502 ";
            grid += game[(row * size) + column];
        }
    }
    grid += " \n\n";
    cout << grid;
}

string takeTurn_2D(int size, string game, string player_name, char player_piece) {
    string game_pieces = game;
    cout << player_name << "(" << player_piece << ")\n";
    int placement = coordinate_2D(size, game);
    game_pieces[placement] = player_piece;
    return game_pieces;
}

int coordinate_2D(int size, string game) {
    int coordinates[2];
    int placement;
    bool valid;
    do {
        cout << "Row: ";
        cin >> coordinates[0];
        cout << "Column: ";
        cin >> coordinates[1];
        placement = ((coordinates[0] * size) + coordinates[1]);
        if (game[placement] != ' ') {
            cout << "That space is taken.\n";
            valid = false;
        } else if ((coordinates[0] < 0) || (coordinates[0] >= size) || 
                   (coordinates[1] < 0) || (coordinates[1] >= size)) {
            cout << "Row and Collumn # must be an integer from 0 to " << (size-1)<< endl;
            valid = false;
        } else {
            valid = true;
        }
    }   while (!valid);
    return placement;
}

bool rowWin(int size, int row, string game) {
    bool result = true;
    int placement = (row * size);
    for (int column = 0; column < size; column++) {
        int spot = placement + column;
        if (game[spot] == ' ') {
            result = false;
            break;
        } else if (game[spot] != game[placement]) {
            result = false;
            break;
        } else {
            continue;
        }
    }
    return result;
}

bool rowPossible(int size, int row, string game) {
    bool result = true;
    bool x = false, o = false;
    int placement = (row * size);
    for (int column = 0; column < size; column++) {
        if (game[placement + column] == 'x') {
            // check if x is in the row
            x = true;
        } else if (game[placement + column] == 'o') {
            // check if o is in the row
            o = true;
        } else {
            continue;
        }
    }
    if (x && o) {
        result = false;
    }
    return result;
}

bool columnWin(int size, int column, string game) {
    bool result = true;
    for (int row = 0; row < size; row++) {
        int spot = column + (row * size);
        if (game[spot] == ' ') {
            result = false;
            break;
        } else if (game[spot] != game[column]) {
            result = false;
            break;
        } else {
            continue;
        }
    }
    return result;
}

bool columnPossible(int size, int column, string game) {
    bool result = true;
    bool x = false, o = false;
    int placement;
    for (int row = 0; row < size; row++) {
        placement = row * size;
        if (game[column + placement] == 'x') {
            x = true;
        } else if (game[column + placement] == 'o') {
            o = true;
        } else {
            continue;
        }
    }
    if (x && o) {
        result = false;
    }
    return result;
}

bool fDiagWin(int size, string game) {
    bool result = true;
    for (int place = 0; place < size; place++) {
        int spot = (place * size) + place; 
        if (game[spot] == ' ') {
            result = false;
            break;
        } else if (game[spot] != game[0]) {
            result = false;
            break;
        } else {
            continue;
        }
    }
    return result;
}

bool fDiagPossible(int size, string game) {
    bool result = true;
    bool x = false, o = false;
    for (int row = 0; row < size; row ++) {
        if (game[(row*size) +row] == 'x') {
            x = true;
        } else if (game[(row * size) + row] == 'o') {
            o = true;
        } else {
            continue;
        }
    }
    if (x && o) {
        result = false;
    }
    return result;
}

bool rDiagWin(int size, string game) {
    bool result = true;
    int spot = 0;
    for (int place = 0; place < size; place++) {
        spot += size - 1;
        if (game[spot] == ' ') {
            result = false;
            break;
        } else if (game[spot] != game[size-1]) {
            result = false;
            break;
        } else {
            continue;
        }
    }
    return result;
}

bool rDiagPossible(int size, string game) {
    bool result = true;
    bool x = false, o = false;
    int placement = 0;
    for (int row = 0; row < size; row ++) {
        placement += size - 1;
        if (game[placement] == 'x') {
            x = true;
        } else if (game[placement] == 'o') {
            o = true;
        } else {
            continue;
        }
    }
    if (x && o) {
        result = false;
    }
    return result;
}

string gameStatus_2D(int size, string game) {
    // return options are "Win"", "Draw", or "Unfinished"
    // First, test for Wins
    if (detectWin_2D(size, game)) {
        return "Win";
    } else if (detectDraw_2D(size, game)) {
        // If no one has won, check if the game is a draw
        return "Draw";
    } else {
        // If there is no win or draw, the game continues
        return "Unfinished";
    }
}

bool detectWin_2D(int size, string game) {
    // test the rows and columns for wins
    for (int num = 0; num < size; num++) {
        if (rowWin(size, num, game)) {
            cout << "Win in row " << num << endl;
            return true;
        } else if (columnWin(size, num, game)) {
            cout << "Win in column " << num << endl;
            return true;
        } else {
            continue;
        }
    }
    // test the diagonals for wins
    if (fDiagWin(size, game)) {
        cout << "Win on the forward diagonal\n";
        return true;
    } else if (rDiagWin(size, game)) {
        cout << "Win on the reverse diagonal\n";
        return true;
    } else {
        return false;
    }
}

bool detectDraw_2D(int size, string game) {
    // test to see if a win is still possible in any row or column
    for (int num = 0; num < size; num++) {
        if (rowPossible(size, num, game)) {
            return false;
        } else if (columnPossible(size, num, game)) {
            return false;
        } else {
            continue;
        }
    }
    // test to see if a win is still possible along either diagonal
    if (fDiagPossible(size, game)) {
        return false;
    } else if (rDiagPossible(size, game)) {
        return false;
    } else {
        return true;
    }
}
