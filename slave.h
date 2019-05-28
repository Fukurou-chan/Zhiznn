int itas();

void slave(int *pozition) /*get an ant's pozition address*/ {
	//sneak-like search
	int r = 1;//search radius
	int *addr0 = *(*(pozition - r) - r);//zero search address
	//int limit_sum = limit^2 - 1;//ограничение для поиска (общее)
	int lr = 0; int ud = 0; int rl = 0; int du = 0; /*lr - left to right,
	ud - up to down, rl - right to left, du - down to up*/
	//int stick = 0;//ветка найдена? (0/1)
	int s_count = 0;
	int s_lim = 8;
	int stick[stick_lim];
	
	for (int r_l = 1; r_l <= r && s_count < s_lim; r_l++) /*r_l - local radius */ {
			for (lr = 0; lr < r_l * 2 + 1; lr++) {
				if (itas(int tmp_add = *(*(addr0 + lr) + ud))) {
					stick[s_count] = tmp_add;
					stick_count++;//продолжать переделывать как и здесь
				}
			}
			if (s_count >= s_lim - 1) {
				break;
			}
			for (ud = 0; ud < r_l * 2 + 1; ud++) {
				if (itas(*(*(addr0 + lr) + ud))) {
					stick[s_count]++;
					s_count++;
				}
			}
			if (s_count >= s_lim - 1) {
				break;
			}
			for (lr = 0; lr < r_l * 2 + 1; lr++) {
				if (itas(*(*(addr0 + lr) + ud))) {
					stick[s_count]++;
					s_count++;
				}
			}
			if (s_count >= s_lim - 1) {
				break;
			}
			for (lr = 0; lr < r_l * 2 + 1; lr++) {
				if (itas(*(*(addr0 + lr) + ud))) {
					stick[s_count]++;
					s_count++;
				}
			}
			if (s_count >= s_lim - 1) {
				break;
			}
	}
}

int itas(int p) /*Is This A Stick?*/ {
	if (p == 3) {
		return 1;
	}
	return 0;
}