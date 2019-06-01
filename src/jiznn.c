#include"jiznn.h"

void napoln(int table[16][16]){
	int x,y;
	a:
    x = rand()%15;
    y = rand()%15;
    if(table[x][y] == 1){
    	table[x][y] = 2;
	}
	else{
		goto a;	
	}
}
void hod(int table[16][16],int x,int y,int *index,struct murv *murv){
	
	if(table[y][x] == 9) logic_qeen(table,index,murv);
	if((table[y][x] > 10) && (murv[table[y][x] - 10].flag_hod == 0)) {
		int n = logic_murv(table,murv,x,y);
	//	if(murv[n].flag_vet == 1) murv[n].mem_i--;
		murv[n].flag_hod = 1;
	}
}


void logic_qeen(int table[16][16], int *index, struct murv *murv){
	if((table[15][14] == 2) && (table[15][13] == 2) ) {
		*index = *index + 1;
		printf("%d" , *index);
		table[15][13] = 1;
		murv[*index].energy = 300;
		murv[*index].buff = 1;
		murv[*index].flag_vet = 0;
		murv[*index].mem_i = 0;
		murv[*index].mem[0].x = 14;
		murv[*index].mem[0].y = 15;
		murv[*index].flag_hod = 0;
		napoln(table);
		napoln(table);
		table[15][14] = murv[*index].klass = *index + 10;
		printf("I'am born! I dream a working! Let's start!\n");
	}
	if((table[14][15] == 2) && (table[13][15] == 2) ) {
		*index = *index + 1;
		table[13][15] = 1;
		murv[*index].energy = 300;
		murv[*index].buff = 1;
		murv[*index].flag_vet = 0;
		murv[*index].mem_i = 0;
		murv[*index].mem[0].x = 15;
		murv[*index].mem[0].y = 14;
		murv[*index].flag_hod = 0;
		napoln(table);
		napoln(table);
		table[14][15] = murv[*index].klass = *index + 10;
		printf("I'am born! I dream a working! Let's start!\n");
	}
}
int obzor(int table[16][16],int x,int y,struct murv *murv){
	int up = 0,left = 0, right = 0, down = 0, max = -1;
	for(int i = 0; i  < 1; i++){
		for(int j = 0; j < 3; j++){
			int o = y-1;
			int p = x;
			if((o == murv[table[y][x] - 10].mem[murv[table[y][x] - 10].mem_i].y-1) && (p == murv[table[y][x] - 10].mem[murv[table[y][x] - 10].mem_i].x-1)) up = -1;
			if(((o ==15) && ( p == 14)) || ((o ==15) && ( p == 13))) up = -1;
			if(table[o][p] == 9) up = -1;
			if(table[o][p] > 10) up = -1;
			if((o > 16) || (p > 16) || (o < 0) || (p < 0)) up = -1;
			int buf = table[y-1+i][x-1+j];
			switch(buf){
				case 2: 
					up = up + 5; 			
			}	
		if(up == -1) break;
		
		}
	}
	if(up > max) max = up;
	for(int i = 0; i  < 1; i++){
		for(int j = 0; j < 3; j++){
			int o = y;
			int p = x-1;
			if(((o ==15) && ( p == 14)) || ((o ==15) && ( p == 13))) left = -1;
			if(table[o][p] == 9) left = -1;
			if(table[o][p] > 10) left = -1;
			if((o == murv[table[y][x] - 10].mem[murv[table[y][x] - 10].mem_i-1].y) && (p == murv[table[y][x] - 10].mem[murv[table[y][x] - 10].mem_i-1].x)) left = -1;
			if((o > 16) || (p > 16) || (o < 0) || (p < 0)) left = -1;
			int buf = table[y-1+j][x-1+i];
			switch(buf){
				case 2: 
					left = left + 5; 			
			}	
		if(left == -1) break;
		}
	}
	if(left > max) max = left;
	for(int i = 0; i  < 1; i++){
		for(int j = 0; j < 3; j++){
			int o = y;
			int p = x+1;
			if(((o ==15) && ( p == 14)) || ((o ==15) && ( p == 13))) right = -1;
			if(table[o][p] == 9) right = -1;
			if(table[o][p] > 10) right = -1;
			if((o == murv[table[y][x] - 10].mem[murv[table[y][x] - 10].mem_i-1].y) && (p == murv[table[y][x] - 10].mem[murv[table[y][x] - 10].mem_i-1].x)) right = -1;
			if((o > 16) || (p > 16) || (o < 0) || (p < 0)) right = -1;
			int buf = table[y-1+j][x+1-i];
			switch(buf){
				case 2: 
					right = right + 5; 			
			}	
		if(right == -1) break;
		
		}
	}	
	if(right > max) max = right;
	for(int i = 0; i  < 1; i++){
		for(int j = 0; j < 3; j++){
			int o = y+1;
			int p = x;
			if(((o ==15) && ( p == 14)) || ((o ==15) && ( p == 13))) {
				down = -1;
				break;
			}
			if(table[o][p] == 9) {
				down = -1;
				break;
			}
			if(table[o][p] > 10) {
				down = -1;
				break;
			}
			if((o == murv[table[y][x] - 10].mem[murv[table[y][x] - 10].mem_i-1].y) && (p == murv[table[y][x] - 10].mem[murv[table[y][x] - 10].mem_i-1].x)) {
				down = -1;
				break;
			}
			if((o > 16) || (p > 16) || (o < 0) || (p < 0)) {
				down = -1;
				break;
			}
			int buf = table[y+1-i][x-1+j];
			switch(buf){
				case 2: 
					down = down + 5; 			
			}	
		if(down == -1) break;
		
		}
	}
	if(down > max) max = down;
	if(max < 0) return 4;
	if((max == down) && (max != up) && (max != left) && (max != right)){
		return 3;
	} else if((max == down) && (max == up) ){
		down = down + rand()%100;
		up = up + rand()%100;
		if(up > down) return 0;
		else return 3;
	  } else if((max == down) && (max == left)){
		down = down + rand()%100;
		left = left + rand()%100;
		if(left > down) return 1;
		else return 3;
	    } else if((max == down) && (max == right) ){
		down = down + rand()%100;
		right = right + rand()%100;
		if(right > down) return 2;
		else return 3;
	      }
	if((max == up) && (max != down) && (max != left) && (max != right)){
		return 0;
	} else if((max == up) && (max == left) ){
		left = left + rand()%100;
		up = up + rand()%100;
		if(up > left) return 0;
		else return 1;
	  } else if((max == right) && (max == up) ){
		down = right + rand()%100;
		up = up + rand()%100;
		if(up > right) return 0;
		else return 2;
	  }
	if((max == left) && (max != up) && (max != down) && (max != right)){
		return 1;
	} else if((max == left) && (max == right) ){
		right = right + rand()%100;
		left = left + rand()%100;
		if(left > right) return 1;
		else return 2;
	  }
	if((max == right) && (max != up) && (max != left) && (max != down)){
		return 2;
	}
	return 4;
}
int logic_murv(int table[16][16], struct murv *murv,int x, int y){
	int n = table[y][x] - 10;
	if(murv[n].energy == 0) {
		table[y][x] = murv[n].buff;
		murv[n].buff = 1;
		for(int i = 0; i < 20;i++){
			murv[n].mem[i].x = 0;
			murv[n].mem[i].y = 0;
		}
	}
	if(murv[n].flag_vet == 1){
		
		//printf("   %d%d ", murv[n].mem_i,n);
		table[y][x] =  murv[n].buff;
		murv[n].buff = table[murv[n].mem[murv[n].mem_i].y][murv[n].mem[murv[n].mem_i].x];
		table[murv[n].mem[murv[n].mem_i].y][murv[n].mem[murv[n].mem_i].x] = murv[n].klass;
		murv[n].mem_i--;
		if( (murv[n].mem[murv[n].mem_i].x == 14) && (murv[n].mem[murv[n].mem_i].y == 14) ) {
				murv[n].flag_vet = 0;
				murv[n].buff = 1;
				if(table[15][14] == 1) table[15][14] = 2;
				else table[15][13] = 2;		
					
			} 
		return n;
	}
	switch(obzor(table,x,y,murv)){
		case 0:
			murv[n].mem_i++;
		//	printf("    %d%d ", murv[n].mem_i,n);
		        table[y][x] =  murv[n].buff;
			murv[n].buff = table[y-1][x];
			table[y-1][x] = murv[n].klass;
			murv[n].mem[murv[n].mem_i].x = x;
			murv[n].mem[murv[n].mem_i].y = y-1;
			murv[n].energy--; 
			if(murv[n].buff == 2){
				murv[n].buff = 1;
				murv[n].flag_vet = 1;
				murv[n].mem_i--;
			}
			break;
		case 1:
			murv[n].mem_i++;
		//	printf("   %d%d ", murv[n].mem_i,n);
		        table[y][x] =  murv[n].buff;
			murv[n].buff = table[y][x-1];
			table[y][x-1] = murv[n].klass;
			murv[n].mem[murv[n].mem_i].x = x-1;
			murv[n].mem[murv[n].mem_i].y = y;
			murv[n].energy--;
			if(murv[n].buff == 2){
				murv[n].buff = 1;
				murv[n].flag_vet = 1;
				murv[n].mem_i--;
			}
			break;
		case 2:
			murv[n].mem_i++;
		//	printf("    %d%d ", murv[n].mem_i,n);
		        table[y][x] =  murv[n].buff;
			murv[n].buff = table[y][x+1];
			table[y][x+1] = murv[n].klass;
			murv[n].mem[murv[n].mem_i].x = x+1;
			murv[n].mem[murv[n].mem_i].y = y;
			murv[n].energy--;
			if(murv[n].buff == 2){
				murv[n].buff = 1;
				murv[n].flag_vet = 1;
				murv[n].mem_i--;
			}
			
			break;
		case 3:
			murv[n].mem_i++;
		//	printf("   %d%d ", murv[n].mem_i,n);
		        table[y][x] =  murv[n].buff;
			murv[n].buff = table[y+1][x];
			table[y+1][x] = murv[n].klass;
			murv[n].mem[murv[n].mem_i].x = x;
			murv[n].mem[murv[n].mem_i].y = y+1;
			murv[n].energy--;
			if(murv[n].buff == 2){
				murv[n].buff = 1;
				murv[n].flag_vet = 1;
				murv[n].mem_i--;
			}
		
			break;
		case 4:
			break;
		default:
			printf("Error\n");
	
	}
	return n;

}
