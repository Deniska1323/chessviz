#include "printF.h"
#include <stdio.h>
#include <stdlib.h>

void printF(char aa[9][9])
{
    system("clear");
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            printf("  %c  ", aa[i][j]);
        }
        printf("\n");
    }
}
