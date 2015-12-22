//
// Created by Jonas on 22.12.2015.
//

#include <stdio.h>
#include "util.h"

struct Present {
    int x;
    int y;
    int z;
};

int wrappingPaper(struct Present present) {
    int side1 = present.x * present.y;
    int side2 = present.y * present.z;
    int side3 = present.z * present.x;
    return 2 * side1 + 2 * side2 + 2 * side3 + (side1 < side2 ? side1 < side3 ? side1 : side3 : side2 < side3 ? side2 : side3);
}

int main(int argc, char *argv[]) {
    char* input = getInput(argv[0]);

    int totalWrappingPaper = 0;

    int i = 0;
    char ch;
    struct Present present;
    int *presentDimensions = &present.x;
    int presentDimension = 0;

    while(input[i] != '\0') {
        present.x = 0;
        present.y = 0;
        present.z = 0;
        presentDimension = 0;
        do {
            while ((ch = input[i]) != 'x' && (ch != '\n')) {
                presentDimensions[presentDimension] *= 10;
                presentDimensions[presentDimension] += ch - 48;
                i++;
            }
            presentDimension++;
            i++;
        } while (ch != '\n');
        totalWrappingPaper += wrappingPaper(present);
    }

    printf("Wrapping paper needed: %i", totalWrappingPaper);
    return 0;
}

