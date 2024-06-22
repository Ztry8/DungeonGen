# DungeonGen
## Dungeon generator for roguelikes made with just 35 lines of code!
### This code is written in pure C99. Use the stdio to display a map.
![screenshot](https://github.com/Ztry8/DungeonGen/blob/main/1.PNG)

#### Building
The project has only one file, so you can build it with a single command:   
```clang -std=c99 -Wall -pedantic main.c -o generator.exe```

#### Input data
Before running the generation, you need to provide the program with three arguments:   
the width, the height, and the percentage of floor tiles in relation to all tiles. 


#### TODO
- [x] Fix the bug with generating a map outside the border.
- [x] Added the input for the width, height and percentage of floor tiles in relation to all tiles. 
- [ ] Replace stack with the heap.
- [ ] Add ```<; >; $; *;``` tiles.
- [ ] Add corridors and rooms.
