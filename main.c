#include"jiznn.h"

int itas();
int auf();


int	main(){

	struct murv mur[20];
	mur[0].klass = 9;
	mur[0].energy = 6;
	int index = 0;
	int table[16][16];
	for( int i = 0; i < 16; i++) {
	for(int j = 0; j < 16; j++) {
		 table[i][j] = rand()%5;
	}
	}
	table[13][4] = mur[0].klass;
	while(1){
	
	for(int i = 0; i < 16; i++){
		 for(int j = 0; j < 16; j++){
		switch(table[i][j]){
			  case 0:
			printf(". ");
			break;
			  case 1:
			printf("O ");
			break;
			  case 2:
			printf("| ");
			break;
			  case 3:
			printf("x ");
			break;
			case 8:
				printf("8");
				if (table[i + 1][j] == 3) {
					myhod(table[i][j], table[i + 1][j]);
				} else { if (table[i][j + 1] == 3) {
					myhod(table[i][j], table[i][j + 1]);
				} else { if (table[i - 1][j] == 3) {
					myhod(table[i][j], table[i - 1][j]);
				} else { if (table[i - 1][j - 1] == 3) {
					myhod(table[i][j], table[i - 1][j - 1]);
				}
				
				//the search alg
				int r = 1;//search radius
				//int *addr0 = *(*(pozition - r) - r);//zero search address
				//int adrr0;
				//int limit_sum = limit^2 - 1;//ограничение для поиска (общее)
				//int lr = 0; int ud = 0; int rl = 0; int du = 0; /*lr - left to right,
				/*ud - up to down, rl - right to left, du - down to up*/
				int s_count = 0;
				int s_lim = 20;
				int stick[2][s_lim];
				
				for (int r_l = 1; r_l <= r && s_count < s_lim; r_l++) /*r_l - local radius*/ {
					//l_r_l - the local radius limit, i_l - local 'i'
					//j_l - local 'j'
					int l_r_l = r_l * 2 + 1;
					int i_l = i - r_l;
					int j_l = j - r_l;
					
					for (int c_l = 0, j_l; c_l < l_r_l && s_count < s_lim
						&& auf(i_l, j_l, i, j); c_l++, j_l++) {
						if (itas(table[i_l][j_l])) {
							stick[0][s_count] = i_l;
							stick[1][s_count] = j_l;
							s_count++;
						}
					}
				if (s_count >= s_lim) {
					break;
				}
						for (int c_l = 0, i_l; c_l < l_r_l - 1 && s_count < s_lim
						&& auf(i_l, j_l, i, j); c_l++, i_l--) {
							if (itas(table[i_l][j_l])) {
								stick[0][s_count] = i_l;
								stick[1][s_count] = j_l;
								s_count++;
							}
						}
				if (s_count >= s_lim) {
					break;
				}
				for (int c_l = 0, j_l; c_l < l_r_l - 1 && s_count < s_lim
						&& auf(i_l, j_l, i, j); c_l++, j_l--) {
					if (itas(table[i_l][j_l])) {
							stick[0][s_count] = i_l;
							stick[1][s_count] = j_l;
							s_count++;
						}
				}
				if (s_count >= s_lim) {
					break;
				}
				for (int c_l = 0, i_l; c_l < l_r_l - 1 && s_count < s_lim
						&& auf(i_l, j_l, i, j); c_l++, i_l++) {
					if (itas(table[i_l][j_l])) {
							stick[0][s_count] = i_l;
							stick[1][s_count] = j_l;
							s_count++;
						}
					}
					if (s_count >= s_lim) {
						break;
					}
				}
				
				
				int sum[s_lim];
				for (int c_l = 0; c_l < s_lim; c_l++) {
				for (int r_l = 1; r_l <= r; r_l++) {
					int l_r_l = r_l * 2 + 1;
					int i_l = i - r_l;
					int j_l = j - r_l;
					//4 raza napisatt for
					for (int c_l = 0, i_l; c_l < l_r_l - 1
						&& auf(i_l, j_l, i, j); c_l++, i_l++) {
							sum[c_l] += table[i_l][j_l];
						}
				}
				}
				int prior[2];
				int tmp = 0;
				for (int c_l = 0; c_l < s_lim; c_l++) {
					if (tmp > sum[c_l]) {
						tmp = sum[c_l];
						prior[0] = stick[0][c_l];
						prior[1] = stick[1][c_l];
					}
				}
				
				int i_g = i;
				int j_g = j;
				if (i_g == 0 || j_g == 0) {
					i_g++;
					j_g++;
				}
				
				float num1 = j_g / i_g + i_g % j_g;
				float num2 = i_g / j_g + j_g % i_g;
				if (num1 == 1 || num2 == 1) {
					if (j_g > 0) {
						myhod(table[i][j], table[i][j + 1]);
					} if (j_g < 0) {
						myhod(table[i][j], table[i][j - 1]);
					}
				}
				if (num1 > num2 && j_g > 0) {
					myhod(table[i][j], table[i][j + 1]);
				} else { if (num2 > num1 && i_g > 0) {
					myhod(table[i][j], table[i + 1][j]);
				} else { if (num1 > num2 && j_g < 0) {
					myhod(table[i][j], table[i][j - 1]);
				} else { if (num1 > num2 && j_g < 0) {
					myhod(table[i][j], table[i - 1][j]);
				}
				}
				}
				}
				
				
			break;
			//case 9:
			//printf("Q ");
			//break;
		}	
		 }
		 printf("\n");
	}
	int a;
	scanf("%d", &a);
	
	
	}

}
    }
    }
return 0;
}

//Is This A Stick?
int itas(int c) {
	if (c == 2) {
		return 1;
	}
	
	return 0;
}

//Another Unuseless Function
//This function checks points for correctness of location in the limit
int auf(int i_l, int j_l, int i, int j)  {
	if (j_l >= 0 && j_l <= j && i_l >= 0 && i_l <= i) {
		return 1;
	}
	return 0;
}