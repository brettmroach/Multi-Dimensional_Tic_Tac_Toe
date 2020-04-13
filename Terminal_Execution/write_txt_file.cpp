// write_txt_file.cpp

#include <fstream>
#include <iostream>
#include <cassert>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " <file_name> <text>\n";
        exit(1);
    }
    string filename = argv[1];
    string line;
    int x=2;
    bool finished = false;
    ofstream outfile;
    outfile.open(filename);
    while (argv[x]) {
        string word = argv[x];
        if (word == "\\n") {
            outfile << "\n";
        } else {
            outfile << argv[x] << " ";
        }
        x++;
    }
    outfile << endl;
    outfile.close();
    return 0;
}