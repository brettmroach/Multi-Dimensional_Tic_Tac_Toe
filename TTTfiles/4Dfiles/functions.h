// functions.h
// working functions for ttt3D
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include "utility.h"

// Assigns name and info to players
Player *createPlayer_4D(); 

// Asks for the dimensions of the gameboard
int gameSize_4D();

/* Creates string of length (size*size*size*size) for empty gameboard
 * For the vector P for a position on the gameboard: 
 * P = <cube, level, row, column>
 * The index I of P in the game-string can be calculated like so:
 * I = (cube*size*size*size)+(level*size*size)+(row*size)+(column)
 */
std::string newGame_string_4D(int size);

void takeTurn_4D(int size, std::string& game, Player *player);

int coordinate_4D(int size, std::string game);

void placeOnGrid_4D(int size, std::string game);

#endif // FUNCTIONS_H
