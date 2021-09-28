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


std::string test_win3D_ColRowLev_1_4D(int size, int cube,
                         std::string game, GameStringList *failures);
std::string test_win3D_ColRowLev_2_4D(int size, int cube,
                         std::string game, GameStringList *failures);
std::string test_win3D_ColRowLev_3_4D(int size, int cube,
                         std::string game, GameStringList *failures);
std::string test_win3D_ColRowLev_4_4D(int size, int cube,
                         std::string game, GameStringList *failures);
std::string test_win3D_ColRowCub_1_4D(int size, int level,
                         std::string game, GameStringList *failures);
std::string test_win3D_ColRowCub_2_4D(int size, int level,
                         std::string game, GameStringList *failures);
std::string test_win3D_ColRowCub_3_4D(int size, int level,
                         std::string game, GameStringList *failures);
std::string test_win3D_ColRowCub_4_4D(int size, int level,
                         std::string game, GameStringList *failures);
std::string test_win3D_ColLevCub_1_4D(int size, int row,
                         std::string game, GameStringList *failures);
std::string test_win3D_ColLevCub_2_4D(int size, int row,
                         std::string game, GameStringList *failures);
std::string test_win3D_ColLevCub_3_4D(int size, int row,
                         std::string game, GameStringList *failures);
std::string test_win3D_ColLevCub_4_4D(int size, int row,
                         std::string game, GameStringList *failures);
std::string test_win3D_RowLevCub_1_4D(int size, int column,
                         std::string game, GameStringList *failures);
std::string test_win3D_RowLevCub_2_4D(int size, int column,
                         std::string game, GameStringList *failures);
std::string test_win3D_RowLevCub_3_4D(int size, int column,
                         std::string game, GameStringList *failures);
std::string test_win3D_RowLevCub_4_4D(int size, int column,
                         std::string game, GameStringList *failures);


std::string test_win4D_1_4D(int size, std::string game,
                         GameStringList *failures);
std::string test_win4D_2_4D(int size, std::string game,
                         GameStringList *failures);
std::string test_win4D_3_4D(int size, std::string game,
                         GameStringList *failures);
std::string test_win4D_4_4D(int size, std::string game,
                         GameStringList *failures);
std::string test_win4D_5_4D(int size, std::string game,
                         GameStringList *failures);
std::string test_win4D_6_4D(int size, std::string game,
                         GameStringList *failures);
std::string test_win4D_7_4D(int size, std::string game,
                         GameStringList *failures);
std::string test_win4D_8_4D(int size, std::string game,
                         GameStringList *failures);

#endif // TESTFUNCS4D_H