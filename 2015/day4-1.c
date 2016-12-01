//
// Created by Jonas on 22.12.2015.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "util/general.h"
#include <openssl/md5.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *input = getInput(argv[0]);

    clock_t t1, t2;

    t1 = clock();

    unsigned char output[MD5_DIGEST_LENGTH];
    int i = 0;
    int inputLength = strlen(input);
    int toHashLength = inputLength + 2 + 1;
    int toHashStrLen = 0;
    char *toHash = malloc((size_t) toHashLength);

    do {
        i++;
        sprintf(toHash, "%s%i", input, i);
        toHashStrLen = strlen(toHash);
        MD5((unsigned char *)toHash, (size_t) toHashStrLen, output);
        if (toHashLength - 1 <= toHashStrLen) {
            toHashLength++;
            toHash = realloc(toHash, (size_t) toHashLength);
        }
    } while (output[0] != 0 || output[1] != 0 || output[2] > 15);

    t2 = clock();
    int time = t2 - t1;
    printf("The answer was found in %i milliseconds\n", time);

    printf("The lowest number is %i", i);

    free(input);
    return 0;
}

