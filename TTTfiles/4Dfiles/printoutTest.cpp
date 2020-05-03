// printoutTest.cpp

#include <iostream>
#include <string>
#include "functions.h"
#include "utility.h"
#include "gameStatus.h"
#include "winDetection.h"
using namespace std;

bool test_wins(int size, string game);

int main() {
/*    Player *player = createPlayer_4D();
    cout << player->name << " is " << player->piece << "'s\n"
         << (player+1)->name << " is " << (player+1)->piece << "'s\n";
    int size = gameSize_4D();
 */
    int size = 3;
    string game = newGame_string_4D(size);
//    placeOnGrid_4D(size, game);

    Player *test1 = new Player((Player){"Test 1", 'x'});
    Player *test2 = new Player((Player){"Test 2", 'x'});
    Player *test3 = new Player((Player){"Test 3", 'x'});
    cout << "Enter the spaces on which you wish to test a win:\n";
    takeTurn_4D(size, game, test1);
    delete test1;
    takeTurn_4D(size, game, test2);
    delete test2;
    takeTurn_4D(size, game, test3);
    delete test3;
    placeOnGrid_4D(size, game);

    if (test_wins(size, game)) {
        cout << "PASSED\n";
    } else {
        cout << "FAILED\n";
    }
 
    return 0;
}

bool test_wins(int size, string game) {
    for (int num1 = 0; num1 < size; num1++) {
        for (int num2 = 0; num2 < size; num2++) {
            for (int num3 = 0; num3 < size; num3++) {
                if (win1D(size, num1, num2, num3, game)) {
                    return true;
                } else {
                    continue;
                }
            }
            if (win2D(size, num1, num2, game)) {
                return true;
            } else {
                continue;
            }
        }
        if (win3D(size, num1, game)) {
            return true;
        } else {
            continue;
        }
    }
    return false;
}