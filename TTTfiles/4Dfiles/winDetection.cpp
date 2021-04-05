// winDetection.cpp
// detectWin helpers - identify a win anywhere in the game

#include <string>
#include <cmath>
using std::string;

bool win1D_col_4D(int size, int row, int level, int cube, string game) {
    bool result = true;
    int placement = (cube * pow(size, 3)) + (level * pow(size, 2)) + (row * size);
    for (int column = 0; column < size; column++) {
        if (game[placement + column] == ' ') {
            result = false;
            break;
        } else if (game[placement + column] != game[placement]) {
            result = false;
            break;
        } else {
            continue;
        }
    }
    return result;
}
bool win1D_row_4D(int size, int column, int level, int cube, string game) {
    bool result = true;
    int placement = (cube * pow(size, 3)) + (level * pow(size, 2)) + column;
    for (int row = 0; row < size; row++) {
        if (game[placement + (row * size)] == ' ') {
            result = false;
            break;
        } else if (game[placement + (row * size)] != game[placement]) {
            result = false;
            break;
        } else {
            continue;
        }
    }
    return result;
}
bool win1D_lev_4D(int size, int column, int row, int cube, string game) {
    bool result = true;
    int placement = (cube * pow(size, 3)) + (row * size) + column;
    for (int level = 0; level < size; level++) {
        if (game[placement + (level * pow(size, 2))] == ' ') {
            result = false;
            break;
        } else if (game[placement + (level * pow(size, 2))] != game[placement]) {
            result = false;
            break;
        } else {
            continue;
        }
    }
    return result;
}
bool win1D_cub_4D(int size, int column, int row, int level, std::string game) {
    bool result = true;
    int placement = (level * pow(size, 2)) + (row * size) + column;
    for (int cube = 0; cube < size; cube++) {
        if (game[placement + (cube * pow(size, 3))] == ' ') {
            result = false;
            break;
        } else if (game[placement + (cube * pow(size, 3))] != game[placement]) {
            result = false;
            break;
        } else {
            continue;
        }
    }
    return result;
}
/* The 2D vector spaces anazlyzed in the following
 * functions are defined as follows:
 * ColRow = <column, row>; (const level, cube)
 * ColLev = <column, level>; (const row, cube)
 * ColCub = <column, cube>; (const row, level)
 * RowLev = <row, level>; (const column, cube)
 * RowCub = <row, cube>; (const column, level)
 * LevCub = <level, cube>; (const column, row)
 */
bool win2D_ColRow_1_4D(int size, int level, int cube, string game) {
    bool result = true;
    int placement = (cube * pow(size, 3)) + (level * pow(size, 2));
    int column;
    for (int row = 0; row < size; row++) { 
        column = row;
        if (game[placement + (row * size) + column] == ' ') {
            result = false;
            break;
        } else if (game[placement + (row * size) + column] != game[placement]) {
            result = false;
            break;
        } else {
            continue;
        }
    }
    return result;
}
bool win2D_ColRow_2_4D(int size, int level, int cube, string game) {
    bool result = true;
    int placement = (cube * pow(size, 3)) + (level * pow(size, 2));
    int column;
    for (int row = 0; row < size; row++) {
        column = size - 1 - row;
        if (game[placement + (row * size) + column] == ' ') {
            result = false;
            break;
        } else if (game[placement + (row * size) + column]
                    != game[placement + size - 1]) {
            result = false;
            break;
        } else {
            continue;
        }
    }
    return result;
}
bool win2D_ColLev_1_4D(int size, int row, int cube, string game) {
    bool result = true;
    int placement = (cube * pow(size, 3)) + (row * size);
    int column;
    for (int level = 0; level < size; level++) {
        column = level;
        if (game[placement + (level * pow(size, 2)) + column] == ' ') {
            result = false;
            break;
        } else if (game[placement + (level * pow(size, 2)) + column]
                    != game[placement]) {
            result = false;
            break;
        } else {
            continue;
        }
    }
    return result;
}
bool win2D_ColLev_2_4D(int size, int row, int cube, string game) {
    bool result = true;
    int placement = (cube * pow(size, 3)) + (row * size);
    int column;
    for (int level = 0; level < size; level++) {
        column = size - 1 - level;
        if (game[placement + (level * pow(size, 2)) + column] == ' ') {
            result = false;
            break;
        } else if (game[placement + (level * pow(size, 2)) + column]
                    != game[placement + size - 1]) {
            result = false;
            break;
        } else {
            continue;
        }
    }
    return result;
}
bool win2D_ColCub_1_4D(int size, int row, int level, string game) {
    bool result = true;
    int placement = (level * pow(size, 2)) + (row * size);
    int column;
    for (int cube = 0; cube < size; cube++) {
        column = cube;
        if (game[placement + (cube * pow(size, 3)) + column] == ' ') {
            result = false;
            break;
        } else if (game[placement + (cube * pow(size, 3)) + column]
                    != game[placement]) {
            result = false;
            break;
        } else {
            continue;
        }
    }
    return result;
}
bool win2D_ColCub_2_4D(int size, int row, int level, string game) {
    bool result = true;
    int placement = (level * pow(size, 2)) + (row * size);
    int column;
    for (int cube = 0; cube < size; cube++) {
        column = size - 1 - cube;
        if (game[placement + (cube * pow(size, 3)) + column] == ' ') {
            result = false;
            break;
        } else if (game[placement + (cube * pow(size, 3)) + column]
                    != game[placement + size - 1]) {
            result = false;
            break;
        } else {
            continue;
        }
    }
    return result;
}
bool win2D_RowLev_1_4D(int size, int column, int cube, string game) {
    bool result = true;
    int placement = (cube * pow(size, 3)) + column;
    int row;
    for (int level = 0; level < size; level++) {
        row = level;
        if (game[placement + (level * pow(size, 2)) + (row * size)] == ' ') {
            result = false;
            break;
        } else if (game[placement + (level * pow(size, 2)) + (row * size)]
                    != game[placement]) {
            result = false;
            break;
        } else {
            continue;
        }
    }
    return result;
}
bool win2D_RowLev_2_4D(int size, int column, int cube, string game) {
    bool result = true;
    int placement = (cube * pow(size, 3)) + column;
    int row;
    for (int level = 0; level < size; level++) {
        row = size - 1 - level;
        if (game[placement + (level * pow(size, 2)) + (row * size)] == ' ') {
            result = false;
            break;
        } else if (game[placement + (level * pow(size, 2)) + (row * size)]
                    != game[placement + ((size - 1) * size)]) {
            result = false;
            break;
        } else {
            continue;
        }
    }
    return result;
}
bool win2D_RowCub_1_4D(int size, int column, int level, string game) {
    bool result = true;
    int placement = (level * pow(size, 2)) + column;
    int row;
    for (int cube = 0; cube < size; cube++) {
        row = cube;
        if (game[placement + (cube * pow(size, 3)) + (row * size)] == ' ') {
            result = false;
            break;
        } else if (game[placement + (cube * pow(size, 3)) + (row * size)]
                    != game[placement]) {
            result = false;
            break;
        } else {
            continue;
        }
    }
    return result;
}
bool win2D_RowCub_2_4D(int size, int column, int level, string game) {
    bool result = true;
    int placement = (level * pow(size, 2)) + column;
    int row;
    for (int cube = 0; cube < size; cube++) {
        row = size - 1 - cube;
        if (game[placement + (cube * pow(size, 3)) + (row * size)] == ' ') {
            result = false;
            break;
        } else if (game[placement + (cube * pow(size, 3)) + (row * size)]
                    != game[placement + ((size - 1) * size)]) {
            result = false;
            break;
        } else {
            continue;
        }
    }
    return result;
}
bool win2D_LevCub_1_4D(int size, int column, int row, string game) {
    bool result = true;
    int placement = (row * size) + column;
    int level;
    for (int cube = 0; cube < size; cube++) {
        level = cube;
        if (game[placement + (cube * pow(size, 3)) + (level * pow(size, 2))]
             == ' ') {
            result = false;
            break;    
        } else if (game[placement + (cube * pow(size, 3))
                         + (level * pow(size, 2))] != game[placement]) {
            result = false;
            break;
        } else {
            continue;
        }
    }
    return result;
}
bool win2D_LevCub_2_4D(int size, int column, int row, string game) {
    bool result = true;
    int placement = (row * size) + column;
    int level;
    for (int cube = 0; cube < size; cube++) {
        level = size - 1 - cube;
        if (game[placement + (cube * pow(size, 3)) + (level * pow(size, 2))]
             == ' ') {
            result = false;
            break;    
        } else if (game[placement + (cube * pow(size, 3)) + (level * pow(size, 2))]
                    != game[placement + ((size - 1) * pow(size, 2))]) {
            result = false;
            break;
        } else {
            continue;
        }
    }
    return result;
}

/* The 3D vector spaces analyzed in the following
 * functions are defined as follows:
 * ColRowLev = <column, row, level>; (const cube)
 * ColRowCub = <column, row, cube>; (const level)
 * ColLevCub = <column, level, cube>; (const row)
 * RowLevCub = <row, level, cube>; (const column)
 */

bool win3D_ColRowLev_1_4D(int size, int cube, string game) {
    bool result = true;
    int column, row, level, placement;
    for (int count = 0; count < size; count++) {
        column = count;
        row = count;
        level = count;
        placement = (cube * pow(size, 3)) + (level * pow(size, 2))
                      + (row * size) + column;
        if (game[placement] == ' ') {
            result = false;
            break;
        } else if (game[placement] != game[cube * pow(size, 3)]) {
            result = false;
            break;
        }
    }
    return result;
}
bool win3D_ColRowLev_2_4D(int size, int cube, string game) {
    bool result = true;
    int column, row, level, placement;
    for (int count = 0; count < size; count++) {
        column = size - 1 - count;
        row = count;
        level = count;
        placement = (cube * pow(size, 3)) + (level * pow(size, 2))
                      + (row * size) + column;
        if (game[placement] == ' ') {
            result = false;
            break;
        } else if (game[placement]
                    != game[(cube * pow(size, 3)) + (size - 1)]) {
            result = false;
            break;
        }
    }
    return result;
}
bool win3D_ColRowLev_3_4D(int size, int cube, string game) {
    bool result = true;
    int column, row, level, placement;
    for (int count = 0; count < size; count++) {
        column = count;
        row = size - 1 - count;
        level = count;
        placement = (cube * pow(size, 3)) + (level * pow(size, 2))
                      + (row * size) + column;
        if (game[placement] == ' ') {
            result = false;
            break;
        } else if (game[placement]
                    != game[(cube * pow(size, 3))
                             + ((size - 1) * size)]) {
            result = false;
            break;
        }
    }
    return result;
}
bool win3D_ColRowLev_4_4D(int size, int cube, string game) {
    bool result = true;
    int column, row, level, placement;
    for (int count = 0; count < size; count++) {
        column = count;
        row = count;
        level = size - 1 - count;
        placement = (cube * pow(size, 3)) + (level * pow(size, 2))
                     + (row * size) + column;
        if (game[placement] == ' ') {
            result = false;
            break;
        } else if (game[placement]
                    != game[(cube * pow(size, 3))
                             + ((size - 1) * pow(size, 2))]) {
            result = false;
            break;
        }
    }
    return result;
}
bool win3D_ColRowCub_1_4D(int size, int level, string game) {
    bool result = true;
    int column, row, cube, placement;
    for (int count = 0; count < size; count++) {
        column = count;
        row = count;
        cube = count;
        placement = (cube * pow(size, 3)) + (level * pow(size, 2))
                      + (row * size) + column;
        if (game[placement] == ' ') {
            result = false;
            break;
        } else if (game[placement] != game[level * pow(size, 2)]) {
            result = false;
            break;
        }
    }
    return result;
}
bool win3D_ColRowCub_2_4D(int size, int level, string game) {
    bool result = true;
    int column, row, cube, placement;
    for (int count = 0; count < size; count++) {
        column = size - 1 - count;
        row = count;
        cube = count;
        placement = (cube * pow(size, 3)) + (level * pow(size, 2))
                      + (row * size) + column;
        if (game[placement] == ' ') {
            result = false;
            break;
        } else if (game[placement]
                    != game[(level * pow(size, 2)) + (size - 1)]) {
            result = false;
            break;
        }
    }
    return result;
}
bool win3D_ColRowCub_3_4D(int size, int level, string game) {
    bool result = true;
    int column, row, cube, placement;
    for (int count = 0; count < size; count++) {
        column = count;
        row = size - 1 - count;
        cube = count;
        placement = (cube * pow(size, 3)) + (level * pow(size, 2))
                      + (row * size) + column;
        if (game[placement] == ' ') {
            result = false;
            break;
        } else if (game[placement]
                    != game[(level * pow(size, 2))
                             + ((size - 1) * size)]) {
            result = false;
            break;
        }
    }
    return result;
}
bool win3D_ColRowCub_4_4D(int size, int level, string game) {
    bool result = true;
    int column, row, cube, placement;
    for (int count = 0; count < size; count++) {
        column = count;
        row = count;
        cube = size - 1 - count;
        placement = (cube * pow(size, 3)) + (level * pow(size, 2))
                     + (row * size) + column;
        if (game[placement] == ' ') {
            result = false;
            break;
        } else if (game[placement]
                    != game[((size - 1) * pow(size, 3))
                             + (level * pow(size, 2))]) {
            result = false;
            break;
        }
    }
    return result;
}
bool win3D_ColLevCub_1_4D(int size, int row, string game) {
    bool result = true;
    int column, level, cube, placement;
    for (int count = 0; count < size; count++) {
        column = count;
        level = count;
        cube = count;
        placement = (cube * pow(size, 3)) + (level * pow(size, 2))
                      + (row * size) + column;
        if (game[placement] == ' ') {
            result = false;
            break;
        } else if (game[placement] != game[row * size]) {
            result = false;
            break;
        }
    }
    return result;
}
bool win3D_ColLevCub_2_4D(int size, int row, string game) {
    bool result = true;
    int column, level, cube, placement;
    for (int count = 0; count < size; count++) {
        column = size - 1 - count;
        level = count;
        cube = count;
        placement = (cube * pow(size, 3)) + (level * pow(size, 2))
                      + (row * size) + column;
        if (game[placement] == ' ') {
            result = false;
            break;
        } else if (game[placement]
                    != game[(row * size) + (size - 1)]) {
            result = false;
            break;
        }
    }
    return result;
}
bool win3D_ColLevCub_3_4D(int size, int row, string game) {
    bool result = true;
    int column, level, cube, placement;
    for (int count = 0; count < size; count++) {
        column = count;
        level = size - 1 - count;
        cube = count;
        placement = (cube * pow(size, 3)) + (level * pow(size, 2))
                      + (row * size) + column;
        if (game[placement] == ' ') {
            result = false;
            break;
        } else if (game[placement]
                    != game[((size - 1) * pow(size, 2))
                             + (row * size)]) {
            result = false;
            break;
        }
    }
    return result;
}
bool win3D_ColLevCub_4_4D(int size, int row, string game) {
    bool result = true;
    int column, level, cube, placement;
    for (int count = 0; count < size; count++) {
        column = count;
        level = count;
        cube = size - 1 - count;
        placement = (cube * pow(size, 3)) + (level * pow(size, 2))
                     + (row * size) + column;
        if (game[placement] == ' ') {
            result = false;
            break;
        } else if (game[placement]
                    != game[((size - 1) * pow(size, 3))
                             + (row * size)]) {
            result = false;
            break;
        }
    }
    return result;
}
bool win3D_RowLevCub_1_4D(int size, int column, string game) {
    bool result = true;
    int row, level, cube, placement;
    for (int count = 0; count < size; count++) {
        row = count;
        level = count;
        cube = count;
        placement = (cube * pow(size, 3)) + (level * pow(size, 2))
                      + (row * size) + column;
        if (game[placement] == ' ') {
            result = false;
            break;
        } else if (game[placement] != game[column]) {
            result = false;
            break;
        }
    }
    return result;
}
bool win3D_RowLevCub_2_4D(int size, int column, string game) {
    bool result = true;
    int row, level, cube, placement;
    for (int count = 0; count < size; count++) {
        row = size - 1 - count;
        level = count;
        cube = count;
        placement = (cube * pow(size, 3)) + (level * pow(size, 2))
                      + (row * size) + column;
        if (game[placement] == ' ') {
            result = false;
            break;
        } else if (game[placement]
                    != game[((size - 1) * size) + column]) {
            result = false;
            break;
        }
    }
    return result;
}
bool win3D_RowLevCub_3_4D(int size, int column, string game) {
    bool result = true;
    int row, level, cube, placement;
    for (int count = 0; count < size; count++) {
        row = count;
        level = size - 1 - count;
        cube = count;
        placement = (cube * pow(size, 3)) + (level * pow(size, 2))
                      + (row * size) + column;
        if (game[placement] == ' ') {
            result = false;
            break;
        } else if (game[placement]
                    != game[((size - 1) * pow(size, 2))
                             + column]) {
            result = false;
            break;
        }
    }
    return result;
}
bool win3D_RowLevCub_4_4D(int size, int column, string game) {
    bool result = true;
    int row, level, cube, placement;
    for (int count = 0; count < size; count++) {
        row = count;
        level = count;
        cube = size - 1 - count;
        placement = (cube * pow(size, 3)) + (level * pow(size, 2))
                     + (row * size) + column;
        if (game[placement] == ' ') {
            result = false;
            break;
        } else if (game[placement]
                    != game[((size - 1) * pow(size, 3))
                             + column]) {
            result = false;
            break;
        }
    }
    return result;
}

bool win4D_1_4D(int size, string game) {
    bool result = true;
    int column, row, level, cube, placement;
    for (int count = 0; count < size; count++) {
        column = count;
        row = count;
        level = count;
        cube = count;
        placement = (cube * pow(size, 3)) + (level * pow(size, 2))
                     + (row * size) + column;
        if (game[placement] == ' ') {
            result = false;
            break;
        } else if (game[placement] != game[0]) {
            result = false;
            break;
        }
    }
    return result;
}
bool win4D_2_4D(int size, string game) {
    bool result = true;
    int column, row, level, cube, placement;
    for (int count = 0; count < size; count++) {
        column = size - 1 - count;
        row = count;
        level = count;
        cube = count;
        placement = (cube * pow(size, 3)) + (level * pow(size, 2))
                     + (row * size) + column;
        if (game[placement] == ' ') {
            result = false;
            break;
        } else if (game[placement] != game[size-1]) {
            result = false;
            break;
        }
    }
    return result;
}
bool win4D_3_4D(int size, string game) {
    bool result = true;
    int column, row, level, cube, placement;
    for (int count = 0; count < size; count++) {
        column = count;
        row = size - 1 - count;
        level = count;
        cube = count;
        placement = (cube * pow(size, 3)) + (level * pow(size, 2))
                     + (row * size) + column;
        if (game[placement] == ' ') {
            result = false;
            break;
        } else if (game[placement] != game[(size - 1) * size]) {
            result = false;
            break;
        }
    }
    return result;
}
bool win4D_4_4D(int size, string game) {
    bool result = true;
    int column, row, level, cube, placement;
    for (int count = 0; count < size; count++) {
        column = count;
        row = count;
        level = size - 1 - count;
        cube = count;
        placement = (cube * pow(size, 3)) + (level * pow(size, 2))
                     + (row * size) + column;
        if (game[placement] == ' ') {
            result = false;
            break;
        } else if (game[placement] != game[(size - 1) * pow(size, 2)]) {
            result = false;
            break;
        }
    }
    return result;
}
bool win4D_5_4D(int size, string game) {
    bool result = true;
    int column, row, level, cube, placement;
    for (int count = 0; count < size; count++) {
        column = count;
        row = count;
        level = count;
        cube = size - 1 - count;
        placement = (cube * pow(size, 3)) + (level * pow(size, 2))
                     + (row * size) + column;
        if (game[placement] == ' ') {
            result = false;
            break;
        } else if (game[placement] != game[(size - 1) * pow(size, 3)]) {
            result = false;
            break;
        }
    }
    return result;
}
bool win4D_6_4D(int size, string game) {
    bool result = true;
    int column, row, level, cube, placement;
    for (int count = 0; count < size; count++) {
        column = size - 1 - count;
        row = count;
        level = count;
        cube = size - 1 - count;
        placement = (cube * pow(size, 3)) + (level * pow(size, 2))
                     + (row * size) + column;
        if (game[placement] == ' ') {
            result = false;
            break;
        } else if (game[placement]
                    != game[((size - 1) * pow(size, 3)) + (size - 1)]) {
            result = false;
            break;
        }
    }
    return result;
}
bool win4D_7_4D(int size, string game) {
    bool result = true;
    int column, row, level, cube, placement;
    for (int count = 0; count < size; count++) {
        column = count;
        row = size - 1 - count;
        level = count;
        cube = size - 1 - count;
        placement = (cube * pow(size, 3)) + (level * pow(size, 2))
                     + (row * size) + column;
        if (game[placement] == ' ') {
            result = false;
            break;
        } else if (game[placement]
                    != game[((size - 1) * pow(size, 3))
                             + ((size - 1) * size)]) {
            result = false;
            break;
        }
    }
    return result;
}
bool win4D_8_4D(int size, string game) {
    bool result = true;
    int column, row, level, cube, placement;
    for (int count = 0; count < size; count++) {
        column = count;
        row = count;
        level = size - 1 - count;
        cube = size - 1 - count;
        placement = (cube * pow(size, 3)) + (level * pow(size, 2))
                     + (row * size) + column;
        if (game[placement] == ' ') {
            result = false;
            break;
        } else if (game[placement]
                    != game[((size - 1) * pow(size, 3))
                             + ((size - 1) * pow(size, 2))]) {
            result = false;
            break;
        }
    }
    return result;
}

