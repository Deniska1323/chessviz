#include "printF.h"
#include "sp.h"
//#include <iostream>
#include <stdio.h>
//#include <string>

int main()
{
    // int i, j, n = 9;
    int g = 1;
    char aa[9][9] = {{'8', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                     {'7', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                     {'6', '.', '.', '.', '.', '.', '.', '.', '.'},
                     {'5', '.', '.', '.', '.', '.', '.', '.', '.'},
                     {'4', '.', '.', '.', '.', '.', '.', '.', '.'},
                     {'3', '.', '.', '.', '.', '.', '.', '.', '.'},
                     {'2', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                     {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                     {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};

    /*char** aa = new char*[n];
    for (i = 0; i < n; i++)
        aa[i] = new char[n];

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            aa[i][j] = a[i][j];
        }
    }*/
    pf(aa);
    printf("\nTo complete the move, the recording looks like this (e2e4m), to "
           "take (e2e4f).\nExit the program: (exit)\n");
    while (g == 1) {
        g = sp(aa);
        printf("\n");
        pf(aa);
    }
    printf("Goodbye!\n");
}
