#include "header.h"

void initMatrix(Matrix *M){
	int i, j;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			M->Mat[i][j] = -1;
		}
	}
}

void fillMatrix(Matrix *M){
	int i, j;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(M->Mat[i][j] == -1) M->Mat[i][j] = 0;
		}
	}
}

int isEmpty(Matrix M){
	int i,j;
	
	int count = 0;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(M.Mat[i][j]>=0) count++;
		}
	}
	
	return count;
}

void printMatrix(Matrix M){
	int i, j;
	
	int choose = 0;
	
	cyan();
	
	for(i=0;i<11;i++){
		gotoxy(15, 5 + choose);
		printf("|");
		gotoxy(36, 5 + choose);
		printf("|");
		choose++;
	}
	
	choose = 0;
	white();
	printf("\n");
	
	for(i=0;i<N;i++){
		gotoxy(16, 6 + choose);
		for(j=0;j<N;j++){
			if(M.Mat[i][j] == -1) printf(" __ ");
			else if(M.Mat[i][j] > 9) printf(" %d ", M.Mat[i][j]);
			else printf("  %d ", M.Mat[i][j]);
		}
		printf("\n\n");
		choose += 2;
	}
}

Matrix sumMatrix(Matrix M1, Matrix M2){
	Matrix M3;
	
	int i, j;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			M3.Mat[i][j] = M1.Mat[i][j] + M2.Mat[i][j];
		}
	}
	
	return M3;
}

Matrix multMatrix(Matrix M1, Matrix M2){
	Matrix M3;
	
	int i, j, k;
	
	initMatrix(&M3);
	fillMatrix(&M3);
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			for(k=0;k<N;k++){ //untuk mengakses baris dan kolom yang dibutuhkan saat pekralian matriks
				M3.Mat[i][j] += M1.Mat[i][k] * M2.Mat[k][j];
			}
		}
	}
	
	return M3;
}

void tampilCalcMatrix(Matrix A, Matrix B, Matrix Result, int pick){
	int i, j;
	
	int choose = 0;
	
	cyan();
	for(i=0;i<11;i++){
		gotoxy(15, 5 + choose);
		printf("|");
		gotoxy(36, 5 + choose);
		printf("|");
		choose++;
	}
	
	choose = 0;
	white();
	
	for(i=0;i<N;i++){
		gotoxy(16, 6 + choose);
		for(j=0;j<N;j++){
			if(A.Mat[i][j] > 9) printf(" %d ", A.Mat[i][j]);
			else printf("  %d ", A.Mat[i][j]);
		}
		choose += 2;
	}
	
	yellow();
	gotoxy(22, 3);
	printf("Matrix A");
	
	gotoxy(43, 10);
	if(pick==4) printf("+");
	else printf("x");
	
	choose = 0;
	cyan();
	
	for(i=0;i<11;i++){
		gotoxy(50, 5 + choose);
		printf("|");
		gotoxy(71, 5 + choose);
		printf("|");
		choose++;
	}
	
	choose = 0;
	white();
	
	for(i=0;i<N;i++){
		gotoxy(51, 6 + choose);
		for(j=0;j<N;j++){
			if(B.Mat[i][j] > 9) printf(" %d ", B.Mat[i][j]);
			else printf("  %d ", B.Mat[i][j]);
		}
		choose += 2;
	}
	
	yellow();
	gotoxy(57, 3);
	printf("Matrix B");
	
	choose = 0;
	cyan();
	
	for(i=0;i<11;i++){
		gotoxy(85, 5 + choose);
		printf("|");
		gotoxy(115, 5 + choose);
		printf("|");
		choose++;
	}
	
	yellow();
	gotoxy(94, 3);
	printf("Matrix Result");
	
	choose = 0;
	white();
	
	for(i=0;i<N;i++){
		gotoxy(90, 6 + choose);
		for(j=0;j<N;j++){
			if(Result.Mat[i][j] > 100) printf("%d ", Result.Mat[i][j]);
			else if(Result.Mat[i][j] > 9) printf(" %d ", Result.Mat[i][j]);
			else printf("  %d ", Result.Mat[i][j]);
		}
		choose += 2;
	}
	
	yellow();
	gotoxy(78, 10);
	printf("=");
	white();
}
