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

bool win3D_ColRowLev_1_4D(int size, int cube, std::string game);
bool win3D_ColRowLev_2_4D(int size, int cube, std::string game);
bool win3D_ColRowLev_3_4D(int size, int cube, std::string game);
bool win3D_ColRowLev_4_4D(int size, int cube, std::string game);
bool win3D_ColRowCub_1_4D(int size, int level, std::string game);
bool win3D_ColRowCub_2_4D(int size, int level, std::string game);
bool win3D_ColRowCub_3_4D(int size, int level, std::string game);
bool win3D_ColRowCub_4_4D(int size, int level, std::string game);
bool win3D_ColLevCub_1_4D(int size, int row, std::string game);
bool win3D_ColLevCub_2_4D(int size, int row, std::string game);
bool win3D_ColLevCub_3_4D(int size, int row, std::string game);
bool win3D_ColLevCub_4_4D(int size, int row, std::string game);
bool win3D_RowLevCub_1_4D(int size, int column, std::string game);
bool win3D_RowLevCub_2_4D(int size, int column, std::string game);
bool win3D_RowLevCub_3_4D(int size, int column, std::string game);
bool win3D_RowLevCub_4_4D(int size, int column, std::string game);

bool win4D_1_4D(int size, std::string game);
bool win4D_2_4D(int size, std::string game);
bool win4D_3_4D(int size, std::string game);
bool win4D_4_4D(int size, std::string game);
bool win4D_5_4D(int size, std::string game);
bool win4D_6_4D(int size, std::string game);
bool win4D_7_4D(int size, std::string game);
bool win4D_8_4D(int size, std::string game);


#endif // WINDETECTION_H