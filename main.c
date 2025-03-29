#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

const int SIZE = 30;

signed main(void) {
	srand((unsigned)time(NULL)); unsigned char* map = calloc(SIZE * SIZE, sizeof(unsigned char)); 
        if (map == NULL) return 1; memset(map, '#', SIZE * SIZE * sizeof(unsigned char));
	int px = rand() % SIZE, py = rand() % SIZE, floor_tiles = (SIZE * SIZE)/3, tunnel_length = 0, tunnel_dir = 0; 
        
	while (floor_tiles) {
		switch (tunnel_length ? tunnel_dir : rand() % 8) {
		case 0: px + 1 == SIZE-1 ? px-- : px++; break;
		case 1: px - 1 == 0 ? px++ : px--; break;
		case 2: py + 1 == SIZE-1 ? py-- : py++; break;
		case 3: py - 1 == 0 ? py++ : py--; break;
		default: tunnel_dir = rand() % 4; tunnel_length = rand()%(SIZE / 5); break; 
		}	
  
	      if (map[py * SIZE + px] == '#') map[py * SIZE + px] = '.';
	      if (tunnel_length) tunnel_length--;
	      else floor_tiles--;
	};
        
        char last = 'Z';
	for (int i = 0; i < SIZE;) {
		int index = rand()%(SIZE * SIZE);
		if (map[index] == '.') { 
		    map[index] = i < SIZE/2 && last != '!' ? '!' : 'Z'; 
		    last = map[index];
		    i++; 
		}
	}
	
	map[py * SIZE + px] = '<';
	
	// Output map
	FILE *img = fopen("map.pbm", "wb");

	if (img == NULL) {
		for (int y = 0; y < SIZE; y++) { 
			for (int x = 0; x < SIZE; x++) putchar(map[y * SIZE + x]); 
			putchar('\n'); 
		}
		puts("The error occurs when opening/creating the \'map.pbm\' file, the map will be displayed in the console!");
	} else {
		fprintf(img, "P3\n%d %d\n255\n", SIZE, SIZE);
		for (int i = 0; i < SIZE * SIZE; i++) {
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
