//utility.h
#ifndef UTILITY_H
#define UTILITY_H

#include <string>

struct Player {
    std::string name;
    char piece;
};

/* ============================================================== */
/* ============================================================== */


class GameString
{
private:
    std::string game;
    std::string message;
    GameString *next;
public:
    GameString(std::string g = "", std::string m = "",
               GameString *n = NULL);
    ~GameString();
    GameString(const GameString & gs);
    GameString & operator=(const GameString & gs);
    void setGame(std::string g);
    void setMessage(std::string m);
    void setNext(GameString *n);
    std::string getGame() const;
    std::string getMessage() const;
    GameString *getNext() const;
};

/* ============================================================== */
/* ============================================================== */


class GameStringList
{
private:
    GameString *head;
    GameString *tail;
public:
    GameStringList(GameString *h = NULL, GameString *t = NULL);
    ~GameStringList();
    GameStringList(const GameStringList & gsl);
    GameStringList & operator=(const GameStringList & gls);
    void setHead(GameString *h);
    void setTail(GameString *t);
    GameString *getHead() const;
    GameString *getTail() const;
};

/* ============================================================== */
/* ============================================================== */

std::string charToString(char piece);
std::string arrayToString(char a[], int size);

void addToGameStringList(GameStringList *list, std::string game);
void freeGameStringList(GameStringList *list);

#endif // UTILITY_H