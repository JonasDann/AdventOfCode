//
// Created by Jonas on 22.12.2015.
//

#ifndef ADVENTOFCODEC_GENERAL_H
#define ADVENTOFCODEC_GENERAL_H

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

#endif //ADVENTOFCODEC_GENERAL_H