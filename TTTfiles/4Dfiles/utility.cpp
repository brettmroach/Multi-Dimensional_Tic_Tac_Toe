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
    if (list->head == NULL) {
        list->head = new GameString;
        list->tail = list->head;
    } else {
        list->tail->next = new GameString;
        list->tail = list->tail->next;
    }
    list->tail->game = game;
    return;
}

void freeGameStringList(GameStringList *list) {
    GameString *head = list->head, *next;
    while (head != NULL) {
        next = head->next;
        delete head;
        head = next;
    }
    delete list;
    return;
}