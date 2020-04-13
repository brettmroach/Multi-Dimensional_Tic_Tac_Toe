// winDetection.h

#include <string>
using std::string;

bool rowWin_3D(int size, int row, int level, string game);
bool columnWin_3D(int size, int column, int level, string game);
bool vertWin_3D(int size, int row, int column, string game);
bool diagWin2D_l1_3D(int size, int level, string game);
bool diagWin2D_l2_3D(int size, int level, string game);
bool diagWin2D_r1_3D(int size, int row, string game);
bool diagWin2D_r2_3D(int size, int row, string game);
bool diagWin2D_c1_3D(int size, int column, string game);
bool diagWin2D_c2_3D(int size, int column, string game);
bool diagWin3D_1_3D(int size, string game);
bool diagWin3D_2_3D(int size, string game);
bool diagWin3D_3_3D(int size, string game);
bool diagWin3D_4_3D(int size, string game);

