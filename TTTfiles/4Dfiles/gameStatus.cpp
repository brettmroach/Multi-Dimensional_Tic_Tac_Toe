// gamestatus.cpp

#include <iostream>
#include "gameStatus.h"
#include "winDetection.h"
#include "drawDetection.h"

using namespace std;

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

// TODO
bool detectWin_4D(int size, string game) {
    for (int num1 = 0; num1 < size; num1++) {
        for (int num2 = 0; num2 < size; num2++) {
            for (int num3 = 0; num3 < size; num3++) {
                // row(num1), level(num2), cube(num3)
                if (win1D_col_4D(size, num1, num2, num3, game)) {
                    cout << "Win across the column in cube "
                        << num3 << ", level " << num2
                        << ", row " << num1 << endl;
                    return true;
                // column(num1), level(num2), cube(num3)
                } else if (win1D_row_4D(size, num1, num2, num3, game)) {
                    cout << "Win across the row in cube "
                        << num3 << ", level " << num2
                        << ", column " << num1 << endl;
                    return true;
                // column(num1), row(num2), cube(num3)
                } else if (win1D_lev_4D(size, num1, num2, num3, game)) {
                    cout << "Win across the levels in cube "
                        << num3 << ", row " << num2
                        << ", column " << num1 << endl;
                    return true;
                // column(num1), row(num2), level(num3)
                } else if (win1D_cub_4D(size, num1, num2, num3, game)) {
                    cout << "Win across the cubes in level "
                        << num3 << ", row " << num2
                        << ", column " << num1 << endl;
                    return true;
                } else {
                    continue;
                }
            }
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
            // column(num1), cube(num2)
            } else if (win2D_RowLev_1_4D(size, num1, num2, game)) {
                cout << "Win diagonally from (" << num2 << ",0,0,"
                    << num1 << ") to (" << num2 << "," << size-1
                    << "," << size-1 << "," << num1 << ")\n";
                return true;
            } else if (win2D_RowLev_2_4D(size, num1, num2, game)) {
                cout << "Win diagonally from (" << num2 << ",0,"
                    << size-1 << "," << num1 << ") to (" << num2
                    << "," << size-1 << ",0," << num1 << ")\n";
                return true;
            // column(num1), level(num2)
            } else if (win2D_RowCub_1_4D(size, num1, num2, game)) {
                cout << "Win diagonally from (0," << num2 << ",0,"
                    << num1 << ") to (" << size-1 << "," << num2
                    << "," << size-1 << "," << num1 << ")\n";
                return true;
            } else if (win2D_RowCub_2_4D(size, num1, num2, game)) {
                cout << "Win diagonally from (0," << num2 << ","
                    << size-1 << "," << num1 << ") to (" << size-1
                    << "," << num2 << ",0," << num1 << ")\n";
                return true;
            // column(num1), row(num2)
            } else if (win2D_LevCub_1_4D(size, num1, num2, game)) {
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
                continue;
            }
        }
    }
    // test the 3D diagonals
    if (diagWin3D_1(size, game)) {
        cout << "Win diagonally from (0,0,0) to (" << size-1 << "," << size-1 << ","
             << size-1 << ")\n";
        return true;
    } else if (diagWin3D_2(size, game)) {
        cout << "Win diagonally from (0," << size-1 << ",0) to (" << size-1 << ",0,"
             << size-1 << ")\n";
        return true;
    } else if (diagWin3D_3(size, game)) {
        cout << "Win diagonally from (" << size-1 << ",0,0) to (0," << size-1 << ","
             << size-1 << ")\n";
        return true;
    } else if (diagWin3D_4(size, game)) {
        cout << "Win diagonally from (" << size-1 << "," << size-1 << ",0) to (0,0,"
             << size-1 << ")\n";
        return true;
    } else {
        return false;
    }
}

// TODO
bool detectDraw_4D(int size, string game) {
    // test to see if a win is still possible in any row or column in each level
    for (int num1 = 0; num1 < size; num1++) {
        for (int num2 = 0; num2 < size; num2++) {
            if (rowPossible(size, num1, num2, game)) {
                return false;
            } else if (columnPossible(size, num1, num2, game)) {
                return false;
            } else if (vertPossible(size, num1, num2, game)) {
                return false;
            } else {
                continue;
            }
        }
        // test the diagonals across each 2D space by level, row, and column
        if (lDiagPossible_1(size, num1, game)) {
            return false;
        } else if (lDiagPossible_2(size, num1, game)) {
            return false;
        } else if (rDiagPossible_1(size, num1, game)) {
            return false;
        } else if (rDiagPossible_2(size, num1, game)) {
            return false;
        } else if (cDiagPossible_1(size, num1, game)) {
            return false;
        } else if (cDiagPossible_2(size, num1, game)) {
            return false;
        } else continue;
    }
    // test the 3D diagonals for a possible win remaining
    if (diagPossible3D_1(size, game)) {
        return false;
    } else if (diagPossible3D_2(size, game)) {
        return false;
    } else if (diagPossible3D_3(size, game)) {
        return false;
    } else if (diagPossible3D_4(size, game)) {
        return false;
    } else {
        return true;
    }
}

