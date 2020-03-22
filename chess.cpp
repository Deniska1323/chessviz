#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    int i, j;
    char a[9][9] = {{'8', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                    {'7', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                    {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {'2', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                    {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                    {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};

    ofstream fout;
    fout.open("chess.txt");
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            fout.width(4);
            fout << a[i][j];
        }
        fout << "\n";
    }
    //    std::cout << "Hellow World!\n";
    return 0;
}
