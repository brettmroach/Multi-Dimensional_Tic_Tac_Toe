// printoutTest.cpp

#include <iostream>
#include <string>
#include <cmath>
#include "functions.h"
#include "utility.h"
#include "gameStatus.h"
#include "winDetection.h"
using namespace std;

void test_wins(int size);

int main() {
/*    Player *player = createPlayer_4D();
    cout << player->name << " is " << player->piece << "'s\n"
         << (player+1)->name << " is " << (player+1)->piece << "'s\n";
    int size = gameSize_4D();
 */
    int size = 3;
/*
    string game = newGame_string_4D(size);

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
 */
    test_wins(size);

    return 0;
}

void test_wins(int size) {
    string game;
    for (int num1 = 0; num1 < size; num1++) {
        for (int num2 = 0; num2 < size; num2++) {
            for (int num3 = 0; num3 < size; num3++) {
                // testing win1D_col_4D
                game = newGame_string_4D(size);
                for (int num4 = 0; num4 < size; num4++) {
                    game[(num3 * pow(size, 3)) + (num2 * pow(size, 2))
                          + (num1 * size) + num4] = 'x';
                }
                if (win1D_col_4D(size, num1, num2, num3, game)) {
                    cout << "  PASSED: win1D_col_4D; row(" << num1
                         << ") level(" << num2 << ") cube(" << num3
                         << ")\n";
                } else {
                    cout << "FAIL: win1D_col_4D; row(" << num1
                         << ") level(" << num2 << ") cube(" << num3
                         << ")\n";
                }

                // testing win1D_row_4D
                game = newGame_string_4D(size);
                for (int num4 = 0; num4 < size; num4++) {
                    game[(num3 * pow(size, 3)) + (num2 * pow(size, 2))
                          + (num4 * size) + num1] = 'x';
                }
                if (win1D_row_4D(size, num1, num2, num3, game)) {
                    cout << "  PASSED: win1D_row_4D; column(" << num1
                         << ") level(" << num2 << ") cube(" << num3
                         << ")\n";
                } else {
                    cout << "FAIL: win1D_row_4D; column(" << num1
                         << ") level(" << num2 << ") cube(" << num3
                         << ")\n";
                }
            }
        }
    }
    return;
}