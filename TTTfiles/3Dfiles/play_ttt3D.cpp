//play_ttt3D.cpp
#include <string>
#include "ttt3D.h"
#include "functions.h"
using namespace std;

int main() {
    // begins the game of tic tac toe
    // Name each player
    string player1 = namePlayer_3D(1);
    string player2 = namePlayer_3D(2);
    // Ask the player for dimensions of game board
    int size = gameSize_3D();
    ttt3D(player1, player2, size);
    return 0;
}