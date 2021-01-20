//evaluate.cpp
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    // argv[1]: dimension of the game
    char dimension = *argv[1];
    // argv[2]: size of game
    int size;
    switch (dimension) {
        case '2':
            if (argv[2]) {
                size = stoi(argv[2]);
                cout << "\n  Play on " << size << "x" << size 
                     << " game board? [Y/N] ";
                break;
            } else {
                cout << "\n  A typical game of 2-dimensional"
                     << " Tic Tac Toe is played on a 3x3 "
                     << "game board,\n  however this program"
                     << " allows for games of other sizes "
                     << "in 2 dimensions.\n";
                cout << "  Enter the desired width of the "
                     << "game: ";
                break;
            }
        case '3':
            if (argv[2]) {
                size = stoi(argv[2]);
                cout << "\n  The terminal width must be set to "
                     << 7+(4*size*size)
                     << " or greater.\n  Play on " << size
                     << "x" << size << "x" << size
                     << " game board? [Y/N] ";
                break;
            } else {
                cout << "\n  A typical game of 2-dimensional "
                     << "Tic Tac Toe is played on a 3x3 "
                     << "game board,\n  however this program "
                     << "allows for games of other "
                     << "sizes in 3 dimensions.\n";
                cout << "  Enter the desired width of the "
                     << "game: ";
                break;
            }
/*
        case '4':
            play_ttt4D();
            break;
*/
        default:
            cerr << "\n Usage: " << argv[0] << " [dimension]"
                << "\n [dimension] is an integer argument "
                << "which corresponds to\n the multi-"
                << "dimensional space of the desired game."
                << "\n {2 or 3}\n\n";
            exit(1);
    }
    return 0;
}