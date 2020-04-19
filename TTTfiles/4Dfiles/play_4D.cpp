//play_4D.cpp
#include <iostream>
#include "functions.h"
#include "ttt4D.h"
using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "  Usage: " << argv[0] << " [size]\n";
        exit(1);
    }
    int size = stoi(argv[1]);
    Player *player = createPlayer_4D();
    ttt4D(player, size);
    return 0;
}
