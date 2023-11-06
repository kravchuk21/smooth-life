#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WEIDTH 10
#define HEIGHT 10

char level[] = " .-=coaA@#";
#define level_count (sizeof(level)/sizeof(level[0]) - 1)

float grid[HEIGHT][WEIDTH] = {0};
float ra = 21;
float alpha = 0.028;

float b1 = 0.278;
float b2 = 0.365;
float d1 = 0.267;
float d2 = 0.445;

float rand_float(void) {
    return (float)rand()/(float)RAND_MAX;
}

void random_grid(void) {
    for (size_t y = 0; y < HEIGHT; ++y) {
        for (size_t x = 0; x < HEIGHT; ++x) {
            grid[y][x] = rand_float();
        }
    }
}

int emod(int a, int b) {
    return (a % b + b) % b;
}

void display_grid(void) {
    for (size_t y = 0; y < HEIGHT; ++y) {
        for (size_t x = 0; x < HEIGHT; ++x) {
            char c = level[(int)(grid[y][x]*level_count - 1)];
            printf("%c", c);
        }
        printf("\n");
    }
}

float sigma1(float x, float a) {
    return 1.0f / (1.0f + expf(-(x - a) * 4 / alpha));
}

float sigma2(float x, float a, float b) {
    return sigma1(x, a) * (1 - sigma1(x, b));
}

float sigmam(float x, float y, float m) {
    return x * (1 - sigma1(m, 0.5f)) + y*sigma1(m, 0.5f);
}

float s(float n, float m) {
    return sigma2(n, sigmam(b1, d1, m), sigmam(b2, d2, m));
}

int main(void) {
    srand(time(0));

    random_grid();

    int cx = 0;
    int cy = 0;
    float m = 0, N = 0;
    float n = 0, M = 0;
    float ri = ra/3;

    for (int dy = -(ra - 1); dy <= (ra - 1); ++dy) {
        for (int dx = -(ra - 1); dx <= (ra - 1); ++dx) {
            int x = emod(cx + dx, WEIDTH);
            int y = emod(cy + dx, HEIGHT);
            if (dx*dx + dy*dy <= ri*ri) {
                m  += grid[y][x];
                M += 1;
            }
            else if (dx*dx + dy*dy <= ra*ra) {
                n  += grid[y][x];
                N += 1;
            }
        }
    }

    m /= M;
    n /= N;

    printf("s(n, m) = %f\n", s(n, m));

    return 0;
}
