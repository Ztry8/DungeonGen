#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define WIDTH 150
#define HEIGHT 100
#define FLOOR_PERCENT 45

#define int long

signed main(void) {
	srand((unsigned)time(NULL)); int map[WIDTH][HEIGHT];
	for (int y = 0; y < HEIGHT; y++) { for (int x = 0; x < WIDTH; x++)  map[x][y] = '#'; }

	int px = rand() % WIDTH, py = rand() % HEIGHT, floor_tiles = 0;
	while ((int)(FLOOR_PERCENT / 100.f * (WIDTH * HEIGHT)) >= floor_tiles) {
		switch (rand() % 4) {
		case 0: px++; break;
		case 1: px--; break;
		case 2: py++; break;
		case 3: py--; break;
		}
		if (px >= WIDTH) px--;
		if (py >= HEIGHT) py--;

		if (map[px][py] == '#') map[px][py] = '.', floor_tiles++;
	};

	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) putchar(map[x][y]);
		putchar('\n');
	};

	return 0;
}