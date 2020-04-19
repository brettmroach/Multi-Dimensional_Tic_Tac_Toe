//utility.cpp

#include <sstream>
#include "utility.h"

std::string charToString(char piece) {
    std::ostringstream oss;
    oss << piece;
    return oss.str();
}

std::string arrayToString(char a[], int size) {
    if (size==0) {
        return "{}";
    }
    std::ostringstream oss;
    oss << "{" + charToString(a[0]);
    for (int i = 1; i < size; i++) {
        oss << ", " + charToString(a[i]);
    }
    oss << "}";
    return oss.str();
}
