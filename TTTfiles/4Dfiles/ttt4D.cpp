//ttt4D.cpp
// Brett Roach
// 4 Dimensional game of tic toe at any length and width

#include <iostream>
#include "ttt4D.h"
#include "functions.h"
#include "gameStatus.h"

using namespace std;

int ttt4D(Player *player, int size) {
    // Generate a string of whitespaces as placeholders
    // for the gameboard and prints the empty gameboard
    string game = newGame_string_4D(size);
    placeOnGrid_4D(size, game);
    cout << "The rows, columns, and levels are numbered 0 - " << size-1 << endl;
    cout << "First move: ";
    string result = "Unfinished";
    int turn = 0, player_num;
    while (result == "Unfinished") {
/*
        if ((turn%2) == 0) {
            player_name = player;
            player_piece = 'x';
        } else {
            player_name = player2;
            player_piece = 'o';
        }
        takeTurn_4D(size, game, player_name, player_piece);
*/
        player_num = (turn%2);
        takeTurn_4D(size, game, (player+player_num));
        placeOnGrid_4D(size, game);
        result = gameStatus_4D(size, game);
        if (result == "Unfinished") {
            cout << "Next move: ";
            continue;
        } else if (result == "Draw") {
            cout << "It's a Draw\n";
            break;
        } else if (result == "Win") {
            cout << "Congratulations " << (player+player_num)->name << endl;
            break;
        }
        turn++;
    }
    return 0;
}