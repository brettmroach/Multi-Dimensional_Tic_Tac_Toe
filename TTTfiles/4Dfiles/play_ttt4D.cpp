//play_ttt4D.cpp
#include <string>
#include "ttt4D.h"
#include "functions.h"
using namespace std;

int main() {
    // Begins the game of tic tac toe
    Player *player = createPlayer_4D();
    // Promts player for dimensions of game board
    int size = gameSize_4D();
    ttt4D(player, size);
    return 0;
}