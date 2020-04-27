#include "printF.hpp"
#include <iostream>
#include<cstdlib>
using namespace std;

void printF(char** aa)
{
    system("clear");
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            cout.width(4);
            cout << aa[i][j];
        }
        cout << "\n";
    }
}
