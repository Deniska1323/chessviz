#include"sp.hpp"
#include <iostream>
using namespace std;

int sp(char** aa)
{
    std::string sp1;
    sp1 = "";

    int b, b1, b2, b3, t = 1, s = sizeof(sp1) / sizeof(char);

    std::cout << "Player: "; //проверка на правильность ввода
    b = 11;
    b1 = 11;
    b2 = 11;
    b3 = 11;
    while (s != 4 && t == 1) {
        std::cin >> sp1;
        if (sp1 == "exit" || sp1 == "Exit") {
            return 0;
        }

        switch (sp1[1]) {
        case '1':
            b = 7;
            break;
        case '2':
            b = 6;
            break;
        case '3':
            b = 5;
            break;
        case '4':
            b = 4;
            break;
        case '5':
            b = 3;
            break;
        case '6':
            b = 2;
            break;
        case '7':
            b = 1;
            break;
        case '8':
            b = 0;
            break;
        default:
            cout << ": ";
            break;
        }

        switch (sp1[0]) {
        case 'a':
            b1 = 1;
            break;
        case 'b':
            b1 = 2;
            break;
        case 'c':
            b1 = 3;
            break;
        case 'd':
            b1 = 4;
            break;
        case 'e':
            b1 = 5;
            break;
        case 'f':
            b1 = 6;
            break;
        case 'g':
            b1 = 7;
            break;
        case 'h':
            b1 = 8;
            break;
        default:
            cout << ": ";
            break;
        }

        switch (sp1[3]) {
        case '1':
            b2 = 7;
            break;
        case '2':
            b2 = 6;
            break;
        case '3':
            b2 = 5;
            break;
        case '4':
            b2 = 4;
            break;
        case '5':
            b2 = 3;
            break;
        case '6':
            b2 = 2;
            break;
        case '7':
            b2 = 1;
            break;
        case '8':
            b2 = 0;
            break;
        default:
            cout << ": ";
            break;
        }

        switch (sp1[2]) {
        case 'a':
            b3 = 1;
            break;
        case 'b':
            b3 = 2;
            break;
        case 'c':
            b3 = 3;
            break;
        case 'd':
            b3 = 4;
            break;
        case 'e':
            b3 = 5;
            break;
        case 'f':
            b3 = 6;
            break;
        case 'g':
            b3 = 7;
            break;
        case 'h':
            b3 = 8;
            break;
        default:
            cout << ": ";
            break;
        }
        if (b != 11 && b1 != 11 && b2 != 11 && b3 != 11) {
            t = 0;
        }
    }
    aa[b2][b3] = aa[b][b1];
    aa[b][b1] = '.';

    sp1 = "";
    // t = 1;
    // break;

    return 1;
}

