//
// Created by Jonas on 22.12.2015.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "util/general.h"
#include "util/positionVisistedList.h"

int main(int argc, char *argv[]) {
    char *input = getInput(argv[0]);

    clock_t t1, t2;

    t1 = clock();

    int totalHouses = 1;
    int x = 0;
    int y = 0;

    int i = 0;
    PositionVisitedList list;
    list.size = 0;

    checkAndInsert(&list, 0, 0);

    while(input[i] != '\0') {
        switch (input[i]) {
            case '^':
                y--;
                break;
            case 'v':
                y++;
                break;
            case '<':
                x--;
                break;
            case'>':
                x++;
                break;
            default:
                printf("Illegal character");
                return 1;
        }
        totalHouses += checkAndInsert(&list, x, y) ? 0 : 1;
        i++;
    }

    freeList(&list);

    t2 = clock();
    int time = t2 - t1;
    printf("The answer was found in %i milliseconds\n", time);

    printf("Santa visited %i houses", totalHouses);

    free(input);
    return 0;
}

