//
// Created by Jonas on 22.12.2015.
//

#include <stdlib.h>
#include <string.h>
#include "positionVisistedList.h"

void createList(PositionVisitedList *list, size_t elementSize) {
    list->array = malloc(5 * sizeof(void *));
    list->size = 5;
    list->negative_max = 2;
    int i;
    for (i = 0; i < 5; i++) {
        list->array[i] = malloc(elementSize);
        memset(list->array[i], 0, elementSize);
    }
}

void expandList(PositionVisitedList *list, size_t elementSize, int negativeExpansion) {
    list->array = realloc(list->array, (list->size + 5) * sizeof(void *));
    if (negativeExpansion) {
        memmove(list->array, &list->array[5], list->size * sizeof(void *));
        list->negative_max += 5;
    }
    int i;
    for (i = negativeExpansion ? 0 : list->size; i < 5; i++) {
        list->array[i] = malloc(elementSize);
        memset(list->array[i], 0, elementSize);
    }
    list->size += 5;
}

int checkAndInsertY(PositionVisitedList *list, int y) {
    if (list->size == 0) {
        createList(list, sizeof(int *));
    }
    if (y < 0) {
        if (-y > list->negative_max) {
            expandList(list, sizeof(int *), 1);
        }
    } else if (y > 0) {
        if (y > list->size - list->negative_max - 1) {
            expandList(list, sizeof(int *), 0);
        }
    }
    int result = *(int *)list->array[y + list->negative_max];
    memset(list->array[y + list->negative_max], 1, 1);
    return result;
}

int checkAndInsert(PositionVisitedList *list, int x, int y) {
    if (list->size == 0) {
        createList(list, sizeof(PositionVisitedList *));
    }
    if (x < 0) {
        if (-x > list->negative_max) {
            expandList(list, sizeof(PositionVisitedList *), 1);
        }
    } else if (x > 0) {
        if (x > list->size - list->negative_max - 1) {
            expandList(list, sizeof(PositionVisitedList *), 0);
        }
    }
    return checkAndInsertY(list->array[x + list->negative_max], y);
}

