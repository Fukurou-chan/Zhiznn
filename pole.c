int pole () 
{  
int g = 3; int k = 12;/*камушки*/
int v = 3; int w = 40;/*ветки*/
int l = 5; int list = 80; /*листики*/
int ev = 2; /*Злые*/
int murv = 3; int y = 1; /*Рабочие*/ 

int table [16][16];



   for( int i = 0; i < 16; i++) 
   {
        for(int j = 0; j < 16; j++)
        {
        table[i][j] = rand()%6;
    
       table[14][14] = 9;     
       table[14][15] = 15;
       table[14][13] = 15;
       table[13][14] = 15;
       table[13][15] = 15;
       table[13][13] = 15;
       table[15][14] = 15;
       table[15][15] = 15;
       table[15][13] = 15;

        switch (table [i][j])
            {
            case 0:
                if ((g!=0) && (k!=0) && (table[i][j] != table [i+1][j+1]) && (table [i][j] != table [i][j+1]) && (table [i][j] != table [i+1][j])&&(table [i][j] != table [i][j+2]))
                  {
                   printf ("O ");
                   g--;
                   k--;
                  }
                 else printf (". ");
               break;
            
            case 1:
                printf (". ");
                break;
            
            case 2:
                if (((v!=0) && (w!=0)) && ((table[i][j] != table [i+1][j+1])&&(table [i][j] != table [i][j+1])&&(table [i][j] != table [i+1][j])&&(table [i][j] != table [i][j+2])))
                   {
                    printf ("| ");
                    v--;
                    w--;
                   }
                else printf (". ");
                break;
                
            case 3:
                 if ((l != 0)&&(list != 0))
                    {
                        printf ("* ");
                        l--;
                        list--;
                    }
               else printf ("_ ");
                 break;
                 
                 
            case 4:
                  if ((ev != 0) && (i<5))
                    {
                        printf ("x ");
                        ev--;
                    }
               else printf (". ");
                 break;
               
           case 5:
               if ((murv != 0)&&(i > 10)&&(table[i][j] != table [i][j+1])&& (y!=0))
                    {
                        printf ("m ");
                        murv--;
                        y--;
                    }
               else printf (". ");
                 break;
           
           
               
                 case 15:
                     printf ("# ");
                     break;
                
                case 9:
                     printf ("Q ");
                     break;
             
           }
        
        
    }
    printf ("\t \n");
    g = 2;
    v = 2;
    l = 5;
    y = 1;
    }
}

