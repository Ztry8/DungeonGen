# DungeonGen
## Fast and simple level generator for roguelikes written in pure C99/Rust! 
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
```clang -std=c99 -Wall -Wextra -pedantic main.c -o generator``` (For Rust: ```cargo run```)


### Time
The time to generate a map with a scale of 100 (300x200 tiles) is range from 0.002 to 0.003 seconds.
If the program was built by the command in the `Building` section.


### TODO
- [x] Fixed the bug with generating a map outside the boundary.
- [x] Added the input for scale. 
- [x] Replaced stack with the heap.
- [x] Added corridors and rooms.
- [x] Added ```<; E; *;``` tiles.
- [x] Added image support
- [x] Add Rust version


### Results
![screenshot](https://github.com/Ztry8/DungeonGen/blob/main/screenshots/5.png)
![screenshot](https://github.com/Ztry8/DungeonGen/blob/main/screenshots/4.png)
![screenshot](https://github.com/Ztry8/DungeonGen/blob/main/screenshots/1.png)
![screenshot](https://github.com/Ztry8/DungeonGen/blob/main/screenshots/3.png)
