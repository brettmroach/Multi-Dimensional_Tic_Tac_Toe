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
    string game = newGame_string_4D(size);
    placeOnGrid_4D(size, game);
    return 0;
}
