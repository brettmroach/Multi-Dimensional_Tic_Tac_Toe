// winDetection.h
#ifndef WINDETECTION_H
#define WINDETECTION_H
#include <string>

bool win1D_col_4D(int size, int row, int level, int cube, std::string game);
bool win1D_row_4D(int size, int column, int level, int cube, std::string game);
bool win1D_lev_4D(int size, int column, int row, int cube, std::string game);
bool win1D_cub_4D(int size, int column, int row, int level, std::string game);
bool win2D_ColRow_1_4D(int size, int level, int cube, std::string game);
bool win2D_ColRow_2_4D(int size, int level, int cube, std::string game);
bool win2D_ColLev_1_4D(int size, int row, int cube, std::string game);
bool win2D_ColLev_2_4D(int size, int row, int cube, std::string game);
bool win2D_ColCub_1_4D(int size, int row, int level, std::string game);
bool win2D_ColCub_2_4D(int size, int row, int level, std::string game);
bool win2D_RowLev_1_4D(int size, int column, int cube, std::string game);
bool win2D_RowLev_2_4D(int size, int column, int cube, std::string game);
bool win2D_RowCub_1_4D(int size, int column, int level, std::string game);
bool win2D_RowCub_2_4D(int size, int column, int level, std::string game);
bool win2D_LevCub_1_4D(int size, int column, int row, std::string game);
bool win2D_LevCub_2_4D(int size, int column, int row, std::string game);
bool win3D_1_4D(int size, std::string game);
bool win3D_2_4D(int size, std::string game);
bool win3D_3_4D(int size, std::string game);
bool win3D_4_4D(int size, std::string game);

#endif // WINDETECTION_H