//utility.h
#ifndef UTILITY_H
#define UTILITY_H

#include <string>

struct Player {
    std::string name;
    char piece;
};

struct GameString {
    std::string game;
    std::string message = "";
    GameString *next = NULL;
};

struct GameStringList {
    GameString *head = NULL;
    GameString *tail = NULL;
};


std::string charToString(char piece);
std::string arrayToString(char a[], int size);

void addToGameStringList(GameStringList *list, std::string game);
void freeGameStringList(GameStringList *list);

#endif // UTILITY_H