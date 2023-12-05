#include "header.h"

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hidecursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void showcursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 10;
   info.bVisible = TRUE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void emptyArr(string input){
	int i;
	
	for(i=0;i<N;i++){
		input[i] = '-';
	}
}

void pickMenu(Matrix *A, Matrix *B, bool *isInputtedA, bool *isInputtedB, bool isInputMenu){
	int choose = 0;
	char input = ' ';
	
	while(choose!=4){
		if(*isInputtedA && *isInputtedB && isInputMenu) break;
		
		choose = 0;
		input = ' ';
		
		system("cls");
		
		blue();
		
		gotoxy(23, 3);
		printf(" CHALLENGE ");
		
		gotoxy(24, 4);
		printf(" MATRIX ");
		
		white();
		
		gotoxy(24, 6);
		printf("Matrix A");
		
		gotoxy(24, 8);
		printf("Matrix B");
		
		gotoxy(26, 10);
		printf("Back");
		
		yellow();
		
		gotoxy(10, 17);
		printf("  %c\t- Up", 24);
		gotoxy(10, 18);
		printf("  %c\t- Down", 25);
		gotoxy(10, 19);
		printf("ENTER\t- Select Menu");
		gotoxy(10, 20);
		printf("ESC\t- Back");
		
		white();
		
		while(input!=13){
				gotoxy(16, 6 + choose);
				green();
				printf("->");
				gotoxy(38, 6 + choose);
				printf("<-");
				
				input = getch();
				if(input == -32) input = getch();
				
				if(input == 27) {
					choose = 4;
					break;
				}
				
				if(choose==0 && isInputMenu && *isInputtedA && input == 13){
					gotoxy(42, 6);
					printf("Data sudah terinput, edit di 'Edit Matrix'");
					sleep(1.5);
					gotoxy(42, 6);
					printf("                                          ");
					input = ' ';
					continue;
				}
				
				if(choose==2 && isInputMenu && *isInputtedB && input == 13){
					gotoxy(42, 8);
					printf("Data sudah terinput, edit di 'Edit Matrix'");
					sleep(1.5);
					gotoxy(42, 8);
					printf("                                          ");
					input = ' ';
					continue;
				}
				
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
					if(choose<4){
						choose += 2;
					}
				}
			}
			
		switch(choose){
			case 0:
				inputMenu(A, isInputMenu);
				fillMatrix(A);
				*isInputtedA = true;
				break;
			case 2:
				inputMenu(B, isInputMenu);
				fillMatrix(B);
				*isInputtedB = true;
				break;
			case 4:
				break;
		}
	}
	
	choose = 0;
}

void inputMenu(Matrix *M, bool isInputMenu){
	char input = ' ', inputSave = ' ';
	
	int chooseX = 0, chooseY = 0, typeX = 0;
	int i;
	
	int totalInput = 0;
	
	string userInput;
	emptyArr(userInput);
	
	system("cls");
	printMatrix(*M);
	
	green();
	gotoxy(38, 5);
	if(isInputMenu) printf("[ Input Matriks ]");
	else printf("[ Edit Matriks ]");
	yellow();
	gotoxy(38, 9);
	printf("  %c\t- Up", 24);
	gotoxy(38, 10);
	printf("  %c\t- Down", 25);
	gotoxy(38, 11);
	printf(" <--\t- Left");
	gotoxy(38, 12);
	printf(" -->\t- Right");
	gotoxy(38, 13);
	printf("BACKSPACE\t- Delete (Select Mode)");
	gotoxy(38, 14);
	printf("ENTER\t- Select or Confirm (Select Mode)");
	gotoxy(38, 15);
	printf("ESC\t- Exit and Save or Cancel (Select Mode)");
	white();
	
	while(input!=27){
		if(isEmpty(*M)==25 && isInputMenu){
			gotoxy(16, 17);	
			green();
			printf("\tMatriks berhasil terinput!");
			sleep(1.5);
			white();
			break;
		}
		
		blue();
		gotoxy(38, 7);
		printf("Location : %d - %d", chooseY, chooseX);
		
		green();
		gotoxy(17 + chooseX * 4, 7 + chooseY * 2);
		printf("%c%c", 24, 24);
		white();
		
		input = getch();
		if(input == -32) input = getch();
		
		gotoxy(17 + chooseX * 4, 7 + chooseY * 2);
		printf("  ");
		
		if(input==27 && isInputMenu){
			yellow();
			gotoxy(16, 17);
			printf("Yakin untuk kembali ke menu? (Data yang kosong akan otomatis terisi 0)");
			gotoxy(16, 18);
			printf("Tekan Y untuk kembali ke menu");
			gotoxy(16, 19);
			printf("Tekan tombol apa saja untuk batal");
			white();
			input = getch();
			if(toupper(input) == 'Y'){
				break;
			}
			else{
				gotoxy(16, 17);
				printf("                                                                      ");
				gotoxy(16, 18);
				printf("                              ");
				gotoxy(16, 19);
				printf("                                 ");
				input = ' ';
				continue;
			}
		}
		
		if(input == 72){
				if(chooseY>0){
					chooseY -= 1;
				}
			}
			
		if(input == 80){
			if(chooseY<4){
				chooseY += 1;
			}
		}
		
		if(input == 75){
			if(chooseX>0){
				chooseX -= 1;
			}
		}
		
		if(input == 77){
			if(chooseX<4){
				chooseX += 1;
			}
		}
		
		if(M->Mat[chooseY][chooseX]>-1 && isInputMenu && input == 13) {
			gotoxy(16, 17);
			red();
			hidecursor();
			printf("Untuk mengedit nilai tolong edit di menu edit!");
			sleep(1.5);
			white();
			gotoxy(16, 17);
			printf("                                              ");
			input = ' ';
			continue;
		}
		
		if(input == 13){
			gotoxy(24, 3);
			green();
			printf("Masukan Nilai [0-50]");
			white();
			
			gotoxy(17 + chooseX * 4 + typeX, 6 + chooseY * 2);
			printf("__");
			
			while(true){
				gotoxy(17 + chooseX * 4 + typeX, 6 + chooseY * 2);
				showcursor();
				
				input = getch();
				
				if(input == 8 && totalInput == 0) continue;
				
				if(input == 13 && totalInput == 0) {
					gotoxy(16, 17);
					red();
					hidecursor();
					printf("Tolong inputkan nilai sebelum enter!");
					sleep(1.5);
					white();
					gotoxy(16, 17);
					printf("                                    ");
					continue;
				}
				
				if(input == 8 && totalInput > 0) {
					userInput[totalInput-1] = '-';
					
					printf("\b_\b");
					typeX--;
					totalInput--;
					
					continue;
				}
				
				if(input == 27) {
					input = ' ';
					inputSave = ' ';
					hidecursor();
					
					gotoxy(17 + chooseX * 4, 6 + chooseY * 2);
					
					if(M->Mat[chooseY][chooseX] > -1 && M->Mat[chooseY][chooseX] <= 9) printf(" %d", M->Mat[chooseY][chooseX]);
					else if(M->Mat[chooseY][chooseX] > -1) printf("%d", M->Mat[chooseY][chooseX]);
					else printf("__");
					
					gotoxy(24, 3);
					printf("                        ");
					
					typeX = 0;
					totalInput = 0;
					emptyArr(userInput);
					
					break;
				}
				
				hidecursor();
				gotoxy(17 + chooseX * 4 + typeX, 6 + chooseY * 2);
				printf("%c", input);
				
				if(!isdigit(input) && input != 13 && input !=27) {
					hidecursor();
					
					gotoxy(16, 17);
					red();
					printf("Input tidak sesuai!");
					sleep(1.5);
					white();
					gotoxy(16, 17);
					printf("                     ");
					
					gotoxy(24, 3);
					printf("                        ");
					
					gotoxy(17 + chooseX * 4, 6 + chooseY * 2);
					printf("__ ");
					
					typeX = 0;
					totalInput = 0;
					emptyArr(userInput);
					
					continue;
				}
				else inputSave = input;
				
				if(isdigit(inputSave)) {
					typeX++;
					userInput[totalInput] = input;
					totalInput++;
				}
				
				if(atoi(userInput) > 50 || totalInput == 3){
					gotoxy(16, 17);
					red();
					printf("Input melebihi range!");
					sleep(1.5);
					white();
					gotoxy(16, 17);
					printf("                     ");
						
					gotoxy(17 + chooseX * 4, 6 + chooseY * 2);
					printf("__ ");
					
					totalInput = 0;
					emptyArr(userInput);
					typeX = 0;
					inputSave = ' ';
					
					continue;
				}
				
				if(input == 13 && totalInput > 0) {
					M->Mat[chooseY][chooseX] = atoi(userInput);
					
					if(M->Mat[chooseY][chooseX] <= 9) {
						gotoxy(17 + chooseX * 4, 6 + chooseY * 2);
						printf(" %d", M->Mat[chooseY][chooseX]);
					}
					
					gotoxy(19, 17);
					green();
					if(isInputMenu) printf("Input berhasil!");
					else printf("Edit berhasil!");
					sleep(1.5);
					white();
					gotoxy(19, 17);
					printf("               ");
					
					gotoxy(24, 3);
					printf("                        ");
					
					emptyArr(userInput);
					inputSave = ' ';
					totalInput = 0;
					typeX = 0;
					
					break;
				}
			}
		}
	}
}
