// functions.h
// working functions for ttt3D
#include <string>

void printCube_3D();
std::string namePlayer_3D(int player_num);
int gameSize_3D();
std::string newGame_3D(int size);
void takeTurn_3D(int size, std::string& game, std::string player_name, char player_piece);
int coordinate_3D(int size, std::string game);
void placeOnGrid_3D(int size, std::string game);
