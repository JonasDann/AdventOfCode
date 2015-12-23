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
    int xSanta = 0;
    int ySanta = 0;
    int xRoboSanta = 0;
    int yRoboSanta = 0;

    int i = 0;
    PositionVisitedList list;
    list.size = 0;

    checkAndInsert(&list, 0, 0);

    while(input[i] != '\0' && input[i + 1] != '\0') {
        switch (input[i]) {
            case '^':
                ySanta--;
                break;
            case 'v':
                ySanta++;
                break;
            case '<':
                xSanta--;
                break;
            case'>':
                xSanta++;
                break;
            default:
                printf("Illegal character");
                return 1;
        }
        switch (input[i + 1]) {
            case '^':
                yRoboSanta--;
                break;
            case 'v':
                yRoboSanta++;
                break;
            case '<':
                xRoboSanta--;
                break;
            case'>':
                xRoboSanta++;
                break;
            default:
                printf("Illegal character");
                return 1;
        }
        totalHouses += checkAndInsert(&list, xSanta, ySanta) ? 0 : 1;
        totalHouses += checkAndInsert(&list, xRoboSanta, yRoboSanta) ? 0 : 1;
        i += 2;
    }

    t2 = clock();
    int time = t2 - t1;
    printf("The answer was found in %i milliseconds\n", time);

    printf("Santa and RoboSanta visited %i houses", totalHouses);

    freeList(&list);
    free(input);
    return 0;
}

