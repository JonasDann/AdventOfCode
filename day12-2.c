//
// Created by Jonas on 22.12.2015.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "util/general.h"

int getObjectValue(char *input, int *i) {
    int result = 0, red = 0, openedObjects = 1;
    while (true) {
        if ((red == 0 && input[*i] == ':') || (red == 1 && input[*i] == '"') || (red == 2 && input[*i] == 'r') || (red == 3 && input[*i] == 'e'))
            red++;
        else if (red == 4 && input[*i] == 'd') {
            result = 0;
            break;
        } else
            red = 0;

        if (input[*i] == '{') {
            (*i)++;
            result += getObjectValue(input, i);
        }

        if (isDigit(input[*i]))
            if (*i > 0 && input[(*i) - 1] == '-')
                result -= readInteger(input, i);
            else
                result += readInteger(input, i);

        if (input[*i] != '}' && input[*i] != '\0')
            (*i)++;
        else
            break;
    }
    while (true) {
        if (input[*i] == '{')
            openedObjects++;
        else if (input[*i] == '}')
            openedObjects--;
        if (input[*i] == '}' && openedObjects == 0) {
            (*i)++;
            break;
        } else if (input[*i] == '\0') {
            break;
        }
        (*i)++;
    }
    return result;
}

int main(int argc, char *argv[]) {
    char *input = getInput(argv[0]);

    clock_t t1, t2;

    t1 = clock();

    int i = 0, result = getObjectValue(input, &i);

    t2 = clock();
    int time = t2 - t1;
    printf("The answer was found in %i milliseconds\n", time);

    printf("The numbers aggregate to %i.", result);

    free(input);
    return 0;
}

