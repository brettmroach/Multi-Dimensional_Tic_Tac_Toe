//testFuncs4D.cpp
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include "functions.h"
#include "utility.h"
#include "gameStatus.h"
#include "winDetection.h"
#include "testFuncs4D.h"
using namespace std;

GameStringList *test_wins(int size) {
    string game;
    GameStringList *failures = new GameStringList;
    for (int num1 = 0; num1 < size; num1++) {
        for (int num2 = 0; num2 < size; num2++) {
            for (int num3 = 0; num3 < size; num3++) {
                // testing win1D_col_4D
                game = newGame_string_4D(size);
                for (int num4 = 0; num4 < size; num4++) {
                    game[(num3 * pow(size, 3))
                          + (num2 * pow(size, 2))
                          + (num1 * size) + num4] = 'x';
                }
                cout << test_win1D_col_4D(size, num1, num2, num3,
                                           game, failures);

                // testing win1D_row_4D
                game = newGame_string_4D(size);
                for (int num4 = 0; num4 < size; num4++) {
                    game[(num3 * pow(size, 3))
                          + (num2 * pow(size, 2))
                          + (num4 * size) + num1] = 'x';
                }
                cout << test_win1D_row_4D(size, num1, num2, num3,
                                           game, failures);

                // testing win1D_lev_4D
                game = newGame_string_4D(size);
                for (int num4 = 0; num4 < size; num4++) {
                    game[(num3 * pow(size, 3))
                          + (num4 * pow(size, 2))
                          + (num2 * size) + num1] = 'x';
                }
                cout << test_win1D_lev_4D(size, num1, num2, num3,
                                           game, failures);

                // testing win1D_cub_4D
                game = newGame_string_4D(size);
                for (int num4 = 0; num4 < size; num4++) {
                    game[(num4 * pow(size, 3))
                          + (num3 * pow(size, 2))
                          + (num2 * size) + num1] = 'x';
                }
                cout << test_win1D_cub_4D(size, num1, num2, num3,
                                           game, failures);
            }
        }
    }
    return failures;
}

void check_failures(GameStringList *list, int size) {
    GameString *gs = list->head;
    while (gs != NULL) {
        cout << endl << gs->message;
        placeOnGrid_4D(size, gs->game);
        gs = gs->next;
    }
    return;
}

string test_win1D_col_4D(int size, int num1, int num2, int num3,
                         string game, GameStringList *failures) {
    ostringstream oss;
    if (win1D_col_4D(size, num1, num2, num3, game)) {
        oss << "  PASSED: win1D_col_4D; row(" << num1
            << ") level(" << num2 << ") cube(" << num3
            << ")\n";
    } else {
        oss << "FAIL: win1D_col_4D; row(" << num1
            << ") level(" << num2 << ") cube(" << num3
            << ")\n";
        addToGameStringList(failures, game);
        failures->tail->message = oss.str();
    }
    return oss.str();
}
string test_win1D_row_4D(int size, int num1, int num2, int num3,
                         string game, GameStringList *failures) {
    ostringstream oss;
    if (win1D_row_4D(size, num1, num2, num3, game)) {
        oss << "  PASSED: win1D_row_4D; col(" << num1
            << ") level(" << num2 << ") cube(" << num3
            << ")\n";
    } else {
        oss << "FAIL: win1D_row_4D; col(" << num1
            << ") level(" << num2 << ") cube(" << num3
            << ")\n";
        addToGameStringList(failures, game);
        failures->tail->message = oss.str();
    }
    return oss.str();
}
string test_win1D_lev_4D(int size, int num1, int num2, int num3,
                         string game, GameStringList *failures) {
    ostringstream oss;
    if (win1D_lev_4D(size, num1, num2, num3, game)) {
        oss << "  PASSED: win1D_lev_4D; col(" << num1
            << ") row(" << num2 << ") cube(" << num3
            << ")\n";
    } else {
        oss << "FAIL: win1D_lev_4D; col(" << num1
            << ") row(" << num2 << ") cube(" << num3
            << ")\n";
        addToGameStringList(failures, game);
        failures->tail->message = oss.str();
    }
    return oss.str();
}
string test_win1D_cub_4D(int size, int num1, int num2, int num3,
                         string game, GameStringList *failures) {
    ostringstream oss;
    if (win1D_cub_4D(size, num1, num2, num3, game)) {
        oss << "  PASSED: win1D_cub_4D; col(" << num1
            << ") row(" << num2 << ") level(" << num3
            << ")\n";
    } else {
        oss << "FAIL: win1D_cub_4D; col(" << num1
            << ") row(" << num2 << ") level(" << num3
            << ")\n";
        addToGameStringList(failures, game);
        failures->tail->message = oss.str();
    }
    return oss.str();
}