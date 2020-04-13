//play_ttt2D.cpp
#include <string>
#include "ttt2D.h"
using namespace std;


int main() {
    // begins the game of tic tac toe
    string player1 = namePlayer_2D(1);
    string player2 = namePlayer_2D(2);
    // promts player for dimensions of game board
    int size = gameSize_2D();
    ttt2D(player1, player2, size);
    return 0;
}