int itas();

void slave(int *pozition) /*передаём адресс расположения муровья*/ {
	//поиск типа "змейка"
	int r = 1;//радиус поиска
	int *addr0 = *(*(pozition - r) - r);//нулевой адресс поиска
	//int limit_sum = limit^2 - 1;//ограничение для поиска (общее)
	int lr = 0; int ud = 0; int rl = 0; int du = 0; /*lr - слева направо,
	ud - сверху вниз, rl - справа налево, du - снизу вверх*/
	//int stick = 0;//ветка найдена? (0/1)
	int s_count = 0;
	int s_lim = 8;
	int stick[stick_lim];
	
	for (int r_l = 1; r_l <= r && s_count < s_lim; r_l++) /*r_l - "локальный" радиус*/ {
			for (lr = 0; lr < r_l * 2 + 1; lr++) {
				if (itas(*(*(addr0 + lr) + ud))) {
					stick[s_count]++;
					stick_count++;
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

int itas(int p) /*Is This A Stick? - Это палка?*/ {
	if (p == 3) {
		return 1;
	}
	return 0;
}