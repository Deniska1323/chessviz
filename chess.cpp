
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void printF(char **aa) {
system("cls");
int i, j;
for (i = 0; i < 9; i++) {
for (j = 0; j < 9; j++) {
cout.width(4);
cout << aa[i][j];
}
cout << "\n";
}
}

int main()
{
int i, j, n = 9;
char a[9][9] = { { '8', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
{ '7', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
{ '6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
{ '5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
{ '4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
{ '3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
{ '2', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
{ '1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' },
{ ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' } };

char **aa = new char*[n];
for (i = 0; i < n; i++) aa[i] = new char[n];

for (i = 0; i < 9; i++) {
for (j = 0; j < 9; j++) {
aa[i][j] = a[i][j];
}
}
// free(a);

printF(aa);

int b, b1, b2, b3, t;
std::string sp1;


std::cout << "1Player: "; //проверка на правиьность ввода
std::cin >> sp1;
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
}
switch (sp1[2]) {
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
}
switch (sp1[1]) {
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
}
// std::cout << b << b2<< " " << b1 << b3<<"\n";
// std::cout << b << ;

// if (aa[b][b2] != ' ' && aa[b1][b3] == ' ') {
// aa[b3][b1] = aa[b2][b];
// std::cout << "-" << aa[b2][b] << "\n";
// std::cout << "-" << aa[b3][b1];

swap(aa[b3][b1], aa[b2][b]);
// }

printF(aa);

// b = sp1[0]; b1 = sp1[1];
// std::cout << b << " " << b1;



system("pause");
return 0;
}

/*int main()
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
// std::cout << "Hellow World!\n";
return 0;
}*/
