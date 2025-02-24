# BSQ
language: **C**
compilation: via `Makefile`, including `re`, `clean` and `fclean` rules

## Usage

`./bsq [map.txt] -> To launch the program.`

## Description

The goal of this project is to find the biggest square in a map given in argument.
'.' is a free space.
'o' is an obstacle.

only theese two caracters can be on the map.

- Exemple of a map
```
.ooo..o..o.o.o..o.oo.o........o.oo.o....o.....o...o...oo..o..ooo........o....o........o.o.o...oo.
.o.o.......o...o.o.oo...........o...o.o...oo.o..o..o...o...ooo....oo..ooo......o...............o.
o..o.........o.....oo..ooo.o..o..o....o....o.oo.......oo.....oo.......o.......o..o.ooo.oo........
......oo..oo....o..oo........oo.oo..o.......o..........o......o...o..oo........o..o....o.....o.o.
oo...o.o...oo.o..o.....ooo.o................o..o....ooo.o.o.o....ooooo.o.....o.....o......o..ooo.
..o...o..o..oooo......oo........o.oo....o...o...o..oo..o.o...........o....o......o....oo.o.ooo...
....oo..o...o.o.o.o.o.o........o.o.o..o.oo..o..o.oo......o.o....o.....o.oo.o..o.....o..o.o...o...
..ooo...oo...o..oo....o....oo.oo...o....oo..........ooo................ooo......o..ooo...........
..oo.............o..................ooo..o....o.o....o......o.o.......o......oo.........o.o......
...o.....ooo.o.........ooooo.o...oo..........o..o.....o.ooo..o.........o..oo.......o...ooo..o.oo.
.....o...o..o..o...........o..oo..o.....o.oo.oo..oo................o.....ooo..o......o.....oo..o.
oooo...o............o..oo............oo...oo.....o...o....o.o.o.o.....o.o..oo..................oo
.......oo..o...oo..........o...o....ooo....o..oo...o...o...oo.......oo.oo..............o.....o.o.
.oo.oo....oooo.....o.....o.o.o......o.o....o.....o........o....o.............oo...ooo.......oo..o
...o.o.......oo..o.....o.....o.o...o.oo.......o.o...ooo..........o.o..o...oo.......o.............
.....o...o.oo..o.....o...o..o...oo....oo.o......o..o.....o.oo...o.oo......oo...o...oo...oo.......
..o..oo.....o.o..o..ooo.o....o.o..o......o.....o.oo.......o.o..o..o.o.o...oo......o.......o..oo..
.o.....o...o.oo...oo.o..o....o..o...o......o.....ooo...o....o...........ooo...o....oo..o.......o.
..o....oo..o.o.....o.o..o.o...oo......o...o..o....o.............o..oo..............o....o..o....o
oo......o....o.o...oo...oo.o.......o..o.o...............o..oooo..o.o.......oo..oo..........o...o.
.oo..o.o...oo.......o.o..o.o..o..o...oo..o.oo......o....oo......oo.o.o.........o...oo.o.o.o......
```

the biggest square in this map is represented by 'x' caracters.

```
.ooo..o..o.o.o..o.oo.o........o.oo.o....o.....o...o...oo..o..ooo........oxxxxo........o.o.o...ooo
.o.o.......o...o.o.oo...........o...o.o...oo.o..o..o...o...ooo....oo..oooxxxx..o...............o.
o..o.........o.....oo..ooo.o..o..o....o....o.oo.......oo.....oo.......o..xxxx.o..o.ooo.oo........
......oo..oo....o..oo........oo.oo..o.......o..........o......o...o..oo..xxxx..o..o....o.....o.o.
oo...o.o...oo.o..o.....ooo.o................o..o....ooo.o.o.o....ooooo.o.....o.....o......o..ooo.
..o...o..o..oooo......oo........o.oo....o...o...o..oo..o.o...........o....o......o....oo.o.ooo...
....oo..o...o.o.o.o.o.o........o.o.o..o.oo..o..o.oo......o.o....o.....o.oo.o..o.....o..o.o...o...
..ooo...oo...o..oo....o....oo.oo...o....oo..........ooo................ooo......o..ooo...........
..oo.............o..................ooo..o....o.o....o......o.o.......o......oo.........o.o......
...o.....ooo.o.........ooooo.o...oo..........o..o.....o.ooo..o.........o..oo.......o...ooo..o.oo.
.....o...o..o..o...........o..oo..o.....o.oo.oo..oo................o.....ooo..o......o.....oo..o.
oooo...o............o..oo............oo...oo.....o...o....o.o.o.o.....o.o..oo..................oo
.......oo..o...oo..........o...o....ooo....o..oo...o...o...oo.......oo.oo..............o.....o.o.
.oo.oo....oooo.....o.....o.o.o......o.o....o.....o........o....o.............oo...ooo.......oo..o
...o.o.......oo..o.....o.....o.o...o.oo.......o.o...ooo..........o.o..o...oo.......o.............
.....o...o.oo..o.....o...o..o...oo....oo.o......o..o.....o.oo...o.oo......oo...o...oo...oo.......
..o..oo.....o.o..o..ooo.o....o.o..o......o.....o.oo.......o.o..o..o.o.o...oo......o.......o..oo..
.o.....o...o.oo...oo.o..o....o..o...o......o.....ooo...o....o...........ooo...o....oo..o.......o.
..o....oo..o.o.....o.o..o.o...oo......o...o..o....o.............o..oo..............o....o..o....o
oo......o....o.o...oo...oo.o.......o..o.o...............o..oooo..o.o.......oo..oo..........o...o.
.oo..o.o...oo.......o.o..o.o..o..o...oo..o.oo......o....oo......oo.o.o.........o...oo.o.o.o......
```
