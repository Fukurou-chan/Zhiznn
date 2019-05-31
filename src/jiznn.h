#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct memory{
	int x;
	int y;
}memory;

struct  murv{
    int energy;
    int flag_vet;
    int klass;
    struct memory mem[1000];
    int buff;
    int mem_i;
    int flag_hod;
};

void napoln(int table[16][16]);
int logic(int table[16][16],int x, int y);
void hod(int table[16][16],int x,int y,int *index,struct murv *murv);
void logic_qeen(int table[16][16], int *index, struct murv *murv);
int logic_murv(int table[16][16],struct murv *murv,int x, int y);
int obzor(int table[16][16], int x,int y,struct murv *murv);
