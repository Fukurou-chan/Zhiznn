#include <stdio.h>
#define CSI "\x1B\x5B"
#include <string.h>
char colors[][5] = {   /*"Библиотека" возможных цветов*/

        "0;30", /*Чёрный*/
        "1;30",
        /*Тёмно серый*/ "0;31", /*Красный*/
        "1;31",
        /* Жирно-красный(жирный текст красного цвета)*/ "0;32",
        /* Green */ "1;32", /* Bold Green */
                                                              /*Мне лень всё переводить*/
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
    char text[] = "From dawn till dusk";
    int m = strlen(text);
    
   int i;
   printf("%s%sm", CSI, colors[9]);/*Сделает вывод цветным*/
   for (i = 0; i<5; i++)
       printf ("%c", text[i]);
   for (i = 5; i < m; i++)
       {
          printf("%c", text[i]);
          printf("%s0m", CSI); /*Не поставив эту строчку, будет окрашен весь текст*/
      
            
        }
    
   
   printf ("\n");
   
   printf("%s%sm", CSI, colors[13]);
   printf ("* ");
   printf("%s0m", CSI);
        

}



