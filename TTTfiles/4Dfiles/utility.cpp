//utility.cpp

#include <sstream>
#include "utility.h"

using namespace std;

string charToString(char piece) {
    ostringstream oss;
    oss << piece;
    return oss.str();
}

string arrayToString(char a[], int size) {
    if (size==0) {
        return "{}";
    }
    ostringstream oss;
    oss << "{" + charToString(a[0]);
    for (int i = 1; i < size; i++) {
        oss << ", " + charToString(a[i]);
    }
    oss << "}";
    return oss.str();
}

void addToGameStringList(GameStringList *list, string game) {
    if (list->getHead() == NULL) {
        list->setHead(new GameString);
        list->setTail(list->getHead());
    } else {
        list->getTail()->setNext(new GameString);
        list->setTail(list->getTail()->getNext());
    }
    list->getTail()->setGame(game);
    return;
}

void freeGameStringList(GameStringList *list) {
    GameString *h = list->getHead(), *n;
    while (h != NULL) {
        n = h->getNext();
        delete h;
        h = n;
    }
    delete list;
    return;
}

/* ============================================================== */
/* ============================================================== */
/* ============================================================== */


// Constructors/Destructors
GameString::GameString(std::string g, std::string m,
                       GameString *n) {
    game = g;
    message = m;
    next = n;
}
GameString::~GameString() {
    game = "";
    message = "";
    next = NULL;
}
GameString::GameString(const GameString & gs) {
    game = gs.game;
    message = gs.message;
    next = gs.next;
}
GameString & GameString::operator=(const GameString & gs) {
    game = gs.game;
    message = gs.message;
    next = gs.next;
    return *this;
}
// Mutators
void GameString::setGame(std::string g) {
    game = g;
}
void GameString::setMessage(std::string m) {
    message = m ;
}
void GameString::setNext(GameString *n) {
    next = n;
}
// Accessors
std::string GameString::getGame() const {
    return game;
}
std::string GameString::getMessage() const {
    return message;
}
GameString *GameString::getNext() const {
    return next;
}

/* ============================================================== */
/* ============================================================== */
/* ============================================================== */


//Constructors/Destructors
GameStringList::GameStringList(GameString *h, GameString *t) {
    head = h;
    tail = t;
}
GameStringList::~GameStringList() {
    head = NULL;
    tail = NULL;
}
GameStringList::GameStringList(const GameStringList & gls) {
    head = gls.head;
    tail = gls.tail;
}
GameStringList & GameStringList::operator=(const GameStringList
                                          & gls) {
    head = gls.head;
    tail = gls.tail;
    return *this;
}
// Mutators
void GameStringList::setHead(GameString *h) {
    head = h;
}
void GameStringList::setTail(GameString *t) {
    tail = t;
}
// Accessors
GameString *GameStringList::getHead() const {
    return head;
}
GameString *GameStringList::getTail() const {
    return tail;
}
