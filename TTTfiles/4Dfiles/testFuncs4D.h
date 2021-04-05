//testFuncs4D.h
#ifndef TESTFUNCS4D_H
#define TESTFUNCS4D_H

#include "utility.h"

GameStringList *test_wins(int size);
void check_failures(GameStringList *list, int size);
std::string test_win1D_col_4D(int size, int row, int level, int cube,
                         std::string game, GameStringList *failures);
std::string test_win1D_row_4D(int size, int column, int level,
               int cube, std::string game, GameStringList *failures);
std::string test_win1D_lev_4D(int size, int column, int row,
               int cube, std::string game, GameStringList *failures);
std::string test_win1D_cub_4D(int size, int column, int row,
              int level, std::string game, GameStringList *failures);

std::string test_win2D_ColRow_1_4D(int size, int level, int cube,
                         std::string game, GameStringList *failures);
std::string test_win2D_ColRow_2_4D(int size, int level, int cube,
                         std::string game, GameStringList *failures);
std::string test_win2D_ColLev_1_4D(int size, int row, int cube,
                         std::string game, GameStringList *failures);
std::string test_win2D_ColLev_2_4D(int size, int row, int cube,
                         std::string game, GameStringList *failures);
std::string test_win2D_ColCub_1_4D(int size, int row, int level,
                         std::string game, GameStringList *failures);
std::string test_win2D_ColCub_2_4D(int size, int row, int level,
                         std::string game, GameStringList *failures);
std::string test_win2D_RowLev_1_4D(int size, int column, int cube,
                         std::string game, GameStringList *failures);
std::string test_win2D_RowLev_2_4D(int size, int column, int cube,
                         std::string game, GameStringList *failures);
std::string test_win2D_RowCub_1_4D(int size, int column, int level,
                         std::string game, GameStringList *failures);
std::string test_win2D_RowCub_2_4D(int size, int column, int level,
                         std::string game, GameStringList *failures);
std::string test_win2D_LevCub_1_4D(int size, int column, int row,
                         std::string game, GameStringList *failures);
std::string test_win2D_LevCub_2_4D(int size, int column, int row,
                         std::string game, GameStringList *failures);

#endif // TESTFUNCS4D_H