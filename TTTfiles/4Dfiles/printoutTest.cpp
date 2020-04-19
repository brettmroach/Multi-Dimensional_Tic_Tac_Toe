// printoutTest.cpp

#include <iostream>
#include <string>
#include "functions.h"
#include "utility.h"
using namespace std;

int main() {
    Player *player = createPlayer_4D();
    cout << player->name << " is " << player->piece << "'s\n"
         << (player+1)->name << " is " << (player+1)->piece << "'s\n";
    int size = gameSize_4D();
    string emptyGame = newGame_string_4D(size);
    placeOnGrid_4D(size, emptyGame);
    return 0;
}