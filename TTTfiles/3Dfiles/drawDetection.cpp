// drawDetection.cpp
// detectDraw helpers - check to see that there are no possible wins 

#include <string>
#include "drawDetection.h"
using std::string;

bool rowPossible_3D(int size, int row, int level, string game) {
    bool result = true;
    bool x = false, o = false;
    int placement = (level * size * size) + (row * size);
    for (int column = 0; column < size; column++) {
        if (game[placement + column] == 'x') {
            // check if x is in the row
            x = true;
        } else if (game[placement + column] == 'o') {
            // check if o is in the row
            o = true;
        } else {
            continue;
        }
    }
    if (x && o) {
        result = false;
    }
    return result;
}
bool columnPossible_3D(int size, int column, int level, string game) {
    bool result = true;
    bool x = false, o = false;
    int placement = (level * size * size) + column;
    for (int row = 0; row < size; row++) {
        if (game[placement + (row * size)] == 'x') {
            x = true;
        } else if (game[placement + (row * size)] == 'o') {
            o = true;
        } else {
            continue;
        }
    }
    if (x && o) {
        result = false;
    }
    return result;
}
bool vertPossible_3D(int size, int row, int column, string game) {
    bool result = true;
    bool x = false, o = false;
    int placement = (row * size) + column;
    for (int level = 0; level < size; level++) {
        if (game[placement + (level * size * size)] == 'x') {
            x = true;
        } else if (game[placement + (level * size * size)] == 'o') {
            o = true;
        } else {
            continue;
        }
    }
    if (x && o) {
        result = false;
    }
    return result;
}
bool diagPossible2D_l1_3D(int size, int level, string game) {
    bool result = true;
    bool x = false, o = false;
    int column, placement;
    for (int row = 0; row < size; row ++) {
        column = row;
        placement = (level * size * size) + (row * size) + column;
        if (game[placement] == 'x') {
            x = true;
        } else if (game[placement] == 'o') {
            o = true;
        } else {
            continue;
        }
    }
    if (x && o) {
        result = false;
    }
    return result;
}
bool diagPossible2D_l2_3D(int size, int level, string game) {
    bool result = true;
    bool x = false, o = false;
    int column, placement;
    for (int row = 0; row < size; row ++) {
        column = size - 1 - row;
        placement = (level * size * size) + (row * size) + column;
        if (game[placement] == 'x') {
            x = true;
        } else if (game[placement] == 'o') {
            o = true;
        } else {
            continue;
        }
    }
    if (x && o) {
        result = false;
    }
    return result;
}
bool diagPossible2D_r1_3D(int size, int row, string game) {
    bool result = true;
    bool x= false, o = false;
    int level, placement;
    for (int column = 0; column < size; column++) {
        level = column;
        placement = (level * size * size) + (row * size) + column;
        if (game[placement] == 'x') {
            x = true;
        } else if (game[placement] == 'o') {
            o = true;
        } else {
            continue;
        }
    }
    if (x && o) {
        result = false;
    }
    return result;
}
bool diagPossible2D_r2_3D(int size, int row, string game) {
    bool result = true;
    bool x= false, o = false;
    int level, placement;
    for (int column = 0; column < size; column++) {
        level = size - 1 - column;
        placement = (level * size * size) + (row * size) + column;
        if (game[placement] == 'x') {
            x = true;
        } else if (game[placement] == 'o') {
            o = true;
        } else {
            continue;
        }
    }
    if (x && o) {
        result = false;
    }
    return result;
}
bool diagPossible2D_c1_3D(int size, int column, string game) {
    bool result = true;
    bool x= false, o = false;
    int row, placement;
    for (int level = 0; level < size; level++) {
        row = level;
        placement = (level * size * size) + (row * size) + column;
        if (game[placement] == 'x') {
            x = true;
        } else if (game[placement] == 'o') {
            o = true;
        } else {
            continue;
        }
    }
    if (x && o) {
        result = false;
    }
    return result;
}
bool diagPossible2D_c2_3D(int size, int column, string game) {
    bool result = true;
    bool x = false, o = false;
    int row, placement;
    for (int level = 0; level < size; level++) {
        row = size - 1 - level;
        placement = (level * size * size) + (row * size) + column;
        if (game[placement] == 'x') {
            x = true;
        } else if (game[placement] == 'o') {
            o = true;
        } else {
            continue;
        }
    }
    if (x && o) {
        result = false;
    }
    return result;
}
bool diagPossible3D_1_3D(int size, string game) {
    bool result = true;
    bool x = false, o = false;
    int row, column, level, placement;
    for (int count = 1; count < size; count++) {
        row = count;
        column = count;
        level = count;
        placement = (level * size * size) + (row * size) + column;
        if (game[placement == 'x']) {
            x = true;
        } else if (game[placement] == 'o') {
            o = true;
        } else {
            continue;
        }
    }
    if (x && o ) {
        result = false;
    }
    return result;
}
bool diagPossible3D_2_3D(int size, string game) {
    bool result = true;
    bool x = false, o = false;
    int row, column, level, placement;
    for (int count = 1; count < size; count++) {
        row = count;
        column = size - 1 - count;
        level = count;
        placement = (level * size * size) + (row * size) + column;
        if (game[placement == 'x']) {
            x = true;
        } else if (game[placement] == 'o') {
            o = true;
        } else {
            continue;
        }
    }
    if (x && o ) {
        result = false;
    }
    return result;
}
bool diagPossible3D_3_3D(int size, string game) {
    bool result = true;
    bool x = false, o = false;
    int row, column, level, placement;
    for (int count = 1; count < size; count++) {
        row = size - 1 - count;
        column = count;
        level = count;
        placement = (level * size * size) + (row * size) + column;
        if (game[placement == 'x']) {
            x = true;
        } else if (game[placement] == 'o') {
            o = true;
        } else {
            continue;
        }
    }
    if (x && o ) {
        result = false;
    }
    return result;
}
bool diagPossible3D_4_3D(int size, string game) {
    bool result = true;
    bool x = false, o = false;
    int row, column, level, placement;
    for (int count = 1; count < size; count++) {
        row = count;
        column = count;
        level = size - 1 - count;
        placement = (level * size * size) + (row * size) + column;
        if (game[placement == 'x']) {
            x = true;
        } else if (game[placement] == 'o') {
            o = true;
        } else {
            continue;
        }
    }
    if (x && o ) {
        result = false;
    }
    return result;
}
