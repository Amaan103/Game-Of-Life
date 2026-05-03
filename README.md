# Conway's Game of Life (SDL2)

A visual implementation of Conway's Game of Life written in C using the SDL2 library. This version features a unique **age-based coloring system** that makes the simulation more dynamic and interesting to watch!

## Demo

<p align="center">
  <img width="800" height="533" alt="gameoflife" src="https://github.com/user-attachments/assets/6ab1ebae-7531-4682-916f-48f978d5e5b9" />
</p>

## Features

- **Classic Cellular Automaton**: Implements standard Conway's Game of Life rules with a wrap-around (toroidal) grid.
- **Age-Based Coloring**: Cells change colors dynamically based on how long they have survived:
  - 🟢 **Young (< 5 generations)**: Bright neon green (Newborns, moving gliders)
  - 🔵 **Medium (< 20 generations)**: Cyan/Blue (Oscillators)
  - 🟣 **Old (< 50 generations)**: Purple (Starting to settle)
  - ⚪ **Very Old (50+ generations)**: Bright white (Static patterns, blocks, beehives)
- **Randomized Start**: The world is initially seeded with a random state of living and dead cells.

## Rules of the Game

The universe of the Game of Life is a two-dimensional orthogonal grid of square cells, each of which is in one of two possible states, *alive* or *dead*. Every cell interacts with its eight neighbors, which are the cells that are horizontally, vertically, or diagonally adjacent. At each step in time, the following transitions occur:

1. **Birth**: A dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
2. **Survival (Alive)**: A live cell with two or three live neighbors lives on to the next generation.
3. **Death**:
   - *Underpopulation*: A live cell with fewer than two live neighbors dies.
   - *Overpopulation*: A live cell with more than three live neighbors dies.

## Requirements

To compile and run this project, you will need:
- A C compiler (e.g., GCC, Clang)
- [SDL2 Library](https://libsdl.org/) development files installed

## How to Compile

Using GCC on Linux or macOS (assuming SDL2 is installed system-wide):

```bash
gcc gameoflife.c -o gameoflife -lSDL2
```

Using MinGW on Windows (assuming SDL2 is in your include/lib paths):

```bash
gcc gameoflife.c -o gameoflife.exe -lmingw32 -lSDL2main -lSDL2
```

## How to Run

Simply execute the compiled binary. The simulation will start automatically.

```bash
./gameoflife
```

Close the window to exit the application.
