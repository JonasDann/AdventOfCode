//
// Created by Jonas on 24.12.2015.
//

#include "lightGrid.h"

void toggle(int **grid, Rect rect) {
    int x, y;
    for (x = rect.x1; x <= rect.x2; x++) {
        for (y = rect.y1; y <= rect.y2; y++) {
            grid[x][y] = grid[x][y] ? 0 : 1;
        }
    }
}

void toggle2(int **grid, Rect rect) {
    int x, y;
    for (x = rect.x1; x <= rect.x2; x++) {
        for (y = rect.y1; y <= rect.y2; y++) {
            grid[x][y] += 2;
        }
    }
}

void turnOn(int **grid, Rect rect) {
    int x, y;
    for (x = rect.x1; x <= rect.x2; x++) {
        for (y = rect.y1; y <= rect.y2; y++) {
            grid[x][y] = 1;
        }
    }
}

void turnOn2(int **grid, Rect rect) {
    int x, y;
    for (x = rect.x1; x <= rect.x2; x++) {
        for (y = rect.y1; y <= rect.y2; y++) {
            grid[x][y] += 1;
        }
    }
}

void turnOff(int **grid, Rect rect) {
    int x, y;
    for (x = rect.x1; x <= rect.x2; x++) {
        for (y = rect.y1; y <= rect.y2; y++) {
            grid[x][y] = 0;
        }
    }
}

void turnOff2(int **grid, Rect rect) {
    int x, y;
    for (x = rect.x1; x <= rect.x2; x++) {
        for (y = rect.y1; y <= rect.y2; y++) {
            grid[x][y] -= 1;
            if (grid[x][y] < 0) {
                grid[x][y] = 0;
            }
        }
    }
}

int countLights(int **grid, int width, int height) {
    int x, y;
    int lights = 0;
    for (x = 0; x < width; x++) {
        for (y = 0; y < height; y++) {
            lights += grid[x][y];
        }
    }
    return lights;
}
