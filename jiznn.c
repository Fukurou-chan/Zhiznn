#include"jiznn.h"

void napoln(int table[16][16]){

    for(int i = 0; i < 16; i++){
	for(int j = 0; j < 16; j++){
	    table[i][j] = rand()%5;
	}
    }
}

void myhod(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}