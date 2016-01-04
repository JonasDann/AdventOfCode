//
// Created by Jonas on 22.12.2015.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "util/general.h"

int main(int argc, char *argv[]) {
    char *input = getInput(argv[0]);

    clock_t t1, t2;

    t1 = clock();

    int i = 0, codeLength = 0, memoryLength = 0;
    while(input[i] != '\0') {
        i++; codeLength++;
        while (input[i] != '\n') {
            if (input[i] == '\\') {
                i++; codeLength++;
                switch (input[i]) {
                    case 'x':
                        i += 3; codeLength += 3;
                        break;
                    case '\\':
                    case '"':
                        i++; codeLength++;
                        break;
                    default:
                        printf("Illegal character");
                        break;
                }
                memoryLength++;
            } else if (input[i] == '"') {
                i++; codeLength++;
            } else {
                i++; codeLength++; memoryLength++;
            }
        }
        i++;
    }

    int result = codeLength - memoryLength;

    t2 = clock();
    int time = t2 - t1;
    printf("The answer was found in %i milliseconds\n", time);

    printf("The difference is %i.", result);

    free(input);
    return 0;
}

