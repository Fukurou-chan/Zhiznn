#include <stdio.h>
#define CSI "\x1B\x5B"
#include <string.h>
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
    char text[] = "From dawn till dusk";
    int m = strlen(text);
    
   int i;
   printf("%s%sm", CSI, colors[9]);
   for (i = 0; i<5; i++)
       printf ("%c", text[i]);
   for (i = 5; i < m; i++)
       {
          printf("%c", text[i]);
          printf("%s0m", CSI);
	  
            
        }
    
   
   printf ("\n");
   
   printf("%s%sm", CSI, colors[13]);
   printf ("* ");
   printf("%s0m", CSI);
        

}




