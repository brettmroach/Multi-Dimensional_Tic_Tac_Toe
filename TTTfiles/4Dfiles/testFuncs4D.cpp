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

/* ============================================================ */

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

/* ============================================================ */

            // testing win2D_ColRow_1_4D
            game = newGame_string_4D(size);
            for (int num4 = 0; num4 < size; num4++) {
                game[(num2 * pow(size, 3))
                      + (num1 * pow(size, 2))
                      + (num4 * size) + num4] = 'x';
            }
            cout << test_win2D_ColRow_1_4D(size, num1, num2,
                                            game, failures);
            
            // testing win2D_ColRow_2_4D
            game = newGame_string_4D(size);
            for (int num4 = 0; num4 < size; num4++) {
                game[(num2 * pow(size, 3))
                      + (num1 * pow(size, 2))
                      + (num4 * size) + (size - 1 - num4)] = 'x';
            }
            cout << test_win2D_ColRow_2_4D(size, num1, num2,
                                            game, failures);
            
            // testing win2D_ColLev_1_4D
            game = newGame_string_4D(size);
            for (int num4 = 0; num4 < size; num4++) {
                game[(num2 * pow(size, 3))
                      + (num4 * pow(size, 2))
                      + (num1 * size) + num4] = 'x';
            }
            cout << test_win2D_ColLev_1_4D(size, num1, num2,
                                           game, failures);

            // testing win2D_ColLev_2_4D
            game = newGame_string_4D(size);
            for (int num4 = 0; num4 < size; num4++) {
                game[(num2 * pow(size, 3))
                      + (num4 * pow(size, 2))
                      + (num1 * size) + (size - 1 - num4)] = 'x';
            }
            cout << test_win2D_ColLev_2_4D(size, num1, num2,
                                           game, failures);
                                           
            // testing win2D_ColCub_1_4D
            game = newGame_string_4D(size);
            for (int num4 = 0; num4 < size; num4++) {
                game[(num4 * pow(size, 3))
                      + (num2 * pow(size, 2))
                      + (num1 * size) + num4] = 'x';
            }
            cout << test_win2D_ColCub_1_4D(size, num1, num2,
                                           game, failures);
            
            // testing win2D_ColCub_2_4D
            game = newGame_string_4D(size);
            for (int num4 = 0; num4 < size; num4++) {
                game[(num4 * pow(size, 3))
                      + (num2 * pow(size, 2))
                      + (num1 * size) + (size - 1 - num4)] = 'x';
            }
            cout << test_win2D_ColCub_2_4D(size, num1, num2,
                                           game, failures);
            
            // testing win2D_RowLev_1_4D
            game = newGame_string_4D(size);
            for (int num4 = 0; num4 < size; num4++) {
                game[(num2 * pow(size, 3))
                      + (num4 * pow(size, 2))
                      + (num4 * size) + num1] = 'x';
            }
            cout << test_win2D_RowLev_1_4D(size, num1, num2,
                                           game, failures);
            
            // testing win2D_RowLev_2_4D
            game = newGame_string_4D(size);
            for (int num4 = 0; num4 < size; num4++) {
                game[(num2 * pow(size, 3))
                      + (num4 * pow(size, 2))
                      + ((size - 1 - num4) * size) + num1] = 'x';
            }
            cout << test_win2D_RowLev_2_4D(size, num1, num2,
                                           game, failures);

            // testing win2D_RowCub_1_4D
            game = newGame_string_4D(size);
            for (int num4 = 0; num4 < size; num4++) {
                game[(num4 * pow(size, 3))
                      + (num2 * pow(size, 2))
                      + (num4 * size) + num1] = 'x';
            }
            cout << test_win2D_RowCub_1_4D(size, num1, num2,
                                           game, failures);

            // testing win2D_RowCub_2_4D
            game = newGame_string_4D(size);
            for (int num4 = 0; num4 < size; num4++) {
                game[(num4 * pow(size, 3))
                      + (num2 * pow(size, 2))
                      + ((size - 1 - num4) * size) + num1] = 'x';
            }
            cout << test_win2D_RowCub_2_4D(size, num1, num2,
                                           game, failures);

            // testing win2D_LevCub_1_4D
            game = newGame_string_4D(size);
            for (int num4 = 0; num4 < size; num4++) {
                game[(num4 * pow(size, 3))
                      + (num4 * pow(size, 2))
                      + (num2 * size) + num1] = 'x';
            }
            cout << test_win2D_LevCub_1_4D(size, num1, num2,
                                           game, failures);

            // testing win2D_LevCub_2_4D
            game = newGame_string_4D(size);
            for (int num4 = 0; num4 < size; num4++) {
                game[(num4 * pow(size, 3))
                      + ((size - 1 - num4) * pow(size, 2))
                      + (num2 * size) + num1] = 'x';
            }
            cout << test_win2D_LevCub_2_4D(size, num1, num2,
                                           game, failures);

        }

/* ============================================================ */

        // testing win3D_ColRowLev_1_4D
        game = newGame_string_4D(size);
        for (int num4 = 0; num4 < size; num4++) {
            game[(num1 * pow(size, 3))
                  + (num4 * pow(size, 2))
                  + (num4 * size) + num4] = 'x';
        }
        cout << test_win3D_ColRowLev_1_4D(size, num1,
                                           game, failures);

        // testing win3D_ColRowLev_2_4D
        game = newGame_string_4D(size);
        for (int num4 = 0; num4 < size; num4++) {
            game[(num1 * pow(size, 3))
                  + (num4 * pow(size, 2))
                  + (num4 * size) + (size - 1 - num4)] = 'x';
        }
        cout << test_win3D_ColRowLev_2_4D(size, num1,
                                           game, failures);

        // testing win3D_ColRowLev_3_4D
        game = newGame_string_4D(size);
        for (int num4 = 0; num4 < size; num4++) {
            game[(num1 * pow(size, 3))
                  + (num4 * pow(size, 2))
                  + ((size - 1 - num4) * size) + num4] = 'x';
        }
        cout << test_win3D_ColRowLev_3_4D(size, num1,
                                           game, failures);

        // testing win3D_ColRowLev_4_4D
        game = newGame_string_4D(size);
        for (int num4 = 0; num4 < size; num4++) {
            game[(num1 * pow(size, 3))
                  + ((size - 1 - num4) * pow(size, 2))
                  + (num4 * size) + num4] = 'x';
        }
        cout << test_win3D_ColRowLev_4_4D(size, num1,
                                           game, failures);
        
        // testing win3D_ColRowCub_1_4D
        game = newGame_string_4D(size);
        for (int num4 = 0; num4 < size; num4++) {
            game[(num4 * pow(size, 3))
                  + (num1 * pow(size, 2))
                  + (num4 * size) + num4] = 'x';
        }
        cout << test_win3D_ColRowCub_1_4D(size, num1,
                                           game, failures);

        // testing win3D_ColRowCub_2_4D
        game = newGame_string_4D(size);
        for (int num4 = 0; num4 < size; num4++) {
            game[(num4 * pow(size, 3))
                  + (num1 * pow(size, 2))
                  + (num4 * size) + (size - 1 - num4)] = 'x';
        }
        cout << test_win3D_ColRowCub_2_4D(size, num1,
                                           game, failures);

        // testing win3D_ColRowCub_3_4D
        game = newGame_string_4D(size);
        for (int num4 = 0; num4 < size; num4++) {
            game[(num4 * pow(size, 3))
                  + (num1 * pow(size, 2))
                  + ((size - 1 - num4) * size) + num4] = 'x';
        }
        cout << test_win3D_ColRowCub_3_4D(size, num1,
                                           game, failures);

        // testing win3D_ColRowCub_4_4D
        game = newGame_string_4D(size);
        for (int num4 = 0; num4 < size; num4++) {
            game[((size - 1 - num4) * pow(size, 3))
                  + (num1 * pow(size, 2))
                  + (num4 * size) + num4] = 'x';
        }
        cout << test_win3D_ColRowCub_4_4D(size, num1,
                                           game, failures);

        // testing win3D_ColLevCub_1_4D
        game = newGame_string_4D(size);
        for (int num4 = 0; num4 < size; num4++) {
            game[(num4 * pow(size, 3))
                  + (num4 * pow(size, 2))
                  + (num1 * size) + num4] = 'x';
        }
        cout << test_win3D_ColLevCub_1_4D(size, num1,
                                           game, failures);

        // testing win3D_ColLevCub_2_4D
        game = newGame_string_4D(size);
        for (int num4 = 0; num4 < size; num4++) {
            game[(num4 * pow(size, 3))
                  + (num4 * pow(size, 2))
                  + (num1 * size) + (size - 1 - num4)] = 'x';
        }
        cout << test_win3D_ColLevCub_2_4D(size, num1,
                                           game, failures);

        // testing win3D_ColLevCub_3_4D
        game = newGame_string_4D(size);
        for (int num4 = 0; num4 < size; num4++) {
            game[(num4 * pow(size, 3))
                  + ((size - 1 - num4) * pow(size, 2))
                  + (num1 * size) + num4] = 'x';
        }
        cout << test_win3D_ColLevCub_3_4D(size, num1,
                                           game, failures);

        // testing win3D_ColLevCub_4_4D
        game = newGame_string_4D(size);
        for (int num4 = 0; num4 < size; num4++) {
            game[((size - 1 - num4) * pow(size, 3))
                  + (num4 * pow(size, 2))
                  + (num1 * size) + num4] = 'x';
        }
        cout << test_win3D_ColLevCub_4_4D(size, num1,
                                           game, failures);

        // testing win3D_RowLevCub_1_4D
        game = newGame_string_4D(size);
        for (int num4 = 0; num4 < size; num4++) {
            game[(num4 * pow(size, 3))
                  + (num4 * pow(size, 2))
                  + (num4 * size) + num1] = 'x';
        }
        cout << test_win3D_RowLevCub_1_4D(size, num1,
                                           game, failures);

        // testing win3D_RowLevCub_2_4D
        game = newGame_string_4D(size);
        for (int num4 = 0; num4 < size; num4++) {
            game[(num4 * pow(size, 3))
                  + (num4 * pow(size, 2))
                  + ((size - 1 - num4) * size) + num1] = 'x';
        }
        cout << test_win3D_RowLevCub_2_4D(size, num1,
                                           game, failures);

        // testing win3D_RowLevCub_3_4D
        game = newGame_string_4D(size);
        for (int num4 = 0; num4 < size; num4++) {
            game[(num4 * pow(size, 3))
                  + ((size - 1 - num4) * pow(size, 2))
                  + (num4 * size) + num1] = 'x';
        }
        cout << test_win3D_RowLevCub_3_4D(size, num1,
                                           game, failures);

        // testing win3D_RowLevCub_4_4D
        game = newGame_string_4D(size);
        for (int num4 = 0; num4 < size; num4++) {
            game[((size - 1 - num4) * pow(size, 3))
                  + (num4 * pow(size, 2))
                  + (num4 * size) + num1] = 'x';
        }
        cout << test_win3D_RowLevCub_4_4D(size, num1,
                                           game, failures);

    }

/* ============================================================ */

    // testing win4D_1_4D
    game = newGame_string_4D(size);
    for (int num4 = 0; num4 < size; num4++) {
        game[(num4 * pow(size, 3))
              + (num4 * pow(size, 2))
              + (num4 * size) + num4] = 'x';
    }
    cout << test_win4D_1_4D(size, game, failures);

    // testing win4D_2_4D
    game = newGame_string_4D(size);
    for (int num4 = 0; num4 < size; num4++) {
        game[(num4 * pow(size, 3))
              + (num4 * pow(size, 2))
              + (num4 * size) + (size - 1 - num4)] = 'x';
    }
    cout << test_win4D_2_4D(size, game, failures);

    // testing win4D_3_4D
    game = newGame_string_4D(size);
    for (int num4 = 0; num4 < size; num4++) {
        game[(num4 * pow(size, 3))
              + (num4 * pow(size, 2))
              + ((size - 1 - num4) * size) + num4] = 'x';
    }
    cout << test_win4D_3_4D(size, game, failures);

    // testing win4D_4_4D
    game = newGame_string_4D(size);
    for (int num4 = 0; num4 < size; num4++) {
        game[(num4 * pow(size, 3))
              + ((size - 1 - num4) * pow(size, 2))
              + (num4 * size) + num4] = 'x';
    }
    cout << test_win4D_4_4D(size, game, failures);

    // testing win4D_5_4D
    game = newGame_string_4D(size);
    for (int num4 = 0; num4 < size; num4++) {
        game[((size - 1 - num4) * pow(size, 3))
              + (num4 * pow(size, 2))
              + (num4 * size) + num4] = 'x';
    }
    cout << test_win4D_5_4D(size, game, failures);

    // testing win4D_6_4D
    game = newGame_string_4D(size);
    for (int num4 = 0; num4 < size; num4++) {
        game[((size - 1 - num4) * pow(size, 3))
              + (num4 * pow(size, 2))
              + (num4 * size) + (size - 1 - num4)] = 'x';
    }
    cout << test_win4D_6_4D(size, game, failures);

    // testing win4D_7_4D
    game = newGame_string_4D(size);
    for (int num4 = 0; num4 < size; num4++) {
        game[((size - 1 - num4) * pow(size, 3))
              + (num4 * pow(size, 2))
              + ((size - 1 - num4) * size) + num4] = 'x';
    }
    cout << test_win4D_7_4D(size, game, failures);

    // testing win4D_8_4D
    game = newGame_string_4D(size);
    for (int num4 = 0; num4 < size; num4++) {
        game[((size - 1 - num4) * pow(size, 3))
              + ((size - 1 - num4) * pow(size, 2))
              + (num4 * size) + num4] = 'x';
    }
    cout << test_win4D_8_4D(size, game, failures);

    return failures;
}

/* ============================================================ */

/* ============================================================ */


void check_failures(GameStringList *list, int size) {
    GameString *gs = list->getHead();
    while (gs != NULL) {
        cout << endl << gs->getMessage();
        placeOnGrid_4D(size, gs->getGame());
        gs = gs->getNext();
    }
    return;
}

/* ============================================================ */

/* ============================================================ */


string test_win1D_col_4D(int size, int row, int level, int cube,
                         string game, GameStringList *failures) {
    ostringstream oss;
    if (win1D_col_4D(size, row, level, cube, game)) {
        oss << "  PASSED: win1D_col_4D; row(" << row
            << ") level(" << level << ") cube(" << cube
            << ")\n";
    } else {
        oss << "FAIL: win1D_col_4D; row(" << row
            << ") level(" << level << ") cube(" << cube
            << ")\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}
string test_win1D_row_4D(int size, int column, int level, int cube,
                         string game, GameStringList *failures) {
    ostringstream oss;
    if (win1D_row_4D(size, column, level, cube, game)) {
        oss << "  PASSED: win1D_row_4D; col(" << column
            << ") level(" << level << ") cube(" << cube
            << ")\n";
    } else {
        oss << "FAIL: win1D_row_4D; col(" << column
            << ") level(" << level << ") cube(" << cube
            << ")\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}
string test_win1D_lev_4D(int size, int column, int row, int cube,
                         string game, GameStringList *failures) {
    ostringstream oss;
    if (win1D_lev_4D(size, column, row, cube, game)) {
        oss << "  PASSED: win1D_lev_4D; col(" << column
            << ") row(" << row << ") cube(" << cube
            << ")\n";
    } else {
        oss << "FAIL: win1D_lev_4D; col(" << column
            << ") row(" << row << ") cube(" << cube
            << ")\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}
string test_win1D_cub_4D(int size, int column, int row, int level,
                         string game, GameStringList *failures) {
    ostringstream oss;
    if (win1D_cub_4D(size, column, row, level, game)) {
        oss << "  PASSED: win1D_cub_4D; col(" << column
            << ") row(" << row << ") level(" << level
            << ")\n";
    } else {
        oss << "FAIL: win1D_cub_4D; col(" << column
            << ") row(" << row << ") level(" << level
            << ")\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}

/* ============================================================ */

/* ============================================================ */


string test_win2D_ColRow_1_4D(int size, int level, int cube,
                         string game, GameStringList *failures) {
    ostringstream oss;
    if (win2D_ColRow_1_4D(size, level, cube, game)) {
        oss << "  PASSED: win2D_ColRow_1_4D; level(" << level
            << ") cube(" << cube << ")\n";
    } else {
        oss << "FAIL: win2D_ColRow_1_4D; level(" << level
            << ") cube(" << cube << ")\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}
string test_win2D_ColRow_2_4D(int size, int level, int cube,
                         string game, GameStringList *failures) {
    ostringstream oss;
    if (win2D_ColRow_2_4D(size, level, cube, game)) {
        oss << "  PASSED: win2D_ColRow_2_4D; level(" << level
            << ") cube(" << cube << ")\n";
    } else {
        oss << "FAIL: win2D_ColRow_2_4D; level(" << level
            << ") cube(" << cube << ")\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}
string test_win2D_ColLev_1_4D(int size, int row, int cube,
                         string game, GameStringList *failures) {
    ostringstream oss;
    if (win2D_ColLev_1_4D(size, row, cube, game)) {
        oss << "  PASSED: win2D_ColLev_1_4D; row(" << row
            << ") cube(" << cube << ")\n";
    } else {
        oss << "FAIL: win2D_ColLev_1_4D; row(" << row
            << ") cube(" << cube << ")\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}
string test_win2D_ColLev_2_4D(int size, int row, int cube,
                         string game, GameStringList *failures) {
    ostringstream oss;
    if (win2D_ColLev_2_4D(size, row, cube, game)) {
        oss << "  PASSED: win2D_ColLev_2_4D; row(" << row
            << ") cube(" << cube << ")\n";
    } else {
        oss << "FAIL: win2D_ColLev_2_4D; row(" << row
            << ") cube(" << cube << ")\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}
string test_win2D_ColCub_1_4D(int size, int row, int level,
                         string game, GameStringList *failures) {
    ostringstream oss;
    if (win2D_ColCub_1_4D(size, row, level, game)) {
        oss << "  PASSED: win2D_ColCub_1_4D; row(" << row
            << ") level(" << level << ")\n";
    } else {
        oss << "FAIL: win2D_ColCub_1_4D; row(" << row
            << ") level(" << level << ")\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}
string test_win2D_ColCub_2_4D(int size, int row, int level,
                         string game, GameStringList *failures) {
    ostringstream oss;
    if (win2D_ColCub_2_4D(size, row, level, game)) {
        oss << "  PASSED: win2D_ColCub_2_4D; row(" << row
            << ") level(" << level << ")\n";
    } else {
        oss << "FAIL: win2D_ColCub_2_4D; row(" << row
            << ") level(" << level << ")\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}
string test_win2D_RowLev_1_4D(int size, int column, int cube,
                         string game, GameStringList *failures) {
    ostringstream oss;
    if (win2D_RowLev_1_4D(size, column, cube, game)) {
        oss << "  PASSED: win2D_RowLev_1_4D; col(" << column
            << ") cube(" << cube << ")\n";
    } else {
        oss << "FAIL: win2D_RowLev_1_4D; col(" << column
            << ") cube(" << cube << ")\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}
string test_win2D_RowLev_2_4D(int size, int column, int cube,
                         string game, GameStringList *failures) {
    ostringstream oss;
    if (win2D_RowLev_2_4D(size, column, cube, game)) {
        oss << "  PASSED: win2D_RowLev_2_4D; col(" << column
            << ") cube(" << cube << ")\n";
    } else {
        oss << "FAIL: win2D_RowLev_2_4D; col(" << column
            << ") cube(" << cube << ")\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}
string test_win2D_RowCub_1_4D(int size, int column, int level,
                         string game, GameStringList *failures) {
    ostringstream oss;
    if (win2D_RowCub_1_4D(size, column, level, game)) {
        oss << "  PASSED: win2D_RowCub_1_4D; col(" << column
            << ") level(" << level << ")\n";
    } else {
        oss << "FAIL: win2D_RowCub_1_4D; col(" << column
            << ") level(" << level << ")\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}
string test_win2D_RowCub_2_4D(int size, int column, int level,
                         string game, GameStringList *failures) {
    ostringstream oss;
    if (win2D_RowCub_2_4D(size, column, level, game)) {
        oss << "  PASSED: win2D_RowCub_2_4D; col(" << column
            << ") level(" << level << ")\n";
    } else {
        oss << "FAIL: win2D_RowCub_2_4D; col(" << column
            << ") level(" << level << ")\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}
string test_win2D_LevCub_1_4D(int size, int column, int row,
                         string game, GameStringList *failures) {
    ostringstream oss;
    if (win2D_LevCub_1_4D(size, column, row, game)) {
        oss << "  PASSED: win2D_LevCub_1_4D; col(" << column
            << ") row(" << row << ")\n";
    } else {
        oss << "FAIL: win2D_LevCub_1_4D; col(" << column
            << ") row(" << row << ")\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}
string test_win2D_LevCub_2_4D(int size, int column, int row,
                         string game, GameStringList *failures) {
    ostringstream oss;
    if (win2D_LevCub_2_4D(size, column, row, game)) {
        oss << "  PASSED: win2D_LevCub_2_4D; col(" << column
            << ") row(" << row << ")\n";
    } else {
        oss << "FAIL: win2D_LevCub_2_4D; col(" << column
            << ") row(" << row << ")\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}

/* ============================================================ */

/* ============================================================ */

string test_win3D_ColRowLev_1_4D(int size, int cube, string game,
                                  GameStringList *failures) {
    ostringstream oss;
    if (win3D_ColRowLev_1_4D(size, cube, game)) {
        oss << "  PASSED: win3D_ColRowLev_1_4D; cube("
            << cube << ")\n";
    } else {
        oss << "FAIL: win3D_ColRowLev_1_4D; cube("
            << cube << ")\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}
string test_win3D_ColRowLev_2_4D(int size, int cube, string game,
                                  GameStringList *failures) {
    ostringstream oss;
    if (win3D_ColRowLev_2_4D(size, cube, game)) {
        oss << "  PASSED: win3D_ColRowLev_2_4D; cube("
            << cube << ")\n";
    } else {
        oss << "FAIL: win3D_ColRowLev_2_4D; cube("
            << cube << ")\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}
string test_win3D_ColRowLev_3_4D(int size, int cube, string game,
                                  GameStringList *failures) {
    ostringstream oss;
    if (win3D_ColRowLev_3_4D(size, cube, game)) {
        oss << "  PASSED: win3D_ColRowLev_3_4D; cube("
            << cube << ")\n";
    } else {
        oss << "FAIL: win3D_ColRowLev_3_4D; cube("
            << cube << ")\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}
string test_win3D_ColRowLev_4_4D(int size, int cube, string game,
                                  GameStringList *failures) {
    ostringstream oss;
    if (win3D_ColRowLev_4_4D(size, cube, game)) {
        oss << "  PASSED: win3D_ColRowLev_4_4D; cube("
            << cube << ")\n";
    } else {
        oss << "FAIL: win3D_ColRowLev_4_4D; cube("
            << cube << ")\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}
string test_win3D_ColRowCub_1_4D(int size, int level, string game,
                                  GameStringList *failures) {
    ostringstream oss;
    if (win3D_ColRowCub_1_4D(size, level, game)) {
        oss << "  PASSED: win3D_ColRowCub_1_4D; level("
            << level << ")\n";
    } else {
        oss << "FAIL: win3D_ColRowCub_1_4D; level("
            << level << ")\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}
string test_win3D_ColRowCub_2_4D(int size, int level, string game,
                                  GameStringList *failures) {
    ostringstream oss;
    if (win3D_ColRowCub_2_4D(size, level, game)) {
        oss << "  PASSED: win3D_ColRowCub_2_4D; level("
            << level << ")\n";
    } else {
        oss << "FAIL: win3D_ColRowCub_2_4D; level("
            << level << ")\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}
string test_win3D_ColRowCub_3_4D(int size, int level, string game,
                                  GameStringList *failures) {
    ostringstream oss;
    if (win3D_ColRowCub_3_4D(size, level, game)) {
        oss << "  PASSED: win3D_ColRowCub_3_4D; level("
            << level << ")\n";
    } else {
        oss << "FAIL: win3D_ColRowCub_3_4D; level("
            << level << ")\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}
string test_win3D_ColRowCub_4_4D(int size, int level, string game,
                                  GameStringList *failures) {
    ostringstream oss;
    if (win3D_ColRowCub_4_4D(size, level, game)) {
        oss << "  PASSED: win3D_ColRowCub_4_4D; level("
            << level << ")\n";
    } else {
        oss << "FAIL: win3D_ColRowCub_4_4D; level("
            << level << ")\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}
string test_win3D_ColLevCub_1_4D(int size, int row, string game,
                                  GameStringList *failures) {
    ostringstream oss;
    if (win3D_ColLevCub_1_4D(size, row, game)) {
        oss << "  PASSED: win3D_ColLevCub_1_4D; row("
            << row << ")\n";
    } else {
        oss << "FAIL: win3D_ColLevCub_1_4D; row("
            << row << ")\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}
string test_win3D_ColLevCub_2_4D(int size, int row, string game,
                                  GameStringList *failures) {
    ostringstream oss;
    if (win3D_ColLevCub_2_4D(size, row, game)) {
        oss << "  PASSED: win3D_ColLevCub_2_4D; row("
            << row << ")\n";
    } else {
        oss << "FAIL: win3D_ColLevCub_2_4D; row("
            << row << ")\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}
string test_win3D_ColLevCub_3_4D(int size, int row, string game,
                                  GameStringList *failures) {
    ostringstream oss;
    if (win3D_ColLevCub_3_4D(size, row, game)) {
        oss << "  PASSED: win3D_ColLevCub_3_4D; row("
            << row << ")\n";
    } else {
        oss << "FAIL: win3D_ColLevCub_3_4D; row("
            << row << ")\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}
string test_win3D_ColLevCub_4_4D(int size, int row, string game,
                                  GameStringList *failures) {
    ostringstream oss;
    if (win3D_ColLevCub_4_4D(size, row, game)) {
        oss << "  PASSED: win3D_ColLevCub_4_4D; row("
            << row << ")\n";
    } else {
        oss << "FAIL: win3D_ColLevCub_4_4D; row("
            << row << ")\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}
string test_win3D_RowLevCub_1_4D(int size, int column, string game,
                                  GameStringList *failures) {
    ostringstream oss;
    if (win3D_RowLevCub_1_4D(size, column, game)) {
        oss << "  PASSED: win3D_RowLevCub_1_4D; col("
            << column << ")\n";
    } else {
        oss << "FAIL: win3D_RowLevCub_1_4D; col("
            << column << ")\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}
string test_win3D_RowLevCub_2_4D(int size, int column, string game,
                                  GameStringList *failures) {
    ostringstream oss;
    if (win3D_RowLevCub_2_4D(size, column, game)) {
        oss << "  PASSED: win3D_RowLevCub_2_4D; col("
            << column << ")\n";
    } else {
        oss << "FAIL: win3D_RowLevCub_2_4D; col("
            << column << ")\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}
string test_win3D_RowLevCub_3_4D(int size, int column, string game,
                                  GameStringList *failures) {
    ostringstream oss;
    if (win3D_RowLevCub_3_4D(size, column, game)) {
        oss << "  PASSED: win3D_RowLevCub_3_4D; col("
            << column << ")\n";
    } else {
        oss << "FAIL: win3D_RowLevCub_3_4D; col("
            << column << ")\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}
string test_win3D_RowLevCub_4_4D(int size, int column, string game,
                                  GameStringList *failures) {
    ostringstream oss;
    if (win3D_RowLevCub_4_4D(size, column, game)) {
        oss << "  PASSED: win3D_RowLevCub_4_4D; col("
            << column << ")\n";
    } else {
        oss << "FAIL: win3D_RowLevCub_4_4D; col("
            << column << ")\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}

/* ============================================================ */

/* ============================================================ */

string test_win4D_1_4D(int size, string game,
                        GameStringList *failures) {
    ostringstream oss;
    if (win4D_1_4D(size, game)) {
        oss << "  PASSED: win4D_1_4D\n";
    } else {
        oss << "FAIL: win4D_1_4D\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}

string test_win4D_2_4D(int size, string game,
                        GameStringList *failures) {
    ostringstream oss;
    if (win4D_2_4D(size, game)) {
        oss << "  PASSED: win4D_2_4D\n";
    } else {
        oss << "FAIL: win4D_2_4D\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}

string test_win4D_3_4D(int size, string game,
                        GameStringList *failures) {
    ostringstream oss;
    if (win4D_3_4D(size, game)) {
        oss << "  PASSED: win4D_3_4D\n";
    } else {
        oss << "FAIL: win4D_3_4D\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}

string test_win4D_4_4D(int size, string game,
                        GameStringList *failures) {
    ostringstream oss;
    if (win4D_4_4D(size, game)) {
        oss << "  PASSED: win4D_4_4D\n";
    } else {
        oss << "FAIL: win4D_4_4D\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}

string test_win4D_5_4D(int size, string game,
                        GameStringList *failures) {
    ostringstream oss;
    if (win4D_5_4D(size, game)) {
        oss << "  PASSED: win4D_5_4D\n";
    } else {
        oss << "FAIL: win4D_5_4D\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}

string test_win4D_6_4D(int size, string game,
                        GameStringList *failures) {
    ostringstream oss;
    if (win4D_6_4D(size, game)) {
        oss << "  PASSED: win4D_6_4D\n";
    } else {
        oss << "FAIL: win4D_6_4D\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}

string test_win4D_7_4D(int size, string game,
                        GameStringList *failures) {
    ostringstream oss;
    if (win4D_7_4D(size, game)) {
        oss << "  PASSED: win4D_7_4D\n";
    } else {
        oss << "FAIL: win4D_7_4D\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}

string test_win4D_8_4D(int size, string game,
                        GameStringList *failures) {
    ostringstream oss;
    if (win4D_8_4D(size, game)) {
        oss << "  PASSED: win4D_8_4D\n";
    } else {
        oss << "FAIL: win4D_8_4D\n";
        addToGameStringList(failures, game);
        failures->getTail()->setMessage(oss.str());
    }
    return oss.str();
}

