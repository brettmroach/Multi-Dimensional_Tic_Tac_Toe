//play_ttt3D.cpp
#include <iostream>
#include "functions.h"
#include "ttt3D.h"
using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "  Usage: " << argv[0] << " [size]\n";
        exit(1);
    }
    int size = stoi(argv[1]);
    string player1 = namePlayer_3D(1);
    string player2 = namePlayer_3D(2);
    ttt3D(player1, player2, size);
    return 0;
}