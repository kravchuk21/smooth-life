#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WEIDTH 10
#define HEIGHT 10

char level[] = " .-=coaA@#";
#define level_count (sizeof(level)/sizeof(level[0]) - 1)

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
            char c = level[(int)(grid[y][x]*level_count - 1)];
            printf("%c", c);
        }
        printf("\n");
    }

    return 0;
}
