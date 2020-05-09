//testFuncs4D.h
#ifndef TESTFUNCS4D_H
#define TESTFUNCS4D_H

#include "utility.h"

GameStringList *test_wins(int size);
void check_failures(GameStringList *list, int size);
std::string test_win1D_col_4D(int size, int num1, int num2, int num3,
                         std::string game, GameStringList *failures);
std::string test_win1D_row_4D(int size, int num1, int num2, int num3,
                         std::string game, GameStringList *failures);
std::string test_win1D_lev_4D(int size, int num1, int num2, int num3,
                         std::string game, GameStringList *failures);
std::string test_win1D_cub_4D(int size, int num1, int num2, int num3,
                         std::string game, GameStringList *failures);

#endif // TESTFUNCS4D_H