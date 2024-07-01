#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define int long 

int min(int a, int b) { return a > b ? b : a; }

signed main(void) {
	int scale; puts("Enter the scale:"); scanf("%ld", &scale); 
	if (scale < 10) { 
		puts("Scale must be more than 10!"); 
		return 1; 
	}

	int width = 3 * scale, height = 2 * scale; srand((unsigned)time(NULL)); 
	int* map = malloc((width * height) * sizeof(int)); if (map == NULL) return 1;
	for (int i = 0; i < height * width; i++) map[i] = '#';
	int px = rand() % width, py = rand() % height, floor_tiles = width * height/3, tunnel_length = 0, tunnel_dir = 0; 
	map[py * width + px] = '<';

	while (floor_tiles--) {
		switch (tunnel_length ? tunnel_dir : rand() % 5) {
		case 0: px + 1 >= width ? px-- : px++; break;
		case 1: px - 1 <= 0 ? px++ : px--; break;
		case 2: py + 1 >= height ? py-- : py++; break;
		case 3: py - 1 <= 0 ? py++ : py--; break;
		case 4: tunnel_dir = rand() % 4; tunnel_length = rand()%((tunnel_dir <= 1 ? width : height) / 5); break; 
		}	
		if (tunnel_length) tunnel_length--;
		if (map[py * width + px] == '#') map[py * width + px] = '.';
	};
	
	for (int i = 0; i < scale; i++) { 
		int room_x = rand()%(int)(width*0.9f), room_y = rand()%(int)(height), room_w = rand()%(width/10), room_h = rand()%(height/10);
		for (int y = room_y; y < min(room_y+room_h, height); y++) { 
			for (int x = room_x; x < min(room_x+room_w, width); x++) map[y * width + x] = '.'; 
		}
	}

	for (int y = 0; y < height; y++) { 
		for (int x = 0; x < width; x++) putchar(map[y * width + x]); 
		putchar('\n'); 
	}

	free(map); 
	return 0;
}