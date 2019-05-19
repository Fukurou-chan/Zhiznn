
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define CSI "\x1B\x5B"

char colors[][5] = {

        "0;30",
        "1;30",
        /* Dark Gray */ "0;31", /* Red */
        "1;31",
        /* Bold Red */ "0;32",
        /* Green */ "1;32", /* Bold Green */

        "0;33",
        /* Yellow */ "1;33",
        /* Bold Yellow */ "0;34", /* Blue */

        "1;34",
        /* Bold Blue */ "0;35",
        /* Purple */ "1;35", /* Bold Purple */

        "0;36",
        "1;36"};


int main()
{
    int i, j;
    int ForKamni = 3;
    int kamni = 10; /*камушки*/
    int ForVetki = 3;
    int vetki = 40; /*ветки*/
    int ForList = 5;
    int list = 80; /*листики*/
    int ev = 2;    /*Злые*/
    int murv = 3;
    int y = 1;  /*Рабочие*/
    int freekl; /*количество свободных клеток*/

    int table[16][16];
   
   
    printf("%s%sm", CSI, colors[11]);
   
    printf("  ~Welcome to murvs life~ \n");
     printf("%s0m", CSI); // return normal text color

  

    

    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j++) {
            table[i][j] = rand() % 6;

            table[14][14] = 9;
            table[14][15] = 15;
            table[14][13] = 15;
            table[13][14] = 15;
            table[13][15] = 15;
            table[13][13] = 15;
            table[15][14] = 15;
            table[15][15] = 15;
            table[15][13] = 15;

            switch (table[i][j]) {
            case 0:
                if ((ForKamni != 0) && (kamni != 0) && (table[i][j] != table[i + 1][j + 1])
                    && (table[i][j] != table[i][j + 1])
                    && (table[i][j] != table[i + 1][j])) {
                    printf("O ");
                    ForKamni--;
                    kamni--;
                } else {
                    printf(". ");
                    freekl++;
                }
                break;

            case 1: {
                printf(". ");
                freekl++;
            } break;

            case 2:
                if (((ForVetki != 0) && (vetki != 0)) && (table[i][j] != table[i][j + 1])
                    && (table[i][j] != table[i + 1][j])
                    && (table[i][j] != table[i][j + 2])) {
                    printf("| ");
                    ForVetki--;
                    vetki--;
                } else {
                    printf("* ");
                    freekl++;
                }
                break;

            case 3:
                if (list != 0) {
                    printf("* ");
                    list--;
                } else {
                    printf(". ");
                    freekl++;
                }
                break;

            case 4:
                if ((ev != 0) && (i < 5)) {
                    printf("x ");
                    ev--;

                } else {
                    printf(". ");
                    freekl++;
                }
                break;

            case 5:
                if ((murv != 0) && (i > 10) && (table[i][j] != table[i][j + 1])
                    && (y != 0)) {
                    printf("m ");
                    murv--;
                    y--;
                } else {
                    printf("* ");
                    freekl++;
                }
                break;

            case 15:
                printf("# ");
                break;

            case 9:
                printf("Q ");
                break;
            }
        }
        printf("\t \n");
        ForKamni = 2;
        ForVetki = 2;
        y = 1;
    }
}

