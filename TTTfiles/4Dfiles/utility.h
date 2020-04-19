//utility.h
#ifndef UTILITY_H
#define UTILITY_H

#include <string>

struct Player {
    std::string name;
    char piece;
};


std::string charToString(char piece);
std::string arrayToString(char a[], int size);

#endif // UTILITY_H