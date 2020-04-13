// gamestatus.cpp

#include <iostream>
#include "gameStatus.h"
#include "winDetection.h"
#include "drawDetection.h"

using namespace std;

bool detectWin_3D(int size, string game) {
    // test the rows and columns for wins in each level
    // output coordinates look like (row, column, level)
    for (int num1 = 0; num1 < size; num1++) {
        for (int num2 = 0; num2 < size; num2++) {
            if (rowWin_3D(size, num1, num2, game)) {
                cout << "Win in row " << num1 << ", level "
                     << num2 << endl;
                return true;
            } else if (columnWin_3D(size, num1, num2, game)) {
                cout << "Win in column " << num1 << ", level "
                     << num2 << endl;
                return true;
            } else if (vertWin_3D(size, num1, num2, game)) {
                cout << "Win vertically in row " << num1
                     << ", column " << num2 << endl;
                return true;
            } else {
                continue;
            }
        }
        // test for diagonal wins on each level
        if (diagWin2D_l1_3D(size, num1, game)) {
            cout << "Win diagonally from (0,0," << num1 << ") to (" << size-1 << ","
                 << size-1 << "," << num1 << ")\n";
            return true;
        } else if (diagWin2D_l2_3D(size, num1, game)) {
            cout << "Win diagonally from (0," << size-1 << "," << num1 << ") to ("
                 << size-1 << ",0," << num1 << ")\n";
            return true;
        }
        // test the diagonals wins on each row
        else if (diagWin2D_r1_3D(size, num1, game)) {
            cout << "Win diagonally from (" << num1 << ",0,0) to (" << num1 << ","
                 << size-1 << "," << size-1 << ")\n";
            return true;
        } else if (diagWin2D_r2_3D(size, num1, game)) {
            cout << "Win diagonally from (" << num1 << ",0," << size-1 << ") to ("
                 << num1 << "," << size-1 << ",0)\n";
                 return true;
        }
        // test the horizontal diagonals for wins on each level
        else if (diagWin2D_c1_3D(size, num1, game)) {
            cout << "Win diagonally from (0," << num1 << ",0) to (" << size-1 << ","
                 << num1 << "," << size-1 << ")\n";
            return true;
        } else  if (diagWin2D_c2_3D(size, num1, game)) {
            cout << "Win diagonally from (0," << num1 << "," << size-1 << ") to ("
                 << size-1 << "," << num1 << ",0)\n";
            return true; 
        } else {
            continue;
        }
    }
    // test the 3D diagonals
    if (diagWin3D_1_3D(size, game)) {
        cout << "Win diagonally from (0,0,0) to (" << size-1 << "," << size-1 << ","
             << size-1 << ")\n";
        return true;
    } else if (diagWin3D_2_3D(size, game)) {
        cout << "Win diagonally from (0," << size-1 << ",0) to (" << size-1 << ",0,"
             << size-1 << ")\n";
        return true;
    } else if (diagWin3D_3_3D(size, game)) {
        cout << "Win diagonally from (" << size-1 << ",0,0) to (0," << size-1 << ","
             << size-1 << ")\n";
        return true;
    } else if (diagWin3D_4_3D(size, game)) {
        cout << "Win diagonally from (" << size-1 << "," << size-1 << ",0) to (0,0,"
             << size-1 << ")\n";
        return true;
    } else {
        return false;
    }
}

bool detectDraw_3D(int size, string game) {
    // test to see if a win is still possible in any row or column in each level
    for (int num1 = 0; num1 < size; num1++) {
        for (int num2 = 0; num2 < size; num2++) {
            if (rowPossible_3D(size, num1, num2, game)) {
                return false;
            } else if (columnPossible_3D(size, num1, num2, game)) {
                return false;
            } else if (vertPossible_3D(size, num1, num2, game)) {
                return false;
            } else {
                continue;
            }
        }
        // test the diagonals across each 2D space by level, row, and column
        if (diagPossible2D_l1_3D(size, num1, game)) {
            return false;
        } else if (diagPossible2D_l2_3D(size, num1, game)) {
            return false;
        } else if (diagPossible2D_r1_3D(size, num1, game)) {
            return false;
        } else if (diagPossible2D_r2_3D(size, num1, game)) {
            return false;
        } else if (diagPossible2D_c1_3D(size, num1, game)) {
            return false;
        } else if (diagPossible2D_c2_3D(size, num1, game)) {
            return false;
        } else continue;
    }
    // test the 3D diagonals for a possible win remaining
    if (diagPossible3D_1_3D(size, game)) {
        return false;
    } else if (diagPossible3D_2_3D(size, game)) {
        return false;
    } else if (diagPossible3D_3_3D(size, game)) {
        return false;
    } else if (diagPossible3D_4_3D(size, game)) {
        return false;
    } else {
        return true;
    }
}

string gameStatus_3D(int size, string game) {
    // Returns "Win"", "Draw", or "Unfinished" depending on if
    // a player has won in the previous move, or if it is still
    // possible for a player to win
    // First, test for Wins
    if (detectWin_3D(size, game)) {
        return "Win";
    }
    // If no one has won, check if the game is a draw
    else if (detectDraw_3D(size, game)) {
        return "Draw";
    } else {
        // If there is no win or draw, the game continues
        return "Unfinished";
    }
}
