//
// Created by Jonas on 22.12.2015.
//

#ifndef ADVENTOFCODEC_POSITIONVISISTEDLIST_H
#define ADVENTOFCODEC_POSITIONVISISTEDLIST_H


#include <stddef.h>

typedef struct {
    void *array[];
    size_t size;
    size_t negative_max;
} PositionVisitedList;

int checkAndInsert(PositionVisitedList *list, int x, int y);

#endif //ADVENTOFCODEC_POSITIONVISISTEDLIST_H
