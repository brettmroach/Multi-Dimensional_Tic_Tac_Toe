// winDetection.cpp
// detectWin helpers - identify a win anywhere in the game

#include <string>
#include "winDetection.h"
using std::string;

bool rowWin_3D(int size, int row, int level, string game) {
    bool result = true;
    int placement = (level * size * size) + (row * size);
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
bool columnWin_3D(int size, int column, int level, string game) {
    bool result = true;
    int placement = (level * size * size) + column;
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
bool vertWin_3D(int size, int row, int column, string game) {
    bool result = true;
    int placement = (row * size) + column;
    for (int level = 0; level < size; level++) {
        if (game[placement + (level*size * size)] == ' ') {
            result = false;
            break;
        } else if (game[placement + (level * size * size)] != game[placement]) {
            result = false;
            break;
        } else {
            continue;
        }
    }
    return result;
}
bool diagWin2D_l1_3D(int size, int level, string game){
    bool result = true;
    int placement = level * size * size;
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
bool diagWin2D_l2_3D(int size, int level, string game){
    bool result = true;
    int placement = level * size * size;
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
bool diagWin2D_r1_3D(int size, int row, string game){
    bool result = true;
    int placement = row * size;
    int level;
    for (int column = 0; column < size; column++) {
        level = column;
        if (game[(level * size * size) + placement + column] == ' ') {
            result = false;
            break;
        } else if (game[(level * size * size) + placement + column]
                    != game[placement]) {
            result = false;
            break;
        } else {
            continue;
        }
    }
    return result;
}
bool diagWin2D_r2_3D(int size, int row, string game){
    bool result = true;
    int placement = row * size;
    int level;
    for (int column = 0; column < size; column++) {
        level = size - 1 - column;
        if (game[(level * size * size) + placement + column] == ' ') {
            result = false;
            break;
        } else if (game[(level * size * size) + placement + column]
                    != game[((size - 1) * size * size) + placement]) {
            result = false;
            break;
        } else {
            continue;
        }
    }
    return result;
}
bool diagWin2D_c1_3D(int size, int column, string game){
    bool result = true;
    int row;
    for (int level = 0; level < size; level++) {
        row = level;
        if (game[(level * size * size) + (row * size) + column] == ' ') {
            result = false;
            break;
        } else if (game[(level * size * size) + (row * size) + column]
                    != game[column]) {
            result = false;
            break;
        }
    }
    return result;
}
bool diagWin2D_c2_3D(int size, int column, string game){
    bool result = true;
    int row;
    for (int level = 0; level < size; level++) {
        row = size - 1 - level;
        if (game[(level * size * size) + (row * size) + column] == ' ') {
            result = false;
            break;
        } else if (game[(level * size * size) + (row * size) + column]
                    != game[((size - 1) * size) + column]) {
            result = false;
            break;
        }
    }
    return result;
}
bool diagWin3D_1_3D(int size, string game) {
    bool result = true;
    int row, column, level, placement;
    for (int count = 0; count < size; count++) {
        row = count;
        column = count;
        level = count;
        placement = (level * size * size) + (row * size) + column;
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
bool diagWin3D_2_3D(int size, string game) {
    bool result = true;
    int row, column, level, placement;
    for (int count = 0; count < size; count++) {
        row = count;
        column = size - 1 - count;
        level = count;
        placement = (level * size * size) + (row * size) + column;
        if (game[placement] == ' ') {
            result = false;
            break;
        } else if (game[placement] != game[size - 1]) {
            result = false;
            break;
        }
    }
    return result;
}
bool diagWin3D_3_3D(int size, string game) {
    bool result = true;
    int row, column, level, placement;
    for (int count = 0; count < size; count++) {
        row = size - 1 - count;
        column = count;
        level = count;
        placement = (level * size * size) + (row * size) + column;
        if (game[placement] == ' ') {
            result = false;
            break;
        } else if (game[placement] != game[((size - 1) * size)]) {
            result = false;
            break;
        }
    }
    return result;
}
bool diagWin3D_4_3D(int size, string game) {
    bool result = true;
    int row, column, level, placement;
    for (int count = 0; count < size; count++) {
        row = count;
        column = count;
        level = size - 1 - count;
        placement = (level * size * size) + (row * size) + column;
        if (game[placement] == ' ') {
            result = false;
            break;
        } else if (game[placement] != game[((size - 1) * size) + size-1]) {
            result = false;
            break;
        }
    }
    return result;
}
