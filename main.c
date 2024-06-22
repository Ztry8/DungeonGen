#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define WIDTH 100
#define HEIGHT 75
#define FLOOR_PERCENT 45

signed main(int argc, char **arg) {
	srand((unsigned)time(NULL)); int map[WIDTH][HEIGHT];
	for (int y = 0; y < HEIGHT; y++) { for (int x = 0; x < WIDTH; x++)  map[x][y] = '#'; }

	int px = rand() % WIDTH, py = rand() % HEIGHT, floor_tiles = 0;
	while ((int)(FLOOR_PERCENT / 100.f * (WIDTH * HEIGHT)) >= floor_tiles) {
		switch (rand() % 4) {
		case 0: px+1 >= WIDTH ? px-- : px++; break;
		case 1: px-1 <= 0 ? px++ : px--; break;
		case 2: py+1 >= HEIGHT ? py-- : py++; break;
		case 3: py-1 <= 0 ? py++ : py--; break;
		}

		if (map[px][py] == '#') map[px][py] = '.', floor_tiles++;
	};

	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) putchar(map[x][y]);
		putchar('\n');
	};

	return 0;
}
