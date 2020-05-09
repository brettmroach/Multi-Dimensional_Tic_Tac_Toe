// printoutTest.cpp

#include <iostream>
#include <string>
#include <cmath>
#include "functions.h"
#include "utility.h"
#include "gameStatus.h"
#include "winDetection.h"
#include "testFuncs4D.h"
using namespace std;

int main() {
    int size = 3;
    GameStringList *failures = test_wins(size);
    char response;
    if (failures->head == NULL) {
        cout << "All Pass\n";
    } else {
        cout << "Check failures? [y/n] ";
        cin >> response;
        if (response == 'y') {
            check_failures(failures, size);
        }
    }
    freeGameStringList(failures);
    return 0;
}

