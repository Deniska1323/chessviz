#include <iostream>
#include <string>
#include "sp.hpp"
#include "checkmove.hpp"

int sp(char** aa)
{
    std::string sp1;
    sp1 = "";

    int b, b1, b2, b3, b4, t = 1, s = sp1.length();

    std::cout << "Player: "; 
    b = 11;
    b1 = 11;
    b2 = 11;
    b3 = 11;
    b4 = 11;
    while (s != 5 || t == 1) {
    	//std::cout<< "("<< s <<")\n";
        std::cin >> sp1;
        s = sp1.length();
        if (sp1 == "exit" || sp1 == "Exit") {
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
            std::cout << "0:";
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
            std::cout << "1:";
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
            std::cout << "2:";
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
            std::cout << "3:";
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
            std::cout << "4:";
            break;
        }
        
        t = checkmove(b, b1, b2, b3, b4, aa);
        
        }
    
        
        ////////
    
    
    aa[b3][b2] = aa[b1][b];
    aa[b1][b] = '.';

    sp1 = "";
    // t = 1;
    // break;

    return 1;
}

