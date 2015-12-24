//
// Created by Jonas on 24.12.2015.
//

#ifndef ADVENTOFCODEC_LIGHTGRID_H
#define ADVENTOFCODEC_LIGHTGRID_H

#include "general.h"

void toggle(int **grid, Rect rect);
void toggle2(int **grid, Rect rect);
void turnOn(int **grid, Rect rect);
void turnOn2(int **grid, Rect rect);
void turnOff(int **grid, Rect rect);
void turnOff2(int **grid, Rect rect);

int countLights(int **grid, int width, int height);

#endif //ADVENTOFCODEC_LIGHTGRID_H
