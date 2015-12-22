//
// Created by Jonas on 22.12.2015.
//

#include <stdio.h>
#include "util.h"

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
        i++;
    }

    printf("Floor: %i", floor);

    return 0;
}