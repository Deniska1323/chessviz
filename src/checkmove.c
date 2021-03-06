#include "checkmove.h"
#include "sp.h"
//#include <iostream>
#include "stdio.h"
#include <stdlib.h>

int checkmove(int b, int b1, int b2, int b3, int b4, char aa[9][9])
{
    int i, t = 0;
    // justmove
    if (aa[b1][b] == 'p' || aa[b1][b] == 'P') {           //пешки
        if (aa[b1][b] == 'P') {                           // team1
            if (b1 == 6) {                                //первый ход
                if (b3 >= b1 - 2 && b3 < b1 && b == b2) { //ход до 2
                    if (!(aa[b1 - 1][b] == '.'
                          && aa[b1 - 2][b] == '.')) { //если п-е
                        t = 1;
                    }
                } else {
                    t = 1;
                }
            } else { //не первый ход
                if (b3 >= b1 - 1 && b3 < b1 && b == b2) { //ход до 1
                                                          // t
                    if (!(aa[b1 - 1][b] == '.')) {        //если п-е
                        t = 1;
                    }
                } else {
                    t = 1;
                }
            }
        } else if (aa[b1][b] == 'p') {                    // team2
            if (b1 == 1) {                                //первый ход
                if (b3 <= b1 + 2 && b3 > b1 && b == b2) { //ход до 2
                    if (!(aa[b1 + 1][b] == '.'
                          && aa[b1 + 2][b] == '.')) { //если п-е
                        t = 1;
                    }
                } else {
                    t = 1;
                }
            } else { //не первый ход
                if (b3 <= b1 + 1 && b3 > b1 && b == b2) { //ход до 1
                    if (!(aa[b1][b + 1] == '.')) {        //если п-е
                        t = 1;
                    }
                } else {
                    t = 1;
                }
            }
        }
    }
    if (aa[b1][b] == 'r' || aa[b1][b] == 'R') { //лодья
        if (b == b2) {                          //вертикаль
            if (b1 > b3) {                      //вперед
                for (i = b1; i > b3; i--) { //вертикаль цыфры (b1 -- b3)
                    if (!(aa[i - 1][b] == '.')) { //есть п-е
                        t = 1;
                    }
                }
                if (!(b == b2)) { //проверка вертикали
                    t = 1;
                }
            }
            if (b1 < b3) {                  //назад
                for (i = b1; i < b3; i++) { //вертикаль цыфры (b1 -- b3)
                    if (!(aa[i + 1][b] == '.')) { //есть п-е
                        t = 1;
                    }
                }
                if (!(b == b2)) { //проверка вертикали
                    t = 1;
                }
            }
        }
        if (b != b2) {                             //горизонт
            if (b > b2) {                          //влево
                for (i = b; i > b2; i--) {         //горизонт (b -- b2)
                    if (!(aa[b1][i - 1] == '.')) { //есть п-е
                        t = 1;
                    }
                }
                if (!(b1 == b3)) { //проверка горизонт
                    t = 1;
                }
            }
            if (b < b2) {                          //вправо
                for (i = b; i < b2; i++) {         //горизонт (b -- b2)
                    if (!(aa[b1][i + 1] == '.')) { //есть п-е
                        t = 1;
                    }
                }
                if (!(b1 == b3)) { //проверка вертикали
                    t = 1;
                }
            }
        }
    }
    if (aa[b1][b] == 'n' || aa[b1][b] == 'N') { //конь
        if (b != b2 && b1 != b3) { //проверка вертикали и горизонта
            if (b3 == b1 + 2 || b3 == b1 - 2) {   //вертикаль
                if (b2 == b + 1 || b2 == b - 1) { //горизонт
                    if (!(aa[b3][b2] == '.')) {
                        t = 1;
                    }
                } else {
                    t = 1;
                }
            } else if (b2 == b + 2 || b2 == b - 2) { //горизонт
                if (b3 == b1 + 1 || b3 == b1 - 1) {  //вертикаль
                    if (!(aa[b3][b2] == '.')) {
                        t = 1;
                    }
                } else {
                    t = 1;
                }
            } else {
                t = 1;
            }
        } else {
            t = 1;
        }
    }
    if (aa[b1][b] == 'B' || aa[b1][b] == 'b') { //слон
        if (abs(b1 - b3) == abs(b - b2)) {      //ход по диоганали
            for (i = 1; i <= abs(b - b2); i++) {
                if (b > b2 && b1 > b3) { //лево-верх
                    if (!(aa[b1 - i][b - i] == '.')) {
                        t = 1;
                    }
                } else if (b > b2 && b1 < b3) { //лево-низ
                    if (!(aa[b1 + i][b - i] == '.')) {
                        t = 1;
                    }
                } else if (b < b2 && b1 < b3) { //право-низ
                    if (!(aa[b1 + i][b + i] == '.')) {
                        t = 1;
                    }
                } else if (b < b2 && b1 > b3) { //право-верх
                    if (!(aa[b1 - i][b + i] == '.')) {
                        t = 1;
                    }
                } else {
                    t = 1;
                }
            }
        } else {
            t = 1;
        }
    }
    if (aa[b1][b] == 'K' || aa[b1][b] == 'k') {      //король
        if (abs(b - b2) <= 1 && abs(b1 - b3) <= 1) { //не дальше шага
            if (!(aa[b3][b2] == '.')) {
                t = 1;
            }
        } else {
            t = 1;
        }
    }
    if (aa[b1][b] == 'Q' || aa[b1][b] == 'q') {
        if (b == b2 && b1 != b3) {          //вертикаль
            if (b1 > b3) {                  //вперед
                for (i = b1; i > b3; i--) { //вертикаль цыфры (b1 -- b3)
                    if (!(aa[i - 1][b] == '.')) { //есть п-е
                        t = 1;
                    }
                }
            }
            if (b1 < b3) {                  //назад
                for (i = b1; i < b3; i++) { //вертикаль цыфры (b1 -- b3)
                    if (!(aa[i + 1][b] == '.')) { //есть п-е
                        t = 1;
                    }
                }
            }
        } else if (b != b2 && b1 == b3) {          //горизонт
            if (b > b2) {                          //влево
                for (i = b; i > b2; i--) {         //горизонт (b -- b2)
                    if (!(aa[b1][i - 1] == '.')) { //есть п-е
                        t = 1;
                    }
                }
            }
            if (b < b2) {                          //вправо
                for (i = b; i < b2; i++) {         //горизонт (b -- b2)
                    if (!(aa[b1][i + 1] == '.')) { //есть п-е
                        t = 1;
                    }
                }
            }
        } else if (abs(b1 - b3) == abs(b - b2)) { //ход по диоганали
            for (i = 1; i <= abs(b - b2); i++) {
                if (b > b2 && b1 > b3) { //лево-верх
                    if (!(aa[b1 - i][b - i] == '.')) {
                        t = 1;
                    }
                } else if (b > b2 && b1 < b3) { //лево-низ
                    if (!(aa[b1 + i][b - i] == '.')) {
                        t = 1;
                    }
                } else if (b < b2 && b1 < b3) { //право-низ
                    if (!(aa[b1 + i][b + i] == '.')) {
                        t = 1;
                    }
                } else if (b < b2 && b1 > b3) { //право-верх
                    if (!(aa[b1 - i][b + i] == '.')) {
                        t = 1;
                    }
                } else {
                    t = 1;
                }
            }
        } else {
            t = 1;
        }
    }

    return t;
}
