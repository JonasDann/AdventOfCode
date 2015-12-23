//
// Created by Jonas on 22.12.2015.
//

#include <stdio.h>
#include "util/general.h"
#include "util/present.h"

int main(int argc, char *argv[]) {
    char* input = getInput(argv[0]);

    int totalWrappingPaper = 0;

    int i = 0;
    char ch;
    Present present;
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
        totalWrappingPaper += getWrappingPaperNeededInSquareFoot(present);
    }

    printf("Wrapping paper needed: %i", totalWrappingPaper);
    return 0;
}

