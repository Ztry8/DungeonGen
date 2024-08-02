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
	unsigned char* map = calloc(width * height, sizeof(unsigned char)); if (map == NULL) return 1;
	memset(map, '#', width * height * sizeof(unsigned char));
	int px = rand() % width, py = rand() % height, floor_tiles = (width * height)/4, tunnel_length = 0, tunnel_dir = 0; 
	map[py * width + px] = '<';

	while (floor_tiles) {
		switch (tunnel_length ? tunnel_dir : rand() % 5) {
		case 0: px + 1 == width-1 ? px-- : px++; break;
		case 1: px - 1 == 0 ? px++ : px--; break;
		case 2: py + 1 == height-1 ? py-- : py++; break;
		case 3: py - 1 == 0 ? py++ : py--; break;
		case 4: tunnel_dir = rand() % 4; tunnel_length = rand()%((tunnel_dir <= 1 ? width : height) / 5); break; 
		}	
		if (tunnel_length) tunnel_length--;
		else floor_tiles--;
		if (map[py * width + px] == '#') map[py * width + px] = '.';
	};

	for (int i = 0; i < scale; i++) {
		int index = (rand()%(int)(height)) * width + (rand()%(int)(width*0.9f));
		if (map[index] == '.') {
			map[index] = 'Z';
			if (i < scale/10) map[index] = '!';
		}
		else i--;
	}
	
	// Output map
	FILE *img = fopen("map.pbm", "wb");

	if (img == NULL) {
		for (int y = 0; y < height; y++) { 
			for (int x = 0; x < width; x++) putchar(map[y * width + x]); 
			putchar('\n'); 
		}
		puts("The error occurs when opening/creating the \'map.pbm\' file, the map will be displayed in the console!");
	}
	else {
		fprintf(img, "P3\n%d %d\n255\n", width, height);
		for (int i = 0; i < width * height; i++) {
			switch (map[i]) {
			case '#': fputs("127 127 127 ", img); break;
			case '.': fputs("0 0 0 ", img); break;
			case 'Z': fputs("255 0 0 ", img); break;
			case '!': fputs("255 255 0 ", img); break;
			case '<': fputs("0 0 255 ", img); break; 
			default: break;
			}
		}
		
		puts("Done! See map.pbm file.");
		fclose(img);
	}

	free(map); 
	return 0;
}