#include "header.h"

/*
Digunakan untuk merubah warna pada console
biar estetik ygy
*/

void red(){
	printf("\033[1;31m");
}

void white(){
	printf("\033[0;37m");
}

void yellow(){
	printf("\n\033[1;33m");
}

void green(){
	printf("\033[1;32m");
}

void blue(){
	printf("\033[1;34m");
}

void cyan(){
	printf("\033[0;36m");
}
