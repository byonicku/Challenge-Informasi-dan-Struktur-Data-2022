#include "header.h"

int main(int argc, char *argv[]) {
	Matrix A, B, Result;
	
	int choose = 0;
	char input = ' ';
	
	bool isInputMenu = false;
	
	bool isInputtedA = false;
	bool isInputtedB = false;
	
	SetWindowText( GetConsoleWindow(), TEXT("MATRIX") );
	
	hidecursor();
	
	initMatrix(&A);
	initMatrix(&B);
	initMatrix(&Result);
	
	system("cls"); // ntah kenapa tanpa ini diawal ga bisa pake warna.c
	
	while(true){
		blue();
		
		gotoxy(23, 3);
		printf(" CHALLENGE ");
		
		gotoxy(24, 4);
		printf(" MATRIX ");
		
		white();
		
		gotoxy(22, 6);
		printf("Input Matrix");
		
		gotoxy(22, 8);
		printf("Edit Matrix");
		
		gotoxy(19, 10);
		printf("Penjumlahan Matrix");
		
		gotoxy(20, 12);
		printf("Perkalian Matrix");
		
		gotoxy(26, 14);
		printf("Quit");
		
		yellow();
		
		gotoxy(10, 17);
		printf("  %c\t- Up", 24);
		gotoxy(10, 18);
		printf("  %c\t- Down", 25);
		gotoxy(10, 19);
		printf("ENTER\t- Select Menu");
		
		white();
		
		while(input!=13){
			gotoxy(16, 6 + choose);
			green();
			printf("->");
			
			gotoxy(38, 6 + choose);
			printf("<-");
			
			input = getch();
			if(input == -32) input = getch();
			
			gotoxy(16, 6 + choose);
			printf("  ");
			gotoxy(38, 6 + choose);
			white();
			printf("  ");
			
			if(input == 72){
				if(choose>0){
					choose -= 2;
				}
			}
			
			if(input == 80){
				if(choose<8){
					choose += 2;
				}
			}
		}
		
		switch(choose){
			case 0:
				if(isInputtedA && isInputtedB){
					gotoxy(40, 6);	
					red();
					printf("Data sudah terinput!");
					sleep(1.5);
					white();
					gotoxy(40, 6);	
					printf("                         ");
					break;
				}
				isInputMenu = true;
				pickMenu(&A, &B, &isInputtedA, &isInputtedB, isInputMenu);
				//setelah berhasil menginputkan keduanya
				if(isInputtedA && isInputtedB){
					gotoxy(16, 21);	
					green();
					printf("\tKedua matriks berhasil terinput!");
					sleep(1.5);
					white();
					gotoxy(16, 21);	
					printf("                         ");
				}
				break;
			case 2:
				if(A.Mat[0][0] == -1 || B.Mat[0][0] == -1) {
					gotoxy(40, 8);
					red();	
					printf("Data masih ada yang belum diinput!");
					sleep(1.5);
					white();
					gotoxy(40, 8);	
					printf("                                   ");
					break;
				}
				
				isInputMenu = false;
				pickMenu(&A, &B, &isInputtedA, &isInputtedB, isInputMenu);
				break;
			case 4:
				if(A.Mat[0][0] == -1 || B.Mat[0][0] == -1) {
					gotoxy(40, 10);	
					red();
					printf("Data masih ada yang belum diinput!");
					sleep(1.5);
					white();
					gotoxy(40, 10);	
					printf("                         ");
					break;
				}
				system("cls");
				Result = sumMatrix(A, B);
				tampilCalcMatrix(A, B, Result, choose);
				gotoxy(16, 17);
				printf("Tekan tombol apa saja untuk kembali...");
				getch();
				break;
			case 6:
				if(A.Mat[0][0] == -1 || B.Mat[0][0] == -1) {
					gotoxy(40, 12);	
					red();
					printf("Data masih ada yang belum diinput!");
					sleep(1.5);
					white();
					gotoxy(40, 12);	
					printf("                         ");
					break;
				}
				system("cls");
				Result = multMatrix(A, B);
				tampilCalcMatrix(A, B, Result, choose);
				gotoxy(16, 17);
				printf("Tekan tombol apa saja untuk kembali...");
				getch();
				break;
			case 8:
				system("cls");
				printf("Nico Herlim - 210711227");
				printf("\nInformasi dan Struktur Data C\n\n");
				system("pause");
				exit(0);
				break;
		}
		
    	input = ' ';
    	system("cls");

	}
	return 0;
}
