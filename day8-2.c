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

    int i = 0, codeLength = 0, encodedLength = 0;
    while(input[i] != '\0') {
        i++; codeLength++; encodedLength += 3;
        while (input[i] != '\n') {
            if (input[i] == '\\') {
                i++; codeLength++; encodedLength += 2;
                switch (input[i]) {
                    case 'x':
                        i += 3; codeLength += 3; encodedLength += 3;
                        break;
                    case '\\':
                    case '"':
                        i++; codeLength++; encodedLength += 2;
                        break;
                    default:
                        printf("Illegal character");
                        break;
                }
            } else if (input[i] == '"') {
                i++; codeLength++; encodedLength += 3;
            } else {
                i++; codeLength++; encodedLength++;
            }
        }
        i++;
    }

    int result = encodedLength - codeLength ;

    t2 = clock();
    int time = t2 - t1;
    printf("The answer was found in %i milliseconds\n", time);

    printf("The difference is %i.", result);

    free(input);
    return 0;
}

