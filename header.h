#ifndef header_h //agar tidak terduplikat untuk include dan deklarasi fungsi
#define header_h

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define N 5

typedef char string[N];

typedef struct{
	int Mat[N][N];
}Matrix;

//source.c
void gotoxy(int x, int y);
void hidecursor();
void showcursor();
void emptyArr(string input);
void pickMenu(Matrix *A, Matrix *B, bool *isInpputedA, bool *isInputtedB, bool isInputMenu);
void inputMenu(Matrix *M, bool isInputMenu);

//matrix.c
void initMatrix(Matrix *M);
void fillMatrix(Matrix *M);
int isEmpty(Matrix M);
void printMatrix(Matrix M);
Matrix sumMatrix(Matrix M1, Matrix M2);
Matrix multMatrix(Matrix M1, Matrix M2);
void tampilCalcMatrix(Matrix A, Matrix B, Matrix Result, int menu);

//warna.c
void red();
void green();
void white();
void yellow();
void blue();
void cyan();

#endif
