// gamestatus.cpp

#include <iostream>
#include "gameStatus.h"
#include "winDetection.h"
#include "drawDetection.h"

using namespace std;

/*
string gameStatus_4D(int size, string game) {
    // return options are "Win"", "Draw", or "Unfinished"
    // First, test for Wins
    if (detectWin_4D(size, game)) {
        return "Win";
    } else if (detectDraw_4D(size, game)) {
        // If no one has won, check if the game is a draw
        return "Draw";
    } else {
        // If there is no win or draw, the game continues
        return "Unfinished";
    }
}
*/

bool detectWin_4D(int size, string game) {
    for (int num1 = 0; num1 < size; num1++) {
        for (int num2 = 0; num2 < size; num2++) {
            for (int num3 = 0; num3 < size; num3++) {
                // test for 1D Wins
                if (win1D(size, num1, num2, num3, game)) {
                    return true;
                } else {
                    continue;
                }
            }
            // test for 2D Wins
            if (win2D(size, num1, num2, game)) {
                return true;
            } else {
                continue;
            }
        }
        // test for 3D Wins
        if (win3D(size, num1, game)) {
            return true;
        } else {
            continue;
        }
    }
    // test for 4D Wins
    if (win4D(size, game)) {
        return true;
    } else {
        return false;
    }
}


bool win1D(int size, int num1, int num2, int num3, string game) {
    // row(num1), level(num2), cube(num3)
    if (win1D_col_4D(size, num1, num2, num3, game)) {
        cout << "Win across the column in cube "
             << num3 << ", level " << num2
             << ", row " << num1 << endl;
        return true;
    }
    // column(num1), level(num2), cube(num3)
    else if (win1D_row_4D(size, num1, num2, num3, game)) {
        cout << "Win across the row in cube "
             << num3 << ", level " << num2
             << ", column " << num1 << endl;
        return true;
    }
    // column(num1), row(num2), cube(num3)
    else if (win1D_lev_4D(size, num1, num2, num3, game)) {
        cout << "Win across the levels in cube "
             << num3 << ", row " << num2
             << ", column " << num1 << endl;
        return true;
    }
    // column(num1), row(num2), level(num3)
    else if (win1D_cub_4D(size, num1, num2, num3, game)) {
        cout << "Win across the cubes in level "
             << num3 << ", row " << num2
             << ", column " << num1 << endl;
        return true;
    } else {
        return false;
    }
}
bool win2D(int size, int num1, int num2, string game) {
    // level(num1), cube(num2)
    if (win2D_ColRow_1_4D(size, num1, num2, game)) {
        cout << "Win diagonally from (" << num2 << "," << num1
             << ",0,0) to (" << num2 << "," << num1 << ","
             << size-1 << "," << size-1 << ")\n";
        return true;
    } else if (win2D_ColRow_2_4D(size, num1, num2, game)) {
        cout << "Win diagonally from (" << num2 << "," << num1
             << ",0," << size-1 << ") to (" << num2 << ","
             << num1 << "," << size-1 << ",0)\n";
        return true;
    }
    // row(num1), cube(num2)
    else if (win2D_ColLev_1_4D(size, num1, num2, game)) {
        cout << "Win diagonally from (" << num2 << ",0,"
             << num1 << ",0) to (" << num2 << ","
             << size-1 << "," << num1 << "," << size-1 << ")\n";
        return true;
    } else if (win2D_ColLev_2_4D(size, num1, num2, game)) {
        cout << "Win diagonally from (" << num2 << ",0,"
             << num1 << "," << size-1 << ") to (" << num2
             << "," << size-1 << "," << num1 << ",0)\n";
        return true;
    }
    // row(num1), level(num2)
    else if (win2D_ColCub_1_4D(size, num1, num2, game)) {
        cout << "Win diagonally from (0," << num2 << ","
             << num1 << ",0) to (" << size-1 << ","<< num2
             << "," << num1 << "," << size-1 << ")\n";
        return true;
    } else  if (win2D_ColCub_2_4D(size, num1, num2, game)) {
        cout << "Win diagonally from (0," << num2 << ","
             << num1 << "," << size-1 << ") to ("<< size-1
             << "," << num2 << "," << num1 << ",0)\n";
        return true;
    }
    // column(num1), cube(num2)
    else if (win2D_RowLev_1_4D(size, num1, num2, game)) {
        cout << "Win diagonally from (" << num2 << ",0,0,"
             << num1 << ") to (" << num2 << "," << size-1
             << "," << size-1 << "," << num1 << ")\n";
        return true;
    } else if (win2D_RowLev_2_4D(size, num1, num2, game)) {
        cout << "Win diagonally from (" << num2 << ",0,"
             << size-1 << "," << num1 << ") to (" << num2
             << "," << size-1 << ",0," << num1 << ")\n";
        return true;
    }
    // column(num1), level(num2)
    else if (win2D_RowCub_1_4D(size, num1, num2, game)) {
        cout << "Win diagonally from (0," << num2 << ",0,"
             << num1 << ") to (" << size-1 << "," << num2
             << "," << size-1 << "," << num1 << ")\n";
        return true;
    } else if (win2D_RowCub_2_4D(size, num1, num2, game)) {
        cout << "Win diagonally from (0," << num2 << ","
             << size-1 << "," << num1 << ") to (" << size-1
             << "," << num2 << ",0," << num1 << ")\n";
        return true;
    }
    // column(num1), row(num2)
    else if (win2D_LevCub_1_4D(size, num1, num2, game)) {
        cout << "Win diagonally from (0,0," << num2 << ","
             << num1 << ") to (" << size-1 << "," << size-1
             << "," << num2 << "," << num1 << ")\n";
        return true;
    } else if (win2D_LevCub_2_4D(size, num1, num2, game)) {
        cout << "Win diagonally from (0," << size-1 << ","
             << num2 << "," << num1 << ") to (" << size-1
             << ",0," << num2 << "," << num1 << ")\n";
        return true;
    } else {
        return false;
    }
}

bool win3D(int size, int num1, string game) {
    // cube(num1)
    if (win3D_ColRowLev_1_4D(size, num1, game)) {
        cout << "Win diagonally from (" << num1 << ",0,0,0) to ("
             << num1 << "," << size-1 << "," << size-1 << "," << size-1
             << ")\n";
        return true;
    } else if (win3D_ColRowLev_2_4D(size, num1, game)) {
        cout << "Win diagonally from (" << num1 << ",0,0," << size-1
             << ") to (" << num1 << "," << size-1 << "," << size-1
             << ",0)\n";
        return true;
    } else if (win3D_ColRowLev_3_4D(size, num1, game)) {
        cout << "Win diagonally from (" << num1 << ",0," << size-1
             << ",0) to (" << num1 << "," << size-1 << ",0,"
             << size-1 << ")\n";
        return true;
    } else if (win3D_ColRowLev_4_4D(size, num1, game)) {
        cout << "Win diagonally from (" << num1 << ",0," << size-1 << ","
             << size-1 << ") to (" << num1 << "," << size-1 << "0,0)\n";
        return true;
    }
    // level(num1)
    else if (win3D_ColRowCub_1_4D(size, num1, game)) {
        cout << "Win diagonally from (0," << num1 << ",0,0) to ("
             << size-1 << "," << num1 << "," << size-1 << "," << size-1
             << ")\n";
        return true;
    } else if (win3D_ColRowCub_2_4D(size, num1, game)) {
        cout << "Win diagonally from (0," << num1 << ",0," << size-1
             << ") to (" << size-1 << "," << num1 << "," << size-1
             << ",0)\n";
        return true;
    } else if (win3D_ColRowCub_3_4D(size, num1, game)) {
        cout << "Win diagonally from (0," << num1 << "," << size-1
             << ",0) to (" << size-1 << "," << num1 << ",0,"
             << size-1 << ")\n";
        return true;
    } else if (win3D_ColRowCub_4_4D(size, num1, game)) {
        cout << "Win diagonally from (0," << num1 << "," << size-1 << ","
             << size-1 << ") to (" << size-1 << "," << num1 << "0,0)\n";
        return true;
    }
    // row(num1)
    else if (win3D_ColLevCub_1_4D(size, num1, game)) {
        cout << "Win diagonally from (0,0," << num1 << ",0) to ("
             << size-1 << "," << size-1 << "," << num1 << "," << size-1
             << ")\n";
        return true;
    } else if (win3D_ColLevCub_2_4D(size, num1, game)) {
        cout << "Win diagonally from (0,0," << num1 << "," << size-1
             << ") to (" << size-1 << "," << size-1 << "," << num1
             << ",0)\n";
        return true;
    } else if (win3D_ColLevCub_3_4D(size, num1, game)) {
        cout << "Win diagonally from (0," << size-1 << "," << num1
             << ",0) to (" << size-1 << ",0," << num1 << ","
             << size-1 << ")\n";
        return true;
    } else if (win3D_ColLevCub_4_4D(size, num1, game)) {
        cout << "Win diagonally from (0," << size-1 << "," << num1 << ","
             << size-1 << ") to (" << size-1 << ",0," << num1 << ",0)\n";
        return true;
    }
    // column(num1)
    else if (win3D_RowLevCub_1_4D(size, num1, game)) {
        cout << "Win diagonally from (0,0,0," << num1 << ") to ("
             << size-1 << "," << size-1 << "," << size-1 << "," << num1
             << ")\n";
        return true;
    } else if (win3D_RowLevCub_2_4D(size, num1, game)) {
        cout << "Win diagonally from (0,0," << size-1 << "," << num1
             << ") to (" << size-1 << "," << size-1 << ",0," << num1
             << ")\n";
        return true;
    } else if (win3D_RowLevCub_3_4D(size, num1, game)) {
        cout << "Win diagonally from (0," << size-1 << ",0," << num1
             << ") to (" << size-1 << ",0," << size-1 << ","
             << num1 << ")\n";
        return true;
    } else if (win3D_RowLevCub_4_4D(size, num1, game)) {
        cout << "Win diagonally from (0," << size-1 << "," << size-1 << ","
             << num1 << ") to (" << size-1 << ",0,0," << num1 << ")\n";
        return true;
    } else {
        return false;
    }
}

bool win4D(int size, string game) {
    if (win4D_1_4D(size, game)) {
        cout << "Win diagonally from (0,0,0,0) to (" << size-1 << ","
             << size-1 << "," << size-1 << "," << size-1 << ")\n";
        return true;
    } else if (win4D_2_4D(size, game)) {
        cout << "Win diagonally from (0,0,0," << size-1 << ") to ("
             << size-1 << "," << size-1 << "," << size-1 << ",0)\n";
        return true;
    } else if (win4D_3_4D(size, game)) {
        cout << "Win diagonally from (0,0," << size-1 << ",0) to ("
             << size-1 << "," << size-1 << ",0," << size-1 << ")\n";
        return true;
    } else if (win4D_4_4D(size, game)) {
        cout << "Win diagonally from (0," << size-1 << ",0,0) to ("
             << size-1 << ",0," << size-1 << "," << size-1 << ")\n";
        return true;
    } else if (win4D_5_4D(size, game)) {
        cout << "Win diagonally from (0," << size-1 << "," << size-1
             << "," << size-1 << ") to (" << size-1 << ",0,0,0)\n";
        return true;
    } else if (win4D_6_4D(size, game)) {
        cout << "Win diagonally from (0," << size-1 << "," << size-1
             << ",0) to (" << size-1 << ",0,0," << size-1 << ")\n";
        return true;
    } else if (win4D_7_4D(size, game)) {
        cout << "Win diagonally from (0," << size-1 << ",0," << size-1
             << ") to (" << size-1 << ",0," << size-1 << ",0)\n";
        return true;
    } else if (win4D_8_4D(size, game)) {
        cout << "Win diagonally from (0,0," << size-1 << "," << size-1
             << ") to (" << size-1 << "," << size-1 << ",0,0)\n";
        return true;
    }
    return false;
}


bool detectDraw_4D(int size, string game) {
    // test to see if a win is still possible in any row or column
    // in each level
    for (int num1 = 0; num1 < size; num1++) {
        for (int num2 = 0; num2 < size; num2++) {
            for (int num3 = 0; num3 < size; num3++) {
                // test for possible 1D wins
                if (possible1D(size, num1, num2, num3, game)) {
                    return true;
                } else {
                    continue;
                }
            }
            // test for possible 2D wins
            if (possible2D(size, num1, num2, game)) {
                return true;
            } else {
                continue;
            }
        }
        // test for possible 3D wins
        if (possible3D(size, num1, game)) {
            return true;
        } else {
            continue;
        }
    }
    // test for possible 4D wins
    if (possible4D(size, game)) {
        return true;
    } else {
        return false;
    }
}


/* TODO
bool possible1D(int size, int num1, int num2, int num3, string game);
bool possible2D(int size, int num1, int num2, string game);
bool possible3D(int size, int num1, string game);
bool possible4D(int size, string game);
 */
