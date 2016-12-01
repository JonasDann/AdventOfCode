//
// Created by Jonas on 22.12.2015.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "util/general.h"
#include "util/charPairCache.h"

int main(int argc, char *argv[]) {
    char *input = getInput(argv[0]);

    clock_t t1, t2;

    t1 = clock();

    int i = 0;
    char lastChar;
    char nextToLastChar;
    int repeatOneLetterBetween;
    CharPairCache cache;
    cache.size = 0;
    int charPairs;
    int niceStrings = 0;

    while (input[i] != '\0') {
        lastChar = '\0';
        nextToLastChar = '\0';
        repeatOneLetterBetween = 0;
        cache.used = 0;
        charPairs = 0;
        while (input[i] != '\n') {
            if (nextToLastChar == input[i]) {
                repeatOneLetterBetween++;
            }
            if (lastChar != '\0' && hasCharPairNotOverlapping(&cache, &input[i - 1])) {
                charPairs++;
            }
            if (lastChar != '\0') {
                addCharPair(&cache, &input[i - 1]);
            }
            nextToLastChar = lastChar;
            lastChar = input[i];
            i++;
        }
        if (repeatOneLetterBetween > 0 && charPairs > 0) {
            niceStrings++;
        }
        i++;
    }

    freeCache(&cache);

    t2 = clock();
    int time = t2 - t1;
    printf("The answer was found in %i milliseconds\n", time);

    printf("There are %i nice strings", niceStrings);

    free(input);
    return 0;
}

