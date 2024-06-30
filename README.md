# DungeonGen
## Dungeon generator for roguelikes created with less than 35 lines of code!
### This code is written in pure C99. Used the stdio to display a map.
![screenshot](https://github.com/Ztry8/DungeonGen/blob/main/screenshots/1.png)

#### Building
The project has only one file, so you can build it with a single command:   
```clang -std=c99 -Wall -Wextra -pedantic main.c -o generator```

#### Time
The time to generate a map with a scale of 200 (600x400 tiles) is: 
```
real	0m0.767s
user	0m0.022s
sys	0m0.006s
```
If the program was built by the command in the previous section.

#### Designation
`<` - exit   
`E` - enemy   
`$` - money   
`*` - chest
`+` - door

#### Input data
Before running the generation, you need to provide the program `scale` argument.   
Scale = 1 => 4x3 size.
For example:

Scale = 10   
![screenshot](https://github.com/Ztry8/DungeonGen/blob/main/screenshots/10s.png)

Scale = 25   
![screenshot](https://github.com/Ztry8/DungeonGen/blob/main/screenshots/25s.png)

#### TODO
- [x] Fixed the bug with generating a map outside the boundary.
- [x] Added the input for scale. 
- [x] Replaced stack with the heap.
- [x] Added corridors and rooms.
- [x] Add ```<; E; $; *; +;``` tiles.
