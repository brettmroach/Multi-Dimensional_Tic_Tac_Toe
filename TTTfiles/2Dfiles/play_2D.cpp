//play_2D.cpp
#include <string>
#include <iostream>
#include "ttt2D.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "  Usage: " << argv[0] << " [size]\n";
        exit(1);
    }
    int size = stoi(argv[1]);
    // begins the game of tic tac toe
    string player1 = namePlayer_2D(1);
    string player2 = namePlayer_2D(2);
    ttt2D(player1, player2, size);
    return 0;
}