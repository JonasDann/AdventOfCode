//
// Created by Jonas on 22.12.2015.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "util/general.h"
#include "util/lightGrid.h"

void fillRect(int *rect, char *input, int *i) {
    int rectField = 0;
    while (input[*i] != '\n') {
        rect[rectField] = 0;
        while (input[*i] != ',' && input[*i] != ' ' && input[*i] != '\n') {
            rect[rectField] *= 10;
            rect[rectField] += input[*i] - 48;
            (*i)++;
        }
        if (input[*i] == ',') {
            (*i)++;
        } else if (input[*i] == ' ') {
            (*i) += 9;
        }
        rectField++;
    }
    (*i)++;
}

int main(int argc, char *argv[]) {
    char *input = getInput(argv[0]);

    clock_t t1, t2;

    t1 = clock();

    int i = 0;
    Rect rect;
    int **grid = malloc(1000 * sizeof(int *));
    int x, y;
    for (x = 0; x < 1000; x++) {
        grid[x] = malloc(1000 * sizeof(int));
        for (y = 0; y < 1000; y++) {
            grid[x][y] = 0;
        }
    }

    while (input[i] != '\0') {
        i++;
        if (input[i] == 'o') {
            i += 6;
            fillRect(&rect.x1, input, &i);
            toggle2(grid, rect);
        } else {
            i += 5;
            if (input[i] == 'n') {
                i += 2;
                fillRect(&rect.x1, input, &i);
                turnOn2(grid, rect);
            } else {
                i += 3;
                fillRect(&rect.x1, input, &i);
                turnOff2(grid, rect);
            }
        }
    }

    int lights = countLights(grid, 1000, 1000);

    for (x = 0; x < 1000; x++) {
        free(grid[x]);
    }
    free(grid);

    t2 = clock();
    int time = t2 - t1;
    printf("The answer was found in %i milliseconds\n", time);

    printf("The total brightness is %i.", lights);

    free(input);
    return 0;
}

