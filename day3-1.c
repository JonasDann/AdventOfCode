//
// Created by Jonas on 22.12.2015.
//

#include <stdio.h>
#include <stdlib.h>
#include "util/general.h"
#include "util/present.h"
#include "util/positionVisistedList.h"

int main(int argc, char *argv[]) {
    char *input = getInput(argv[0]);

    int totalHouses = 1;
    int x = 0;
    int y = 0;

    int i = 0;
    PositionVisitedList list;
    list.size = 0;

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

    printf("Houses: %i", totalHouses);

    freeList(&list);
    free(input);
    return 0;
}

