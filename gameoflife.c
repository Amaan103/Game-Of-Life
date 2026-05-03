#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 60
#define COLS 80
#define SIZE 10 

#undef main 
int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) return 1;
    SDL_Window* win = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, COLS*SIZE, ROWS*SIZE, 0);
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    int world[ROWS][COLS], future[ROWS][COLS];
    srand(time(NULL));
    for(int r=0; r<ROWS; r++) 
        for(int c=0; c<COLS; c++) world[r][c] = rand() % 2;
    int running = 1;
    SDL_Event e;
    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) running = 0;
        }
        SDL_SetRenderDrawColor(ren, 10, 10, 20, 255); 
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 255, 0, 100, 255);
        for(int r=0; r<ROWS; r++) {
            for(int c=0; c<COLS; c++) {
                if(world[r][c]) {
                    
                    SDL_Rect rect = {c*SIZE, r*SIZE, SIZE-1, SIZE-1};
                    SDL_RenderFillRect(ren, &rect);
                }
                int buddy = 0;
                for(int i=-1; i<=1; i++) {
                    for(int j=-1; j<=1; j++) {
                        if(i==0 && j==0) continue;
                        int row = (r + i + ROWS) % ROWS;
                        int col = (c + j + COLS) % COLS;
                        buddy += world[row][col];
                    }
                }
                if (world[r][c]) future[r][c] = (buddy == 2 || buddy == 3);
                else future[r][c] = (buddy == 3);
            }
        }
        for(int r=0; r<ROWS; r++) 
            for(int c=0; c<COLS; c++) world[r][c] = future[r][c];
        SDL_RenderPresent(ren);
        SDL_Delay(70); 
    }
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
