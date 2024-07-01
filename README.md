# DungeonGen
## Dungeon generator for roguelikes written in pure C99! 
![screenshot](https://github.com/Ztry8/DungeonGen/blob/main/screenshots/1.png)

### Building
The project has only one file, so you can build it with a single command:   
```clang -std=c99 -Wall -Wextra -pedantic main.c -o generator```

### Designation
`<` - exit   
`E` - enemy   
`$` - money   
`*` - chest

### Input data
Before running the generation, you need to provide the program `scale` argument.   
For example:

Scale = 10 or 40x30 size:   
![screenshot](https://github.com/Ztry8/DungeonGen/blob/main/screenshots/10s.png)

Scale = 25 or 100x75 size:   
![screenshot](https://github.com/Ztry8/DungeonGen/blob/main/screenshots/25s.png)

### Time
The time to generate a map with a scale of 100 (300x200 tiles) is 0.026 seconds.
If the program was built by the command in the `Building` section.

### TODO
- [x] Fixed the bug with generating a map outside the boundary.
- [x] Added the input for scale. 
- [x] Replaced stack with the heap.
- [x] Added corridors and rooms.
- [ ] Add ```<; E; $; *;``` tiles.
- [ ] Optimize for large areas.