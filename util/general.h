//
// Created by Jonas on 22.12.2015.
//

#ifndef ADVENTOFCODEC_GENERAL_H
#define ADVENTOFCODEC_GENERAL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<stdbool.h>

typedef struct {
    int x1;
    int y1;
    int x2;
    int y2;
} Rect;

typedef struct {
    int x;
    int y;
    int z;
} Vector3;

char *getInput(char *programPath);
char *readString(char *input, int *i, char end);
bool isDigit(char character);
int readInteger(char *input, int *i);

#endif //ADVENTOFCODEC_GENERAL_H