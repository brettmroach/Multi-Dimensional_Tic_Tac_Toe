//play_ttt3D.cpp
// Brett Roach
// 3 Dimensional game of tic toe at any length and width

#include <iostream>
#include "ttt3D.h"
#include "functions.h"
#include "gameStatus.h"

using namespace std;

int ttt3D(string player1, string player2, int size) {
    // Generate a string of whitespaces as placeholders
    // for the gameboard and print the empty gameboard
    string game = newGame_3D(size);
    cout << "\nThe rows, columns, and levels are numbered 0 - " << size-1 << endl;
    placeOnGrid_3D(size, game);
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
        takeTurn_3D(size, game, player_name, player_piece);
        placeOnGrid_3D(size, game);
        result = gameStatus_3D(size, game);
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