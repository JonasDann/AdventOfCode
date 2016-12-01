//
// Created by Jonas on 22.12.2015.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "util/general.h"
#include <string.h>

int main(int argc, char *argv[]) {
    char *input = getInput(argv[0]);

    clock_t t1, t2;

    t1 = clock();

    int i = 0;
    int naughty;
    char lastChar;
    int vowels;
    int doubles;
    int niceStrings = 0;

    while (input[i] != '\0') {
        naughty = 0;
        vowels = 0;
        doubles = 0;
        lastChar = '\0';
        while (input[i] != '\n') {
            if ((lastChar == 'a' && input[i] == 'b') || (lastChar == 'c' && input[i] == 'd') || (lastChar == 'p' && input[i] == 'q') || (lastChar == 'x' && input[i] == 'y')) {
                naughty = 1;
                while (input[i] != '\n') {
                    i++;
                }
                continue;
            }
            if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u') {
                vowels++;
            }
            if (input[i] == lastChar) {
                doubles++;
            }
            lastChar = input[i];
            i++;
        }
        if (!naughty && vowels > 2 && doubles > 0) {
            niceStrings++;
        }
        i++;
    }

    t2 = clock();
    int time = t2 - t1;
    printf("The answer was found in %i milliseconds\n", time);

    printf("There are %i nice strings.", niceStrings);

    free(input);
    return 0;
}

