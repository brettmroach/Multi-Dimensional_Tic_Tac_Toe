// gameStatus.h
#ifndef GAMESTATUS_H
#define GAMESTATUS_H
#include <string>

std::string gameStatus_4D(int size, std::string game);

// TODO
bool detectWin_4D(int size, std::string game);

// TODO
bool detectDraw_4D(int size, std::string game);

// Tests for 1D straight line wins
bool win1D(int size, int num1, int num2, int num3, std::string game);
// Tests for 2D diagonal wins
bool win2D(int size, int num1, int num2, std::string game);
// TODO:
// Tests for 3D diagonal wins
bool win3D(int size, int num1, std::string game);
// TODO:
// Tests for 4D diagonal wins
bool win4D(int size, std::string game);


#endif // GAMESTATUS_H