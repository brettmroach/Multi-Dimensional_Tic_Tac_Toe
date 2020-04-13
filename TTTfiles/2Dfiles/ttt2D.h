//ttt2D.h
// Brett Roach
// 2 Dimensional game of tic toe at any length and width

#ifndef TTT2D_H
#define TTT2D_H
#include <string>


int ttt2D(std::string player1, std::string player2, int size);
std::string namePlayer_2D(int player_num);
int gameSize_2D();
std::string newGame_2D(int size);
void placeOnGrid_2D(int size, std::string game);
std::string takeTurn_2D(int size, std::string game,
                     std::string player_name,
                     char player_piece);
int coordinate_2D(int size, std::string game);
std::string gameStatus_2D(int size, std::string game);
bool detectWin_2D(int size, std::string game);
bool detectDraw_2D(int size, std::string game);

#endif //TTT2D_H