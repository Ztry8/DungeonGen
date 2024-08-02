# DungeonGen
## Dungeon generator for roguelikes written in pure C99! 
![screenshot](https://github.com/Ztry8/DungeonGen/blob/main/screenshots/12.png)

### About generator

#### The programmer's part
The program generates [.pbm images](https://en.wikipedia.org/wiki/Netpbm) (or display in console) of the dungeon map for visual perception,   
but the basic generator algorithm simply manipulates a vector of tiles.   
Algorithm based on [this](https://www.roguebasin.com/index.php/Random_Walk_Cave_Generation)    

#### The player's part
This program creates cave-like rooms with corridors.
Could be a cave with mining tunnels!   

### Designation

#### Text mode
`<` - exit   
`Z` - enemy   
`!` - chest

#### Image mode
`blue` - exit   
`red` - enemy   
`yellow` - chest


### Building
The project has only one file, so you can build it with a single command:   
```clang -std=c99 -Wall -Wextra -pedantic main.c -o generator```


### Input data
Before running the generation, you need to provide the program `scale` argument.   
For example:

Scale = 20 or 60x40 size: (text mode)
![screenshot](https://github.com/Ztry8/DungeonGen/blob/main/screenshots/20s.png)

Scale = 35 or 105x70 size: (image mode)
![screenshot](https://github.com/Ztry8/DungeonGen/blob/main/screenshots/21.png)


### Time
The time to generate a map with a scale of 100 (300x200 tiles) is range from 0.008 to 0.011 seconds.
If the program was built by the command in the `Building` section.


### TODO
- [x] Fixed the bug with generating a map outside the boundary.
- [x] Added the input for scale. 
- [x] Replaced stack with the heap.
- [x] Added corridors and rooms.
- [x] Added ```<; E; *;``` tiles.
- [x] Added image support
