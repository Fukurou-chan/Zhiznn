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
	if(table[y][x] > 10) logic_murv(table,murv,x,y);
}


void logic_qeen(int table[16][16], int *index, struct murv *murv){
	if((table[15][14] == 2) && (table[15][13] == 2) ) {
		*index = *index + 1;
		printf("%d" , *index);
		table[15][13] = 1;
		murv[*index].energy = 15;
		murv[*index].buff = 1;
		murv[*index].mem_i = 0;
		murv[*index].mem[0].x = 15;
		murv[*index].mem[0].y = 14;
		table[15][14] = murv[*index].klass = *index + 10;
		printf("I'am born! I dream a working! Let's start!");
	}
	if((table[14][15] == 2) && (table[13][15] == 2) ) {
		*index = *index + 1;
		table[13][15] = 1;
		murv[*index].energy = 15;
		murv[*index].buff = 1;
		murv[*index].mem_i = 0;
		murv[*index].mem[0].x = 15;
		murv[*index].mem[0].y = 14;
		table[14][15] = murv[*index].klass = *index + 10;
		printf("I'am born! I dream a working! Let's start!");
	}
}
int obzor(int table[16][16],int x,int y){
	int up = 0,left = 0, right = 0, down = 0, max = 0;
	for(int i = 0; i  < 2; i++){
		for(int j = 0; j < 4; j++){
			int o = y-2-i;
			int p = x-2-j;
			if((o > 16) || (p > 16) || (o < 0) || (p < 0)) up = -1;
			int buf = table[y-2+i][x-2+j];
			switch(buf){
				case 2: 
					up = up + 5; 			
			}	
		if(up == -1) break;
		if(up > max) max = up;
		}
	}
	for(int i = 0; i  < 2; i++){
		for(int j = 0; j < 4; j++){
			int o = y-2-j;
			int p = x-2-i;
			if((o > 16) || (p > 16) || (o < 0) || (p < 0)) left = -1;
			int buf = table[y-2+j][x-2+i];
			switch(buf){
				case 2: 
					left = left + 5; 			
			}	
		if(left == -1) break;
		if(left > max) left = down;
		}
	}
	for(int i = 0; i  < 2; i++){
		for(int j = 0; j < 4; j++){
			int o = y-2-i;
			int p = x-2-j;
			if((o > 16) || (p > 16) || (o < 0) || (p < 0)) right = -1;
			int buf = table[y-2+j][x+2-i];
			switch(buf){
				case 2: 
					right = right + 5; 			
			}	
		if(right == -1) break;
		if(right > max) max = right;
		}
	}	
	for(int i = 0; i  < 2; i++){
		for(int j = 0; j < 4; j++){
			int o = y-2-i;
			int p = x-2-j;
			if((o > 16) || (p > 16) || (o < 0) || (p < 0)) down = -1;
			int buf = table[y+2-i][x-2+j];
			switch(buf){
				case 2: 
					down = down + 5; 			
			}	
		if(down == -1) break;
		if(down > max) max = down;
		}
	}

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
}
void logic_murv(int table[16][16], struct murv *murv,int x, int y){
	int n = table[y][x] - 10;
	int mem_i = murv[n].mem_i;
	if(murv[n].energy == 0) {
		table[y][x] = murv[n].buff;
		murv[n].buff = 0;
		for(int i = 0; i < 20;i++){
			murv[n].mem[i].x = 0;
			murv[n].mem[i].y = 0;
		}
	}
	switch(obzor(table,x,y)){
		case 0:
			mem_i++;
		        table[y][x] =  murv[n].buff;
			murv[n].buff = table[y-1][x];
			table[y-1][x] = murv[n].klass;
			murv[n].mem[mem_i].x = x;
			murv[n].mem[mem_i].y = y-1;
		case 1:
			mem_i++;
		        table[y][x] =  murv[n].buff;
			murv[n].buff = table[y][x-1];
			table[y][x-1] = murv[n].klass;
			murv[n].mem[mem_i].x = x-1;
			murv[n].mem[mem_i].y = y;
		case 2:
			mem_i++;
		        table[y][x] =  murv[n].buff;
			murv[n].buff = table[y][x+1];
			table[y][x+1] = murv[n].klass;
			murv[n].mem[mem_i].x = x+1;
			murv[n].mem[mem_i].y = y;
		case 3:
			mem_i++;
		        table[y][x] =  murv[n].buff;
			murv[n].buff = table[y+1][x];
			table[y+1][x] = murv[n].klass;
			murv[n].mem[mem_i].x = x;
			murv[n].mem[mem_i].y = y+1;
		default:
			printf("Error");
	
	}


}
