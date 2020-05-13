#include "sp.h"
#include "checkfite.h"
#include "checkmove.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sp(char aa[9][9])
{
    char sp1[6], sp[] = "exit", sp2[] = "Exit";
    int b, b1, b2, b3, b4, t = 1, s = strlen(sp1);

    printf("::");
    b = 11;
    b1 = 11;
    b2 = 11;
    b3 = 11;
    b4 = 11;
    while (s != 5 || t == 1) {
        scanf("%s", sp1);
        s = strlen(sp1);
        if (strcmp(sp1, sp) == 0 || strcmp(sp1, sp2) == 0) {
            return 0;
        }

        switch (sp1[0]) {
        case 'a':
            b = 1;
            break;
        case 'b':
            b = 2;
            break;
        case 'c':
            b = 3;
            break;
        case 'd':
            b = 4;
            break;
        case 'e':
            b = 5;
            break;
        case 'f':
            b = 6;
            break;
        case 'g':
            b = 7;
            break;
        case 'h':
            b = 8;
            break;
        default:
            // std::cout << "0:";
            printf("0:");
            break;
        }
        switch (sp1[1]) {
        case '1':
            b1 = 7;
            break;
        case '2':
            b1 = 6;
            break;
        case '3':
            b1 = 5;
            break;
        case '4':
            b1 = 4;
            break;
        case '5':
            b1 = 3;
            break;
        case '6':
            b1 = 2;
            break;
        case '7':
            b1 = 1;
            break;
        case '8':
            b1 = 0;
            break;
        default:
            printf("1:");
            break;
        }
        switch (sp1[2]) {
        case 'a':
            b2 = 1;
            break;
        case 'b':
            b2 = 2;
            break;
        case 'c':
            b2 = 3;
            break;
        case 'd':
            b2 = 4;
            break;
        case 'e':
            b2 = 5;
            break;
        case 'f':
            b2 = 6;
            break;
        case 'g':
            b2 = 7;
            break;
        case 'h':
            b2 = 8;
            break;
        default:
            printf("2:");
            break;
        }
        switch (sp1[3]) {
        case '1':
            b3 = 7;
            break;
        case '2':
            b3 = 6;
            break;
        case '3':
            b3 = 5;
            break;
        case '4':
            b3 = 4;
            break;
        case '5':
            b3 = 3;
            break;
        case '6':
            b3 = 2;
            break;
        case '7':
            b3 = 1;
            break;
        case '8':
            b3 = 0;
            break;
        default:
            printf("3:");
            break;
        }
        switch (sp1[4]) {
        case 'f':
            b4 = 1;
            break;
        case 'm':
            b4 = 0;
            break;
        default:
            printf("4:");
            break;
        }

        if (b != 11 && b1 != 11 && b2 != 11 && b3 != 11 && b4 != 11) {
            t = 0;
            if (!(aa[b1][b] == aa[b3][b2] || aa[b1][b] == '.')) {
                if (b4 == 0) {
                    t = checkmove(b, b1, b2, b3, b4, aa);
                }
                if (b4 == 1) {
                    t = checkfite(b, b1, b2, b3, b4, aa);
                }
            }

        } else {
            printf("5:");
        }
    }

    aa[b3][b2] = aa[b1][b];
    aa[b1][b] = '.';

    return 1;
}
