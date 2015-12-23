//
// Created by Jonas on 22.12.2015.
//

#include <stdio.h>
#include <stdlib.h>
#include "util/general.h"

int main(int argc, char *argv[]) {
    char* input = getInput(argv[0]);

    int floor = 0;

    int i = 0;
    char ch;
    while((ch = input[i]) != '\0') {
        if (ch == '(') {
            floor++;
        } else if (ch == ')') {
            floor--;
        }
        if (floor < 0) {
            printf("Position: %i", i + 1);
            return 0;
        }
        i++;
    }

    printf("Santa does not have to go to the basement.");

    free(input);
    return 0;
}
