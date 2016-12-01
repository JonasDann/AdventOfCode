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

    int i = 0, result = 0;
    while (input[i] != '\0') {
        if (isDigit(input[i]))
            if (i > 0 && input[i - 1] == '-')
                result -= readInteger(input, &i);
            else
                result += readInteger(input, &i);
        i++;
    }

    t2 = clock();
    int time = t2 - t1;
    printf("The answer was found in %i milliseconds\n", time);

    printf("The numbers aggregate to %i.", result);

    free(input);
    return 0;
}

