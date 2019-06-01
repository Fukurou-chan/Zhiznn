#include "jiznn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
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
    struct murv mur[20];
    struct murv ev_mur[20];
    int i, j;
    mur[0].klass = 9; //êëàññ êîðîëåâû 9 , à ñàìà îíà ñ÷èòàåòñÿ 0-ûì ìóðàâüžì
    mur[0].energy = 10000;
    ev_mur[0].klass = 4; //êëàññ êîðîëåâû 9 , à ñàìà îíà ñ÷èòàåòñÿ 0-ûì ìóðàâüžì
    ev_mur[0].energy = 10000;
    int ForKamni = 3;
    int kamni = 10; /*камушки*/
    int ForVetki = 3;
    int vetki = 40; /*ветки*/
    int list = 80;  /*листики*/
    int ev = 2;     /*Злые*/
    int murv = 3;
    int y = 1;  /*Рабочие*/
    int freekl; /*количество свободных клеток*/
    int index = 0;
    int table[16][16];

    printf("%s%sm", CSI, colors[11]);

    printf("  ~Welcome to murvs life~ \n");
    printf("%s0m", CSI); // return normal text color
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j++) {
            table[i][j] = rand() % 4;

            switch (table[i][j]) {
            case 0:
                if ((ForKamni != 0) && (kamni != 0)
                    && (table[i][j] != table[i + 1][j + 1])
                    && (table[i][j] != table[i][j + 1])
                    && (table[i][j] != table[i + 1][j])) {
                    printf("%s%sm", CSI, colors[2]);
                    printf("O ");
                    printf("%s0m", CSI);
                    ForKamni--;
                    kamni--;
                } else {
                    table[i][j] = 1;
                    printf("%s%sm", CSI, colors[1]);
                    printf(". ");
                    table[i][j] = 1;
                    printf("%s0m", CSI);
                    freekl++;
                }
                break;

            case 1: {
                printf("%s%sm", CSI, colors[1]);
                printf(". ");
                printf("%s0m", CSI);
                freekl++;
            } break;

            case 2:
                if (((ForVetki != 0) && (vetki != 0))
                    && (table[i][j] != table[i][j + 1])
                    && (table[i][j] != table[i + 1][j])
                    && (table[i][j] != table[i][j + 2])) {
                    printf("%s%sm", CSI, colors[7]);
                    printf("| ");
                    printf("%s0m", CSI);
                    ForVetki--;
                    vetki--;
                } else {
                    printf("%s%sm", CSI, colors[5]);
                    printf("* ");
                    table[i][j] = 3;
                    printf("%s0m", CSI);
                    freekl++;
                }
                break;

            case 3:
                if (list != 0) {
                    printf("%s%sm", CSI, colors[5]);
                    printf("* ");
                    printf("%s0m", CSI);
                    list--;
                } else {
                    printf("%s%sm", CSI, colors[1]);
                    printf(". ");
                    table[i][j] = 1;
                    printf("%s0m", CSI);
                    freekl++;
                }
                break;

            case 4:
                if ((ev != 0) && (i < 5)) {
                    printf("%s%sm", CSI, colors[3]);
                    printf("x ");
                    printf("%s0m", CSI);
                    ev--;

                } else {
                    printf("%s%sm", CSI, colors[1]);
                    printf(". ");
                    table[i][j] = 1;
                    printf("%s0m", CSI);
                    freekl++;
                }
                break;

            case 8:
                if ((murv != 0) && (i > 10) && (table[i][j] != table[i][j + 1])
                    && (y != 0)) {
                    printf("%s%sm", CSI, colors[11]);
                    printf("m ");
                    printf("%s0m", CSI);
                    murv--;
                    y--;
                } else {
                    printf("%s%sm", CSI, colors[5]);
                    printf("* ");
                    table[i][j] = 3;
                    printf("%s0m", CSI);

                    freekl++;
                }
                break;

            case 9:
                printf("%s%sm", CSI, colors[6]);
                printf("Q ");
                printf("%s0m", CSI);
                break;
            }
        }
        printf("\t \n");
        ForKamni = 2;
        ForVetki = 2;
        y = 1;
    }
    table[15][15] = mur[0].klass;
    table[15][14] = 2;
    table[15][13] = 2;
    table[4][8] = ev_mur[0].klass;
    mur[2].energy = 15;
    mur[2].buff = 1;
    mur[2].mem_i = 0;
    mur[2].mem[0].x = 15;
    mur[2].mem[0].y = 14;
    table[1][7] = mur[2].klass = 2 + 10;
    while (1) {
        system("clear");
        for (i = 0; i < 16; i++) {
            for (j = 0; j < 16; j++) {
                if (table[i][j] > 10) {
                    printf("%s%sm", CSI, colors[11]);
                    printf("m ");
                    printf("%s0m", CSI);
                }
                switch (table[i][j]) {
                case 0:

                    printf("%s%sm", CSI, colors[2]);
                    printf("O ");
                    printf("%s0m", CSI);

                    break;

                case 1:
                    printf("%s%sm", CSI, colors[1]);
                    printf(". ");
                    printf("%s0m", CSI);

                    break;

                case 2:

                    printf("%s%sm", CSI, colors[7]);
                    printf("| ");
                    printf("%s0m", CSI);

                    break;

                case 3:

                    printf("%s%sm", CSI, colors[5]);
                    printf("* ");
                    printf("%s0m", CSI);
                    list--;

                    break;

                case 4:

                    printf("%s%sm", CSI, colors[3]);
                    printf("x ");
                    printf("%s0m", CSI);

                    break;

                case 9:
                    printf("%s%sm", CSI, colors[6]);
                    printf("Q ");
                    printf("%s0m", CSI);
                    break;
                }
            }
            printf("\t \n");
        }

        char n;
        scanf("%c", &n);
        if (n == 'q')
            return 0;
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) {
                hod(table, j, i, &index, mur);
            }
        }
    }
}