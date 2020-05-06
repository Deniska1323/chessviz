#include "printF.hpp"
#include "sp.hpp"
#include <iostream>
#include <string>

int main()
{
    int i, j, n = 9;
    int g = 1;
    char a[9][9] = {{'8', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                    {'7', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                    {'6', '.', '.', '.', '.', '.', '.', '.', '.'},
                    {'5', '.', '.', '.', '.', '.', '.', '.', '.'},
                    {'4', '.', '.', '.', '.', '.', '.', '.', '.'},
                    {'3', '.', '.', '.', '.', '.', '.', '.', '.'},
                    {'2', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                    {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                    {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};

    char** aa = new char*[n];
    for (i = 0; i < n; i++)
        aa[i] = new char[n];

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            aa[i][j] = a[i][j];
        }
    }
    printF(aa);
    std::cout << "\nInput: e2e4m\nExit the program: exit\n";
    while (g == 1) {
        g = sp(aa);
        std::cout << "\n";
        printF(aa);
    }
    std::cout << "Goodbye!\n";
}
