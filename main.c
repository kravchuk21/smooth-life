#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WEIDTH 10
#define HEIGHT 10

float grid[HEIGHT][WEIDTH] = {0};

float rand_float(void) {
    return (float)rand()/(float)RAND_MAX;
}

int main(void) {
    srand(time(0));

    for (size_t y = 0; y < HEIGHT; ++y) {
        for (size_t x = 0; x < HEIGHT; ++x) {
            grid[y][x] = rand_float();
        }
    }

    for (size_t y = 0; y < HEIGHT; ++y) {
        for (size_t x = 0; x < HEIGHT; ++x) {
            printf("%f ", grid[y][x]);
        }
        printf("\n");
    }

    return 0;
}
