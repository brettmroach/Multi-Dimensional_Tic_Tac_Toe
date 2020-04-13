// drawDetection.h

#include <string>
using std::string;

bool rowPossible_3D(int size, int row, int level, string game);
bool columnPossible_3D(int size, int column, int level, string game);
bool vertPossible_3D(int size, int row, int column, string game);
bool diagPossible2D_l1_3D(int size, int level, string game);
bool diagPossible2D_l2_3D(int size, int level, string game);
bool diagPossible2D_r1_3D(int size, int row, string game);
bool diagPossible2D_r2_3D(int size, int row, string game);
bool diagPossible2D_c1_3D(int size, int column, string game);
bool diagPossible2D_c2_3D(int size, int column, string game);
bool diagPossible3D_1_3D(int size, string game);
bool diagPossible3D_2_3D(int size, string game);
bool diagPossible3D_3_3D(int size, string game);
bool diagPossible3D_4_3D(int size, string game);

