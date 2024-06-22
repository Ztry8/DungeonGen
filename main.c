#include <stdio.h>
#include <time.h>
#include <stdlib.h>

signed main(void) {
	int width, height;
	float floor_percent;

	puts("Enter the width, height, and percentage of floor tiles to all tiles:");
	scanf("%d%d%f", &width, &height, &floor_percent);

	srand((unsigned)time(NULL)); int map[width][height];
	for (int y = 0; y < height; y++) { for (int x = 0; x < width; x++)  map[x][y] = '#'; }

	int px = rand() % width, py = rand() % height, floor_tiles = 0;
	while ((int)(floor_percent / 100.f * (width * height)) >= floor_tiles) {
		switch (rand() % 4) {
		case 0: px+1 >= width ? px-- : px++; break;
		case 1: px-1 <= 0 ? px++ : px--; break;
		case 2: py+1 >= height ? py-- : py++; break;
		case 3: py-1 <= 0 ? py++ : py--; break;
		}

		if (map[px][py] == '#') map[px][py] = '.', floor_tiles++;
	};

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) putchar(map[x][y]);
		putchar('\n');
	};

	return 0;
}
