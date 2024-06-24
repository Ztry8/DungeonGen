# DungeonGen
## Dungeon generator for roguelikes created with less than 35 lines of code!
### This code is written in pure C99. Used the stdio to display a map.
![screenshot](https://github.com/Ztry8/DungeonGen/blob/main/screenshots/newver.PNG)

#### Building
The project has only one file, so you can build it with a single command:   
```clang -std=c99 -Wall -Wextra -pedantic main.c -o generator.exe```

#### Input data
Before running the generation, you need to provide the program with three arguments:   
the width, the height, and the percentage of floor tiles in relation to all tiles.   
For example:

75x50 size, 50% of the floor tiles compared to all tiles.   
![screenshot](https://github.com/Ztry8/DungeonGen/blob/main/screenshots/50per.PNG)

75x50 size, 25% of the floor tiles compared to all tiles.   
![screenshot](https://github.com/Ztry8/DungeonGen/blob/main/screenshots/25per.PNG)

#### TODO
- [x] Fixed the bug with generating a map outside the boundary.
- [x] Added the input for the width, height and percentage of floor tiles in relation to all tiles. 
- [x] Replaced stack with the heap.
- [x] Added corridors and rooms.
- [ ] Create larger rooms.
- [ ] Add ```<; >; $; *;``` tiles.
